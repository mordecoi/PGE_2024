#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Persona
{
protected:
    string nombre;
    int edad;
    string genero;

public:
    Persona(string n, int e, string g) : nombre(n), edad(e), genero(g) {}

    virtual void mostrarInfo() const
    {
        cout << "Nombre: " << nombre << ", Edad: " << edad << ", Género: " << genero << endl;
    }
};

class Empleado : public Persona
{
protected:
    double salario;
    string cargo;

public:
    Empleado(string n, int e, string g, double s, string c)
        : Persona(n, e, g), salario(s), cargo(c) {}

    void mostrarInfo() const override
    {
        Persona::mostrarInfo();
        cout << "Cargo: " << cargo << ", Salario: $" << salario << endl;
    }
};

class Estudiante : public Persona
{
private:
    double nota;

public:
    Estudiante(string n, int e, string g, double nt)
        : Persona(n, e, g), nota(nt) {}

    void mostrarInfo() const override
    {
        Persona::mostrarInfo();
        cout << "Nota: " << nota << endl;
    }
};

class Trabajador
{
private:
    Persona persona;
    string departamento;
    int horasTrabajadas;

public:
    Trabajador(const Persona &p, string dep, int horas)
        : persona(p), departamento(dep), horasTrabajadas(horas) {}

    double calcularSalario() const
    {
        double tarifaPorHora = 10.0;
        if (departamento == "IT")
            tarifaPorHora *= 1.5;
        else if (departamento == "Gerencia")
            tarifaPorHora *= 2.0;
        return tarifaPorHora * horasTrabajadas;
    }

    void mostrarInfo() const
    {
        persona.mostrarInfo();
        cout << "Departamento: " << departamento
             << ", Horas trabajadas: " << horasTrabajadas
             << ", Salario calculado: $" << calcularSalario() << endl;
    }
};

class SistemaGestionPersonal
{
private:
    vector<Empleado> empleados;
    vector<Estudiante> estudiantes;
    vector<Trabajador> trabajadores;

public:
    void agregarEmpleado(const Empleado &emp)
    {
        empleados.push_back(emp);
    }

    void agregarEstudiante(const Estudiante &est)
    {
        estudiantes.push_back(est);
    }

    void agregarTrabajador(const Trabajador &trab)
    {
        trabajadores.push_back(trab);
    }

    void mostrarTodoElPersonal() const
    {
        cout << "Empleados:" << endl;
        for (const auto &emp : empleados)
            emp.mostrarInfo();

        cout << "\nEstudiantes:" << endl;
        for (const auto &est : estudiantes)
            est.mostrarInfo();

        cout << "\nTrabajadores:" << endl;
        for (const auto &trab : trabajadores)
            trab.mostrarInfo();
    }
};

int main()
{
    SistemaGestionPersonal sistema;
    int opcion;

    do
    {
        cout << "\n----->Menú de opciones<-----\n";
        cout << "[1]. Agregar Empleado\n";
        cout << "[2]. Agregar Estudiante\n";
        cout << "[3]. Agregar Trabajador\n";
        cout << "[4]. Mostrar Todo el Personal\n";
        cout << "[5]. Salir\n";
        cout << "--->Selecciona una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            string nombre, genero, cargo;
            int edad;
            double salario;

            cout << "Introduce el nombre del empleado: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Introduce la edad del empleado: ";
            cin >> edad;
            cout << "Introduce el género del empleado: ";
            cin >> genero;
            cout << "Introduce el salario del empleado: ";
            cin >> salario;
            cout << "Introduce el cargo del empleado: ";
            cin.ignore();
            getline(cin, cargo);

            Empleado emp(nombre, edad, genero, salario, cargo);
            sistema.agregarEmpleado(emp);
            cout << "Se ha agregado un nuevo empleado...\n";
            cin.ignore();
            break;
        }
        case 2:
        {
            string nombre, genero;
            int edad;
            double nota;

            cout << "Introduce el nombre del estudiante: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Introduce la edad del estudiante: ";
            cin >> edad;
            cout << "Introduce el género del estudiante: ";
            cin >> genero;
            cout << "Introduce la nota del estudiante: ";
            cin >> nota;

            Estudiante est(nombre, edad, genero, nota);
            sistema.agregarEstudiante(est);
            cout << "Se ha agregado un nuevo estudiante...\n";
            cin.ignore();
            break;
        }
        case 3:
        {
            string nombre, genero, departamento;
            int edad, horasTrabajadas;

            cout << "Introduce el nombre del trabajador: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Introduce la edad del trabajador: ";
            cin >> edad;
            cout << "Introduce el género del trabajador: ";
            cin >> genero;
            cout << "Introduce el departamento del trabajador: ";
            cin.ignore();
            getline(cin, departamento);
            cout << "Introduce las horas trabajadas: ";
            cin >> horasTrabajadas;

            Persona p(nombre, edad, genero);
            Trabajador trab(p, departamento, horasTrabajadas);
            sistema.agregarTrabajador(trab);
            cout << "Se ha agregado un nuevo trabajador...\n";
            cin.ignore();
            break;
        }
        case 4:
            sistema.mostrarTodoElPersonal();
            cin.ignore();
            break;
        case 5:
            cout << "Saliendo del sistema de gestión de personal...\n";
            break;
        default:
            cout << "Opción no válida. Intenta de nuevo.\n";
            break;
        }
    } while (opcion != 5);

    return 0;
}