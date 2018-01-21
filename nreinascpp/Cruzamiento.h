#pragma once

#include <array>
#include "Poblacion.h"
#include "SeleccionIndividuos.h"

class Cruzamiento {
public:
	Cruzamiento(Cromosoma*, Cromosoma*);
	~Cruzamiento();
	Cromosoma* getHijo1() const;
	Cromosoma* getHijo2() const;

private:
	Cromosoma * padre1;
	Cromosoma* padre2;
	Cromosoma* hijo1;
	Cromosoma* hijo2;

	void validarGen(Cromosoma*, Cromosoma*, int);
	void crearDescendencia();
};
