#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* map(char *array, int array_length, char (*f) (char)) {
    char* out = (char*)malloc(array_length);
    if (!out) return NULL;
    for (int i = 0; i < array_length; i++) out[i] = f(array[i]);
    return out;
}

char my_get(char c) {
    int ch = fgetc(stdin);
    return (ch == EOF) ? c : (char)ch;
}

char cxprt(char c) {
    unsigned char uc = (unsigned char)c;
    if (uc >= 0x20 && uc <= 0x7E) printf("%c ", uc);
    else                          printf(". ");
    printf("%02x\n", uc);
    return c;
}

char encrypt(char c) {
    unsigned char uc = (unsigned char)c;
    if (uc >= 0x20 && uc <= 0x7E) return (char)(uc + 1);
    return c;
}

char decrypt(char c) {
    unsigned char uc = (unsigned char)c;
    if (uc >= 0x21 && uc <= 0x7F) return (char)(uc - 1);
    return c;
}

char dprt(char c) {
    printf("%u\n", (unsigned int)(unsigned char)c);
    return c;
}

struct fun_desc {
    char *name;
    char (*fun)(char);
};

int main(void) {
    const int base_len = 5;
    char* carray = (char*)malloc(base_len);
    if (!carray) return 1;
    memset(carray, 0, base_len);

    struct fun_desc menu[] = {
        {"Get String",  my_get},
        {"Encrypt",     encrypt},
        {"Decrypt",     decrypt},
        {"Print dec",   dprt},
        {"Print char+hex", cxprt},
        {NULL,          NULL}
    };

    int menu_len = 0;
    while (menu[menu_len].name) menu_len++;

    char line[64];
    for (;;) {
        printf("Select operation from the following menu:\n");
        for (int i = 0; i < menu_len; i++)
            printf("%d) %s\n", i, menu[i].name);
        printf("Option: ");
        if (!fgets(line, sizeof(line), stdin)) break; 

        char *end = NULL;
        long choice = strtol(line, &end, 10);
        if (end == line || choice < 0 || choice >= menu_len) {
            printf("Outside ranges\n");
            break;
        }

        char* new_arr = map(carray, base_len, menu[choice].fun);
        if (!new_arr) { free(carray); return 1; }
        free(carray);
        carray = new_arr;

        printf("DONE.\n");
    }

    free(carray);
    return 0;
}