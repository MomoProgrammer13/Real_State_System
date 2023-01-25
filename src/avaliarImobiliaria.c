/*
 * Comentário....
 */
#include<stdio.h>
#include <string.h>
#include "libImobiliarias.h"
/****** Completar *****/
int avaliarImobiliaria (char arqFisicoImobiliarias[], char nomeImobiliaria[]){
    int opt = -1;

    FILE *arq = fopen(arqFisicoImobiliarias,"rb");

    FILE *arqTmp = fopen("../obj/tmp2.bin","wb");


    if(arq == NULL)
    {
        printf("Nao foi possivel abrir o arquivo bin de imobiliária\n");
        return 1;
    }

    Imobiliaria im;

    while(fread(&im,sizeof(Imobiliaria),1,arq) != 0)
    {
        if(strcmp(nomeImobiliaria,im.nome) == 0)
        {
            printf("\n---------\n");
            printf("Ruim : 2\n");
            printf("Bom :  3\n");
            printf("Excelente:  4\n");
            scanf("%d",&opt);
            if(opt == 2)
                im.avaliacao.ruim++;
            else if(opt == 3)
                im.avaliacao.bom++;
            else if(opt == 4)
                im.avaliacao.excelente++;
        }
        fwrite(&im,sizeof(Imobiliaria),1,arqTmp);
    }

    fclose(arq);
    fclose(arqTmp);

    remove(arqFisicoImobiliarias);

    rename("../obj/tmp2.bin",arqFisicoImobiliarias);

    return opt;
}
