#ifndef Hrdina_h
#define Hrdina_h
#include "InterakceNPC.h"
#include "InventarLektvar.h"
#include "InventarZbran.h"
#include "InventarZbroj.h"
#include "Zbroj.h"
#include "Zbran.h"
#include "Pozice2d.h"
#include "PoziceNPC.h"
#include "PoziceItem.h"
#include "Boj.h"
#include <stdlib.h>
#include <vector>
#include <iostream>

class Hrdina {
	/**
    * @brief Nejvetsi trida v cele hre obsaujici veskere moznosti hrdiny.
    *
    *
    * Nektere metody jsou roztrideny do trid InventarLektvar, InventarZbran a
    * InventarZbroj, pro sbirani, pouzivani a odhazovani Itemu. Jine pro interakce
    * jako je boj. 300 radku je sice hodne, ale kdyz ma tolik atributu, getru a
    * celkove metod, neni snadne vytvorit kratky kod.
    * Hrdina se nam vytvori pri zapnuti a pri ukonceni cele hry. Ma dva konsturktory
    * podle vyberu v hlavni nabidce. A jeden destruktor, ktery maze fiktivni atributy hrdiny.
    */
private:
		/**
		 * / Instance jednotlivych atributu hrdiny, diky kterym ho muzeme identifikovat
		 */
        std::string m_jmeno;
        std::string m_typHrdiny;

		/**
		 * / Instance jednotlivych atributu hrdiny, ktere mu slouzi jako schopnosti a dovednosti
		 */
        float m_zivoty;
        float m_maxZivoty;
        int m_sila;
        int m_obrana;
        int m_magie;
        float m_zkusenosti;
        float m_maxZkusenosti;
        int m_uroven;
        int m_pocetZabitychNepratel;
        int m_ankVzkriseni;
		/**
		 * / Instance jednotlivych atributu hrdiny, ktere muze hrdina nest nebo take pouzivat
		 */
        Zbroj* m_nesenaZbroj;
        Zbran* m_nesenaZbran;
        InventarLektvar* m_inventarLektvar;
        InventarZbran* m_inventarZbran;
        InventarZbroj* m_inventarZbroj;
        InterakceNPC* m_interakceNPC;
		/**
		 * / Instance pozice Hrdiny pro urceni jeho polohy na mape
		 */
        std::vector<std::vector< Pozice2d*>> m_pozice;

public:
		/**
		 *  Bezparametricky konstruktor, ktery se vytvori pri volbe v uvodni nabidce Nova Hra
		 *  Po konstrukci zadavame jmeno, a typ hrdiny, ktery nam priradi startovni hodnoty atributu
		 */
        Hrdina();

		/**
		 *  Parametricky konstruktor, ktery se vytvori pri volbe v uvodni nabidce Pokracovat
		 *  Po konstrukci nemusime zadavat nic, a ma predstavovat fixci jak hra vypada po urcitem
		 *  odehranem case (hrdina je silny).
		 */
        Hrdina(std::string jmeno);

        /**
		 * / Metoda, za pomoci ktere nastavime pri uvodu Nove Hry jmeno Hrdiny
		 */
        void setJmeno(std::string jmeno);

        /**
		 *   Metoda, za pomoci ktere nastavime typ Hrdiny, podle toho jaky zvolime ve tride
		 *   Hrdina Director, ktera je volana po zadani jmena. A podle typu zavola nektereho dedice Hrdiny buildra.
		 */
        void setTypHrdiny(std::string typHrdiny);

        /**
		 * / Metoda, za pomoci ktere nastavime silu Hrdiny
		 */
        void setSila(int sila);

        /**
		 * / Metoda, za pomoci ktere nastavime obranu Hrdiny
		 */
        void setObrana(int obrana);

        /**
		 * / Metoda, za pomoci ktere nastavime magii Hrdiny
		 */
        void setMagie(int magie);

        /**
		 * / Metoda, za pomoci ktere nastavime zivoty Hrdiny
		 */
        void setZivoty();

        /**
		 * / Metoda, ktera nam vraci Jmeno Hrdiny
		 */
        std::string getJmeno();

        /**
		 * / Metoda, ktera nam vraci silu Hrdiny
		 */
        int getSila();

        /**
		 * / Metoda, ktera nam vraci obranu Hrdiny
		 */
        int getObrana();

        /**
		 * / Metoda, ktera nam vraci uroven Hrdiny
		 */
        int getUroven();

        /**
		 *   Metoda, ktera nam vraci maximalni zkusenosti Hrdiny, ktere jsou nastaveny
		 *   vzorcem predesle maximalni zkusenosti + uroven * 150. Pokud zkusenosti
		 *   dosahnou maximalnich Hrdina obdrzi novou uroven
		 */
        float getMaxZkusenosti();

        /**
		 * / Metoda, ktera nam vraci inventar lektvaru Hrdiny
		 */
        InventarLektvar* getInventarLektvar();

        /**
		 * / Metoda, ktera nam vraci inventar zbrani Hrdiny
		 */
        InventarZbran* getInventarZbran();

        /**
		 * / Metoda, ktera nam vraci inventar zbroji Hrdiny
		 */
        InventarZbroj* getInventarZbroj();

        /**
		 * / Metoda, ktera nam vraci pocet anku vzkriseni Hrdiny - pokud neni zadny, hra se ukonci
		 */
        int getAnkVzkriseni();

