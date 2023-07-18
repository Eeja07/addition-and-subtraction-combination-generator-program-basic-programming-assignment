#include <stdio.h>
#include <stdlib.h>
int jumlah_10;
void kombinasi(int *pengali, int index, int *angka, int n)
{
    int jumlah;
    if (index < n - 1)
    {
        do
        {
            kombinasi(pengali, index + 1, angka, n);
            pengali[index] *= -1;
        } while (pengali[index] != 1);
    }
    else
    {
        jumlah = 1;
        for (int i = 0; i < n - 1; i++)
        {
            jumlah += angka[i] * pengali[i];
        }
        if (jumlah == 10)
        {
            printf("\n1");
            for (int i = 0; i < n - 1; i++)
            {
                if (angka[i] * pengali[i] > 0)
                    printf("+ %i ", angka[i] *
                                        pengali[i]);

                else
                    printf("- %i ", angka[i] * pengali[i] * -1);
                printf("= %i", jumlah);
                jumlah_10++;
                printf("\t");
            }
        }
    }
}
int main()
{
    int n;
    scanf("%i", &n);
    int *angka, *pengali;
    angka = malloc((n - 1) * sizeof(int));
    pengali = malloc((n - 1) * sizeof(int));
    for (int i = 0; i < n - 1; i++)
    {
        angka[i] = i + 2;
        pengali[i] = 1;
    }
    kombinasi(pengali, 0, angka, n);
    if (jumlah_10 == 0)
        printf("Tidak ada kombinasi pengurangan dan penjumlahan untuk 1 - %i yang menghasilkan nilai 10", n);
    free(angka);
    free(pengali);
    return 0;
}