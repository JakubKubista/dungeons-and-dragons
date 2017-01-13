#ifndef ItemZbran_h
#define ItemZbran_h
#include "Item.h"
#include <iostream>
class ItemZbran : public Item {

	/**
    * @brief Trida jenz je potomkem tridy Item, dedi jeji ciste virtualni metody a jeji atributy
    *
    * Tato trida funguje na zaklade polymorfismu a reprezentuje urcity objekt v urcite lokaci.
    * Jedna se o mistni Zbran, kterou Hrdina muze vzit do inventare, pote ji nosit nebo zahodit.
    * Zbran nelze vratit do Inventare, jelikoz uz je pouzita, proto nova zbran nahrazuje starou.
    * Trida obsahuje pouze sve atributy, konstruktor a getry.
    * A ma samozrejme sve pevne dane souradnice. Pomoci nahodneho generatoru ve tride Mistnost,
    * ktera vola predka Item, mame 33% sanci, ze na Item v dane Mistnosti narazime.
    */
private:
        /**
		 * / Zde jsou deklarovan atribut Zbrane v dane Mistnosti
		 */
        int m_bonusSila;

public:
		/**
		 *  Jedna se o parametricky konstruktor, kde pri vytvoreni noveho Zbrane v Mistnosti
		 *  musime priradit jednotlive atributy, vetsina z nich se ve hre vyskytuje vickrat.
		 *  Konstruktor predka teto tridy musi explicitne vybrat, ktery parametricky konstruktor
		 *  se ma volat a s jakymi parametry
		 */
		 ItemZbran(std::string nazevItemu, int hodnotaItemu, int bonusSila);

        /**
		 * / Metoda, ktera nam vraci Nazev Zbrane v dane Mistnosti
		 */
        std::string getNazevItemu();

        /**
		 * / Metoda, ktera nam vraci Hodnotu Zbrane v dane Mistnosti
		 */
        int getHodnotaItemu();

        /**
		 * / Metoda, ktera nam vraci Bonusovou Silu Zbrane v dane Mistnosti
		 */
        int getBonusSila();

        /**
		 * / Metoda, ktera nam vraci Bonusovou Obranu Zbrane v dane Mistnosti - vraci 0
		 */
        int getBonusObrana();

        /**
		 * / Metoda, ktera nam vraci Bonusove Zivoty Zbrane v dane Mistnosti - vraci 0
		 */
        float getBonusZivoty();

        /**
		 * / Metoda, ktera nam vraci Bonusove Zkusenosti Zbrane v dane Mistnosti - vraci 0
		 */
        float getBonusZkusenosti();

};
#endif
