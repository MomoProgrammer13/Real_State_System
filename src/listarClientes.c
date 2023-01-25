/*
 * Comentário....
 */
#include<stdio.h>
#include "libImobiliarias.h"
/****** Completar *****/
void listarClientes(char arqFisicoClientes[]){
    FILE *arq = fopen(arqFisicoClientes, "rb");
    Cliente user;
    while(fread(&user,sizeof(Cliente),1,arq) != 0){
        printf("Usuario : %s\n",user.login.username);
    }
    fclose(arq);
}
