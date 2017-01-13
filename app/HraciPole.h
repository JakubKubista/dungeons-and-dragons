#ifndef HraciPole_h
#define HraciPole_h
#include <iostream>
#include "Pozice2d.h"
#include "Hrdina.h"
namespace modelHra {
	/**
 * @brief Abstraktni trida predstavujici obecne herni pole
 *
 * Tato trida predstavuje obecne hraci pole. Toto pole se pouziva pouze pro
 * dedeni ruznych konkretnich typu hracich poli. Slouzi hlavne k tomu, abychom
 * mohli mit univerzalni ukazatel na libovolne hraci pole, dosadili si za nej
 * co uzname za vhodne a pak provolavali ruzne implementace metod (polym.).
 * Vytvarejte si vlastni potomky a doplnujte atributy a metody podle potreby.
 */
class HraciPole {

	protected:
		/**
		 * / Testovaci atribut, ktery se dedi do vsech potomku
		 */
		std::string m_popis;
		int m_obtiznost;

	public:
		HraciPole(std::string popis, int obtiznost);

		/**
		 * / Testovaci metoda, ktera se dedi do vsech potomku
		 */
		virtual std::string getPopis() = 0;

		/**
		 * / Testovaci metoda, ktera se dedi do vsech potomku
		 */
		virtual int getObtiznost() = 0;

    private:
		/**
		 * / Testovaci metoda, ktera se dedi do vsech potomku
		 */
        virtual void inicializujVsechnyItemy() = 0;

		/**
		 * / Testovaci metoda, ktera se dedi do vsech potomku
		 */
        virtual void inicializujVsechnyNPC() = 0;

		/**
		 * @brief Metoda vracejici obranny bonus pro bojove jednotky, ktere na ni stoji
		 *
		 * Toto je zcela nesmyslna metoda, jen ilustruje polymorfni chovani poli
		 * na hraci desce - kazde pole nyni musi vracet obr. bonus vypocteny
		 * podle nejakeho kriteria - pro les se pocita jinak, pro pole jinak atp.
		 * Pokud by existovala nejaka univerzalni metoda vypoctu, kterou by pouzivala
		 * vetsina poli, tak bychom ji udelali pouze virtualni a pouze v nekterem
		 * potomkovi prekryli.
		 */

    public:
		virtual void vypisMenu(Hrdina* hero,Pozice2d* mojePozice) = 0;

		/**
		 * / Tridy, ktere budou mit potomky by mely mit virt. dest., pak se zavola vzdy destruktor spravneho potomka
		 */
		virtual ~HraciPole();
	};
}
#endif
