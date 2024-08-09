#include <iostream>
using namespace std;

class Animal
{
private:
    bool puedeDormir = 0;
    bool puedeComer = 0;

public:
    Animal(bool dormir, bool comer) : puedeDormir(dormir), puedeComer(comer) {}
    void dormir()
    {
        if (puedeDormir == 0)
            cout << "El animal no puede dormir\n";
        else
            cout << "El animal esta durmiendo\n";
    }
    void comer()
    {
        if (puedeComer == 0)
            cout << "El animal no puede comer\n";
        else
            cout << "El animal esta comiendo\n";
    }
    bool getDormir() { return puedeDormir; }
    bool getComer() { return puedeComer; }
};

class Veterinario
{
private:
    string nombre;

public:
    Veterinario(string nombre) : nombre(nombre) {}
    void setNombre(string nombre) { this->nombre = nombre; }
    string getNombre() { return nombre; }
    void revisarAnimal(Animal animal)
    {
        if (animal.getDormir() == 1 && animal.getComer() == 1)
            cout << "El animal esta sano\n";
        else
        {
            cout << "El animal no esta sano\n";
        }
    }
};

int main()
{
    Animal A1(1, 1);
    Veterinario V1("Juan");

    A1.dormir();
    A1.comer();
    V1.revisarAnimal(A1);

    return 0;
}