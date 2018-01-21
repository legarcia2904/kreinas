#pragma once
#include <vector>
#include "Cromosoma.h"

class Poblacion
{
	private:
		int longitudPoblacion;
		std::vector<Cromosoma*> poblacion;
		Cromosoma* mejorCromosoma;
		int aptitudPromedio;

		void generarPoblacionAleatoria(const int& longitudCromosoma);
		int insertarHijo(int inicio, Cromosoma* hijo);

	public:
		Poblacion(const int longitudPoblacion, const int longitudCromosoma);
		~Poblacion();
		Cromosoma* getCromosoma(const int& index) const;
		Cromosoma* getMejor() const;
		const int& getLongitud() const;
		void ordenarPorAptitud();
		void ejecutarGeneracion();
		const int& obtenerAptitudPromedio();
};

