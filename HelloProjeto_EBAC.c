#include <stdio.h> //Biblioteca de cominuca��o com o usu�rio
#include <locale.h> //Biblioteca de texto por regi�o/idioma
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <string.h> //Bilioteca de Strings

int registrar()
{
	int cadastrarnovo=0;
	
	setlocale(LC_ALL, "Portuguese");
	      
    char arquivo[40];
    char cpf[30];
    char nome[30];
    char sobrenome[30];
    char cargo[30];
    
    printf("Registrar usu�rio:\n\n\n");
    
    printf("Digite seu CPF a ser cadastrado: ");
    scanf("%s", cpf); //"Salva" um pequeno espa�o na mem�ria para registrar a informa��o
    
    strcpy(arquivo, cpf); //Nota: Copia os valores das stings
    
    FILE *file; //Cria o arquivo
    file = fopen(arquivo, "w"); //Caminho para criar/salvar o arquivo
    fprintf(file,cpf); //Para salvar a vari�vel
    fclose(file); // Para fechar e salvar o arquivo
    
    file = fopen(arquivo, "a"); //Abre o arquivo utuilizando o comando "a" para atualizar o mesmo
    fprintf(file,"\nNome: "); //Salva o arquivo com o dado preenchido
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,"\nSobrenome: ");
    fclose(file);
    
    printf("Digite seu sobrenome: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,"\nCargo: ");
    fclose(file);
    
    printf("Digite seu cargo: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    	
}

int consultar()
{ 
    setlocale(LC_ALL, "Portuguese");
    
    char cpf[30]; //"Char" - Apontacria��o de caracteres
    char conteudo[200];
    
    printf("\\/ CONSULTA - REGISTRO DE USU�RIOS CADASTRADOS \\/\n");
    printf("   ��������   ��������������������������������\n\n");
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file; //"*" < Aponta ao arquivo desejado
    file = fopen(cpf, "r"); //Abre o arquivo utilizando o "r" - read -para leitura

    if(file == NULL) //Fun��o "SE"
    {
    	printf("\nATEN��O:\nN�o foi poss�vel localizar o usu�rio; Usu�rio n�o cadastrado!\n");
		printf("Favor confirmar o CPF informado.\n\n");
		system("pause"); //Pausar tela
		return 0; //Retorna ao inicio da Main (menu).
	}
	
    while (!feof(file)) //Enquanto n�o se chegar no final do arquivo
    {
       conteudo == fgets(conteudo, 200, file);  // o 'fgets' l� os caracteres ou at� o '\n'
       if (conteudo)  // Se foi poss�vel ler
	   printf(conteudo,consultar);
    } 
    fclose(file);
    printf("\n\n\n"); //Pula linha

    system("pause"); //Pausar tela
}

int deletar()
{
	
  	int deletarounao=0;
  
  	char cpf[30];
  
  	printf("\\/ EXCLUIR USU�RIOS DO BANCO DE DADOS \\/\n");
 	 printf("   ����������������������������������\n\n");
 	 printf("Digite o CPF do usu�rio a ser deletado: ");
 	 scanf("%s",cpf);
  
 	 FILE *file;
 	 file = fopen(cpf, "r"); 
  
 	 if(file)
 	 {
   		 printf("*Usu�rio localizado*\n\n");
   		 printf("\tATEN��O: Tem certeza que deseja excluir o usu�rio?\n");
   		 printf("\t       1 - SIM | 2 - N�O- Retorne ao menu\n");
    	 printf("\nOP��O: ");
   		 fclose(file);
    
    scanf("%d", &deletarounao);
    
    system("cls");
  	}
  	if(deletarounao==1)
  	{
  		deletar2();
  	}
  
  	if(deletarounao==2)
  	{
  		return 0;
 	}

	if(file == NULL)
    	printf("\nCPF n�o localizado -Retorne ao menu\n");
    	system("pause");
}

int deletar2()
{
  	char cpf[30];

  	printf("Confirme o CPF do usu�rio a ser deletado: ");
  	scanf("%s",cpf);
  
  	FILE *file;
 	file = fopen(cpf, "r"); 
  
  	if(file)
  	{
 		printf("Usu�rio removido com sucesso!\n\n");
 		fclose(file);
  	
  		remove(cpf);
  	}
  	if(file == NULL)
 	 {
 		 printf("\n\nCPF n�o localizado -Retorne ao menu\n");	
 	 }
}

int confirmasair()
{
   	int confirmasair=0;
   
  	printf("Tem certeza que deseja sair?\n\n");
  	printf("Aperte 1 - Sair | 2 - Voltar ao Menu");
  	printf("\n\nOp��o: ");
   
   scanf("%d", &confirmasair);
   
   if (confirmasair==1)
   {
		system("cls");
   		printf("\n\nSaindo.. At� logo..");
   		exit (0);
   }
   	
   if (confirmasair==2)
   {
   	    return 0;
   }
}


int main() //Fun��o principal do projeto
{   
   int opcao=0; //Defini��o de vari�vel
   int repetir=1; //Defini��o da fun��o para voltar
   
   for(repetir=1;repetir=1;) //Fun��o para voltar do come�o
      {
   	
   	  system("cls"); //Zerar tela
   
      setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
   
      printf("\t     ||| Ol� Mundo! Ol� curso! ||| \n\n\n"); //Titulo
      printf("\t  Cart�rio de registros-Projeto EBAC\n"); //Inicio do menu
      printf("\t -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- \n \n");
      printf("\t       Escolha a op��o do menu:\n");
      printf("1 > Registrar \n");
      printf("2 > Consultar \n");
      printf("3 > Deletar nomes \n\n");
      
      printf("Op��o: "); //Fim do Menu
   
      scanf("%d", &opcao); //Armazenar a escolha do usu�rio
   
      system("cls"); //Inicio de nova tela com as op��es abaixo
   
      switch(opcao)  //Inicio das op��es (Nota pessoal: fun��o Switch, melhor nos casos de Menu's
      {
   	      case 1: //op��es do menu
          registrar();
   	      break;
   	   
   	      case 2:
   	      consultar();
          break;
       
          case 3:
          deletar();
	      break;	
	   
	      default:
	      printf("*Op��o inv�lida; Favor definir uma op��o v�lida no Menu-\n\n");
	      system("pause"); //Pausa a tela
	      break; //Evita possiveis erros de programa��o, "encerrando" a fun��o.
	    	
      } //fim da sele��o
   }
   
}
