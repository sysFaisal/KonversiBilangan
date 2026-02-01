#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define str_int 18 //Maks Long Long Int - 1 digit
#define str_hex 16 //Maks Long Long Int
#define str_oktal 21 //Maks Long Long Int
#define str_biner 60 //Maks Long Long Int
#define nmax 20

//Kode ini tanpa menggunakan Library ini menyatu menu + rumus
//Ada fitur History

typedef struct{
	long long int Desimal;
	char Biner[str_biner + 1];
	char Hexa[str_hex + 1];
	char Oktal[str_oktal + 1];
}Data;

typedef struct{
	Data List[nmax];
	int neff;
}Tab;

// Membalikan String ============================
void balik(char bil[],int panjang){
	int i,temp;
	for (i = 0; i < panjang / 2; i++){
    	temp = bil[i];
        bil[i] = bil[panjang - 1 - i];
        bil[panjang - 1 - i] = temp;
	}
}

// Cek Input (Hex,oktal,Biner,biner) ============================
bool cekDesimal(char desimal_str[], int panjang){
    int i;
    for (i = 0; i < panjang; i++) { 
        if (!(desimal_str[i] >= '0' && desimal_str[i] <= '9')){	
            return false;
        }
    }
    return true;
}

bool cekHexa(char hex[], int panjang){
    int i;
    for (i = 0; i < panjang; i++) { 
        if (!((hex[i] >= '0' && hex[i] <= '9') || (hex[i] >= 'A' && hex[i] <= 'F') || (hex[i] >= 'a' && hex[i] <= 'f' ))) {	
            return false;
        }
    }
    return true;
}

bool cekOktal(char oktal[], int panjang){
    int i;
    for (i = 0; i < panjang; i++) {
        if (!(oktal[i] >= '0' && oktal[i] <= '7')) {
            return false;
        }
    }
    return true;
}

bool cekBiner(char biner[], int panjang){
    int i;
    for (i = 0; i < panjang; i++) {
        if (biner[i] != '0' && biner[i] != '1') {
            return false;
        }
    }
    return true;
}

// Konversi Desimal (Inti) ============================
void DesimalkeOktal(Data *Input){
	long long int desimal = (*Input).Desimal;
	
    if (desimal == 0){
        strcpy((*Input).Oktal, "0");
        return;
    }
    int panjang, o = 0;
    char oktal[str_oktal + 1];
    while (desimal != 0){
        oktal[o] = (desimal % 8) + '0';
        desimal = desimal / 8;
        o++;
    }
    oktal[o] = '\0';
    panjang = strlen(oktal);
    balik(oktal,panjang);
    strcpy((*Input).Oktal, oktal);
}

