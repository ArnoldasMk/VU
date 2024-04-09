#include <iostream>
#include <random>
#include <math.h>

double masyvovidurkis(int n, int masyvas[])
{
    int suma = 0;
    for (int i = 0; i < n; i++)
    {
        suma += masyvas[i];
    }
    return suma * 1.0 / n;
}
void vidurkioartimas(int n, int masyvas[])
{
    double vidurkis;
    int skaicius;
    vidurkis = masyvovidurkis(n, masyvas);
    int artimiausias = masyvas[0];
    int e = abs(vidurkis - masyvas[0]);
    for (int i = 1; i < n; i++)
    {
        if (abs(vidurkis - masyvas[i]) < e)
        {
            e = abs(vidurkis - masyvas[i]);
            artimiausias = masyvas[i];
            skaicius = n;
        }
    }
    std::cout << "artimiausias " << artimiausias << ", kai n = " << skaicius << "\n";
}
void perkelimasmasyvu(int n, int masyvas[], float masyvas2[])
{
    double vidurkis = masyvovidurkis(n, masyvas);
    for (int i = 0; i < n; i++)
    {
        if (masyvas[i] < vidurkis)
        {
            masyvas2[i] = masyvas[i];
        }
        else
        {
            masyvas2[i] = 0;
        }
    }
}
void sorteris(float masyvas2[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int max = i;
        for (int j = i + 1; j < n; j++)
        {
            if (masyvas2[j] > masyvas2[max])
            {
                max = j;
            }
        }
        int laikinas = masyvas2[i];
        masyvas2[i] = masyvas2[max];
        masyvas2[max] = laikinas;
        std ::cout << masyvas2[i] << " ";
    }
}
int main()
{
    int n = 10;
    int masyvas[n];
    float masyvas2[n];  
    for (int i = 0; i < 5; i++)
    {
        std::cin >> masyvas[i];
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << masyvas[i] << " ";
    }
    for (int i = 5; i < 10; i++)
    {
        masyvas[i] = rand() % 21 + 10;
        std::cout << masyvas[i] << " ";
    }
    std::cout << "Vidurkis" << masyvovidurkis(n, masyvas) << std::endl;
    vidurkioartimas(n, masyvas);
    perkelimasmasyvu(n, masyvas, masyvas2);
    sorteris(masyvas2, n);
}