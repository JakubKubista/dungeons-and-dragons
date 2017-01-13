#ifndef LokaceItem_h
#define LokaceItem_h
#include "MenuGUI.h"
#include "Pozice2d.h"
#include "Hrdina.h"
#include "PoziceItem.h"
#include <iostream>
#include <stdlib.h>

	/**
    * @brief Trida, ktera ma za ucel propojit a osetrit propojeni mezi Itemem
    * v Mistnosti a mezi Hrdinou. U vetsiny metod se jedna spise o vystup textu.
    */
class LokaceItem {

private:
		/**
		 *   Tento atribut slouzi k opakovani, pokud je spatne zadana operace,
		 *   aby se nam nezobrazobrazoval porad dokola obrazek o nalezeni.
		 */
        int m_logickeCislo;

        /**
		 * / Metoda, ktera nam zobrazi nadpis Mistni Lokace.
		 */
        void nadpisItem();

        /**
		 * / Metoda, ktera zobrazi obrazek o nalezeni pokud v dane Mistnosti je Item.
		 */
        void obrazekItem();

        /**
		 *   Metoda, ktera nam vypise detailni informace o Itemu za pomoci trid
		 *   PoziceItem a Pozice2d.
		 */
        void itemInfo(Pozice2d* mojePozice,PoziceItem* mistniItem);
public:
        /**
		 * / Metoda, ktera nam nastavi po kolikate se snimek o nalezeni opakuje.
		 */
		void setOpakovani(int logickeCislo);

        /**
		 * / Metoda, ktera nam vrati kolikrat se metoda opakuje.
		 */
        int getOpakovani();

        /**
		 *   Metoda, kvuli ktere je cela trida LokaceItem vytvorena. Nejdrive zjisti,
		 *   jestli se v dane Mistnosti o urcitych souradnicich nejaky Item nachazi.
		 *   Pote se odkaze na Hrdinovu metodu integrujItem. Cela metoda je osetrena
		 *   za pomoci podminek, pro spatne zadavani apod.
		 */
        void vypisItemy(Hrdina* hero,Pozice2d* mojePozice,PoziceItem* mistniItem);

};
#endif
