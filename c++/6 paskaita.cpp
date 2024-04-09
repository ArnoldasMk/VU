#include <iostream>
#include <string>
#include <cmath>
// void function(char kintamasis='A')
// {
//     if (kintamasis == 'A')
//     {
//         std::cout << "Sveiki, esu funkcija!";
//     }
//     if (kintamasis == 'E' && kintamasis == 'e')
//     {
//         std::cout << "Hello, I'm a function!";
//     }
//     if (kintamasis == 'D' && kintamasis == 'd')
//     {
//         std::cout << "Hallo, ich bin eine Funktion!";
//     }
//     if (kintamasis == 'F' && kintamasis == 'f')
//     {
//         std::cout << "Bonjour, je suis une fonction!";
//     }
// }
// int main()
// {
//     char kintamasis = 'A';
//     std::cin >> kintamasis;
//     function(kintamasis);
// }
// double atstumas(double x, double y)
// {
//     return sqrt(pow(x,2)+pow(y,2));
// }
// void vieta(double x, double y)
// {
//     if (x > 0 && y > 0)
//     {
//         std::cout << "1 ketvirtis";
//     }
//     else if (x < 0 && y > 0)
//     {
//         std::cout << "2 ketvirtis";
//     }
//     else if (x < 0 && y < 0)
//     {
//         std::cout << "3 ketvirtis";
//     }
//     else if (x > 0 && y < 0)
//     {
//         std::cout << "4 ketvirtis";
//     }
//     else if (x < 0 && y < 0)
//     {
//         std::cout << "0;0";
//     }
// }
// int main()
// {
//     double x, y;
//     std::cin >> x >> y;
//     std::cout << atstumas(x, y) << "\n";
//     vieta(x,y);
// }
bool rezultatas(int K, int p)
{
    if (K % p == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int K = 100;
    int p = K;
    // std::cin >> K;
    while (p > 0)
    {
        if (rezultatas(K,p))
        {
            std::cout << p << "\n";
        }
        p--;
    }
}