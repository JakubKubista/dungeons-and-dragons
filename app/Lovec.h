#ifndef Lovec_h
#define Lovec_h
#include "HrdinaBuilder.h"
#include "Hrdina.h"

	/**
    * @brief Trdia, ktera dedi z abstraktni tridy HrdinaBuilder, jedna se o jeji
    * potomek, ktery prebira ciste virtualni metodu.
    */
class Lovec : HrdinaBuilder {

public:

		/**
		 *  Verejna metoda, ktera je zdedena ze tridy HrdinaBuilder a za pomoci
		 *  set metod nam nastavi hrdinovi atributy sily, obrany, magie a
		 *  typ Hrdiny bude Lovec
		 */
        void buildHrdina(Hrdina* mujHrdina);

};
#endif
