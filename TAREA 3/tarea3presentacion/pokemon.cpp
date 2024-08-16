// pokemon.cpp
#include "pokemon.h"

Movimiento::Movimiento(string nombre, int poder, string tipo)
    : nombre(nombre), poder(poder), tipo(tipo) {}

Pokemon::Pokemon(string nombre)
    : nombre(nombre), tipo("Normal"), nivel(1), saludMaxima(20), salud(20), ataque(5), defensa(5), combatesGanados(0)
{
    cout << nombre << " ha entrado al combate" << endl;
}

Pokemon::~Pokemon() {}

string Pokemon::getNombre() const { return nombre; }
string Pokemon::getTipo() const { return tipo; }
int Pokemon::getSalud() const { return salud; }
int Pokemon::getSaludMaxima() const { return saludMaxima; }
int Pokemon::getNivel() const { return nivel; }

void Pokemon::recibirDanio(int danio)
{
    salud = max(0, salud - danio);
    cout << nombre << " ha recibido " << danio << " puntos de daño" << endl;
    if (salud == 0)
    {
        cout << nombre << " se ha debilitado... Fuera de combate" << endl;
    }
    else
    {
        cout << nombre << " tiene " << salud << "/" << saludMaxima << " puntos de vida restantes" << endl
             << endl;
    }
}

void Pokemon::agregarMovimiento(const Movimiento &movimiento)
{
    if (movimientos.size() < 4)
    {
        movimientos.push_back(movimiento);
    }
}

int Pokemon::atacar(Pokemon &objetivo, const Movimiento &movimiento)
{
    int danio = movimiento.poder + ataque;
    cout << nombre << " usa " << movimiento.nombre << "!" << endl;
    if (movimiento.tipo == objetivo.getTipo())
    {
        danio /= 2;
        cout << "No es muy efectivo..." << endl;
    }
    else if (esEfectivo(movimiento.tipo, objetivo.getTipo()))
    {
        danio *= 2;
        cout << "¡Es super efectivo!" << endl;
    }
    objetivo.recibirDanio(danio);
    return danio;
}

const vector<Movimiento> &Pokemon::getMovimientos() const { return movimientos; }

Movimiento Pokemon::seleccionarMovimientoAleatorio() const
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(0, movimientos.size() - 1);
    return movimientos[dis(gen)];
}

void Pokemon::ganarCombate()
{
    combatesGanados++;
    if (experienciaSuficiente())
    {
        subirNivel();
        combatesGanados = 0;
    }
}

bool Pokemon::esEfectivo(const string &tipoAtaque, const string &tipoDefensa) const
{
    return (tipoAtaque == "Agua" && tipoDefensa == "Fuego") ||
           (tipoAtaque == "Fuego" && tipoDefensa == "Planta") ||
           (tipoAtaque == "Planta" && tipoDefensa == "Agua");
}

bool Pokemon::experienciaSuficiente() const
{
    return combatesGanados >= nivel;
}

void Pokemon::subirNivel()
{
    nivel++;
    ataque += 2;
    defensa += 2;
    saludMaxima += 10;
    salud = saludMaxima;
    cout << nombre << " ha subido al nivel " << nivel << " y se ha curado completamente!" << endl;
    cout << "Salud: " << salud << "/" << saludMaxima << endl;
}

PokemonAgua::PokemonAgua(string nombre) : Pokemon(nombre)
{
    tipo = "Agua";
    agregarMovimiento(Movimiento("Pistola de agua", 6, "Agua"));
    agregarMovimiento(Movimiento("Burbuja", 5, "Agua"));
    agregarMovimiento(Movimiento("Placaje", 5, "Normal"));
    agregarMovimiento(Movimiento("Mordisco", 6, "Normal"));
}

PokemonFuego::PokemonFuego(string nombre) : Pokemon(nombre)
{
    tipo = "Fuego";
    agregarMovimiento(Movimiento("Ascuas", 6, "Fuego"));
    agregarMovimiento(Movimiento("Giro fuego", 5, "Fuego"));
    agregarMovimiento(Movimiento("Arañazo", 5, "Normal"));
    agregarMovimiento(Movimiento("Gruñido", 4, "Normal"));
}

