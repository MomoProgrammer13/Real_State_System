/*
 * Comentário....
 */

#include <stdio.h>
#include "libImobiliarias.h"
/****** Completar *****/
void removerImobiliaria(char arqFisicoImobiliarias[], int idImobiliaria){

   FILE *arq = fopen(arqFisicoImobiliarias,"rb");

   FILE *arqt = fopen("../obj/tmp.bin","wb");

   int encontrou;
   char nome[40];
   Imobiliaria imo;


   while(fread(&imo,sizeof(Imobiliaria),1,arq) !=0)
   {
       if(imo.id == idImobiliaria){
           encontrou = 1;
       }
       else
       {
           fwrite(&imo,sizeof(Imobiliaria),1,arqt);
       }
   }

   if(!encontrou)
   {
       printf("Imobiliar nao encontrada\n");
   }
   else
   {
       printf("Imobiliaria removida com sucesso\n");
   }
   fclose(arq);
   fclose(arqt);

   remove(arqFisicoImobiliarias);

   rename("../obj/tmp.bin",arqFisicoImobiliarias);
}
