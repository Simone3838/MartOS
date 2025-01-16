CROSS_COMPILE = i686-elf-

all: os-image

os-image: bootloader.bin kernel.bin
    # Combine bootloader and kernel to create the OS image
    cat $^ > os-image

bootloader.bin: boot.asm
    # Assemble the bootloader
    nasm -f bin $< -o $@

kernel.bin: kernel.c linker.ld
    # Compile the kernel
    $(CROSS_COMPILE)gcc -m32 -ffreestanding -c kernel.c -o kernel.o
    # Link the kernel
    $(CROSS_COMPILE)ld -m elf_i386 -T linker.ld -o kernel.bin kernel.o

clean:
    # Remove all generated files
    rm -f *.bin *.o os-image
