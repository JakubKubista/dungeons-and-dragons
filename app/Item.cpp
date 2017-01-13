#include "Item.h"

Item::Item(std::string nazevItemu, int hodnotaItemu) {
    if (nazevItemu == ""){
        std::cerr << " Snazite se do popisu itemu nastavit prazdnou hodnotu" << std::endl;
    }
	m_nazevItemu = nazevItemu;

    if ((hodnotaItemu < 0)or(hodnotaItemu >15)){
        std::cerr << " Takova hodnota neexistuje" << std::endl;
    }
	m_hodnotaItemu = hodnotaItemu;

}

Item::~Item() {
}
