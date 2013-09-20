#include <cstdlib>
#include <iostream>
#include <ctype.h>

//Estrutura que representa a loca��o de um filme no sistema
typedef struct locacao
{
  unsigned int id;               //c�digo da loca��o
  char filme[255];               //Nome do filme
  char cliente[255];             //Nome do Cliente
  char data_devolucao[15];       //Data de Devolu��o do filme
};

//Pede ao usuario para digitar uma loca��o e salva na struct locacao
locacao readLocacao();

//Exibe na tela os dados de uma locacao
void viewLocacao(locacao l);

//Grava locacao no arquivo no formato tamid|filme|cliente|devolucao
int saveLocacao(locacao l,FILE *arq);


