#ifndef HrdinaDirector_h
#define HrdinaDirector_h
#include "Hrdina.h"
#include "Bojovnik.h"
#include "Lovec.h"
#include "Mag.h"
#include "ObjektovaHraciDeska.h"
#include "InventarLektvar.h"
#include "InventarZbran.h"
#include "InventarZbroj.h"
#include <iostream>
#include <stdlib.h>
	/**
    * @brief Trida, jejimz primarnim ucelem bylo zkraceni enorme dlouheho kodu tridy Hrdina
    *
    *
    * Zaroven trida obsahuje pocitadlo dnu, umoznuje nam vytvoreni noveho Hrdiny, neboli nastaveni
    * startovnich atributu tridy Hrdina. To funguje jako nabidka, ktera pres prikaz case vola dalsi
    * metody zdedene z tridy Hrdina Builder. Dalsi jeho ucel je cele jadro inventare, volajici
    * dalsi metody z jednotlivych trid Inventaru a samotneho Hrdiny. A nakonec, aby Hra nebyla tak
    * obtizna, byla vytvorena metoda odpocivej. Princip je takovy, ze po mape jsou 4 odpocivadla,
    * kde se muze Hrdina, bez interakce s neprateli, uzdravit.
    */
class HrdinaDirector {

private:
		/**
		 * / Instance atrubutu den, ktery pro prehlednost udava kolikrat jsme spali na odpocivadlech
         */
        int m_den;

		/**
		 * / Instance atributu volba, ktera slouzi k prepinani nadpisu pro prehlednost
		 */
        int m_volba;

public:
		/**
		 * / Bezparametricky konstruktor Directora, ktery nastavi ze je 1 den
		 */
        HrdinaDirector();

        /**
		 * / Metoda, za pomoci ktere zvysujeme pocet uhranych dnu
		 */
        void setDen();

        /**
		 * / Metoda, ktera vraci o ktery den se ve hre jedna
		 */
        int getDen();

        /**
		 * / Metoda, slouzici pouze k zobrazeni nadpisu Vytvoreni Hrdiny
		 */
        void nadpis();

private:
        /**
		 *   Zde je metoda ktera nam zobrazi tabulku, obsahujici typy Hrdiny,
		 *   ktere si muzeme v dalsi metode zvolit.
		 */
        void vypisClass();

public:
        /**
		 *  Metoda, slouzici ke zvoleni typu Hrdiny, je vytvorena jako rada metod
		 *  v projektu na zaklade prikazu case (nabidky). Po zvoleni hrdiny nas odkaze
		 *  na jednoho ze tri potomku (Zlodej,Bojovnik,Mag), kteri maji za predka Hrdinu Buildera.
		 */
        void zvolTypHrdiny(Hrdina* hero);

        /**
		 * / Metoda, slouzici pouze k nastaveni volby. (Jaky nadpis chceme zobrazit.)
		 */
        void vypisInventar(int volba);

        /**
		 *   Metoda, je opet funguje jako nabidka, ale tentokrat se jedna o nejvetsi nabidku z projektu,
		 *   slozenou z 10 casti, vcetne vraceni do hlavniho menu. Prvni tri casti nam zobrazi typ inventare
		 *   jaky chceme prohlizet. Moznosti jsou Inventar Lektvar, Inventar Zbran a Inventar Zbroj.
		 *   Dale menu Inventare umozni zavolat metodu vypij lektvar, ktera preda hodnoty Hrdinovi, coz je umozneno
		 *   metodou prubehPitiLektvaru v Inventar Lektvar.
		 *   Volba oblec Zbroj je na stejnem zaklade jako uchop Zbran, obe tyto metody jsou volany ze tridy Hrdina,
		 *   kde jsou take podrobne popsany. Nakonec muzeme jednotlive itemy z inventare zahodit, coz je vyreseno
		 *   jednotlivymi metodami (zahod Lektvar,Zbran,Zbroj), ktere se nachazi v tridach jednotlivych Inventaru.
		 */
        void inventar(Hrdina* hero);

        /**
		 *   Aby se hrac nemusel obavat, ze ho kazdym krokem neco zabije, byla vytvorena metoda, ktera mu doplni zivot.
		 *   Tuto metodu vsak smi hrac zavolat pouze na urcitych mistech, presneji ve 4 Mistnostech. Metoda funguje jako
		 *   nocleh, uzdravi vas a probudite se do noveho dne. Hra tak ziskava na efektivite.
		 */
        void odpocivej(Hrdina* hero,Pozice2d* mojePozice,modelHra::ObjektovaHraciDeska* m_hraciDeska);

        /**
		 * / Destruktor, ktery se vola pri smazani Hrdiny Directora
		 */
        ~HrdinaDirector();
};
#endif
