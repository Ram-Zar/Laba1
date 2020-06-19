#include "pch.h"
#include "framework.h"
#include "SLib.h"
#include <stdexcept>

void Func(int* A, int n)
{
	for (int i = n-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (*(A + j) > * (A + j + 1))
			{
				int b = *(A + j);
				*(A + j) = *(A + j + 1);
				*(A + j + 1) = b;
			}
		}
	}
}