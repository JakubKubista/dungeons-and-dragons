#ifndef MoznostiPohybu_h
#define MoznostiPobybu_h
#include "MenuGUI.h"
#include "Pozice2d.h"
#include "Hrdina.h"
#include "ObjektovaHraciDeska.h"
#include <iostream>
#include <stdlib.h>

	/**
    * @brief Trida reprezentujici system pohybu ve hre
    *
    * Napadu na vytvoreni pohybu bylo opravdu mnoho a uznavam ze toto
    * reseni, co se objektoveho navrhu tyce neni rozhodne vzorove,
    * presto sestaveni pohybu je staticke a pevne dane. Bylo narocne
    * vytvorit logicke vyrazy tak aby byl pohyb bezchybny, ale pro pekne
    * menu, ktere metoda obsahuje jsem se rozhodl pro tuto variantu.
    * Pro vetsi mapu bych metodu rozhodne zmenil.
    */
class MoznostiPohybu {


private:
		/**
		 * / Metoda vypisujici nadpis danych Moznosti Pohybu.
		 */
    void nadpisPohyb();

		/**
		 *   Metoda vypisujici cast mapy ,ve ktere se nachazime.
		 *   Orientovat se muzeme za pomoci indexu
		 */
    void mapaPohyb();

		/**
		 *   Dlouha, presto originalni a ucina metoda, ktera organizuje moznosti pohybu
		 *   v Objektove Hraci Desce. Omluva za dlouhy neroztrideny kod metody. Nejdrive
		 *   zavola metodu nadpisPohyb a dale za pomoci logickych operaci zobrazi kam se
		 *   muzeme z dane lokace dostat. Logicke operace jsou dlouhe a snadno se v nich
		 *   udela chyba pri takove sirce, proto jsou nekolikanasobne kontrolovany.
		 *   Vzdy je moznost jit zpet do hlavni nabidky. Pod timto vystupem je volana
		 *   metoda mapaPohyb. Nyni za pomoci prikazu case, zvolime jestli chceme jit
		 *   vlevo, vpravo, nahoru nebo dolu (podle toho co se zobrazi). A po stisknuti
		 *   je metoda znovu osetrena za pomoci logickych operaci a presune nas do
		 *   Mistnosti, ve ktere chceme byt, pokud na ni mame pozadovanou uroven.
		 */
public:

	void vypisPohyb(Hrdina* hero,Pozice2d* mojePozice,modelHra::ObjektovaHraciDeska* deska);

};
#endif
