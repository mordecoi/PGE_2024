#include <ncurses.h>
#include <unistd.h> // Para usar usleep

void drawPixel(int x, int y, int colorPair) {
    attron(COLOR_PAIR(colorPair));
    mvaddch(y, x, ' ' | A_REVERSE);
    attroff(COLOR_PAIR(colorPair));
}

int main() {
    // Inicializar ncurses
    initscr();
    start_color();
    noecho();
    cbreak();
    timeout(0); // No bloquear en getch()

    // Definir pares de colores
    init_pair(1, COLOR_GREEN, COLOR_GREEN);

    // Posición inicial del personaje
    int posX = COLS / 2;
    int posY = LINES / 2;

    while (true) {
        // Limpiar la pantalla
        clear();

        // Mostrar texto en la primera línea
        mvprintw(16, 16, "Usa WASD para mover, Q para salir");

        // Detectar teclas presionadas y actualizar la posición del personaje
        int ch = getch();
        switch (ch) {
            case 'w': // Mover hacia arriba
                posY = (posY > 1) ? posY - 1 : posY; // Evitar la primera línea
                break;
            case 's': // Mover hacia abajo
                posY = (posY < LINES - 1) ? posY + 1 : posY;
                break;
            case 'a': // Mover hacia la izquierda
                posX = (posX > 0) ? posX - 1 : posX;
                break;
            case 'd': // Mover hacia la derecha
                posX = (posX < COLS - 1) ? posX + 1 : posX;
                break;
            case 'q': // Salir del bucle
                endwin();
                return 0;
        }

        // Dibujar el personaje en la nueva posición
        drawPixel(posX, posY, 1);

        // Refrescar la pantalla para mostrar los cambios
        refresh();

        // Esperar un poco antes de la siguiente actualización
        usleep(100000); // 100 ms
    }

    // Finalizar ncurses
    endwin();

    return 0;
}