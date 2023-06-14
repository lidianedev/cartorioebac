#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço em memória
#include <locale.h>//biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsavel por cuidar das string
		
int registro() //função responsável por cadastrar usuários no sistema
{
	//início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variáveis/string

	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}



int consulta()
{
	setlocale(LC_ALL, "portuguese"); //definindo linguagem
	
	char cpf [40];
	char conteudo [200];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file= fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("nao foi possivel abrir o arquivo, não localizado!\n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	
	
}


int deletar()
{
	char cpf[40];
	
	printf("digite o cpf a ser deletado ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf(" O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}



int teste()
{
	printf("funcionou a funcao pedro");
	system("pause");
}


	
	
	
int main()
	{
	int opcao=0; //Definindo variÃ¡veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls"); //responsável por limpar a tela

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		printf("### CartÃ³rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opÃ§Ã£o desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - sair do sistema\n\n");
		printf("OpÃ§Ã£o: ");//fim do menu
				
		scanf("%d", &opcao); //armazenando a escolha do usuÃ¡rio
		
		system("cls");
	
		switch(opcao) //inicio da seleÃ§Ã£o
		{
			case 1: //chamada de função
			
			registro();
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
			
			case 4:
			printf("obrigado por utilizar o sistema!\n");
			return 0;
			break;
		
			default:
			printf("Essa opÃ§Ã£o nÃ£o estÃ¡ disponivel!\n");
			system("pause");
			break;
		} //fim da seleÃ§Ã£o
			
	}	
}
		
