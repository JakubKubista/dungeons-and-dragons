#ifndef MenuGUI_h
#define MenuGUI_h
#include "Pozice2d.h"
#include "Hrdina.h"
#include "HrdinaDirector.h"
#include "Mistnost.h"
#include "ObjektovaHraciDeska.h"

	/**
    * @brief Trida, ktera ma za ucel zkraceni kodu ve tride CivEngine.
    *
    * V teto tride se nachazi vetsinou jednotlive textove casti metody
    * vypisMoznostiGui, ktera se nachazi ve tride CivEngine.
    */
class MenuGUI {

public:

        /**
		 *   Metoda nejdrive smaze predeslou obrazovku a pote vypise
		 *   nadpis hlavni herni nabidky Dungeons and Dragons
		 */
        void nadpisGUI();

        /**
		 *   Metoda zavola metodu nadpisGUI, zobrazi ze tridy Hrdina
		 *   jeho jmeno a uroven, take zobrazi ze tridy Objektova Hraci
		 *   Deska jmeno mistni Mistnosti a jeji souradnice. Nakonec
		 *   zobrazi text a obrazek - nabidku hlavni hry bez casu.
		 */
        void vypisMenuGUI(Hrdina* hero, HrdinaDirector* director,Pozice2d* mojePozice,modelHra::ObjektovaHraciDeska* m_hraciDeska);

        /**
		 *   Tuto metodu volame ve tride CivEngine pokazde kdyz zadame
		 *   spatnou odpoved pro vstup v nabidce.
		 */
        void spatne();

};
#endif
