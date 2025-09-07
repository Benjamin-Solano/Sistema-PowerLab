#pragma once
#include "Bateria_Ejercicios.h"

class Rutina {
private:
	Bateria_Ejercicios* pierna;
	Bateria_Ejercicios* espalda;
	Bateria_Ejercicios* pechoYTriceps;
	Bateria_Ejercicios* biceps;
public:
	Rutina() {
		pierna = new Bateria_Ejercicios;
		espalda = new Bateria_Ejercicios;
		pechoYTriceps = new Bateria_Ejercicios;
		biceps = new Bateria_Ejercicios;
	}

	// Gets
	Bateria_Ejercicios* getPierna() { return this->pierna; }
	Bateria_Ejercicios* getEspalda() { return this->espalda; }
	Bateria_Ejercicios* getPechoYTriceps() { return this->pechoYTriceps; }
	Bateria_Ejercicios* getBiceps() { return this->biceps; }

	// SETs
	void setPierna(Bateria_Ejercicios* nuevo) { this->pierna = nuevo; }
	void setEspalda(Bateria_Ejercicios* nuevo) { this->espalda = nuevo; }
	void setPechoYTriceps(Bateria_Ejercicios* nuevo) { this->pechoYTriceps = nuevo; }
	void setBiceps(Bateria_Ejercicios* nuevo) { this->biceps = nuevo; }

	// Mostrar Rutina Completa
	string toString() {
		stringstream mostrar;
		mostrar << pierna->toString() << endl
			<< espalda->toString() << endl
			<< pechoYTriceps->toString() << endl
			<< biceps->toString() << endl;
		return mostrar.str();
	}

};