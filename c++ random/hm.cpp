//Justinas Kuklis, 5 variantas
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

void tikrinimofunkcija(float skaiciai[], int i, float suma1, float suma2)
{
	if (skaiciai[i] > 0)
	{
		suma1 += skaiciai[i];
		cout << "Teigiamu absoliutine verte: " << abs(suma1) << endl;
	}
	if (skaiciai[i] < 0)
	{
		suma2 += skaiciai[i];
		cout << "Neigiamu absoliutine verte: " << abs(suma2) << endl;
	}
}

class darbuotojuklase
{
private:
	int ID;
	int isdirbta;
	float atlygis;
public:
	void generuotiID(int Iden)
	{
		ID = Iden;
	}
	void generuotidienas(int dienos)
	{
		isdirbta = dienos;
	}
	void generuotiatlygi(float alga)
	{
		atlygis = alga;
	}
	int nuskaitykID()
	{
		return ID;
	}
	int nuskaitykdienas()
	{
		return isdirbta;
	}
	float nuskaitykatlygi()
	{
		return atlygis;
	}
};
void algostikrinimas(darbuotojuklase darbuotojas[], int darbuotojusk)
{
	for (int p = 1; p <= darbuotojusk; p++)
	{
		if (darbuotojas[p].nuskaitykdienas() >= 15 && darbuotojas[p].nuskaitykatlygi() * 8 * darbuotojas[p].nuskaitykdienas() > 700)
			cout << "Darbuotojas " << darbuotojas[p].nuskaitykID() << " dirbo po 8 valandas " << darbuotojas[p].nuskaitykdienas() << " dienu ir uzdirbo " << darbuotojas[p].nuskaitykatlygi()*8*darbuotojas[p].nuskaitykdienas() << endl;
	}
}

int main()
{
	//1 uzduotis
	int i;
	int dydis = 0;
	float suma1 = 0, suma2 = 0;
	float* skaiciai = new float[dydis];
	cout << "Iveskite elementu kieki masyve: "; cin >> dydis;
	for (i = 0; i < dydis; i++)
	{
		skaiciai[i] = (rand() % 4 + 0.14) - (rand() % 4 + 0.14) / 2;
		cout << skaiciai[i] << endl;
	}
	tikrinimofunkcija(skaiciai, i, suma1, suma2);
	


	//2 uzduotis
	darbuotojuklase darbuotojas[8];
	int darbuotojusk = 7;
	
	for (int n = 1; n < darbuotojusk; n++)
	{
		int ID = rand() % 1001 + 1999;
		int isdirbta = (rand() + 1) % 23;
		float temp = rand();
		float atlygis = 0;
		if (temp >= 3.5 && temp <= 9.5)
			atlygis = temp;
		darbuotojas[n].generuotiID(ID);
		darbuotojas[n].generuotidienas(isdirbta);
		darbuotojas[n].generuotiatlygi(atlygis);
		cout << darbuotojas[n].nuskaitykID() << endl;
		cout << darbuotojas[n].nuskaitykdienas() << endl;
		cout << darbuotojas[n].nuskaitykatlygi() << endl;
	}
	algostikrinimas(darbuotojas, darbuotojusk);
	return 0;
}