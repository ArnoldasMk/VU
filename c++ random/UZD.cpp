#include <cmath>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

//! * 2.1
//TODO :  Apskaičiuokite reiškinio cos(x)+(1x)4 vertes keletui pasirinktų x verčių.Rezultatus į ekraną išveskite tokiu pavidalu :
//TODO :  Argumentas | Rezultatas
// ?int main()
// ?{
// ?    double rez1;
// ?    double rez2;
// ?    double rez;
// ?    double x;
// ?    for (int i = 0; i < 15; i++)
// ?    {
// ?        x++;
// ?        rez1 = cos(x);
// ?        rez2 = pow((1/x), 4);
// ?        rez = rez1+rez2;
// ?        std::cout << "Argumentas  " << "  Argumentas " << "| " << i << " |" << "      Rezultatas" << "| " << rez << " \n";
// ?    }
// ?}
//! * 2.2
//TODO : Apskaičiuokite reiškinio 23sin(x)+cos(x)√ reikšmes keletui klaviatūra įvedamų x verčių intervale nuo 0 iki π2
// ?int main()
// ?{
// ?double rez1;
// ?double rez2;
// ?double rez;
// ?double x=0;
// ?for (int i = 0; i < 90; i++)
// ?{
// ?    x=x+1;
// ?    if (i == 0)
// ?    {
// ?        x = 0;
// ?    }
// ?    rez1=sin(x);
// ?    rez2=cos(x);
// ?    rez=rez1+rez2;
// ?    rez = sqrt(rez);
// ?    cout << x << "  " << rez*2/3 << "\n";
// ?}
//! * 2.3
//TODO : Patobulinkite 2 užduotį pridėdami klaviatūra įvedamos x vertės patikrą naudodami sąlygos operatorius (?) taip: 
//TODO : jei x<0, priskirkite jam π2 jei x>π2 priskirkite jam nulį.
// ?int main()
// ?{
// ?    double rez1;
// ?    double rez2;
// ?    double rez;
// ?    double x;
// ?    cin >> x;
// ?    rez1 = sin(x);
// ?    rez2 = cos(x);
// ?    rez = rez1 + rez2;
// ?    rez = sqrt(rez)* 2 / 3;
// ?    cout << rez << "\n";
// ?    double galutinis = (rez > M_PI/2) ? 0 : M_PI / 2;
// ?    cout << galutinis;
// ?}
//! * 2.4
//TODO : Apskaičiuokite reiškinio: y = ax2+b, kur a = sin(x) ir b = cos(x) vertes keletui pasirinktų argumento x verčių.
// ?int main()
// ?{
// ?    double x = 0;
// ?    double a = sin(x);
// ?    double b = cos(x);
// ?    double y = a * pow(x, 2) + b;
// ?    for (int i = 0; i < 90; i++)
// ?    {
// ?        x++;
// ?        a = sin(x);
// ?        b = cos(x);
// ?        y = a * pow(x, 2) + b;
// ?        cout << x << "  " << y << "\n";
// ?    }
// ?}
//! * 2.5
//TODO :   Apskaičiuokite stačiojo trikampio perimetrą, kai viena jo statinių yra x, o įstrižainė yra y metrų ilgio. x ir y vertes įveskite klaviatūra.
// ?int main()
// ?{
// ?    double x;
// ?    double y;
// ?    double z;
// ?    cin >> x;
// ?    cin >> y;
// ?    z = sqrt(pow(x, 2) + pow(y, 2));
// ?    cout << "Perimetras: " << x + y + z << "\n";
// ?}
//! * 2.6
//TODO : Apskaičiuokite trapecijos, kurios pagrindai yra a ir b, o aukštinė - c bei įvairiakraščio trikampio, kurio kraštinės yra a, b, ir c plotų santykį. a, b, ir c vertes įveskite klaviatūra.
// ?int main()
// ?{
// ?    int a, b, c;
// ?    int p;
// ?    double Trap, Trik;
// ?    std::cin >> a;
// ?    std::cin >> b;
// ?    std::cin >> c;
// ?    if (a + b < c || a + c < b || b + c < a)
// ?    {
// ?        std::cout << "Trikampio nesudaryti negalima" << "\n";
// ?        return 0;
// ?    }
// ?    if (a < 0 || b < 0 || c < 0)
// ?    {
// ?        std::cout << "Ivesti neigiami skaiciai" << "\n";
// ?        return 0;
// ?    }
// ?    Trap = (a + b) / 2 * c;
// ?    p = (a + b + c) / 2;
// ?    Trik = sqrt(p * (p - a) * (p - b) * (p - c));
// ?    std::cout << "Trikampio plotas: " << Trik << "\n";
// ?    std::cout << "Trapecijos plotas: " << Trap << "\n";
// ?    std::cout << "Santykis " << Trap/Trik << "\n";
// ?}
//! * 3.1
//TODO : Parašykite programą, kuri nustatytų, kuriame Dekarto koordinačių sistemos ketvirtyje yra duotas taškas, kurio koordinatės yra (x,y). 
//TODO : Sveikųjų skaičių x ir y vertes įveskite klaviatūra, 0 traktuokite pirmo ketvirčio skaičiumi. Pasistenkite programoje panaudoti kuo mažiau sąlygos operatorių.
// ?int main()
// ?{
// ?    int x = 0, y = 0;
// ?    std::cin >> x;
// ?    std::cin >> y;

