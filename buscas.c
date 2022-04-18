#include <stdio.h>
#define MAX_LENGHT 1000

int vetor[MAX_LENGHT];
int i;

int buscaLinear(int resp);
int buscaBinaria(int resp);
int buscaTabelada(int resp);

int main(int argc, char** argv){
	int resp, resultado;
	
	for(i = 0; i < MAX_LENGHT; i++){
		vetor[i] = i + 1;
	}
	
	printf("Escolha um valor entre 1 e 1000 para buscar: ");
	scanf("%d",& resp);
	printf("\n");
	
	resultado = buscaLinear(resp);
	resultado = buscaBinaria(resp);
	resultado = buscaTabelada(resp);
	
	if(resultado == -1){
		printf("Valor nao encontrado.");
	}
	return 0;
}

int buscaLinear(int resp){
	for(i = 0; i < MAX_LENGHT; i++){
		if(vetor[i] == resp){
			printf("O numero %d foi encontrado em %d tentativas na busca linear.\n", resp, i+1);
			return 0;
		}
	}
	return -1;
}

int buscaBinaria(int resp){
	int meio;
	int maior = vetor[MAX_LENGHT-1];
	int menor = vetor[0];
	i = 1;
	
	while(menor < maior){
		int media = (maior+menor) / 2;
		if(media == resp){
			printf("O numero %d foi encontrado em %d tentativas na busca binaria.\n", resp, i);
			return 0;
		}
		else if(media < resp){
			menor = media + 1;
		}
		else{
			maior = media;
		}
		i++;
	}
	return -1;
}

int buscaTabelada(int resp){
	int tabela_Frequencia[MAX_LENGHT + 1];
	
	if(resp < vetor[0] || resp > vetor[MAX_LENGHT - 1]){
		return -1;
	}
	for(i = 0; i < MAX_LENGHT + 1; i++){
		tabela_Frequencia[i] = 0;
	}
	for(i = 0; i < MAX_LENGHT; i++){
		tabela_Frequencia[vetor[i]]++;
	}
	i = 1;
	if(tabela_Frequencia[resp]>0){
		printf("O numero %d foi encontrado em %d tentativas na busca por tabela de frequencia.\n", resp, i);
		return 0;
	} 
	else{
		return -1;
	}
}
