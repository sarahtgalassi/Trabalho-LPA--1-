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
void unico (int *inteiros, int n) // esta fun��o analisa quais elementos de um vetor n�o se repetem
{
   if (n > 8 && n != 1) // entre as linhas 53 e 56 � checado qual o melhor algortimo de ordena��o baseado no tamanho do vetor
    quicksort(inteiros,0, n-1);
    if(n < 8 && n != 1)
        insertion(inteiros, n);
   int x = 0;
   int *valores_unicos = NULL; // este ponteiro aponta para o endere�o de mem�ria dos valores �nicos
    while(x<=n-2) // este ciclo verifica elementos �nicos entre x=0 e x=n-2
    {
        if(*(inteiros + x + 1) > *(inteiros + x))
        {
            valores_unicos = inteiros + x;
            printf("%i\n", *(inteiros + x));
            x++;
        }
        if(*(inteiros + x + 1) == *(inteiros + x))
        {
            while(*(inteiros + x) == *(inteiros + x + 1))
                x++;
            x++; //Quando o ciclo terminar vet[x] ainda ser� igual ao valor que estava repetindo,
                 //adicionando +1 a x, o valor seguinte ser� diferente.
        }
    }
    if (x == n-1 && *(inteiros + x) > *(inteiros + x + 1)) // verifica se apenas o �ltimo valor � �nico
    {
        valores_unicos = inteiros + x;
        printf("%i\n", *(inteiros + x));
    }
    if(valores_unicos == NULL && n != 1) // se o ponteiro n�o apontar para nenhum endere�o de mem�ria, ent�o n�o h� valores �nicos
        printf("Nao ha valores unicos.\n");
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
    printf("\nOs valores unicos sao:\n");
    unico(inteiros, n);
    free(inteiros);

}
