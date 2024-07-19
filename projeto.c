#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //Fun��o responsavel por caddastrar os usu�rios no sistema
{
    //Inicio da cria��o de vari�veis/string
	char arquivo [40];
	char cpf [40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variaveis/string
	printf("Digite o cpf a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); //Responsavel por copiar os valores da string
	
	FILE *file; //Cria os arquivos
	file = fopen(arquivo,"w"); //Cria os arquivos
	fprintf(file,cpf); //Salvo o valor da variavel
	fclose(file); //Fecha o arquivo
	
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
	scanf("%s", sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
    system("pause");
}


int consulta()
{
	setlocale(LC_ALL, "portuguese"); //Definido Linguagem
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o cpf a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
    	printf("N�o foi possivel encontrar esse cpf\n");
	}
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas foram as informa��es encontradas do usuario:\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
    system("pause");

}

int excluir()
{
	setlocale(LC_ALL, "portuguese"); //Definido Linguagem
	
    char cpf[40];
    
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
        printf("Esse usu�rio n�o foi encontrado\n");
        system("pause");
}

int main ()
{
	int opcao=0; //Definindo variaveis
	int laco=1;

	for(laco=1;laco=1;)
	{
	

	   system ("cls"); //Responsavel por limpar a tela
	
       setlocale(LC_ALL, "portuguese"); //Definido Linguagem
    
       printf("### Cart�rio da EBAC ###\n\n"); //Inicio do Menu
       printf("Escolha a op��o desejada abaixo:\n\n");
       printf("\t1-Registrar usuario\n");
       printf("\t2-Consultar usuario\n");
       printf("\t3-Excluir usuario\n");
       printf("\t4-Sair do sistema\n");
	   printf("Op��o: "); //Fim do Menu
   
       scanf("%d", &opcao); //Armazenando a escolha do Usu�rio
   
       system("cls");
    
    switch(opcao) //Inicio da sele��o
	{
		//Chamada de fun��es
		case 1: 
		registro();
   	    break;
   	    
   	    case 2:
   	    consulta();
   	    break;
   	    
   	    case 3:
   	    excluir();
   	    break;
   	    
   	    case 4:
   	    printf("Obrigado por utilizar o sistema!\n");
   	    return 0;
   	    break;
   	    
   	    default:
   	     printf("Essa op��o n�o est� disponivel\n"); //Fim da Sele��o
   	    system ("pause");
   	    break;
   	    //Fim da Sele��o
	}
	
   }
   
   
}
