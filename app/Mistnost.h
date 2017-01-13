#ifndef Mistnost_h
#define Mistnost_h
#include "HraciPole.h"
#include "Pozice2d.h"
#include "PoziceItem.h"
#include "PoziceNPC.h"
#include "Hrdina.h"
#include "ItemLektvar.h"
#include "ItemZbroj.h"
#include "ItemZbran.h"
#include "LokaceItem.h"
#include "LokaceNPC.h"
#include "Drak.h"
#include "Ork.h"
#include "Vlk.h"
#include <stdlib.h>

	/**
    * @brief Trida jenz je potomkem tridy NPC, dedi jeji ciste virtualni metody a jeji atributy
    *
    * Trida, ktera se podoba tride CivEngine, diky inicializaci jednotlivych objektu.
    * Jedna se o inicializaci dvou matic, pro prehlednost kde se nachazi NPC a kde item
    */
class Mistnost : public modelHra::HraciPole {

private:

		/**
		 * / Instance pozic objektu lokaci, ktery ponese vsechny Itemy
		 */
		PoziceItem* m_vsechnyItemy;

		/**
		 * / Instance pozic objektu lokaci, ktery ponese vsechny NPC
		 */
		PoziceNPC* m_vsechnyNPC;

public:

		/**
		 * / Konstruktor volajici inicializaci jak jednotlivych NPC tak Itemu
		 */
	Mistnost(std::string popis,int obtiznost);

		/**
		 * / Vraci popis mistnosti (daneho objektu v mistnosti)
		 */
	std::string getPopis();

		/**
		 * / Vraci obtiznost mistnosti (daneho objektu v mistnosti)
		 */
	int getObtiznost();

private:
		/**
		 *  Naplni jednotlive bunky ve tridach PoziceItem objekty - Itemy
		 *
		 */
    void inicializujVsechnyItemy();

		/**
		 *  Naplni jednotlive bunky ve tridach PoziceNPC objekty - NPC (Nepratele)
		 *
		 */
    void inicializujVsechnyNPC();

		/**
		 * Velice dulezita metoda, ktera zjisti zda v Mistnosti je ci neni objekt, kdyz
		 * zde objekt je, prednost ma NPC, kvuli rychlejsimu nabirani zkusenosti
		 * Metoda dale vola tridy LokaceItem a LokaceNPC ktere mohli byt soucasti,
		 * ale kvuli skraceni kodu v jedne tride museli byt vytvoreny
		 *
		 */

public:

		/**
		 * Metoda, ve ktere potrebujeme fiktivni parametry Hrdiny a Pozice2d. Zjisti nam
		 * jestli je v dane mistnosti nejaky objekt (NPC/Item). Prednost ma NPC (nepritel),
		 * proto se v podmince nejdrive zepta na nej a pote na Item (vec), pokud neni ani jedno,
		 * vypise hlasku, pokud se nachazi NPC, spusti se interakce Boj. Pokud se nachazi Item
		 * tak mame 33% sanci, ze na nej narazime, pomoci nahodneho generatoru, pokud na nej narazime
		 * spusti se nam ze tridy Hrdiny metoda o pridani Itemu do inventare.
		 *
		 */
	void vypisMenu(Hrdina* hero,Pozice2d* mojePozice);

		/**
		 * / Desktruktor rusici jednotlive objekty
		 */
    ~Mistnost();
};
#endif
