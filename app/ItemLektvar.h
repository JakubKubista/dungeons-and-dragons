#ifndef ItemLektvar_h
#define ItemLektvar_h
#include "Item.h"
#include <iostream>

	/**
    * @brief Trida jenz je potomkem tridy Item, dedi jeji ciste virtualni metody a jeji atributy
    *
    * Tato trida funguje na zaklade polymorfismu a reprezentuje urcity objekt v urcite lokaci.
    * Jedna se o mistni Lektvar, ktery Hrdina muze vzit do inventare, pote ho pit nebo zahodit.
    * Trida obsahuje pouze sve atributy, konstruktor a getry.
    * A ma samozrejme sve pevne dane souradnice. Pomoci nahodneho generatoru ve tride Mistnost,
    * ktera vola predka Item, mame 33% sanci, ze na Item v dane Mistnosti narazime.
    */
class ItemLektvar : public Item {

private:
        /**
		 * / Zde jsou deklarovany jednotlive atributy Lektvaru v dane Mistnosti
		 */
        float m_bonusZivoty;
        float m_bonusZkusenosti;

public:
		/**
		 *  Jedna se o parametricky konstruktor, kde pri vytvoreni noveho Lektvaru v Mistnosti
		 *  musime priradit jednotlive atributy, vetsina z nich se ve hre vyskytuje vickrat.
		 *  Konstruktor predka teto tridy musi explicitne vybrat, ktery parametricky konstruktor
		 *  se ma volat a s jakymi parametry
		 */
        ItemLektvar(std::string nazevItemu, int hodnotaItemu, float bonusZivoty, float bonusZkusenosti);

        /**
		 * / Metoda, ktera nam vraci Nazev Lektvaru v dane Mistnosti
		 */
        std::string getNazevItemu();

        /**
		 * / Metoda, ktera nam vraci Hodnotu Lektvaru v dane Mistnosti
		 */
        int getHodnotaItemu();

        /**
		 * / Metoda, ktera nam vraci Bonusove Zivoty Lektvaru v dane Mistnosti
		 */
        float getBonusZivoty();

        /**
		 * / Metoda, ktera nam vraci Bonusove Zkusenosti Lektvaru v dane Mistnosti
		 */
        float getBonusZkusenosti();

        /**
		 * / Metoda, ktera nam vraci Bonusovou Silu Lektvaru v dane Mistnosti - vraci 0
		 */
        int getBonusSila();

        /**
		 * / Metoda, ktera nam vraci Bonusovou Obranu Lektvaru v dane Mistnosti - vraci 0
		 */
        int getBonusObrana();

};
#endif
