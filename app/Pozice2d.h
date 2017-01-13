#ifndef Pozice2d_h
#define Pozice2d_h
#include <iostream>

	/**
    * @brief Trida, ktera analyzuje lokaci, ve ktere se Hrdina nachazi
    *
    * Jelikoz je mapa vytvorena na zaklade matice, tak Hrdinovi musime vzdy priradit
    * urcity radek a sloupec, muzeme mu nastavit startovni pozici nebo nechat 0,0.
    * Vzdy se tride Hrdina meni Pozice2d jen o jednicku a to budto jen u sloupce
    * nebo u radku.
    */
struct Pozice2d {
		/**
		 * / Instance radku Pozice2d tridy Hrdina
		 */
        int m_radek;

		/**
		 * / Instance sloupce Pozice2d tridy Hrdina
		 */
        int m_sloupec;

public:
		/**
		 *   Bezparametricky konstruktor, ktery nam nastavi startovni
		 *   pozici Hrdiny na (0,0), kdyz hrdinu vytvorime.
		 */

        Pozice2d();
		/**
		 *   Parametricky konstruktor, diky kteremu muzeme nastavit
		 *   pozici Hrdiny na lib. radek a sloupec v Objektove Hraci Desce.
		 */
        Pozice2d(int radek, int sloupec);
		/**
		 * / Metoda, ktera nam vraci cislo radku
		 */
        int getRadek();

		/**
		 * / Metoda, ktera nam vraci cislo radku
		 */
        int getSloupec();

};
#endif
