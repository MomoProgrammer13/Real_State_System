/*
 * Comentário....
 */
#include<stdio.h>
#include "libImobiliarias.h"
/****** Completar *****/
void listarImobiliarias(char arqFisicoImobiliarias[]){
    FILE *arq = fopen(arqFisicoImobiliarias,"rb");

    Imobiliaria imo;

    while(fread(&imo,sizeof(Imobiliaria),1,arq) != 0)
    {
      printf("------%s-------\n",imo.nome);
      printf("ID: %d\n",imo.id);
      printf("Endereco: %s %d %s %s %d\n",imo.endereco.rua,imo.endereco.numero,imo.endereco.complemento,imo.endereco.cidade,imo.endereco.cep);
      printf("Fone: %s\n",imo.contato.fone);
      printf("Email: %s\n",imo.contato.email);
      printf("Tipo de imoveis:\n");

      if(imo.tipoDeImovel.casa == 1)
        printf("    casa\n");
      if(imo.tipoDeImovel.sobrado == 1)
        printf("    sobrado\n");
      if(imo.tipoDeImovel.apartamento == 1)
        printf("    apartamento\n");
      if(imo.tipoDeImovel.terreno == 1)
        printf("    terreno\n");
      if(imo.tipoDeImovel.casa == 1)
        printf("    chacarra\n");
      if(imo.tipoDeImovel.sitio == 1)
        printf("    sitio\n");
      if(imo.tipoDeImovel.fazenda == 1)
        printf("    fazenda\n");

      printf("Avaliacoes\n");
      printf("     Ruim: (%d/%d)\n",imo.avaliacao.ruim,imo.avaliacao.ruim + imo.avaliacao.bom + imo.avaliacao.excelente);
      printf("     Boa: (%d/%d)\n",imo.avaliacao.bom,imo.avaliacao.ruim + imo.avaliacao.bom + imo.avaliacao.excelente);
      printf("     Excelente: (%d/%d)\n",imo.avaliacao.excelente,imo.avaliacao.ruim + imo.avaliacao.bom + imo.avaliacao.excelente);
    }

    fclose(arq);
}
