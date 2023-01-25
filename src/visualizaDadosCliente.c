/*
 * Comentário....
 */
#include<stdio.h>
#include<string.h>
#include "libImobiliarias.h"
void visualizaDadosCliente(char arqFisicoClientes[], LogInfo userLog){
  FILE *arq = fopen(arqFisicoClientes,"rb");

  Cliente y;
  while(fread(&y, sizeof(Cliente), 1, arq) != 0){
      if(strcmp(y.login.username,userLog.username) == 0){
          printf("NOME : %s %s\n",y.nome,y.sobrenome);
          printf("Endereco : %s %d %s %s %d\n",y.endereco.rua,y.endereco.numero,y.endereco.complemento,y.endereco.cidade,y.endereco.cep);
          printf("Contato : %s %s\n",y.contato.email,y.contato.fone);
          printf("Nascimento : %d %d %d\n",y.dataNascimento.dia,y.dataNascimento.mes,y.dataNascimento.ano);
      }
  }
  fclose(arq);
}
