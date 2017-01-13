#ifndef HraciDeska_h
#define HraciDeska_h
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
namespace modelHra {
	/**
 * @brief Dvojrozmerne pole cisel, ktere ma schopnost ulozit se do souboru a nacist se z nej
 *
 * Predstavuje tridu, kterou lze pouzit pro ukladani informaci o stavu hry do textoveho souboru.
 * Jak funguje vas nemusi zajimat. Dulezite je pouze rozhranni, ktere mate v hlavickovem souboru.
 */
class HraciDeska {

	private:
		/**
		 * / Hraci deska, ktera obsahuje pole cisel
		 */
		std::vector<std::vector<int>> m_deska;
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
		 * / Konstruktor, ktery vytvori pole prislusne velikosti a nastavi do kazde bunky nulovaci prvek
		 */
		HraciDeska(const unsigned int pocetRadek, const unsigned int pocetSloupcu, const int nulovaciPrvek);

    private:
		/**
		 * / Vrati cislo na pozici na prislusnem radku a v prislusnem sloupci
		 */
		int vrat(const unsigned int radek, const unsigned int sloupec);

		/**
		 * / Vlozi cislo na pozici na prislusnem radku a v prislusnem sloupci
		 */
		void vloz(const unsigned int radek, const unsigned int sloupec, const int prvek);

    public:
		/**
		 *   Ulozi cele pole do textoveho souboru. Nedoladeno po nekolikahodinovem
		 *   zkouseni jsem tuto metodu zavrhl. Jedine mozne reseni bylo ulozit po radcich
		 *   primo metody Hrdiny do souboru.
		 */
		void ulozDoTextovehoSouboru(const std::string cesta);

    private:
		/**
		 * / Nacte cele pole z textoveho souboru. Nedoladeno po nekolikahodinovem
		 *   zkouseni jsem tuto metodu zavrhl. Jedine mozne reseni bylo nacist po radcich
		 *   primo metody Hrdiny ze souboru.
		 */
		void nactiZTextovehoSouboru(const std::string cesta);

    public:
		/**
		 * / Vraci aktualni pocet radek pole
		 */
		int getPocetRadek();

		/**
		 * / Vraci aktualni pocet skloupcu pole
		 */
		int getPocetSloupcu();

    private:
		/**
		 * / Vypise obsah aktualniho hraciho pole na obrazovku
		 */
		void vypisDesku();

    public:
		/**
		 * / Vypise text uvodni nabidky ze ktere se hra odviji
		 */
		void lebka();

		/**
		 * / Vypise navod se stejnou lebkou jako pri uvodu
		 */
		void lebkaNavod();

	};
}
#endif
