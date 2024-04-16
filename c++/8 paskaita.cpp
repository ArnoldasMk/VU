#include <iostream>

// int main() 
// {
//     int a = 1, b = 3, c = 2;

//     int *pa = &a, *pb = &b, *pc = &c;

//     int temp = *pa;
//     *pa = *pb;
//     *pb = *pc;
//     *pc = temp;

//     std::cout << "a = " << a << "  b = " << b << "  c = " << c << std::endl;
// }


void funkcija(int* masyvas, int dydis, int& min, int& max) {
    min = max = masyvas[0];
    for (int i = 1; i < dydis; i++) {
        if (masyvas[i] < min) min = masyvas[i];
        if (masyvas[i] > max) max = masyvas[i];
    }
}

int main() {
    int n;
    std::cout << "1-20";
    std::cin >> n;
    int min, max;
    int* masyvas = new int[n];

    for (int i = 0; i < n; i++) {
        masyvas[i] = rand() % 201 - 100;
    }

    funkcija(masyvas, n, min, max);
    std::cout << "Maziausia: " << min << "\n" << "Didziausia: " << max << std::endl;

}


// int funkcija(int* masyvas, int dydis) {
//     int n = 0;
//     for (int i = 0; i < dydis; i++) {
//         if (masyvas[i] > 0) n++;
//     }   
//     return n;
// }

// int main() {

//     int n;
//     std::cout << "1-20";
//     std::cin >> n;

//     int* masyvas = new int[n];

//     for (int i = 0; i < n; i++) {
//         masyvas[i] = rand() % 201 - 100; 
//     }

//     int teigiami_n = funkcija(masyvas, n); 

//     int* teigiami = new int[teigiami_n]; 

//     for (int i = 0, j = 0; i < n; i++) {
//         if (masyvas[i] > 0) {
//             teigiami[j++] = masyvas[i];
//         }
//     }

//     std::cout << "Teigiami" << std::endl;
//     for (int i = 0; i < teigiami_n; i++) {
//         std::cout << teigiami[i] << " ";
//     }
// }