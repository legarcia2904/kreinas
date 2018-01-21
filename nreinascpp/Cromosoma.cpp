#include "stdafx.h"
#include <iostream>
#include <new>
#include <string>
#include <cmath>
#include <random>
#include "PosicionesMatriz.h"
#include "Cromosoma.h"

Cromosoma::Cromosoma(const int& longitud) {
	this->longitud = longitud;
	informacion = new int[this->longitud];
	for (int i = 0; i < longitud; i++)
	{
		informacion[i] = 0;
	}
}

Cromosoma::Cromosoma(int* informacion, const int& size, const int& aptitud) {
	this->longitud = size;
	this->informacion = new int[this->longitud];
	this->aptitud = aptitud;

	for (int i = 0; i < this->longitud; i++)
		this->informacion[i] = informacion[i];
}

Cromosoma::~Cromosoma() {
	delete[] informacion;
}

void Cromosoma::intercambiar() {
	informacion = PosicionesMatriz::indices(0, longitud);
	Cromosoma::barajar(informacion, longitud);
}

const int& Cromosoma::getAptitud() const {
	return aptitud;
}

const int& Cromosoma::getLongitud() const {
	return longitud;
}

int Cromosoma::getGen(const int& index) const {
	return informacion[index];
}

void Cromosoma::setAptitud(const int aptitud) {
	this->aptitud = aptitud;
}

void Cromosoma::setGen(int index, int gene) {
	informacion[index] = gene;
}

int Cromosoma::compararCon(const Cromosoma* obj) const {
	if (aptitud > obj->getAptitud()) return 1;
	else if (obj->getAptitud() == aptitud) return 0;
	else return -1;
}

void Cromosoma::evaluar() {
	aptitud = 0;

	for (int x = 0; x < longitud - 1; x++) {
		for (int y = x + 1; y < longitud; y++) {
			int i = informacion[x];
			int j = x + 1;

			int k = informacion[y];
			int l = y + 1;

			if ((i - j == k - l || i + j == k + l)) aptitud++;
		}
	}
}

Cromosoma* Cromosoma::clonarCromosoma() const {
	Cromosoma* copy = new Cromosoma(informacion, longitud, aptitud);
	return copy;
}

int* Cromosoma::getInformacion() const {
	return informacion;
}

void Cromosoma::barajar(int*& array, const int size) {
	std::random_device rd;
	std::mt19937 gen(rd());

	for (int i = size - 1; i > 0; i--) {
		std::uniform_int_distribution<unsigned int> random(0, i);

		int index = random(gen);
		int temp = array[index];
		array[index] = array[i];
		array[i] = temp;
	}

	incrementar(array, size, 1);
}

void Cromosoma::incrementar(int*& array, const int size, const int& x) {
	for (int i = 0; i < size; i++)
		array[i] += x;
}

std::ostream& operator<<(std::ostream& salida, const Cromosoma* cromosoma) {
	std::string str("Aptitud: ");
	str.append(std::to_string(cromosoma->getAptitud()) + "\n");

	str.append("Genotipo: [");
	for (int i = 0; i < cromosoma->longitud; i++) {
		str.append(std::to_string(cromosoma->informacion[i]));
		if (i != cromosoma->longitud - 1) str.append(", ");
	}
	str.append("]");
	salida << str;
	return salida;
}

