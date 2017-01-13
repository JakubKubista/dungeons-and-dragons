#include "HraciPole.h"

modelHra::HraciPole::HraciPole(std::string popis, int obtiznost) {
    if (popis == ""){
        std::cerr << " Snazite se do popisu pole nastavit prazdnou hodnotu" << std::endl;
    }
    m_popis = popis;
    if ((obtiznost == 0)or(obtiznost >10)){
        std::cerr << " Takova obtiznost neexistuje" << std::endl;
    }
    m_obtiznost = obtiznost;

}

modelHra::HraciPole::~HraciPole() {
}
