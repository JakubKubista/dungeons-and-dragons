#include "ObjektovaHraciDeska.h"

modelHra::ObjektovaHraciDeska::ObjektovaHraciDeska(const unsigned int pocetRadek, const unsigned int pocetSloupcu) {

    std::vector<HraciPole*> pomocnyRadek(pocetSloupcu, 0);
    // lze samozrejme i jinak
    m_deska.resize(pocetRadek);
    for(unsigned int i=0; i<pocetRadek; i++){
        m_deska[i] = pomocnyRadek;
    }
    m_pocetSloupcu = pocetSloupcu;
    m_pocetRadek = pocetRadek;
}

modelHra::HraciPole* modelHra::ObjektovaHraciDeska::vrat(const unsigned int radek, const unsigned int sloupec,Pozice2d* mojePozice) {
    // kontroluji, zda nepristupujeme mimo rozsah pole
    if ((radek < m_pocetRadek) and (sloupec < m_pocetSloupcu)){
        // kontroluji, zda je na pozici objekt
        if (m_deska[radek][sloupec] != 0){
            return m_deska[radek][sloupec];
            }else{
            return m_deska[mojePozice->getRadek()][mojePozice->getSloupec()];
            }
    }else{
    return m_deska[mojePozice->getRadek()][mojePozice->getSloupec()];
    }
}

void modelHra::ObjektovaHraciDeska::vloz(const unsigned int radek, const unsigned int sloupec, HraciPole* pole) {
    // kontrola, zda nepristupuji mimo rozsah pole
    if ((radek < m_pocetRadek) and (sloupec < m_pocetSloupcu)){
        m_deska[radek][sloupec] = pole;
    } else {
        std::cerr << " Pokus o pristup mimo rozsah desky!";
        std::cerr << " Pozadadovana pozice [" << radek << ", " << sloupec << "]." << std::endl;
        std::cerr << " Maximalni pozice [" << m_pocetRadek-1 << ", " << m_pocetSloupcu-1 << "]." << std::endl;
    }
}

