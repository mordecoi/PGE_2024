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

    /**
     * @brief Constructor de la clase Movimiento.
     * 
     * @param nombre El nombre del movimiento.
     * @param poder El poder del movimiento.
     * @param tipo El tipo del movimiento.
     */
    Movimiento(string nombre, int poder, string tipo);
};

/**
 * @class Pokemon
 * @brief Representa un Pokemon con varios atributos y acciones.
 * 
 * La clase Pokemon proporciona funcionalidad para crear y manipular objetos Pokemon.
 * Contiene atributos como nombre, tipo, nivel, salud, ataque, defensa y combates ganados.
 * También tiene métodos para obtener y establecer estos atributos, así como realizar acciones como recibir daño,
 * agregar movimientos, atacar a otros Pokemon y ganar experiencia.
 * 
 * @note Esta clase está destinada a ser heredada y extendida por tipos de Pokemon específicos.
 */
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
    /**
     * @brief Constructor de la clase Pokemon.
     * 
     * @param nombre El nombre del Pokemon.
     */
    Pokemon(string nombre);

    /**
     * @brief Destructor de la clase Pokemon.
     */
    virtual ~Pokemon();

    /**
     * @brief Obtiene el nombre del Pokemon.
     * 
     * @return El nombre del Pokemon.
     */
    string getNombre() const;

    /**
     * @brief Obtiene el tipo del Pokemon.
     * 
     * @return El tipo del Pokemon.
     */
    string getTipo() const;

    /**
     * @brief Obtiene la salud actual del Pokemon.
     * 
     * @return La salud actual del Pokemon.
     */
    int getSalud() const;

    /**
     * @brief Obtiene la salud máxima del Pokemon.
     * 
     * @return La salud máxima del Pokemon.
     */
    int getSaludMaxima() const;

    /**
     * @brief Obtiene el nivel del Pokemon.
     * 
     * @return El nivel del Pokemon.
     */
    int getNivel() const;

    /**
     * @brief Recibe daño y reduce la salud del Pokemon.
     * 
     * @param danio El daño recibido.
     */
    void recibirDanio(int danio);

    /**
     * @brief Agrega un movimiento al Pokemon.
     * 
     * @param movimiento El movimiento a agregar.
     */
    void agregarMovimiento(const Movimiento &movimiento);

    /**
     * @brief Ataca a otro Pokemon con un movimiento específico.
     * 
     * @param objetivo El Pokemon objetivo del ataque.
     * @param movimiento El movimiento a utilizar.
     * @return El daño infligido al Pokemon objetivo.
     */
    virtual int atacar(Pokemon &objetivo, const Movimiento &movimiento);

    /**
     * @brief Obtiene los movimientos del Pokemon.
     * 
     * @return Los movimientos del Pokemon.
     */
    const vector<Movimiento> &getMovimientos() const;

    /**
     * @brief Selecciona un movimiento aleatorio del Pokemon.
     * 
     * @return El movimiento seleccionado aleatoriamente.
     */
    Movimiento seleccionarMovimientoAleatorio() const;

    /**
     * @brief Incrementa el contador de combates ganados del Pokemon.
     */
    void ganarCombate();

private:
    /**
     * @brief Verifica si un tipo de ataque es efectivo contra un tipo de defensa.
     * 
     * @param tipoAtaque El tipo de ataque.
     * @param tipoDefensa El tipo de defensa.
     * @return true si el ataque es efectivo, false en caso contrario.
     */
    bool esEfectivo(const string &tipoAtaque, const string &tipoDefensa) const;

    /**
     * @brief Verifica si el Pokemon tiene suficiente experiencia para subir de nivel.
     * 
     * @return true si tiene suficiente experiencia, false en caso contrario.
     */
    bool experienciaSuficiente() const;

    /**
     * @brief Incrementa el nivel del Pokemon y ajusta sus atributos.
     */
    void subirNivel();
};

class PokemonAgua : public Pokemon
{
public:
    /**
     * @brief Constructor de la clase PokemonAgua.
     * 
     * @param nombre El nombre del PokemonAgua.
     */
    PokemonAgua(string nombre);
};

class PokemonFuego : public Pokemon
{
public:
    /**
     * @brief Constructor de la clase PokemonFuego.
     * 
     * @param nombre El nombre del PokemonFuego.
     */
    PokemonFuego(string nombre);
};

class PokemonPlanta : public Pokemon
{
public:
    /**
     * @brief Constructor de la clase PokemonPlanta.
     * 
     * @param nombre El nombre del PokemonPlanta.
     */
    PokemonPlanta(string nombre);
};

class Ubicacion
{
public:
    string nombre;
    string descripcion;
    bool tieneCombate;
    bool liderDerrotado;

    /**
     * @brief Constructor de la clase Ubicacion.
     * 
     * @param nombre El nombre de la ubicación.
     * @param descripcion La descripción de la ubicación.
     * @param tieneCombate Indica si la ubicación tiene un combate.
     */
    Ubicacion(string nombre, string descripcion, bool tieneCombate);
};

class Mapa
{
private:
    vector<vector<Ubicacion>> grid;
    int filaActual;
    int columnaActual;

public:
    /**
     * @brief Constructor de la clase Mapa.
     * 
     * @param filas El número de filas del mapa.
     * @param columnas El número de columnas del mapa.
     */
    Mapa(int filas, int columnas);

