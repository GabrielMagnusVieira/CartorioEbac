#include <stdio.h> // biblioteca de comunica��o com o usuario
#include <stdlib.h> // biblitoeca de aloca��o de espa�o em memoria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() // fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio da cria��o de variaveis/strings
	char arquivo[40]; // "[]" refere-se a string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis
	
	printf("Digite o CPF a ser cadastrado:"); //coletando informa��o do usuario
	scanf("%s", cpf); //% refere-se a string ,scanf (tipo_da_vari�vel, nome_da_vari�vel)
	
	strcpy(arquivo, cpf); //Responsavel por copiar valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo  e o "w" significa escrever write
    fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	 
	 file = fopen(arquivo, "a"); //abre o arqu
	 fprintf(file,","); // salva o valor da variavel
	 fclose(file); // fecha o arquivo
	 
	 printf("Digite o nome a ser cadastrado:"); //coletando informa��o do usuario
	 scanf("%s" ,nome);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file,nome); // salva o valor da variavel
	 fclose(file); // fecha o arquivo
	 
	 printf("Digite o sobrenome a ser cadastrado:"); //coletando informa��o do usuario
	 scanf("%s",sobrenome); //% refere-se a string
	 
	 file = fopen(arquivo, "a");
	 fprintf(file,sobrenome); // salva o valor da variavel
	 fclose(file); // fecha o arquivo
	 
	 file = fopen(arquivo, "a");
	 fprintf(file,","); // salva o valor da variavel
	 fclose(file); // fecha o arquivo
	 
	 printf("Digite o cargo a ser cadastrado:"); //coletando informa��o do usuario
	 scanf("%s",cargo); //% refere-se a string
	 file = fopen(arquivo,"a");
	 fprintf(file,cargo); // salva o valor da variavel
	 fclose(file); // fecha o arquivo
	 
	 system("pause"); // pausa a leitura do codigo ate outra a��o
	 
	 
}

int consulta() //fun��o responsavel por consultar nome de usuario
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a lingaugem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado:");
	scanf("%s",cpf); //% refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //procura o cpf na pasta
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");   // pausa a leitura do codigo ate outra a��o
}
int deletar() // fun��o responsavel por deleatar o usuario 
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado:");
	scanf("%s",cpf); //% refere-se a string
	
	remove(cpf); //op�ao deletar
	
	FILE *file; //chamar a pasta "file"
	file = fopen(cpf,"r"); // abrir a pasta" file"
	 
	if(file == NULL) //Condi��o para arquivo nao encontrado
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause"); // pausa a leitura do codigo ate outra a��o
	
	}
	
}

int main() // fun��o principal
    {
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) //looping para retornar ao menu principal
	{
		system("cls"); //Responsavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a lingaugem
	
		printf("### Cart�rio da EBAC ###\n\n"); //inic�o do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o:");// fim do menu
	
		scanf("%d" ,&opcao); //armazenando a escolha do usu�rio "%d"= numero inteiro "&op�ao" = variavel 0
	
		system("cls"); // limpar a tela
		
		switch(opcao) // inicio da sele�ao do menu
		{
			case 1: //":" funciona como se fosse uma chave
			registro(); //chamada de fun�oes
			break; //fim da chave
			
			case 2:
			consulta(); //chamada de fun�oes
			break;
			
			case 3:
			deletar(); //chamada de fun�oes
			break;
			
	
			default: // op�ao invalida
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
			
			
		}
	
    
	}
}

