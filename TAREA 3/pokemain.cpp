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

class Movimiento {
public:
    string nombre;
    int poder;
    string tipo;

    Movimiento(string nombre, int poder, string tipo) : nombre(nombre), poder(poder), tipo(tipo) {}
};

class Pokemon {
protected:
    string nombre;
    string tipo;
    int nivel;
    int saludMaxima;
    int salud;
    int ataque;
    int defensa;
    int combatesGanados;  // Nuevo atributo
    vector<Movimiento> movimientos;

public:
    Pokemon(string nombre) : nombre(nombre), tipo("Normal"), nivel(1), saludMaxima(20), salud(20), ataque(5), defensa(5), combatesGanados(0) {
        cout << nombre << " ha entrado al combate" << endl;
    }

    virtual ~Pokemon() {}

    string getNombre() const { return nombre; }
    string getTipo() const { return tipo; }
    int getSalud() const { return salud; }
    int getSaludMaxima() const { return saludMaxima; }
    int getNivel() const { return nivel; }  // Nuevo getter para nivel

    void recibirDanio(int danio) {
        salud = max(0, salud - danio);
        cout << nombre << " ha recibido " << danio << " puntos de daño" << endl;
        if (salud == 0) {
            cout << nombre << " se ha debilitado... Fuera de combate" << endl;
        } else {
            cout << nombre << " tiene " << salud << "/" << saludMaxima << " puntos de vida restantes" << endl << endl;
        }
    }

    void agregarMovimiento(const Movimiento& movimiento) {
        if (movimientos.size() < 4) {
            movimientos.push_back(movimiento);
        }
    }

    virtual int atacar(Pokemon& objetivo, const Movimiento& movimiento) {
        int danio = movimiento.poder + ataque;
        cout << nombre << " usa " << movimiento.nombre << "!" << endl;
        if (movimiento.tipo == objetivo.getTipo()) {
            danio /= 2;
            cout << "No es muy efectivo..." << endl;
        } else if (esEfectivo(movimiento.tipo, objetivo.getTipo())) {
            danio *= 2;
            cout << "¡Es super efectivo!" << endl;
        }
        objetivo.recibirDanio(danio);
        return danio;
    }

    const vector<Movimiento>& getMovimientos() const { return movimientos; }

    Movimiento seleccionarMovimientoAleatorio() const {
        static random_device rd;
        static mt19937 gen(rd());
        uniform_int_distribution<> dis(0, movimientos.size() - 1);
        return movimientos[dis(gen)];
    }

    // Modificado: Subida progresiva de nivel
    void ganarCombate() {
        combatesGanados++;
        if (experienciaSuficiente()) {
            subirNivel();
            combatesGanados = 0;  // Reiniciar el contador al subir de nivel
        }
    }

private:
    bool esEfectivo(const string& tipoAtaque, const string& tipoDefensa) const {
        return (tipoAtaque == "Agua" && tipoDefensa == "Fuego") ||
               (tipoAtaque == "Fuego" && tipoDefensa == "Planta") ||
               (tipoAtaque == "Planta" && tipoDefensa == "Agua");
    }

    bool experienciaSuficiente() const {
        return combatesGanados >= nivel;  // Progresión: 1 combate por nivel
    }

        void subirNivel() {
        nivel++;
        ataque += 2;
        defensa += 2;
        saludMaxima += 10;
        salud = saludMaxima;
        cout << nombre << " ha subido al nivel " << nivel << " y se ha curado completamente!" << endl;
        cout << "Salud: " << salud << "/" << saludMaxima << endl;
    }
};


class PokemonAgua : public Pokemon {
public:
    PokemonAgua(string nombre) : Pokemon(nombre) {
        tipo = "Agua";
        agregarMovimiento(Movimiento("Pistola de agua", 6, "Agua"));
        agregarMovimiento(Movimiento("Burbuja", 5, "Agua"));
        agregarMovimiento(Movimiento("Placaje", 5, "Normal"));
        agregarMovimiento(Movimiento("Mordisco", 6, "Normal"));
    }
};

class PokemonFuego : public Pokemon {
public:
    PokemonFuego(string nombre) : Pokemon(nombre) {
        tipo = "Fuego";
        agregarMovimiento(Movimiento("Ascuas", 6, "Fuego"));
        agregarMovimiento(Movimiento("Giro fuego", 5, "Fuego"));
        agregarMovimiento(Movimiento("Arañazo", 5, "Normal"));
        agregarMovimiento(Movimiento("Gruñido", 4, "Normal"));
    }
};

