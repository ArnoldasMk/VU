#include <iostream>
#include <string>

class kaimynai
{
private:
    std::string vardas;
    int id;
    int amzius;

public:
    void InputVardas()
    {
        std::cout << "Iveskite varda: ";
        std::cin >> vardas;
    }

    void InputId()
    {
        std::cout << "Iveskite id: ";
        std::cin >> id;
    }

    void InputAmzius()
    {
        std::cout << "Iveskite amziu: ";
        std::cin >> amzius;
    }

    std::string grazinkVardas()
    {
        return vardas;
    }

    int grazinkId()
    {
        return id;
    }

    int grazinkAmzius()
    {
        return amzius;
    }
    void output1()
    {
        std::cout << "  *   Vardas     *     ID numeris     *  amžius  *" << std::endl;
        std::cout << "  ******************************************" << std::endl;
    }
    void output2()
    {
        std::cout << "  *   " << vardas << "   *   " << id << "   *   " << amzius << "   *" << std::endl;
    }
    kaimynai()
    {
        id = 2;
        amzius = rand() % 50 + 1;
        vardas = "Paulius";
    }
    kaimynai(std::string vardas, int id, int amzius)
    {
        InputVardas();
        InputId();
        InputAmzius();
    }
    void Amziupalyginimas(kaimynai &k1, kaimynai &k2, kaimynai &k3)
    {
        if (k1.grazinkAmzius() > k2.grazinkAmzius() && k1.grazinkAmzius() > k3.grazinkAmzius())
        {
            std::cout << "Vyriausias kaimynas: " << k1.grazinkVardas() << std::endl;
        }
        else if (k2.grazinkAmzius() > k1.grazinkAmzius() && k2.grazinkAmzius() > k3.grazinkAmzius())
        {
            std::cout << "Vyriausias kaimynas: " << k2.grazinkVardas() << std::endl;
        }
        else
        {
            std::cout << "Vyriausias kaimynas: " << k3.grazinkVardas() << std::endl;
        }
    }
    void Abecelespalyginimas(kaimynai &k1, kaimynai &k2, kaimynai &k3)
    {
        if (k1.grazinkVardas()[0] < k2.grazinkVardas()[0] && k1.grazinkVardas()[0] < k3.grazinkVardas()[0])
        {
            std::cout << "Pirmas pagal abecele: " << k1.grazinkVardas() << std::endl;
        }
        else if (k2.grazinkVardas()[0] < k1.grazinkVardas()[0] && k2.grazinkVardas()[0] < k3.grazinkVardas()[0])
        {
            std::cout << "Pirmas pagal abecele: " << k2.grazinkVardas() << std::endl;
        }
        else
        {
            std::cout << "Pirmas pagal abecele: " << k3.grazinkVardas() << std::endl;
        }
    }
};

int main()
{
    char confirm;
    kaimynai kaimynas;
    kaimynas.InputVardas();
    kaimynas.InputId();
    kaimynas.InputAmzius();
    kaimynai k2;
    kaimynas.output1();
    kaimynas.output2();
    k2.output2();
    kaimynai k3("Tomas", 3, 30);
    k3.output2();
    std::cout << "ar norite suzinot kas vyriausias y/n" << std::endl;
    std::cin >> confirm;
    if (confirm = 'y')
    {
        kaimynas.Amziupalyginimas(kaimynas, k2, k3);
    }
    confirm = 'n';
    std::cout << "ar norite suzinot kas pirmas pagal abecele y/n" << std::endl;
    std::cin >> confirm;
    if (confirm = 'y')
    {
        kaimynas.Abecelespalyginimas(kaimynas, k2, k3);
    }
}