#include "Boj.h"

Boj::Boj(std::string popis):InterakceNPC(popis){
        m_popis = popis;
}

void Boj::nadpisBoj(){
    system("cls");
    std::cout << std::endl << std::endl;
	std::cout <<"                                      BITVA                                     " << std::endl << std::endl;
    std::cout <<" ----------------------------------------------------------------------------- " << std::endl;
    std::cout << std::endl;
}

void Boj::vypisVitezstvi() {
    nadpisBoj();
    for(int i=1; i<6; i++){std::cout << std::endl;}
    std::cout <<"                                 -------------                                 " << std::endl;
	std::cout <<"                                |  Vitezstvi  |                                " << std::endl;
    std::cout <<"                                 -------------                                 " << std::endl;
    std::cout <<"                                +"<<m_ziskaneZkusenosti<<" zkusenosti                                 " << std::endl;
    for(int i=1; i<8; i++){std::cout << std::endl;}
    std::cout << " "; system("pause");
}

void Boj::vypisProhru() {
    nadpisBoj();
    for(int i=1; i<6; i++){std::cout << std::endl;}
    std::cout <<"                                 -------------                                 " << std::endl;
	std::cout <<"                                |   Porazka   |                                " << std::endl;
    std::cout <<"                                 -------------                                 " << std::endl;
    for(int i=1; i<10; i++){std::cout << std::endl;}
    std::cout << " "; system("pause");
}

void Boj::zvyseniUrovne(int uroven, int magie) {
    system("cls");
    for(int i=1; i<8; i++){std::cout << std::endl;}
    std::cout <<"                               ------------------                               " << std::endl;
	std::cout <<"                                                                                 " << std::endl;
	std::cout <<"                                    UROVEN "<<uroven<<"                                     " << std::endl;
	std::cout <<"                                                                                 " << std::endl;
    std::cout <<"                               ------------------                               " << std::endl;
    if(magie==0){
    std::cout <<"                                    +8 sila                                     " << std::endl;
    std::cout <<"                                    +8 obrana                                   " << std::endl;
    for(int i=1; i<6; i++){std::cout << std::endl;}
    std::cout << "\t\t   "; system("pause");
    }else{
    std::cout <<"                                    +4 sila                                     " << std::endl;
    std::cout <<"                                    +4 obrana                                   " << std::endl;
    std::cout <<"                                    +8 magie                                    " << std::endl;
    for(int i=1; i<5; i++){std::cout << std::endl;}
    std::cout << "\t\t   "; system("pause");
    }
}

void Boj::konecHry() {
    system("cls");
    for(int i=1; i<8; i++){std::cout << std::endl;}
    std::cout <<"                               ------------------                               " << std::endl;
	std::cout <<"                              |                  |                               " << std::endl;
	std::cout <<"                              |    KONEC  HRY    |                               " << std::endl;
	std::cout <<"                              |                  |                               " << std::endl;
    std::cout <<"                               ------------------                               " << std::endl;
    for(int i=1; i<8; i++){std::cout << std::endl;}
    std::cout << "\t\t   "; system("pause");
}

void Boj::setAktualniZivotyHrdina(float aktualniZivotyHrdina){
    m_aktualniZivotyHrdina = aktualniZivotyHrdina;
}

void Boj::setAktualniZivotyNPC(float aktualniZivotyNPC){
    m_aktualniZivotyNPC = aktualniZivotyNPC;
}

void Boj::setKolo(int koloBitvy){
    m_koloBitvy = koloBitvy;
}

void Boj::setZiskZkusenosti(float ziskZkusenosti){
    m_ziskaneZkusenosti = ziskZkusenosti;
}

void Boj::setAktualniAnkVzkriseni(int aktualniAnkVzkriseni){
    m_aktualniAnkVzkriseni = aktualniAnkVzkriseni;
}

float Boj::getAktualniZivotyHrdina(){
    return m_aktualniZivotyHrdina;
}

float Boj::getAktualniZivotyNPC(){
    return m_aktualniZivotyNPC;
}

int Boj::getAktualniAnkVzkriseni(){
    return m_aktualniAnkVzkriseni;
}
float Boj::getZiskZkusenosti(){
    return m_ziskaneZkusenosti;
}

void Boj::ziskejZkusenosti(Pozice2d* mojePozice,PoziceNPC* mistniNPC){
    m_ziskaneZkusenosti = (mistniNPC->vratNPC(mojePozice->getRadek(),mojePozice->getSloupec())->getZkusenostiZVitezstvi());
}

