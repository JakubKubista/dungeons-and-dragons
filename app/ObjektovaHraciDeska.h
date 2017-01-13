#ifndef ObektovaHraciDeska_h
#define ObektovaHraciDeska_h
#include "HraciPole.h"
#include "Pozice2d.h"
#include <stdlib.h>
#include <vector>
namespace modelHra {
	/**
 * @brief Trida reprezentuji hraci desku skladajici se z hernich poli, ktere jsou objekty
 *
 * Toto je nejdulezitejsi cast prikladu. Tato deska je schopna do sebe zapouzdrit zakladni
 * chovani hraci desky. Vas herni engine by mohl tuto desku vyuzivat. Vyresite tim skladovani
 * informaci o hernich polich a ziskate jiz nachystanou kostru pro polymorfni chovani.
 * Budete si moci odvodit ruzne dalsi vlastni potomky tridy HraciPole a udelat tak desku
 * plnou ruznych hernich "kamenu". Samozrejme si libovolne doplnujte funkcionalitu zejmena
 * do trody HerniPole, aby hra fungovala jak potrebujete.
 */
class ObjektovaHraciDeska {

	private:
		/**
		 * / Hraci deska, ktera obsahuje jednotliva herni pole
		 */
		std::vector<std::vector< HraciPole*>> m_deska;
		/**
		 * / Pomocna promenna s poctem radku hraci desky
		 */
		unsigned int m_pocetRadek;
		/**
		 * / Pomocna promenna s poctem sloupcu hraci desky
		 */
		unsigned int m_pocetSloupcu;

	public:
		/**
		 * / Konstruktor, ketry vytvori prazdne pole o predane velikosti
		 */
		ObjektovaHraciDeska(const unsigned int pocetRadek, const unsigned int pocetSloupcu);

		/**
		 * / Pokud je to mozne, vrati objekt, ktery je na dane pozici v herni desce
		 */
		modelHra::HraciPole* vrat(const unsigned int radek, const unsigned int sloupec, Pozice2d* mojePozice);

		/**
		 * / Vlozi novy objekt, ktery je potomkem tridy HraciPole na pozici v desce
		 */
		void vloz(const unsigned int radek, const unsigned int sloupec, HraciPole* pole);

		/**
		 * / Zjisti za objekt je nebo neni v desce
		 */
		int zjisti(const unsigned int radek, const unsigned int sloupec);

		/**
		 * / Pri zjisteni ze neni vypise chybovou chlasku
		 */
		void vypisError(const unsigned int radek, const unsigned int sloupe);

        /**
		 * / Vrati pocet radek matice (maximalni index je o jedno mensi)
		 */
		int getPocetRadek();

		/**
		 * / Vrati pocet sloupcu matice (maximalni index je o jedno mensi)
		 */
		int getPocetSloupcu();

		/**
		 * / Vypise popisy jednotlivych hracich poli, vcetne jejich obtiznosti na obrazovku
		 */
		void vypisDesku();

		/**
		 * / Vypise navrh kompletni mapy se vsemi castmi
		 */
        void vypisMapu();

		/**
		 * / Vypise popisy jednotlivych odpocivadel, vcetne jejich souradnic
		 */
        void odpocivadla();

		/**
		 * @brief Metoda mazajici jednotliva herni pole
		 *
		 * Tato metoda je trochu zvlastni. Obvykle maze objekty ten, kdo je vytvari
		 * Ale v tomto pripade by to bylo komplikovane, proto vznikla tato specialni
		 * cistici metoda.
		 */
		void vymazDesku();
	};
}
#endif