PokemonPlanta::PokemonPlanta(string nombre) : Pokemon(nombre)
{
    tipo = "Planta";
    agregarMovimiento(Movimiento("Látigo cepa", 6, "Planta"));
    agregarMovimiento(Movimiento("Hoja afilada", 5, "Planta"));
    agregarMovimiento(Movimiento("Placaje", 5, "Normal"));
    agregarMovimiento(Movimiento("Gruñido", 4, "Normal"));
}

Ubicacion::Ubicacion(string nombre, string descripcion, bool tieneCombate)
    : nombre(nombre), descripcion(descripcion), tieneCombate(tieneCombate), liderDerrotado(false) {}

Mapa::Mapa(int filas, int columnas)
    : grid(filas, vector<Ubicacion>(columnas, Ubicacion("", "", false))), filaActual(0), columnaActual(0) {}

void Mapa::setUbicacion(int fila, int columna, const Ubicacion &ubicacion)
{
    if (fila >= 0 && fila < grid.size() && columna >= 0 && columna < grid[0].size())
    {
        grid[fila][columna] = ubicacion;
    }
}

Ubicacion &Mapa::getUbicacionActual()
{
    return grid[filaActual][columnaActual];
}

bool Mapa::mover(char direccion)
{
    int nuevaFila = filaActual;
    int nuevaColumna = columnaActual;

    switch (direccion)
    {
    case 'N':
        nuevaFila--;
        break;
    case 'S':
        nuevaFila++;
        break;
    case 'E':
        nuevaColumna++;
        break;
    case 'W':
        nuevaColumna--;
        break;
    default:
        return false;
    }

    if (nuevaFila >= 0 && nuevaFila < grid.size() && nuevaColumna >= 0 && nuevaColumna < grid[0].size())
    {
        filaActual = nuevaFila;
        columnaActual = nuevaColumna;
        return true;
    }
    return false;
}

void Mapa::mostrarMapa()
{
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[i].size(); ++j)
        {
            if (i == filaActual && j == columnaActual)
            {
                cout << "[P] ";
            }
            else
            {
                cout << "[ ] ";
            }
        }
        cout << endl;
    }
}

Jugador::Jugador(string nombre) : nombre(nombre) {}

void Jugador::agregarPokemon(Pokemon *pokemon)
{
    if (equipo.size() < 6)
    {
        equipo.push_back(pokemon);
    }
}

bool Jugador::tienePokemonDisponibles() const
{
    return !equipo.empty();
}

void Jugador::enviarPokemonAlCentro(Pokemon *pokemon)
{
    auto it = find(equipo.begin(), equipo.end(), pokemon);
    if (it != equipo.end())
    {
        centroPokemon.push_back(pokemon);
        equipo.erase(it);
        cout << "Pokémon enviado al Centro Pokémon: " << pokemon->getNombre() << endl;
    }
    else
    {
        cout << "El Pokémon no está en el equipo." << endl;
    }
}

void Jugador::recogerPokemonDelCentro()
{
    if (centroPokemon.empty())
    {
        cout << "No hay Pokémon en el Centro Pokémon." << endl;
        return;
    }
    for (Pokemon *pokemon : centroPokemon)
    {
        pokemon->recibirDanio(-(pokemon->getSaludMaxima() - pokemon->getSalud()));
        agregarPokemon(pokemon);
        cout << "Pokémon recogido del Centro Pokémon: " << pokemon->getNombre() << endl;
    }
    centroPokemon.clear();
}

Jugador::~Jugador()
{
    for (auto pokemon : equipo)
    {
        if (pokemon)
            delete pokemon;
    }
    equipo.clear();
    for (auto pokemon : centroPokemon)
    {
        if (pokemon)
            delete pokemon;
    }
    centroPokemon.clear();
}