    /**
     * @brief Establece la ubicación en una posición específica del mapa.
     * 
     * @param fila La fila de la ubicación.
     * @param columna La columna de la ubicación.
     * @param ubicacion La ubicación a establecer.
     */
    void setUbicacion(int fila, int columna, const Ubicacion &ubicacion);

    /**
     * @brief Obtiene la ubicación actual del jugador en el mapa.
     * 
     * @return La ubicación actual del jugador.
     */
    Ubicacion &getUbicacionActual();

    /**
     * @brief Mueve al jugador en una dirección específica en el mapa.
     * 
     * @param direccion La dirección del movimiento (N, S, E, O).
     * @return true si el movimiento fue exitoso, false en caso contrario.
     */
    bool mover(char direccion);

    /**
     * @brief Muestra el mapa en la consola.
     */
    void mostrarMapa();
};

class Jugador
{
public:
    string nombre;
    vector<Pokemon *> equipo;
    vector<Pokemon *> centroPokemon;

    /**
     * @brief Constructor de la clase Jugador.
     * 
     * @param nombre El nombre del jugador.
     */
    Jugador(string nombre);

    /**
     * @brief Agrega un Pokemon al equipo del jugador.
     * 
     * @param pokemon El Pokemon a agregar.
     */
    void agregarPokemon(Pokemon *pokemon);

    /**
     * @brief Verifica si el jugador tiene Pokemon disponibles en su equipo.
     * 
     * @return true si tiene Pokemon disponibles, false en caso contrario.
     */
    bool tienePokemonDisponibles() const;

    /**
     * @brief Envía un Pokemon al centro Pokemon para ser curado.
     * 
     * @param pokemon El Pokemon a enviar al centro Pokemon.
     */
    void enviarPokemonAlCentro(Pokemon *pokemon);

    /**
     * @brief Recoge los Pokemon curados del centro Pokemon.
     */
    void recogerPokemonDelCentro();

    /**
     * @brief Destructor de la clase Jugador.
     */
    ~Jugador();
};

/**
 * @brief Muestra el arte ASCII de un Pokemon específico.
 * 
 * @param pokemon El nombre del Pokemon.
 */
void mostrarArtePokemon(const string &pokemon);

/**
 * @brief Permite al usuario seleccionar un Pokemon.
 * 
 * @return El Pokemon seleccionado por el usuario.
 */
Pokemon *seleccionarPokemonUsuario();

/**
 * @brief Permite seleccionar un Pokemon aleatorio basado en el nivel del jugador.
 * 
 * @param nivelJugador El nivel del jugador.
 * @return El Pokemon seleccionado aleatoriamente.
 */
Pokemon *seleccionarPokemonAleatorio(int nivelJugador);

/**
 * @brief Muestra el estado del combate entre dos Pokemon.
 * 
 * @param jugador El Pokemon del jugador.
 * @param oponente El Pokemon del oponente.
 */
void mostrarEstadoCombate(const Pokemon &jugador, const Pokemon &oponente);

/**
 * @brief Permite al usuario seleccionar un movimiento para su Pokemon.
 * 
 * @param pokemon El Pokemon del jugador.
 * @return El movimiento seleccionado por el usuario.
 */
Movimiento seleccionarMovimientoUsuario(const Pokemon &pokemon);

/**
 * @brief Inicia un combate entre un jugador y un oponente.
 * 
 * @param seleccionJugadorCallback Callback para seleccionar el Pokemon del jugador.
 * @param seleccionOponenteCallback Callback para seleccionar el Pokemon del oponente.
 * @param movimientoJugadorCallback Callback para seleccionar el movimiento del jugador.
 * @param movimientoOponenteCallback Callback para seleccionar el movimiento del oponente.
 * @param ataqueCallback Callback para realizar el ataque entre los Pokemon.
 * @param mostrarEstadoCallback Callback para mostrar el estado del combate.
 * @param onGanador Callback para ejecutar cuando el jugador gana el combate.
 * @param onPerdedor Callback para ejecutar cuando el jugador pierde el combate.
 * @return true si el jugador ganó el combate, false en caso contrario.
 */
bool IniciarCombate(
    function<Pokemon *()> seleccionJugadorCallback,
    function<Pokemon *()> seleccionOponenteCallback,
    function<Movimiento(const Pokemon &)> movimientoJugadorCallback,
    function<Movimiento(const Pokemon &)> movimientoOponenteCallback,
    function<void(Pokemon &, Pokemon &, const Movimiento &)> ataqueCallback,
    function<void(const Pokemon &, const Pokemon &)> mostrarEstadoCallback,
    function<void()> onGanador,
    function<void()> onPerdedor);

/**
 * @brief Muestra el arte ASCII del juego.
 */
void mostrarArteASCII();

/**
 * @brief Inicializa el mapa del juego.
 * 
 * @return El mapa inicializado.
 */
Mapa inicializarMapa();

/**
 * @brief Despachador de eventos del juego.
 * 
 * @param jugador El jugador del juego.
 * @param mapa El mapa del juego.
 */
void despachadorDeEventos(Jugador &jugador, Mapa &mapa);

/**
 * @brief Inicia la aventura del juego.
 */
void jugarAventura();

#endif // POKEMON_H
