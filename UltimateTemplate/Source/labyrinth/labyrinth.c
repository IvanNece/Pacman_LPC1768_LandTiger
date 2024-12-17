#include <stdio.h>
#include "math.h"
#include "labyrinth.h"
#include "GLCD/GLCD.h"
#include "RIT/RIT.h"

int score = 0;
int countdown = 60;  // Countdown iniziale a 60 secondi
int lives = START_LIVES;

int offset_x = (240 - WIDTH * CELL_SIZE) / 2;    // Offset orizzontale centrato
int offset_y = (320 - HEIGHT * CELL_SIZE) / 2;   // Offset verticale centrato


//int return_element(int x, int y) {
    //if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
  //      int element = labyrinth[y][x];
    //    return element;
    //}
    //return -1;
//}



// Funzione per disegnare il labirinto
void draw_labyrinth(int labyrinth[HEIGHT][WIDTH]) {
    int x, y;  // Coordinate pixel
    int i, j;  // Iteratori sulla matrice
		int px, py;


    for (i = 0; i < HEIGHT; i++) {       // Itera sulle righe
        for (j = 0; j < WIDTH; j++) {    // Itera sulle colonne
						x = offset_x + j * CELL_SIZE; // Posizione X della cella centrata
            y = offset_y + i * CELL_SIZE; // Posizione Y della cella centrata
            
            switch (labyrinth[i][j]) {
                case WALL:
                    // Disegna il muro come un blocco pieno
                    for (px = 0; px < CELL_SIZE; px++) {
                        for (py = 0; py < CELL_SIZE; py++) {
                            LCD_SetPoint(x + px, y + py, WALL_COLOR);
                        }
                    }
                    break;

                case STANDARD_PILL:
                    // Disegna la pillola standard come un punto centrale
                    LCD_SetPoint(x + CELL_SIZE / 2, y + CELL_SIZE / 2, PILL_COLOR);
                    break;

                case POWER_PILL:
                    // Disegna la power pill come un quadrato centrale pi� grande
                    for (px = -1; px <= 1; px++) {
                        for (py = -1; py <= 1; py++) {
                            LCD_SetPoint(x + CELL_SIZE / 2 + px, y + CELL_SIZE / 2 + py, POWER_PILL_COLOR);
                        }
                    }
                    break;

                default:
                    // Disegna lo sfondo nero per le celle vuote
                    for (px = 0; px < CELL_SIZE; px++) {
                        for (py = 0; py < CELL_SIZE; py++) {
                            LCD_SetPoint(x + px, y + py, EMPTY_COLOR);
                        }
                    }
                    break;
            }
        }
    }
}


void draw_pacman_icon(int x, int y, int radius, uint16_t color) {
    int i, j;

    // Disegna il cerchio completo
    for (i = -radius; i <= radius; i++) {
        for (j = -radius; j <= radius; j++) {
            if (i * i + j * j <= radius * radius) {  // Condizione per rimanere nel cerchio
                float angle = atan2(j, i) * 180 / PI;  // Calcola l'angolo corrente
                if (angle < 220 && angle > 140) {  // Cancella la fetta (bocca)
                    continue;
                }
                LCD_SetPoint(x + i, y + j, color);  // Disegna il pixel
            }
        }
    }
}


void display_game_info(void) {
		int i;
	
    // Pulisci la parte superiore e inferiore per le informazioni
    LCD_Clear(BACKGROUND_COLOR);

    // Mostra il countdown timer in alto a sinistra
    GUI_Text(10, 10, (uint8_t *)"TIMER:", TEXT_COLOR, BACKGROUND_COLOR);
    char timer_str[10];
    sprintf(timer_str, "%02d", countdown);
    GUI_Text(70, 10, (uint8_t *)timer_str, TEXT_COLOR, BACKGROUND_COLOR);

    // Mostra lo score in alto a destra
    GUI_Text(140, 10, (uint8_t *)"SCORE:", TEXT_COLOR, BACKGROUND_COLOR);
    char score_str[10];
    sprintf(score_str, "%d", 0);
    GUI_Text(210, 10, (uint8_t *)score_str, TEXT_COLOR, BACKGROUND_COLOR);

    // Mostra le vite rimanenti in basso
    GUI_Text(10, 300, (uint8_t *)"LIVES:", TEXT_COLOR, BACKGROUND_COLOR);
    for (i = 0; i < lives; i++) {
        // Disegna l'icona Pac-Man per ogni vita
        draw_pacman_icon(70 + (i * 20), 310, 8, Yellow);  // Posizione centrata, raggio 8
    }
}

void display_timer(void) {
    char timer_str[10]; // Buffer per la stringa
    sprintf(timer_str, "%02d", countdown); // Converte il valore in stringa

    // Cancella la vecchia scritta e mostra il nuovo countdown
    GUI_Text(70, 10, (uint8_t *)"    ", TEXT_COLOR, BACKGROUND_COLOR); // Pulisce l'area
    GUI_Text(70, 10, (uint8_t *)timer_str, TEXT_COLOR, BACKGROUND_COLOR);
}

void display_score(void) {
    char score_str[10];
    sprintf(score_str, "%d", score); // Converte il punteggio in stringa

    // Pulisce la vecchia area dello score
    LCD_ClearWindow(210, 10, 50, 15, BACKGROUND_COLOR);

    // Mostra lo score aggiornato
    //GUI_Text(210, 10, (uint8_t *)"SCORE:", TEXT_COLOR, BACKGROUND_COLOR);
		disable_RIT();
    GUI_Text(210, 10, (uint8_t *)score_str, TEXT_COLOR, BACKGROUND_COLOR);
		enable_RIT();
}
