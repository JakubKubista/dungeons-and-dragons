#include "Pozice2d.h"

Pozice2d::Pozice2d() {
        m_radek = 0;
        m_sloupec = 0;
}

Pozice2d::Pozice2d(int radek, int sloupec) {
        this->m_radek = radek;
        this->m_sloupec = sloupec;
}

int Pozice2d::getRadek(){
    return m_radek;
}

int Pozice2d::getSloupec(){
    return m_sloupec;
}

