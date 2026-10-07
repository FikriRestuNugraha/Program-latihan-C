#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
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

    printf("File       : %s\n", argv[1]);
    printf("Jumlah data: %d\n", n);

    clock_t mulai = clock();

    heapSort(data, n);

    clock_t selesai = clock();

    double waktu = (double)(selesai - mulai) / CLOCKS_PER_SEC;

    printf("Waktu      : %.6f detik\n", waktu);

    free(data);

    return 0;
}