#include <iostream>
#include <fstream>

class Detales
{
private:
    int kodas;
    int detaliu_kiekis;
    std::string yyyy_mm_dd;

public:
    Detales() {}
    Detales(int kodas, int kiekis, std::string data)
    {
        kodas = rand() % 1000000;
        kiekis = rand() % 10;
        gautidata();
    }
    int gautiKoda()
    {
        return kodas;
    }

    int gautiKieki()
    {
        return detaliu_kiekis;
    }

    void gautidata()
    {
        std::cin>>yyyy_mm_dd;
    }

    std::string grazinkData()
    {
        return yyyy_mm_dd;
    }
};

void rast_lygint(Detales masyvas[], int size)
{
    Detales kitas[100]; 
    int kiekis = 0;

    for (int i = 0; i < size; i++)
    {
        if (masyvas[i].gautiKieki() < 3)
        {
            kitas[kiekis++] = masyvas[i];
        }
    }

    for (int i = 0; i < kiekis-1; i++)
    {
        for (int j = 0; j < kiekis-i-1; j++)
        {
            // if (lygint(kitas[j], kitas[j+1]))
            // {
            //     Detales trecias = kitas[j];
            //     kitas[j] = kitas[j+1];
            //     kitas[j+1] = trecias;
            // }
        }
    }
    std::ofstream out("rezultatai.txt");
    for (int i = 0; i < kiekis; i++)
    {
        out << kitas[i].gautiKoda() << " " << kitas[i].gautiKieki() << " " << kitas[i].grazinkData() << std::endl;
    }
}

int main()
{
    std::ifstream in("Tekstas.txt");
    std::string tekstas;
    while (in >> tekstas)
    {
        if (tekstas.size() >= 2)
        {
            std::string galas = tekstas.substr(tekstas.size() - 2);
            if (galas == "as" || galas == "is")
            {
                std::cout << tekstas << std::endl;
            }
        }
    }

    Detales masyvas[8];
    for (int i = 0; i < 8; i++)
    {
        int kodas = rand() % 1000000;
        int kiekis = rand() % 10;
        std::cout << "Iveskite data: ";
        std::string data;
        std::cin >> data;
        masyvas[i] = Detales(kodas, kiekis, data);
    }

    for(int i = 0; i < 8; i++)
    {
        std::cout << i << masyvas[i].gautiKoda() << masyvas[i].gautiKieki() << masyvas[i].grazinkData() << std::endl;
    }

}