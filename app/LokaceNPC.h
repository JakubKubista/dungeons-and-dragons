#ifndef LokaceNPC_h
#define LokaceNPC_h
#include "MenuGUI.h"
#include "Pozice2d.h"
#include "Hrdina.h"
#include "PoziceNPC.h"
#include <iostream>
#include <stdlib.h>

	/**
    * @brief Trida, ktera ma za ucel propojit a osetrit propojeni mezi NPC
    * v Mistnosti a mezi Hrdinou. U vetsiny metod se jedna spise o vystup textu.
    */
class LokaceNPC {

private:
        /**
		 * / Metoda, ktera nam zobrazi nadpis Mistni Lokace.
		 */
        void nadpisNPC();

        /**
		 * / Metoda, ktera nam zobrazi nadpis BITVA.
		 */
        void nadpisBitva();

        /**
		 * / Metoda, ktera zobrazi obrazek o nalezeni pokud v dane Mistnosti je Item.
		 */
        void obrazekNPC();
public:
        /**
		 *   Metoda, kvuli ktere je cela trida LokaceNPC vytvorena. Nejdrive zjisti,
		 *   jestli se v dane Mistnosti o urcitych souradnicich nejake NPC nachazi.
		 *   Pote se odkaze na Hrdinovu metodu integrujNPC.
		 */
        void vypisNPC(Hrdina* hero,Pozice2d* mojePozice,PoziceNPC* mistniNPC);

};
#endif
