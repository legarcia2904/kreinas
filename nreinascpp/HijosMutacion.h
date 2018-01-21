#pragma once
#include "Cromosoma.h"

class HijosMutacion {
public:
	HijosMutacion(Cromosoma* hijo1, Cromosoma* hijo2);
	void calcular(Cromosoma* cromosoma);
};

