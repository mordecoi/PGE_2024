// pokemon.h
#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <limits>
#include <functional>
#include <map>
#include <memory>

using namespace std;

class Movimiento
{
public:
    string nombre;
    int poder;
    string tipo;

    Movimiento(string nombre, int poder, string tipo);
};

class Pokemon
{
protected:
    string nombre;
    string tipo;
    int nivel;
    int saludMaxima;
    int salud;
    int ataque;
    int defensa;
    int combatesGanados;
    vector<Movimiento> movimientos;

public:
    Pokemon(string nombre);
    virtual ~Pokemon();

    string getNombre() const;
    string getTipo() const;
    int getSalud() const;
    int getSaludMaxima() const;
    int getNivel() const;

    void recibirDanio(int danio);
    void agregarMovimiento(const Movimiento &movimiento);
    virtual int atacar(Pokemon &objetivo, const Movimiento &movimiento);
    const vector<Movimiento> &getMovimientos() const;
    Movimiento seleccionarMovimientoAleatorio() const;
    void ganarCombate();

private:
    bool esEfectivo(const string &tipoAtaque, const string &tipoDefensa) const;
    bool experienciaSuficiente() const;
    void subirNivel();
};

class PokemonAgua : public Pokemon
{
public:
    PokemonAgua(string nombre);
};

class PokemonFuego : public Pokemon
{
public:
    PokemonFuego(string nombre);
};

class PokemonPlanta : public Pokemon
{
public:
    PokemonPlanta(string nombre);
};

class Ubicacion
{
public:
    string nombre;
    string descripcion;
    bool tieneCombate;
    bool liderDerrotado;

    Ubicacion(string nombre, string descripcion, bool tieneCombate);
};

class Mapa
{
private:
    vector<vector<Ubicacion>> grid;
    int filaActual;
    int columnaActual;

public:
    Mapa(int filas, int columnas);
    void setUbicacion(int fila, int columna, const Ubicacion &ubicacion);
    Ubicacion &getUbicacionActual();
    bool mover(char direccion);
    void mostrarMapa();
};

class Jugador
{
public:
    string nombre;
    vector<Pokemon *> equipo;
    vector<Pokemon *> centroPokemon;

    Jugador(string nombre);
    void agregarPokemon(Pokemon *pokemon);
    bool tienePokemonDisponibles() const;
    void enviarPokemonAlCentro(Pokemon *pokemon);
    void recogerPokemonDelCentro();
    ~Jugador();
};

void mostrarArtePokemon(const string &pokemon);
Pokemon *seleccionarPokemonUsuario();
Pokemon *seleccionarPokemonAleatorio(int nivelJugador);
void mostrarEstadoCombate(const Pokemon &jugador, const Pokemon &oponente);
Movimiento seleccionarMovimientoUsuario(const Pokemon &pokemon);
bool IniciarCombate(
    function<Pokemon *()> seleccionJugadorCallback,
    function<Pokemon *()> seleccionOponenteCallback,
    function<Movimiento(const Pokemon &)> movimientoJugadorCallback,
    function<Movimiento(const Pokemon &)> movimientoOponenteCallback,
    function<void(Pokemon &, Pokemon &, const Movimiento &)> ataqueCallback,
    function<void(const Pokemon &, const Pokemon &)> mostrarEstadoCallback,
    function<void()> onGanador,
    function<void()> onPerdedor);
void mostrarArteASCII();
Mapa inicializarMapa();
void despachadorDeEventos(Jugador &jugador, Mapa &mapa);
void jugarAventura();

#endif // POKEMON_H
