#include <iostream>
#include <string>

using namespace std;

class Persona {
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

class Trabajador {
    private:
        Persona persona;
        string cargo;
        int horasTrabajadas;
        double tarifaPorHora;
    
    public:
        Trabajador(Persona persona, string cargo, int horasTrabajadas, double tarifaPorHora) 
            : persona(persona), cargo(cargo), horasTrabajadas(horasTrabajadas), tarifaPorHora(tarifaPorHora) {}
        
        double calcularSalario() {
            return horasTrabajadas * tarifaPorHora;
        }

        void mostrarInformacion() {
            cout << "Nombre: " << persona.getNombre() << endl;
            cout << "Edad: " << persona.getEdad() << endl;
            cout << "Genero: " << persona.getGenero() << endl;
            cout << "Cargo: " << cargo << endl;
            cout << "Horas Trabajadas: " << horasTrabajadas << endl;
            cout << "Tarifa por Hora: " << tarifaPorHora << endl;
            cout << "Salario: " << calcularSalario() << endl;
        }
};

int main() {
    Persona p1("Juan Perez", 30, "Masculino");
    Trabajador t1(p1, "Desarrollador", 40, 25.5);
    t1.mostrarInformacion();
    return 0;
}