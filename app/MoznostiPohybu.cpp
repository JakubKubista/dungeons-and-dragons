#include "MoznostiPohybu.h"

void MoznostiPohybu::nadpisPohyb(){
    system("cls");
    std::cout << std::endl << std::endl;
	std::cout <<"                                Moznosti Pohybu                                " << std::endl << std::endl;
    std::cout <<" ----------------------------------------------------------------------------- " << std::endl;
    std::cout << std::endl;
}

void MoznostiPohybu::mapaPohyb(){
    std::cout << " -----------------------------------------------------------------------------"<< std::endl;
    std::cout << std::endl;
    std::cout <<"\t\t  #=======#=======#=======#=======#=======#" << std::endl;
    std::cout <<"\t\t  # (0,0)   (0,1)   (0,2)   (0,3)   (0,4) #" << std::endl;
    std::cout <<"\t\t  #       #=======#       #=======#       #" << std::endl;
    std::cout <<"\t\t  # (1,0) # (1,1) # (1,2) # (1,3) # (1,4) #" << std::endl;
    std::cout <<"\t\t  #       #       #=======#       #       #" << std::endl;
    std::cout <<"\t\t  # (2,0) # (2,1) # (2,2) # (2,3)   (2,4) #" << std::endl;
    std::cout <<"\t\t  #       #       #       #       #       #" << std::endl;
    std::cout <<"\t\t  # (3,0)   (3,1) # (3,2)   (3,3)   (3,4) #" << std::endl;
    std::cout <<"\t\t  #=======#=======#       #=======#=======#" << std::endl;
    std::cout <<"\t\t          # (4,1)   (4,2)   (4,3) #" << std::endl;
    std::cout <<"\t\t          #=======#=======#=======#" << std::endl;
    std::cout << std::endl;
}

