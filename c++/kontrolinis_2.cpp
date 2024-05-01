#include <iostream>
#include <cmath>
// Arnoldas Mikša
// 4 variantas
int radimas(char *eilute)
{
    int zenklai = 0;
    for (int i = 0; eilute[i] != '\0'; i++)
    {
        if (eilute[i] == ',' || eilute[i] == '.')
        {
            zenklai++;
        }
    }
    return zenklai;
}
double sumavimas(double *dyn_masyvas, int n)
{
    double suma = 0;
    for (int i = 0; i < n; i++)
    {
        if (dyn_masyvas[i] > 0)
        {
            suma += dyn_masyvas[i];
        }
    }
    return suma;
}
void function(double masyvas[10])
{
    int teigiami = 0;
    int neigiami = 0;
    for (int i = 0; i < 10; i++)
    {
        if (masyvas[i] > 0)
        {
            teigiami++;
        }
        else if (masyvas[i] < 0)
        {
            neigiami++;
        }
    }
    std::cout << "teigiamu skaiciu : " << teigiami << std::endl;
    std::cout << "neigiamu skaiciu : " << neigiami << std::endl;
}

int main()
{
    double masyvas[10];
    for (int i = 0; i < 10; i++)
    {
        masyvas[i] = rand() % (int)(2 * M_PI * 100) / 100.0 - M_PI;
    }
    std::cout << "1. Pradzia" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << masyvas[i] << " ";
    }
    std::cout << std::endl;
    function(masyvas);
    std::cout << "1. Pabaiga " << std::endl;

    std::cout << "2. Pradzia" << std::endl;
    int n = 0;
    std::cout << "Iveskite masyvo dydi: ";
    std::cin >> n;
    double *dyn_masyvas = new double[n];
    double *masyvas1 = new double[n];
    for (int i = 0; i < 10; i++)
    {
        masyvas1[i] = masyvas[i];
    }
    for (int i = 0; i < n; i++)
    {
        dyn_masyvas[i] = masyvas1[i % 10];
        if (i % 10 == 0)
        {
            std::cout << std::endl;
        }
        std::cout << dyn_masyvas[i] << " ";
    }
    std::cout << std::endl << "suma: " << sumavimas(dyn_masyvas, n) << std::endl;
    std::cout << std::endl << "2. pabaiga" << std::endl;
    char eilute[118] = "Today, more than 10 million loT devices are already expanding business activity in telematics, network, telemedicine.";
    std::cout << "3. pradzia" << std::endl;
    std::cout << "zenklu skaicius : " << radimas(eilute) << std::endl;
    std::cout << "3. pabaiga" << std::endl;
}