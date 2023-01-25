/*
 * Comentário....
 */
#include <stdio.h>
#include <string.h>
#include "libImobiliarias.h"
/****** Completar *****/
int alterarCliente(char arqFisicoClientes[], char usernameCliente[]){
      FILE *arq = fopen(arqFisicoClientes,"a+b");
      FILE *arqC = fopen("../obj/tmp.bin","wb");
    int which;

    Cliente c;
    int encontrou;
    while(fread(&c , sizeof(Cliente),1,arq) !=0){
      if(strcmp(c.login.username, usernameCliente) == 0){

        printf("\n-------------------------\n");
        printf("1: Nome e sobrenome\n");
        printf("2: Endereco\n");
        printf("3: Contato\n");
        printf("4: Data de nascimento\n");
        printf("\n-------------------------\n");
        printf("Qual dado deseja modificar\n");
        scanf("%d",&which);

        encontrou = 1;

        switch (which) {
          case 1 :
                  printf("Altere o nome do cliente\n");
                  scanf("\n%[^\n]s",c.nome);
                  printf("Altere o sobrenome do Cliente\n");
                  scanf("\n%[^\n]s",c.sobrenome);
                  break;
          case 2 :
                  printf("Altere o nome da rua\n");
                  scanf("\n%[^\n]s", c.endereco.rua);
                  printf("Altere o numero da casa\n");
                  scanf("%d", &c.endereco.numero);
                  printf("Altere o complemento do endereco\n");
                  scanf("\n%[^\n]s", c.endereco.complemento);
                  printf("Altere a cidade\n");
                  scanf("\n%[^\n]s", c.endereco.cidade);
                  printf("Altere o CEP\n");
                  scanf("%d", &c.endereco.cep);
                  break;
        case 3 :
                  printf("Altere o numero de contato do cliente\n");
                  scanf("\n%[^\n]s",c.contato.fone);
                  printf("Altere o email do cliente\n");
                  scanf("\n%[^\n]s",c.contato.email);
                  break;
        case 4 :
                  printf("Altere o dia mes e ano de nascimento do cliente\n");
                  scanf("%d %d %d",&c.dataNascimento.dia,&c.dataNascimento.mes,&c.dataNascimento.ano);

        }
      }
        fwrite(&c,sizeof(Cliente),1,arqC);
    }
    if(encontrou != 1)
      return -1;

    fclose(arq);
    fclose(arqC);

    remove(arqFisicoClientes);

    rename("../obj/tmp.bin",arqFisicoClientes);

   return 0;
}