void mostrarArtePokemon(const string &pokemon)
{
    if (pokemon == "Charmander")
    {
        cout << R"(
              _.--""`-..
            ,'          `.
          ,'          __  `.
         /|          " __   \
        , |           / |.   .
        |,'          !_.'|   |
      ,'             '   |   |
     /              |`--'|   |
    |                `---'   |
     .   ,                   |                       ,".
      ._     '           _'  |                    , ' \ `
  `.. `.`-...___,...---""    |       __,.        ,`"   L,|
  |, `- .`._        _,-,.'   .  __.-'-. /        .   ,    \
-:..     `. `-..--_.,.<       `"      / `.        `-/ |   .
  `,         """"'     `.              ,'         |   |  ',,
    `.      '            '            /          '    |'. |/
      `.   |              \       _,-'           |       ''
        `._'               \   '"\                .      |
           |                '     \                `._  ,'
           |                 '     \                 .'|
           |                 .      \                | |
           |                 |       L              ,' |
           `                 |       |             /   '
            \                |       |           ,'   /
          ,' \               |  _.._ ,-..___,..-'    ,'
         /     .             .      `!             ,j'
        /       `.          /        .           .'/
       .          `.       /         |        _.'.'
        `.          7`'---'          |------"'_.'
       _,.`,_     _'                ,''-----"'
   _,-_    '       `.     .'      ,\
   -" /`.         _,'     | _  _  _.|
    ""--'---"""""'        `' '! |! /
                            `" " -' mh
        )" << endl;
        cout << "\tCharmander, te elijo a tí!" << endl;
    }
    else if (pokemon == "Squirtle")
    {
        cout << R"(
               _,........__
            ,-'            "`-.
          ,'                   `-.
        ,'                        \
      ,'                           .
      .'\               ,"".       `
     ._.'|             / |  `       \
     |   |            `-.'  ||       `.
     |   |            '-._,'||       | \
     .`.,'             `..,'.'       , |`-.
     l                       .'`.  _/  |   `.
     `-.._'-   ,          _ _'   -" \  .     `
`."""""'-.`-...,---------','         `. `....__.
.'        `"-..___      __,'\          \  \     \
\_ .          |   `""""'    `.           . \     \
  `.          |              `.          |  .     L
    `.        |`--...________.'.        j   |     |
      `._    .'      |          `.     .|   ,     |
         `--,\       .            `7""' |  ,      |
            ` `      `            /     |  |      |    _,-'"""`-.
             \ `.     .          /      |  '      |  ,'          `.
              \  v.__  .        '       .   \    /| /              \
               \/    `""\"""""""`.       \   \  /.''                |
                `        .        `._ ___,j.  `/ .-       ,---.     |
                ,`-.      \         ."     `.  |/        j     `    |
               /    `.     \       /         \ /         |     /    j
              |       `-.   7-.._ .          |"          '         /
              |          `./_    `|          |            .     _,'
              `.           / `----|          |-............`---'
                \          \      |          |
               ,'           )     `.         |
                7____,,..--'      /          |
                                  `---.__,--.'mh
        )" << endl;
        cout << "\tSquirtle, te elijo a tí!" << endl;
    }
    else if (pokemon == "Bulbasaur")
    {
        cout << R"(
                                           /
                        _,.------....___,.' ',.-.
                     ,-'          _,.--"        |
                   ,'         _.-'              .
                  /   ,     ,'                   `
                 .   /     /                     ``.
                 |  |     .                       \.\
       ____      |___._.  |       __               \ `.
     .'    `---""       ``"-.--"'`  \               .  \
    .  ,            __               `              |   .
    `,'         ,-"'  .               \             |    L
   ,'          '    _.'                -._          /    |
  ,`-.    ,".   `--'                      >.      ,'     |
 . .'\'   `-'       __    ,  ,-.         /  `.__.-      ,'
 ||:, .           ,'  ;  /  / \ `        `.    .      .'/
 j|:D  \          `--'  ' ,'_  . .         `.__, \   , /
/ L:_  |                 .  "' :_;                `.'.'
.    ""'                  """""'                    V
 `.                                 .    `.   _,..  `
   `,_   .    .                _,-'/    .. `,'   __  `
    ) \`._        ___....----"'  ,'   .'  \ |   '  \  .
   /   `. "`-.--"'         _,' ,'     `---' |    `./  |
  .   _  `""'--.._____..--"   ,             '         |
  | ." `. `-.                /-.           /          ,
  | `._.'    `,_            ;  /         ,'          .
 .'          /| `-.        . ,'         ,           ,
 '-.__ __ _,','    '`-..___;-...__   ,.'\ ____.___.'
 `"^--'..'   '-`-^-'"--    `-^-'`.''"""""`.,^.`.--' mh
        )" << endl;
        cout << "\tBulbasaur, te elijo a tí!" << endl;
    }
    else
    {
        cout << "\tPokémon no reconocido." << endl;
    }
}

Pokemon *seleccionarPokemonUsuario()
{
    cout << "\t\t-----BATALLA POKEMON-----" << endl;
    cout << "\t[1]. Squirtle (Agua)" << endl;
    cout << "\t[2]. Charmander (Fuego)" << endl;
    cout << "\t[3]. Bulbasaur (Planta)" << endl;
    cout << "\tSelecciona tu POKEMON: [ ]\b\b";
    int opcion;
    while (!(cin >> opcion) || opcion < 1 || opcion > 3)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\tOpción no válida. Por favor, elige 1, 2 o 3:" << endl;
    }

    string nombrePokemon;
    switch (opcion)
    {
    case 1:
        nombrePokemon = "Squirtle";
        break;
    case 2:
        nombrePokemon = "Charmander";
        break;
    case 3:
        nombrePokemon = "Bulbasaur";
        break;
    default:
        return nullptr;
    }

    mostrarArtePokemon(nombrePokemon);

    string nombre;
    cout << "---->Introduce un nombre para tu Pokemon: ";
    cin.ignore();
    getline(cin, nombre);

    switch (opcion)
    {
    case 1:
        return new PokemonAgua(nombre);
    case 2:
        return new PokemonFuego(nombre);
    case 3:
        return new PokemonPlanta(nombre);
    default:
        return nullptr;
    }
}

Pokemon *seleccionarPokemonAleatorio(int nivelJugador)
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 3);

    Pokemon *enemigo;
    switch (dis(gen))
    {
    case 1:
        enemigo = new PokemonAgua("Squirtle");
        break;
    case 2:
        enemigo = new PokemonFuego("Charmander");
        break;
    case 3:
        enemigo = new PokemonPlanta("Bulbasaur");
        break;
    default:
        enemigo = new PokemonAgua("Squirtle");
        break;
    }

    for (int i = 1; i < nivelJugador; i++)
    {
        enemigo->ganarCombate();
    }

    return enemigo;
}

void mostrarEstadoCombate(const Pokemon &jugador, const Pokemon &oponente)
{
    cout << string(50, '-') << endl;
    cout << jugador.getNombre() << "\t(Tú) - Salud: " << jugador.getSalud() << "/" << jugador.getSaludMaxima() << endl;
    cout << string(25, '*') << endl;
    cout << oponente.getNombre() << "\t(Oponente) - Salud: " << oponente.getSalud() << "/" << oponente.getSaludMaxima() << endl;
    cout << string(50, '-') << endl;
}

Movimiento seleccionarMovimientoUsuario(const Pokemon &pokemon)
{
    const vector<Movimiento> &movimientos = pokemon.getMovimientos();
    cout << "\tSelecciona un movimiento:" << endl;
    for (size_t i = 0; i < movimientos.size(); ++i)
    {
        cout << i + 1 << ". " << movimientos[i].nombre << " (Poder: " << movimientos[i].poder << ")" << endl;
    }

    size_t opcion;
    while (!(cin >> opcion) || opcion < 1 || opcion > movimientos.size())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\tOpción no válida. Por favor, elige un número entre 1 y " << movimientos.size() << ":" << endl;
    }

    return movimientos[opcion - 1];
}

bool IniciarCombate(
    function<Pokemon *()> seleccionJugadorCallback,
    function<Pokemon *()> seleccionOponenteCallback,
    function<Movimiento(const Pokemon &)> movimientoJugadorCallback,
    function<Movimiento(const Pokemon &)> movimientoOponenteCallback,
    function<void(Pokemon &, Pokemon &, const Movimiento &)> ataqueCallback,
    function<void(const Pokemon &, const Pokemon &)> mostrarEstadoCallback,
    function<void()> onGanador,
    function<void()> onPerdedor)
{
    Pokemon *jugador = seleccionJugadorCallback();
    Pokemon *oponente = seleccionOponenteCallback();

    cout << "\n¡Comienza el combate!" << endl;
    cout << jugador->getNombre() << " vs " << oponente->getNombre() << endl;

    while (jugador->getSalud() > 0 && oponente->getSalud() > 0)
    {
        mostrarEstadoCallback(*jugador, *oponente);

        Movimiento movimientoJugador = movimientoJugadorCallback(*jugador);
        ataqueCallback(*jugador, *oponente, movimientoJugador);

        if (oponente->getSalud() > 0)
        {
            Movimiento movimientoOponente = movimientoOponenteCallback(*oponente);
            ataqueCallback(*oponente, *jugador, movimientoOponente);
        }
    }

    mostrarEstadoCallback(*jugador, *oponente);
    bool gano = (jugador->getSalud() > 0);
    if (gano)
    {
        cout << jugador->getNombre() << " ha ganado!" << endl;
        onGanador();
    }
    else
    {
        cout << oponente->getNombre() << " ha ganado!" << endl;
        onPerdedor();
    }

    delete oponente;
    return gano;
}

void mostrarArteASCII()
{
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
                                `'                            '-._|)"
         << endl;
}

Mapa inicializarMapa()
{
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

    mapa.mostrarMapa();
    return mapa;
}

void despachadorDeEventos(Jugador &jugador, Mapa &mapa)
{
    bool jugando = true;

    while (jugando)
    {
        Ubicacion &ubicacionActual = mapa.getUbicacionActual();
        cout << "\nEstás en: " << ubicacionActual.nombre << endl;
        cout << ubicacionActual.descripcion << endl;

        if (ubicacionActual.liderDerrotado)
        {
            cout << "Ya has derrotado al líder de gimnasio aquí. No puedes entrar de nuevo." << endl;
        }
        else if (ubicacionActual.tieneCombate && (rand() % 100 < 90))
        {
            if (!jugador.tienePokemonDisponibles())
            {
                cout << "No tienes Pokémon disponibles para combatir. Debes recogerlos del Centro Pokémon." << endl;
                continue;
            }
            cout << "¡Un Pokémon salvaje apareció!" << endl;

            Pokemon *oponente = seleccionarPokemonAleatorio(jugador.equipo[0]->getNivel());

            bool ganoCombate = IniciarCombate(
                [&jugador]()
                { return jugador.equipo[0]; },
                [oponente]()
                { return oponente; },
                seleccionarMovimientoUsuario,
                [](const Pokemon &pokemon)
                { return pokemon.seleccionarMovimientoAleatorio(); },
                [](Pokemon &atacante, Pokemon &objetivo, const Movimiento &movimiento)
                { atacante.atacar(objetivo, movimiento); },
                mostrarEstadoCombate,
                [&jugador]()
                { jugador.equipo[0]->ganarCombate(); },
                [&jugador]()
                { jugador.enviarPokemonAlCentro(jugador.equipo[0]); });

            if (ubicacionActual.nombre.find("Gimnasio") != string::npos && ganoCombate)
            {
                ubicacionActual.liderDerrotado = true;
                cout << "¡Has derrotado al líder del gimnasio en " << ubicacionActual.nombre << "!" << endl;
                continue;
            }
            else if (ubicacionActual.nombre.find("Gimnasio") != string::npos && !ganoCombate)
            {
                cout << "No has derrotado al líder del gimnasio. Intenta de nuevo cuando estés más preparado." << endl;
            }
        }

        cout << "\n¿Qué deseas hacer? (Mover [M], Curar [C], Recoger Pokémon [R],Salir [Q]): ";
        char accion;
        cin >> accion;

        switch (toupper(accion))
        {
        case 'M':
        {
            cout << "\n¿Hacia dónde quieres ir? (N/S/E/W): ";
            char direccion;
            cin >> direccion;

            if (!mapa.mover(toupper(direccion)))
            {
                cout << "No puedes ir en esa dirección." << endl;
            }
            else
            {
                mapa.mostrarMapa();
            }
            break;
        }
        case 'C':
        {
            for (Pokemon *p : jugador.equipo)
            {
                if (p->getSalud() == 0)
                {
                    cout << "El Pokémon se encuentra debilitado..." << endl;
                    cout << "Se debe de ir a buscar al Centro Pokémon" << endl;
                }
                else
                {
                    cout << "Curando a tus Pokémon en el Centro Pokémon..." << endl;
                    p->recibirDanio(-(p->getSaludMaxima() - p->getSalud()));
                }
            }
            break;
        }
        case 'R':
        {
            cout << "Recogiendo a tus Pokémon del Centro Pokémon..." << endl;
            jugador.recogerPokemonDelCentro();
            break;
        }
        case 'Q':
        {
            cout << "Gracias por jugar. ¡Hasta la próxima!" << endl;
            jugando = false;
            break;
        }
        default:
            cout << "Acción no válida. Intenta de nuevo." << endl;
        }
    }
}
