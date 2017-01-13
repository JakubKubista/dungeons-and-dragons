#include "HrdinaDirector.h"

HrdinaDirector::HrdinaDirector(){
        m_den = 1;
}

void HrdinaDirector::setDen(){
        m_den++;
}

int HrdinaDirector::getDen(){
        return m_den;
}

void HrdinaDirector::nadpis(){
    system("cls");
    std::cout << std::endl << std::endl;
	std::cout <<"                                Vytvoreni Hrdiny                               " << std::endl << std::endl;
    std::cout <<" ----------------------------------------------------------------------------- " << std::endl;
    std::cout << std::endl;
}

void HrdinaDirector::vypisClass() {
    std::cout << "            1: Bojovnik      |      2: Lovec      |      3: Mag      " << std::endl;
    std::cout << "      ---------------------------------------------------------------" << std::endl;
    std::cout <<"            Sila: " << 10 <<"         |      Sila: " << 15 <<"      |      Sila: " << 5 << std::endl;
    std::cout <<"            Obrana: " << 15 <<"       |      Obrana: " << 10 <<"    |      Obrana: " << 5 << std::endl;
    std::cout <<"            Magie: " << 0 <<"         |      Magie: " << 0 <<"      |      Magie: " << 15 << std::endl;
    std::cout << "      ---------------------------------------------------------------" << std::endl << std::endl;
    std::cout << std::endl;
}

void HrdinaDirector::zvolTypHrdiny(Hrdina* hero){
        Bojovnik* typBojovnik;
        Lovec* typLovec;
        Mag* typMag;
        char x;
        std::cout <<"\t\t\t\t    4:(Zpet)" << std::endl << std::endl << std::endl << std::endl;
        vypisClass();
        std::cout <<"\t\t\t\t Vyberte volbu: ";
        std::cin >> x;
        std::cin.get ();
        switch(x){
		case '1':
                {
                typBojovnik->buildHrdina(hero);
				break;
                }
		case '2':
                {
                typLovec->buildHrdina(hero);
				break;
                }
		case '3':
                {
                typMag->buildHrdina(hero);
				break;
                }
        case '4':
                {
                nadpis();
                hero->setJmeno("Jmeno");
                nadpis();
                zvolTypHrdiny(hero);
				break;
                }
        default:
                {
                std::cout <<" Spatne zadana operace!" << std::endl;
                std::cout <<" ";
                system("pause");
                nadpis();
                zvolTypHrdiny(hero);
				break;
                }
}
}

void HrdinaDirector::vypisInventar(int volba){
    m_volba = volba;
}


