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

void unico (int vet[], int n) // esta fun��o analisa quais elementos de um vetor n�o se repetem
{
   if (n > 8 && n != 1) // entre as linhas 53 e 56 � checado qual o melhor algortimo de ordena��o baseado no tamanho do vetor
    quicksort(vet,0, n-1);
    if(n < 8 && n != 1)
        insertion(vet, n);
   int x = 0;
   int *valores_unicos = NULL; // este ponteiro aponta para o endere�o de mem�ria dos valores �nicos
    while(x<=n-2) // este ciclo verifica elementos �nicos entre x=0 e x=n-2
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
            x++; //Quando o ciclo terminar vet[x] ainda ser� igual ao valor que estava repetindo,
                 //adicionando +1 a x, o valor seguinte ser� diferente.
        }
    }
    if (x == n-1 && vet[x] > vet[x-1]) // verifica se apenas o �ltimo valor � �nico
    {
        valores_unicos = &vet[x];
        printf("%i\n", vet[x]);
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
    int cont, vet[n];
    for(cont = 0; cont < n; cont++)
        scanf("%i", &vet[cont]);
    printf("Os valores unicos sao:\n");
    unico(vet, n);
}
