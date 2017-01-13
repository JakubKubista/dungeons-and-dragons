#include "InventarZbroj.h"

InventarZbroj::InventarZbroj(){
    m_pocet = 0;
    m_kapacita = 3;
    m_logickyVstup = 1;
}

void InventarZbroj::vlozeniZbroj(Pozice2d* mojePozice,PoziceItem* mistniItem){
    int r = mojePozice->getRadek();
    int s = mojePozice->getSloupec();
    bool ulozeno = false;
    int i = 0;
    if (m_pocet<=m_kapacita){
    if (m_logickyVstup==1){
        std::cout << std::endl << "\t\t\t -----------------------------" << std::endl;
        std::cout << std::endl << "\t\t\t Sebral jste novou Zbroj!" << std::endl;
        std::cout << "\t\t\t ";
        system("pause");
        m_pocet++;
        m_logickyVstup++;
    }
    while((ulozeno == false)and(i<m_neseneZbrojeInventar.size())){
    if (m_neseneZbrojeInventar.at(i) != nullptr){
        m_neseneZbrojeInventar.at(i) = (mistniItem->vratItem(r,s));
        std::cout << std::endl << "\t\t\t -----------------------------" << std::endl;
        std::cout << std::endl << "\t\t\t Sebral jste novou Zbroj!" << std::endl;
        std::cout << "\t\t\t ";
        system("pause");
        m_pocet++;
        ulozeno = true;
    }else{i++;}}
    m_neseneZbrojeInventar.push_back(mistniItem->vratItem(r,s));
    }else{
        std::cout << std::endl << "\t\t\t -----------------------------" << std::endl;
        std::cout << std::endl << "\t\t\t Nedostatek mista v Inventari!" << std::endl;
        std::cout << "\t\t\t ";
        system("pause");
    }
}

void InventarZbroj::zahodZbroj(int druhZbroje) {
bool ulozeno = false;
char x;
       std::cout << "\t\t    Opravdu chcete zahodit Zbroj? (Y/N)  "; std::cin >> x;
       if(x=='y'){x='Y';}
       if(x=='n'){x='N';}
       if(x=='Y'){
                if(m_neseneZbrojeInventar.at(druhZbroje) != nullptr){
                m_neseneZbrojeInventar.at(druhZbroje) = nullptr;
                m_pocet--;
                ulozeno =true;}else{std::cout << std::endl << "\t\t    Pod timto cislem zadny Zbroj neni!  ";}
       }else if(x=='N'){
            ulozeno = false;
       }
}

void InventarZbroj::novaZbroj(int druhZbroje) {
    system("cls");
    std::cout << std::endl << std::endl;
    std::cout <<"                              Inventar - Zbroje                                " << std::endl << std::endl;
    std::cout <<" ----------------------------------------------------------------------------- " << std::endl << std::endl;
    for(int i=1; i<6; i++){std::cout << std::endl;}
    std::cout <<"                                ----------------                               " << std::endl;
    std::cout <<"                               |   NOVA ZBROJ   |                              " << std::endl;
    std::cout <<"                                ----------------                               " << std::endl;
    std::cout <<"                                   +" << m_neseneZbrojeInventar.at(druhZbroje)->getBonusObrana() << " obrana" << std::endl;
    for(int i=1; i<10; i++){std::cout << std::endl;}
    std::cout << " "; system("pause");
    m_pocet--;
}

std::string InventarZbroj::getNazevItemu() {
	return m_nazevItemu;
}

int InventarZbroj::getCisloItemu() {
	return m_cisloItemu;
}

int InventarZbroj::getBonusObrana() {
	return m_bonusObrana;
}

int InventarZbroj::getHodnotaItemu() {
	return m_hodnotaItemu;
}

int InventarZbroj::getBonusSila() {
	return 0;
}

float InventarZbroj::getBonusZivoty() {
	return 0;
}

float InventarZbroj::getBonusZkusenosti() {
	return 0;
}

void InventarZbroj::vypisZbroj(){
            for(int i=0; i<m_neseneZbrojeInventar.size();i++){
            if( m_neseneZbrojeInventar.at(i)!=nullptr){
            if((i==2)or(i==4)or(i==6)or(i==8)){std::cout << std::endl;}
            std::cout << "    " << i << ". ";
            std::cout << m_neseneZbrojeInventar.at(i)->getNazevItemu();
            std::cout << " (+" << m_neseneZbrojeInventar.at(i)->getBonusObrana() << " obrana)";
            }
}
}
