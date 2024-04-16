#include <iostream>
#include <string>

bool funkcija(char inputas_zodis)
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
int main()
{
    char inputas_eilute[30];
    char inputas_zodis[10] = {};
    int eilutes_index = 0;
    int zodzio_index = 0;
    bool baik = false;
    std::cin.get(inputas_eilute, 29);
    while (baik == false)
    {
        if (inputas_eilute[eilutes_index] != ' ' && inputas_eilute[eilutes_index] != '\0')
        {
            inputas_zodis[zodzio_index] = inputas_eilute[eilutes_index];
            zodzio_index++;
            eilutes_index++;
        }
        else
        {
            inputas_zodis[zodzio_index] = '\0';
            // std::cout << inputas_zodis << '\n';
            std::cout << funkcija(zodis);
            if (inputas_eilute[eilutes_index] == '\0')
            {
                baik = true;
            }
            eilutes_index++;
            zodzio_index = 0;
        }
    }
}
