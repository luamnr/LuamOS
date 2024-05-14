#include "../cpu/idt.h"
#include "../cpu/isr.h"
#include "../cpu/timer.h"
#include "../drivers/display.h"
#include "../drivers/keyboard.h"
#include "../drivers/vga.h"

#include "util.h"
#include "mem.h"


void* alloc(int n) {
    int *ptr = (int *) mem_alloc(n * sizeof(int));
    if (ptr == NULL_POINTER) {
        print_string("Memory not allocated.\n");
    } else {
        // Get the elements of the array
        for (int i = 0; i < n; ++i) {
//            ptr[i] = i + 1; // shorthand for *(ptr + i)
        }

        for (int i = 0; i < n; ++i) {
//            char str[256];
//            int_to_string(ptr[i], str);
//            print_string(str);
        }
//        print_nl();
    }
    return ptr;
}

void start_kernel() {
    clear_screen();
    print_string("Installing interrupt service routines (ISRs).\n");
    isr_install();

    print_string("Enabling external interrupts.\n");
    asm volatile("sti");

    print_string("Initializing keyboard (IRQ 1).\n");
    init_keyboard();

    print_string("Initializing dynamic memory.\n");
    init_dynamic_mem();

    print_string("init_dynamic_mem()\n");
    clear_screen();
    
    print_string("Welcome to the LuamOS!");


    print_nl();
    print_string("> ");
}

void execute_command(char *input) {

    if (compare_string(input, "EXIT") == 0) {
        print_string("Stopping the CPU. Bye!\n");
        asm volatile("hlt");
    }
    
    else if (compare_string(input, "") == 0) {
        print_string("\n> ");
    }
    
    else if (compare_string(input, "TEST") == 0) {
        vga_init();
        vga_draw_rect(VGA_COLOR_LIGHT_RED, 10, 10, 20, 10);
        // x y w h
        vga_draw_rect(VGA_COLOR_LIGHT_RED, 40, 10, 1, 10);

        // vga_clear();
        
        
    }

    else if (compare_string(input, "MEM") == 0){
        print_dynamic_mem();
    }
    

    else if (compare_string(input, "CLEAR") == 0) {
        clear_screen();
        print_string("> ");
    }

    else if (compare_string(input, "HELP") == 0) {
        print_string("Available commands:\n");
        print_string("  - EXIT: Stop the CPU\n");
        print_string("  - CLEAR: Clear the screen\n");
        print_string("  - HELP: Display this help message\n");
        print_string("> ");
    }

    else {
        print_string("Unknown command: ");
        print_string(input);
        print_string("\n> ");
    }
}
