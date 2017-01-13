#ifndef Ork_h
#define Ork_h
#include "NPC.h"

	/**
    * @brief Trida jenz je potomkem tridy NPC, dedi jeji ciste virtualni metody a jeji atributy
    *
    * Tato trida funguje na zaklade polymorfismu a reprezentuje urcity objekt v urcite lokaci.
    * Jedna se o stredne tezkou jednotku, na kterou diky obtiznosti 2 muzeme narazit od urovne 5
    * a vys. A ma samozrejme sve pevne dane souradnice, po boji se v dane lokaci smaze.
    */
class Ork : public NPC {

private:
		/**
		 * / Zde jsou deklarovany jednotlive atributy Orka
		 */
        float m_zivoty;
        int m_sila;
        int m_obrana;
        int m_zkusenostiZVitezstvi;

public:
		/**
		 *  Jelikoz se jedna o bezparametricky konstruktor, nemusime urcovat, ktere
		 *  parametry se volaji z predka, pouze primo nastavime jednotlive atributy Orka
		 */
        Ork();

		/**
		 * / Metoda, ktera nam vraci Nazev Orka v dane Mistnosti
		 */
        std::string getNazevNPC();

		/**
		 * / Metoda, ktera nam vraci Obtiznost Orka v dane Mistnosti
		 */
        int getObtiznost();

        /**
		 * / Metoda, ktera nam vraci Zivoty Orka v dane Mistnosti
		 */
        float getZivoty();

		/**
		 * / Metoda, ktera nam vraci Maximalni Zivoty Orka v dane Mistnosti
		 */
        float getMaxZivoty();

		/**
		 * / Metoda, ktera nam vraci Silu Orka v dane Mistnosti
		 */
        int getSila();

		/**
		 * / Metoda, ktera nam vraci Obranu Orka v dane Mistnosti
		 */
        int getObrana();

        /**
		 * / Metoda, ktera nam vraci Magii Orka v dane Mistnosti
		 */
        int getMagie();

        /**
		 * / Metoda, ktera nam vraci Zkusenosti Z Vitezstvi Orka v dane Mistnosti
		 */
        int getZkusenostiZVitezstvi();

};
#endif
