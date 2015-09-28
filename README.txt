Trabalho de Linguagens de Programa��o e Aplica��es - SCC300
Professor: Adenilso Sim�o

Alunos: Sarah Tatsuta Galassi 	 	9311650		sarahtgalassi
	F�bio Assis de Campos Junior    9312761		

1) Informa��es gerais
Linguagem utilizada: C (.c)
Ambiente de desenvolvimento dos programas: Dev-C++ (vers�o 5.10) e Code::Blocks (vers�o 13.12)
Compilador para a cria��o dos execut�veis: TDM-GCC MinGW 4.8.1 32 bit Profiling (padr�o). 
H� ainda a possibilidade de se compilar o c�digo via linhas de comando, no pr�prio execut�vel.
Bibliotecas utilizadas: stdio.h e stdlib.h
Par�metros de compila��o: padr�o dos ambientes usados

2) Closest Pair
O programa "Closest Pair tem como objetivo encontrar, dados determinados elementos componentes 
de um vetor, o par (ou pares) com menor diferen�a de valor entre eles.
O c�digo do programa � composto por duas fun��es de ordena��o (h� a possibilidade de o programa 
utilizar a fun��o "Quicksort" ou a fun��o "Insertion", dependendo da quantidade de elementos a 
serem ordenados), pela fun��o "elementos_prox", que compara os elementos vizinhos depois de 
ordenados) para localizar os elementos com a menor diferen�a entre eles e imprimir esse par. 
Se todos os valores inseridos no vetor forem iguais, o programa imprime uma mensagem indicando 
isso; e se existirem mais de um par de elementos com a mesma diferen�a m�nima, o programa 
imprimir� todos os pares que apresentam essa diferen�a. A fun��o main do programa � respons�vel 
por receber os elementos do vetor, bem como chamar a fun��o elementos_prox.


3) Element Uniqueness
O programa "Element Uniqueness" tem como objetivo encontrar os elementos que aparecem uma �nica 
vez em um vetor dado.
O c�digo do programa � composto por duas fun��es de ordena��o (h� a possibilidade de o programa 
utilizar a fun��o "quicksort" ou a fun��o "insertion", dependendo da quantidade de elementos a 
serem ordenados), pela fun��o "unico", que compara elementos vizinhos (com o vetor j� ordenado) 
para identificar os elementos que n�o tem como vizinho elementos id�nticos. Ap�s feita a checagem, 
o programa imprime os valores que s�o �nicos no vetor e, caso n�o existam nenhum, o programa 
imprime uma mensagem de que todos os valores s�o repetidos ao menos uma vez. A fun��o main do 
programa � respons�vel por receber os elementos do vetor, bem como chamar a fun��o unico.

4) Frequency Distribution
O programa "Frequency Distribution" tem como objetivo encontrar os elementos que mais se repetem 
em um vetor dado.
O c�digo do programa � composto por duas fun��es de ordena��o (h� a possibilidade de o programa 
utilizar a fun��o "quicksort" ou a fun��o "insertion", dependendo da quantidade de elementos a 
serem ordenados), pela fun��o "mais_repete", que identifica o n�mero de vezes que cada entrada 
se repete em um determinado vetor e armazena esse valor, de modo que os compara depois e define 
o elemento com maior frequ�ncia, imprimindo esse elemento. Caso mais de um valor apresente a 
frequ�ncia m�xima, todos os valores s�o impressos. A fun��o main do programa � respons�vel por 
receber os elementos do vetor, bem como chamar a fun��o mais_repete.