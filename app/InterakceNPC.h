#ifndef InterakceNPC_h
#define InterakceNPC_h
#include "PoziceNPC.h"
#include "Pozice2d.h"
#include <iostream>

	/**
    * @brief Abstraktni Trida reprezentujici fiktivni interakci mezi Hrdinou a NPC
    * resena za pomoci Polymorfismu.
    *
    * Je zde zatim pouze Boj, ale bral jsem v uvahu i loupec, kterou jsem uz nestihl
    * v ramci casovem rozmezi vytvorit.
    * Vsechny metody jsou ciste virtualni az na konstruktor a destruktor a predavaji se do Boje,
    * kde jsou podrobne popsany.
    */

class InterakceNPC {

protected:
 	/**
    * / Atribut popisu dane Interakce, ktery se dedi za pomoci Polymorfismu do Tridy Boj
    */
	std::string m_popis;

public:
	InterakceNPC(std::string popis);

private:
 	/**
    * / Ciste virtualni metody vice popsany ve Tride Boj, kam se dedi
    */
    virtual void nadpisBoj() = 0;

	virtual void vypisVitezstvi() = 0;

	virtual void vypisProhru() = 0;

public:
	virtual void zvyseniUrovne(int uroven, int magie) = 0;

    virtual void konecHry() = 0;

    virtual void setAktualniZivotyHrdina(float aktualniZivotyHrdina) = 0;

    virtual void setAktualniZivotyNPC(float aktualniZivotyNPC) = 0;

    virtual void setKolo(int koloBitvy) = 0;

	virtual void setZiskZkusenosti(float ziskZkusenosti) = 0;

    virtual void setAktualniAnkVzkriseni(int aktualniAnkVzkriseni) = 0;

	virtual float getAktualniZivotyHrdina() = 0;

	virtual float getAktualniZivotyNPC() = 0;

    virtual int getAktualniAnkVzkriseni() = 0;

    virtual float getZiskZkusenosti() = 0;

	virtual void ziskejZkusenosti(Pozice2d* mojePozice,PoziceNPC* mistniNPC) = 0;

	virtual void zautoc(Pozice2d* mojePozice,PoziceNPC* mistniNPC,float maxZivotyH,int silaH,int obranaH,int magieH,int urovenH,std::string jmenoH) = 0;

	~InterakceNPC();
};
#endif
