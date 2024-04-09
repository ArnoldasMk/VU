#include <iostream>
#include <stdio.h>
#include <cmath>
// document all the lines in this code:

// int main()
// {
//     int i;
//     std::cin >> i;
//     while (i > 0)
//     {
//         if (i % 2 == 0)
//         {
//             std::cout << i << "\n";
//         }
//         i--;
//     }
// }

int main()
{
    int i;
    float n = 1;
    int sum = 1;
    while (i > 0)
    {
        std::cin >> i;
        std::cout << sum++ << "  " << sqrt(i) << "\n";
    }
}

// int main()
// {
//     float sum1 = 0;
//     float sum2 = 0;
//     int n1 = 3;
//     int n2 = 3;
//     while (n1 > 0)
//     {
//         sum1 = sum1 + (1 / (pow(2, n1)));
//         std::cout << "n1 " << sum1 << "\n";
//         n1--;
//     }
//     while (n2 > 0)
//     {
//         sum2 = sum2 + (1 / (pow(2, n2)));
//         std::cout << "n2 " << sum2 << "\n";
//         n2--;
//     }
//     std::cout << "sudetis " << sum1 + sum2 << "\n";
//     std::cout << "atimtis " << sum1 - sum2;
// }