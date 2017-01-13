#include "Hrdina.h"

Hrdina::Hrdina() {
	m_zivoty = 100.0f;
	m_maxZivoty = 100.0f;
	m_sila = 0;
	m_obrana = 0;
	m_magie = 0;
	m_zkusenosti = 0;
	m_uroven = 1;
	m_maxZkusenosti = 300;
	m_pocetZabitychNepratel = 0;
	m_ankVzkriseni = 3;
	m_typHrdiny = "Zebrak";
	m_nesenaZbran = new Zbran();
	m_nesenaZbroj = new Zbroj();
	m_interakceNPC = nullptr;
	m_inventarLektvar = new InventarLektvar();
	m_inventarZbran = new InventarZbran();
	m_inventarZbroj = new InventarZbroj();
}

Hrdina::Hrdina(std::string jmeno) {
    m_jmeno = jmeno;
	m_zivoty = 500.0f;
	m_maxZivoty = 500.0f;
	m_sila = 70;
	m_obrana = 70;
	m_magie = 70;
	m_zkusenosti = 10000;
	m_uroven = 15;
	m_maxZkusenosti = 12000;
	m_pocetZabitychNepratel = 100;
	m_ankVzkriseni = 3;
	m_typHrdiny = "Mag";
	m_nesenaZbran = new Zbran();
	m_nesenaZbroj = new Zbroj();
	m_interakceNPC = nullptr;
	m_inventarLektvar = new InventarLektvar();
	m_inventarZbran = new InventarZbran();
	m_inventarZbroj = new InventarZbroj();
}

void Hrdina::setJmeno(std::string jmeno){
	std::cout << "\t\t\t Zadejte jmeno hrdiny: ";
	std::cin >> jmeno;
	m_jmeno = jmeno;
}

void Hrdina::setTypHrdiny(std::string typHrdiny){
	m_typHrdiny = typHrdiny;
}

void Hrdina::setSila(int sila){
	m_sila = sila;
}

void Hrdina::setObrana(int obrana){
	m_obrana = obrana;
}

void Hrdina::setMagie(int magie){
	m_magie = magie;
}

void Hrdina::setZivoty(){
	m_zivoty = m_maxZivoty;
}

std::string Hrdina::getJmeno() {
	return m_jmeno;
}

int Hrdina::getSila() {
	return m_sila+(m_nesenaZbran->getBonusSily());
}

int Hrdina::getObrana() {
	return m_obrana+(m_nesenaZbroj->getBonusObrany());
}

int Hrdina::getUroven() {
	return m_uroven;
}

float Hrdina::getMaxZkusenosti(){
    m_maxZkusenosti += (m_uroven*150);
    return m_maxZkusenosti;
}

InventarLektvar* Hrdina::getInventarLektvar(){
    return m_inventarLektvar;
}

InventarZbran* Hrdina::getInventarZbran(){
    return m_inventarZbran;
}

InventarZbroj* Hrdina::getInventarZbroj(){
    return m_inventarZbroj;
}

int Hrdina::getAnkVzkriseni(){
    return m_ankVzkriseni;
}

Pozice2d* Hrdina::ziskejPozici(int radek, int sloupec){
        Pozice2d* mojePozice;
            return m_pozice[radek][sloupec];
}

void Hrdina::naucInterakciNPC(InterakceNPC* novaInterakceNPC) {
    m_interakceNPC = novaInterakceNPC;
}

void Hrdina::interagujNPC(Pozice2d* mojePozice,PoziceNPC* mistniNPC) {
    naucInterakciNPC(new Boj("AktualniBoj"));
    m_interakceNPC->setAktualniZivotyNPC(mistniNPC->vratNPC(mojePozice->getRadek(),mojePozice->getSloupec())->getZivoty());
    m_interakceNPC->setAktualniZivotyHrdina(m_zivoty);
    m_interakceNPC->setKolo(1);
    m_interakceNPC->setZiskZkusenosti(0);
    m_interakceNPC->setAktualniAnkVzkriseni(m_ankVzkriseni);
   	m_interakceNPC->zautoc(mojePozice,mistniNPC,m_maxZivoty,getSila(),getObrana(),m_magie,m_uroven,m_jmeno);
   	m_zivoty = (m_interakceNPC->getAktualniZivotyHrdina());
   	if(m_ankVzkriseni>(m_interakceNPC->getAktualniAnkVzkriseni())){m_zivoty = m_maxZivoty;}
            m_ankVzkriseni = (m_interakceNPC->getAktualniAnkVzkriseni());
            m_zkusenosti += (m_interakceNPC->getZiskZkusenosti());
    if((m_interakceNPC->getAktualniZivotyNPC())<=0){
            m_pocetZabitychNepratel++;
            mistniNPC->vymazKonkretniNPC(mojePozice->getRadek(),mojePozice->getSloupec());}
   	if(m_zkusenosti>=m_maxZkusenosti){
            m_uroven++;
            if(m_magie==0){
            m_sila+=8;
            m_obrana+=8;}else{m_magie+=8;
                              m_sila+=4;
                              m_obrana+=4;}
            m_maxZivoty+=30;
            m_zivoty = m_maxZivoty;
            getMaxZkusenosti();
            m_interakceNPC->zvyseniUrovne(m_uroven,m_magie);}
    delete m_interakceNPC;
}

