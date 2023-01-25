/*
 * Comentário....
 */
#include<stdio.h>
#include <string.h>
#include "libImobiliarias.h"
/****** Completar *****/
void atualizaAvaliacaoCliente(char arqFisicoClientes[], char usernameCliente[], char nomeImobiliaria[], int avaliacao){

  FILE *arq = fopen(arqFisicoClientes,"rb");

  FILE *arqTmp = fopen("../obj/tmp.bin","wb");
  int encontrou;
  Cliente c;

  while(fread(&c,sizeof(Cliente),1,arq) != 0)
  {
    while(fread(&c,sizeof(Cliente),1,arq) !=0){
      for(int i=0; i < c.numeroAvaliacoes;i++){
        if(strcmp(c.vetAvaliacoes[i].nomeImobiliaria,nomeImobiliaria) == 0)
          encontrou = 0;
      }
    }
          if(strcmp(usernameCliente,c.login.username) == 0 && encontrou !=0)
          {
            c.numeroAvaliacoes++;
            strcpy(c.vetAvaliacoes[c.numeroAvaliacoes].nomeImobiliaria, nomeImobiliaria);
            if(avaliacao == 2)
              c.vetAvaliacoes[c.numeroAvaliacoes].avaliacaoImobiliaria.ruim = 1;
            else if(avaliacao == 3)
              c.vetAvaliacoes[c.numeroAvaliacoes].avaliacaoImobiliaria.bom = 1;
            else if(avaliacao == 4)
              c.vetAvaliacoes[c.numeroAvaliacoes].avaliacaoImobiliaria.excelente = 1;
            }
            encontrou =1;
      }
      fwrite(&c,sizeof(Cliente),1,arqTmp);

  fclose(arq);
  fclose(arqTmp);

  remove(arqFisicoClientes);

  rename("../obj/tmp.bin",arqFisicoClientes);

}
