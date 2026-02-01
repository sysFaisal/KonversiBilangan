#include <stdio.h>
#include <string.h>
#include <omp.h>
#include <time.h>

#include "Library/Konversi.h"

#define STR_INT     19
#define STR_HEX     17
#define STR_OKTAL   22
#define STR_BINER   61

#define LOOP 100000000 // 1 MILIAR bebas 

// Kode ini hanya digunakan untuk Stress Test
// Stress Test Harus Menggunakan MinGW64
// gcc.exe (Rev11, Built by MSYS2 project) 15.2.0

// Untuk Menjalankan, Ketik diterminal
// gcc -O2 -Wall -Wextra -fopenmp -ILibrary stress_test.c Library/konversi.c -o stress_test.exe -lwinpthread 
// Tunggu build terus ketik
// .\stress_test.exe
// Kalau selesai stress test Jangan Lupa stress_test.exe di hapus!! 


void gen_fast(char *buf, int max_len, const char *set) {
    int set_len = strlen(set);
    int len = max_len - 1;
    for (int i = 0; i < len; i++) buf[i] = set[i % set_len];
    buf[len] = '\0';
}

int main() {
    char input[64];
    gen_fast(input, 18, "0123456789");

    int nThreads = omp_get_max_threads();
    omp_set_num_threads(nThreads);

    clock_t start = clock();
    volatile unsigned long long sink = 0;

    #pragma omp parallel
    {
        char outBiner[STR_BINER];
        char outOktal[STR_OKTAL];
        char outDesimal[STR_INT];
        char outHexa[STR_HEX];

        #pragma omp for schedule(dynamic, 1000)
        for (int i = 0; i < LOOP; i++) {
            int ret = Desimal(input, outBiner, outOktal, outDesimal, outHexa);
            if (ret == 0) {
                sink += outBiner[0] ^ outOktal[0] ^ outDesimal[0] ^ outHexa[0];
            }
        }
    }

    clock_t end = clock();
    double elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("=== STRESS TEST DONE ===\n");
    printf("Loop     : %d\n", LOOP);
    printf("Threads  : %d\n", nThreads);
    printf("Time     : %.2f seconds\n", elapsed);
    printf("Sink     : %llu\n", sink);

    return 0;
}
