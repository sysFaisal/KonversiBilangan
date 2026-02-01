#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdlib.h>
#include "Konversi.h"


#define str_int 19 //Maks Long Long Int - 1 digit
#define str_hex 17 //Maks Long Long Int
#define str_oktal 22 //Maks Long Long Int
#define str_biner 61 //Maks Long Long Int


// Cek Input (Hex,oktal,Biner,biner) ============================
bool cekDesimal(char desimal_str[]){
    int i; int panjang = strlen(desimal_str);

    if (panjang >= str_int){
        return false;
    }

    for (i = 0; i < panjang; i++) { 
        if (!(desimal_str[i] >= '0' && desimal_str[i] <= '9')){	
            return false;
        }
    }
    return true;
}

bool cekHexa(char hex[]){
    int i; int panjang = strlen(hex);

    if (panjang >= str_hex){
        return false;
    }

    for (i = 0; i < panjang; i++) { 
        if (!((hex[i] >= '0' && hex[i] <= '9') || (hex[i] >= 'A' && hex[i] <= 'F') || (hex[i] >= 'a' && hex[i] <= 'f' ))) {	
            return false;
        }
    }
    return true;
}

    bool cekOktal(char oktal[]){
        int i; int panjang = strlen(oktal);

        if (panjang >= str_oktal){
            return false;
        }
        for (i = 0; i < panjang; i++) {
            if (!(oktal[i] >= '0' && oktal[i] <= '7')) {
                return false;
            }
        }
        return true;
    }

bool cekBiner(char biner[]){
    int i; int panjang = strlen(biner);
    if (panjang >= str_biner){
        return false;
    }

    for (i = 0; i < panjang; i++) {
        if (biner[i] != '0' && biner[i] != '1') {
            return false;
        }
    }
    return true;
}
// End Code =====================================

// Gagal Semua Kosong ===============================
void Allzero(char Biner[str_biner], char Oktal[str_oktal], 
    char Desimal[str_int], char Hexadesimal[str_hex]){
        strcpy(Biner,"0");
        strcpy(Oktal,"0");
        strcpy(Desimal,"0");
        strcpy(Hexadesimal,"0");
}
// End Code ===========================================

// Konversi Desimal =====================================
long long int DesimalStr(char input[str_int]){
    long long int desimal = 0, pangkat = 1;
    int i, panjang = strlen(input);


    for (i = panjang - 1; i >= 0; i--) {
		desimal = desimal + (input[i] - '0') * pangkat;
        pangkat = pangkat * 10;
    }

    return desimal;
}

long long int BinerkeDesimal(char input[str_biner]){
    long long int desimal = 0, pangkat = 1;
    int i, panjang = strlen(input);
    
    for (i = panjang - 1; i >= 0; i--) {
		desimal = desimal + (input[i] - '0') * pangkat;
        pangkat = pangkat * 2;
    }
    
    return desimal;
}

long long int OktalkeDesimal(char input[str_oktal]){
    long long int desimal = 0, pangkat = 1;
    int i, panjang = strlen(input);
    
	for (i = panjang - 1; i >= 0; i--) {
		desimal = desimal + (input[i] - '0') * pangkat;
        pangkat = pangkat * 8;
    }
    
    return desimal;
}

long long int HexadeskeDesimal(char input[str_hex]){
    long long int desimal = 0, pangkat = 1;
    int i, panjang = strlen(input);
    int r_hex[str_hex] = {0};


    for (i = 0; i < panjang; i++) {
        if (input[i] >= '0' && input[i] <= '9'){
            r_hex[i] = input[i] - '0';
        } else if (input[i] >= 'A' && input[i] <= 'F'){
            r_hex[i] = input[i] - 55;
        } else if (input[i] >= 'a' && input[i] <= 'f'){
            r_hex[i] = input[i] - 87;
        }
    }
    
    for (i = panjang - 1; i >= 0; i--) {
		desimal = desimal + r_hex[i] * pangkat;
        pangkat = pangkat * 16;
    }
    return desimal;
    
}
// End Code =======================================

