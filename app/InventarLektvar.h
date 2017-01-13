#ifndef InventarLektvar_h
#define InventarLektvar_h
#include "Pozice2d.h"
#include "PoziceItem.h"
#include "Item.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
class InventarLektvar {

	/**
    * @brief Trida reprezentujici Inventar Lektvaru.
    *
    * Tato trida ma urcity pocet Lektvaru, ktere jsou definovany jako vektor.
    * Trida ma urcitou kapacitu, ktera je nastavena v konstruktoru. Jednotlive Lektvary
    * jsou do vektoru umisteny z urcite pozice Itemu. Kazde pole vektoru odpovida jednomu
    * vlozenemu Lektvaru. Obsahuje metody vkladani, piti a zahazovani jednotlivych Lektvaru.
    * Trida je urcena pro Hrdinu, ktery ji vlastni pod atributem m_inventarLektvar.
    * Jednotlive metody jsou volany jak v trdie Hrdina v pomocne tride Hrdiny, ktera
    * ma nazev Hrdina Director.
    */
private:
		/**
		 * / Atributy, ktere jsou potrebne pro urceni poctu Lektvaru a kapacity.
		 */
        int m_pocet;
        int m_kapacita;

		/**
		 *  Pri vlozeni prvniho Lektvaru do Inventare Lektvaru nebylo mozne zobratit
		 *  upozornujici okno, proto byl atribut vytvoren, pomoci ktereho je to mozne.
		 */
        int m_logickyVstup;

		/**
		 * / Atributy, urcujici cislo, bonusove zivoty, bonusove zkusenosti a hodnotu Itemu.
		 */
        std::string m_nazevItemu;
        int m_cisloItemu;
        float m_bonusZivoty;
        float m_bonusZkusenosti;
        int m_hodnotaItemu;

		/**
		 * / Atribut, typu vekter, diky kteremu muze Inventar Lektvar obsahovat vice Lektvaru.
		 */
        std::vector<Item*> m_neseneLektvaryInventar;

public:

/*
// Timto kodem v komentari bych rad sdelil, ze nespocet hodin jsem se snazil
// udelat inventare tak, aby jsme ho z mapy odstranili - delete
// a v inventari vytvorily novy se stejnymi hodnotami, ktere predame.
// Ale po dvou dnech snahy o prosazeni vektoru, do ktereho pridavame objekty
// tak jako do mapy, jsem byl nucen odstoupit od teto metodiky.
// Tento zpusob jsem chtel aplikovat i na ostatni inventare

-----------------------------------------------------------------------------------
		/**
		 * / Konstruktor, ketry vytvori prazdne pole o predane velikosti
		 */
/*		InventarLektvar(const unsigned int pocet);

		/**
		 * / Pokud je to mozne, vrati Item, ktery je na dane pozici
		 */
/*		HrdinuvItem* vratLektvar(const unsigned int id);

		/**
		 * / Vlozi novy objekt, ktery je potomkem tridy Item na pozici ve tride Pozice Item
		 */
/*		void vlozLektvar(const unsigned int id, HrdinuvItem* novyItem);

		/**
		 * / Zjisti jestli dany Item existuje
		 */
/*		int zjistiLektvar(const unsigned int id);

        /**
		 * / Vypise obsah aktualniho hraciho pole na obrazovku
		 */
/*		void vypisLektvar();
-----------------------------------------------------------------------------------
*/
		/**
		 *  Bezparametricky konstruktor, ktery se vytvori pri vytvoreni Hrdiny
		 *  Pocet Lektvaru nastaven na 0, kapacita je 5 a logicky vstup je 1.
		 */
        InventarLektvar();

        /**
		 * / Metoda, ktera nam zobrazi pouze nadpis daneho Inventare.
		 */
        void nadpisLektvar();

        /**
		 *   Metoda, za pomoci ktere vlozime Item (Lektvar), na volnou pozici
		 *   ve vektoru m_neseneLektvaryInventar. Tedy vlozime z urcite Mistnosti
		 *   Lektvar od urcitych souradnicich do Inventare Lektvar.
		 */
        void vlozeniLektvar(Pozice2d* mojePozice,PoziceItem* mistniItem);

        /**
		 *   Uvedena metoda nejdriv nastavi Bonusove Zkusenosti a Bonusove Zivoty na 0.
		 *   Protoze tyto hodnoty predavame z getru Hrdinovi a mohou byt pokazde jine.
		 *   Piti lektvaru funguje tak, ze ve tride Hrdina Director zadane cislo Lektvaru
		 *   v Inventar Lektvar, ktery chceme pit.
		 *   Pote zjistime jestli jsme nezadali cislo presahujici vektor a zda pod cislem
		 *   vubec nejaky lektvar je. Nasledne zjisti jestli se jedna o Lektvar Zkusenosti
		 *   ci o Lektvar Zdravi a prida hodnoty do daneho atributu. Nakonec snizi pocet
		 *   Lektvaru v Inventari Lektvaru.
		 */
        void prubehPitiLektvaru(int druhLektvaru);

        /**
		 *   Tato metoda vyzaduje zadani, ktery Lektvar chceme vyhodit, nasledne se zepta
		 *   na potvrzeni. Pote zjisti jestli v poli vektoru vubec nejaky Lektvar je a nasledne
		 *   ho zahodi, neboli priradi poli prazdnou hodnotu.
		 */
        void zahodLektvar(int druhLektvaru);

        /**
		 *   Metoda, ktera nastavi pocet bonusovych zivotu z Lektvaru. Nejdrive ji zavola Hrdina
		 *   a nastavi ji na 0, a to Pred pouzitim metody prubehPitiLektvaru. Pri pouziti ji nastavi
		 *   na hodnotu bonusovych zivotu Lektvaru v Inventar Lektvar.
		 */
        void setBonusZivoty(float bonusZivoty);

        /**
		 * / Pouziti stejne jako u metody setBonusZivoty, akorad nyni nastavujeme bonusove zkusenosti.
		 */
        void setBonusZkusenosti(float bonusZkusenosti);

        /**
		 * / Metoda, ktera vraci nazev daneho Lektvaru v inventari.
		 */
        std::string getNazevItemu();

        /**
		 * / Metoda, ktera vraci cislo daneho Lektvaru v inventari.
		 */
        int getCisloItemu();

        /**
		 * / Metoda, ktera vraci bonusove zivoty daneho Lektvaru v inventari.
		 */
        float getBonusZivoty();

        /**
		 * / Metoda, ktera vraci bonusove zkusenosti daneho Lektvaru v inventari.
		 */
        float getBonusZkusenosti();

        /**
		 * / Metoda, ktera vraci hodnotu daneho Lektvaru v inventari.
		 */
        int getHodnotaItemu();

        /**
		 * / Metoda, ktera vraci bonusovou obranu daneho Lektvaru v inventari - vraci vzdy 0.
		 */
        int getBonusObrana();

        /**
		 * / Metoda, ktera vraci bonusovou silu daneho Lektvaru v inventari - vraci vzdy 0.
		 */
        int getBonusSila();

        /**
		 * / Metoda, ktera vraci pocet Lektvaru v inventari.
		 */
        int getPocet();

        /**
		 * / Metoda, ktera vraci kapacitu Lektvaru v inventari.
		 */
        int getKapacita();

        /**
		 *   Metoda, ktera nam za pomoci for cyklu vypise cely vektor Lektvaru (Inventar Lektvar).
		 */
        void vypisLektvar();

};
#endif
