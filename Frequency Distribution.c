#include <stdio.h>
void main()
{
    int vet[6] = {1,2,3,4,5,6};
    int cont1, cont2 = 1, i = 1, aux;
    cont1 = cont2;
    while(i<6)
    {
        while(vet[i]>vet[i-1])
            i++;
        while(vet[i] == vet[i-1])
        {
            cont2++;
            i++;
        }
        aux = vet[i-1];
        if(cont2>cont1)
            cont1 = cont2;
    }
    if(cont1==1)
        printf("todos sao diferentes\n");
    if(cont1 == 6)
        printf("todos iguais a %i\n", aux);
    if (cont1 != 1 && cont1 != 6)
        printf("o que mais repete eh %i\n", aux);
}
