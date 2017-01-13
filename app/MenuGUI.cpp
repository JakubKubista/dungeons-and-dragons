#include "MenuGUI.h"

void MenuGUI::nadpisGUI(){
	system("cls");
    std::cout << std::endl;
    std::cout <<" ----------------------------------------------------------------------------- " << std::endl << std::endl;
	std::cout <<"                              DUNGEONS AND DRAGONS                             " << std::endl << std::endl;
    std::cout <<" ----------------------------------------------------------------------------- " << std::endl;
    std::cout << std::endl;
}

void MenuGUI::vypisMenuGUI(Hrdina* hero, HrdinaDirector* director,Pozice2d* mojePozice,modelHra::ObjektovaHraciDeska* m_hraciDeska){
    nadpisGUI();
    std::cout <<"         "<< hero->getJmeno() << ", Uroven: " << hero->getUroven();
    std::cout <<"\t\t Mistni lokace: " << m_hraciDeska->vrat((mojePozice->getRadek()),(mojePozice->getSloupec()),mojePozice)->getPopis();
    std::cout <<"  (" << mojePozice->getRadek() << "," << mojePozice->getSloupec() << ")" << std::endl;
    std::cout <<"  -----------------------------" << std::endl;
    std::cout <<" | 1: Vlastnosti hrdiny        |                                             ," << std::endl;
    std::cout <<" | 2: Inventar                 |                                 __...eee8888P" << std::endl;
    std::cout <<" | 3: Zobrazit mapu            |    .effe.     .e88e....____.e888888.*****`   ," << std::endl;
    std::cout <<" | 4: Zobrazit nazvy lokaci    |   ^888888b   :88888888888888888888eeee8888888P" << std::endl;
    std::cout <<" | 5: Prozkoumat mistni lokaci |   ^8888888b  :****8888888888888888888888****" << std::endl;
    std::cout <<" | 6: Moznosti pohybu          |    |`|`8888b.    o  `**8888******888**" << std::endl;
    std::cout <<" | 7: Odpocinek                |         `8888b...__.  A.___.e888**'" << std::endl;
    std::cout <<" |                             |           `8888888P d8888888888'  ," << std::endl;
    std::cout <<" | 8:(Save)                    |              ***** d88888888P*****" << std::endl;
    std::cout <<" | 9:(Hlavni nabidka)          |           __..eed8888888888eee.." << std::endl;
    std::cout <<"  -----------------------------   .|,|_.ed88888888***```````**888L" << std::endl;
    std::cout <<"                                 `*YY*****' \t\t\t\t DEN "<< director->getDen()<<std::endl;
    std::cout <<"                                            \t\t\t\tANKY "<< hero->getAnkVzkriseni()<<std::endl;
    std::cout <<" Vyberte volbu: ";
}

void MenuGUI::spatne(){
    std::cout <<" Spatne zadana operace!" << std::endl;
    std::cout <<" ";
    system("pause");
}
