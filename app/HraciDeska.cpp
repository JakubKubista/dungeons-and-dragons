#include "HraciDeska.h"

modelHra::HraciDeska::HraciDeska(const unsigned int pocetRadek, const unsigned int pocetSloupcu, const int nulovaciPrvek)
{

    std::vector<int> pomocnyRadek(pocetSloupcu, nulovaciPrvek);
    // lze samozrejme i jinak
    m_deska.resize(pocetRadek);
    for(int i=0; i<pocetRadek; i++)
    {
        m_deska[i] = pomocnyRadek;
    }
    m_pocetSloupcu = pocetSloupcu;
    m_pocetRadek = pocetRadek;
}

int modelHra::HraciDeska::vrat(const unsigned int radek, const unsigned int sloupec)
{
    // kontroluji, zda nepristupuji mimo rozsah pole
    if ((radek < m_pocetRadek) and (sloupec < m_pocetSloupcu))
    {
        return m_deska[radek][sloupec];
    }
    else
    {
        std::cerr << "Snazite se pristoupit mimo rozsah desky!" << std::endl;
        std::cerr << "Pozadadovana pozice [" << radek << ", " << sloupec << "]." << std::endl;
        std::cerr << "Maximalni pozice [" << m_pocetRadek-1 << ", " << m_pocetSloupcu-1 << "]." << std::endl;
        return 0;
    }
}

void modelHra::HraciDeska::vloz(const unsigned int radek, const unsigned int sloupec, const int prvek)
{
    // kontroluji, zda nepristupuji mimo rozsah pole
    if ((radek < m_pocetRadek) and (sloupec < m_pocetSloupcu))
    {
        m_deska[radek][sloupec] = prvek;
    }
    else
    {
        std::cerr << "Vloz - Pokus o pristup mimo rozsah desky!" << std::endl;
        std::cerr << "Pozadadovana pozice [" << radek << ", " << sloupec << "]." << std::endl;
        std::cerr << "Maximalni pozice [" << m_pocetRadek-1 << ", " << m_pocetSloupcu-1 << "]." << std::endl;
    }
}

void modelHra::HraciDeska::ulozDoTextovehoSouboru(const std::string cesta)
{
    std::ofstream out(cesta.c_str());
    if (out.is_open())
    {
        // uloz pocet radek a pocet sloupcu
        out << m_pocetRadek << " " << m_pocetSloupcu << std::endl;
        // uloz postupne obsah matice
        for(int radek=0; radek<m_pocetRadek; radek++)
        {
            for(int sloupec=0;  sloupec<m_pocetSloupcu; sloupec++)
            {
                out << m_deska[radek][sloupec] << " ";
            }
            out << std::endl;
        }
        out.close();
    }
    else
    {
        std::cerr << " Nelze ulozit do: " << cesta << std::endl << std::endl;
        std::cerr << " ";
        system("pause");
    }
}

void modelHra::HraciDeska::nactiZTextovehoSouboru(const std::string cesta)
{
    std::ifstream in(cesta.c_str());
    if (in.is_open())
    {
        // nacti pocet radek a pocet sloupcu
        in >> m_pocetRadek;
        in >> m_pocetSloupcu;
        // vytvor matici prislusne velikosti
        std::vector<int> pomocnyRadek(m_pocetSloupcu, 0);
        m_deska.resize(m_pocetRadek);
        for(int i=0; i<m_pocetRadek; i++)
        {
            m_deska[i] = pomocnyRadek;
        }
        // nacti postupne obsah matice
        for(int radek=0; radek<m_pocetRadek; radek++)
        {
            for(int sloupec=0;  sloupec<m_pocetSloupcu; sloupec++)
            {
                in >> m_deska[radek][sloupec];
            }
        }
        in.close();
    }
    else
    {
        std::cerr << " Nelze nacist z: " << cesta << std::endl << std::endl;
        std::cerr << " ";
        system("pause");
    }
}

int modelHra::HraciDeska::getPocetRadek()
{
    return m_pocetRadek;
}

int modelHra::HraciDeska::getPocetSloupcu()
{
    return m_pocetSloupcu;
}

void modelHra::HraciDeska::vypisDesku()
{
    for(int radek=0; radek<m_pocetRadek; radek++)
    {
        for(int sloupec=0;  sloupec<m_pocetSloupcu; sloupec++)
        {
            std::cout << m_deska[radek][sloupec] << " ";
        }
        std::cout << std::endl;
    }
}

