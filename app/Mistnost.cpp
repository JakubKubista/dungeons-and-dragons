#include "Mistnost.h"

Mistnost::Mistnost(std::string popis, int obtiznost):HraciPole(popis,obtiznost) {
	m_popis = popis;
	m_obtiznost = obtiznost;
    m_vsechnyItemy = new PoziceItem(5,5);
    inicializujVsechnyItemy();
    m_vsechnyNPC = new PoziceNPC(5,5);
    inicializujVsechnyNPC();
}

std::string Mistnost::getPopis() {
	return m_popis;
}

int Mistnost::getObtiznost() {
	return m_obtiznost;
}

void Mistnost:: inicializujVsechnyItemy(){
    // Prvni radek
 	m_vsechnyItemy->vlozItem(0,0, new ItemLektvar("Maly Lektvar Zdravi",1,50,0));
	m_vsechnyItemy->vlozItem(0,1, new ItemLektvar("Maly Lektvar Zkusenosti",1,0,100));
	m_vsechnyItemy->vlozItem(0,2, new ItemZbroj("Delnicky Odev",2,5));
	m_vsechnyItemy->vlozItem(0,4, new ItemLektvar("Stredni Lektvar Zdravi",3,100,0));
	// Druhy radek
	m_vsechnyItemy->vlozItem(1,0, new ItemZbran("Drevorubecka Sekera",2,5));
	m_vsechnyItemy->vlozItem(1,1, new ItemZbroj("Draci Zbroj",10,100));
	m_vsechnyItemy->vlozItem(1,2, new ItemZbran("Posvatna Sekera",7,50));
	m_vsechnyItemy->vlozItem(1,3, new ItemLektvar("Obrovsky Lektvar Zkusenosti",10,0,3000));
	// Treti radek
	m_vsechnyItemy->vlozItem(2,1, new ItemLektvar("Velky Lektvar Zkusenosti",5,0,1000));
	m_vsechnyItemy->vlozItem(2,2, new ItemZbran("Mec Bastard",4,25));
	m_vsechnyItemy->vlozItem(2,3, new ItemLektvar("Stredni Lektvar Zdravi",3,100,0));
	m_vsechnyItemy->vlozItem(2,4, new ItemLektvar("Stredni Lektvar Zkusenosti",3,0,400));
	// Ctrty radek
	m_vsechnyItemy->vlozItem(3,0, new ItemLektvar("Stredni Lektvar Zkusenosti",3,0,400));
	m_vsechnyItemy->vlozItem(3,1, new ItemZbroj("Rytirske Brneni",4,25));
	m_vsechnyItemy->vlozItem(3,3, new ItemLektvar("Velky Lektvar Zdravi",5,200,0));
	m_vsechnyItemy->vlozItem(3,4, new ItemLektvar("Maly Lektvar Zdravi",1,50,0));
	// Paty radek
	m_vsechnyItemy->vlozItem(4,1, new ItemZbran("Draci Mec",10,100));
	m_vsechnyItemy->vlozItem(4,2, new ItemLektvar("Velky Lektvar Zdravi",5,200,0));
	m_vsechnyItemy->vlozItem(4,3, new ItemZbroj("Posvatna zbroj",7,50));
}

void Mistnost:: inicializujVsechnyNPC(){
    // Prvni radek
	m_vsechnyNPC->vlozNPC(0,1, new Vlk());
	m_vsechnyNPC->vlozNPC(0,2, new Vlk());
	m_vsechnyNPC->vlozNPC(0,4, new Vlk());
	// Druhy radek
	m_vsechnyNPC->vlozNPC(1,0, new Vlk());
	m_vsechnyNPC->vlozNPC(1,1, new Drak());
	m_vsechnyNPC->vlozNPC(1,2, new Ork());
	m_vsechnyNPC->vlozNPC(1,3, new Drak());
	m_vsechnyNPC->vlozNPC(1,4, new Vlk());
	// Treti radek
	m_vsechnyNPC->vlozNPC(2,0, new Ork());
	m_vsechnyNPC->vlozNPC(2,1, new Ork());
	m_vsechnyNPC->vlozNPC(2,2, new Ork());
	m_vsechnyNPC->vlozNPC(2,4, new Vlk());
	// Ctrty radek
	m_vsechnyNPC->vlozNPC(3,0, new Ork());
	m_vsechnyNPC->vlozNPC(3,1, new Ork());
	m_vsechnyNPC->vlozNPC(3,2, new Vlk());
	m_vsechnyNPC->vlozNPC(3,3, new Vlk());
	// Paty radek
	m_vsechnyNPC->vlozNPC(4,1, new Drak());
	m_vsechnyNPC->vlozNPC(4,3, new Ork());
}

void Mistnost::vypisMenu(Hrdina* hero,Pozice2d* mojePozice) {
    LokaceItem* menuItem;
    LokaceNPC* menuNPC;
    int r = mojePozice->getRadek();
    int s = mojePozice->getSloupec();
    menuItem->setOpakovani(0);
    if((m_vsechnyNPC->zjistiNPC(r,s))==0){
        if((m_vsechnyItemy->zjistiItem(r,s))==0){
                m_vsechnyItemy->neniItem();
        }else{  int n = rand()%2;
                if(n==1){menuItem->vypisItemy(hero,mojePozice,m_vsechnyItemy);}
                else{m_vsechnyItemy->neniItem();}}
    }else{menuNPC->vypisNPC(hero,mojePozice,m_vsechnyNPC);}
}

Mistnost::~Mistnost() {
    m_vsechnyItemy->vymazVsechnyItemy();
    m_vsechnyNPC->vymazVsechnyNPC();
}
