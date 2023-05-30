#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registrar()//função responsável por cadastrar os usuários no sistema
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//início da criação de variáveis/strings (conjunto de variáveis)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char ocupacao[40];
	//fim da criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //coleta de informações do usuário
	scanf("%s", cpf); // scanf= refere-se à string 
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores da string
	
	FILE *file; // criação do arquivo
	file = fopen(arquivo, "w"); // criação do arquivo - w writting
	fprintf(file,cpf); // salvar o valor da variável
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
	
	printf("Digite a ocupação a ser cadastrada: ");
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
  	
	if(file == NULL)// para hipótese de consulta de usuário não cadastrado
	{
	printf("Não foi possível localizar o usuário!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\n Abaixo as informações do usuário consultado:\n");
	printf("%s", conteudo);
	printf("\n\n");
	}
	
  	fclose(file);
	system ("pause");
}

int deletar ()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);// apenas para deletar
	
	FILE *file; //para consultar a existência dos arquivos
	file = fopen (cpf,"r");// r de reading
	fclose(file);
	
	if(file == NULL)
	{
		printf("Usuário não cadastrado no sistema!\n");
		system ("pause");
	}
	
}

int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n");//início do menu
		printf("Escolha uma das opções abaixo:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n\n");//opção para saída/encerramento do sistema
		printf("Opção Desejada:");//fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls"); //responável por limpar a tela;
	
		switch(opcao)//início da seleção do menu principal
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
			printf("Esta opção não está disponível\n");
			system("pause");
			break;
				
		} //fim da seleção	
	}		
}
