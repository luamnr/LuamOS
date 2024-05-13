# $@ = target file
# $< = first dependency
# $^ = all dependencies

# detect all .o files based on their .c source
C_SOURCES = $(wildcard kernel/*.c drivers/*.c)
HEADERS = $(wildcard kernel/*.h  drivers/*.h)
OBJ_FILES = ""

# First rule is the one executed when no parameters are fed to the Makefile
all: run

# gcc -fno-pie -m32 -ffreestanding -c kernel/ports.c -o ports.o
# gcc -fno-pie -m32 -ffreestanding -c kernel/util.c -o util.o
# gcc -fno-pie -m32 -ffreestanding -c drivers/display.c -o kernel.o
kernel.o: kernel/kernel.c
	@echo "Compiling kernel.c"
	gcc -fno-pie -m32 -ffreestanding -c kernel/kernel.c -o kernel.o

kernel.bin: kernel.o
	ld -m elf_i386 -o kernel.bin -Ttext 0x1000 kernel.o --oformat binary

kernel-entry.o: boot/kernel-entry.asm 
	nasm boot/kernel-entry.asm -f elf -o kernel-entry.o

mbr.bin: boot/mbr.asm
	nasm boot/mbr.asm -f bin -i boot -o mbr.bin

os-image.bin: mbr.bin kernel.bin
	cat $^ > $@

run: os-image.bin
	qemu-system-i386 -fda $<

clean:
	$(RM) *.bin *.o *.dis