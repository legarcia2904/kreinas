#include "stdafx.h"
#include <algorithm>
#include <random>
#include <new>
#include <array>
#include "Cruzamiento.h"

Cruzamiento::Cruzamiento(Cromosoma* padre1, Cromosoma* padre2) {
	this->padre1 = padre1->clonarCromosoma();
	this->padre2 = padre2->clonarCromosoma();
	crearDescendencia();
}

Cruzamiento::~Cruzamiento() {
	delete padre1;
	delete padre2;
	delete hijo1;
	delete hijo2;
}

void Cruzamiento::crearDescendencia() {
	std::random_device rd;
	std::mt19937 motor(rd());
	std::uniform_int_distribution<unsigned int> random(0, padre1->getLongitud() - 1);
	int rndIndex = random(motor);

	hijo1 = new Cromosoma(padre1->getLongitud());
	hijo2 = new Cromosoma(padre1->getLongitud());

	for (int i = 0; i < hijo1->getLongitud(); i++) {
		if (i <= rndIndex) {
			hijo1->setGen(i, padre1->getGen(i));
			hijo2->setGen(i, padre2->getGen(i));
		}
		else {
			validarGen(hijo1, padre2, i);
			validarGen(hijo2, padre1, i);
		}
	}
}

void Cruzamiento::validarGen(Cromosoma* hijo, Cromosoma* parent, int i) {
	int j = i;
	while (true) {
		int* itr = std::find(hijo->getInformacion(), hijo->getInformacion() + hijo->getLongitud(), parent->getGen(j));

		if (itr != hijo->getInformacion() + hijo->getLongitud()) {
			j++;
			if (j >= hijo->getLongitud()) j = 0;
		}
		else {
			hijo->setGen(i, parent->getGen(j));
			return;
		}
	}
}

Cromosoma* Cruzamiento::getHijo1() const {
	return hijo1;
}

Cromosoma* Cruzamiento::getHijo2() const {
	return hijo2;
}

