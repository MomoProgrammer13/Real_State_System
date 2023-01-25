/*
 * Comentário....
 */
#include<stdio.h>
#include "libImobiliarias.h"
/****** Completar *****/
void alterarImobiliaria(char arqFisicoImobiliarias[], int idImobiliaria){

   FILE *arq = fopen(arqFisicoImobiliarias,"rb");

   FILE *arqTmp = fopen("../obj/tmp.bin","wb");

   char categoria[50];
   int which;
   Imobiliaria im;

   while(fread(&im,sizeof(Imobiliaria),1,arq) != 0){
       if(im.id == idImobiliaria){

           printf("\n-------------------------\n");
           printf("1: Nome\n");
           printf("2: Endereco\n");
           printf("3: Contato\n");
           printf("4: Tipo de Imovel\n");
           printf("\n-------------------------\n");
           printf("Qual dado deseja modificar\n");
           scanf("%d",&which);

           switch (which) {
               case 1 :
                        printf("Digite o novo nome\n");
                        scanf("\n%[^\n]s",im.nome);
                        break;
               case 2 :
                        printf("Altere o nome da rua\n");
                        scanf("\n%[^\n]s", im.endereco.rua);
                        printf("Altere o numero da casa\n");
                        scanf("%d", &im.endereco.numero);
                        printf("Altere o complemento do endereco\n");
                        scanf("\n%[^\n]s", im.endereco.complemento);
                        printf("Altere a cidade\n");
                        scanf("\n%[^\n]s", im.endereco.cidade);
                        printf("Altere o CEP\n");
                        scanf("%d", &im.endereco.cep);
                        break;
              case 3 :
                        printf("Altere o numero de contato da Imobilia\n");
                        scanf("\n%[^\n]s",im.contato.fone);
                        printf("Altere o email da Imobiliaria\n");
                        scanf("\n%[^\n]s",im.contato.email);
                        break;
              case 4 :
                        strcpy(categoria,"casa");

                        if(setaCategoria(categoria) == 1)
                            im.tipoDeImovel.casa = 1;
                        else
                            im.tipoDeImovel.casa = 0;

                        strcpy(categoria,"sobrado");

                        if(setaCategoria(categoria) == 1)
                            im.tipoDeImovel.sobrado = 1;
                        else
                            im.tipoDeImovel.sobrado = 0;

                        strcpy(categoria,"apartamento");

                        if(setaCategoria(categoria) == 1)
                            im.tipoDeImovel.apartamento = 1;
                        else
                            im.tipoDeImovel.apartamento = 0;

                        strcpy(categoria,"terreno");

                        if(setaCategoria(categoria) == 1)
                            im.tipoDeImovel.terreno = 1;
                        else
                            im.tipoDeImovel.terreno = 0;

                        strcpy(categoria,"chacarra");

                        if(setaCategoria(categoria) == 1)
                            im.tipoDeImovel.chacarra = 1;
                        else
                            im.tipoDeImovel.chacarra = 0;

                        strcpy(categoria,"sitio");

                        if(setaCategoria(categoria) == 1)
                            im.tipoDeImovel.sitio = 1;
                        else
                            im.tipoDeImovel.sitio = 0;

                        strcpy(categoria,"fazenda");

                        if(setaCategoria(categoria) == 1)
                            im.tipoDeImovel.fazenda = 1;
                        else
                            im.tipoDeImovel.fazenda = 0;
                        break;
           }
       }
       fwrite(&im,sizeof(Imobiliaria),1,arqTmp);
   }

   fclose(arq);
   fclose(arqTmp);

   remove(arqFisicoImobiliarias);

   rename("../obj/tmp.bin",arqFisicoImobiliarias);
}