// ?    if (x > 0 && y > 0)
// ?    {
// ?        std::cout << "1 ketvirtis";
// ?    }
// ?    else if (x < 0 && y > 0)
// ?    {
// ?        std::cout << "2 ketvirtis";
// ?    }
// ?    else if (x > 0 && y < 0)
// ?    {
// ?        std::cout << "3 ketvirtis";
// ?    }
// ?    else if (x < 0 && y < 0)
// ?    {
// ?        std::cout << "4 ketvirtis";
// ?    }
// ?    else if (x < 0 && y < 0)
// ?    {
// ?        std::cout << "0;0";
// ?    }
// ?}
//! * 3.2
//TODO : Pardavėjas gauna 30 proc. pelno nuo parduotų prekių, jei parduoda jų daugiau, nei už 10000 Eur per mėnesį. Jei parduoda mažiau - gauna 25 proc. 
//TODO : Apskaičiuokite, kokia pinigų suma lieka pardavėjui, jei nuo gauto pelno jis turi sumokėti 15 proc. pelno mokestį, jei jo gauta suma viršija 5000 Eur arba prekės vertė didesnė, nei 500 Eur. Prekės vertę ir parduotų prekių kiekį įveskite klaviatūra.
// ?int main()
// ?{
// ?    int parduota_verte, parduota_n, parduota_viso;

// ?    std::cin >> parduota_verte;
// ?    std::cin >> parduota_n;

// ?    parduota_viso = parduota_verte * parduota_n;
// ?    std::cout << "Parduota viso PRADZIOJE:  " << parduota_viso << "\n";
// ?    if (parduota_viso > 10000)
// ?    {
// ?        parduota_viso = parduota_viso * 0.3;
// ?    }
// ?    else
// ?    {
// ?        parduota_viso = parduota_viso * 0.25;
// ?    }
// ?    if (parduota_viso > 5000 || parduota_verte > 500)
// ?    {
// ?        parduota_viso = parduota_viso - parduota_viso * 0.15;
// ?    }
// ?    std::cout << "Parduota viso Pabaigoje:  " << parduota_viso << "\n";
// ?}
//! * 3.3
//TODO : Traukinys iš geležinkelio stoties pajudėjo v valandų ir m minučių. Po i minučių jis sustojo kitoje geležinkelio stotyje. Parašykite programą, kuri apskaičiuotų bei išvestų į ekraną, kiek tuomet buvo laiko (v : m formatu). 
//TODO : Išvykimo valanda v, minutės m bei važiavimo trukmė i  įvedami klaviatūra bei išsaugomi sveikojo tipo kintamuosiuose. Išspręskite šią užduotį nenaudodami ciklinių skaičiavimų - pasinaudokite sveikųjų skaičių dalybos savybėmis.
// ?int main()
// ?{
// ?    int minutes, valandos, i, n;
// ?    std::cout << "Valandos" << "\n";
// ?    std::cin >> valandos;
// ?    std::cout << "Minutes"<< "\n";
// ?    std::cin >> minutes;
// ?    std::cout << "i"<< "\n";
// ?    std::cin >> i;

