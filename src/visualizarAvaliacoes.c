/*
 * Comentário....
 */
#include<stdio.h>
#include <string.h>
#include "libImobiliarias.h"
/****** Completar *****/
void visualizarAvaliacoes(char arqFisicoClientes[], char usernameCliente[]){

   FILE *arq = fopen(arqFisicoClientes,"rb");

   Cliente c;

   while(fread(&c,sizeof(Cliente),1,arq) != 0)
   {
       if(strcmp(c.login.username,usernameCliente) == 0)
       {
           for(int i=0; i <= c.numeroAvaliacoes; i++)
           {
               printf("\n-----Avaliacao %d-----\n",i+1);
               printf("Imobiliaria: %s\n",c.vetAvaliacoes[i].nomeImobiliaria);
               if(c.vetAvaliacoes[i].avaliacaoImobiliaria.ruim == 1)
                    printf("Avaliacao : ruim");
               else if(c.vetAvaliacoes[i].avaliacaoImobiliaria.bom == 1)
                    printf("Avaliacao : bom");
               else if(c.vetAvaliacoes[i].avaliacaoImobiliaria.excelente == 1)
                    printf("Avaliacao : excelente");
           }
       }
   }
    fclose(arq);
}
