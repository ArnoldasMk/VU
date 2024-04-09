#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
// 5 VAR // ARNOLDAS MIKŠA
double function(int n, int K)
{
    return K - (K / (1 + pow((n / K), 2)));
}
int main()
{
    // 1
    int sveikas;
    double realus;
    std::cout << "1. Input sveikas 5-25 >> ";
    std::cin >> sveikas;
    if (sveikas >= 5 && sveikas <= 25)
    {
        std::cout << "1. Patenka" << "\n";
        realus = sveikas / 3;
        std::cout << "1. realus: " << realus << "\n";
    }
    else
    {
        std::cout << "1. Nepatenka" << "\n";
        return 0;
    }
    std::cout << "\n";
    // 2
    int K, n;
    std::cout << "2. Input K ";
    std::cin >> K;
    std::cout << "2. Input n ";
    std::cin >> n;
    std::cout << "\n";
    std::cout << "2. Atsakymas: " << function(n, K) << "\n";
    // 3
    int kartai = 1;
    double suma = 0;
    while (true)
    {
        suma = suma + function(kartai, sveikas);
        if(suma > 1.5 * sveikas)
        {
            std::cout << "3. suma: " << suma << " kai n = " << kartai  <<  "\n";
            break;
        }
        kartai++;
    }
    // 4
    if (sveikas % 5 == 0)
    {
        std::cout << sveikas << " <- 4. yra skaciaus 5 kartotinis" << "\n";
    }
    else
    {
        std::cout << sveikas << " <- 4. NERA skaiciaus 5 kartotinis" << "\n";
    }
}