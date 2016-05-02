#include <stdlib.h>
#include <stdio.h>

#define tam (6)

/*
GRAFO DESCONEXO:
0 0 1 1 0 0
0 0 0 0 1 0
1 0 0 0 0 1
1 0 0 0 0 1
0 1 0 0 0 0
0 0 1 1 0 0

GRAFO CONEXO:
0 1 0 1 0 0
1 0 1 0 1 0
0 1 0 0 0 1
1 0 0 0 0 1
0 1 0 0 0 0
0 0 1 1 0 0
*/

void inicializarGrafo(int grafo[][tam]);
void imprimirGrafo(int grafo[][tam]);
void buscaProf(int grafo[][tam], int vIni);
void desmarcarVertices(int grafo[][tam]);
int conexo(int grafo[][tam]);

//Main
int main()
{
	int grafo[tam][tam];

	inicializarGrafo(grafo);

	if (conexo(grafo))
	{
		printf("\nGrafo conexo!\n");
	}
	else
		printf("\nGrafo nao conexo!\n");

	system("pause");
	return 0;
}

void inicializarGrafo(int grafo[][tam])
{
    printf("Informe a matriz de adjacencia do grafo:\n");

	int i, j;
	for (i = 0; i < tam; i++)
	{
		for (j = 0; j < tam; j++)
		{
			scanf("%d", &grafo[i][j]);
		}
	}
}

void imprimirGrafo(int grafo[][tam])
{
	int i, j;
	printf("\n");
	for (i = 0; i < tam; i++)
	{
		for (j = 0; j < tam; j++)
		{
			printf("%d ", grafo[i][j]);
		}
		printf("\n");
	}
}


void buscaProf(int grafo[][tam], int vIni)
{
	int i;
	for (i = 0; i < tam; i++)
	{
		if(grafo[vIni][i] == 1)
			if (grafo[vIni][i] != 2)
			{
				grafo[vIni][i] += 1;
				buscaProf(grafo, i);
			}
	}
}

int conexo(int grafo[][tam])
{
	int i, k;
	buscaProf(grafo, 0);
	for (i = 0; i < tam; i++)
	{
		for (k = 0; k < tam; k++)
		{
			if (grafo[i][k] == 1)
				return 0;
		}
	}
	
	return 1;
}
