#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
using namespace std;

class Pokemon {
public:
    Pokemon(const std::string& nombre, int saludMaxima, int ataque, int defensa, int nivel);

    std::string getNombre() const;
    int getSalud() const;
    int getSaludMaxima() const;
    int getAtaque() const;
    int getDefensa() const;
    int getNivel() const;

    void subirNivel();
    void recibirDanio(int danio);
    bool estaVivo() const;

private:
    std::string nombre;
    int salud;
    int saludMaxima;
    int ataque;
    int defensa;
    int nivel;
};

void mostrarEstadoCombate(const Pokemon& jugador, const Pokemon& oponente);
void mostrarArteASCII();

#endif // POKEMON_H