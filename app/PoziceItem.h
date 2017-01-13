#ifndef PoziceItem_h
#define PoziceItem_h
#include "Item.h"
#include <vector>
#include <stdlib.h>

	/**
    * @brief Trida, ktera je zalozena na Objektove Hraci Deskce, slouzi k urceni pozic Itemu
    *
    */
class PoziceItem {

	private:
		/**
		 * / Pozice Objektu, trida ktera obsahuje jednotlive pozice Itemù
		 */

		std::vector<std::vector< Item*>> m_poziceItem;
		/**
		 * / Pomocna promenna s poctem radku hraci desky pozic objektu
		 */

		unsigned int m_pocetRadek;
		/**
		 * / Pomocna promenna s poctem sloupcu hraci desky pozic objektu
		 */
		unsigned int m_pocetSloupcu;

	public:

		/**
		 * / Konstruktor, ketry vytvori prazdne pole o predane velikosti
		 */
		PoziceItem(const unsigned int pocetRadek, const unsigned int pocetSloupcu);

		/**
		 * / Pokud je to mozne, vrati Item, ktery je na dane pozici
		 */
		Item* vratItem(const unsigned int radek, const unsigned int sloupec);

		/**
		 * / Vlozi novy objekt, ktery je potomkem tridy Item na pozici ve tride Pozice Item
		 */
		void vlozItem(const unsigned int radek, const unsigned int sloupec, Item* vec);

		/**
		 * / Zjisti jestli dany Item existuje
		 */
		int zjistiItem(const unsigned int radek, const unsigned int sloupec);

		/**
		 * / Hlaska, ze Item neexistuje
		 */
		void neniItem();

        /**
		 * / Vrati pocet radek matice (maximalni index je o jedno mensi)
		 */
		int getPocetRadek();

		/**
		 * / Vrati pocet sloupcu matice (maximalni index je o jedno mensi)
		 */

		int getPocetSloupcu();

		/**
		 * Metoda mazajici konkretni Item
		 *
        */
		void vymazKonkretniItem(const unsigned int radek, const unsigned int sloupec);

		/**
		 * Metoda mazajici jednotlive Itemy
		 *
		 * Tato metoda je trochu zvlastni. Obvykle maze objekty ten, kdo je vytvari
		 * Ale v tomto pripade by to bylo komplikovane, proto vznikla tato specialni
		 * cistici metoda.
		 */
		void vymazVsechnyItemy();
};
#endif
