#ifndef Vlk_h
#define Vlk_h
#include "NPC.h"

	/**
    * @brief Trida jenz je potomkem tridy NPC, dedi jeji ciste virtualni metody a jeji atributy
    *
    * Tato trida funguje na zaklade polymorfismu a reprezentuje urcity objekt v urcite lokaci.
    * Jedna se o zakladni nejslabi jednotku, na kterou diky obtiznosti 1 muzeme narazit jiz od prvni
    * urovne. A ma samozrejme sve pevne dane souradnice, po boji se v dane lokaci smaze.
    */
class Vlk : public NPC {

private:
		/**
		 * / Zde jsou deklarovany jednotlive atributy Vlka
		 */
        float m_zivoty;
        int m_sila;
        int m_obrana;
        int m_zkusenostiZVitezstvi;

public:
		/**
		 *  Jelikoz se jedna o bezparametricky konstruktor, nemusime urcovat, ktere
		 *  parametry se volaji z predka, pouze primo nastavime jednotlive atributy Vlka
		 */
        Vlk();
		/**
		 * / Metoda, ktera nam vraci Nazev Vlka v dane Mistnosti
		 */
        std::string getNazevNPC();
		/**
		 * / Metoda, ktera nam vraci Obtiznost Vlka v dane Mistnosti
		 */
        int getObtiznost();
		/**
		 * / Metoda, ktera nam vraci Nazev Vlka v dane Mistnosti
		 */
        float getZivoty();
		/**
		 * / Metoda, ktera nam vraci Maximalni Zivoty Vlka v dane Mistnosti
		 */
        float getMaxZivoty();
		/**
		 * / Metoda, ktera nam vraci Silu Vlka v dane Mistnosti
		 */
        int getSila();
		/**
		 * / Metoda, ktera nam vraci Obranu Vlka v dane Mistnosti
		 */
        int getObrana();
		/**
		 * / Metoda, ktera nam vraci Magii Vlka v dane Mistnosti
		 */
        int getMagie();
		/**
		 * / Metoda, ktera nam vraci Zkusenosti Z Vitezstvi Vlka v dane Mistnosti
		 */
        int getZkusenostiZVitezstvi();

};
#endif
