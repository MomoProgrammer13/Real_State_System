/*
 * Função responsável por gravar as informação de login do novo cliente (newUserLoginInfo) no arquivo arqFisicoLogin.
 */
#include <stdio.h>
#include "libImobiliarias.h"
void gravarNewLogingInfo(char arqFisicoLogin[], LogInfo newUserLoginInfo){
    FILE *pArqLogin = fopen (arqFisicoLogin, "ab");

    fwrite(&newUserLoginInfo, sizeof(LogInfo), 1, pArqLogin);
    fclose(pArqLogin);
}
