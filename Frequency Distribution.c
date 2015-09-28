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

void mais_repete(int *inteiros, int n) // checa qual o elemento que mais repete em um vetor
{
    if (n > 8 && n != 1) // entre as linhas 53 e 56 é checado qual o melhor algortimo de ordenação baseado no tamanho do vetor
    quicksort(inteiros,0, n-1);
    if(n < 8 && n != 1)
        insertion(inteiros, n);if (n > 8 && n != 1) // entre as linhas 53 e 56 é checado qual o melhor algortimo de ordenação baseado no tamanho do vetor
    quicksort(inteiros,0, n-1);
    if(n < 8 && n != 1)
        insertion(inteiros, n);
    int cont1 = 1, cont2, cont3 = 1, i = 1, j = 0;
    printf("\nOs elementos que mais repetem sao:\n");
    while(j < 1) // condição de parada da função
    {

    while(i < n) // este ciclo checa qual o maior número de vezes que um elemento se repete
    {
        while(*(inteiros + i) > *(inteiros + i - 1))
            {
                i++;
            }
            cont2 = 1;
        while(*(inteiros + i) == *(inteiros + i - 1))
        {
            cont2++;
            i++;
        }
        if (cont2 > cont3)
            {
                cont3 = cont2;
            }
    }

    i = 1;
    while(i < n) //este ciclo analisa qual ou quais elementos se repentem o número de vezes encontrado no ciclo anterior
    {
        while (*(inteiros + i) == *(inteiros + i - 1))
        {
            cont1++;
            i++;
        }
        if (cont1 == cont3)
        {
            printf("%i\n", *(inteiros + i - 1));
        }
        if(*(inteiros + i) != *(inteiros + i - 1) && i < n)
            cont1 = 1;
        i++;
    }
    if(cont3 == 1)
        printf("%i\n", *(inteiros + i - 1));
    j = 1; // para a função
    }
}

void main()
{
    int n = 0;
    while (n <= 0){
    printf("Digite um numero inteiro, n, positivo e maior que zero:\n");
    scanf("%i", &n);}
    printf("\nDigite %i numeros inteiros:\n", n);
    int cont, *inteiros = (int *)malloc(n*sizeof(int));
    for(cont = 0; cont < n; cont++)
        scanf("%i", (inteiros + cont));
    mais_repete(inteiros, n);
    free(inteiros);
}
