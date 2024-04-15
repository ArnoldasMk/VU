#include <iostream>

// int main() 
// {
//     int a = 1, b = 3, c = 2;

//     int *pa = &a, *pb = &b, *pc = &c;

//     int temp = *pa;
//     *pa = *pb;
//     *pb = *pc;
//     *pc = temp;

//     std::cout << "Po sukeitimo:\na = " << a << "\nb = " << b << "\nc = " << c << std::endl;
// }


// void funkcija(int* arr, int size, int& min, int& max) {
//     min = max = arr[0];
//     for (int i = 1; i < size; i++) {
//         if (arr[i] < min) min = arr[i];
//         if (arr[i] > max) max = arr[i];
//     }
// }

// int main() {

//     int n;
//     std::cout << "1-20";
//     std::cin >> n;
//     int min, max;
//     int* arr = new int[n];

//     for (int i = 0; i < n; i++) {
//         arr[i] = rand() % 201 - 100;
//     }

//     int min, max;
//     funkcija(arr, n, min, max);
//     std::cout << "Maziausia verte: " << min << "\nDidziausia verte: " << max << std::endl;

// }


int funkcija(int* arr, int size) {
    int n = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) n++;
    }   
    return n;
}

int main() {

    int n;
    std::cout << "1-20";
    std::cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 201 - 100; 
    }

    int teigiami_n = funkcija(arr, n); 

    int* teigiami = new int[teigiami_n]; 

    for (int i = 0, j = 0; i < n; i++) {
        if (arr[i] > 0) {
            teigiami[j++] = arr[i];
        }
    }

    std::cout << "Teigiami" << std::endl;
    for (int i = 0; i < teigiami_n; i++) {
        std::cout << teigiami[i] << " ";
    }
}