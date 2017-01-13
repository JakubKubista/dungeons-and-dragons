#include "CivEngine.h"

/* Tvorba rozmeru objektove desky a pole*/
modelHra::CivEngine::CivEngine() {
    m_hraciDeska = new ObjektovaHraciDeska(5,5);
    inicializujBunkyPole();
}

modelHra::ObjektovaHraciDeska* modelHra::CivEngine::getDeska(){
    return m_hraciDeska;
}
void modelHra::CivEngine::hrej() {
	// Pozor: tato metoda nesmi s rostouci komplexnosti bobtnat na desitky az
	// stovky radku! Je nezbytne, aby se z hlavni smycky volaly pomocne metody
	// ktere budou resit jednotlive varianty. Ty mohou zase volat jine metody
	// nebo tridy atp. Proste dodrzujte deleteni kodu do rozumnych bloku.
    int konec = 1;
    char x;
	HraciDeska* deska;
	MenuGUI* menu;
    HrdinaDirector* director = new HrdinaDirector();
    Pozice2d* mojePozice = new Pozice2d();
    Hrdina* mujHero = new Hrdina("Jakub");
    Hrdina* hero = new Hrdina();
    while(konec!=0)
    {
        deska->lebka();
        std::cin >> x;
		switch (x){
			case '1':{
//				deska->nactiZTextovehoSouboru("B:\Škola\VŠ\ZOO\1. semestr\Projekt\Projekt - Dungeons and Dragons\save.txt");
				vypisMoznostiGui(mujHero,mojePozice,director);}
				break;
			case '2':{
			    director->nadpis();
                hero->setJmeno("Jmeno");
			    director->nadpis();
                director->zvolTypHrdiny(hero);
				vypisMoznostiGui(hero,mojePozice,director);
				break;}
            case '3':{
                deska->lebkaNavod();
                break;}
            case '4':{
                delete hero;
                delete mujHero;
                delete director;
                delete mojePozice;
                konec=0;
                break;}
			default:
                menu->spatne();
				break;
		}
}
}

modelHra::CivEngine::~CivEngine() {
    m_hraciDeska->vymazDesku();
}
/* Naplnime jednotlive bunky ve hre (lokace)*/
void modelHra::CivEngine::inicializujBunkyPole() {
    // Prvni radek
 	m_hraciDeska->vloz(0,0, new Mistnost("Temna Ulicka",1));
	m_hraciDeska->vloz(0,1, new Mistnost("Mesicni Jezero",1));
	m_hraciDeska->vloz(0,2, new Mistnost("Zahadne Rozcesti",1));
	m_hraciDeska->vloz(0,3, new Mistnost("Dlouha cesta",1));
	m_hraciDeska->vloz(0,4, new Mistnost("Rytirska Staj",1));
	// Druhy radek
	m_hraciDeska->vloz(1,0, new Mistnost("Starcova Chatrc",1));
	m_hraciDeska->vloz(1,1, new Mistnost("Posvatny Chram",3));
	m_hraciDeska->vloz(1,2, new Mistnost("Jeskyne Stvur",2));
	m_hraciDeska->vloz(1,3, new Mistnost("Nedobytne Vezeni",3));
	m_hraciDeska->vloz(1,4, new Mistnost("Nekonecny Hrbitov",1));
	// Treti radek
	m_hraciDeska->vloz(2,0, new Mistnost("Kostel sv. Jakuba",2));
	m_hraciDeska->vloz(2,1, new Mistnost("Poutnikova Krcma",2));
	m_hraciDeska->vloz(2,2, new Mistnost("Nezname Udoli",2));
	m_hraciDeska->vloz(2,3, new Mistnost("Rozcesti Smutku",1));
	m_hraciDeska->vloz(2,4, new Mistnost("Krvava Krizovatka",1));
	// Ctrty radek
	m_hraciDeska->vloz(3,0, new Mistnost("Skalni Prusmyk",2));
	m_hraciDeska->vloz(3,1, new Mistnost("Draci Stezka",2));
	m_hraciDeska->vloz(3,2, new Mistnost("Konec Stezky",1));
	m_hraciDeska->vloz(3,3, new Mistnost("Draci Pevnost",1));
	m_hraciDeska->vloz(3,4, new Mistnost("Praseci Hostinec",1));
	// Paty radek
	m_hraciDeska->vloz(4,0, new Mistnost("Trnite Utesy",2));
	m_hraciDeska->vloz(4,1, new Mistnost("Draci Arena",3));
	m_hraciDeska->vloz(4,2, new Mistnost("Lesni Palouk",1));
	m_hraciDeska->vloz(4,3, new Mistnost("Zlaty Gral",2));
	m_hraciDeska->vloz(4,4, new Mistnost("Arnostova Kulna",1));
}

void modelHra::CivEngine::vypisMoznostiGui(Hrdina* hero,Pozice2d* mojePozice,HrdinaDirector* director) {
    int konec2=1;
    char a;
    MenuGUI* menu;
    MoznostiPohybu* pohyb;
    while(konec2!=0){
    if((hero->getAnkVzkriseni())==0){konec2=0;}else{
    menu->vypisMenuGUI(hero,director,mojePozice,m_hraciDeska);
    std::cin >> a;
        switch(a){
		case '1':
                hero->printInfo();
				break;
		case '2':
                director->vypisInventar(0);
                director->inventar(hero);
				break;
		case '3':
                m_hraciDeska->vypisMapu();
				break;
        case '4':
                m_hraciDeska->vypisDesku();
				break;
		case '5':
                m_hraciDeska->vrat((mojePozice->getRadek()),(mojePozice->getSloupec()),mojePozice)->vypisMenu(hero,mojePozice);
                break;
		case '6':
                pohyb->vypisPohyb(hero,mojePozice,m_hraciDeska);
				break;
		case '7':
                director->odpocivej(hero,mojePozice,m_hraciDeska);
				break;
		case '8':
			    HraciDeska* deska;
				deska->ulozDoTextovehoSouboru("B:\Škola\VŠ\ZOO\1. semestr\Projekt\Projekt - Dungeons and Dragons\save.txt");
				break;
		case '9':
                konec2=0;
				break;
        default:
                menu->spatne();
				break;
}
}
}
}
