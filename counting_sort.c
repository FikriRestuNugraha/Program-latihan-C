#include <stdio.h>
#include <stdlib.h>

void countingSort(int array[], int size) {
    int max = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    int *count = calloc(max + 1, sizeof(int));
    int *output = malloc(size * sizeof(int));

    if (count == NULL || output == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        free(count);
        free(output);
        return;
    }

    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }

    free(count);
    free(output);
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

    countingSort(data, n);

    printf("Data berhasil diurutkan menggunakan Counting Sort.\n");

    free(data);

    return 0;
}