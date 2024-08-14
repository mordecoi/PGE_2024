#include "pokemon.h"

using namespace std;

Pokemon::Pokemon(const std::string& nombre, int saludMaxima, int ataque, int defensa, int nivel)
    : nombre(nombre), salud(saludMaxima), saludMaxima(saludMaxima), ataque(ataque), defensa(defensa), nivel(nivel) {}

std::string Pokemon::getNombre() const {
    return nombre;
}

int Pokemon::getSalud() const {
    return salud;
}

int Pokemon::getSaludMaxima() const {
    return saludMaxima;
}

int Pokemon::getAtaque() const {
    return ataque;
}

int Pokemon::getDefensa() const {
    return defensa;
}

int Pokemon::getNivel() const {
    return nivel;
}

void Pokemon::subirNivel() {
    ++nivel;
    saludMaxima += 5;
    salud = saludMaxima;
    ataque += 2;
    defensa += 2;
    cout << nombre << " ha subido de nivel! Ahora es nivel " << nivel << endl;
}

void Pokemon::recibirDanio(int danio) {
    salud = max(0, salud - danio);
    cout << nombre << " ha recibido " << danio << " puntos de daño" << endl;
    if (salud == 0) {
        cout << nombre << " se ha debilitado... Fuera de combate" << endl;
    } else {
        cout << nombre << " tiene " << salud << "/" << saludMaxima << " puntos de vida restantes" << endl << endl;
    }
}

bool Pokemon::estaVivo() const {
    return salud > 0;
}

void mostrarEstadoCombate(const Pokemon& jugador, const Pokemon& oponente) {
    // Implementación de la función para mostrar el estado del combate
}

void mostrarArteASCII() {
    // Implementación de la función para mostrar el arte ASCII
}