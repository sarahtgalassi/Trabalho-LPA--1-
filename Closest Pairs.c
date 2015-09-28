#include <stdio.h>

main ()
{
	int cont;
	int vet [cont];
	int n = 0;
	while (n<=0){
		printf ("insira um numero \n");
		scanf ("%i", &n);
		printf("insira %i numeros inteiros", n);
	}
	
	for(cont = 0; cont<n; cont++){
		scanf ("%i", &vet[cont]);
		if (vet[cont] >= '/', vet[cont]<= ':'){
			printf ("Caractere invalido, insira apenas numeros \n");
}
	}

}
