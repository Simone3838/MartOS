void kernel_main() {
    const char *str = "Welcome to MartOS!";
    char *vidptr = (char*)0xb8000;  // Video memory starts here
    unsigned int i = 0;
    unsigned int j = 0;

    // Clear the screen
    while (j < 80 * 25 * 2) {
        vidptr[j] = ' ';
        vidptr[j+1] = 0x07;  // Light grey on black background
        j = j + 2;
    }

    j = 0;

    // Write the string to video memory
    while (str[j] != '\0') {
        vidptr[i] = str[j];
        vidptr[i+1] = 0x07;  // Light grey on black background
        ++j;
        i = i + 2;
    }

    return;
}
