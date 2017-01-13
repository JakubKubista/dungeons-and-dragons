#ifndef InventarZbroj_h
#define InventarZbroj_h
#include "Pozice2d.h"
#include "PoziceItem.h"
#include "Item.h"
#include <vector>
#include <iostream>

	/**
    * @brief Trida reprezentujici Inventar Zbroji.
    *
    * Tato trida ma urcity pocet Zbroji, ktere jsou definovany jako vektor.
    * Trida ma urcitou kapacitu, ktera je nastavena v konstruktoru. Jednotlive Zbroje
    * jsou do vektoru umisteny z urcite pozice Itemu. Kazde pole vektoru odpovida jedne
    * vlozene Zbroji. Obsahuje metody vkladani, piti a zahazovani jednotlivych Zbroji.
    * Trida je urcena pro Hrdinu, ktery ji vlastni pod atributem m_inventarZbroj.
    * Jednotlive metody jsou volany jak v trdie Hrdina v pomocne tride Hrdiny, ktera
    * ma nazev Hrdina Director.
    */
class InventarZbroj{

private:
		/**
		 * / Atributy, ktere jsou potrebne pro urceni poctu Zbroji a kapacity
		 */
        int m_pocet;
        int m_kapacita;

		/**
		 *  Pri vlozeni prvni Zbroje do Inventare Zbroji nebylo mozne zobratit
		 *  upozornujici okno, proto byl atribut vytvoren, pomoci ktereho je to mozne.
		 */
        int m_logickyVstup;

		/**
		 * / Atributy, urcujici nazev, cislo, bonusovou obranu a hodnotu Itemu
		 */
        std::string m_nazevItemu;
        int m_cisloItemu;
        int m_bonusObrana;
        int m_hodnotaItemu;

public:

		/**
		 *   Atribut, typu vekter, diky kteremu muze Inventar Zbroj obsahovat vice Zbroji.
		 *   Je samozreme, ze vsechny atributy musi byt public, ale diky zvolene metode, aby
		 *   Hrdina mohl uchopit zbran, se mi nepodarila naprogramovat jina moznost.
		 */
        std::vector<Item*> m_neseneZbrojeInventar;

		/**
		 *  Bezparametricky konstruktor, ktery se vytvori pri vytvoreni Hrdiny
		 *  Pocet Zbroji nastaven na 0, kapacita je 5 a logicky vstup je 1
		 */
        InventarZbroj();

        /**
		 *   Metoda, za pomoci ktere vlozime Item (Zbroj), na volnou pozici
		 *   ve vektoru m_neseneZbrojeInventar. Tedy vlozime z urcite Mistnosti
		 *   Zbroj od urcitych souradnicich do Inventare Zbroj.
		 */
		 void vlozeniZbroj(Pozice2d* mojePozice,PoziceItem* mistniItem);

        /**
		 *   Tato metoda vyzaduje zadani, kterou Zbroj chceme vyhodit, nasledne se zepta
		 *   na potvrzeni. Pote zjisti jestli v poli vektoru vubec nejaka Zbroj je a nasledne
		 *   ji zahodi, neboli priradi poli prazdnou hodnotu.
		 */
		 void zahodZbroj(int druhZbroje);

        /**
		 *   Toto je metoda ktera nam pouze zobrazi hlasku, ze jsme obdrzeli novou Zbroj
		 *   a zaroven vypise jeji bonusovou obranu.
		 */
        void novaZbroj(int druhZbroje);

        /**
		 * / Metoda, ktera vraci nazev Zbroje v inventari.
		 */
        std::string getNazevItemu();

        /**
		 * / Metoda, ktera vraci cislo Zbroje v inventari.
		 */
        int getCisloItemu();

        /**
		 * / Metoda, ktera vraci bonusovou obranu Zbroje v inventari.
		 */
        int getBonusObrana();

        /**
		 * / Metoda, ktera vraci hodnotu Zbroje v inventari.
		 */
        int getHodnotaItemu();

        /**
		 * / Metoda, ktera vraci bonusovou silu Zbroje v inventari - vraci vzdy 0.
		 */
        int getBonusSila();

        /**
		 * / Metoda, ktera vraci bonusove zivoty Zbroje v inventari - vraci vzdy 0.
		 */
        float getBonusZivoty();

        /**
		 * / Metoda, ktera vraci bonusove zkusenosti Zbroje v inventari - vraci vzdy 0.
		 */
        float getBonusZkusenosti();

        /**
		 *   Metoda, ktera nam za pomoci for cyklu vypise cely vektor Zbroji (Inventar Zbroj).
		 */
        void vypisZbroj();
};
#endif