void HrdinaDirector::inventar(Hrdina* hero){
    system("cls");
    std::cout << std::endl << std::endl;
    char b;
    if(m_volba==0){
	std::cout <<"                                    Inventar                                   " << std::endl << std::endl;
    std::cout <<" ----------------------------------------------------------------------------- " << std::endl << std::endl;}
    if(m_volba==1){
    std::cout <<"                              Inventar - Lektvary                              " << std::endl << std::endl;
    std::cout <<" ----------------------------------------------------------------------------- " << std::endl << std::endl;
    hero->getInventarLektvar()->vypisLektvar();}
    if(m_volba==2){
    std::cout <<"                              Inventar - Zbrane                                " << std::endl << std::endl;
    std::cout <<" ----------------------------------------------------------------------------- " << std::endl << std::endl;
    hero->getInventarZbran()->vypisZbran();}
    if(m_volba==3){
    std::cout <<"                              Inventar - Zbroje                                " << std::endl << std::endl;
    std::cout <<" ----------------------------------------------------------------------------- " << std::endl << std::endl;
    hero->getInventarZbroj()->vypisZbroj();}
    std::cout << std::endl << std::endl;
    std::cout <<"\t\t\t ------------------------------"<< std::endl;
    std::cout <<"\t\t\t| 1: Zobrazit Lektvary         |" << std::endl;
    std::cout <<"\t\t\t| 2: Zobrazit Zbrane           |" << std::endl;
    std::cout <<"\t\t\t| 3: Zobrazit Zbroje           |" << std::endl;
    std::cout <<"\t\t\t| 4: Vypit Lekvar              |" << std::endl;
    std::cout <<"\t\t\t| 5: Uchopit Zbran             |" << std::endl;
    std::cout <<"\t\t\t| 6: Oblect Zbroj              |" << std::endl;
    std::cout <<"\t\t\t| 7: Zahod Lekvar z Inventare  |" << std::endl;
    std::cout <<"\t\t\t| 8: Zahod Zbran z Inventare   |" << std::endl;
    std::cout <<"\t\t\t| 9: Zahod Zbroj z Inventare   |" << std::endl;
    std::cout <<"\t\t\t|                              |" << std::endl;
    std::cout <<"\t\t\t| Z:(Zpet)                     |" << std::endl;
    std::cout <<"\t\t\t ------------------------------"<< std::endl;
    std::cout << std::endl;
    std::cout <<"\t\t\t       Vyberte volbu: ";
    std::cin >> b;
    if(b=='z'){b='Z';}
    int c;
    switch (b){
          case '1':
                vypisInventar(1);
                inventar(hero);
                break;
          case '2':
                vypisInventar(2);
                inventar(hero);
                break;
          case '3':
                vypisInventar(3);
                inventar(hero);
                break;
          case '4':
                std::cout << std::endl <<"\t\t    Cislo lektvaru, jenz chcete vypit: ";
                std::cin >> c;
                hero->getInventarLektvar()->prubehPitiLektvaru(c);
                hero->vypijLektvar();
                inventar(hero);
                break;
          case '5':
                std::cout << std::endl <<"\t\t    Cislo Zbrane, jenz chcete uchopit: ";
                std::cin >> c;
                hero->uchopZbran(c);
                inventar(hero);
                break;
          case '6':
                std::cout << std::endl <<"\t\t    Cislo Zbroje, jenz chcete obleknout: ";
                std::cin >> c;
                hero->oblecZbroj(c);
                inventar(hero);
                break;
          case '7':
                std::cout << std::endl <<"\t\t    Cislo Lektvaru, jenz chcete zahodit: ";
                std::cin >> c;
                hero->getInventarLektvar()->zahodLektvar(c);
                inventar(hero);
                break;
          case '8':
                std::cout << std::endl <<"\t\t    Cislo Zbrane, jenz chcete zahodit: ";
                std::cin >> c;
                hero->getInventarZbran()->zahodZbran(c);
                inventar(hero);
                break;
          case '9':
                std::cout << std::endl <<"\t\t    Cislo Zbroje, jenz chcete zahodit: ";
                std::cin >> c;
                hero->getInventarZbroj()->zahodZbroj(c);
                inventar(hero);
                break;
          case 'Z':
                break;
            default:
                std::cout <<"\t\t\t  Spatne zadana operace!" << std::endl;
                std::cout <<"\t\t\t  ";
                system("pause");
                inventar(hero);
                break;
    }
}

void HrdinaDirector::odpocivej(Hrdina* hero,Pozice2d* mojePozice,modelHra::ObjektovaHraciDeska* m_hraciDeska){
    system("cls");
    std::cout << std::endl << std::endl << "        Odpocinek"<< std::endl;
    std::cout << "  --------------------------------------"<< std::endl;
    int r = mojePozice->getRadek();
    int s = mojePozice->getSloupec();
    if(((r==1)and(s==0))or((r==2)and(s==1))or((r==0)and(s==4))or((r==4)and(s==2))){
        char t;
        std::cout <<std::endl << "  (Odpocinek vam doplni zivoty na MAX a probudite se nasledujici den.)";
        std::cout <<std::endl <<std::endl << "  Chcete si zde odpocinout?  (Y/N)  ";
        std::cin>>t;
        if(t=='y'){t='Y';}
        if(t=='n'){t='N';}
            if(t=='Y'){
            hero->setZivoty();
            setDen();
            system("cls");
            for(int i=1;i<7;i++){std::cout << std::endl;} std::cout << "\t\t    --------------------------------------"<< std::endl;
            std::cout << std::endl << std::endl << "\t\t          Vitejte do noveho dne (DEN "<<m_den<< ")"<< std::endl;
            std::cout << std::endl << std::endl << "\t\t    --------------------------------------"<< std::endl;
            for(int i=1;i<11;i++){std::cout << std::endl;}
            std::cout << " ";
            system("pause");
            }else{};
    }else{
    m_hraciDeska->odpocivadla();
    }

}
HrdinaDirector::~HrdinaDirector() {
}
