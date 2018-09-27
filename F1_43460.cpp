#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int main()
{
	FILE *Dados; // Apontador para uma estrutura de um ficheiro  
	char URL_Dados[] = { "c:\\EDA\\Ficheiro_Dados.txt" }; // String com o nome do ficheiro 

	int i;
	float *valores; // Apontador para o Array dinâmico que guarda os valores lidos do ficheiro
	float min, max; //Variáveis para o valor minimo e máximo dos dados obtidos
	float soma_total, media; //Valores para o cálculo da média
	int nlinhas;  // Nº de dados que o ficheiro contém  
	int nclasses; // Nº de classes do histograma 

	// Leitura dos dados de um ficheiro para o array valores  // 
	Dados = fopen(URL_Dados, "r"); // Abertura do ficheiro em modo de leitura

	if (Dados == NULL) // Erro na abertura do ficheiro   
		printf("Erro na abertura do ficheiro: %s\n", URL_Dados);

	else // Ficheiro aberto sem qualquer problema  
	{
		// Leitura da 1ª linha com o nº de classes do histograma   
		fscanf(Dados, "%d", &nclasses);

		// Leitura da 2ª linha com o total de valores a ler   
		fscanf(Dados, "%d", &nlinhas);

		valores = new float[nlinhas];

		// Leitura e impressão das linhas seguintes   
		max = 0;
		min = 0;
		soma_total = 0;
		printf("Amostra de Dados:\n");
		for (i = 0; i < nlinhas; i++)
		{
			fscanf(Dados, "%f", &valores[i]);
			printf("%f, ", valores[i]);

			// Para saber o valor máximo e mínimo de modo a saber as classes a criar
			if (valores[i] >= max)
			{
				max = valores[i];
			}
			if (valores[i] <= min)
			{
				min = valores[i];
			}
			// Iremos precisar de fazer já a soma, para usar na média
			soma_total = soma_total + valores[i];
		}

		printf("Numero de Classes: %d\n", nclasses);

		//Cálculos para os dados da tabela
		media = soma_total / nlinhas;


		// C O M P L E T A R  //


		delete[] valores; // Libertação da memória ocupada pelo array dinâmico 

	}
	return 0;
}