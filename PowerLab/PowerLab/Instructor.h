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
	Instructor() : cedula(""), nombre(""), telefono(""), correo(""), nacimiento(""), tam(10), cant(0) {
		especialidades = new Especialidad*[tam];

		for (int i = 0; i < tam; i++) especialidades = nullptr;
	}

	Instructor(string c, string n, string t, string co, string na, int ta) 
		: cedula(c), nombre(n), telefono(t), correo(co), nacimiento(na), tam(ta)
	{
		especialidades = new Especialidad * [tam];
	}

};