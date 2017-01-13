#ifndef InventarZbran_h
#define InventarZbran_h
#include "Pozice2d.h"
#include "PoziceItem.h"
#include "Item.h"
#include <vector>
#include <iostream>
class InventarZbran{

	/**
    * @brief Trida reprezentujici Inventar Zbrani.
    *
    * Tato trida ma urcity pocet Zbrani, ktere jsou definovany jako vektor.
    * Trida ma urcitou kapacitu, ktera je nastavena v konstruktoru. Jednotlive Zbrane
    * jsou do vektoru umisteny z urcite pozice Itemu. Kazde pole vektoru odpovida jedne
    * vlozene Zbrani. Obsahuje metody vkladani, piti a zahazovani jednotlivych Zbrani.
    * Trida je urcena pro Hrdinu, ktery ji vlastni pod atributem m_inventarZbran.
    * Jednotlive metody jsou volany jak v trdie Hrdina v pomocne tride Hrdiny, ktera
    * ma nazev Hrdina Director.
    */
private:
		/**
		 * / Atributy, ktere jsou potrebne pro urceni poctu Zbrani a kapacity
		 */
        int m_pocet;
        int m_kapacita;

		/**
		 *  Pri vlozeni prvni Zbrane do Inventare Zbrani nebylo mozne zobratit
		 *  upozornujici okno, proto byl atribut vytvoren, pomoci ktereho je to mozne.
		 */
        int m_logickyVstup;

		/**
		 * / Atributy, urcujici nazev, cislo, bonusovou silu a hodnotu Itemu
		 */
        std::string m_nazevItemu;
        int m_cisloItemu;
        int m_bonusSila;
        int m_hodnotaItemu;

public:

		/**
		 *   Atribut, typu vekter, diky kteremu muze Inventar Zbran obsahovat vice Zbrani.
		 *   Je samozreme, ze vsechny atributy musi byt public, ale diky zvolene metode, aby
		 *   Hrdina mohl uchopit zbran, se mi nepodarila naprogramovat jina moznost.
		 */
        std::vector<Item*> m_neseneZbraneInventar;

		/**
		 *  Bezparametricky konstruktor, ktery se vytvori pri vytvoreni Hrdiny
		 *  Pocet Zbrani nastaven na 0, kapacita je 5 a logicky vstup je 1
		 */
        InventarZbran();

        /**
		 *   Metoda, za pomoci ktere vlozime Item (Zbran), na volnou pozici
		 *   ve vektoru m_neseneZbraneInventar. Tedy vlozime z urcite Mistnosti
		 *   Zbran od urcitych souradnicich do Inventare Zbran.
		 */
		 void vlozeniZbran(Pozice2d* mojePozice,PoziceItem* mistniItem);

        /**
		 *   Tato metoda vyzaduje zadani, kterou Zbran chceme vyhodit, nasledne se zepta
		 *   na potvrzeni. Pote zjisti jestli v poli vektoru vubec nejaka Zbran je a nasledne
		 *   ji zahodi, neboli priradi poli prazdnou hodnotu.
		 */
        void zahodZbran(int druhZbrane);

        /**
		 *   Toto je metoda ktera nam pouze zobrazi hlasku, ze jsme obdrzeli novou Zbran
		 *   a zaroven vypise jeji bonusovou silu.
		 */
        void novaZbran(int druhZbrane);

        /**
		 * / Metoda, ktera vraci nazev Zbrane v inventari.
		 */
        std::string getNazevItemu();

        /**
		 * / Metoda, ktera vraci cislo Zbrane v inventari.
		 */
        int getCisloItemu();

        /**
		 * / Metoda, ktera vraci bonusovou silu Zbrane v inventari.
		 */
        int getBonusSila();

        /**
		 * / Metoda, ktera vraci hodnotu Zbrane v inventari.
		 */
        int getHodnotaItemu();

        /**
		 * / Metoda, ktera vraci bonusovou obranu Zbrane v inventari - vraci vzdy 0.
		 */
        int getBonusObrana();

        /**
		 * / Metoda, ktera vraci bonusove zivoty Zbrane v inventari - vraci vzdy 0.
		 */
        float getBonusZivoty();

        /**
		 * / Metoda, ktera vraci bonusove zkusenosti Zbrane v inventari - vraci vzdy 0.
		 */
        float getBonusZkusenosti();

        /**
		 *   Metoda, ktera nam za pomoci for cyklu vypise cely vektor Zbrani (Inventar Zbroj).
		 */
        void vypisZbran();
};
#endif
