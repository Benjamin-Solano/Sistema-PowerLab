#pragma once
#include "Especialidad.h"
#include "Cliente.h"

class Cliente;

class Instructor {
private:
	string cedula;
	string nombre;
	string telefono;
	string correo;
	string nacimiento;
	Especialidad** especialidades;
	Cliente** clientes;
	int cant;
	int tam;

	int cantClientes;
public:
	Instructor() : 
		cedula(""), nombre(""), telefono(""), correo(""), nacimiento(""), tam(10), cant(0) {
		especialidades = new Especialidad*[tam];
		clientes = new Cliente * [10];
		for (int i = 0; i < tam; i++) {
			especialidades[i] = nullptr;
			clientes[i] = nullptr;
		}
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


				especialidades[cant - 1] = nullptr;
				cant--;
				return true;
			}
		}
		return false;
	}


	// Metodos CRUD Clientes
	bool agregarCliente(Cliente* cliente) {
		if (cantClientes < tam) {
			clientes[cantClientes++] = cliente;
			return true;
		}
		return false;
	}

	Cliente* buscarClientePorCedula(string c) {
		if (cantClientes == 0) return nullptr;
		for (int i = 0; i < cantClientes; i++) {
			if (clientes[i]->getCedula() == c) {
				return clientes[i];
			}
		}
		return nullptr;
	}

	bool actualizarCliente(Cliente* nuevo, string c) {
		if (cantClientes == 0) return false;
		for (int i = 0; i < cantClientes; i++) {
			if (clientes[i]->getCedula() == c) {
				clientes[i] = nuevo;
				return true;
			}
		}
		return false;
	}

	bool eliminarCliente(string c) {
		if (cantClientes == 0) return false;
		for (int i = 0; i < cantClientes; i++) {
			if (clientes[i]->getCedula() == c) {
				delete clientes[i];  // liberamos memoria

				for (int j = i; j < cantClientes - 1; j++) {
					clientes[j] = clientes[j + 1];
				}

				clientes[cantClientes - 1] = nullptr;
				cantClientes--;
				return true;
			}
		}
		return false;
	}
};