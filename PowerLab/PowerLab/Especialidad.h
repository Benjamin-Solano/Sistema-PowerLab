#pragma once
#include <iostream>

using namespace std;

static string especialidades[9] = { "Crossfit", "HIIT", "TRX", "Pesas", "Spinning", "Cardio","Yoga","Zumba","Calistenia"};

class Especialidad {
private:
	string nombre;
public:
	// Constructores
	Especialidad() : nombre("") {}

	Especialidad(int e) : nombre(especialidades[e + 1]) { }

	// GET
	string getNombreEspecialidad() { return this->nombre; }
	// Set
	void setNombreEspecialidad(string nuevo) { this->nombre = nuevo; }
};