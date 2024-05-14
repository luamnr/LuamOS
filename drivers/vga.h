// drivers/vga.h

#ifndef VGA_H
#define VGA_H

#include <stdint.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_BUFFER_ADDRESS 0xB8000

// Define constantes para cores VGA padrão
#define VGA_COLOR_BLACK         0
#define VGA_COLOR_BLUE          1
#define VGA_COLOR_GREEN         2
#define VGA_COLOR_CYAN          3
#define VGA_COLOR_RED           4
#define VGA_COLOR_MAGENTA       5
#define VGA_COLOR_BROWN         6
#define VGA_COLOR_LIGHT_GRAY    7
#define VGA_COLOR_DARK_GRAY     8
#define VGA_COLOR_LIGHT_BLUE    9
#define VGA_COLOR_LIGHT_GREEN   10
#define VGA_COLOR_LIGHT_CYAN    11
#define VGA_COLOR_LIGHT_RED     12
#define VGA_COLOR_LIGHT_MAGENTA 13
#define VGA_COLOR_YELLOW        14
#define VGA_COLOR_WHITE         15

// Função para inicializar o driver VGA
void vga_init();

// Função para limpar a tela com uma cor específica
void vga_clear(uint8_t color);

// Função para imprimir um caractere na posição específica
void vga_put_char(char c, uint8_t color, int x, int y);

// Função para desenhar um retângulo na tela
void vga_draw_rect(uint8_t color, int x, int y, int width, int height);

#endif
