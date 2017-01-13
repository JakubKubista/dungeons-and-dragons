#include "InventarZbran.h"

InventarZbran::InventarZbran(){
    m_pocet = 0;
    m_kapacita = 3;
    m_logickyVstup = 1;
}

void InventarZbran::vlozeniZbran(Pozice2d* mojePozice,PoziceItem* mistniItem){
    int r = mojePozice->getRadek();
    int s = mojePozice->getSloupec();
    bool ulozeno = false;
    int i = 0;
    if (m_pocet<=m_kapacita){
    if (m_logickyVstup==1){
        std::cout << std::endl << "\t\t\t -----------------------------" << std::endl;
        std::cout << std::endl << "\t\t\t Sebral jste novou Zbran!" << std::endl;
        std::cout << "\t\t\t ";
        system("pause");
        m_pocet++;
        m_logickyVstup++;
    }
    while((ulozeno == false)and(i<m_neseneZbraneInventar.size())){
    if (m_neseneZbraneInventar.at(i) != nullptr){
        m_neseneZbraneInventar.at(i) = (mistniItem->vratItem(r,s));
        std::cout << std::endl << "\t\t\t -----------------------------" << std::endl;
        std::cout << std::endl << "\t\t\t Sebral jste novou Zbran!" << std::endl;
        std::cout << "\t\t\t ";
        system("pause");
        m_pocet++;
        ulozeno = true;
    }else{i++;}}
    m_neseneZbraneInventar.push_back(mistniItem->vratItem(r,s));
    }else{
        std::cout << std::endl << "\t\t\t -----------------------------" << std::endl;
        std::cout << std::endl << "\t\t\t Nedostatek mista v Inventari!" << std::endl;
        std::cout << "\t\t\t ";
        system("pause");
    }
}

void InventarZbran::zahodZbran(int druhZbrane) {
bool ulozeno = false;
char x;
       std::cout << "\t\t    Opravdu chcete zahodit Zbran? (Y/N)  "; std::cin >> x;
       if(x=='y'){x='Y';}
       if(x=='n'){x='N';}
       if(x=='Y'){
                if(m_neseneZbraneInventar.at(druhZbrane) != nullptr){
                m_neseneZbraneInventar.at(druhZbrane) = nullptr;
                m_pocet--;
                ulozeno =true;}else{std::cout << std::endl << "\t\t    Pod timto cislem zadna Zbran neni!  ";}
       }else if(x=='N'){
            ulozeno = false;
       }
}

void InventarZbran::novaZbran(int druhZbrane) {
    system("cls");
    std::cout << std::endl << std::endl;
    std::cout <<"                              Inventar - Zbrane                                " << std::endl << std::endl;
    std::cout <<" ----------------------------------------------------------------------------- " << std::endl << std::endl;
    for(int i=1; i<6; i++){std::cout << std::endl;}
    std::cout <<"                                ----------------                               " << std::endl;
    std::cout <<"                               |   NOVA ZBRAN   |                              " << std::endl;
    std::cout <<"                                ----------------                               " << std::endl;
    std::cout <<"                                    +" << m_neseneZbraneInventar.at(druhZbrane)->getBonusSila() << " sila" << std::endl;
    for(int i=1; i<10; i++){std::cout << std::endl;}
    std::cout << " "; system("pause");
    m_pocet--;
}

std::string InventarZbran::getNazevItemu() {
	return m_nazevItemu;
}

int InventarZbran::getCisloItemu() {
	return m_cisloItemu;
}

int InventarZbran::getBonusSila() {
	return m_bonusSila;
}

int InventarZbran::getHodnotaItemu() {
	return m_hodnotaItemu;
}

int InventarZbran::getBonusObrana() {
	return 0;
}

float InventarZbran::getBonusZivoty() {
	return 0;
}

float InventarZbran::getBonusZkusenosti() {
	return 0;
}

void InventarZbran::vypisZbran(){
            for(int i=0; i<m_neseneZbraneInventar.size();i++){
            if( m_neseneZbraneInventar.at(i)!=nullptr){
            if((i==2)or(i==4)or(i==6)or(i==8)){std::cout << std::endl;}
            std::cout << "    " << i << ". ";
            std::cout << m_neseneZbraneInventar.at(i)->getNazevItemu();
            std::cout << " (+" << m_neseneZbraneInventar.at(i)->getBonusSila() << " sila)";
            }
}
}
