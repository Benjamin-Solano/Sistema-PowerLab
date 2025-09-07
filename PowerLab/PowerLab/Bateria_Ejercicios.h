#pragma once
#include "Ejercicio.h"

class Bateria_Ejercicios {
private:
	int cant;
	int tam;
	Ejercicio** vec;
public:
	// Constructores
	Bateria_Ejercicios() : cant(0), tam(10) {
		vec = new Ejercicio * [tam];

		for (int i = 0; i < tam; i++) {
			vec[i] = nullptr;
		}
	}
	
	Bateria_Ejercicios(int t) : cant(0) {
		tam = t;
		vec = new Ejercicio * [tam];

		for (int i = 0; i < tam; i++) {
			vec[i] = nullptr;
		}
	}

	// Destructor
	virtual ~Bateria_Ejercicios() {
		for (int i = 0; i < cant; i++) {
			delete vec[i];
		}
		delete[] vec;
	}

	// Metodos CRUD
	bool agregarEjercicio(Ejercicio* e) {
		if (cant < tam) {
			vec[cant++] = e;
			return true;
		}
		return false;
	}

	Ejercicio* buscarEjercicioPorNombre(string nom) {
		// validar si hay elementos
		if (cant == 0) {
			return nullptr;
		}
		for (int i = 0; i < cant; i++) {
			if (vec[i]->getNombreEjercicio() == nom) {
				return vec[i];
			}
		}
	}

	// Busca y actualiza el ejercicio por nombre
	bool buscarYactualizarEjercicio(string nom, Ejercicio* nuevo) {
		if (cant != 0) {
			for (int i = 0; i < cant; i++) {
				if (vec[i]->getNombreEjercicio() == nom) {
					vec[i] = nuevo;
					return true;
				}
			}
		}
		return false;
	}
	
	// Busca y elimina el ejercicio por nombre
	bool eliminaEjercicio(string nom) {
		if (cant != 0) {
			for (int i = 0; i < cant; i++) {
				if (vec[i]->getNombreEjercicio() == nom) {
					delete vec[i];
					// Desplazar los elementos una posición hacia la izquierda
					for (int j = i; j < cant - 1; j++) {
						vec[j] = vec[j + 1];
					}

					vec[cant - 1] = nullptr; 
					cant--; 
					return true;
				}
			}
		}
		return false;
	}

};