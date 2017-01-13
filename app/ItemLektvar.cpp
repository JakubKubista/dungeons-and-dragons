#include "ItemLektvar.h"

ItemLektvar::ItemLektvar(std::string nazevItemu, int hodnotaItemu, float bonusZivoty, float bonusZkusenosti):Item(nazevItemu,hodnotaItemu) {
	m_nazevItemu = nazevItemu;
	m_hodnotaItemu = hodnotaItemu;
	m_bonusZivoty = bonusZivoty;
	m_bonusZkusenosti = bonusZkusenosti;
}

std::string ItemLektvar::getNazevItemu() {
	return m_nazevItemu;
}

int ItemLektvar::getHodnotaItemu() {
	return m_hodnotaItemu;
}

float ItemLektvar::getBonusZivoty() {
	return m_bonusZivoty;
}

float ItemLektvar::getBonusZkusenosti(){
    return m_bonusZkusenosti;
}

int ItemLektvar::getBonusSila() {
	return 0;
}

int ItemLektvar::getBonusObrana() {
	return 0;
}