        /**
		 *   Metoda, za pomoci ktere hrdina ziska pozici, diky tride Pozice2d, ktera je dana radkem
		 *   a sloupcem v objektove hraci desce.
		 */
        Pozice2d* ziskejPozici(int radek, int sloupec);

private:
        /**
		 *   Metoda, ktera nastavi jakou interakci prave provadime , funguje jako metoda set
		 *   Byla brana v uvahu interakce Ukradni, aby polymorfismus trid InterakceNPC a Boj mel vubec
		 *   smysl, ale skrz casove rozmezi jsem uz toho potomka nestihl vytvorit.
		 */
        void naucInterakciNPC(InterakceNPC* novaInterakceNPC);

public:
        /**
		 *   Metoda, reprezentujici interakci mezi Hrdinou a NPC (nepritelem). Vetsina boje se odkazuje
		 *   na tridu Boj, jenz je prave potomkem tridy InterakceNPC. Nejdrive se zavola metoda naucInterakciNPC,
		 *   diky ktere vime o jakou interakci se jedna a pote nastavime atributy tridy boj na prvni kolo bitvy.
		 *   Pote se za pomoci metody zautoc v Boji predaji hodnoty hrdiny a mistniho NPC se souradnicemi a bitva
		 *   muze zacit. Pote se prevedou hodnoty atributu z bitvy na hrdinovy.
		 *   Nasleduji tri podminky, zda jsme neumreli, neobdrzeli novou uroven a jestli byl nepritel porazen.
		 *
		 */
        void interagujNPC(Pozice2d* mojePozice,PoziceNPC* mistniNPC);

        /**
		 *   Metoda, ktera slouzi k predani Itemu v Mistnosti do inventare Hrdiny. Zjisti o jaky item se jedna
		 *   Pokud je to Lektvar, preda hodnoty do Inventar Lektvar, stejne je to tak u Inventare Zbroji a
		 *   Inventare Zbrani. Veskere dalsi operace s Itemem jsou popsany v danem Invenari.
		 */
        void interagujItem(Pozice2d* mojePozice,PoziceItem* mistniItem);

        /**
		 *  Metoda, diky ktere Hrdina pije Lektvar z Inventare Lektvaru, je zde zavolana metoda
		 *  nauc interakciNPC kdyby se zvysila uroven, ktera by se k Inventari ani spravne nemela
		 *  vztahovat, ale aby se kod zbytecne neprodluzoval je problematika vyresena takto.
		 *  Hrdinovi prida hodnoty Lektvaru a to zkusenosti a zdravi, ale v Mistnostech jsou
		 *  stejne pouze Lektvary Zkusenosti a Lektvary Zivotu, takze si polepsi pouze u jednoho atributu.
		 */
        void vypijLektvar();

        /**
		 *  Jedna se o Metodu, ktera hrdinovi umoznuje zakladnim zpusobem vzit zbran z Inventare Zbrani. Nejprve
		 *  tato metoda mela byt resena pres interakci, ale po nekolikahodinove praci jsem se rozhodl,
		 *  ze to bude reseno metodou, ktera nam bohuzel zbytecne zdelsi kod tridy Hrdina.
		 *
		 *  Z pomocne tridy hrdiny Hrdina Director si zadame, index vektoru, neboli Zbrane, kterou chceme vzit.
		 *  Nyni navazujeme na zdejsi metodu, ktera nam ji umozni za pomoci podminek vzit z inventare, pokud
		 *  pod timto cislem nejaka vubec je. Dle podminky zjisti jestli uz mame nebo nemame Zbran, pokud ano
		 *  tak tak nam ciste prepise hodnoty, predesle Zbrane, pokud ne vytvori se zcela nova Zbran hrdiny
		 *  a opet zapise jeji atributy. Pokud hrdina zbran mel, tak to ma symbolizovat, ze starou zahodi
		 *  a novou vezme, i kdyz pouze prepise atributy Zbrane.
		 */
        void uchopZbran(int druhZbrane);


        /**
		 *  Meto je skoro totozna s metodou uchopeni Zbroje, umoznuje obleci zbroj z Inventare Zbroji. Nejprve
		 *  tato metoda mela byt resena pres interakci, ale po nekolikahodinove praci jsem se rozhodl,
		 *  ze to bude reseno metodou, ktera nam bohuzel zbytecne zdelsi kod tridy Hrdina.
		 *
		 *  Z pomocne tridy hrdiny Hrdina Director si zadame, index vektoru, neboli Zbroje, kterou chceme obleci.
		 *  Nyni navazujeme na zdejsi metodu, ktera nam ji umozni za pomoci podminek sebrat z inventare, pokud
		 *  pod timto cislem nejaka vubec je. Dle podminky zjisti jestli uz mame nebo nemame Zbroj, pokud ano
		 *  tak tak nam ciste prepise hodnoty, predesle Zbroje, pokud ne vytvori se zcela nova Zbroj hrdiny
		 *  a opet zapise jeji atributy. Pokud hrdina zbran mel, tak to ma symbolizovat, ze starou zahodi
		 *  a novou vezme, i kdyz pouze prepise atributy Zbroje.
		 */
        void oblecZbroj(int druhZbroje);

        /**
		 * / Tato metoda nam vypise veskere dulezite a pro nas potrebne vlastnosti (atributy) Hrdiny.
		 */
        void printInfo();

        /**
		 *  Destruktor, ktery se vola pri smazani Hrdiny a smaze nam vsechny
		 *  jeho vytvorene nesene atributy Trid.
 		 */
        void vymazHrdinu();
};
#endif
