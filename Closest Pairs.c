#include <stdio.h>
#include <stdlib.h>

void insertion (int *inteiros, int tamanho)
{
		int i;
	int j;
	int aux;
	for (i = 1; i < tamanho; i++){                   	// percorre da esquerda para a direita
            aux = *(inteiros + i);                            	// separa-se o valor a ser ordenado
            j = i - 1;
            while ((j>=0) && (aux < *(inteiros + j))) {    	 	// percorre da direita para a esquerda at� o 1� termo
 *(inteiros + j + 1) = *(inteiros + j);                		 	//Se auxiliar � menor, os valores maiores ser�o copiados para a posi��o seguinte
               j--;
         }
         if (i != j + 1) {
*(inteiros + j + 1) = aux;                                      	//Se auxiliar � maior, ela ocupa a posi��o
         }
      }
    }

void troca (int* inteiros, int pos, int esq) // troca dois elementos de posi��o
{
int aux = *(inteiros + esq);
*(inteiros + esq) = *(inteiros + pos);
*(inteiros + pos) = aux;
}
int dividir (int *inteiros, int esq, int dir) // esta fun��o coloca o piv� do vetor em sua posi��o correta
{
    int i = esq + 1, j = dir; // esq � o elemento tomado com piv� e dir � o �ltimo elemento do vetor
    while(i <= j) // este ciclo percorre todo o vetor at� encontrar a posi��o correta do piv�
    {
        if(*(inteiros + i) < *(inteiros + esq) || *(inteiros + i) == *(inteiros + esq))
            i++;
        if(*(inteiros + j) > *(inteiros + esq) || *(inteiros + j) == *(inteiros + esq))
            j--;
        if(j<i)
            break;
        troca(inteiros, i, j);
    }
    if (j >= 0) // esta parte coloca o piv� em sua posi��o correta e retorna a posi��o
 {
    troca(inteiros, j, esq);
    return j;
}

}
void quicksort (int *inteiros, int esq, int dir) // esta fun��o ordena um vetor de inteiros em ordem crescente
{
    if(esq<dir){ //esta parte checa se as posi��o recebidas como argumento fazem sentido
    int pos = rand() % (dir - esq + 1) + esq;
    troca(inteiros, pos, esq);
    int pos_pivo = dividir(inteiros,esq,dir);
    quicksort(inteiros,esq,pos_pivo -1); // recurs�o da fun��o quicksort
    quicksort(inteiros,pos_pivo +1,dir);}
}

void elementos_prox (int *inteiros, int n) //esta fun��o procura elementos diferente cuja a diferen�a � a menor dentro do vetor
{
    int menor, aux, i = 1, j = 0; // a vari�vel menor armazena a diferen�a entre dois elementos do vetor
    if(n > 8)
        quicksort(inteiros, 0, n-1);
    else
        insertion(inteiros,n);
    printf("\nOs elementos mais proximos sao:\n");
    while (j < 1) // j serve como uma condi��o de parada da fun��o
    {
        while(*(inteiros + i) - *(inteiros + i - 1) == 0 && i < n) // a linha 43 at� a linha 49 servem para verificar se o vetor cont�m apenas
            i++;                               //valores iguais e, caso sejam diferentes, a partir de qual posi��o s�o diferentes
        if(i == n)
        {
            printf("Todos os elementos sao iguais a %i.\n", *inteiros);
            j = 1; // para a fun��o
        }
    else // caso i seja diferente de n
    {
    menor = *(inteiros + i) - *(inteiros + i - 1); //menor recebe o primeiro par de valores com diferen�a diferente de 0
    aux = i; // aux recebe a posi��o do maior valor
    }
    while (i < n) //este ciclo descobre qual a menor diferen�a entre valores do vetor
    {
        if(*(inteiros + i) - *(inteiros + i - 1) < menor && *(inteiros + i) - *(inteiros + i - 1) > 0)
        {
         menor = *(inteiros + i) - *(inteiros + i - 1);
         aux = i;
        }
        i++;
    }
    while(aux < n) // este ciclo mostra quais s�o os valores cuja diferen�a � a menor
    {
            if(*(inteiros + aux) - *(inteiros + aux - 1) == menor)
            {
                printf("%i e %i\n", *(inteiros + aux - 1), *(inteiros + aux));
            }
            aux++;
    }
    j = 1; // encerra a fun��o
    }
}

void main()
{
    int n = -1;
    while(n <= 0)
        {
    printf("Digite um inteiro , n, maior que zero e positivo:\n");
    scanf("%i", &n);
        }
    int x, *inteiros = (int *)malloc(n * sizeof(int));
    printf("digite os %i valores inteiros:\n", n);
    for(x = 0; x < n; x++)
        scanf("%i", inteiros + x);
    elementos_prox(inteiros, n);
    free(inteiros);
}
