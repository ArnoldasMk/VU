#include <iostream>
#include <math.h>
#include <iomanip>

// double function(double e) {
//     double n = 1.0;
//     double an = sqrt(n / (n*n + 1)) + sqrt(n*n - 1);
//     double an_minus_1 = 0.0;

//     while (abs(an - an_minus_1) >= e) {
//         n += 1.0;
//         an_minus_1 = an;
//         an = sqrt(n / (n*n + 1)) + sqrt(n*n - 1);
//     }

//     std::cout << "Ribą " << an << " pasiekėme, kai n buvo " << n << "." << std::endl;
//     return an;
// }

// int main() {
//     double e = 0.00001;
//     function(e);
// }

// double function(double a, double e) {
//     double x0;
//     if (a <= 1) {
//         x0 = 0.95;
//     } else if (a <= 25) {
//         x0 = a / 5;
//     } else {
//         x0 = a / 25;
//     }

//     double xn = x0;
//     double xn_plus_1 = (0.2) * (4 * xn + a / pow(xn, 4));

//     while (abs(xn_plus_1 - xn) > e) {
//         xn = xn_plus_1;
//         xn_plus_1 = (0.2) * (4 * xn + a / pow(xn, 4));
//     }

//     return xn_plus_1;
// }

// int main() {
//     double a;
//     double e = 0.00001;
//     std::cout << "Įveskite skaičių a";
//     std::cin >> a;
//     double saknis = function(a, e);
//     std::cout << "Penktojo laipsnio šaknis iš " << a << " yra " << saknis << "\n";
// }

long double factorialas(int n)
{
    double skaicius = 1;
    for (int i = n; i > 0; i -= 1)
    {
        skaicius *= i;
    }
    return skaicius;
}

void funkcija(double x, long double e)
{
    double laipsniai = x * M_PI / 180.0;
    long double suma = 1;
    int n = 2;
    long double laikinas = 1;

    while (std::abs(laikinas) >= e)
    {
        if (n % 2 == 0)
        {
            laikinas = std::pow(-1, n / 2) * std::pow(laipsniai, n) / factorialas(n);
            //std::cout << std::setw(10) << "n = " << std::setw(5) << n << std::setw(15) << "laikinas = " << std::setw(16) << laikinas << std::setw(10) << "suma = " << std::setw(28) << suma << std::setprecision(20) << std::endl;
            suma += laikinas;
        }
        n += 1;
    }
    std::cout << "cos(" << x << ") = " << suma << std::endl;
}

double cosinus(double laipsniai)
{
    double radianai = laipsniai * M_PI / 180.0;
    return std::cos(radianai);
}
int main()
{
    double x = 0;
    long double e = 0.0000001;
    
    std::cout << "Įveskite x  ";
    std::cin >> x;
    std::cout << "cos(x) su paklaida: ";
    funkcija(x, e);
    std::cout << "\n";
    std::cout << "cos(x) be paklaidos: " << cosinus(x) << "\n";
}