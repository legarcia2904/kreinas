#pragma once
#include <array>
#include "Poblacion.h"
#include "Cromosoma.h"

class SeleccionIndividuos {
public:
	explicit SeleccionIndividuos(Poblacion*);
	~SeleccionIndividuos();
	Cromosoma* getPadreSeleccionado1() const;
	Cromosoma* getPadreSeleccionado2() const;

private:
	std::array<Cromosoma*, 5> padreSeleccionado;
	int longitudPoblacion;
	std::array<int, 5> generarArrayUnico();
};