void Boj::zautoc(Pozice2d* mojePozice,PoziceNPC* mistniNPC,float maxZivotyH,int silaH,int obranaH,int magieH,int urovenH,std::string jmenoH) {
    int r = mojePozice->getRadek();
    int s = mojePozice->getSloupec();
    int silaN = mistniNPC->vratNPC(r,s)->getSila();
    int obranaN = mistniNPC->vratNPC(r,s)->getObrana();
    int magieN = mistniNPC->vratNPC(r,s)->getMagie();
    float maxZivotyN = mistniNPC->vratNPC(r,s)->getMaxZivoty();
    int urovenN = (mistniNPC->vratNPC(r,s)->getObtiznost())*3;
	nadpisBoj();
	char x;
	float uderNepritel = (silaN+obranaN+magieN+(m_aktualniZivotyNPC/10));
	float uderHrdina = (silaH+obranaH+magieH+(m_aktualniZivotyHrdina/10));

    std::cout << std::endl;
    std::cout << "\t                             ROUND " << m_koloBitvy << "                        " << std::endl;
    std::cout << "\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
    std::cout << "\t                    \t\t|                              " << std::endl;
    std::cout << "\t            Nepritel\t\t|            Hrdina            " << std::endl;
    std::cout << "\t                    \t\t|                              " << std::endl;
    std::cout << "\t -------------------------------------------------------------" << std::endl;
    std::cout << "\t Jmeno: " << mistniNPC->vratNPC(r,s)->getNazevNPC();
    std::cout << "\t\t| Jmeno: " << jmenoH << std::endl;
    std::cout << "\t Uroven: " << urovenN;
    std::cout << "\t\t\t| Uroven: " << urovenH << std::endl;
    std::cout << "\t Zivoty: " << m_aktualniZivotyNPC << "/"  <<maxZivotyN;
    std::cout << " \t\t| Zivoty: " << m_aktualniZivotyHrdina << "/"  << maxZivotyH << std::endl;
    std::cout << "\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
    std::cout << "\t Sila: " << silaN;
    std::cout << "\t\t\t| Sila: " << silaH << std::endl;
    std::cout << "\t Obrana: " << obranaN;
    std::cout << "\t\t\t| Obrana: " << obranaH << std::endl;
    if((magieN)!=0){
    std::cout << "\t Magie: " <<magieN;
    }else{std::cout << "\t\t";}
    if((magieH)!=0){
    std::cout << "\t\t\t| Magie: " << magieH << std::endl;
    }else{std::cout << "\t\t\t|" << std::endl;}
    std::cout << "\t -------------------------------------------------------------" << std::endl << std::endl;
    if(m_koloBitvy==1){std::cout << "\t\t   Prejete si na nepritele zautocit? (Y/N) ";
    }else{std::cout << "\t       Prejete si na nepritele znovu zautocit? (Y/N) ";}
    std::cin >> x;
    if(x=='y'){x='Y';}
    if(x=='n'){x='N';}
    if((x!='Y')and(x!='N')){
            std::cout << std::endl << "\t\t   Spatne zadana operace! ";
            std::cout << std::endl << "\t\t   ";
            system("pause");
            nadpisBoj();
            zautoc(mojePozice,mistniNPC,maxZivotyH,silaH,obranaH,magieH,urovenH,jmenoH);
            if(m_koloBitvy==1){std::cout << "\t\t   Prejete si na nepritele zautocit? (Y/N) ";
            }else{std::cout << "\t       Prejete si na nepritele znovu zautocit? (Y/N) ";}
            std::cin >> x;
            }
    if(x=='N'){
        int z=rand()%3;
        if(z==1){m_aktualniZivotyHrdina = m_aktualniZivotyHrdina - uderNepritel;
        std::cout << "\t       Nepodarilo se vam uteci bez uhony..(-" << uderNepritel<<" HP)";}
        else{std::cout << "\t       Podarilo se vam uteci bez uhony!";}
    }
    if(x=='Y'){
            m_aktualniZivotyNPC = m_aktualniZivotyNPC - uderHrdina;
            if(m_aktualniZivotyNPC>0){
                m_aktualniZivotyHrdina = m_aktualniZivotyHrdina - uderNepritel;
                if(m_aktualniZivotyHrdina>0){
                m_koloBitvy++;
                nadpisBoj();
                zautoc(mojePozice,mistniNPC,maxZivotyH,silaH,obranaH,magieH,urovenH,jmenoH);
                }else{vypisProhru();m_aktualniAnkVzkriseni--;
                if(m_aktualniAnkVzkriseni==0){konecHry();}}
            }else{ziskejZkusenosti(mojePozice,mistniNPC);
                  vypisVitezstvi();}
    }
}