// ?    minutes = minutes + i;
// ?    if (minutes >= 60)
// ?    {
// ?        n = i / 60;
// ?        valandos = valandos + 1*n;
// ?        minutes = minutes - 60 * n;
// ?    }
// ?    if (valandos >= 24)
// ?    {
// ?        n = i / 1440;
// ?        valandos = valandos - 24 * n;
// ?    }
// ?    std::cout << valandos << " H" << minutes << " min" << " Trukme: " << i;
// ?}
//! * 3.4
//TODO :  Parašykite programą, kuri iš klaviatūra įvestų 4 taškų koordinačių (x,y) išrinktų tašką su maksimalia ordinate. 
//TODO :  Apskaičiuokite šio taško atstumą iki koordinačių pradžios (taškas (0,0)) bei apskritimo, kuris eina per šį tašką o centras yra koordinačių pradžioje, perimetrą.
// ?4 uzduotis
// ?int main()
// ?{
// ?    int x[4], y[4];
// ?    int iks, yk;
// ?    double atstumas;
// ?    for (int i = 0; i < 4; i++)
// ?    {
// ?        std::cin >> y[i];
// ?        std::cin >> x[i];
// ?        if (y[i] > yk)
// ?        {
// ?            yk = y[i];
// ?            iks = x[i];
// ?        }
// ?    }
// ?    atstumas = sqrt(pow(iks, 2) + pow(yk, 2));
// ?    std::cout << "Atstumas iki pradzios: " << atstumas << "\n";
// ?    std::cout << "Apskritimo perimetras: " << 2 * M_PI * atstumas << "\n";
// ?}
//! * 3.5
//TODO :  Parašykite programą, kuri sukeistų triženklio sveikojo skaičiaus skaitmenis tokia tvarka:

//TODO    a) 1 su 3, jei 2 skaitmuo didesnis už 5 (pvz. 365->563).
//TODO    b) 1 su 2, jei 2 skaitmuo mažesnis už 5 (pvz. 315->135).
//TODO    c) 2 su 3, jei 2 skaitmuo lygus 5 (pvz. 356->365).
// ?int main()
// ?{
// ?    int skaicius;
// ?    int p;
// ?    int a;
// ?    int t;
// ?    std::cin >> skaicius;
// ?    p = skaicius / 100;
// ?    a = (skaicius - p * 100) / 10;
// ?    t = skaicius - p * 100 - a * 10;
// ?    if (a > 5)
// ?    {
// ?        skaicius = 100 * t + a * 10 + p;
// ?    }
// ?    if (a < 5)
// ?    {
// ?        skaicius = 100 * a + p * 10 + t;
// ?    }
// ?    if (a == 5)
// ?    {
// ?        skaicius = 100 * p + t * 10 + a;
// ?    }
// ?    std::cout << skaicius << "\n";
// ?}

