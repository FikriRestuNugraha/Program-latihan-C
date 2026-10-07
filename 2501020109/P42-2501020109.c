#include <stdio.h>
#include <stdlib.h>

void segitiga(int tinggi)
{
    for (int i = 1; i <= tinggi; i++)
    {
        for (int j = 0; j < (2 * i - 1); j++)
        {
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
    segitiga(tinggi);

    return 0;
}