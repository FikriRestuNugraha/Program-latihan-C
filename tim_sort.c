#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RUN 32

void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *leftArr = malloc(n1 * sizeof(int));
    int *rightArr = malloc(n2 * sizeof(int));

    if (leftArr == NULL || rightArr == NULL) {
        free(leftArr);
        free(rightArr);
        return;
    }

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    while (i < n1)
        arr[k++] = leftArr[i++];

    while (j < n2)
        arr[k++] = rightArr[j++];

    free(leftArr);
    free(rightArr);
}

void timSort(int arr[], int n) {
    for (int i = 0; i < n; i += RUN) {
        int right = i + RUN - 1;

        if (right >= n)
            right = n - 1;

        insertionSort(arr, i, right);
    }

    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = left + 2 * size - 1;

            if (mid >= n)
                continue;

            if (right >= n)
                right = n - 1;

            merge(arr, left, mid, right);
        }
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

    timSort(data, n);

    clock_t selesai = clock();

    double waktu = (double)(selesai - mulai) / CLOCKS_PER_SEC;

    printf("Waktu      : %.6f detik\n", waktu);

    free(data);

    return 0;
}