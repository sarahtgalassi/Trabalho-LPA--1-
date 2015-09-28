#include <stdio.h>

#include <stdio.h>

int dividir (int vet[], int esq, int dir)
{
    int aux, i = esq + 1, j = dir;
    while(i <= j)
    {
        if(vet[i]<vet[esq] || vet[i] == vet[esq])
            i++;
        if(vet[j]>vet[esq] || vet[j] == vet[esq])
            j--;
        if(j<i)
            break;
        aux = vet[j];
        vet[j]=vet[i];
        vet[i]=aux;
    }
    if (j >= 0)
 {
    aux = vet[j];
    vet[j]=vet[esq];
    vet[esq]=aux;
    return j;
}

}
void quicksort (int vet[], int esq, int dir)
{
    if(esq<dir){
    int pos_pivo = dividir(vet,esq,dir);
    quicksort(vet,esq,pos_pivo -1);
    quicksort(vet,pos_pivo +1,dir);}
}
void elementos_prox (int vet[], int n)
{
    int menor, aux, i = 1;
    quicksort(vet, 0, n-1);
    menor = vet[i] - vet[i-1];
    aux = i;
    printf("Os elementos mais proximos sao:\n");
    while (i < n)
    {
        if(vet[i] - vet[i-1] < menor)
        {
         menor = vet[i] - vet[i-1];
         aux = i;
        }
        i++;
    }
    if (menor == 0)
        {
            printf("Todos os elementos sao iguais.\n");
            i = n;
        }
    while(aux < n && menor > 0)
    {
            if(vet[aux]-vet[aux-1] == menor)
            {
                printf("%i e %i\n", vet[aux-1], vet[aux]);
            }
            aux++;
    }
}

void main()
{
    int n;
    printf("digite n:\n");
    scanf("%i", &n);
    int vet[n], i;
    printf("digite os n valores:\n");
    for(i=0;i<n;i++)
        scanf("%i", &vet[i]);
        elementos_prox(vet, n);
}
