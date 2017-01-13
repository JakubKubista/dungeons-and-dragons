#ifndef Zbran_h
#define Zbran_h
#include <iostream>

	/**
    * @brief Trida reprezentujici Zbran tridy Hrdina
    *
    * Trida je pevne spata se tridou Hrdina. Trida prebira hodnoty do atributu
    * ze tridy InventarZbran. Hrdina tuto Zbran vlastni pevne jiz od zacatku hry.
    * Prepisovani hodnot v atributech ma vypadat jako nahrazovani jednotlivych
    * Zbrani.
    */
class Zbran {

private:
		/**
		 * / Atributy, ktere ziskaji hodnotu, za pomoci poli ze tridy Inventar Zbran
		 */
        std::string m_nazevZbrane;
        int m_hodnotaZbrane;
        int m_bonusSily;

public:
		/**
		 *  Bezparametricky konstruktor, ktery se zavola pri vytvoreni tridy Hrdina
		 *  Ma predem dany nazev, bonus sily a hodnotu Zbrane. Atributy jsou minimalni
		 *  hodnoty a jsou vytvorene, aby aspon neco hrac ze startu mel.
		 */
        Zbran();

        /**
		 * / Metoda, ktera nam vraci nazev Zbrane Hrdiny
		 */
        std::string getNazevZbrane();

        /**
		 * / Metoda, ktera nam vraci hodnotu Zbrane Hrdiny
		 */
        int getHodnotaZbrane();

        /**
		 * / Metoda, ktera nam vraci bonus sily Zbrane Hrdiny
		 */
        int getBonusSily();

        /**
		 * / Metoda, za pomoci ktere nastavujeme nazev Zbrane Hrdiny
		 */
        void setNazevZbrane(std::string nazevZbrane);

        /**
		 * / Metoda, za pomoci ktere nastavujeme hodnotu Zbrane Hrdiny
		 */
        void setHodnotaZbrane(int hodnotaZbrane);

        /**
		 * / Metoda, za pomoci ktere nastavujeme bonus sily Zbrane Hrdiny
		 */
        void setBonusSily(int bonusSily);
};
#endif
