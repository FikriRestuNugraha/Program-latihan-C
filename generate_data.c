#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Penggunaan: %s nama_file jumlah_data\n", argv[0]);
        return 1;
    }

    char *nama_file = argv[1];
    int jumlah_data = atoi(argv[2]);

    FILE *file = fopen(nama_file, "w");

    if (file == NULL) {
        printf("Gagal membuka file.\n");
        return 1;
    }

    srand((unsigned int)time(NULL));

    for (int i = 0; i < jumlah_data; i++) {
        int angka = 10 + rand() % 999991;
        fprintf(file, "%d\n", angka);
    }

    fclose(file);

    printf("Berhasil membuat %s dengan %d data.\n",
           nama_file, jumlah_data);

    return 0;
}