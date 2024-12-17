#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <stdint.h>

#define EMPTY 0
#define WALL 1
#define STANDARD_PILL 2
#define POWER_PILL 3

#define WIDTH 28 // Numero di celle in larghezza
#define HEIGHT 31 // Numero di celle in altezza

// Definizioni
#define CELL_SIZE 8
#define WALL_COLOR Blue
#define PILL_COLOR Yellow
#define POWER_PILL_COLOR Red
#define EMPTY_COLOR Black

#define WIDTH 28 // Numero di celle in larghezza
#define HEIGHT 31 // Numero di celle in altezza

#define TEXT_COLOR White
#define BACKGROUND_COLOR Black
#define START_LIVES 3
#define PI 3.14159

// Dichiarazione del labirinto
//extern int labyrinth[HEIGHT][WIDTH];

// Prototipi delle funzioni

int return_element(int x, int y);
void draw_labyrinth(int labyrinth[HEIGHT][WIDTH]);
void draw_pacman_icon(int x, int y, int radius, uint16_t color);
void display_game_info(void);

#endif