//! * 3.6
//TODO : Parašykite programą, kuri palygintų tris klaviatūra įvestus dviženklius skaičius ir išrinktų didžiausią bei mažiausią iš jų.
// ?6 uzduotis
// ?int main()
// ?{
// ?    int input1, input2, input3;
// ?    std::cin >> input1;
// ?    std::cin >> input2;
// ?    std::cin >> input3;
// ?    if (input1 > input2 && input1 > input3)
// ?    {
// ?        std::cout << "Didziausias: " << input1 << "\n";
// ?    }
// ?    else if (input2 > input1 && input2 > input3)
// ?    {
// ?        std::cout << "Didziausias: " << input2 << "\n";
// ?    }
// ?    else if (input3 > input1 && input3 > input2)
// ?    {
// ?        std::cout << "Didziausias: " << input3 << "\n";
// ?    }
// ?    else
// ?    {
// ?        std::cout << "Lygus" << "\n";
// ?    }
// ?    if (input1 < input2 && input1 < input3)
// ?    {
// ?        std::cout << "Maziausias: " << input1 << "\n";
// ?    }
// ?    else if (input2 < input1 && input2 < input3)
// ?    {
// ?        std::cout << "Maziausias: " << input2 << "\n";
// ?    }
// ?    else if (input3 < input1 && input3 < input2)
// ?    {
// ?        std::cout << "Maziausias: " << input3 << "\n";
// ?    }
// ?}
//! * 4.1
//TODO : Parašykite ciklą, kuris būtų vykdomas tiek kartų, kiek jums yra metų. Į konsolės ekraną išveskite informaciją apie kiekvieną lyginę ciklo iteraciją.
// ?int main()
// ?{
// ?    int i;
// ?    std::cin >> i;
// ?    while (i > 0)
// ?    {
// ?        if (i % 2 == 0)
// ?        {
// ?            std::cout << i << "\n";
// ?        }
// ?        i--;
// ?    }
// ?}
//! * 4.2
//TODO : Parašykite programą, kuri skaičiuotų ir išvestų į konsolės ekraną klaviatūra įvedamo skaičiaus kvadratinės šaknies vertę tol, kol bus įvestas neigiamas skaičius. 
//TODO : Taip pat suskaičiuokite ir išveskite į konsolės ekraną, kiek kartų vartotojas įvedė skaičių.
// ?int main()
// ?{
// ?    int i;
// ?    float n = 1;
// ?    int sum = 1;
// ?    while (i > 0)
// ?    {
// ?        std::cin >> i;
// ?        std::cout << sum++ << "  " << sqrt(i) << "\n";
// ?    }
// ?}
//! * 4.3
//TODO : Apskaičiuokite sumą: ∑ni=112i kai n = 10 ir 20. Į ekraną išveskite tiek gautas sumų vertes, tiek ir jų skirtumą,
// ?int main()
// ?{
// ?    float sum1 = 0;
// ?    float sum2 = 0;
// ?    int n1 = 3;
// ?    int n2 = 3;
// ?    while (n1 > 0)
// ?    {
// ?        sum1 = sum1 + (1 / (pow(2, n1)));
// ?        std::cout << "n1 " << sum1 << "\n";
// ?        n1--;
// ?    }
// ?    while (n2 > 0)
// ?    {
// ?        sum2 = sum2 + (1 / (pow(2, n2)));
// ?        std::cout << "n2 " << sum2 << "\n";
// ?        n2--;
// ?    }
// ?    std::cout << "sudetis " << sum1 + sum2 << "\n";
// ?    std::cout << "atimtis " << sum1 - sum2;
// ?}
//! * 4.4
//TODO :  Parašykte ciklą, kuris vykdytų dvigubai daugiau iteracijų, nei skaičius, kurį įvedė vartotojas konsolės ekrane.
// ?int main()
// ?{
// ?    int i = 0;
// ?    std::cin >> i;
// ?    i = i * 2;
// ?    while (i > 0)
// ?    {
// ?            std::cout << i << "\n";
// ?        i--;
// ?    }
// ?}
//! * 4.5
//TODO : Parašykite programą, kuri susumuotų klaviatūra įvedamų skaičių kvadratinių šaknų vertes. Sumavimas turi vykti cikle, o skaičiai turi būti iš intervalo 1-10.
//TODO : Ciklo iteracijų skaičius turi būti įvedamas klaviatūra prieš pradedant vesti skaičius.
//TODO : Jei sumavimo metu įvedamas skaičius, nepatenkantis į intervalą, neįtraukite jo į bendrą sumą.
// ?int main()
// ?{
// ?    int i = 0;
// ?    double suma = 0;
// ?    while (true)
// ?    {
// ?        std::cin >> i;
// ?        if (i <= 0 || i > 10)
// ?        {
// ?            std::cout << "Ivestas netinkamas skaicius\n";
// ?        }
// ?        else
// ?        {
// ?            suma = suma + sqrt(i);
// ?            std::cout << "suma " << suma << "\n";
// ?        }
// ?    }
// ?}
//! * 4.6
//TODO : Apskaičiuokite reiškinio: ∏ni=1(x−i)n! reikšmę, kai n yra sveikasis teigiamas, o x - realusis skaičiai, įvedami klaviatūra.
// ?double Funkcijos_sandauga(int n, int x)
// ?{
// ?    int sandauga = 1, i = 1;
// ?    while (i-1 < n)
// ?    {
// ?        sandauga = sandauga * (x - i);
// ?        i++;
// ?    }
// ?    std::cout << sandauga << "\n";
// ?    return sandauga;
// ?}
// ?int factorialas(int n)
// ?{
// ?    int daugyba = 1, i = 1;
// ?    while (i-1 < n)
// ?    {
// ?        daugyba = daugyba * i;
// ?        i++;
// ?    }
// ?    std::cout << daugyba << "\n";
// ?    return daugyba;
// ?}
// ?int main()
// ?{
// ?    int x = 0;
// ?    int n = 0;
// ?    std::cin >> n;
// ?    std::cin >> x;
// ?    std::cout << Funkcijos_sandauga(n, x) / factorialas(n) << "\n";
// ?}
//! * 5.1
// TODO : Apskaičiuokite sekos  an , n = 1, 2, 3, …  ribą tikslumu e = 0.00001, kur: an=nn2+1√+n2−1√
// TODO : Ieškoma riba bus  an , kai dviejų gretimų sekos narių modulio skirtumas  | an - an-1 |  taps mažesnis už pasirinktą tikslumą e . 
// TODO : Išveskite į ekraną apskaičiuotą ribą ir prie kokio  n  ji buvo gauta.
// ?double function(int n)
// ?{
// ?    return n / (sqrt(pow(n, 2) + 1) + sqrt(pow(n, 2) - 1));
// ?}