class PokemonPlanta : public Pokemon {
public:
    PokemonPlanta(string nombre) : Pokemon(nombre) {
        tipo = "Planta";
        agregarMovimiento(Movimiento("Látigo cepa", 6, "Planta"));
        agregarMovimiento(Movimiento("Hoja afilada", 5, "Planta"));
        agregarMovimiento(Movimiento("Placaje", 5, "Normal"));
        agregarMovimiento(Movimiento("Gruñido", 4, "Normal"));
    }
};

// Nuevo: Clase para representar una ubicación en el mapa
class Ubicacion {
public:
    string nombre;
    string descripcion;
    bool tieneCombate;
    bool liderDerrotado;  // Nuevo atributo

    Ubicacion(string nombre, string descripcion, bool tieneCombate)
        : nombre(nombre), descripcion(descripcion), tieneCombate(tieneCombate), liderDerrotado(false) {}
};

// Nuevo: Clase para representar el mapa del juego
class Mapa {
private:
    vector<vector<Ubicacion>> grid;
    int filaActual;
    int columnaActual;

public:
    Mapa(int filas, int columnas) : grid(filas, vector<Ubicacion>(columnas, Ubicacion("", "", false))), filaActual(1), columnaActual(1) {}

    void setUbicacion(int fila, int columna, const Ubicacion& ubicacion) {
        if (fila >= 0 && fila < grid.size() && columna >= 0 && columna < grid[0].size()) {
            grid[fila][columna] = ubicacion;
        }
    }

    Ubicacion& getUbicacionActual() {
        return grid[filaActual][columnaActual];
    }

    bool mover(char direccion) {
        int nuevaFila = filaActual;
        int nuevaColumna = columnaActual;

        switch (direccion) {
            case 'N': nuevaFila--; break;
            case 'S': nuevaFila++; break;
            case 'E': nuevaColumna++; break;
            case 'W': nuevaColumna--; break;
            default: return false;
        }

        if (nuevaFila >= 0 && nuevaFila < grid.size() && nuevaColumna >= 0 && nuevaColumna < grid[0].size()) {
            filaActual = nuevaFila;
            columnaActual = nuevaColumna;
            return true;
        }
        return false;
    }
};

// Nuevo: Clase para representar al jugador
class Jugador {
public:
    string nombre;
    vector<Pokemon*> equipo;

    Jugador(string nombre) : nombre(nombre) {}

    void agregarPokemon(Pokemon* pokemon) {
        if (equipo.size() < 6) {
            equipo.push_back(pokemon);
        }
    }

    ~Jugador() {
        for (auto pokemon : equipo) {
            delete pokemon;
        }
    }
};

// Definición de tipos de callbacks
using MovimientoCallback = function<Movimiento(const Pokemon&)>;
using AtaqueCallback = function<void(Pokemon&, Pokemon&, const Movimiento&)>;
using SeleccionPokemonCallback = function<Pokemon*()>;
using MostrarEstadoCallback = function<void(const Pokemon&, const Pokemon&)>;

// Funciones de utilidad
Pokemon* seleccionarPokemonUsuario() {
    cout << "\t\t-----BATALLA POKEMON-----" << endl;
    cout << "\t[1]. Squirtle (Agua)" << endl;
    cout << "\t[2]. Charmander (Fuego)" << endl;
    cout << "\t[3]. Bulbasaur (Planta)" << endl;
    cout << "\tSelecciona tu POKEMON: [ ]\b\b";
    int opcion;
    while (!(cin >> opcion) || opcion < 1 || opcion > 3) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Opción no válida. Por favor, elige 1, 2 o 3:" << endl;
    }

    string nombre;
    cout << "--->Introduce un nombre para tu Pokemon: ";
    cin.ignore();
    getline(cin, nombre);

    switch (opcion) {
        case 1: return new PokemonAgua(nombre);
        case 2: return new PokemonFuego(nombre);
        case 3: return new PokemonPlanta(nombre);
        default: return nullptr;
    }
}

Pokemon* seleccionarPokemonAleatorio(int nivelJugador) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 3);

    Pokemon* enemigo;
    switch (dis(gen)) {
        case 1: enemigo = new PokemonAgua("Squirtle"); break;
        case 2: enemigo = new PokemonFuego("Charmander"); break;
        case 3: enemigo = new PokemonPlanta("Bulbasaur"); break;
        default: enemigo = new PokemonAgua("Squirtle"); break;
    }

    // Ajustar nivel del enemigo al nivel del jugador
    for (int i = 1; i < nivelJugador; i++) {
        enemigo->ganarCombate();  // Subir el nivel del enemigo progresivamente
    }

    return enemigo;
}

