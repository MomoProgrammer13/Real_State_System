
#include<stdio.h>
#include <string.h>
#include "libImobiliarias.h"

void cadastraImobiliaria(char arqFisicoImobiliarias[]){
    FILE *arq = fopen(arqFisicoImobiliarias,"rb");

    int ide=0;
    char categoria[40];
    Imobiliaria im;
    Imobiliaria ima;

    printf("Digite o nome da imobiliaria a ser cadastrada\n");
    scanf("\n%[^\n]s", im.nome);


    do{
        ide++;
        if(strcmp(ima.nome,im.nome) == 0){
            printf("Imobiliaria ja cadastrada,digite outro nome\n");
            scanf("\n%[^\n]s", im.nome);
            rewind(arq);
        }
    }while(fread(&ima,sizeof(Imobiliaria),1,arq) != 0);

    im.id = ide;

    printf("Digite a rua da imobiliaria\n");
    scanf("\n%[^\n]s", im.endereco.rua);
    printf("Digite o numero\n");
    scanf("%d",&im.endereco.numero);
    printf("Digite o complemento\n");
    scanf("\n%[^\n]s", im.endereco.complemento);
    printf("Digite a cidade\n");
    scanf("\n%[^\n]s", im.endereco.cidade);
    printf("Digite o cep\n");
    scanf("%d",&im.endereco.cep);
    printf("Digite o numero de contato\n");
    scanf("\n%[^\n]s", im.contato.fone);
    printf("Digite o email\n");
    scanf("\n%[^\n]s", im.contato.email);
    im.avaliacao.ruim = 0;
    im.avaliacao.bom = 0;
    im.avaliacao.excelente = 0;

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
                                           
    gravarImobiliaria(arqFisicoImobiliarias,im);

    fclose(arq);
}
