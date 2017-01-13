#include "LokaceItem.h"

void LokaceItem::nadpisItem(){
    system("cls");
    std::cout << std::endl << std::endl;
	std::cout <<"                                 Mistni Lokace                                 " << std::endl << std::endl;
    std::cout <<" ----------------------------------------------------------------------------- " << std::endl;
    std::cout << std::endl;
}

void LokaceItem::obrazekItem(){
    system("cls");
    int i;
    for(i=1;i<3;i++){
    std::cout << std::endl;}
    std::cout << "\t\t\t\t NALEZEN ITEM!"<< std::endl;
    for(i=1;i<3;i++){
    std::cout << std::endl;}
    std::string x[50];
    x[2] = "\t   ________________.=''_;=.______________|___________________";
    x[3] = "\t            |  ,-'_,=''     `'=.|                  |         ";
    x[4] = "\t   _________|__'=._o`'-._        `'=.______________|_________";
    x[5] = "\t                   `'=._o`'=._      _`'=._                   ";
    x[6] = "\t   _____________________:=._o '=._.'_.-='''=.________________";
    x[7] = "\t            |    __.--' , ; `'=._o.' ,-'''-._ '.   |         ";
    x[8] = "\t   _________|_._'  ,. .` ` `` ,  `'-._'-._   '. '__|_________";
    x[9] = "\t              |o`'=._` , '` `; .'. ,  '-._'-._; ;            ";
    x[10] = "\t   ___________| ;`-.o`'=._; .' ` '`.'\` . '-._ / /____________";
    x[11] = "\t            | |o;    `'-.o`'=._``  '` ' ,__.--o;   |         ";
    x[12] = "\t   _________|_| ;     (#) `-.o `'=.`_.--'_o.-; ;___|_________";
    x[13] = "\t   /______/___|o;._    '      `'.o|o_.--'    ;o;____/______/_";
    x[14] = "\t   ___/______/_'=._o--._        ; | ;        ; ;/______/_____";
    x[15] = "\t   /______/______/__'=._o--._   ;o|o;     _._;o;____/______/_";
    x[16] = "\t   ___/______/______/____'=._o._; | ;_.--'o.--'_/______/_____";
    x[17] = "\t   /______/______/______/_____'=.o|o_.--''___/______/______/_";
    x[18] = "\t   ___/______/______/______/______/______/______/______/_____";
    for(int i=2;i<19;i++){std::cout << x[i] << std::endl;}
    std::cout << std::endl << " ";
    system("pause");
}

void LokaceItem::itemInfo(Pozice2d* mojePozice,PoziceItem* mistniItem) {
            int r = mojePozice->getRadek();
            int s = mojePozice->getSloupec();
            std::cout << std::endl;
            std::cout << "\t\t\t       Vlastnosti Itemu    " << std::endl << std::endl;
            std::cout << "\t\t\t -----------------------------" << std::endl;
            std::cout << "\t\t\t Nazev: " << mistniItem->vratItem(r,s)->getNazevItemu() << std::endl;
            std::cout << "\t\t\t Hodnota: " << mistniItem->vratItem(r,s)->getHodnotaItemu() << std::endl;
            if((mistniItem->vratItem(r,s)->getBonusZivoty())!=0){
            std::cout << "\t\t\t Vyleceni: +" << mistniItem->vratItem(r,s)->getBonusZivoty() << " zivotu" << std::endl;}
            if((mistniItem->vratItem(r,s)->getBonusZkusenosti())!=0){
            std::cout << "\t\t\t Zkusenosti: +" << mistniItem->vratItem(r,s)->getBonusZkusenosti() << " zkusenosti" << std::endl;}
            if((mistniItem->vratItem(r,s)->getBonusSila())!=0){
            std::cout << "\t\t\t Sila: +" << mistniItem->vratItem(r,s)->getBonusSila() << std::endl;}
            if((mistniItem->vratItem(r,s)->getBonusObrana())!=0){
            std::cout << "\t\t\t Obrana: +" << mistniItem->vratItem(r,s)->getBonusObrana() << std::endl;}
            std::cout << "\t\t\t -----------------------------" << std::endl << std::endl;
}

void LokaceItem::setOpakovani(int logickeCislo){
    m_logickeCislo = logickeCislo;
}

int LokaceItem::getOpakovani(){
    return m_logickeCislo;
}

void LokaceItem::vypisItemy(Hrdina* hero,Pozice2d* mojePozice,PoziceItem* mistniItem){
    int r = mojePozice->getRadek();
    int s = mojePozice->getSloupec();
    char x;
    if ((mistniItem->zjistiItem(r,s))!=0){
    if(m_logickeCislo==0){obrazekItem();}
    nadpisItem();
    itemInfo(mojePozice,mistniItem);
    std::cout << "\t\t     Sebrat item a dat do inventare? (Y/N) ";
    std::cin >> x;
    if(x=='y'){x='Y';}
    if(x=='n'){x='N';}
    if(x=='Y'){hero->interagujItem(mojePozice,mistniItem);}
    if(x=='N'){}
    if((x!='Y')and(x!='N')){
            std::cout << std::endl << "\t\t   Spatne zadana operace! ";
            std::cout << std::endl << "\t\t   ";
            system("pause");
            setOpakovani(1);
            vypisItemy(hero,mojePozice,mistniItem);}
    }else{mistniItem->neniItem();}
}
