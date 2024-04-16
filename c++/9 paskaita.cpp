#include <iostream>

bool funkcija(char zodis[])
{
    bool rastas = false;
    int i = 0;
    while (rastas == false)
    {
        if (zodis[i] == 's')
        {
            if (zodis[i + 1] == '\0')
            {
                return true;
            }
        }
        i++;
    }
}
// int main()
// {
//     char inputas_eilute[30];
//     char inputas_zodis[10] = {};
//     int eilutes_index = 0;
//     int zodzio_index = 0;
//     bool baik = false;
//     std::cin.get(inputas_eilute, 29);
//     while (baik == false)
//     {
//         if (inputas_eilute[eilutes_index] != ' ' && inputas_eilute[eilutes_index] != '\0')
//         {
//             inputas_zodis[zodzio_index] = inputas_eilute[eilutes_index];
//             zodzio_index++;
//             eilutes_index++;
//         }
//         else
//         {
//             inputas_zodis[zodzio_index] = '\0';
//             std::cout << inputas_zodis << '\n';
//             if (inputas_eilute[eilutes_index] == '\0')
//             {
//                 baik = true;
//             }
//             zodzio_index = 0;
//             eilutes_index = 0;
//         }
//     }
// }
int main()
{
    char Eilute[30];
    char zodis[10] = {};
    int e_ind = 0, z_ind = 0;
    bool pabaiga = false;
    cout << "Iveskite teksto eilute: \n";
    cin.get(Eilute, 29);
    cout << "\nIsvedame zodzius po viena:\n";
    while (pabaiga == false)
    {
        if (Eilute[e_ind] != ' ' && Eilute[e_ind] != '\0') // Tikriname, ar simbolis nėra tarpas
        {                                                  // bei eilutės pabaigos simbolis
            zodis[z_ind] = Eilute[e_ind];                  // Kopijuojame po 1 simbolį į masyvą zodis
            e_ind++;
            z_ind++;
        }
        else
        {
            zodis[z_ind] = '\0'; // Masyvo zodis gale įterpiame eilutės pabaigos simbolį
            cout << zodis << ‘\n';
            if (Eilute[e_ind] == '\0’)
            pabaiga = true;
            e_ind++; z_ind = 0; //Masyvo zodis indeksavimą pradedame iš naujo
        }
    }
    return 0;
}