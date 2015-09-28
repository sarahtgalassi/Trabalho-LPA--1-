#include <stdio.h>
int dividir (int vet[], int esq, int dir)
{
    int aux, i = esq + 1, j = dir;
    while(i<=j)
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
    aux = vet[j];
    vet[j]=vet[esq];
    vet[esq]=aux;
    return j;
}
void quicksort (int vet[], int esq, int dir)
{
    if(esq<dir){
    int pos_pivo = dividir(vet,esq,dir);
    quicksort(vet,esq,pos_pivo -1);
    quicksort(vet,pos_pivo +1,dir);}
}

void unico (int vet[], int n)
{
   quicksort(vet,0, n-1);
   int x = 0, y = 0;
   int *valores_unicos = NULL;
    while(x<n)
    {
        if(vet[x+1] > vet[x])
        {
            valores_unicos = &vet[x];
            printf("%i\n", vet[x]);
            x++;
        }
        if(vet[x+1] == vet[x])
        {
            while(vet[x] == vet[x+1])
                x++;
            x++; //Quando o ciclo terminar vet[x] ainda ser? igual ao valor que estava repetindo,
                 //adicionando +1 a x, o valor seguinte ser? diferente.
        }
    }
    if(valores_unicos == NULL)
        printf("Nao ha valores unicos.\n");
}
void main()
{
    int n = 0;
    while (n <= 0){
    printf("Digite um numero inteiro, n, positivo e maior que zero:\n");
    scanf("%i", &n);}
    printf("\nDigite %i numeros inteiros:\n", n);
    int cont, vet[n];
    for(cont = 0; cont < n; cont++)
        scanf("%i", &vet[cont]);
    printf("Os valores unicos sao:\n");
    unico(vet, n);
}
