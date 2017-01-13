#include "Zbroj.h"

Zbroj::Zbroj() {
    m_nazevZbroje = "Roztrhane hadry";
    m_bonusObrany = 1;
    m_hodnotaZbroje = 0;
}

std::string Zbroj::getNazevZbroje() {
	return m_nazevZbroje;
}

int Zbroj::getHodnotaZbroje() {
	return m_hodnotaZbroje;
}

int Zbroj::getBonusObrany() {
	return m_bonusObrany;
}

void Zbroj::setNazevZbroje(std::string nazevZbroje) {
	m_nazevZbroje = nazevZbroje;
}

void Zbroj::setHodnotaZbroje(int hodnotaZbroje) {
	m_hodnotaZbroje = hodnotaZbroje;
}

void Zbroj::setBonusObrany(int bonusObrany) {
	m_bonusObrany = bonusObrany;
}
