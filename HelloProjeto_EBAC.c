#include <stdio.h> //Biblioteca de cominucação com o usuário
#include <locale.h> //Biblioteca de texto por região/idioma
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
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
    
    printf("Registrar usuário:\n\n\n");
    
    printf("Digite seu CPF a ser cadastrado: ");
    scanf("%s", cpf); //"Salva" um pequeno espaço na memória para registrar a informação
    
    strcpy(arquivo, cpf); //Nota: Copia os valores das stings
    
    FILE *file; //Cria o arquivo
    file = fopen(arquivo, "w"); //Caminho para criar/salvar o arquivo
    fprintf(file,cpf); //Para salvar a variável
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
    
    char cpf[30]; //"Char" - Apontacriação de caracteres
    char conteudo[200];
    
    printf("\\/ CONSULTA - REGISTRO DE USUÁRIOS CADASTRADOS \\/\n");
    printf("   ¨¨¨¨¨¨¨¨   ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n");
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file; //"*" < Aponta ao arquivo desejado
    file = fopen(cpf, "r"); //Abre o arquivo utilizando o "r" - read -para leitura

    if(file == NULL) //Função "SE"
    {
    	printf("\nATENÇÃO:\nNão foi possível localizar o usuário; Usuário não cadastrado!\n");
		printf("Favor confirmar o CPF informado.\n\n");
		system("pause"); //Pausar tela
		return 0; //Retorna ao inicio da Main (menu).
	}
	
    while (!feof(file)) //Enquanto não se chegar no final do arquivo
    {
       conteudo == fgets(conteudo, 200, file);  // o 'fgets' lê os caracteres ou até o '\n'
       if (conteudo)  // Se foi possível ler
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
  
  	printf("\\/ EXCLUIR USUÁRIOS DO BANCO DE DADOS \\/\n");
 	 printf("   ¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨\n\n");
 	 printf("Digite o CPF do usuário a ser deletado: ");
 	 scanf("%s",cpf);
  
 	 FILE *file;
 	 file = fopen(cpf, "r"); 
  
 	 if(file)
 	 {
   		 printf("*Usuário localizado*\n\n");
   		 printf("\tATENÇÃO: Tem certeza que deseja excluir o usuário?\n");
   		 printf("\t       1 - SIM | 2 - NÃO- Retorne ao menu\n");
    	 printf("\nOPÇÃO: ");
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
    	printf("\nCPF não localizado -Retorne ao menu\n");
    	system("pause");
}

int deletar2()
{
  	char cpf[30];

  	printf("Confirme o CPF do usuário a ser deletado: ");
  	scanf("%s",cpf);
  
  	FILE *file;
 	file = fopen(cpf, "r"); 
  
  	if(file)
  	{
 		printf("Usuário removido com sucesso!\n\n");
 		fclose(file);
  	
  		remove(cpf);
  	}
  	if(file == NULL)
 	 {
 		 printf("\n\nCPF não localizado -Retorne ao menu\n");	
 	 }
}

int confirmasair()
{
   	int confirmasair=0;
   
  	printf("Tem certeza que deseja sair?\n\n");
  	printf("Aperte 1 - Sair | 2 - Voltar ao Menu");
  	printf("\n\nOpção: ");
   
   scanf("%d", &confirmasair);
   
   if (confirmasair==1)
   {
		system("cls");
   		printf("\n\nSaindo.. Até logo..");
   		exit (0);
   }
   	
   if (confirmasair==2)
   {
   	    return 0;
   }
}


int main() //Função principal do projeto
{   
   int opcao=0; //Definição de variável
   int repetir=1; //Definição da função para voltar
   
   for(repetir=1;repetir=1;) //Função para voltar do começo
      {
   	
   	  system("cls"); //Zerar tela
   
      setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
   
      printf("\t     ||| Olá Mundo! Olá curso! ||| \n\n\n"); //Titulo
      printf("\t  Cartório de registros-Projeto EBAC\n"); //Inicio do menu
      printf("\t -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_- \n \n");
      printf("\t       Escolha a opção do menu:\n");
      printf("1 > Registrar \n");
      printf("2 > Consultar \n");
      printf("3 > Deletar nomes \n\n");
      
      printf("Opção: "); //Fim do Menu
   
      scanf("%d", &opcao); //Armazenar a escolha do usuário
   
      system("cls"); //Inicio de nova tela com as opções abaixo
   
      switch(opcao)  //Inicio das opções (Nota pessoal: função Switch, melhor nos casos de Menu's
      {
   	      case 1: //opções do menu
          registrar();
   	      break;
   	   
   	      case 2:
   	      consultar();
          break;
       
          case 3:
          deletar();
	      break;	
	   
	      default:
	      printf("*Opção inválida; Favor definir uma opção válida no Menu-\n\n");
	      system("pause"); //Pausa a tela
	      break; //Evita possiveis erros de programação, "encerrando" a função.
	    	
      } //fim da seleção
   }
   
}
