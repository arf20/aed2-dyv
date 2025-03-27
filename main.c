#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a)>(b)?(a):(b))
#define MIN(a, b) ((a)<(b)?(a):(b))

char *A = NULL;
char *sols = NULL;

int fastercmp(const char *a, const char *b) {
    while (*a && *b) {
        if (*a != *b)
            return 0;
        a++; b++;
    }
    return 1;
}

int comprobar(int off) {
    const char *a = A + off;
    return
        fastercmp(a, "acbaac") ||
        fastercmp(a, "acbdca") ||
        fastercmp(a, "aacacb") ||
        fastercmp(a, "aacdca") ||
        fastercmp(a, "dcaacb") ||
        fastercmp(a, "dcaaac");
}

void dyv(int i, int d) {
    int len = (d - i + 1);
    // caso base
    if (len < 6) {

    } else if (len == 6) {
         if (comprobar(i))
            sols[i] = 1;
    } else {
        // dividir
        dyv(i, i + ((len/2) - 1)); // mitad izq
        dyv(i + (len/2), d); // mitad dcha
        // combinar 
        for (int h = MAX(i + ((len/2) - 5), 0); h + 5 <= MIN(i + ((len/2) + 4), d); h++)
            if (comprobar(h))
                sols[h] = 1;
    }
}

int main(int argc, char **argv) {
    size_t len = 0;
    getline(&A, &len, stdin);
    len = strlen(A);
    
    sols = malloc(len);
    memset(sols, 0, len);

    if (argc == 2) {
        if (strcmp(argv[1], "-dyv") == 0)
            dyv(0, len - 1);
        else if (strcmp(argv[1], "-dir") == 0) {
            for (size_t h = 0; h + 5 <= len; h++)
                if (comprobar(h))
                    sols[h] = 1;
        } else
            return 1;

    } else 
        dyv(0, len - 1);

    size_t solcount = 0;
    for (size_t i = 0; i < len; i++) {
        if (sols[i]) {
            solcount++;
            printf("%ld, ", i + 1);
        }
    }

    printf("\nsol: %ld\n", solcount);
}

