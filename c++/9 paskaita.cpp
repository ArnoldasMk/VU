#include <iostream>

bool funkcija(char zodis[])
{
    bool rastas = false;
    int i = 0;
    while (rastas == false)
    {
        if (zodis[i] == 's')
        {
            if (zodis[i+1] == '\0')
            {
                return true;
            }
        }
        i++;
    }
}
int main()
{
    char Eilute[30];
    char zodis[10] = {};
    int e_ind = 0, z_ind = 0;
    bool pabaiga = false;
    std::cin.get(Eilute, 29);
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
            
            std::cout << zodis << '\n';
            if (Eilute[e_ind] == '\0')
                pabaiga = true;
            e_ind++;
            z_ind = 0; // Masyvo zodis indeksavimą pradedame iš naujo
        }
    }
    return 0;
}