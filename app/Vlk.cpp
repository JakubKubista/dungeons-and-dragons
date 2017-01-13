#include "Vlk.h"

Vlk::Vlk() {
	m_nazevNPC = "Hladovy vlk";
	m_obtiznost = 1;
	m_zivoty = 100.0f;
	m_maxZivoty = 100.0f;
	m_sila = 10;
	m_obrana = 8;
	m_zkusenostiZVitezstvi = 100;
}

std::string Vlk::getNazevNPC() {
	return m_nazevNPC;
}

int Vlk::getObtiznost() {
	return m_obtiznost;
}

float Vlk::getZivoty() {
	return m_zivoty;
}

float Vlk::getMaxZivoty() {
	return m_maxZivoty;
}

int Vlk::getSila() {
	return m_sila;
}

int Vlk::getObrana() {
	return m_obrana;
}

int Vlk::getMagie() {
	return 0;
}

int Vlk::getZkusenostiZVitezstvi() {
	return m_zkusenostiZVitezstvi;
}