void DesimalkeBiner(Data *Input){
	long long int desimal = (*Input).Desimal;
    if (desimal == 0){
        strcpy((*Input).Biner, "0");
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
    strcpy((*Input).Biner, biner);
}

void DesimalkeHexa(Data *Input){
	long long int desimal = (*Input).Desimal;
	if (desimal == 0){
        strcpy((*Input).Hexa, "0");
        return;
    }
    int panjang, o = 0;
    int temp1; char temp;
    char hex[str_hex + 1];
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
    strcpy((*Input).Hexa, hex);
}

// Hub Konversi ============================
void proses(Data *Input){
	DesimalkeBiner(Input);
	DesimalkeOktal(Input);
	DesimalkeHexa(Input);
}

// Input Bilangan ============================
void DesimalStr(Data *Input){
	char desimal_str[str_int + 1];
    int i; long long int desimal = 0, pangkat = 1;

    scanf("%s", desimal_str);
    int panjang = strlen(desimal_str);
    
    if (panjang > str_int){
    	printf(" Input Terlalu Banyak\n");
    	(*Input).Desimal = 0;
    	return;
	}
	
    if (!cekDesimal(desimal_str , panjang)){
        printf(" Error: Input bukan Desimal!\n");
        (*Input).Desimal = 0;
        return;
    }

    for (i = panjang - 1; i >= 0; i--) {
		desimal = desimal + (desimal_str[i] - '0') * pangkat;
        pangkat = pangkat * 10;
    }
    (*Input).Desimal = desimal;
}

void BinerkeDesimal(Data *Input){
    char biner[str_biner + 1];
    int i; long long int desimal = 0, pangkat = 1;

    scanf("%s", biner);
    int panjang = strlen(biner);
    
    if (panjang > str_biner){
    	printf(" Input Terlalu Banyak\n");
    	(*Input).Desimal = 0;
    	return;
	}

    if (!cekBiner(biner , panjang)){
        printf(" Error: Input bukan Biner!\n");
        (*Input).Desimal = 0;
        return;
    }
    
    for (i = panjang - 1; i >= 0; i--) {
		desimal = desimal + (biner[i] - '0') * pangkat;
        pangkat = pangkat * 2;
    }
    
    (*Input).Desimal = desimal;
}

void OktalkeDesimal(Data *Input){
	char oktal[str_oktal + 1];
    int i; long long int desimal = 0, pangkat = 1;

    scanf("%s", oktal);
    int panjang = strlen(oktal);
    
    if (panjang > str_oktal){
    	printf(" Input Terlalu Banyak\n");
    	(*Input).Desimal = 0;
    	return;
	}
	
    if (!cekOktal(oktal , panjang)){
        printf(" Error: Input bukan Oktal!\n");
        (*Input).Desimal = 0;
        return;
    }
    
	for (i = panjang - 1; i >= 0; i--) {
		desimal = desimal + (oktal[i] - '0') * pangkat;
        pangkat = pangkat * 8;
    }
    
    (*Input).Desimal = desimal;
}

void HexadeskeDesimal(Data *Input){
    char hex[str_hex + 1]; int r_hex[str_hex + 1];
    int i; long long int desimal = 0, pangkat = 1;
    scanf("%s", hex);
    int panjang = strlen(hex);
    
	if (panjang > str_hex){
    	printf(" Input Terlalu Banyak\n");
    	(*Input).Desimal = 0;
    	return;
	}
	
    if (!cekHexa(hex , panjang)){
        printf(" Error: Input bukan Hexa!\n");
        (*Input).Desimal = 0;
        return;
    }

    for (i = 0; i < panjang; i++) {
        if (hex[i] >= '0' && hex[i] <= '9'){
            r_hex[i] = hex[i] - '0';
        } else if (hex[i] >= 'A' && hex[i] <= 'F'){
            r_hex[i] = hex[i] - 55;
        } else if (hex[i] >= 'a' && hex[i] <= 'f'){
            r_hex[i] = hex[i] - 87;
        }
    }
    
    for (i = panjang - 1; i >= 0; i--) {
		desimal = desimal + r_hex[i] * pangkat;
        pangkat = pangkat * 16;
    }
    (*Input).Desimal = desimal;
    
}

// Menu Konversi ============================
void Menu_Konversi(int pilihan, Data *Input){
    printf("----------------------------------------\n");
    switch(pilihan){        
        case 1:
            printf(" Input (Desimal): ");
            DesimalStr(Input);
            break;
        case 2:
            printf(" Input (Biner): ");
            BinerkeDesimal(Input);
            break;
        case 3:
            printf(" Input (Oktal): ");
            OktalkeDesimal(Input);
            break;
        case 4:
            printf(" Input (Hexadesimal): ");
            HexadeskeDesimal(Input);
            break;
        default:
        	break;
    }
}

// Masuk History ============================
void AddTab(Tab *History, Data Input){
	if(Input.Desimal != 0 && (*History).neff < nmax){
        (*History).List[(*History).neff] = Input;
        (*History).neff++;
    }
}

// Create Tab ============================
void createtab(Tab *History){
	(*History).neff = 0;
}

// Cetak Data =============================
void konvers(Data Input,int temp){
    printf("\n----------------------------------------\n");
    if(temp != -1){
    	printf(" Hasil Konversi Ke %d\n", temp + 1);
	} else {
		printf(" Hasil Konversi \n");
	}
    printf("----------------------------------------\n");
    printf(" Desimal : %lld\n", Input.Desimal);
    printf(" Biner : %s\n", Input.Biner);
    printf(" Oktal  : %s\n", Input.Oktal);
    printf(" Hexadesimal : %s\n", Input.Hexa);
    printf("----------------------------------------\n");
    printf("\n");
}

// Cetak History ==========================
void cetakhistory(Tab History){
	if (History.neff == 0){
        printf(" History Masih Kosong.\n");
        return;
    }
	char lanjut; int i;
	printf(" Tampilkan history? Y/N: ");
    scanf(" %c",&lanjut);
    if (lanjut == 'y' || lanjut == 'Y'){
    	printf("\n========================================\n");
        printf("            HISTORY KONVERSI         \n");
        printf("========================================\n");
    	for (i = 0; i < History.neff; i++){
    		konvers(History.List[i],i);
		}
    } else {
        return;
    }
}

// CreateData ================================
void createdata(Data *Input){
    (*Input).Desimal = 0;
    strcpy((*Input).Biner, "0");
    strcpy((*Input).Oktal, "0");
    strcpy((*Input).Hexa, "0");
}

int main(){
	Tab History;
	Data Input;
	
	createtab(&History);
	int pilihan,temp; char lanjut;
    
    do{
    	createdata(&Input);
    	temp = -1;
    	system("cls");
        printf("========================================\n");
        printf("        PROGRAM KONVERSI BILANGAN        \n");
        printf("========================================\n");
        printf(" [1] Desimal\n");
        printf(" [2] Biner\n");
        printf(" [3] Oktal\n");
        printf(" [4] Hexadesimal\n");
        printf("----------------------------------------\n");
        printf(" Pilihan Anda : ");
        
        if(scanf("%d",&pilihan) == 1){
            if(pilihan >= 1 && pilihan <= 4){
                Menu_Konversi(pilihan , &Input);
				proses(&Input);
				konvers(Input,temp);
				AddTab(&History, Input);
            }else{
                printf(" Error!\n");
            }
        }else{
            printf(" Error!\n");
        }
        
        if (!(History.neff < nmax)){
        	printf(" History Sudah Penuh!\n");
        	break;
		}
		
        printf(" Ingin Konversi Lagi Y/N: ");
        scanf(" %c",&lanjut);
     
    }while(lanjut == 'y' || lanjut == 'Y');
    cetakhistory(History);
}
