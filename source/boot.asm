[BITS 16]
[ORG 0x7C00]

start:
    ; Set up the stack
    cli
    cld
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00

    ; Load the kernel
    mov bx, 0x1000
    mov ah, 0x02
    mov al, 0x01
    mov ch, 0x00
    mov cl, 0x02
    mov dh, 0x00
    int 0x13

    ; Jump to the kernel
    jmp 0x1000:0x0000

    ; Fill the rest of the boot sector with zeros
    times 510-($-$$) db 0
    dw 0xAA55
