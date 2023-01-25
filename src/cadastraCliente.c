/*
 * Comentário
 */
#include<stdio.h>
#include<string.h>
#include"libImobiliarias.h"
/****** Completar *****/

int cadastraCliente(char arqFisicoClientes[], char arqFisicoLogin[], char username[]){
    FILE *arq = fopen(arqFisicoClientes, "a+b");
    if(arq == NULL){
        printf("Nao foi possivel abrir o arquivo na funcao cadastradaCliente\n");
        return 1;
    }

    FILE *arqC = fopen(arqFisicoLogin, "a+b");
    if(arqC == NULL){
        printf("Nao foi possivel abrir o arquivo na funcao cadastradaCliente\n");
        return 1;
    }

    Cliente newUser;
    Cliente user;
    LogInfo newUserLoginInfo;
    printf("Digite o nome do novo cliente\n");
    scanf("\n%[^\n]s", newUser.login.username);
    while(fread(&user,sizeof(Cliente),1,arq) != 0){
        if(strcmp(newUser.login.username,user.login.username) == 0){
            return -1;
        }
    }


    printf("Digite o sobrenome do Cliente\n");
    scanf("\n%[^\n]s",newUser.sobrenome);
    printf("Digite a senha do novo cliente\n");
    scanf("\n%[^\n]s", newUser.login.passwd);
    printf("Digite o nome da rua\n");
    scanf("\n%[^\n]s", newUser.endereco.rua);
    printf("Digite o numero da casa\n");
    scanf("%d", &newUser.endereco.numero);
    printf("Digite o complemento do endereco\n");
    scanf("\n%[^\n]s", newUser.endereco.complemento);
    printf("Digite a cidade\n");
    scanf("\n%[^\n]s", newUser.endereco.cidade);
    printf("Digite o CEP\n");
    scanf("%d", &newUser.endereco.cep);
    printf("Digite o numero de contato do cliente\n");
    scanf("\n%[^\n]s",newUser.contato.fone);
    printf("Digite o email do cliente\n");
    scanf("\n%[^\n]s",newUser.contato.email);
    printf("Digite o dia mes e ano de nascimento do cliente\n");
    scanf("%d %d %d",&newUser.dataNascimento.dia,&newUser.dataNascimento.mes,&newUser.dataNascimento.ano);
    newUser.numeroAvaliacoes = -1;


    strcpy(newUser.nome,newUser.login.username);
    strcpy(newUserLoginInfo.username,newUser.login.username);
    strcpy(newUserLoginInfo.passwd,newUser.login.passwd);

    gravarCliente(arqFisicoClientes,newUser);
    gravarNewLogingInfo(arqFisicoLogin,newUserLoginInfo);
    fclose(arq);
    fclose(arqC);
    return 0;
}
