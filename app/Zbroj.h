#ifndef Zbroj_h
#define Zbroj_h
#include <iostream>

	/**
    * @brief Trida reprezentujici Zbroj tridy Hrdina
    *
    * Trida je pevne spata se tridou Hrdina. Trida prebira hodnoty do atributu
    * ze tridy InventarZbroj. Hrdina tuto Zbroj vlastni pevne jiz od zacatku hry.
    * Prepisovani hodnot v atributech ma vypadat jako nahrazovani jednotlivych
    * Zbroji.
    */
class Zbroj {

private:
		/**
		 * / Atributy, ktere ziskaji hodnotu, za pomoci poli ze tridy Inventar Zbroj
		 */
	std::string m_nazevZbroje;
	int m_hodnotaZbroje;
	int m_bonusObrany;

public:
		/**
		 *  Bezparametricky konstruktor, ktery se zavola pri vytvoreni tridy Hrdina
		 *  Ma predem dany nazev, bonus sily a hodnotu Zbroje. Atributy jsou minimalni
		 *  hodnoty a jsou vytvorene, aby aspon neco hrac ze startu mel.
		 */
	Zbroj();

        /**
		 * / Metoda, ktera nam vraci nazev Zbroje Hrdiny
		 */
        std::string getNazevZbroje();

        /**
		 * / Metoda, ktera nam vraci hodnotu Zbroje Hrdiny
		 */
        int getHodnotaZbroje();

        /**
		 * / Metoda, ktera nam vraci bonus obrany Zbroje Hrdiny
		 */
        int getBonusObrany();

        /**
		 * / Metoda, za pomoci ktere nastavujeme nazev Zbroje Hrdiny
		 */
        void setNazevZbroje(std::string nazevZbroje);

        /**
		 * / Metoda, za pomoci ktere nastavujeme hodnotu Zbroje Hrdiny
		 */
        void setHodnotaZbroje(int hodnotaZbroje);

        /**
		 * / Metoda, za pomoci ktere nastavujeme bonus obrany Zbroje Hrdiny
		 */
        void setBonusObrany(int bonusObrany);
};
#endif
