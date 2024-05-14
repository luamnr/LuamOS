#include "vga.h"
#include "ports.h"

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_BUFFER_ADDRESS 0xB8000

uint16_t *vga_buffer;

void vga_init() {
    // Configurar o modo de vídeo VGA
    // (Código de configuração do modo de vídeo aqui)

    // Inicializar a memória de vídeo
    vga_buffer = (uint16_t *)VGA_BUFFER_ADDRESS;
}

void vga_clear(uint8_t color) {
    uint16_t attribute = color << 12;

    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        vga_buffer[i] = attribute | ' ';
    }
}

void vga_put_char(char c, uint8_t color, int x, int y) {
    uint16_t attribute = color << 12;
    vga_buffer[y * VGA_WIDTH + x] = attribute | c;
}

void vga_draw_rect(uint8_t color, int x, int y, int width, int height) {
    uint16_t attribute = color << 12;
    // Desenhar bordas horizontais
    for (int i = x; i < x + width; i++) {
        vga_buffer[y * VGA_WIDTH + i] = attribute | ' ';
        vga_buffer[(y + height - 1) * VGA_WIDTH + i] = attribute | ' ';
    }
    // Desenhar bordas verticais
    for (int i = y; i < y + height; i++) {
        vga_buffer[i * VGA_WIDTH + x] = attribute | ' ';
        vga_buffer[i * VGA_WIDTH + (x + width - 1)] = attribute | ' ';
    }
}