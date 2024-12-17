#include "Pacman.h"
#include "labyrinth/labyrinth.h"
#include <stdio.h>

// Variabili globali
int pacman_x;
int pacman_y;
int pacman_direction;

extern volatile int game_paused;
extern int labyrinth[HEIGHT][WIDTH];

// Funzione per inizializzare Pac-Man
void pacman_init(void) {
    pacman_x = PACMAN_START_X;
    pacman_y = PACMAN_START_Y;
    pacman_direction = STOP;
    pacman_draw();
}

// Funzione per disegnare Pac-Man
void pacman_draw(void) {
    extern int offset_x;  // Usa l'offset globale definito in labyrinth.c
    extern int offset_y;

    int pixel_x = offset_x + pacman_x * CELL_SIZE + CELL_SIZE / 2; // Centrato sulla cella
    int pixel_y = offset_y + pacman_y * CELL_SIZE + CELL_SIZE / 2;

    draw_pacman_icon(pixel_x, pixel_y, PACMAN_RADIUS, PACMAN_COLOR);
}

// Funzione per cancellare Pac-Man
void pacman_clear(void) {
    extern int offset_x;  // Usa l'offset globale definito in labyrinth.c
    extern int offset_y;

    int pixel_x = offset_x + pacman_x * CELL_SIZE + CELL_SIZE / 2; // Centrato sulla cella
    int pixel_y = offset_y + pacman_y * CELL_SIZE + CELL_SIZE / 2;

    // Cancella Pac-Man ridisegnando il colore dello sfondo
    draw_pacman_icon(pixel_x, pixel_y, PACMAN_RADIUS, EMPTY_COLOR);
}


// Aggiorna il movimento di Pac-Man
void pacman_update(void) {
	
		if (game_paused) {
        return; // Se il gioco è in pausa, non aggiornare Pac-Man
    }	
	
    int next_x = pacman_x;
    int next_y = pacman_y;

    // Calcola la prossima posizione
    switch (pacman_direction) {
        case UP:    next_y--; break;
        case DOWN:  next_y++; break;
        case LEFT:  next_x--; break;
        case RIGHT: next_x++; break;
				case STOP: 	break;
				default: break;
    }
		
    int element = labyrinth[next_y][next_x];
    if (element != 1) {
        pacman_clear();  // Cancella la posizione precedente
        pacman_x = next_x;
        pacman_y = next_y;
        pacman_draw();   // Disegna Pac-Man nella nuova posizione
    } else {
        return; 
    }
}


// Funzione per cambiare la direzione
void pacman_set_direction(int new_direction) {
    pacman_direction = new_direction;
}