void mostrarEstadoCombate(const Pokemon& jugador, const Pokemon& oponente) {
    cout << string(50, '-') << endl;
    cout << jugador.getNombre() << " (Tú) - Salud: " << jugador.getSalud() << "/" << jugador.getSaludMaxima() << endl;
    cout << string(25, '*') << endl;
    cout << oponente.getNombre() << " (Oponente) - Salud: " << oponente.getSalud() << "/" << oponente.getSaludMaxima() << endl;
    cout << string(50, '-') << endl;
}

Movimiento seleccionarMovimientoUsuario(const Pokemon& pokemon) {
    const vector<Movimiento>& movimientos = pokemon.getMovimientos();
    cout << "Selecciona un movimiento:" << endl;
    for (size_t i = 0; i < movimientos.size(); ++i) {
        cout << i + 1 << ". " << movimientos[i].nombre << " (Poder: " << movimientos[i].poder << ")" << endl;
    }
    
    size_t opcion;
    while (!(cin >> opcion) || opcion < 1 || opcion > movimientos.size()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Opción no válida. Por favor, elige un número entre 1 y " << movimientos.size() << ":" << endl;
    }
    
    return movimientos[opcion - 1];
}

// Modificación en la función de combate para subir de nivel al ganar
void IniciarCombate(
    SeleccionPokemonCallback seleccionJugadorCallback,
    SeleccionPokemonCallback seleccionOponenteCallback,
    MovimientoCallback movimientoJugadorCallback,
    MovimientoCallback movimientoOponenteCallback,
    AtaqueCallback ataqueCallback,
    MostrarEstadoCallback mostrarEstadoCallback,
    function<void()> onGanador  // Nuevo: Callback al ganar el combate
) {
    Pokemon* jugador = seleccionJugadorCallback();
    Pokemon* oponente = seleccionOponenteCallback();

    cout << "\n¡Comienza el combate!" << endl;
    cout << jugador->getNombre() << " vs " << oponente->getNombre() << endl;

    while (jugador->getSalud() > 0 && oponente->getSalud() > 0) {
        mostrarEstadoCallback(*jugador, *oponente);
        
        Movimiento movimientoJugador = movimientoJugadorCallback(*jugador);
        ataqueCallback(*jugador, *oponente, movimientoJugador);
        
        if (oponente->getSalud() > 0) {
            Movimiento movimientoOponente = movimientoOponenteCallback(*oponente);
            ataqueCallback(*oponente, *jugador, movimientoOponente);
        }
    }

    mostrarEstadoCallback(*jugador, *oponente);
    if (jugador->getSalud() > 0) {
        cout << jugador->getNombre() << " ha ganado!" << endl;
        onGanador();  // Nuevo: Ejecutar la acción de ganar (como subir de nivel)
    } else {
        cout << oponente->getNombre() << " ha ganado!" << endl;
    }

    delete oponente;
}

