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

void unico (int vet[], int n) // esta função analisa quais elementos de um vetor não se repetem
{
   if (n > 8 && n != 1) // entre as linhas 53 e 56 é checado qual o melhor algortimo de ordenação baseado no tamanho do vetor
    quicksort(vet,0, n-1);
    if(n < 8 && n != 1)
        insertion(vet, n);
   int x = 0;
   int *valores_unicos = NULL; // este ponteiro aponta para o endereço de memória dos valores únicos
    while(x<=n-2) // este ciclo verifica elementos únicos entre x=0 e x=n-2
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
            x++; //Quando o ciclo terminar vet[x] ainda será igual ao valor que estava repetindo,
                 //adicionando +1 a x, o valor seguinte será diferente.
        }
    }
    if (x == n-1 && vet[x] > vet[x-1]) // verifica se apenas o último valor é único
    {
        valores_unicos = &vet[x];
        printf("%i\n", vet[x]);
    }
    if(valores_unicos == NULL && n != 1) // se o ponteiro não apontar para nenhum endereço de memória, então não há valores únicos
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
