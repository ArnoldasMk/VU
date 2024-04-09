#include <cmath>
#include <iostream>
#define _USE_MATH_DEFINES

using namespace std;
// 1
// int main()
// {
//     double rez1;
//     double rez2;
//     double rez;
//     double x;
//     for (int i = 0; i < 15; i++)
//     {
//         x++;
//         rez1 = cos(x);
//         rez2 = pow((1/x), 4);
//         rez = rez1+rez2;
//         std::cout << "Argumentas  " << "  Argumentas " << "| " << i << " |" << "      Rezultatas" << "| " << rez << " \n";
//     }
// }
// 2
// int main()
// {
// double rez1;
// double rez2;
// double rez;
// double x=0;
// for (int i = 0; i < 90; i++)
// {
//     x=x+1;
//     if (i == 0)
//     {
//         x = 0;
//     }
//     rez1=sin(x);
//     rez2=cos(x);
//     rez=rez1+rez2;
//     rez = sqrt(rez);
//     cout << x << "  " << rez*2/3 << "\n";
// }
// 3
int main()
{
    double rez1;
    double rez2;
    double rez;
    double x;
    cin >> x;
    rez1 = sin(x);
    rez2 = cos(x);
    rez = rez1 + rez2;
    rez = sqrt(rez)* 2 / 3;
    cout << rez << "\n";
    double galutinis = (rez > M_PI/2) ? 0 : M_PI / 2;
    cout << galutinis;
}