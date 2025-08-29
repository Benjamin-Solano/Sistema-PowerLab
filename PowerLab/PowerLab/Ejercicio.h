#pragma once
#include <iostream>
using namespace std;

static string const areaDelCuerpo[4] = { "Pecho y Triceps", "Biceps", "Piernas", "Espalda" };

class Ejercicio {
private:
	string nombreEjercicio;
	string areaDeCuerpo;
	int duracionMinutos;

public:
	// Constructores
	Ejercicio() {
		nombreEjercicio = "";
		areaDeCuerpo = "";
		duracionMinutos = 0;
	}

	Ejercicio(string nombreE, int area, int duracionM) : nombreEjercicio(nombreE), duracionMinutos(duracionM) {
		if (area >= 0 && area < 4) {
			areaDeCuerpo = areaDelCuerpo[area];
		}
		else {
			areaDeCuerpo = "";
		}
	}

	// Getters
	string getNombreEjercicio() const {
		return nombreEjercicio;
	}

	string getAreaDeCuerpo() const {
		return areaDeCuerpo;
	}

	int getDuracionMinutos() const {
		return duracionMinutos;
	}

	// Setters
	void setNombreEjercicio(const string& nombre) {
		nombreEjercicio = nombre;
	}

	void setAreaDeCuerpo(int area) {
		if (area >= 0 && area < 4) {
			areaDeCuerpo = areaDelCuerpo[area];
		}
		// Si el área no es válida, no cambia el valor
	}

	void setAreaDeCuerpo(const string& area) {
		areaDeCuerpo = area;
	}

	void setDuracionMinutos(int duracion) {
		if (duracion >= 0) {
			duracionMinutos = duracion;
		}
		// Si la duración es negativa, no cambia el valor
	}

	// Método adicional para mostrar información
	void mostrarEjercicio() const {
		cout << "Ejercicio: " << nombreEjercicio << endl;
		cout << "Área: " << areaDeCuerpo << endl;
		cout << "Duración: " << duracionMinutos << " minutos" << endl;
	}
};

