#include "InventarLektvar.h"


/*

// Timto kodem v komentari bych rad sdelil, ze nespocet hodin jsem se snazil
// udelat inventare tak, aby jsme ho z mapy odstranili - delete
// a v inventari vytvorily novy se stejnymi hodnotami, ktere predame.
// Ale po dvou dnech snahy o prosazeni vektoru, do ktereho pridavame objekty
// tak jako do mapy, jsem byl nucen odstoupit od teto metodiky.

-----------------------------------------------------------------------------------
InventarLektvar::InventarLektvar(const unsigned int pocet) {

    HrdinuvItem* pomocnaBunka(0);
    m_neseneLektvaryInventar.resize(1);
    for(unsigned int i=0; i<1; i++){
        m_neseneLektvaryInventar[i] = pomocnaBunka;
    }
    m_pocet = pocet;
}

HrdinuvItem* InventarLektvar::vratLektvar(const unsigned int id) {
    // kontroluji, zda nepristupujeme mimo rozsah pole
    if (id < m_pocet){
        // kontroluji, zda je na pozici objekt
        if (m_neseneLektvaryInventar[id]!= 0){
            return m_neseneLektvaryInventar[id];
        }else{return 0;}
    }else{return 0;}
}

void InventarLektvar::vlozLektvar(const unsigned int id, HrdinuvItem* mujItem) {
    // kontrola, zda nepristupuji mimo rozsah moznosti umisteni objektu
    if (id < m_pocet){
        m_neseneLektvaryInventar[id] = mujItem;
    } else {
        system("cls");
        std::cout << std:: endl << std:: endl;
        std::cout <<"                 ERROR            " << std::endl << std::endl;
        std::cout <<"  ------------------------------------" << std::endl;
        std::cerr << " Pokus o vraceni objektu, ktery neexistuje" << std::endl;
        system("pause");
    }
}

int InventarLektvar::zjistiLektvar(const unsigned int id) {
        // kontroluji, zda je na pozici objekt
        if (m_neseneLektvaryInventar[id] != 0){
            return 1;
        } else {
            return 0;
        }
}
void InventarLektvar::vypisLektvar()
{
    for(int id=0; id<m_pocet; id++)
        {
            if( m_neseneLektvaryInventar[id]!=nullptr){
            std::cout << m_neseneLektvaryInventar[id]->getNazevItemu() <<  " ";}
        }
        std::cout << std::endl;
}
-----------------------------------------------------------------------------------
*/

InventarLektvar::InventarLektvar(){
    m_pocet = 0;
    m_kapacita = 5;
    m_logickyVstup = 1;
}

void InventarLektvar::nadpisLektvar(){
    system("cls");
    std::cout << std::endl << std::endl;
    std::cout <<"                              Inventar - Lektvary                              " << std::endl << std::endl;
    std::cout <<" ----------------------------------------------------------------------------- " << std::endl << std::endl;
}

