#ifndef KONVERSI_H
#define KONVERSI_H

#define str_int 19 //Maks Long Long Int - 1 digit
#define str_hex 17 //Maks Long Long Int
#define str_oktal 22 //Maks Long Long Int
#define str_biner 61 //Maks Long Long Int

int Biner(char Input[61], char Biner[str_biner], char Oktal[str_oktal], 
                        char Desimal[str_int], char Hexadesimal[str_hex]);

int Oktal(char Input[22], char Biner[str_biner], char Oktal[str_oktal], 
                        char Desimal[str_int], char Hexadesimal[str_hex]);

int Desimal(char Input[19], char Biner[str_biner], char Oktal[str_oktal], 
                            char Desimal[str_int], char Hexadesimal[str_hex]);

int Hexa(char Input[17], char Biner[str_biner], char Oktal[str_oktal], 
                        char Desimal[str_int], char Hexadesimal[str_hex]);

void Help();
#endif

