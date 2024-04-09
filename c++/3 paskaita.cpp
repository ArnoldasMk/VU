#include <iostream>
#include <stdio.h>

// int main()
// {
//     int x = 0, y = 0;
//     std::cin >> x;
//     std::cin >> y;

//     if (x > 0 && y > 0)
//     {
//         std::cout << "1 ketvirtis";
//     }    
//     else if (x < 0 && y > 0)
//     {
//         std::cout << "2 ketvirtis";
//     }    
//     else if (x > 0 && y < 0)
//     {
//         std::cout << "3 ketvirtis";
//     }
//     else if (x < 0 && y < 0)
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
//     int parduota_verte, parduota_n, parduota_viso;

//     std::cin >> parduota_verte;
//     std::cin >> parduota_n;

//     parduota_viso = parduota_verte * parduota_n;
//     std::cout << "Parduota viso PRADZIOJE:  " << parduota_viso << "\n";
//     if (parduota_viso > 10000)
//     {
//         parduota_viso = parduota_viso * 0.3;
//     }
//     else 
//     {
//         parduota_viso = parduota_viso * 0.25;
//     }
//     if (parduota_viso > 5000 || parduota_verte > 500)
//     {
//         parduota_viso = parduota_viso - parduota_viso * 0.15;
//     }
//     std::cout << "Parduota viso Pabaigoje:  " << parduota_viso << "\n";
// }

int main()
{
    int minutes, valandos, i, n;
    std::cout << "Valandos" << "\n";
    std::cin >> valandos;
    std::cout << "Minutes"<< "\n";
    std::cin >> minutes;
    std::cout << "i"<< "\n";
    std::cin >> i;

    minutes = minutes + i;
    if (minutes >= 60)
    {
        n = i / 60;
        valandos = valandos + 1*n;
        minutes = minutes - 60 * n;
    }
    if (valandos >= 24)
    {
        n = i / 1440;
        valandos = valandos - 24 * n;
    }
    std::cout << valandos << " H" << minutes << " min" << " Trukme: " << i;
}