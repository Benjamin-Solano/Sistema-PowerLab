#pragma once
#include "Cliente.h"
#include <iomanip>  // para formatear fecha
#include <chrono>
#include <ctime>
#include "MedidaCorporal.h"

class Reporte {
private:
	Cliente* cliente;
	time_t fechaMedicion;
	double peso;
	double estatura;
	double porcentajeGrasa;
	double porcentajeMusculo;
	int edadMetabolica;
	double grasaVisceral;
	MedidaCorporal* medidaCorporal;

public:
	Reporte() {
		cliente = nullptr;
		peso = 0; // en kilos
		estatura = 0;
		porcentajeGrasa = 0;
		porcentajeMusculo = 0;
		edadMetabolica = 0;
		grasaVisceral = 0;

		fechaMedicion = chrono::system_clock::to_time_t(chrono::system_clock::now());
	}

	Reporte(Cliente* cli, double pes, double est, double pG, double pM, int eM, double gV, MedidaCorporal* mC) {
		cliente = cli;
		peso = pes;
		estatura = est;
		porcentajeGrasa = pG;
		porcentajeMusculo = pM;
		edadMetabolica = eM;
		grasaVisceral = gV;

		fechaMedicion = chrono::system_clock::to_time_t(chrono::system_clock::now());
	}

	~Reporte() {
		if (cliente != nullptr && medidaCorporal != nullptr) {
			delete cliente;
			delete medidaCorporal;
		}
	}

	string IMC() {
		double indice = this->peso / pow(peso, 2);

		if (indice < 16) {
			return "Delgadez Severa";
		}
		else if (16.01 < indice && indice < 16.99) {
			return "Delgadez Moderada";
		}
		else if (17.00 < indice && indice < 18.49) {
			return "Delgadez Leve";
		}
		else if (18.5 < indice && indice < 24.99) {
			return "Normal";
		}
		else if (25.00 < indice && indice < 29.99) {
			return "Pre-Obesidad";
		}
		else if (30.00 < indice && indice < 34.99) {
			return "Obesidad Leve";
		}
		else if (35.00 < indice && indice < 39.99) {
			return "Obvesidad Media"; 
		}
		else if (indice > 40.00) {
			return "Obesidad Morbida";
		}

	}

	double cantProteinaDiarios() {
		return 0.8 * peso;
	}
	
	// Basos de 250ml
	double cantidadDeBasosAgua() {
		return peso / 7;
	}

	string generarReporte() {
		stringstream mostrar;

		mostrar << "<<=======  REPORTE DE " << cliente->getNombre() << "  =======>>" << endl
			<< "  Instructor       : " << this->cliente->getInstructor()->getNombre() << endl
			<< "  Fecha de Medicion: " << this->fechaMedicion << endl
			<< "  Peso en Kilos    : " << this->peso << endl
			<< "  Estatura en cm   : " << this->estatura << endl
			<< "  % de Grasa       : " << this->porcentajeGrasa << endl
			<< "  % de Musculo     : " << this->porcentajeMusculo << endl
			<< "  Edad Metabolica  : " << this->edadMetabolica << endl
			<< "  Grasa Visceral   : " << this->grasaVisceral << endl
			<< "  IMC              : " << this->IMC() << endl
			<< "  Cantidad de Basos x Dia: " << this->cantidadDeBasosAgua() << endl
			<< "  Proteina x Dia   : " << this->cantProteinaDiarios() << endl
			<< "<<=====================================>>" << endl;

		return mostrar.str();
	}

};