#include <iostream>
using namespace std;

// Definición de la función de callback
void MiCallback(int valor)
{
    cout << "El valor es: " << valor << endl;
}

// Función que procesa los datos y llama al callback
void ProcesarDatos(int dato, void (*callback)(int))
{
    callback(dato);
    callback(dato * 2);
}

int main()
{
    // Llamada a la función ProcesarDatos con un valor de dato y el callback MiCallback
    ProcesarDatos(3, MiCallback);
    return 0;
}