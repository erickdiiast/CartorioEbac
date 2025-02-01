#include <stdio.h> //Bibioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca respons�vel pelas strings

int ultima_matricula = 0; // Vari�vel global para controlar a �ltima matr�cula usada

	void gerar_matricula(char *matricula)
	{
		FILE *file = fopen("ultima_matricula.dat", "r"); // Carrega o �ltimo n�mero do arquivo
		if(file != NULL)
		{
			fscanf(file, "%d", &ultima_matricula);
			fclose(file);
		}
		
		ultima_matricula++;
		sprintf(matricula, "%06d", ultima_matricula);
		
		file = fopen("ultima_matricula.dat", "w");
		fprintf(file, "%d", ultima_matricula);
		fclose(file);
	}

	void registro()
	{
		char matricula[7];
		char cpf[12];
		char nome[20];
		char sobrenome[20];
		char cargo[40];
		
		gerar_matricula(matricula); // Gera nova matr�cula
		
		printf("\nNova matr�cula: %s\n", matricula);
		printf("CPF (somente N�meros): ");
		scanf("%11s", cpf);
		
		FILE *file = fopen(matricula, "w");
		fprintf(file, "Matr�cula: %s\nCPF: %s\n", matricula, cpf);
		
		printf("Nome: ");
		scanf("%19s", nome);
		fprintf(file, "Nome: %s\n", nome);
		
		printf("Sobrenome: ");
		scanf("%19s", sobrenome);
		fprintf(file, "Sobrenome: %s\n", sobrenome);
		
		printf("Cargo: ");
		scanf("%39s", cargo);
		fprintf(file, "Cargo: %s\n", cargo);
		
		fclose(file);
		printf("Registro Conclu�do!");
		system("pause");
	}
	
	void consulta() 
	{
    char matricula[7];
    char conteudo[250];
    
    printf("Matr�cula para consulta: ");
    scanf("%6s", matricula);
    
    FILE *file = fopen(matricula, "r");
    if(file == NULL) 
	{
        printf("Matr�cula n�o encontrada!\n");
        system("pause");
        return;
    }
    
    printf("\n--- Dados do Aluno ---\n");
    while(fgets(conteudo, 250, file) != NULL) {
        printf("%s", conteudo);
    }
    fclose(file);
    system("pause");
}
    
    
	void remover() 
	{
    	char matricula[7];
    	printf("Matr�cula para remover: ");
    	scanf("%6s", matricula);
    
    	if(remove(matricula) == 0) 
		{
        printf("Registro removido com sucesso!\n");
    	} 
		else 
		{
        printf("Erro ao remover registro!\n");
    	}
   		system("pause");
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
