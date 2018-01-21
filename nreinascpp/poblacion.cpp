#include "stdafx.h"
#include <new>
#include <vector>
#include <algorithm>
#include "Poblacion.h"
#include "SeleccionIndividuos.h"
#include "Cruzamiento.h"
#include "HijosMutacion.h"


Poblacion::Poblacion(const int longitudPoblacion, const int longitudCromosoma) {
	this->longitudPoblacion = longitudPoblacion;
	poblacion.resize(longitudPoblacion);
	generarPoblacionAleatoria(longitudCromosoma);
}

Poblacion::~Poblacion() {
	for (std::vector<Cromosoma*>::iterator it = poblacion.begin(); it != poblacion.end(); ++it)
		delete (*it);
	poblacion.clear();
}

void Poblacion::generarPoblacionAleatoria(const int& longitudCromosoma) {
	for (int i = 0; i < longitudPoblacion; i++) {
		poblacion[i] = new Cromosoma(longitudCromosoma);
		poblacion[i]->intercambiar();
		poblacion[i]->evaluar();
	}
	mejorCromosoma = poblacion[0];

}

Cromosoma* Poblacion::getCromosoma(const int& index) const {
	return poblacion.at(index);
}

Cromosoma* Poblacion::getMejor() const {
	return mejorCromosoma;
}

const int& Poblacion::getLongitud() const {
	return longitudPoblacion;
}

void Poblacion::ordenarPorAptitud() {
	std::sort(poblacion.begin(), poblacion.end(), [](const Cromosoma* c1, const Cromosoma* c2) {
		return c1->getAptitud() > c2->getAptitud();
	});
}

void Poblacion::ejecutarGeneracion() {
	SeleccionIndividuos seleccionIndividuos(this);
	Cruzamiento cruzamiento(seleccionIndividuos.getPadreSeleccionado1(), seleccionIndividuos.getPadreSeleccionado2());
	HijosMutacion mutacion(cruzamiento.getHijo1(), cruzamiento.getHijo2());

	ordenarPorAptitud();

	if (cruzamiento.getHijo1()->compararCon(cruzamiento.getHijo2()) == 1)
		insertarHijo(insertarHijo(0, cruzamiento.getHijo1()), cruzamiento.getHijo2());
	else
		insertarHijo(insertarHijo(0, cruzamiento.getHijo2()), cruzamiento.getHijo1());

	ordenarPorAptitud();
	mejorCromosoma = poblacion[longitudPoblacion - 1];
}

int Poblacion::insertarHijo(int inicio, Cromosoma* hijo) {
	int i;

	for (i = inicio; i < longitudPoblacion; i++) {
		if (hijo->getAptitud() < poblacion[i]->getAptitud()) {

			for (int j = 0; j < poblacion[i]->getLongitud(); j++)
				poblacion[i]->setGen(j, hijo->getGen(j));

			poblacion[i]->setAptitud(hijo->getAptitud());
			return i;
		}
	}

	return 0;
}

const int& Poblacion::obtenerAptitudPromedio() {
	aptitudPromedio = 0;

	for (int i = 0; i < longitudPoblacion; i++)
		aptitudPromedio += poblacion[i]->getAptitud();

	aptitudPromedio /= longitudPoblacion;
	return aptitudPromedio;
}
