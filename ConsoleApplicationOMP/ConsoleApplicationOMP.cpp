// ConsoleApplicationOMP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#ifdef _OPENMP
#include <omp.h>
#else
#define omp_get_thread_num() 0
#endif

#define N 1000
#define chunk 100
#define mostrar 10

using namespace std;

void imprimeArreglo(float* d);

int main()
{
    float arreglo_a[N], arreglo_b[N], arreglo_c[N];
    int pedazos = chunk, i;

    for (i = 0; i < N; i++) {
        arreglo_a[i] = i * 10;
        arreglo_b[i] = (i + 3) * 3.7;
    }

    #pragma omp parallel for \
    shared(arreglo_a,arreglo_b,arreglo_c,pedazos) private(i) \
    schedule(static,pedazos)

    for (i = 0; i < N; i++) {
        arreglo_c[i] = arreglo_a[i] + arreglo_b[i];
    }
 

    cout << "Primeros " << mostrar << "elementos del arreglo a: " << endl;
    imprimeArreglo(arreglo_a);
    cout << "Primeros " << mostrar << "elementos del arreglo b: " << endl;
    imprimeArreglo(arreglo_b);
    cout << "Primeros " << mostrar << "elementos del arreglo c: " << endl;
    imprimeArreglo(arreglo_c);
    
    return 0;
}

void imprimeArreglo(float* d) {
    for (int x = 0; x < mostrar; x++) {
        cout << d[x] << " - " << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
