/** @file   libImobiliarias - definição de constantes, registros e protótipos das funcões utilizadas
    @author Juliana de Santi
    @date   Abril - 2019
*/

#ifndef _LIBIMOBILIARIAS_H_
#define _LIBIMOBILIARIAS_H_

#include <stdio.h>
#include <string.h>

//=============== Constantes =======================
#define MAX_USER 11 //número máximo de caracteres usado para username
#define MAX_PASSWD 15 //número máximo de caracteres utilizados para a senha

#define MAX_ENDERECO 50 //Quantidade carateres itilizados para o complemento (do endereço)
#define MAX_IMOBILIARIAS 50//número máximo de imobiliárias que podem ser cadastradas
#define MAX_CLIENTES 50 //número máximo de clientes cadastrados
#define MAX_IMOBILIARIAS_POR_CLIENTE 50//número de imobiliárias por cliente


//=============== Registros/structs =======================
//Registro para a definição do tipo Data
typedef struct data{
  int dia, mes, ano;
} Data;

//Registro para a definição do tipo Contatos
typedef struct contatos{
   char fone[18];
   char email[40];
} Contatos;

//Registro para a definição do tipo Endereco
typedef struct endereco{
   char rua[MAX_ENDERECO];
   int numero;
   char complemento[MAX_ENDERECO];
   char cidade[MAX_ENDERECO];
   int cep;
} Endereco;

//Registro para a definição do tipo AvaliacaoParaImobiliaria
typedef struct avaliacaoParaImobiliaria{
   int ruim;
   int bom;
   int excelente;
} AvaliacaoParaImobiliaria;

//Registro para a definição das categorias de imóveis
typedef struct categoria{
  //setado para 1 => tem esta categoria de imóvel
  //setado para 0 => não tem esta categoria de imóvel
  //só pode aceitar estes valores, ou seja, 0 e 1
   int casa;
   int sobrado;
   int apartamento;
   int terreno;
   int chacarra;
   int sitio;
   int fazenda;
} Categoria;

//Registro para a definição do tipo Imobiliaria
typedef struct imobiliaria{
   char nome[40];
   int id;
   Endereco endereco;
   Contatos contato;
   Categoria tipoDeImovel;
   AvaliacaoParaImobiliaria avaliacao;
} Imobiliaria;

//Registro para a definição do tipo AvaliacaoDoCliente
typedef struct avaliacaoDoCliente{
    char nomeImobiliaria[40];
    AvaliacaoParaImobiliaria avaliacaoImobiliaria;
} AvaliacaoDoCliente;


//Registro para a definição do tipo LogInfo, utilizado para guarder username e senha de cada usuário
typedef struct log{
   char username[MAX_USER];
   char passwd[MAX_PASSWD];
}LogInfo;


//Registro para a definição do tipo Cliente
typedef struct cliente{
   LogInfo login;
   char nome[30];
   char sobrenome[30];
   Endereco endereco;
   Contatos contato;
   AvaliacaoDoCliente vetAvaliacoes[MAX_IMOBILIARIAS_POR_CLIENTE];
   int numeroAvaliacoes;
   Data dataNascimento;
} Cliente;

//Registro para a definição do tipo superUser
typedef struct superUser{
   LogInfo login;
} SuperUser;


//=============== Protótipos =======================

void menuLog();
void tryLogin(char arqFisicoRoot[], char arqFisicoClientes[], char arqFisicoLogin[], char arqFisicoImobiliarias[]);
void logAsRoot(char arqFisicoClientes[],  char arqFisicoLogin[], char arqFisicoImobiliarias[]);
void menuRoot();
void logAsNormalUser(char arqFisicoClientes[], char arqFisicoImobiliarias[], LogInfo userLog);
void menuCliente(char username[]);
void visualizaDadosCliente(char arqFisicoClientes[], LogInfo userLog);
int avaliarImobiliaria(char arqFisicoImobiliarias[], char nomeImobiliaria[]);
void atualizaAvaliacaoCliente(char arqFisicoClientes[], char usernameCliente[], char nomeImobiliaria[], int avaliacao);
void visualizarAvaliacoes(char arqFisicoClientes[], char usernameCliente[]);

int cadastraCliente(char arqFisicoClientes[], char arqFisicoLogin[], char username[]);
int alterarCliente(char arqFisicoClientes[], char usernameCliente[]);
int removerCliente(char arqFisicoClientes[], char arqFisicoLogin[], char username[]);
void gravarCliente(char arqFisicoClientes[], Cliente c);
void listarClientes(char arqFisicoClientes[]);

void gravarNewLogingInfo(char arqFisicoLogin[], LogInfo newUserLoginInfo);

void cadastraImobiliaria(char arqFisicoImobiliarias[]);
int setaCategoria(char categoria[]);
void gravarImobiliaria(char arqFisicoImobiliarias[], Imobiliaria imobiliaria);
void listarImobiliarias(char arqFisicoImobiliarias[]);
void alterarImobiliaria(char arqFisicoImobiliarias[], int idImobiliaria);
void removerImobiliaria(char arqFisicoImobiliarias[], int idImobiliaria);


#endif
