#include "ItemZbran.h"

ItemZbran::ItemZbran(std::string nazevItemu, int hodnotaItemu, int bonusSila):Item(nazevItemu,hodnotaItemu) {
    m_nazevItemu = nazevItemu;
    m_hodnotaItemu = hodnotaItemu;
    m_bonusSila = bonusSila;
}

std::string ItemZbran::getNazevItemu() {
	return m_nazevItemu;
}

int ItemZbran::getHodnotaItemu() {
	return m_hodnotaItemu;
}

int ItemZbran::getBonusSila() {
	return m_bonusSila;
}

int ItemZbran::getBonusObrana() {
	return 0;
}

float ItemZbran::getBonusZivoty() {
	return 0;
}

float ItemZbran::getBonusZkusenosti() {
	return 0;
}