void modelHra::HraciDeska::lebka(){
        system("cls");
        std::cout << std::endl << std::endl;
        std::cout <<" \t\t       Vitejte ve hre Dungeons and Dragons " << std::endl << std::endl;
        std::cout <<" ----------------------------------------------------------------------------- " << std::endl;
        std::cout <<"\t	     _..-------.._"<< std::endl;
        std::cout <<"\t\t   .'             '."<< std::endl;
        std::cout <<"\t\t  '                 '"<< std::endl;
        std::cout <<"\t\t ;                   ;"<< std::endl;
        std::cout <<"\t\t |     by Jakub      |"<< "\t\t   1: Pokracovat " << std::endl;
        std::cout <<"\t\t ;                   ;"<< "\t\t   2: Nova hra " << std::endl;
        std::cout <<"\t\t  ' (`'--,    ,--'`) '"<< "\t\t   3: Navod " << std::endl;
        std::cout <<"\t\t   ' |  _ )  ( _  | '"<<  "\t\t   4: Konec hry " << std::endl;
        std::cout <<"\t\t    ) )(')|  |(')( ("<< std::endl;
        std::cout <<"\t\t   (_ `--` ^^ `--` _)"<< std::endl;
        std::cout <<"\t\t     `--, (  ) ,--`"<< std::endl;
        std::cout <<"\t\t     `| / `--` \ |`"<< std::endl;
        std::cout <<"\t\t       |/|/|/|/|/"<< std::endl;
        std::cout <<"\t\t       |        |"<< std::endl;
        std::cout <<"\t\t       |/|/|/|/ |"<< std::endl;
        std::cout <<"\t\t       |`-`--`-`|"<< std::endl;
        std::cout <<"\t\t       |        |"<< std::endl;
        std::cout <<"\t\t         ',__,'"<< std::endl;
        std::cout <<"\t\t          q__p \t\t\t  Vyberte volbu: ";
}
void modelHra::HraciDeska::lebkaNavod(){
        system("cls");
        std::cout << std::endl << std::endl;
        std::cout <<"                                     NAVOD                                     " << std::endl << std::endl;
        std::cout <<" ----------------------------------------------------------------------------- " << std::endl;
        std::cout <<"\t	     _..-------.._"<< std::endl;
        std::cout <<"\t\t   .'             '."<< std::endl;
        std::cout <<"\t\t  '                 '"<< std::endl;
        std::cout <<"\t\t ;                   ;"<< std::endl;
        std::cout <<"\t\t |                   |"<< "\t     S potesenim vam predstavuji" << std::endl;
        std::cout <<"\t\t ;                   ;"<< "\t     prvni verzi hry Dungeons and" << std::endl;
        std::cout <<"\t\t  ' (`'--,    ,--'`) '"<< "\t     Dragons. Jedna se o adventuru" << std::endl;
        std::cout <<"\t\t   ' |  _ )  ( _  | '"<<  "\t     bez grafickeho rozhrani." << std::endl;
        std::cout <<"\t\t    ) )(')|  |(')( ("<< std::endl;
        std::cout <<"\t\t   (_ `--` ^^ `--` _)"<< std::endl;
        std::cout <<"\t\t     `--, (  ) ,--`"<<    "\t     Cil hry = Zabij vsechny  " << std::endl;
        std::cout <<"\t\t     `| / `--` \ |`"<<    "\t     ohnive draky a najdi legendarni" << std::endl;
        std::cout <<"\t\t       |/|/|/|/|/"<<      "\t     Draci Zbroj a Draci Mec." << std::endl;
        std::cout <<"\t\t       |        |"<<      "\t     Ale davej se na pozoru, pri" << std::endl;
        std::cout <<"\t\t       |/|/|/|/ |"<<      "\t     tve velkolepe vyprave na tebe" << std::endl;
        std::cout <<"\t\t       |`-`--`-`|"<<      "\t     ciha spousta nebezpeci!" << std::endl;
        std::cout <<"\t\t       |        |"<< std::endl;
        std::cout <<"\t\t         ',__,'"<< std::endl;
        std::cout <<"\t\t          q__p "<<        "\t     ";system("pause");
}
