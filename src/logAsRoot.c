/*
 * Completar comentário
 */

#include<stdio.h>
//libImobiliarias.h é inclusa para que a função logAsRoot tenha acesso às definições de registros, funções e constantes
#include "libImobiliarias.h"
void logAsRoot(char arqFisicoClientes[], char arqFisicoLogin[], char arqFisicoImobiliarias[]){
    printf("\n**** Bem vindo root **** \n");
    int opt, idImobiliaria,testa;
    char username[MAX_USER];
    menuRoot();
    scanf("%d", &opt);
    while (opt != 9){
        switch(opt){
            case 1 :  if(cadastraCliente(arqFisicoClientes, arqFisicoLogin, username) == -1)
                        printf("Usuario ja cadastrado\n");
                      else
                        printf("Usuario cadastrado com sucesso\n");
                    break;

            case 2 :
                    cadastraImobiliaria(arqFisicoImobiliarias);
                    break;

            case 3 :
                        printf("Digite o nome que deseja ser alterado\n");
                        scanf("\n%[^\n]s",username);
                        if(alterarCliente(arqFisicoClientes,username) == -1)
                            printf("Usuario nao encontrado\n");
                        else
                            printf("Dados alterados com sucesso\n");
                    break;
            case 4 :
                    printf("Digite o id da Imobiliaria que deseja ser alterado os dados\n");
                    scanf("%d",&idImobiliaria);
                    alterarImobiliaria(arqFisicoImobiliarias,idImobiliaria);
                    break;

            case 5 :
                    printf("Digite o nome que deseja ser removido\n");
                    scanf("\n%[^\n]s",username);
                    testa = removerCliente(arqFisicoClientes,arqFisicoLogin,username);
                    if(testa == -1)
                        printf("Usuario nao foi encontrado\n");
                    else if (testa == 0)
                        printf("Usuario removido com sucesso\n");
                    break;
            case 6 :
                    printf("Digite o id da Imobiliaria que deseja remover\n");
                    scanf("%d",&idImobiliaria);
                    removerImobiliaria(arqFisicoImobiliarias,idImobiliaria);
                    break;
            case 7 : listarClientes(arqFisicoClientes);
                    break;
            case 8: listarImobiliarias(arqFisicoImobiliarias);
                    break;
       }

       menuRoot();
       scanf("%d", &opt);
    }
}
