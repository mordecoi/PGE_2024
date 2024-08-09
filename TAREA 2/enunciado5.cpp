#include <iostream>
#include <vector>
using namespace std;

class Estudiante
{
private:
    string nombre;
    int edad;
    int nota;

public:
    Estudiante() : nombre("Mateo"), edad(0), nota(0) {}
    Estudiante(string nombre, int edad, int nota) : nombre(nombre), edad(edad), nota(nota) {}
    void setNombre(string nombre) { this->nombre = nombre; }
    void setEdad(int edad) { this->edad = edad; }
    void setNota(int nota) { this->nota = nota; }
    string getNombre() { return nombre; }
    int getEdad() { return edad; }
    int getNota() { return nota; }
};

class GrupoEstudiantes : public Estudiante
{
private:
    vector<Estudiante> estudiantes;

public:
    GrupoEstudiantes(vector<Estudiante> estudiantes) : estudiantes(estudiantes) {}
    void setEstudiantes(vector<Estudiante> estudiantes) { this->estudiantes = estudiantes; }
    vector<Estudiante> getEstudiantes() { return estudiantes; }
    void aniadirEstudiante(Estudiante estudiante) { estudiantes.push_back(estudiante); }
    void calcularPromedio()
    {
        int suma = 0;
        for (int i = 0; i < estudiantes.size(); i++)
        {
            suma += estudiantes[i].getNota();
        }
        cout << "El promedio de notas es: " << suma / estudiantes.size() << endl;
    }
};

int main()
{
    Estudiante E1("Mateo", 20, 10);
    Estudiante E2("Juan", 21, 9);
    Estudiante E3("Pedro", 22, 8);
    Estudiante E4("Maria", 23, 7);
    Estudiante E5("Ana", 24, 6);

    vector<Estudiante> estudiantes;
    estudiantes.push_back(E1);
    estudiantes.push_back(E2);
    estudiantes.push_back(E3);
    estudiantes.push_back(E4);
    estudiantes.push_back(E5);

    GrupoEstudiantes GE1(estudiantes);

    Estudiante E6("Lucas", 25, 5);
    GE1.aniadirEstudiante(E6);
    GE1.calcularPromedio();

    return 0;
}