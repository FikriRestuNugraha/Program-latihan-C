#include <stdio.h>
#include <stdlib.h>

void cetakHurufBesar(char huruf, int jumlah)
{
    if (jumlah <= 0)
        return;

    printf("%c", huruf);

    cetakHurufBesar(huruf, jumlah - 1);
}

void cetakHurufKecil(char huruf, int jumlah)
{
    if (jumlah <= 0)
        return;

    printf("%c", huruf);

    cetakHurufKecil(huruf, jumlah - 1);
}

void rec2501020109(int i, int n)
{
    if (i > n)
        return;

    char hurufBesar = 'A' + (i - 1);
    char hurufKecil = 'a' + (i - 1);

    cetakHurufBesar(hurufBesar, i);

    cetakHurufKecil(hurufKecil, n - i);

    printf("\n");

    rec2501020109(i + 1, n);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Penggunaan: %s <jumlah>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    rec2501020109(1, n);

    return 0;
}