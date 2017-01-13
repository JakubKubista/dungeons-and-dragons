#ifndef Item_h
#define Item_h
#include <iostream>

	/**
    * @brief Abstraktni Trida reprezentujici jednotlive Veci - Objekty (Itemy) po mape v Mistnostech.
    *
    * Zde je videt typicky polymorfismus, kde abstraktni trida NPC dedi svoje ciste
    * virtualni metody do svych potomku, ktere tedy jeste prebiraji jeji atributy.
    */
class Item {

	protected:
		/**
		 * / Atributy, ktere se dedi do ItemLektvar, ItemZbran, ItemZbroj, kde maji odlisne parametry.
		 */
        std::string m_nazevItemu;
        int m_hodnotaItemu;

	public:

	Item(std::string nazevItemu, int hodnotaItemu);

		/**
		 * / Ciste virtualni metoda, ktera se dedi do potomku ItemLektvar, ItemZbran, ItemZbroj, kde je vice popsana.
		 */
        virtual std::string getNazevItemu() = 0;

		/**
		 * / Ciste virtualni metoda, ktera se dedi do potomku ItemLektvar, ItemZbran, ItemZbroj, kde je vice popsana.
		 */
        virtual int getHodnotaItemu() = 0;

		/**
		 * / Ciste virtualni metoda, ktera se dedi do potomku ItemLektvar, ItemZbran, ItemZbroj, kde je vice popsana.
		 */
        virtual float getBonusZivoty() = 0;

		/**
		 * / Ciste virtualni metoda, ktera se dedi do potomku ItemLektvar, ItemZbran, ItemZbroj, kde je vice popsana.
		 */
        virtual float getBonusZkusenosti() = 0;

		/**
		 * / Ciste virtualni metoda, ktera se dedi do potomku ItemLektvar, ItemZbran, ItemZbroj, kde je vice popsana.
		 */
        virtual int getBonusSila() = 0;

		/**
		 * / Ciste virtualni metoda, ktera se dedi do potomku ItemLektvar, ItemZbran, ItemZbroj, kde je vice popsana.
		 */
        virtual int getBonusObrana() = 0;

		/**
		 * / Tridy, ktere budou mit potomky by mely mit virtualni destruktor, pak se zavola vzdy destruktor spravneho potomka
         *  V tride PoziceItem, ktera nam umozni umistit kde bude jaky Item, jsou
         *  metody vymaz konkretni Item a vymaz vsechny Itemy, diky tomu nesmi chybet destruktor
		 */
	virtual ~Item();
};
#endif
