#include "Ork.h"

Ork::Ork():NPC() {
	m_nazevNPC = "Zurivy ork";
	m_obtiznost = 2;
	m_zivoty = 200.0f;
	m_maxZivoty = 200.0f;
	m_sila = 30;
	m_obrana = 30;
	m_zkusenostiZVitezstvi = 500;
}

std::string Ork::getNazevNPC() {
	return m_nazevNPC;
}

int Ork::getObtiznost() {
	return m_obtiznost;
}

float Ork::getZivoty() {
	return m_zivoty;
}

float Ork::getMaxZivoty() {
	return m_maxZivoty;
}

int Ork::getSila() {
	return m_sila;
}

int Ork::getObrana() {
	return m_obrana;
}

int Ork::getMagie() {
	return 0;
}

int Ork::getZkusenostiZVitezstvi() {
	return m_zkusenostiZVitezstvi;
}