int modelHra::ObjektovaHraciDeska::zjisti(const unsigned int radek, const unsigned int sloupec) {
    // kontroluji, zda nepristupujeme mimo rozsah pole
    if ((radek < m_pocetRadek) and (sloupec < m_pocetSloupcu)){
        // kontroluji, zda je na pozici objekt
        if (m_deska[radek][sloupec] != 0){
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

void modelHra::ObjektovaHraciDeska::vypisError(const unsigned int radek, const unsigned int sloupec){
            system("cls");
            std::cout << std:: endl << std:: endl;
            std::cout <<"                 ERROR            " << std::endl << std::endl;
            std::cout <<"  ------------------------------------" << std::endl;
            std::cerr << " Pokus o pristup do pole bez objektu" << std::endl;
            std::cerr << " Pozadadovana pozice [" << radek << ", " << sloupec << "]." << std::endl;
            std::cout << " ";
            system("pause");
}

int modelHra::ObjektovaHraciDeska::getPocetRadek() {
    return m_pocetRadek;
}

int modelHra::ObjektovaHraciDeska::getPocetSloupcu() {
    return m_pocetSloupcu;
}

void modelHra::ObjektovaHraciDeska::vypisMapu() {
    system("cls");
    std::cout << std::endl << std::endl << std::endl;
    std::cout << "\t\t\t\t         Mapa"<< std::endl;
    std::cout <<"\t\t #====#====#====#====#====#----|----|----|----|----|" << std::endl;
    std::cout <<"\t\t # 00   01   02   03   04 # 05   06   07 | 08 | 09 |" << std::endl;
    std::cout <<"\t\t #    #====#    #====#    #    |----|----|    |    |" << std::endl;
    std::cout <<"\t\t # 10 # 11 # 12 # 13 # 14 # 15 | 16   17 | 18 | 19 |" << std::endl;
    std::cout <<"\t\t #    #    #====#    #    #----|    |----|    |    |" << std::endl;
    std::cout <<"\t\t # 20 # 21 # 22 # 23   24 # 25   26   27   28   29 |" << std::endl;
    std::cout <<"\t\t #    #    #    #    #    #    |    |----|---------|" << std::endl;
    std::cout <<"\t\t # 30   31 # 32   33   34 # 35 | 36 | 37   38   39 |" << std::endl;
    std::cout <<"\t\t #====#====#    #====#====#----|----|----|    |----|" << std::endl;
    std::cout <<"\t\t | 40 # 41   42   43 # 44   45   46 | 47   48   49 |" << std::endl;
    std::cout <<"\t\t |    #====#====#====#    |----|    |    |    |----|" << std::endl;
    std::cout <<"\t\t | 50   51   52 | 53   54   55   56 | 57 | 58 | 59 |" << std::endl;
    std::cout <<"\t\t |    |----|----|    |    |----|----|    |----|    |" << std::endl;
    std::cout <<"\t\t | 60   61   62 | 63 | 64   65   66   67   68   69 |" << std::endl;
    std::cout <<"\t\t |----|    |----|    |----|----|----|----|----|----|" << std::endl;
    std::cout <<"\t\t | 70   71   72   73   74 | 75   76   77   78   79 |" << std::endl;
    std::cout <<"\t\t |----|    |----|----|----|    |----|----|----|    |" << std::endl;
    std::cout <<"\t\t | 80 | 81 | 82   83 | 84 | 85   86   87   88 | 89 |" << std::endl;
    std::cout <<"\t\t |    |    |    |    |    |----|----|----|----|    |" << std::endl;
    std::cout <<"\t\t | 90   91   92 | 93   84   95   96   87   98   99 |" << std::endl;
    std::cout <<"\t\t |----|----|----|----|----|----|----|----|----|----|" << std::endl << std::endl;
    std::cout <<" ";
    system("pause");
}

void modelHra::ObjektovaHraciDeska::vypisDesku() {
    unsigned int i = 0;
    system("cls");
    std::cout << std:: endl << std:: endl;
    std::cout <<"              Nazvy Lokaci            " << std::endl << std::endl;
    std::cout <<"  ------------------------------------" << std::endl;
    std::cout <<"          Nazev         |    Obtiznost " << std::endl;
    std::cout <<"  ------------------------------------" << std::endl;
    for(unsigned int radek=0; radek<m_pocetRadek; radek++){std::cout << std::endl;
        for(unsigned int sloupec=0;  sloupec<m_pocetSloupcu; sloupec++){ i++;
            std::cout << std::endl;
            std::cout << "  " << radek << sloupec << ". ";
            std::cout << m_deska[radek][sloupec]->getPopis() << "\t\t   ("<< m_deska[radek][sloupec] -> getObtiznost() << ")";
            if ((i==10)or(i==20)){
    std::cout << std::endl << std::endl; std::cout <<" ";
    system("pause");
    system("cls");
    std::cout << std:: endl << std:: endl;
    std::cout <<"              Nazvy Lokaci            " << std::endl << std::endl;
    std::cout <<"  ------------------------------------" << std::endl;
    std::cout <<"          Nazev         |    Obtiznost " << std::endl;
    std::cout <<"  ------------------------------------" << std::endl;
            }
        }
    }
    std::cout << std::endl << std::endl; std::cout <<" ";
    system("pause");
}

void modelHra::ObjektovaHraciDeska::odpocivadla(){
    system("cls");
    std::cout << std:: endl << std:: endl;
    std::cout <<"           Odpocivadla Mapy            " << std::endl << std::endl;
    std::cout <<"  ------------------------------------" << std::endl;
    std::cout <<"  Souradnice\t|         Nazev " << std::endl;
    std::cout <<"  ------------------------------------" << std::endl;
    for(unsigned int r=0; r<m_pocetRadek; r++){
        for(unsigned int s=0;  s<m_pocetSloupcu; s++){
            if(((r==1)and(s==0))or((r==2)and(s==1))or((r==0)and(s==4))or((r==4)and(s==2))){
            std::cout << std::endl;std::cout << std::endl;
            std::cout << "      (" << r << "," << s << ") \t|    ";
            std::cout << m_deska[r][s]->getPopis();
            }
        }
    }
    std::cout << std::endl << std::endl; std::cout <<" ";
    system("pause");
}

void modelHra::ObjektovaHraciDeska::vymazDesku() {
    for (unsigned int radek=0; radek<m_pocetRadek; radek++) {
        for (unsigned int sloupec=0; sloupec<m_pocetSloupcu; sloupec++) {
            // vzdy vymazu objekt a nastavim ukazatel na 0
            // tak je mozne testovat, zda tam nic neni
            delete m_deska[radek][sloupec];
            m_deska[radek][sloupec] = 0;
        }
    }
}