void MoznostiPohybu::vypisPohyb(Hrdina* hero,Pozice2d* mojePozice,modelHra::ObjektovaHraciDeska* deska) {
    MenuGUI* menu;
    nadpisPohyb();
    char l;
    int r = mojePozice->getRadek();
    int s = mojePozice->getSloupec();

    if (((r==0)and(0<s)and(s<5))or((r==2)and(s==4))or((r==3)and((s==1)or(s==3)or(s==4)))or((r==4)and((s==2)or(s==3)))){
    s--;
    if ((deska->zjisti(s,r))!=0){
    std::cout <<"  L:[VLEVO] (" << r << "," << s << ") ";
    std::cout << deska->vrat(r,s,mojePozice)->getPopis();
    if (((deska->vrat(r,s,mojePozice)->getObtiznost())==2)and((hero->getUroven())<3)){
    std::cout << "  -> Minimalni uroven je: 3";
    }
    if (((deska->vrat(r,s,mojePozice)->getObtiznost())==3)and((hero->getUroven())<6)){
    std::cout << "  -> Minimalni uroven je: 6";
    }
    std::cout << std::endl;
    }else{deska->vypisError(r,s);}
    s++;
    }

    if (((r==0)and(-1<s)and(s<4))or((r==2)and(s==3))or((r==3)and((s==0)or(s==2)or(s==3)))or((r==4)and((s==1)or(s==2)))){
    s++;
    if ((deska->zjisti(s,r))!=0){
    std::cout <<"  P:[VPRAVO] (" << r << "," << s << ") ";
    std::cout << deska->vrat(r,s,mojePozice)->getPopis();
    if (((deska->vrat(r,s,mojePozice)->getObtiznost())==2)and((hero->getUroven())<3)){
    std::cout << "  -> Minimalni uroven je: 3";
    }
    if (((deska->vrat(r,s,mojePozice)->getObtiznost())==3)and((hero->getUroven())<6)){
    std::cout << "  -> Minimalni uroven je: 6";
    }
    std::cout << std::endl;
    }else{deska->vypisError(r,s);}
    s--;
    }

    if (((s==0)and(0<r)and(r<4))or((s==1)and(1<r)and(r<4))or((s==2)and((r==1)or((2<r)and(r<5))))or((s==3)and(1<r)and(r<4))or((s==4)and(0<r)and(r<4))){
    r--;
    if ((deska->zjisti(s,r))!=0){
    std::cout <<"  N:[NAHORU] (" << r << "," << s << ") ";
    std::cout << deska->vrat(r,s,mojePozice)->getPopis();
    if (((deska->vrat(r,s,mojePozice)->getObtiznost())==2)and(hero->getUroven()<3)){
    std::cout << "  -> Minimalni uroven je: 3";
    }
    if (((deska->vrat(r,s,mojePozice)->getObtiznost())==3)and(hero->getUroven()<6)){
    std::cout << "  -> Minimalni uroven je: 6";
    }
    std::cout << std::endl;
    }else{deska->vypisError(r,s);}
    r++;
    }

    if (((s==0)and(r>-1)and(r<3))or((s==1)and(r>0)and(r<3))or((s==2)and((r==0)or(r>1)and(r<4)))or((s==3)and(0<r)and(r<3))or((s==4)and(-1<r)and(r<3))){
    r++;
    if ((deska->zjisti(s,r))!=0){
    std::cout <<"  D:[DOLU]   (" << r << "," << s << ") ";
    std::cout << deska->vrat(r,s,mojePozice)->getPopis();
    if (((deska->vrat(r,s,mojePozice)->getObtiznost())==2)and(hero->getUroven()<3)){
    std::cout << "  -> Minimalni uroven je: 3";
    }
    if (((deska->vrat(r,s,mojePozice)->getObtiznost())==3)and(hero->getUroven()<6)){
    std::cout << "  -> Minimalni uroven je: 6";
    }
    std::cout << std::endl;
    }else{deska->vypisError(r,s);}
    r--;
    }
    std::cout << std::endl <<"  Z:[Zpet]"<< std::endl;
    mapaPohyb();
    std::cout <<" Vyberte volbu: ";
    std::cin >> l;
    if(l=='l'){l='L';}
    if(l=='p'){l='P';}
    if(l=='n'){l='N';}
    if(l=='d'){l='D';}
    if(l=='z'){l='Z';}
    switch (l){
          case 'L':
                r = mojePozice->m_radek;
                s = mojePozice->m_sloupec;
                s--;
                if ((deska->zjisti(s,r))!=0){s++;
                if (((r==0)and((s>0)and(s<5)))or((r==2)and(s==4))or((r==3)and((s==1)or(s==3)or(s==4)))or((r==4)and((s==2)or(s==3)))){
                mojePozice->m_sloupec--;
                }else{
                menu->spatne();
                vypisPohyb(hero,mojePozice,deska);}
                s--;
                if((((deska->vrat(r,s,mojePozice)->getObtiznost())==2)and((hero->getUroven())<3))or(((deska->vrat(r,s,mojePozice)->getObtiznost())==3)and((hero->getUroven())<6))){
                mojePozice->m_sloupec++;
                s++;
                menu->spatne();
                vypisPohyb(hero,mojePozice,deska);
                }else{s++;}
                }else{deska->vypisError(r,s);s++;}
                break;
          case 'P':
                r = mojePozice->m_radek;
                s = mojePozice->m_sloupec;
                s++;
                if ((deska->zjisti(s,r))!=0){s--;
                if (((r==0)and((s>-1)and(s<4)))or((r==2)and(s==3))or((r==3)and((s==0)or(s==2)or(s==3)))or((r==4)and((s==1)or(s==2)))){
                mojePozice->m_sloupec++;
                }else{
                menu->spatne();
                vypisPohyb(hero,mojePozice,deska);}
                s++;
                if((((deska->vrat(r,s,mojePozice)->getObtiznost())==2)and((hero->getUroven())<3))or(((deska->vrat(r,s,mojePozice)->getObtiznost())==3)and((hero->getUroven())<6))){
                mojePozice->m_sloupec--;
                s--;
                menu->spatne();
                vypisPohyb(hero,mojePozice,deska);
                }else{s--;}
                }else{deska->vypisError(r,s);s--;}
                break;
          case 'N':
                r = mojePozice->m_radek;
                s = mojePozice->m_sloupec;
                r--;
                if ((deska->zjisti(s,r))!=0){r++;
                if (((s==0)and((0<r)and(r<4)))or((s==1)and((r>1)and(r<4)))or((s==2)and((r==1)or((r>2)and(r<5))))or((s==3)and((r>1)and(r<4)))or((s==4)and((r>0)and(r<4)))){
                mojePozice->m_radek--;
                }else{
                menu->spatne();
                vypisPohyb(hero,mojePozice,deska);}
                r--;
                if((((deska->vrat(r,s,mojePozice)->getObtiznost())==2)and((hero->getUroven())<3))or(((deska->vrat(r,s,mojePozice)->getObtiznost())==3)and((hero->getUroven())<6))){
                mojePozice->m_radek++;
                r++;
                menu->spatne();
                vypisPohyb(hero,mojePozice,deska);
                }else{r++;}
                }else{deska->vypisError(r,s);r++;}
                break;
          case 'D':
                r = mojePozice->m_radek;
                s = mojePozice->m_sloupec;
                r++;
                if ((deska->zjisti(s,r))!=0){r--;
                if (((s==0)and((r>-1)and(r<3)))or((s==1)and((r>0)and(r<3)))or((s==2)and((r==0)or((r>1)and(r<4))))or((s==3)and((0<r)and(r<3)))or((s==4)and((-1<r)and(r<3)))){
                mojePozice->m_radek++;
                }else{
                menu->spatne();
                vypisPohyb(hero,mojePozice,deska);}
                r++;
                if((((deska->vrat(r,s,mojePozice)->getObtiznost())==2)and((hero->getUroven())<3))or(((deska->vrat(r,s,mojePozice)->getObtiznost())==3)and((hero->getUroven())<6))){
                mojePozice->m_radek--;
                r--;
                menu->spatne();
                vypisPohyb(hero,mojePozice,deska);
                }else{r--;}
                }else{deska->vypisError(r,s);r--;}
                break;
          case 'Z':
                break;
        default:
                menu->spatne();
                vypisPohyb(hero,mojePozice,deska);
				break;
}
}
