/*
 * Comentário....
 */


//Adicionada para que a função gravarCliente tenha acesso às definições de registros e funções
#include <stdio.h>
#include "libImobiliarias.h"

void gravarCliente(char arqFisicoClientes[], Cliente newUser){
   FILE *arq = fopen(arqFisicoClientes, "ab");
   fwrite(&newUser,sizeof(Cliente),1,arq);
   fclose(arq);
}
