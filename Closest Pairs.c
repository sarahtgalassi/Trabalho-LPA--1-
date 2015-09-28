#include <stdio.h>

void insertion (int vet[], int tamanho)
{
		int i;
	int j;
	int aux;
	for (i = 1; i < tamanho; i++){                   	// percorre da esquerda para a direita
            aux = vet[i];                            	// separa-se o valor a ser ordenado
            j = i - 1;
            while ((j>=0) && (aux < vet[j])) {    	 	// percorre da direita para a esquerda at� o 1� termo
 vet[j+1] = vet[j]          ;                		 	//Se auxiliar � menor, os valores maiores ser�o copiados para a posi��o seguinte
               j--;
         }
         if (i != j + 1) {
vet[j+1] = aux;                                      	//Se auxiliar � maior, ela ocupa a posi��o
         }
      }
    }
int dividir (int vet[], int esq, int dir) // esta fun��o coloca o piv� do vetor em sua posi��o correta
{
    int aux, i = esq + 1, j = dir; // esq � o elemento tomado com piv� e dir � o �ltimo elemento do vetor
    while(i <= j) // este ciclo percorre todo o vetor at� encontrar a posi��o correta do piv�
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
    if (j >= 0) // esta parte coloca o piv� em sua posi��o correta e retorna a posi��o
 {
    aux = vet[j];
    vet[j]=vet[esq];
    vet[esq]=aux;
    return j;
}

}
void quicksort (int vet[], int esq, int dir) // esta fun��o ordena um vetor de inteiros em ordem crescente
{
    if(esq<dir){ //esta parte checa se as posi��o recebidas como argumento fazem sentido
    int pos_pivo = dividir(vet,esq,dir);
    quicksort(vet,esq,pos_pivo -1); // recurs�o da fun��o quicksort
    quicksort(vet,pos_pivo +1,dir);}
}
void elementos_prox (int vet[], int n) //esta fun��o procura elementos diferente cuja a diferen�a � a menor dentro do vetor
{
    int menor, aux, i = 1, j = 0; // a vari�vel menor armazena a diferen�a entre dois elementos do vetor
    if(n > 8)
        quicksort(vet, 0, n-1);
    else
        insertion(vet,n);
    printf("Os elementos mais proximos sao:\n");
    while (j < 1) // j serve como uma condi��o de parada da fun��o
    {
        while(vet[i] - vet[i-1] == 0 && i < n) // a linha 43 at� a linha 49 servem para verificar se o vetor cont�m apenas
            i++;                               //valores iguais e, caso sejam diferentes, a partir de qual posi��o s�o diferentes
        if(i == n)
        {
            printf("Todos os elementos sao iguais a %i.\n", vet[0]);
            j = 1; // para a fun��o
        }
    else // caso i seja diferente de n
    {
    menor = vet[i] - vet[i-1]; //menor recebe o primeiro par de valores com diferen�a diferente de 0
    aux = i; // aux recebe a posi��o do maior valor
    }
    while (i < n) //este ciclo descobre qual a menor diferen�a entre valores do vetor
    {
        if(vet[i] - vet[i-1] < menor && vet[i] - vet[i-1] > 0)
        {
         menor = vet[i] - vet[i-1];
         aux = i;
        }
        i++;
    }
    while(aux < n) // este ciclo mostra quais s�o os valores cuja diferen�a � a menor
    {
            if(vet[aux]-vet[aux-1] == menor)
            {
                printf("%i e %i\n", vet[aux-1], vet[aux]);
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
    int vet[n], x;
    printf("digite os %i valores inteiros:\n", n);
    for(x = 0; x < n; x++)
        scanf("%i", &vet[x]);
    elementos_prox(vet, n);
}
