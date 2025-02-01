#include <stdio.h> //Bibioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca respons�vel pelas strings

int registro()
{
		char arquivo[11];
		char nome[20];
		char sobrenome[20];
		char cpf[12];
		char cargo[40];
		
		printf("Registro de alunos: \n");
		printf("Digite o CPF sem pontos: ");
		scanf("%s", cpf);
		
		strcpy(arquivo, cpf); //Respons�vel por copiar o valor das strings
		
		FILE *file; //Cria o arquivo
		file = fopen(arquivo, "w");
		fprintf(file,cpf); //Salva o valor da vari�vel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file,"\nNome: ");
		fclose(file);
		
		printf("Digite o nome: \n");
		scanf("%s",nome);
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,"\nSobrenome: ");
		fclose(file);
		
		printf("Digite o sobrenome: \n");
		scanf("%s",sobrenome);
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,"\nCargo: ");
		fclose(file);
		
		printf("Digite o cargo: \n");
		scanf("%s",cargo);
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
		
		system("pause");
}

int consulta()
{
		char cpf[11];
		char conteudo[250];
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("Digite o CPF a ser consultado: \n");
		scanf("%s",cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL)
		{
			printf("N�o localizado \n");
		}
		
		while(fgets(conteudo, 250, file) != NULL) 
		{
			printf("%s", conteudo);
			printf("\n");
		}
		
		system("pause");
}

int remover()
{
		char cpf[11];
		
		printf("Digite o CPF a ser deletado: ");
		scanf("%s",cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(remove(cpf) == 0) {
    printf("Removido!\n");
} 
        else {
    	printf("Erro!\n");
}
}

int main()
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for (laco=1;laco=1;) //Iniciando a repeti��o
	{ 
	
	system("cls");
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("    Cart�rio Da EBAC    \n\n"); 
	printf("Escolha a op��o que deseja utilizar: \n\n"); //Inicio do menu inicial
	printf("\t1 - Registrar Aluno \n");
	printf("\t2 - Consultar Aluno \n");
	printf("\t3 - Deletar Registro \n\n");
	printf("Op��o: "); // Fim do meni inicial
	
	scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	system("cls"); 
	
	switch(opcao)
	{
		case 1:
		registro();
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		remover();
		break;
		
		default:
			printf("Op��o inv�lida \n");
		system("pause");
		break;
	}
 }
 return 0;
}