void InventarLektvar::vlozeniLektvar(Pozice2d* mojePozice,PoziceItem* mistniItem){
    int r = mojePozice->getRadek();
    int s = mojePozice->getSloupec();
    bool ulozeno = false;
    int i = 0;
    if (m_pocet<=m_kapacita){
    if (m_logickyVstup==1){
        std::cout << std::endl << "\t\t\t -----------------------------" << std::endl;
        std::cout << std::endl << "\t\t\t Sebral jste novy Lektvar!" << std::endl;
        std::cout << "\t\t\t ";
        system("pause");
        m_pocet++;
        m_logickyVstup++;
    }
    while((ulozeno == false)and(i<m_neseneLektvaryInventar.size())){
    if (m_neseneLektvaryInventar.at(i) != nullptr){
        m_neseneLektvaryInventar.at(i) = (mistniItem->vratItem(r,s));
        std::cout << std::endl << "\t\t\t -----------------------------" << std::endl;
        std::cout << std::endl << "\t\t\t Sebral jste novy Lektvar!" << std::endl;
        std::cout << "\t\t\t ";
        system("pause");
        m_pocet++;
        ulozeno = true;
    }else{i++;}}
    m_neseneLektvaryInventar.push_back(mistniItem->vratItem(r,s));
    }else{
        std::cout << std::endl << "\t\t\t -----------------------------" << std::endl;
        std::cout << std::endl << "\t\t\t Nedostatek mista v Inventari!" << std::endl;
        std::cout << "\t\t\t ";
        system("pause");
    }
}
void InventarLektvar::prubehPitiLektvaru(int druhLektvaru) {
    setBonusZivoty(0);
    setBonusZkusenosti(0);
    if ((druhLektvaru>=0)and(druhLektvaru<m_neseneLektvaryInventar.size())){
    if (m_neseneLektvaryInventar.at(druhLektvaru)!=nullptr){
            if((m_neseneLektvaryInventar.at(druhLektvaru)->getBonusZkusenosti())!=0){
                nadpisLektvar();
                for(int i=1; i<6; i++){std::cout << std::endl;}
                std::cout <<"                                ---------------                                " << std::endl;
                std::cout <<"                                +" << m_neseneLektvaryInventar.at(druhLektvaru)->getBonusZkusenosti() << " zkusenosti" << std::endl;
                std::cout <<"                                ---------------                                " << std::endl;
                for(int i=1; i<10; i++){std::cout << std::endl;}
                std::cout << " "; system("pause");
                m_bonusZkusenosti = m_neseneLektvaryInventar.at(druhLektvaru)->getBonusZkusenosti();
            }
            if((m_neseneLektvaryInventar.at(druhLektvaru)->getBonusZivoty())!=0){
                nadpisLektvar();
                for(int i=1; i<6; i++){std::cout << std::endl;}
                std::cout <<"                                 -------------                                 " << std::endl;
                std::cout <<"                                  +" << m_neseneLektvaryInventar.at(druhLektvaru)->getBonusZivoty() << " zivotu" << std::endl;
                std::cout <<"                                 -------------                                 " << std::endl;
                for(int i=1; i<10; i++){std::cout << std::endl;}
                std::cout << " "; system("pause");
                m_bonusZivoty = m_neseneLektvaryInventar.at(druhLektvaru)->getBonusZivoty();
            }
            m_pocet--;
            m_neseneLektvaryInventar.at(druhLektvaru) = nullptr;
    }else{std::cout << "\t\t    Pod timto cislem zadny Lektvar neni!" << std::endl;}
    }
}

void InventarLektvar::zahodLektvar(int druhLektvaru) {
bool ulozeno = false;
char x;
       std::cout << "\t\t    Opravdu chcete zahodit Lektvar? (Y/N)  "; std::cin >> x;
       if(x=='y'){x='Y';}
       if(x=='n'){x='N';}
       if(x=='Y'){
                if(m_neseneLektvaryInventar.at(druhLektvaru) != nullptr){
                m_neseneLektvaryInventar.at(druhLektvaru) = nullptr;
                m_pocet--;
                ulozeno =true;}else{std::cout << std::endl << "\t\t    Pod timto cislem zadny Lektvar neni!";}
       }else if(x=='N'){
            ulozeno = false;
       }
}

void InventarLektvar::setBonusZivoty(float bonusZivoty){
    m_bonusZivoty = bonusZivoty;
}

void InventarLektvar::setBonusZkusenosti(float bonusZkusenosti){
    m_bonusZkusenosti = bonusZkusenosti;
}

std::string InventarLektvar::getNazevItemu() {
	return m_nazevItemu;
}

int InventarLektvar::getCisloItemu() {
    return m_cisloItemu;
}

float InventarLektvar::getBonusZivoty() {
	return m_bonusZivoty;
}

float InventarLektvar::getBonusZkusenosti() {
	return m_bonusZkusenosti;
}

int InventarLektvar::getHodnotaItemu() {
	return m_hodnotaItemu;
}

int InventarLektvar::getBonusObrana() {
	return 0;
}

int InventarLektvar::getBonusSila() {
	return 0;
}

int InventarLektvar::getPocet(){
    return m_pocet;
}

int InventarLektvar::getKapacita(){
    return m_kapacita;
}

void InventarLektvar::vypisLektvar(){
            for(int i=0; i<m_neseneLektvaryInventar.size();i++){
            if( m_neseneLektvaryInventar.at(i)!=nullptr){
            if((i==2)or(i==4)or(i==6)or(i==8)){std::cout << std::endl;}
            std::cout << "  " << i << ". ";
            std::cout << m_neseneLektvaryInventar.at(i)->getNazevItemu();
            if((m_neseneLektvaryInventar.at(i)->getBonusZkusenosti())!=0){
            std::cout << " (+" << m_neseneLektvaryInventar.at(i)->getBonusZkusenosti() << ")";
            }else{std::cout << " (+" << m_neseneLektvaryInventar.at(i)->getBonusZivoty() << ")";}
            }
}
}

