#include "Windows.h"
#include <iostream>
#include "time.h"
#include "stdlib.h"
int main()
{
    int* A, n;
    std::cout << "input n\n=";
    std::cin >> n;
    A = new int[n];
    srand((unsigned)time(NULL));
    std::cout << "Initial: ";
    for (int i = 0; i < n; i++)
    {
        *(A + i) = rand() % 100 - 50;
        std::cout << *(A + i) << " ";
    }

    HINSTANCE hDLL = LoadLibrary(L"C:/Users/Hp/Desktop/OOP/TestDLL/TestDLL/Debug/Dll.dll");

    if (hDLL != NULL)
    {
        void (*funk)(int*, int);
        funk = (void (*)(int*, int))(GetProcAddress(hDLL, "Func"));
        if (funk != NULL)
        {
            funk(A, n);
            std::cout << std::endl<<"Sorted: ";
            for (int i = 0; i < n; i++)
            {
                std::cout << *(A + i) << " ";
            }
        }
        else
        {
            std::cout << "impossible to load function";
        }
        FreeLibrary(hDLL);
    }
    else
    {
        std::cout << "impossible to load library ";
    }
    delete[]A;
    return 0;
}

