#include "stdafx.h"
#include <iostream>
#include <new>
#include <fstream>
#include <ctime>
#include "Poblacion.h"
using namespace std;

const int longitudPoblacion = 100;


int main() {
	fstream file;
	file.open("resultados.txt", ios::out);
	if (!file) {
		cout << "Error, no se ha podido crear el fichero" << endl;
		return 0;
	}
	cout << "Ingrese el numero de Reinas (8, 16, 32, 64 o 128): "<< "\n";
	int geneNum;
	cin >> geneNum;
	if (geneNum == 8 || geneNum == 16 || geneNum == 32 || geneNum == 64 || geneNum == 128)
	{
		geneNum = geneNum;
	}
	else
	{
		geneNum = 32;
	}
	const int cantGeneraciones = geneNum;
	unsigned tiempoInicial, tiempoFinal;
	tiempoInicial = clock();

	Poblacion* poblacion = new Poblacion(longitudPoblacion, cantGeneraciones);

	int contadorGeneraciones = 0;
	while (poblacion->getMejor()->getAptitud() != 0 && contadorGeneraciones < 10000) {
		poblacion->ejecutarGeneracion();
		contadorGeneraciones++;
		cout << poblacion->getMejor()->getAptitud() << endl;
		file << poblacion->obtenerAptitudPromedio() << "\n";
	}
	cout << endl;
	file << "\n";
	tiempoFinal = clock();
	double tiempoEjecucion = (double(tiempoFinal - tiempoInicial) / CLOCKS_PER_SEC);

	cout << "Iteraciones: " << contadorGeneraciones << "\n\n";
	cout << poblacion->getMejor() << endl;
	cout << "Tiempo de Ejecucion: " << tiempoEjecucion << endl;

	file << "\n Generacion: " << contadorGeneraciones << "\n";
	file << poblacion->getMejor() << "\n";
	file << "Tiempo de Ejecucion: " << tiempoEjecucion << "\n";

	file.close();

	delete poblacion;
	getchar();
	getchar();
	return 0;
}