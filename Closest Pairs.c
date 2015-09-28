#include <stdio.h>

void insertion (int vet[], int tamanho)
{
		int i;
	int j;
	int aux;
	for (i = 1; i < tamanho; i++){                   	// percorre da esquerda para a direita
            aux = vet[i];                            	// separa-se o valor a ser ordenado
            j = i - 1;
            while ((j>=0) && (aux < vet[j])) {    	 	// percorre da direita para a esquerda até o 1º termo
 vet[j+1] = vet[j]          ;                		 	//Se auxiliar é menor, os valores maiores serão copiados para a posição seguinte
               j--;
         }
         if (i != j + 1) {
vet[j+1] = aux;                                      	//Se auxiliar é maior, ela ocupa a posição
         }
      }
    }
int dividir (int vet[], int esq, int dir) // esta função coloca o pivô do vetor em sua posição correta
{
    int aux, i = esq + 1, j = dir; // esq é o elemento tomado com pivô e dir é o último elemento do vetor
    while(i <= j) // este ciclo percorre todo o vetor até encontrar a posição correta do pivô
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
    if (j >= 0) // esta parte coloca o pivô em sua posição correta e retorna a posição
 {
    aux = vet[j];
    vet[j]=vet[esq];
    vet[esq]=aux;
    return j;
}

}
void quicksort (int vet[], int esq, int dir) // esta função ordena um vetor de inteiros em ordem crescente
{
    if(esq<dir){ //esta parte checa se as posição recebidas como argumento fazem sentido
    int pos_pivo = dividir(vet,esq,dir);
    quicksort(vet,esq,pos_pivo -1); // recursão da função quicksort
    quicksort(vet,pos_pivo +1,dir);}
}
void elementos_prox (int vet[], int n) //esta função procura elementos diferente cuja a diferença é a menor dentro do vetor
{
    int menor, aux, i = 1, j = 0; // a variável menor armazena a diferença entre dois elementos do vetor
    if(n > 8)
        quicksort(vet, 0, n-1);
    else
        insertion(vet,n);
    printf("Os elementos mais proximos sao:\n");
    while (j < 1) // j serve como uma condição de parada da função
    {
        while(vet[i] - vet[i-1] == 0 && i < n) // a linha 43 até a linha 49 servem para verificar se o vetor contém apenas
            i++;                               //valores iguais e, caso sejam diferentes, a partir de qual posição são diferentes
        if(i == n)
        {
            printf("Todos os elementos sao iguais a %i.\n", vet[0]);
            j = 1; // para a função
        }
    else // caso i seja diferente de n
    {
    menor = vet[i] - vet[i-1]; //menor recebe o primeiro par de valores com diferença diferente de 0
    aux = i; // aux recebe a posição do maior valor
    }
    while (i < n) //este ciclo descobre qual a menor diferença entre valores do vetor
    {
        if(vet[i] - vet[i-1] < menor && vet[i] - vet[i-1] > 0)
        {
         menor = vet[i] - vet[i-1];
         aux = i;
        }
        i++;
    }
    while(aux < n) // este ciclo mostra quais são os valores cuja diferença é a menor
    {
            if(vet[aux]-vet[aux-1] == menor)
            {
                printf("%i e %i\n", vet[aux-1], vet[aux]);
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
    int vet[n], x;
    printf("digite os %i valores inteiros:\n", n);
    for(x = 0; x < n; x++)
        scanf("%i", &vet[x]);
    elementos_prox(vet, n);
}