// Balik Code =====================================
void balik(char bil[],int panjang){
	int i; char temp;
	for (i = 0; i < panjang / 2; i++){
    	temp = bil[i];
        bil[i] = bil[panjang - 1 - i];
        bil[panjang - 1 - i] = temp;
	}
}
// End Code =========================================

// Desimal ke yg lain ==================================
void DesimalkeStr(long long int desimal, char output[]){
    if (desimal == 0){
        strcpy(output, "0");
        return;
    }

    int panjang, o = 0;
    char des1mal[str_int];

    while (desimal != 0){
        des1mal[o] = (desimal % 10) + '0';
        desimal = desimal / 10;
        o++;
    }

    des1mal[o] = '\0';
    panjang = strlen(des1mal);
    
    balik(des1mal,panjang);
    strcpy(output, des1mal);
}

void DesimalkeOktal(long long int desimal, char output[]){
    if (desimal == 0){
        strcpy(output, "0");
        return;
    }

    int panjang, o = 0;
    char oktal[str_oktal];

    while (desimal != 0){
        oktal[o] = (desimal % 8) + '0';
        desimal = desimal / 8;
        o++;
    }

    oktal[o] = '\0';
    panjang = strlen(oktal);
    
    balik(oktal,panjang);
    strcpy(output, oktal);
}

void DesimalkeBiner(long long int desimal, char output[]){

    if (desimal == 0){
        strcpy(output, "0");
        return;
    }

    int panjang, o = 0;
    char biner[str_biner + 1];

    while (desimal != 0){
        biner[o] = (desimal % 2) + '0';
        desimal = desimal / 2;
        o++;
    }
    biner[o] = '\0';
    panjang = strlen(biner);

    balik(biner,panjang);
    strcpy(output, biner);
}

void DesimalkeHexa(long long int desimal, char output[]){

	if (desimal == 0){
        strcpy(output, "0");
        return;
    }

    int panjang, o = 0;
    int temp1;
    char hex[str_hex];

    while (desimal != 0){
        temp1 = desimal % 16;
        if(temp1 >= 0 && temp1 <= 9){
        	hex[o] = temp1 + '0';
		} else if(temp1 >= 10 && temp1 <= 15){
			hex[o] = temp1 + 55;
		}
        desimal = desimal / 16;
        o++;
    }

    hex[o] = '\0';
    panjang = strlen(hex);
    balik(hex,panjang);
    strcpy(output, hex);

}
// End Code =======================================

// Pusat Le ==========================================
void proses(long long int nilaiDesimal,char Biner[str_biner], char Oktal[str_oktal], 
    char Desimal[str_int], char Hexadesimal[str_hex]){

	DesimalkeBiner(nilaiDesimal,Biner);
	DesimalkeOktal(nilaiDesimal,Oktal);
	DesimalkeHexa(nilaiDesimal,Hexadesimal);
    DesimalkeStr(nilaiDesimal,Desimal);
}
// End Code ==========================================


// Function Header ======================================
int Biner(char Input[61], char Biner[str_biner], char Oktal[str_oktal], 
    char Desimal[str_int], char Hexadesimal[str_hex]){
    long long int nilaiDesimal = 0;

    if(!cekBiner(Input)){
        Allzero(Biner,Oktal,Desimal,Hexadesimal);
        return 1;
    }
    nilaiDesimal = BinerkeDesimal(Input);
    proses(nilaiDesimal,Biner,Oktal,Desimal,Hexadesimal);
    return 0;

}

int Oktal(char Input[22], char Biner[str_biner], char Oktal[str_oktal], 
    char Desimal[str_int], char Hexadesimal[str_hex]){
    long long int nilaiDesimal = 0;

    if(!cekOktal(Input)){
        Allzero(Biner,Oktal,Desimal,Hexadesimal);
        return 1;
    }
    nilaiDesimal = OktalkeDesimal(Input);
    proses(nilaiDesimal,Biner,Oktal,Desimal,Hexadesimal);
    return 0;
}

