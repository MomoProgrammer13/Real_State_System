//Inclui-se libImobiliarias.h para que a função main tenha acesso às funções, registros e constantes definidos no .h.
#include "libImobiliarias.h"

int main(){
  //arqFisicoRoot.bin armazena username (root) e senha (123) do administrador.
  char arqFisicoRoot[] = "../obj/arqFisicoRoot.bin";

  //arqFisicoLogin.bin armazena username e senha dos clientes cadastrados.
  char arqFisicoLogin[] = "../obj/arqFisicoLogin.bin";

  //arqFisicoClientes.bin armazena as informações sobre os clientes cadastrados.
  char arqFisicoClientes[] = "../obj/arqFisicoClientes.bin";

  //armazena as informações sobre as imobiliarias cadastradas.
  char arqFisicoImobiliarias[] = "../obj/arqFisicoImobiliarias.bin";

  int opt;
  do{
     //Função que mostra as opções para o usuário ao executar o programa
     menuLog();
     scanf("%d", &opt);
     switch (opt){
         case 1: tryLogin(arqFisicoRoot, arqFisicoClientes, arqFisicoLogin, arqFisicoImobiliarias);
                break;
	     case 2: listarImobiliarias(arqFisicoImobiliarias);
                break;
         case 3 : listarImobiliarias(arqFisicoImobiliarias);
                break;
     }
  }while (opt != 0);

  return 0;
}
