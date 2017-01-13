#ifndef PoziceNPC_h
#define PoziceNPC_h
#include "NPC.h"
#include <vector>
#include <stdlib.h>

	/**
    * @brief Trida, ktera je zalozena na Objektove Hraci Deskce, slouzi k urceni pozic NPC.
    *
    */
class PoziceNPC {

	private:

		/**
		 * / Pozice Objektu, trida ktera obsahuje jednotlive pozice NPC.
		 */
		std::vector<std::vector< NPC*>> m_poziceNPC;

		/**
		 * / Pomocna promenna s poctem radku hraci desky pozic objektu.
		 */

		unsigned int m_pocetRadek;
		/**
		 * / Pomocna promenna s poctem sloupcu hraci desky pozic objektu.
		 */

		unsigned int m_pocetSloupcu;

	public:

		/**
		 * / Konstruktor, ketry vytvori prazdne pole o predane velikosti.
		 */
		PoziceNPC(const unsigned int pocetRadek, const unsigned int pocetSloupcu);

		/**
		 * / Pokud je to mozne, vrati NPC, ktery je na dane pozici.
		 */
		NPC* vratNPC(const unsigned int radek, const unsigned int sloupec);

		/**
		 * / Vlozi novy objekt, ktery je potomkem tridy NPC na pozici ve tride Pozice NPC.
		 */
		void vlozNPC(const unsigned int radek, const unsigned int sloupec, NPC* prisera);

		/**
		 * / Zjisti jestli dane NPC existuje.
		 */
		int zjistiNPC(const unsigned int radek, const unsigned int sloupec);
		/**
		 * / Hlaska, ze NPC neexistuje.
		 */
		void neniNPC();

        /**
		 * / Vrati pocet radek matice (maximalni index je o jedno mensi).
		 */
		int getPocetRadek();

		/**
		 * / Vrati pocet sloupcu matice (maximalni index je o jedno mensi).
		 */
		int getPocetSloupcu();

		/**
		 * @brief Metoda mazajici konkretni NPC.
		 *
        */
		void vymazKonkretniNPC(const unsigned int radek, const unsigned int sloupec);

		/**
		 * @brief Metoda mazajici jednotlive NPC.
		 *
		 * Tato metoda je trochu zvlastni. Obvykle maze objekty ten, kdo je vytvari
		 * Ale v tomto pripade by to bylo komplikovane, proto vznikla tato specialni
		 * cistici metoda.
		 */
		void vymazVsechnyNPC();
};
#endif
