#include "ItemZbroj.h"

ItemZbroj::ItemZbroj(std::string nazevItemu, int hodnotaItemu, int bonusObrana):Item(nazevItemu,hodnotaItemu) {
    m_nazevItemu = nazevItemu;
    m_hodnotaItemu = hodnotaItemu;
    m_bonusObrana = bonusObrana;
}

std::string ItemZbroj::getNazevItemu() {
	return m_nazevItemu;
}

int ItemZbroj::getHodnotaItemu() {
	return m_hodnotaItemu;
}

int ItemZbroj::getBonusObrana() {
	return m_bonusObrana;
}

int ItemZbroj::getBonusSila() {
	return 0;
}

float ItemZbroj::getBonusZivoty() {
	return 0;
}

float ItemZbroj::getBonusZkusenosti() {
	return 0;
}
