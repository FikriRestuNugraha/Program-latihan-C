#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Penggunaan: %s nama_file.csv\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("File tidak dapat dibuka.\n");
        return 1;
    }

    int kapasitas = 100;
    int n = 0;
    int *data = malloc(kapasitas * sizeof(int));

    if (data == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        fclose(file);
        return 1;
    }

    while (fscanf(file, "%d", &data[n]) == 1) {
        n++;

        if (n >= kapasitas) {
            kapasitas *= 2;

            int *temp = realloc(data, kapasitas * sizeof(int));

            if (temp == NULL) {
                printf("Gagal menambah memori.\n");
                free(data);
                fclose(file);
                return 1;
            }

            data = temp;
        }
    }

    fclose(file);

    clock_t mulai = clock();

    insertionSort(data, n);

    clock_t selesai = clock();

    double waktu = (double)(selesai - mulai) / CLOCKS_PER_SEC;

    printf("File       : %s\n", argv[1]);
    printf("Jumlah data: %d\n", n);
    printf("Waktu      : %.6f detik\n", waktu);

    free(data);

    return 0;
}