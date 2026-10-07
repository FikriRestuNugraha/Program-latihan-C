#include <stdio.h>
#include <stdlib.h>

void segitigaTerbalik(int tinggi)
{
    for (int i = tinggi; i >= 1; i--)
    {
        if (i == 1)
        {
            printf("o");
        }
        else
        {
            printf("o");

            for (int j = 0; j < (2 * i - 3); j++)
            {
                printf("-");
            }

            printf("o");
        }

        printf("\n");
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Penggunaan: %s <tinggi>\n", argv[0]);
        return 1;
    }

    int tinggi = atoi(argv[1]);

    printf("Hello, World!\n");
    segitigaTerbalik(tinggi);

    return 0;
}