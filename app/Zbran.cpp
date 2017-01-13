#include "Zbran.h"

Zbran::Zbran() {
    m_nazevZbrane = "Rezavy nuz";
    m_bonusSily = 1;
    m_hodnotaZbrane = 0;
}

std::string Zbran::getNazevZbrane() {
	return m_nazevZbrane;
}

int Zbran::getHodnotaZbrane() {
	return m_hodnotaZbrane;
}

int Zbran::getBonusSily() {
	return m_bonusSily;
}

void Zbran::setNazevZbrane(std::string nazevZbrane) {
	m_nazevZbrane = nazevZbrane;
}

void Zbran::setHodnotaZbrane(int hodnotaZbrane) {
	m_hodnotaZbrane = hodnotaZbrane;
}

void Zbran::setBonusSily(int bonusSily) {
	m_bonusSily = bonusSily;
}
