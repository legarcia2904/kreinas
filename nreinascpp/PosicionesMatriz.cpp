#include "stdafx.h"
#include <new>
#include "PosicionesMatriz.h"

int*& PosicionesMatriz::indices(int from, int to) {
	int longitud = to - from;
	int* vector = new int[longitud];

	for (int i = 0; i < longitud; i++)
		vector[i] = from++;

	return vector;
}