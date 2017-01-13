#ifndef CivEngine_h
#define CivEngine_h
#include "HraciDeska.h"
#include "ObjektovaHraciDeska.h"
#include "Hrdina.h"
#include "HrdinaDirector.h"
#include "MenuGUI.h"
#include "MoznostiPohybu.h"
#include "Pozice2d.h"
#include <iostream>
#include <stdlib.h>


namespace modelHra {
	/**
    * @brief Trida reprezentujici fiktivni herni engine.
    *
    * Je zde demonstrovano jak pouzit objektovou herni desku pro ulozeni poli.
    * Veskere metody teto tridy, u kterych to bylo mozne jsou private zaroven ma trida
    * uvodni nabidku po spusteni programu a GUI nabidku, ktera vola radu metod pro
    * pohyb po mape, ruzne vypisy, inventare apod.
    * Pred rozdelenim kodu do jednotlivych casti mela tato trida pres 400 radku.
    */
class CivEngine {

	private:
		/**
		 * / Instance objektove herni desky, ktera ponese vsechna herni pole
		 */
		modelHra::ObjektovaHraciDeska* m_hraciDeska;

	public:
		/**
		 * / Konstruktor volajici inicializaci herni desky
		 */
		CivEngine();

	private:
		/**
		 * / Fiktivni metoda, ktera pouze vraci ObjektovouHraciDesku
		 */
        modelHra::ObjektovaHraciDeska* getDeska();

	public:
		/**
		 *  Primarni metoda cele hry, ve ktere volime nacteni hry, pokracovani nebo ukonceni.
		 *  Z teto metody se odvyji veskere ostatni potrebne tridy a metody hry. Zaroven
		 *  nam vytvari Hrdinu, jeho directora a pozici, nabidka funguje pres while cyklus.
		 */
		void hrej();

		/**
		 * / Desktruktor rusici jednotlive prvky herni plochy
		 */
		~CivEngine();

	private:
		/**
		 * @brief Naplni jednotlive bunky hraci desky objekty
		 *
		 * Soukroma metoda, ktera fyzicky vytvori jednotlive casti hraci plochy
		 * Tato metoda je velmi trivialni. Bylo by pekne ji napojit treba
		 * na tridu HraciDeska a vytvorit pole podle hodnot v souboru.
		 * Ale tim se pro zacatek netrapte.
		 */
		void inicializujBunkyPole();
		/**
		 *
		 * Metoda, obsahujici nabidku ktera vola velkou skalu metod v ruznych tridak
		 * funguje jako fiktivni menu, snaha o prehlednost, originalitu a provazanost.
		 * U teto metody byl nejvetsi problem ji zkratit na dany pocet radku, pred
		 * rozdelenim par metod do jednotlivych trid nabyvala cca 500 radku.
		 */
		void vypisMoznostiGui(Hrdina* hero,Pozice2d* mojePozice,HrdinaDirector* director);

	};
}
#endif
