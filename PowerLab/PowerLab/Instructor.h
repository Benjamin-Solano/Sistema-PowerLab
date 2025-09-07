#pragma once
#include "Especialidad.h"

class Instructor {
private:
	string cedula;
	string nombre;
	string telefono;
	string correo;
	string nacimiento;
	Especialidad** especialidades;
	int cant;
	int tam;
public:
	Instructor() : 
		cedula(""), nombre(""), telefono(""), correo(""), nacimiento(""), tam(10), cant(0) {
		especialidades = new Especialidad*[tam];

		for (int i = 0; i < tam; i++) especialidades = nullptr;
	}

	Instructor(string c, string n, string t, string co, string na, int ta) 
		: cedula(c), nombre(n), telefono(t), correo(co), nacimiento(na), tam(ta), cant(0)
	{
		especialidades = new Especialidad * [tam];
	}

	// Sets
	void setCedula(string valor) { this->cedula = valor; }
	void setNombre(string valor) { this->nombre = valor; }
	void setTelefono(string valor) { this->telefono = valor; }
	void setCorreo(string valor) { this->correo = valor; }
	
	// gets
	string getCedula() { return this->cedula; }
	string getNombre() { return this->nombre; }
	string getTelefono() { return this->telefono; }
	string getCorreo() { return this->correo; }
	string getNacimiento() { return this->nacimiento; }

	// Metodos CRUD de Especialidades
	bool agregarEspecialidad(Especialidad* especialidad) {
		if (cant < tam) {
			especialidades[cant++] = especialidad;
			return true;
		}
		return false;
	}

	Especialidad* buscarEspecialidadPorNombre(string n) {
		if (cant == 0) return nullptr;
		for (int i = 0; i < cant; i++) {
			if (especialidades[i]->getNombreEspecialidad() == n) {
				return especialidades[i];
			}
		}
		return nullptr;
	}

	bool actulizarEspecialidad(Especialidad* nueva, string n) {
		if (cant == 0) return false;
		for (int i = 0; i < cant; i++) {
			if (especialidades[i]->getNombreEspecialidad() == n) {
				especialidades[i] = nueva;
				return true;
			}
		}
		return false;
	}

	bool eliminarEspecialidad(string n) {
		if (cant == 0) return false;
		for (int i = 0; i < cant; i++) {

			if (especialidades[i]->getNombreEspecialidad() == n) {

				delete especialidades[i];

				for (int ii = i; ii < cant - 1; ii++) {
					especialidades[ii] = especialidades[ii + 1];
				}


				especialidades[cant + 1] = nullptr;
				cant--;
				return true;
			}
		}
		return false;
	}


};