void Hrdina::interagujItem(Pozice2d* mojePozice,PoziceItem* mistniItem) {
    int r = mojePozice->getRadek();
    int s = mojePozice->getSloupec();
    if(((mistniItem->vratItem(r,s)->getBonusZivoty())!=0)or((mistniItem->vratItem(r,s)->getBonusZkusenosti())!=0)){
    m_inventarLektvar->vlozeniLektvar(mojePozice,mistniItem);}
    if((mistniItem->vratItem(r,s)->getBonusSila())!=0){
    m_inventarZbran->vlozeniZbran(mojePozice,mistniItem);}
    if((mistniItem->vratItem(r,s)->getBonusObrana())!=0){
    m_inventarZbroj->vlozeniZbroj(mojePozice,mistniItem);}
}

void Hrdina::vypijLektvar() {
naucInterakciNPC(new Boj("ZiskZkusenostiLektvar"));
    m_zivoty += m_inventarLektvar->getBonusZivoty();
    if(m_zivoty > m_maxZivoty){m_zivoty = m_maxZivoty;}
    m_zkusenosti += m_inventarLektvar->getBonusZkusenosti();
    m_inventarLektvar->setBonusZivoty(0);
    m_inventarLektvar->setBonusZkusenosti(0);
   	if(m_zkusenosti>=m_maxZkusenosti){
            m_uroven++;
            if(m_magie==0){
            m_sila+=8;
            m_obrana+=8;}else{m_magie+=8;
                              m_sila+=4;
                              m_obrana+=4;}
            m_maxZivoty+=30;
            m_zivoty = m_maxZivoty;
            getMaxZkusenosti();
            m_interakceNPC->zvyseniUrovne(m_uroven,m_magie);}
    delete m_interakceNPC;
}

void Hrdina::uchopZbran(int druhZbrane) {
bool ulozeno = false;
char x;
if(druhZbrane<m_inventarZbran->m_neseneZbraneInventar.size()){
if ((m_inventarZbran->m_neseneZbraneInventar.at(druhZbrane))!=nullptr){
   if (m_nesenaZbran!=nullptr){
        m_nesenaZbran = new Zbran();
        m_nesenaZbran->setNazevZbrane(m_inventarZbran->m_neseneZbraneInventar.at(druhZbrane)->getNazevItemu());
        m_nesenaZbran->setHodnotaZbrane(m_inventarZbran->m_neseneZbraneInventar.at(druhZbrane)->getHodnotaItemu());
        m_nesenaZbran->setBonusSily(m_inventarZbran->m_neseneZbraneInventar.at(druhZbrane)->getBonusSila());
        m_inventarZbran->novaZbran(druhZbrane);
        m_inventarZbran->m_neseneZbraneInventar.at(druhZbrane) = nullptr;
    ulozeno =true;
   }else{
       std::cout << std::endl << " Zbran uz drzite, chcete ji nahradit? (Y/N)";
       std::cin>>x;
       std::cout << std::endl;
        if(x=='y'){x='Y';}
        if(x=='n'){x='N';}
        if(x=='Y'){
                m_nesenaZbran->setNazevZbrane(m_inventarZbran->m_neseneZbraneInventar.at(druhZbrane)->getNazevItemu());
                m_nesenaZbran->setHodnotaZbrane(m_inventarZbran->m_neseneZbraneInventar.at(druhZbrane)->getHodnotaItemu());
                m_nesenaZbran->setBonusSily(m_inventarZbran->m_neseneZbraneInventar.at(druhZbrane)->getBonusSila());
                m_inventarZbran->novaZbran(druhZbrane);
                m_inventarZbran->m_neseneZbraneInventar.at(druhZbrane) = nullptr;
                ulozeno =true;}
        if(x=='N'){ulozeno = false;}
        if((x!='Y')and(x!='N')){
        std::cout << std::endl << "\t\t   Spatne zadana operace! ";
        std::cout << std::endl << "\t\t   ";
        system("pause");}
        }
    }
    else{std::cout << std::endl << " Zadnou Zbran pod timto cislem nemate. " << std::endl;}
}
}

