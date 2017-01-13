#ifndef Mag_h
#define Mag_h
#include "HrdinaBuilder.h"
#include "Hrdina.h"

	/**
    * @brief Trdia, ktera dedi z abstraktni tridy HrdinaBuilder, jedna se o jeji
    * potomek, ktery prebira ciste virtualni metodu.
    */
class Mag : HrdinaBuilder {

public:

		/**
		 *  Verejna metoda, ktera je zdedena ze tridy HrdinaBuilder a za pomoci
		 *  set metod nam nastavi hrdinovi atributy sily, obrany, magie a
		 *  typ Hrdiny bude Mag
		 */
        void buildHrdina(Hrdina* mujHrdina);

};
#endif
