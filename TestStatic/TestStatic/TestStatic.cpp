#include <iostream>
#include "time.h"
#include "stdlib.h"
#include "SLib.h"
using namespace std;

int main()
{
    int* A, n;
    cout << "input n\nn=";
    cin >> n;
    A = new int[n];
    srand((unsigned)time(NULL));
    cout << "\nInitial array: ";
    for (int i = 0; i < n; i++)
    {
        *(A + i) = rand() % 100 - 50;
        cout <<" "<< *(A + i);
    }
    Func(A, n);
    cout << "\nEdited array: ";
    for (int i = 0; i < n; i++)
    {
        cout << " " << *(A + i);
    }
    delete[]A;
    return 0;
}
