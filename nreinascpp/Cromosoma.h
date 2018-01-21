#pragma once
#include <string>

	class Cromosoma {
	private:
		int aptitud = 0;
		int* informacion;
		int longitud;

	public:
		explicit Cromosoma(const int&);
		Cromosoma(int* informacion, const int& size, const int& aptitud);
		~Cromosoma();

		void intercambiar();
		const int& getAptitud() const;
		const int& getLongitud() const;
		int getGen(const int&) const;
		void setGen(const int, const int);
		int compararCon(const Cromosoma*) const;
		Cromosoma* clonarCromosoma() const;
		int* getInformacion() const;
		void setAptitud(const int aptitud);
		static void barajar(int*& array, const int size);
		static void incrementar(int*& array, const int size, const int& x);
		friend std::ostream& operator<<(std::ostream&, const Cromosoma*);
		void evaluar();
};
