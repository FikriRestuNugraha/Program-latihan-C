#include <stdio.h>
#include <stdlib.h>

void pola(int baris, int kolom)
{
    for (int i = 0; i < baris; i++)
    {
        for (int j = 0; j < kolom; j++)
        {
            printf("o");
        }

        printf("\n");
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Penggunaan: %s <baris> <kolom>\n", argv[0]);
        return 1;
    }

    int baris = atoi(argv[1]);
    int kolom = atoi(argv[2]);

    printf("Hello, World!\n");
    pola(baris, kolom);

    return 0;
}