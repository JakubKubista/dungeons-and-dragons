#include "LokaceNPC.h"

void LokaceNPC::nadpisNPC(){
    system("cls");
    std::cout << std::endl << std::endl;
	std::cout <<"                                 Mistni Lokace                                 " << std::endl << std::endl;
    std::cout <<" ----------------------------------------------------------------------------- " << std::endl;
    std::cout << std::endl;
}

void LokaceNPC::nadpisBitva(){
    system("cls");
    std::cout << std::endl << std::endl;
	std::cout <<"                                     BITVA                                     " << std::endl << std::endl;
    std::cout <<" ----------------------------------------------------------------------------- " << std::endl;
    std::cout << std::endl;
}

void LokaceNPC::obrazekNPC(){
    system("cls");
    int i;
    for(i=1;i<3;i++){
    std::cout << std::endl;}
    std::cout << "\t\t\t\t NALEZEN NEPRITEL!"<< std::endl;
    for(i=1;i<2;i++){
    std::cout << std::endl;}
    std::string x[50];
    x[2] = "                              _.-'/   _.:'`/";
    x[3] = "                           ,'`   ( ,:;.-'`(";
    x[4] = "                         .'      .:'`      (";
    x[5] = "                        /       //    _.-';)";
    x[6] = "                      _/      _//_.-;:-'``/";
    x[7] = "               //|    (      (  .-'`      (";
    x[8] = "              || /_,-,_|      | `''--..__  (                  .-'```'--._  ";
    x[9] = "         _.--'_  '-;_/_)_     |(``'''---.;'/-,.-.  _         /  .---.    ;  ";
    x[10] = "        /6    ^`     ':_/     | '-._    .-'../__ )' ',.-. _ |  /     |    |";
    x[11] = "       (`-----`--'.    \_)    ;|`'-.;-./        `''--;.__) ',-.      (|    ) ";
    x[12] = "      __)         {|   |_/)   ||    _.'                  `'-;_ )'-,_(`    ;";
    x[13] = "       /         {=|   |)  ).-'||  /                          `'-.;_:'   /'";
    x[14] = "                 {=|    |_.'    )) '        /                           /'";
    x[15] = "                 {=|     ,                 |      ,                _.-'";
    x[16] = "                  {=;     `''--.            |    '.       __,.---'`";
    x[17] = "                   {=|          `|           '._   '._.-'`";
    x[18] = "             _,.--'`;{| '-.._    /        __,..-'-._ '.";
    x[19] = "            (((/==)/ _`;.--''` .'--''''```  .--'```    )";
    x[20] = "                  ' (((/====```            ((((/======'";
    for(int i=2;i<21;i++){std::cout << x[i] << std::endl;}
    std::cout<< std::endl << " ";
    system("pause");
}

void LokaceNPC::vypisNPC(Hrdina* hero,Pozice2d* mojePozice,PoziceNPC* mistniNPC){
    int r = mojePozice->getRadek();
    int s = mojePozice->getSloupec();
    if ((mistniNPC->zjistiNPC(r,s))!=0){
    obrazekNPC();
    hero->interagujNPC(mojePozice,mistniNPC);
    }else{mistniNPC->neniNPC();}
}
