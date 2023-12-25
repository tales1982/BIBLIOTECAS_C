/*
O Bubble Sort é um algoritmo de ordenação simples que percorre repetidamente
a lista de elementos a serem ordenados, compara cada par de elementos adjacentes
e os troca se estiverem na ordem errada. Ele continua passando pela lista até
que nenhum swap seja necessário, o que indica que a lista está ordenada.

Embora seja um algoritmo simples de entender e implementar, 
o Bubble Sort não é eficiente para grandes conjuntos de dados, 
pois pode ser bastante lento, especialmente quando lidando com muitos elementos. 
Outros algoritmos de ordenação, como Quick Sort e Merge Sort, 
são mais eficientes para grandes volumes de dados.
*/

#include <stdio.h>
#define TAM 9

void bubble_sort(int *list, int size);

int	main(void)
{
	int	num[TAM]= {8,9,1,4,5,3,7,6,2};
	int	i;

	i = 0;
	printf("Antes\n");
	while (i < TAM)
	{
		printf("%d ",num[i]);
		i++;
	}
	bubble_sort(num,TAM);
}

void	swap(int *a, int *b)
{
	int	aux;
    
	aux = *a;
	*a = *b;
	*b = aux;
}

void	bubble_sort(int *list, int size)
{
	int	i;
	int	aux;
	int	flag;
	int	troca;
	int	interacao;

	i = 0;
	flag = 1;
	troca = 0;
	interacao = 0;
	while (flag)
	{
		flag = 0;
		i = 0;
		while(i < size -1)
		{
			if(list[i] > list[i + 1])
			{
				swap(&list[i], &list[i + 1]);
				flag = 1;
				troca++;
			}
			interacao++;
			i++;
		}
	}
    
	printf("\n\nDepois\n");
	i = 0;
	while (i < TAM)
	{
		printf("%d ",list[i]);
		i++;
	}
	printf("\n");
	printf("\nTrocas feitas %d\n",troca);
	printf("Interaçoes feitas %d\n",interacao);
}
