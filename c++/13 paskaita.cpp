#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib> // Įtraukite šią antraštę, kad galėtumėte naudoti rand() funkciją

class Studentas 
{
public:
    std::string vardas;
    int kursas;
    double vidurkis;
};

int cvardai(const std::string& eilute) 
{
    std::istringstream streamas(eilute);
    std::string vardas;
    int kiekis = 0;

    while (streamas >> vardas) 
    {
        kiekis++;
    }
    return kiekis;
}

int main() {
    std::ifstream failas("vardai.txt");
    std::string eilute;
    std::getline(failas, eilute);
    failas.close();

    int varduKiekis = cvardai(eilute);
    Studentas* studentai = new Studentas[varduKiekis];

    std::istringstream streamas(eilute);
    std::string vardas;

    for (int i = 0; i < varduKiekis; i++) 
    {
        streamas >> studentai[i].vardas;
        studentai[i].kursas = rand() % 4 + 1;
        studentai[i].vidurkis = rand() % 10 + 1; 
    }

    std::ofstream rezultatai("rezultatai.txt");

    for (int i = 0; i < varduKiekis; i++) 
    {
        if (studentai[i].kursas > 1 && studentai[i].vidurkis > 8.0) 
        {
            rezultatai << "studentas: " << studentai[i].vardas << "\n";
            rezultatai << "\tkursas - " << studentai[i].kursas << ";\n";
            rezultatai << "\tvidurkis - " << studentai[i].vidurkis << ";\n";
        }
    }
    rezultatai.close();
}