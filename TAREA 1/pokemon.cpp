// ACTIVIDAD N°3: DESARROLLO DE UN VIDEOJUEGO
// IDEA DE JUEGO: BATALLA POKEMON
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <limits>

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
    vector<Movimiento> movimientos;

public:
    Pokemon(string nombre) : nombre(nombre), tipo("Normal"), nivel(1), saludMaxima(20), salud(20), ataque(5), defensa(5) {
        cout << nombre << " ha entrado al combate" << endl;
    }

    virtual ~Pokemon() {}

    string getNombre() const { return nombre; }
    string getTipo() const { return tipo; }
    int getSalud() const { return salud; }
    int getSaludMaxima() const { return saludMaxima; }

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

private:
    bool esEfectivo(const string& tipoAtaque, const string& tipoDefensa) const {
        return (tipoAtaque == "Agua" && tipoDefensa == "Fuego") ||
               (tipoAtaque == "Fuego" && tipoDefensa == "Planta") ||
               (tipoAtaque == "Planta" && tipoDefensa == "Agua");
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

Pokemon* seleccionarPokemon() {
    cout << "\t\t-----BATALLA POKEMON2-----" << endl;
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
        default: return nullptr; // Nunca debería llegar acá
    }
}

Pokemon* seleccionarOponente() {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 3);

    switch (dis(gen)) {
        case 1: return new PokemonAgua("Squirtle");
        case 2: return new PokemonFuego("Charmander");
        case 3: return new PokemonPlanta("Bulbasaur");
        default: return nullptr; // Nunca debería llegar acá
    }
}

void mostrarEstadoCombate(const Pokemon& jugador, const Pokemon& oponente) {
    cout << string(50, '-') << endl;
    cout << jugador.getNombre() << " (Tú) - Salud: " << jugador.getSalud() << "/20" << endl;
    cout << string(jugador.getSalud(), '*') << endl;
    cout << oponente.getNombre() << " (Oponente) - Salud: " << oponente.getSalud() << "/20" << endl;
    cout << string(int(oponente.getSalud()), '*') << endl;
    cout << string(50, '-') << endl;
}

Movimiento seleccionarMovimiento(const Pokemon& pokemon) {
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

void IniciarCombate() {
    Pokemon* jugador = seleccionarPokemon();
    Pokemon* oponente = seleccionarOponente();

    cout << "\n¡Comienza el combate!" << endl;
    cout << jugador->getNombre() << " vs " << oponente->getNombre() << endl;

    while (jugador->getSalud() > 0 && oponente->getSalud() > 0) {
        mostrarEstadoCombate(*jugador, *oponente);
        
        Movimiento movimientoJugador = seleccionarMovimiento(*jugador);
        jugador->atacar(*oponente, movimientoJugador);
        
        if (oponente->getSalud() > 0) {
            Movimiento movimientoOponente = oponente->seleccionarMovimientoAleatorio();
            oponente->atacar(*jugador, movimientoOponente);
        }
    }

    mostrarEstadoCombate(*jugador, *oponente);
    cout << (jugador->getSalud() > 0 ? jugador->getNombre() : oponente->getNombre()) << " ha ganado!" << endl;

    delete jugador;
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

int main() {
    mostrarArteASCII();
    IniciarCombate();
    return 0;
}