#include <stdio.h>
#include <stdlib.h>

void ite2501020109(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char huruf = 'A' + (i - 1);

        for (int j = 1; j <= i; j++)
        {
            printf("%c", huruf);
        }

        for (int j = i + 1; j <= n; j++)
        {
            printf("%c", huruf + ('a' - 'A'));
        }

        printf("\n");
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Penggunaan: %s <jumlah>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    ite2501020109(n);

    return 0;
}