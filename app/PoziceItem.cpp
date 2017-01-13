#include "PoziceItem.h"

PoziceItem::PoziceItem(const unsigned int pocetRadek, const unsigned int pocetSloupcu) {

    std::vector<Item*> pomocnyRadek(pocetSloupcu, 0);
    m_poziceItem.resize(pocetRadek);
    for(unsigned int i=0; i<pocetRadek; i++){
        m_poziceItem[i] = pomocnyRadek;
    }
    m_pocetSloupcu = pocetSloupcu;
    m_pocetRadek = pocetRadek;
}

Item* PoziceItem::vratItem(const unsigned int radek, const unsigned int sloupec) {
    // kontroluji, zda nepristupujeme mimo rozsah pole
    if ((radek < m_pocetRadek) and (sloupec < m_pocetSloupcu)){
        // kontroluji, zda je na pozici objekt
        if (m_poziceItem[radek][sloupec] != 0){
            return m_poziceItem[radek][sloupec];
        }else{return 0;}
    }else{return 0;}
}

void PoziceItem::vlozItem(const unsigned int radek, const unsigned int sloupec, Item* vec) {
    // kontrola, zda nepristupuji mimo rozsah moznosti umisteni objektu
    if ((radek < m_pocetRadek) and (sloupec < m_pocetSloupcu)){
        m_poziceItem[radek][sloupec] = vec;
    } else {
        system("cls");
        std::cout << std:: endl << std:: endl;
        std::cout <<"                 ERROR            " << std::endl << std::endl;
        std::cout <<"  ------------------------------------" << std::endl;
        std::cerr << " Pokus o vraceni objektu, ktery neexistuje" << std::endl;
        std::cerr << " Pozadadovana pozice objektu [" << radek << ", " << sloupec << "]." << std::endl;
        std::cerr << " Maximalni pozice [" << m_pocetRadek-1 << ", " << m_pocetSloupcu-1 << "]." << std::endl;
        system("pause");
    }
}

int PoziceItem::zjistiItem(const unsigned int radek, const unsigned int sloupec) {
        // kontroluji, zda je na pozici objekt
        if (m_poziceItem[radek][sloupec] != 0){
            return 1;
        } else {
            return 0;
        }
}

void PoziceItem::neniItem(){
    system("cls");
    std::cout << std::endl << std::endl;
	std::cout <<"                                 Mistni Lokace                                 " << std::endl << std::endl;
    std::cout <<" ----------------------------------------------------------------------------- " << std::endl;
    for(int i=1; i<10; i++){std::cout << std::endl;}
    std::cout << "\t\t\t\t NIC NENALEZENO"<< std::endl;
    for(int i=1; i<10; i++){std::cout << std::endl;}
    std::cout << " "; system("pause");
}

int PoziceItem::getPocetRadek() {
    return m_pocetRadek;
}

int PoziceItem::getPocetSloupcu() {
    return m_pocetSloupcu;
}

void PoziceItem::vymazKonkretniItem(const unsigned int radek, const unsigned int sloupec) {
    delete m_poziceItem[radek][sloupec];
    m_poziceItem[radek][sloupec] = 0;
}

void PoziceItem::vymazVsechnyItemy() {
    for (unsigned int radek=0; radek<m_pocetRadek; radek++) {
        for (unsigned int sloupec=0; sloupec<m_pocetSloupcu; sloupec++) {
            // vzdy vymazu objekt a nastavim ukazatel na 0
            // tak je mozne testovat, zda tam nic neni
            delete m_poziceItem[radek][sloupec];
            m_poziceItem[radek][sloupec] = 0;
        }
    }
}
