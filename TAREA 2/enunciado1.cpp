#include <iostream>
using namespace std;

class Persona
{
private:
    string nombre;
    int edad;
    string genero;

public:
    Persona(string nombre, int edad, string genero) : nombre(nombre), edad(edad), genero(genero) {}
    void setNombre(string nombre) { this->nombre = nombre; }
    void setEdad(int edad) { this->edad = edad; }
    void setGenero(string genero) { this->genero = genero; }
    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    string getGenero() { return genero; }
};

class Empleado : public Persona
{
private:
    int salario;
    string cargo;

public:
    Empleado(string nombre, int edad, string genero, int salario, string cargo) : Persona(nombre, edad, genero), salario(salario), cargo(cargo) {}
    void setSalario(int salario) { this->salario = salario; }
    void setCargo(string cargo) { this->cargo = cargo; }
    int getSalario() { return salario; }
    string getCargo() { return cargo; }
};

int main()
{
    Persona P1("Gaston", 20, "Masculino");
    Empleado *P2 = new Empleado("Gaston", 20, "Masculino", 1000, "Programador");

    cout << P1.getNombre() << " " << P1.getEdad() << " " << P1.getGenero() << endl;
    cout << P2->getNombre() << " " << P2->getEdad() << " " << P2->getGenero() << " " << P2->getSalario() << " " << P2->getCargo() << endl;

    return 0;
}