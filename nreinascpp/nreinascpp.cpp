#include "stdafx.h"
#include <iostream>
#include <new>
#include <fstream>
#include "Poblacion.h"
using namespace std;

const int longitudPoblacion = 100;
const int geneNum = 32;

int main() {
	fstream file;
	file.open("resultados.txt", ios::out);
	if (!file) {
		cout << "Error, no se ha podido crear el fichero" << endl;
		return 0;
	}
	Poblacion* poblacion = new Poblacion(longitudPoblacion, geneNum);

	int contadorGeneraciones = 0;
	while (poblacion->getMejor()->getAptitud() != 0 && contadorGeneraciones < 10000) {
		poblacion->ejecutarGeneracion();
		contadorGeneraciones++;
		cout << poblacion->getMejor()->getAptitud() << " ";
		file << poblacion->obtenerAptitudPromedio() << " ";
	}
	cout << endl;
	file << "\n";
	cout << "Iteraciones: " << contadorGeneraciones << "\n\n";
	cout << poblacion->getMejor() << endl;
	file << "\n Generacion: " << contadorGeneraciones << "\n";
	file << poblacion->getMejor() << "\n";

	file.close();

	delete poblacion;
	getchar();
	return 0;
}