/*
 * Comentário....
 */
#include  <stdio.h>
#include "libImobiliarias.h"

void gravarImobiliaria(char arqFisicoImobiliarias[], Imobiliaria imobiliaria){


    FILE *arq = fopen(arqFisicoImobiliarias,"ab");

    fwrite(&imobiliaria,sizeof(Imobiliaria),1,arq);

    fclose(arq);
}
