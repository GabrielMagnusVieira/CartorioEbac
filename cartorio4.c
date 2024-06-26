#include <stdio.h> // biblioteca de comunicação com o usuario
#include <stdlib.h> // biblitoeca de alocação de espaço em memoria
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() // função responsavel por cadastrar os usuarios no sistema
{
	//inicio da criação de variaveis/strings
	char arquivo[40]; // "[]" refere-se a string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variaveis
	
	printf("Digite o CPF a ser cadastrado:"); //coletando informação do usuario
	scanf("%s", cpf); //% refere-se a string ,scanf (tipo_da_variável, nome_da_variável)
	
	strcpy(arquivo, cpf); //Responsavel por copiar valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo  e o "w" significa escrever write
    fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	 
	 file = fopen(arquivo, "a"); //abre o arqu
	 fprintf(file,","); // salva o valor da variavel
	 fclose(file); // fecha o arquivo
	 
	 printf("Digite o nome a ser cadastrado:"); //coletando informação do usuario
	 scanf("%s" ,nome);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file,nome); // salva o valor da variavel
	 fclose(file); // fecha o arquivo
	 
	 printf("Digite o sobrenome a ser cadastrado:"); //coletando informação do usuario
	 scanf("%s",sobrenome); //% refere-se a string
	 
	 file = fopen(arquivo, "a");
	 fprintf(file,sobrenome); // salva o valor da variavel
	 fclose(file); // fecha o arquivo
	 
	 file = fopen(arquivo, "a");
	 fprintf(file,","); // salva o valor da variavel
	 fclose(file); // fecha o arquivo
	 
	 printf("Digite o cargo a ser cadastrado:"); //coletando informação do usuario
	 scanf("%s",cargo); //% refere-se a string
	 file = fopen(arquivo,"a");
	 fprintf(file,cargo); // salva o valor da variavel
	 fclose(file); // fecha o arquivo
	 
	 system("pause"); // pausa a leitura do codigo ate outra ação
	 
	 
}

int consulta() //função responsavel por consultar nome de usuario
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
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //procura o cpf na pasta
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");   // pausa a leitura do codigo ate outra ação
}
int deletar() // função responsavel por deleatar o usuario 
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:");
	scanf("%s",cpf); //% refere-se a string
	
	remove(cpf); //opçao deletar
	
	FILE *file; //chamar a pasta "file"
	file = fopen(cpf,"r"); // abrir a pasta" file"
	 
	if(file == NULL) //Condição para arquivo nao encontrado
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause"); // pausa a leitura do codigo ate outra ação
	
	}
	
}

int main() // função principal
    {
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //looping para retornar ao menu principal
	{
		system("cls"); //Responsavel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a lingaugem
	
		printf("### Cartório da EBAC ###\n\n"); //inicío do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção:");// fim do menu
	
		scanf("%d" ,&opcao); //armazenando a escolha do usuário "%d"= numero inteiro "&opçao" = variavel 0
	
		system("cls"); // limpar a tela
		
		switch(opcao) // inicio da seleçao do menu
		{
			case 1: //":" funciona como se fosse uma chave
			registro(); //chamada de funçoes
			break; //fim da chave
			
			case 2:
			consulta(); //chamada de funçoes
			break;
			
			case 3:
			deletar(); //chamada de funçoes
			break;
			
	
			default: // opçao invalida
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
			
			
		}
	
    
	}
}