void Hrdina::oblecZbroj(int druhZbroje) {
bool ulozeno = false;
char x;
if(druhZbroje<m_inventarZbroj->m_neseneZbrojeInventar.size()){
if ((m_inventarZbroj->m_neseneZbrojeInventar.at(druhZbroje))!=nullptr){
   if (m_nesenaZbroj!=nullptr){
        m_nesenaZbroj = new Zbroj();
        m_nesenaZbroj->setNazevZbroje(m_inventarZbroj->m_neseneZbrojeInventar.at(druhZbroje)->getNazevItemu());
        m_nesenaZbroj->setHodnotaZbroje(m_inventarZbroj->m_neseneZbrojeInventar.at(druhZbroje)->getHodnotaItemu());
        m_nesenaZbroj->setBonusObrany(m_inventarZbroj->m_neseneZbrojeInventar.at(druhZbroje)->getBonusObrana());
        m_inventarZbroj->novaZbroj(druhZbroje);
        m_inventarZbroj->m_neseneZbrojeInventar.at(druhZbroje) = nullptr;
    ulozeno =true;
   }else{
       std::cout << std::endl << " Zbroj uz drzite, chcete ji nahradit? (Y/N)";
       std::cin>>x;
       std::cout << std::endl;
        if(x=='y'){x='Y';}
        if(x=='n'){x='N';}
        if(x=='Y'){
                m_nesenaZbroj->setNazevZbroje(m_inventarZbroj->m_neseneZbrojeInventar.at(druhZbroje)->getNazevItemu());
                m_nesenaZbroj->setHodnotaZbroje(m_inventarZbroj->m_neseneZbrojeInventar.at(druhZbroje)->getHodnotaItemu());
                m_nesenaZbroj->setBonusObrany(m_inventarZbroj->m_neseneZbrojeInventar.at(druhZbroje)->getBonusObrana());
                m_inventarZbroj->novaZbroj(druhZbroje);
                m_inventarZbroj->m_neseneZbrojeInventar.at(druhZbroje) = nullptr;
                ulozeno =true;}
        if(x=='N'){ulozeno = false;}
        if((x!='Y')and(x!='N')){
        std::cout << std::endl << "\t\t   Spatne zadana operace! ";
        std::cout << std::endl << "\t\t   ";
        system("pause");}
        }
    }
    else{std::cout << std::endl << " Zadnou Zbroj pod timto cislem nemate. " << std::endl;}
}
}

void Hrdina::printInfo() {
            system("cls");
            std::cout << std::endl << std::endl;
            std::cout << "                               Vlastnosti Hrdiny                               " << std::endl << std::endl;
            std::cout << " ----------------------------------------------------------------------------- " << std::endl << std::endl;
            std::cout << "\t\t\t Jmeno: " << m_jmeno << std::endl;
            std::cout << "\t\t\t Druh: " << m_typHrdiny << std::endl;
            std::cout << "\t\t\t Uroven: " << m_uroven << std::endl;
            std::cout << "\t\t\t - - - - - - - - - - - - - - -" << std::endl;
            std::cout << "\t\t\t Pocet anku vzkriseni: " << m_ankVzkriseni << std::endl;
            std::cout << "\t\t\t Zkusenosti: " << m_zkusenosti  << "/" << m_maxZkusenosti << std::endl;
            std::cout << "\t\t\t Zivoty: " << m_zivoty << "/" << m_maxZivoty << std::endl;
            std::cout << "\t\t\t - - - - - - - - - - - - - - -" << std::endl;
            std::cout << "\t\t\t Sila: " << getSila() << std::endl;
            std::cout << "\t\t\t Obrana: " << getObrana() << std::endl;
            std::cout << "\t\t\t Magie: " << m_magie << std::endl;
            std::cout << "\t\t\t - - - - - - - - - - - - - - -" << std::endl;
            std::cout << "\t\t\t Pocet zabitych nepratel: " << m_pocetZabitychNepratel << std::endl;
            std::cout << "\t\t\t Zbran: " << m_nesenaZbran->getNazevZbrane() << " (+"<< m_nesenaZbran->getBonusSily() <<")"<< std::endl;
            std::cout << "\t\t\t Zbroj: " << m_nesenaZbroj->getNazevZbroje() << " (+"<< m_nesenaZbroj->getBonusObrany() <<")"<< std::endl;
            std::cout << "\t\t\t -----------------------------" << std::endl << std::endl;
            std::cout <<"\t\t  ";
            system("pause");
}

void Hrdina::vymazHrdinu(){
    delete m_nesenaZbran;
    delete m_nesenaZbroj;
    delete m_inventarLektvar;
    delete m_inventarZbran;
    delete m_inventarZbroj;
}
