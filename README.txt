Trabalho de Linguagens de Programação e Aplicações - SCC300
Professor: Adenilso Simão

Alunos: Sarah Tatsuta Galassi 	 	9311650		sarahtgalassi
	Fábio Assis de Campos Junior    9312761		

1) Informações gerais
Linguagem utilizada: C (.c)
Ambiente de desenvolvimento dos programas: Dev-C++ (versão 5.10) e Code::Blocks (versão 13.12)
Compilador para a criação dos executáveis: TDM-GCC MinGW 4.8.1 32 bit Profiling (padrão). 
Há ainda a possibilidade de se compilar o código via linhas de comando, no próprio executável.
Bibliotecas utilizadas: stdio.h e stdlib.h
Parâmetros de compilação: padrão dos ambientes usados

2) Closest Pair
O programa "Closest Pair tem como objetivo encontrar, dados determinados elementos componentes 
de um vetor, o par (ou pares) com menor diferença de valor entre eles.
O código do programa é composto por duas funções de ordenação (há a possibilidade de o programa 
utilizar a função "Quicksort" ou a função "Insertion", dependendo da quantidade de elementos a 
serem ordenados), pela função "elementos_prox", que compara os elementos vizinhos depois de 
ordenados) para localizar os elementos com a menor diferença entre eles e imprimir esse par. 
Se todos os valores inseridos no vetor forem iguais, o programa imprime uma mensagem indicando 
isso; e se existirem mais de um par de elementos com a mesma diferença mínima, o programa 
imprimirá todos os pares que apresentam essa diferença. A função main do programa é responsável 
por receber os elementos do vetor, bem como chamar a função elementos_prox.


3) Element Uniqueness
O programa "Element Uniqueness" tem como objetivo encontrar os elementos que aparecem uma única 
vez em um vetor dado.
O código do programa é composto por duas funções de ordenação (há a possibilidade de o programa 
utilizar a função "quicksort" ou a função "insertion", dependendo da quantidade de elementos a 
serem ordenados), pela função "unico", que compara elementos vizinhos (com o vetor já ordenado) 
para identificar os elementos que não tem como vizinho elementos idênticos. Após feita a checagem, 
o programa imprime os valores que são únicos no vetor e, caso não existam nenhum, o programa 
imprime uma mensagem de que todos os valores são repetidos ao menos uma vez. A função main do 
programa é responsável por receber os elementos do vetor, bem como chamar a função unico.

4) Frequency Distribution
O programa "Frequency Distribution" tem como objetivo encontrar os elementos que mais se repetem 
em um vetor dado.
O código do programa é composto por duas funções de ordenação (há a possibilidade de o programa 
utilizar a função "quicksort" ou a função "insertion", dependendo da quantidade de elementos a 
serem ordenados), pela função "mais_repete", que identifica o número de vezes que cada entrada 
se repete em um determinado vetor e armazena esse valor, de modo que os compara depois e define 
o elemento com maior frequência, imprimindo esse elemento. Caso mais de um valor apresente a 
frequência máxima, todos os valores são impressos. A função main do programa é responsável por 
receber os elementos do vetor, bem como chamar a função mais_repete.