#include <iostream>
#include <string>
#include <sstream>
void skyryba(char inputas_eilute[])
{
    int taskas = 0;
    int kablelis = 0;

    for (int i = 0; inputas_eilute[i] != '\0'; i++)
    {
        if (inputas_eilute[i] == '.')
        {
            taskas++;
        }
        else if (inputas_eilute[i] == ',')
        {
            kablelis++;
        }
    }

    std::cout << "Tasku " << taskas << std::endl;
    std::cout << "Kableliu " << kablelis << std::endl;
}

void funkcija2(char inputas_eilute[])
{
    char zodis[30];
    int indexas = 0;
    for (int i = 0; inputas_eilute[i] != '\0'; i++)
    {
        if (inputas_eilute[i] != ' ' && inputas_eilute[i] != ',' && inputas_eilute[i] != '.')
        {
            zodis[indexas++] = inputas_eilute[i];
        }
        else
        {
            if (indexas > 0 && zodis[indexas - 1] == 's')
            {
                zodis[indexas] = '\0';
                std::cout << zodis << std::endl;
            }
            indexas = 0;
        }
    }
    if (indexas > 0 && zodis[indexas - 1] == 's')
    {
        zodis[indexas] = '\0';
        std::cout << zodis << std::endl;
    }
}

int main()
{
    char inputas_eilute[30];
    std::cin.get(inputas_eilute, 29);
    skyryba(inputas_eilute);
    funkcija2(inputas_eilute);

    int kiekis = 0;
    int did = 0;

    std::istringstream inputas(inputas_eilute);
    std::string zodis;

    while (inputas >> zodis)
    {
        if (isdigit(zodis[0]))
        {
            int skaicius;
            std::istringstream(zodis) >> skaicius;
            kiekis++;
            if (skaicius > did)
            {
                did = skaicius;
            }
        }
    }

    std::cout << "kiekis" << kiekis << std::endl;
    std::cout << "Didziausias" << did << std::endl;
}
