#ifndef Boj_h
#define Boj_h
#include "InterakceNPC.h"
#include <stdlib.h>

	/**
    * @brief Trida, u ktere byly ocekavany cca 4 metody, ale pro prehledny a
    * originalni boj ve hre bez grafickeho rozhrani byla vytvorena komplexnejsi moznost.
    *
    * Dedi vsechny metody z Abstraktni tridy InterakceNPC
    */

class Boj : public InterakceNPC {

private:
		/**
		 *  Hrdinovy i NPC atributy ktere budeme modifikovat predame do fiktivnich
		 *  atributu, protoze jsou privatni. Ostatni atributy jsou pro zprehledneni boje
		 */
        float m_aktualniZivotyHrdina;
        float m_aktualniZivotyNPC;
        int m_koloBitvy;
        int m_aktualniAnkVzkriseni;
        float m_ziskaneZkusenosti;

public:
		/**
		 * / Konstruktor boje, ktery preda popis danemu atributu popis
		 */
        Boj(std::string popis);

private:
		/**
		 * / Metoda, ktera vola nadpis naseho boje
		 */
        void nadpisBoj();

		/**
		 * / Metoda, ktera nam zobrazi Vitezstvi pocet nabytych zkusenosti z boje
		 */
        void vypisVitezstvi();

		/**
		 * / Metoda, ktera nam zobrazi Prohru po ztraceni vsech zivotu
		 */
        void vypisProhru();

public:
		/**
		 * / Metoda, ktera nam po nabiti potrebnych zkusenosti zobrazi novou uroven a bonus atributy
		 */
        void zvyseniUrovne(int uroven, int magie);

		/**
		 * / Metoda, ktera se nam zobrazi po ztrate vsech Anku Vzkriseni
		 */
        void konecHry();

		/**
		 * / Metoda, ve ktere nastavime aktualni zivoty Hrdiny - skrz predavani atributu z boje do Hrdiny
		 */
        void setAktualniZivotyHrdina(float aktualniZivotyHrdina);

		/**
		 * / Metoda, ve ktere nastavime aktualni zivoty NPC - skrz predavani atributu z boje do NPC
		 */
        void setAktualniZivotyNPC(float aktualniZivotyNPC);

		/**
		 * /  Metoda, ve ktere nastavime aktualni kolo bitvy
		 */
        void setKolo(int koloBitvy);

		/**
		 * /  Metoda, ve ktere nastavime zisk zkusenosti z boje, ktere vezmeme z atributu NPC a predame Hrdinovi
		 */
        void setZiskZkusenosti(float ziskZkusenosti);

		/**
		 * /  Metoda, ve ktere nastavime pocet Anku Vzkriseni - opet predame Hrdinovi
		 */
        void setAktualniAnkVzkriseni(int aktualniAnkVzkriseni);

		/**
		 * /  Metoda, ktera vraci aktualni pocet Zivotu Hrdiny
		 */
        float getAktualniZivotyHrdina();

		/**
		 * / Metoda, ktera vraci aktualni pocet Zivotu NPC
		 */
        float getAktualniZivotyNPC();

		/**
		 * / Metoda, ktera vraci aktualni pocet Anku Vzkriseni
		 */
        int getAktualniAnkVzkriseni();

		/**
		 * / Metoda, ktera vraci Zisk Zkusenosti z nynejsiho boje
		 */
        float getZiskZkusenosti();

		/**
		 * / Metoda, ktera preda z Mistniho NPC do atributu pocet Zkusenosti, ktere predavame Hrdinovi
		 */
        void ziskejZkusenosti(Pozice2d* mojePozice,PoziceNPC* mistniNPC);

		/**
		 *  Komplexni metoda, ktera ridy cely boj, po predani vsech potrebnych atributu zjistime
		 *  pomoci vzorce uder Hrdiny a NPC, ktery pak odebira Zivoty. Na prvni pohled ve hre se zda ze
		 *  je boj resen pres cyklus, ale jsou to ciste podminky. Po povrzeni ze chceme utocit nejdrive
		 *  Hrdina ubere Zivoty NPC a pokud to NPC prezilo tak to hrdinovy oplati, pomoci jejich uderu
		 *  nakonec je hrdina bud porazen a zavola se metoda Prohra nebo utece nebo Vitezi
		 */
        void zautoc(Pozice2d* mojePozice,PoziceNPC* mistniNPC,float maxZivotyH,int silaH,int obranaH,int magieH,int urovenH,std::string jmenoH);
};
#endif
