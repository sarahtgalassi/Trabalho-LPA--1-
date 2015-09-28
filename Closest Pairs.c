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
            while ((j>=0) && (aux < *(inteiros + j))) {    	 	// percorre da direita para a esquerda até o 1º termo
 *(inteiros + j + 1) = *(inteiros + j);                		 	//Se auxiliar é menor, os valores maiores serão copiados para a posição seguinte
               j--;
         }
         if (i != j + 1) {
*(inteiros + j + 1) = aux;                                      	//Se auxiliar é maior, ela ocupa a posição
         }
      }
    }

void troca (int* inteiros, int pos, int esq) // troca dois elementos de posição
{
int aux = *(inteiros + esq);
*(inteiros + esq) = *(inteiros + pos);
*(inteiros + pos) = aux;
}
int dividir (int *inteiros, int esq, int dir) // esta função coloca o pivô do vetor em sua posição correta
{
    int i = esq + 1, j = dir; // esq é o elemento tomado com pivô e dir é o último elemento do vetor
    while(i <= j) // este ciclo percorre todo o vetor até encontrar a posição correta do pivô
    {
        if(*(inteiros + i) < *(inteiros + esq) || *(inteiros + i) == *(inteiros + esq))
            i++;
        if(*(inteiros + j) > *(inteiros + esq) || *(inteiros + j) == *(inteiros + esq))
            j--;
        if(j<i)
            break;
        troca(inteiros, i, j);
    }
    if (j >= 0) // esta parte coloca o pivô em sua posição correta e retorna a posição
 {
    troca(inteiros, j, esq);
    return j;
}

}
void quicksort (int *inteiros, int esq, int dir) // esta função ordena um vetor de inteiros em ordem crescente
{
    if(esq<dir){ //esta parte checa se as posição recebidas como argumento fazem sentido
    int pos = rand() % (dir - esq + 1) + esq;
    troca(inteiros, pos, esq);
    int pos_pivo = dividir(inteiros,esq,dir);
    quicksort(inteiros,esq,pos_pivo -1); // recursão da função quicksort
    quicksort(inteiros,pos_pivo +1,dir);}
}

void elementos_prox (int *inteiros, int n) //esta função procura elementos diferente cuja a diferença é a menor dentro do vetor
{
    int menor, aux, i = 1, j = 0; // a variável menor armazena a diferença entre dois elementos do vetor
    if(n > 8)
        quicksort(inteiros, 0, n-1);
    else
        insertion(inteiros,n);
    printf("\nOs elementos mais proximos sao:\n");
    while (j < 1) // j serve como uma condição de parada da função
    {
        while(*(inteiros + i) - *(inteiros + i - 1) == 0 && i < n) // a linha 43 até a linha 49 servem para verificar se o vetor contém apenas
            i++;                               //valores iguais e, caso sejam diferentes, a partir de qual posição são diferentes
        if(i == n)
        {
            printf("Todos os elementos sao iguais a %i.\n", *inteiros);
            j = 1; // para a função
        }
    else // caso i seja diferente de n
    {
    menor = *(inteiros + i) - *(inteiros + i - 1); //menor recebe o primeiro par de valores com diferença diferente de 0
    aux = i; // aux recebe a posição do maior valor
    }
    while (i < n) //este ciclo descobre qual a menor diferença entre valores do vetor
    {
        if(*(inteiros + i) - *(inteiros + i - 1) < menor && *(inteiros + i) - *(inteiros + i - 1) > 0)
        {
         menor = *(inteiros + i) - *(inteiros + i - 1);
         aux = i;
        }
        i++;
    }
    while(aux < n) // este ciclo mostra quais são os valores cuja diferença é a menor
    {
            if(*(inteiros + aux) - *(inteiros + aux - 1) == menor)
            {
                printf("%i e %i\n", *(inteiros + aux - 1), *(inteiros + aux));
            }
            aux++;
    }
    j = 1; // encerra a função
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