int Desimal(char Input[19], char Biner[str_biner], char Oktal[str_oktal], 
    char Desimal[str_int], char Hexadesimal[str_hex]){
    long long int nilaiDesimal = 0;

    if(!cekDesimal(Input)){
        Allzero(Biner,Oktal,Desimal,Hexadesimal);
        return 1;
    }
    nilaiDesimal = DesimalStr(Input);
    proses(nilaiDesimal,Biner,Oktal,Desimal,Hexadesimal);
    return 0;
}

int Hexa(char Input[17], char Biner[str_biner], char Oktal[str_oktal], 
    char Desimal[str_int], char Hexadesimal[str_hex]){
    long long int nilaiDesimal = 0;

    if(!cekHexa(Input)){
        Allzero(Biner,Oktal,Desimal,Hexadesimal);
        return 1;
    }
    nilaiDesimal = HexadeskeDesimal(Input);
    proses(nilaiDesimal,Biner,Oktal,Desimal,Hexadesimal);
    return 0;

}
// End Code =======================================


void Help() {
    printf("=== PROGRAM KONVERSI BILANGAN ===\n\n");
    printf("Program ini dapat mengonversi bilangan dari satu sistem bilangan ke sistem bilangan lainnya.\n\n");

    printf("Fungsi yang tersedia:\n\n");

    printf("1. int Biner(char Input[61], char Biner[str_biner], char Oktal[str_oktal], char Desimal[str_int], char Hexadesimal[str_hex]);\n");
    printf("   - Input      : Bilangan dalam format Biner (maks 60 karakter)\n");
    printf("   - Biner      : Array untuk menyimpan hasil konversi ke Biner\n");
    printf("   - Oktal      : Array untuk menyimpan hasil konversi ke Oktal\n");
    printf("   - Desimal    : Array untuk menyimpan hasil konversi ke Desimal\n");
    printf("   - Hexadesimal: Array untuk menyimpan hasil konversi ke Hexadesimal\n\n");

    printf("2. int Oktal(char Input[22], char Biner[str_biner], char Oktal[str_oktal], char Desimal[str_int], char Hexadesimal[str_hex]);\n");
    printf("   - Input      : Bilangan dalam format Oktal (maks 21 karakter)\n");
    printf("   - Biner      : Array untuk hasil konversi ke Biner\n");
    printf("   - Oktal      : Array untuk hasil konversi ke Oktal\n");
    printf("   - Desimal    : Array untuk hasil konversi ke Desimal\n");
    printf("   - Hexadesimal: Array untuk hasil konversi ke Hexadesimal\n\n");

    printf("3. int Desimal(char Input[19], char Biner[str_biner], char Oktal[str_oktal], char Desimal[str_int], char Hexadesimal[str_hex]);\n");
    printf("   - Input      : Bilangan dalam format Desimal (maks 18 digit)\n");
    printf("   - Biner      : Array untuk hasil konversi ke Biner\n");
    printf("   - Oktal      : Array untuk hasil konversi ke Oktal\n");
    printf("   - Desimal    : Array untuk hasil konversi ke Desimal\n");
    printf("   - Hexadesimal: Array untuk hasil konversi ke Hexadesimal\n\n");

    printf("4. int Hexa(char Input[17], char Biner[str_biner], char Oktal[str_oktal], char Desimal[str_int], char Hexadesimal[str_hex]);\n");
    printf("   - Input      : Bilangan dalam format Hexadesimal (maks 16 karakter)\n");
    printf("   - Biner      : Array untuk hasil konversi ke Biner\n");
    printf("   - Oktal      : Array untuk hasil konversi ke Oktal\n");
    printf("   - Desimal    : Array untuk hasil konversi ke Desimal\n");
    printf("   - Hexadesimal: Array untuk hasil konversi ke Hexadesimal\n\n");

    printf("Catatan:\n");
    printf("- Pastikan input sesuai dengan tipe bilangan yang dipilih.\n");
    printf("- Array output harus cukup besar untuk menampung hasil konversi.\n");
    printf("- Fungsi akan mengisi semua array output sesuai konversi.\n");

    printf("\nTekan Apapun Untuk Keluar dari Menu Help...");
    getchar(); 
    getchar();
    system("cls");
}