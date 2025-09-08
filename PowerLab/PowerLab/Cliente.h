#include "Rutina.h"
#include <chrono>
#include <ctime>
#include <sstream>  // para toString
#include <iomanip>  // para formatear fecha
#include "Instructor.h"
using namespace std;

class Instructor;

class Cliente {
private:
    string cedula;
    string nombre;
    string telefono;
    string correo;
    string nacimiento;
    char sexo;
    time_t inscripcion;   // fecha actual de inscripción
    Instructor* instructor;
public:
    // Constructor
    Cliente(string c, string n, string t, string na, char s, string co = "")
        : cedula(c), nombre(n), telefono(t), nacimiento(na), sexo(s), correo(co), instructor(nullptr)
    {
        inscripcion = chrono::system_clock::to_time_t(chrono::system_clock::now());
    }

    // --- GETTERS ---
    string getCedula() const { return cedula; }
    string getNombre() const { return nombre; }
    string getTelefono() const { return telefono; }
    string getCorreo() const { return correo; }
    string getNacimiento() const { return nacimiento; }
    char getSexo() const { return sexo; }
    time_t getInscripcion() const { return inscripcion; }
    Instructor* getInstructor() { return this->instructor; }

    // --- SETTERS ---
    void setCedula(const string& c) { cedula = c; }
    void setNombre(const string& n) { nombre = n; }
    void setTelefono(const string& t) { telefono = t; }
    void setCorreo(const string& co) { correo = co; }
    void setNacimiento(const string& na) { nacimiento = na; }
    void setSexo(char s) { sexo = s; }
    void setInscripcion(time_t i) { inscripcion = i; }
    void setInstructor(Instructor* nuevo) { this->instructor = nuevo; }

    // --- toString ---
    string toString() const {
        stringstream ss;

        // Convertir la fecha de inscripción a formato legible
        tm* fecha = localtime(&inscripcion);
        ss << "Cliente:\n";
        ss << "  Cedula: " << cedula << "\n";
        ss << "  Nombre: " << nombre << "\n";
        ss << "  Telefono: " << telefono << "\n";
        ss << "  Correo: " << correo << "\n";
        ss << "  Nacimiento: " << nacimiento << "\n";
        ss << "  Sexo: " << sexo << "\n";
        ss << "  Inscripcion: "
            << put_time(fecha, "%d/%m/%Y %H:%M:%S") << "\n"
            << "Instructor Personal: " << this->instructor->getNombre() << endl;

        return ss.str();
    }
};
