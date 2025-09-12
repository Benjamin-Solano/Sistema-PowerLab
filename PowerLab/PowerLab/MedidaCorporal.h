#pragma once
#include <iostream>

// En centimetros
class MedidaCorporal {
private:
	double cintura;
	double cadera;
	double pecho;
	double muslo;

public:
	MedidaCorporal() : cintura(0), cadera(0), pecho(0), muslo(0) { }
	MedidaCorporal(double cin, double cad, double pec, double mus) : cintura(cin), cadera(cad), pecho(pec), muslo(mus) { }

	// Gets
	double getCintura() { return this->cintura; }
	double getCadera() { return this->cadera; }
	double getPecho() { return this->pecho; }
	double getMuslo() { return this->muslo; }

 	// Sets
	void setCintura(double valor) { this->cintura = valor; }
	void setCadera(double valor) { this->cadera = valor; }
	void setPecho(double valor) { this->pecho = valor; }
	void setMuslo(double valor) { this->muslo = valor; }

};