void mostrarArteASCII() {
    cout << R"(                                  ,'\
    _.----.        ____         ,'  _\   ___    ___     ____
_,-'       `.     |    |  /`.   \,-'    |   \  /   |   |    \  |`.
\      __    \    '-.  | /   `.  ___    |    \/    |   '-.   \ |  |
 \.    \ \   |  __  |  |/    ,','_  `.  |          | __  |    \|  |
   \    \/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |
    \     ,-'/  /   \    ,'   | \/ / ,`.|         /  /   \  |     |
     \    \ |   \_/  |   `-.  \    `'  /|  |    ||   \_/  | |\    |
      \    \ \      /       `-.`.___,-' |  |\  /| \      /  | |   |
       \    \ `.__,'|  |`-._    `|      |__| \/ |  `.__,'|  | |   |
        \_.-'       |__|    `-._ |              '-.|     '-.| |   |
                                `'                            '-._|)" << endl;
}

// Nuevo: Función para inicializar el mapa
Mapa inicializarMapa() {
    Mapa mapa(3, 3);
    mapa.setUbicacion(0, 0, Ubicacion("Pueblo Paleta", "Tu aventura comienza aquí.", false));
    mapa.setUbicacion(0, 1, Ubicacion("Ruta 1", "Un camino lleno de hierba alta.", true));
    mapa.setUbicacion(0, 2, Ubicacion("Ciudad Verde", "Una ciudad tranquila con un gimnasio.", false));
    mapa.setUbicacion(1, 0, Ubicacion("Laboratorio del Prof. Oak", "Aquí puedes obtener tu primer Pokémon.", false));
    mapa.setUbicacion(1, 1, Ubicacion("Bosque Verde", "Un denso bosque lleno de Pokémon bicho.", true));
    mapa.setUbicacion(1, 2, Ubicacion("Centro Pokémon", "Cura a tus Pokémon aquí.", false));
    mapa.setUbicacion(2, 0, Ubicacion("Ruta 2", "Un camino que lleva al Bosque Verde.", true));
    mapa.setUbicacion(2, 1, Ubicacion("Casa abandonada", "Una casa misteriosa y abandonada.", true));
    mapa.setUbicacion(2, 2, Ubicacion("Gimnasio de Ciudad Verde", "¡Enfréntate al líder de gimnasio!", true));
    return mapa;
}

void despachadorDeEventos(Jugador& jugador, Mapa& mapa) {
    bool jugando = true;

    while (jugando) {
        Ubicacion& ubicacionActual = mapa.getUbicacionActual();
        cout << "\nEstás en: " << ubicacionActual.nombre << endl;
        cout << ubicacionActual.descripcion << endl;

        // Verificar si es un gimnasio con el líder derrotado
        if (ubicacionActual.liderDerrotado) {
            cout << "Ya has derrotado al líder de gimnasio aquí. No puedes entrar de nuevo." << endl;
        } else if (ubicacionActual.tieneCombate && (rand() % 100 < 90)) {  // 30% de probabilidad de combate
            cout << "¡Un Pokémon salvaje apareció!" << endl;

            // Seleccionar Pokémon enemigo aleatorio, escalado al nivel del Pokémon del jugador
            Pokemon* oponente = seleccionarPokemonAleatorio(jugador.equipo[0]->getNivel());

            IniciarCombate(
                [&jugador]() { return jugador.equipo[0]; },
                [oponente]() { return oponente; },
                seleccionarMovimientoUsuario,
                [](const Pokemon& pokemon) { return pokemon.seleccionarMovimientoAleatorio(); },
                [](Pokemon& atacante, Pokemon& objetivo, const Movimiento& movimiento) { atacante.atacar(objetivo, movimiento); },
                mostrarEstadoCombate,
                [&jugador]() { jugador.equipo[0]->ganarCombate(); }  // Ganar combate y subir nivel si es necesario
            );

            // Verificar si es un gimnasio y marcar líder como derrotado
            if (ubicacionActual.nombre.find("Gimnasio") != string::npos) {
                ubicacionActual.liderDerrotado = true;  // Marcar líder de gimnasio derrotado
                cout << "¡Has derrotado al líder del gimnasio en " << ubicacionActual.nombre << "!" << endl;
                continue;
            }
        }

        // Despachar eventos según la entrada del jugador
        cout << "\n¿Qué deseas hacer? (Mover [M], Curar [C], Salir [Q]): ";
        char accion;
        cin >> accion;

        switch (toupper(accion)) {
            case 'M': {
                cout << "\n¿Hacia dónde quieres ir? (N/S/E/W): ";
                char direccion;
                cin >> direccion;

                if (!mapa.mover(toupper(direccion))) {
                    cout << "No puedes ir en esa dirección." << endl;
                }
                break;
            }
            case 'C': {
                cout << "Curando a tus Pokémon en el Centro Pokémon..." << endl;
                for (Pokemon* p : jugador.equipo) {
                    if(p->getSalud() >= 0){
                        p->recibirDanio(-(p->getSaludMaxima()-p->getSalud()));  // Restaurar la salud al máximo
                    }
                }
                break;
            }
            case 'Q': {
                cout << "Gracias por jugar. ¡Hasta la próxima!" << endl;
                jugando = false;
                break;
            }
            default:
                cout << "Acción no válida. Intenta de nuevo." << endl;
                break;
        }
    }
}

// Modificación en la función principal del juego para gestionar correctamente la lógica tras derrotar al líder
void jugarAventura() {
    cout << "\tBienvenido a la aventura Pokémon!" << endl;
    string nombreJugador;
    cout << "\t¿Cuál es tu nombre? ";
    getline(cin, nombreJugador);

    Jugador jugador(nombreJugador);
    jugador.agregarPokemon(seleccionarPokemonUsuario());

    Mapa mapa = inicializarMapa();

    despachadorDeEventos(jugador, mapa);
}

int main() {
    mostrarArteASCII();
    jugarAventura();
    return 0;
}