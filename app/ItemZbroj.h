#ifndef ItemZbroj_h
#define ItemZbroj_h
#include <iostream>
#include "Item.h"
class ItemZbroj : public Item {

	/**
    * @brief Trida jenz je potomkem tridy Item, dedi jeji ciste virtualni metody a jeji atributy
    *
    * Tato trida funguje na zaklade polymorfismu a reprezentuje urcity objekt v urcite lokaci.
    * Jedna se o mistni Zbroj, kterou Hrdina muze vzit do inventare, pote ji nosit nebo zahodit.
    * Zbroj nelze vratit do Inventare, jelikoz uz je pouzita, proto nova zbroj nahrazuje starou.
    * Trida obsahuje pouze sve atributy, konstruktor a getry.
    * A ma samozrejme sve pevne dane souradnice. Pomoci nahodneho generatoru ve tride Mistnost,
    * ktera vola predka Item, mame 33% sanci, ze na Item v dane Mistnosti narazime.
    */
private:
        /**
		 * / Zde jsou deklarovan atribut Zbroje v dane Mistnosti
		 */
        int m_bonusObrana;

public:
		/**
		 *  Jedna se o parametricky konstruktor, kde pri vytvoreni novehe Zbroje v Mistnosti
		 *  musime priradit jednotlive atributy, vetsina z nich se ve hre vyskytuje vickrat.
		 *  Konstruktor predka teto tridy musi explicitne vybrat, ktery parametricky konstruktor
		 *  se ma volat a s jakymi parametry
		 */
        ItemZbroj(std::string nazevItemu, int hodnotaItemu, int bonusObrana);

        /**
		 * / Metoda, ktera nam vraci Nazev Zbroje v dane Mistnosti
		 */
        std::string getNazevItemu();

        /**
		 * / Metoda, ktera nam vraci Hodnotu Zbroje v dane Mistnosti
		 */
        int getHodnotaItemu();

        /**
		 * / Metoda, ktera nam vraci Bonusovou Obranu Zbroje v dane Mistnosti
		 */
        int getBonusObrana();

        /**
		 * / Metoda, ktera nam vraci Bonusovou Silu Zbroje v dane Mistnosti - vraci 0
		 */
        int getBonusSila();

        /**
		 * / Metoda, ktera nam vraci Bonusove Zivoty Zbroje v dane Mistnosti - vraci 0
		 */
        float getBonusZivoty();

        /**
		 * / Metoda, ktera nam vraci Bonusove Zkusenosti Zbroje v dane Mistnosti - vraci 0
		 */
        float getBonusZkusenosti();

};
#endif