// ?int main()
// ?{
// ?    double paklaida = 0.1;
// ?    int n = 1;
// ?    int ok = 0;
// ?    double An = function(n);
// ?    double An1 = 0;
// ?    for (int i = 1; ok == 0; i++)
// ?    {
// ?        while (std::abs(An - An1) >= paklaida)
// ?        {
// ?            n++;
// ?            An1 = An;
// ?            An = function(n);
// ?        }
// ?        std::cout << "Sekos riba: " << An << ", kai n = " << i << std::endl;
// ?        ok = 1;
// ?    }
// ?    return 0;
// ?}

//! * 5.2
// ?double function(double a, double xn)
// ?{
// ?    return 0.4 * xn + a / (5 * std::pow(xn, 4));
// ?}
// ?double check(double a)
// ?{
// ?    double x0, skirtumas;
// ?    if (a <= 1)
// ?    {
// ?        x0 = 0.95;
// ?    }
// ?    else if (a > 1 && a <= 25)
// ?    {
// ?        x0 = a/5;
// ?    }
// ?    else if (a > 25)
// ?    {
// ?        x0 = a/25;
// ?    }
// ?    return x0;
// ?}
// ?double riba(double a, double e)
// ?{
// ?    double xn, xn1;
// ?    xn = check(a);
// ?    xn1 = function(a, xn);    
// ?    while (std::abs(xn1 - xn) >= e)
// ?    {
// ?        xn = xn1;
// ?        xn1 = function(a, xn);
// ?    }
// ?    return xn1;
// ?}

//! * 5.3
// ?long long factorialas(int n) {
// ?    long long daugyba = 1;
// ?    for (int i = 1; i <= n; ++i) {
// ?        daugyba *= i;
// ?    }
// ?    return daugyba;
// ?}
// ?double function(int n, double x)
// ?{
// ?    return rand() % (int)(2 * M_PI * 100) / 100.0 - M_PI;
// ?}
// ?double riba(double x, double e, double xn)
// ?{
// ?    double xn1;
// ?    xn1 = function(x, xn);    
// ?    while (std::abs(xn1 - xn) >= e)
// ?    {
// ?        xn = xn1;
// ?        xn1 = function(x, xn);
// ?    }
// ?    return xn1;
// ?}
// ?double sum(double x, double e)
// ?{
// ?    double suma = 0;
// ?    int n = 0;
// ?    while (std::abs(function(n, x)) >= e)
// ?    {
// ?        suma = suma + function(n, x);
// ?        ++n;
// ?    }
// ?    return suma+1;
// ?}
// ?int main()
// ?{
// ?    double x0 = 1;
// ?    double e = 0.00001;
// ?    double x = 90;
// ?    // ?std::cin >> x;
// ?    // ?std::cin >> e;
// ?    std::cout << sum(x, e);
// ?}

//! * 5.4

//! * 5.5

//! * 5.6
