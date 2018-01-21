#include "stdafx.h"
#include "SeleccionIndividuos.h"
#include <random>
#include "Cruzamiento.h"

SeleccionIndividuos::SeleccionIndividuos(Poblacion* poblacion) {
	longitudPoblacion = poblacion->getLongitud();
	std::array<int, 5> rndParents = generarArrayUnico();

	for (unsigned int i = 0; i < rndParents.size(); i++)
		padreSeleccionado[i] = poblacion->getCromosoma(rndParents[i])->clonarCromosoma();

	std::sort(padreSeleccionado.begin(), padreSeleccionado.end(), [](const Cromosoma* c1, const Cromosoma* c2) {
		return c1->getAptitud() < c2->getAptitud();
	});
}

Cromosoma* SeleccionIndividuos::getPadreSeleccionado1() const {
	return padreSeleccionado[0];
}

Cromosoma* SeleccionIndividuos::getPadreSeleccionado2() const {
	return padreSeleccionado[1];
}

SeleccionIndividuos::~SeleccionIndividuos() {
	for (std::array<Cromosoma*, 5>::iterator it = padreSeleccionado.begin(); it != padreSeleccionado.end(); ++it)
		delete (*it);
}

std::array<int, 5> SeleccionIndividuos::generarArrayUnico() {
	std::array<int, 5> generatedNumbers;
	generatedNumbers.fill(0);

	std::random_device rd;
	std::mt19937 motor(rd());
	std::uniform_int_distribution<unsigned int> random(0, longitudPoblacion - 1);

	for (int i = 0; i < 5; i++) {
		while (true) {
			int value = random(motor);
			auto itr = std::find(generatedNumbers.begin(), generatedNumbers.end(), value);

			if (itr != generatedNumbers.end()) continue;
			else {
				generatedNumbers[i] = value;
				break;
			}
		}
	}

	return generatedNumbers;
}