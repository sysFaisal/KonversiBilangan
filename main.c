#include <stdio.h>
#include <string.h>

#include "Library/Konversi.h" //Library

#define STR_INT     19
#define STR_HEX     17
#define STR_OKTAL   22
#define STR_BINER   61

//Baca Help() dulu!!

//Untuk Menjalan Program + Library
//mingw32-make run

//Untuk Menghapus Program + Library
//mingw32-make clean

int main (){
    Help();

    char input[STR_BINER] = "110001";
    char biner[str_biner];
    char oktal[str_oktal];
    char desimal[str_int];
    char hex[str_hex];

    Biner(input, biner, oktal, desimal, hex);

    printf("\nHasil konversi:\n");
    printf("Biner      : %s\n", biner);
    printf("Oktal      : %s\n", oktal);
    printf("Desimal    : %s\n", desimal);
    printf("Hexadesimal: %s\n", hex);

    return 0;
}