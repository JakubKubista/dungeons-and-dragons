#ifndef HrdinaBuilder_h
#define HrdinaBuilder_h
#include "Hrdina.h"

	/**
    * @brief Abstraktni Trdia s Jednou jedinou ciste virtualni metodou
    */
class HrdinaBuilder {

public:
		/**
		 * / Ciste virtualni metoda, ktera se dedi do Trid Bojovnik, Lovec a Mag.
		 *   Je volana hned ze zacatku nove Hry v CivEngine. Vice podrobnosti v jednotlivych
		 *   dedicich.
		 */
        virtual void buildHrdina() = 0;

};
#endif
