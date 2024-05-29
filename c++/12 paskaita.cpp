#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

std::string tarpai(const std::string &tekstas)
{
    std::string galutinisTekstas = tekstas;
    for (char &raide : galutinisTekstas)
    {
        if (raide == ' ')
        {
            raide = ';';
        }
    }
    return galutinisTekstas;
}

int *sortasskaiciu(const std::string &tekstas, int &dydis)
{
    int *skaiciai = new int[dydis];
    int kiekis = 0;
    std::string laikinas;
    std::istringstream srautas(tekstas);

    while (std::getline(srautas, laikinas, ';'))
    {
        ;
        if (isdigit(laikinas[0]))
        {
            std::istringstream skaiciuSrautas(laikinas);
            skaiciuSrautas >> skaiciai[kiekis];
            kiekis++;
        }
    }

    dydis = kiekis;
    return skaiciai;
}

void regroup(const std::string &tekstas, const std::string &failoVardas)  
{
    std::string *zodziai = new std::string[100];
    int kiekis = 0;
    std::string laikinas;
    std::istringstream srautas(tekstas);

    while (std::getline(srautas, laikinas, ';'))
    {
        if (!isdigit(laikinas[0]))
        {
            zodziai[kiekis] = laikinas;
            kiekis++;
        }
    }

    std::sort(zodziai, zodziai + kiekis);

    std::ofstream outputFile(failoVardas);
    if (outputFile.is_open())
    {
        for (int i = 0; i < kiekis; i++)
        {
            outputFile << zodziai[i] << " ";
        }
        outputFile.close();
    }
}
int main()
{
    std::string tekstas = "siandien man sueina 20 metu ir gavau 50 euru ir 80 centu ";
    tekstas = tarpai(tekstas);

    int dydis = 100;
    int *skaiciai = sortasskaiciu(tekstas, dydis);

    for (int i = 0; i < dydis; i++)
    {
        std::cout << skaiciai[i] << " ";
    }
    regroup(tekstas, "zodziai.txt");
}