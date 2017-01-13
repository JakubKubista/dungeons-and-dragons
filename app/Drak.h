#ifndef Drak_h
#define Drak_h
#include "NPC.h"

	/**
    * @brief Trida jenz je potomkem tridy NPC, dedi jeji ciste virtualni metody a jeji atributy
    *
    * Tato trida funguje na zaklade polymorfismu a reprezentuje urcity objekt v urcite lokaci.
    * Jedna se o pokrocilou jednotku, na kterou diky obtiznosti 3 muzeme narazit od 10 urovne
    * a vys, vyskytuje se trikrat a cilem hry je tyto jednotky zabit a vzit Itemy v jejich Mistnostech
    * A ma samozrejme sve pevne dane souradnice, po boji se v dane lokaci smaze.
    */
class Drak : public NPC {

private:
        /**
		 * / Zde jsou deklarovany jednotlive atributy Draka
		 */
        float m_zivoty;
        int m_sila;
        int m_obrana;
        int m_magie;
        int m_zkusenostiZVitezstvi;

public:
		/**
		 *  Jelikoz se jedna o bezparametricky konstruktor, nemusime urcovat, ktere
		 *  parametry se volaji z predka, pouze primo nastavime jednotlive atributy Draka
		 */
        Drak();

        /**
		 * / Metoda, ktera nam vraci Nazev Draka v dane Mistnosti
		 */
        std::string getNazevNPC();

        /**
		 * / Metoda, ktera nam vraci Obtiznost Draka v dane Mistnosti
		 */
        int getObtiznost();

        /**
		 * / Metoda, ktera nam vraci Zivoty Draka v dane Mistnosti
		 */
        float getZivoty();

        /**
		 * / Metoda, ktera nam vraci Maximalni Zivoty Draka v dane Mistnosti
		 */
        float getMaxZivoty();

        /**
		 * / Metoda, ktera nam vraci Silu Draka v dane Mistnosti
		 */
        int getSila();

        /**
		 * / Metoda, ktera nam vraci Obranu Draka v dane Mistnosti
		 */
        int getObrana();

        /**
		 * / Metoda, ktera nam vraci Magii Draka v dane Mistnosti
		 */
        int getMagie();

        /**
		 * / Metoda, ktera nam vraci Zkusenosti Z Vitezsvi Draka v dane Mistnosti
		 */
        int getZkusenostiZVitezstvi();

};
#endif
