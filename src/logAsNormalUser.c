/*
 * Função responsável por gerenciar as chamadas para as funções que realizam as operações do cliente logado.
 */
#include<stdio.h>
#include "libImobiliarias.h"
void logAsNormalUser(char arqFisicoClientes[], char arqFisicoImobiliarias[], LogInfo userLog){
    int opt;

    printf("\n**** Bem vindo %s **** \n", userLog.username);

    menuCliente(userLog.username);
    scanf("%d", &opt);
    while (opt != 6){
       switch(opt){
          case 1: visualizaDadosCliente(arqFisicoClientes, userLog);
                  break;
          case 2: alterarCliente (arqFisicoClientes, userLog.username);
              break;
          case 3: listarImobiliarias(arqFisicoImobiliarias);
              break;
           case 4: printf("\nNome da imobiliária a avaliar: ");
                  char nomeImobiliaria[40];
                  scanf("\n%[^\n]s", nomeImobiliaria);
                  int avaliacao = avaliarImobiliaria(arqFisicoImobiliarias, nomeImobiliaria);
		  if (avaliacao == -1){
		     printf("\nImobiliaria %s não cadastrada\n", nomeImobiliaria);
		  }
		  else if (avaliacao >1 && avaliacao <= 4){
		     atualizaAvaliacaoCliente(arqFisicoClientes, userLog.username, nomeImobiliaria, avaliacao);
		  }
              break;
          case 5: visualizarAvaliacoes(arqFisicoClientes, userLog.username);
              break;
       }

       menuCliente(userLog.username);
       scanf("%d", &opt);
    }

}
