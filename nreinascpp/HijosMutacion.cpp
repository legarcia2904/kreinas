#include "stdafx.h"
#include "HijosMutacion.h"
#include <random>

HijosMutacion::HijosMutacion(Cromosoma* hijo1, Cromosoma* hijo2) {
	std::random_device rd;
	std::mt19937 motor(rd());
	std::uniform_int_distribution<unsigned int> random(1, 10);

	if (random(motor) > 2)
		calcular(hijo1);

	if (random(motor) > 2)
		calcular(hijo2);

	hijo1->evaluar();
	hijo2->evaluar();
}

void HijosMutacion::calcular(Cromosoma* cromosoma) {
	std::random_device rd;
	std::mt19937 motor(rd());
	std::uniform_int_distribution<unsigned int> random(0, cromosoma->getLongitud() - 1);

	int indexA = random(motor);
	int indexB = random(motor);

	int g1 = cromosoma->getGen(indexA);
	int g2 = cromosoma->getGen(indexB);

	cromosoma->setGen(indexA, g2);
	cromosoma->setGen(indexB, g1);
}
