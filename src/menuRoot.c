/*
 * Lista as operações que podem ser realizadas pelo usuário root.
*/
#include<stdio.h>
#include "libImobiliarias.h"

void menuRoot(){
   printf("\n==== Root =====");
   printf("\n1 - Cadastrar cliente.");
   printf("\n2 - Cadastrar imobiliaria.");
   printf("\n3 - Alterar dados do cliente.");
   printf("\n4 - Alterar dados da imobiliaria.");
   printf("\n5 - Remover cliente.");
   printf("\n6 - Remover imobiliaria.");
   printf("\n7 - Listar todos os clientes.");
   printf("\n8 - Listar todas as imobiliarias.");
   printf("\n9 - Logout.");
   printf("\n=======================\n");
}
