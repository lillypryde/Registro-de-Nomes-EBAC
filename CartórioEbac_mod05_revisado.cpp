#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registrar()//fun��o respons�vel por cadastrar os usu�rios no sistema
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//in�cio da cria��o de vari�veis/strings (conjunto de vari�veis)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char ocupacao[40];
	//fim da cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coleta de informa��es do usu�rio
	scanf("%s", cpf); // scanf= refere-se � string 
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores da string
	
	FILE *file; // cria��o do arquivo
	file = fopen(arquivo, "w"); // cria��o do arquivo - w writting
	fprintf(file,cpf); // salvar o valor da vari�vel
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo, "a"); //"a" apenas para adicionar no mesmo arquivo
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
	
	printf("Digite a ocupa��o a ser cadastrada: ");
	scanf("%s",ocupacao);
	
	file = fopen(arquivo, "a");
	fprintf(file,ocupacao);
	fclose(file);	
	
    system("pause");
}

int consultar ()
{

	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
  	
	FILE *file;
	file = fopen(cpf,"r"); //r de read, para leitura, contulta apenas
  	
	if(file == NULL)// para hip�tese de consulta de usu�rio n�o cadastrado
	{
	printf("N�o foi poss�vel localizar o usu�rio!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\n Abaixo as informa��es do usu�rio consultado:\n");
	printf("%s", conteudo);
	printf("\n\n");
	}
	
  	fclose(file);
	system ("pause");
}

int deletar ()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);// apenas para deletar
	
	FILE *file; //para consultar a exist�ncia dos arquivos
	file = fopen (cpf,"r");// r de reading
	fclose(file);
	
	if(file == NULL)
	{
		printf("Usu�rio n�o cadastrado no sistema!\n");
		system ("pause");
	}
	
}

int main()
{
	int opcao=0; //definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n");//in�cio do menu
		printf("Escolha uma das op��es abaixo:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n\n");//op��o para sa�da/encerramento do sistema
		printf("Op��o Desejada:");//fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
		system("cls"); //respon�vel por limpar a tela;
	
		switch(opcao)//in�cio da sele��o do menu principal
		{
			case 1:
			registrar ();
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o nosso sistema!\n");
			return 0;
			break;
			
			default:
			printf("Esta op��o n�o est� dispon�vel\n");
			system("pause");
			break;
				
		} //fim da sele��o	
	}		
}
