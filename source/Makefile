CROSS_COMPILE = i686-elf-

all: os-image

os-image: bootloader.bin kernel.bin
    cat $^ > os-image

bootloader.bin: boot.asm
    nasm -f bin $< -o $@

kernel.bin: kernel.c linker.ld
    $(CROSS_COMPILE)gcc -m32 -ffreestanding -c kernel.c -o kernel.o
    $(CROSS_COMPILE)ld -m elf_i386 -T linker.ld -o kernel.bin kernel.o

clean:
    rm -f *.bin *.o os-image
