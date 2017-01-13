#include "Drak.h"

Drak::Drak():NPC() {
	m_nazevNPC = "Ohnivy drak";
	m_obtiznost = 3;
	m_zivoty = 500.0f;
	m_maxZivoty = 500.0f;
	m_sila = 70;
	m_obrana = 70;
	m_magie = 50;
	m_zkusenostiZVitezstvi = 3000;
}

std::string Drak::getNazevNPC() {
	return m_nazevNPC;
}

int Drak::getObtiznost() {
	return m_obtiznost;
}

float Drak::getZivoty() {
	return m_zivoty;
}

float Drak::getMaxZivoty() {
	return m_maxZivoty;
}

int Drak::getSila() {
	return m_sila;
}

int Drak::getObrana() {
	return m_obrana;
}

int Drak::getMagie() {
	return m_magie;
}

int Drak::getZkusenostiZVitezstvi() {
	return m_zkusenostiZVitezstvi;
}

