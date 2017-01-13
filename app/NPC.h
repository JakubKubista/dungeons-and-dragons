#ifndef NPC_h
#define NPC_h
#include <iostream>

	/**
    * @brief Abstraktni Trida reprezentujici jednotlive Nepratele (NPC) po mape v Mistnostech.
    *
    * Zde je videt typicky polymorfismus, kde abstraktni trida NPC dedi svoje ciste
    * virtualni metody do svych potomku, ktere tedy jeste prebiraji jeji atributy.
    */
class NPC {

protected:
		/**
		 * / Atributy, ktere se dedi do Drak, Vlk, Ork, kde maji odlisne parametry.
		 */
        std::string m_nazevNPC;
        int m_obtiznost;
        float m_maxZivoty;

public:
		/**
		 * / Konstruktor se samozrejme nededi, navic je bezparametricky.
		 */
        NPC();

		/**
		 * / Ciste virtualni metoda, ktera se dedi do potomku Vlk, Drak a Ork, kde je vice popsana.
		 */
        virtual std::string  getNazevNPC() = 0;

		/**
		 * / Ciste virtualni metoda, ktera se dedi do potomku Vlk, Drak a Ork, kde je vice popsana.
		 */
        virtual int getObtiznost() = 0;

		/**
		 * / Ciste virtualni metoda, ktera se dedi do potomku Vlk, Drak a Ork, kde je vice popsana.
		 */
        virtual float getZivoty() = 0;

		/**
		 * / Ciste virtualni metoda, ktera se dedi do potomku Vlk, Drak a Ork, kde je vice popsana.
		 */
        virtual float getMaxZivoty() = 0;

		/**
		 * /  Ciste virtualni metoda, ktera se dedi do potomku Vlk, Drak a Ork, kde je vice popsana.
		 */
        virtual int getSila() = 0;

		/**
		 * /  Ciste virtualni metoda, ktera se dedi do potomku Vlk, Drak a Ork, kde je vice popsana.
		 */
        virtual int getObrana() = 0;

		/**
		 * /  Ciste virtualni metoda, ktera se dedi do potomku Vlk, Drak a Ork, kde je vice popsana.
		 */
        virtual int getMagie() = 0;

		/**
		 * / Ciste virtualni metoda, ktera se dedi do potomku Vlk, Drak a Ork, kde je vice popsana.
		 */
        virtual int getZkusenostiZVitezstvi() = 0;

		/**
		 * / Tridy, ktere budou mit potomky by mely mit virtualni destruktor, pak se zavola vzdy destruktor spravneho potomka
         *  V tride PoziceNPC, ktera nam umozni umistit kde bude jake NPC, jsou
         *  metody vymaz konkretni NPC a vymaz vsechny NPC, diky tomu nesmi chybet destruktor
		 */
        virtual ~NPC();

};
#endif
