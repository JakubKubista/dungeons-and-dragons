#ifndef Bojovnik_h
#define Bojovnik_h
#include "HrdinaBuilder.h"
#include "Hrdina.h"

	/**
    * @brief Trdia, ktera dedi z abstraktni tridy HrdinaBuilder, jedna se o jeji
    * potomek, ktery prebira ciste virtualni metodu.
    */
class Bojovnik : HrdinaBuilder {

public:

		/**
		 *  Verejna metoda, ktera je zdedena ze tridy HrdinaBuilder a za pomoci
		 *  set metod nam nastavi hrdinovi atributy sily, obrany, magie a
		 *  typ Hrdiny bude Bojovnik
		 */
        void buildHrdina(Hrdina* hero);

};
#endif
