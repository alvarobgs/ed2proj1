/*
  PROJETO I - Estrutura de Dados II
  Locadora
  
  Alvaro Govone
  Vinicius Pfeifer
  
  Arquivos utilizados:
      principal.txt - Arquivo que salva os registros das loca��es
      index.txt - Arquivo que guarda a chave primaria(id) e o offset no arquivo principal
*/

#include <cstdlib>
#include <iostream>
#include "locacao.h"
#include "indice.h"

void menu();

int main()
{
  indice *indices = NULL;
  
  getAllIndexesOnFile(&indices);
  
  FILE *arq;
    
  unsigned int option = 0,aux=0;
    
  indice *i;
    
    if(arq=fopen("principal.txt","a+"))
    {
      do
      {
        system("cls");
        
        printIndexes(indices);
        
        menu();
        
        printf("\n\nEscolha uma opcao : ");
        scanf("%d",&option);
        
        system("cls");
                    
        switch(option)
        {
          case 0:
            break;
          case 1:
            
            printf("========= CADASTRO DE LOCACAO ==========\n\n");
            
            locacao l = readLocacao();
            
            aux = saveLocacao(l,arq);
            
            //insere no indice
            i=(indice *)malloc(sizeof(indice *));
            i->id_locacao=l.id;
            i->offset=aux;
            i->prox = NULL;
            
            insertIndexOnFile(i);
            
            insertIndexOnList(&indices,i);
            
            printf("\n\nLocacao salva com sucesso!\n\n");
            
            break;
          
          case 5:
            printf("========= BUSCAR LOCACAO POR ID ==========\n\n");
            
            printf("Digite o ID da locacao que deseja buscar : ");
            scanf("%d",&aux);
            
            i = findIndexByID(indices,aux);
            
            if(i==NULL)
              printf("\n\nLocacao n�o encontrada!");
            else
            {
              printf("\n%d %d\n",i->id_locacao,i->offset);
              
              fseek(arq,i->offset,SEEK_SET);
              
              fread(&aux,sizeof(int),1,arq);
              
              printf("\n%d\n",aux);
              
              fread(&aux,sizeof(int),1,arq);
              
              printf("\n%d\n",aux);
            }
            
            break;
          default:
            printf("Opcao invalida!\n\n");
            break;
        }
        
        if(option!=0)
          system("PAUSE");
      }while(option!=0);
      
    }
    else
    {
      printf("Erro ao abrir o arquivo!");
    }
    
    fclose(arq);
    
  return 1;
}

void menu()
{
  printf("========= LOCADORA UNESP ==========\n\n");
  printf("Menu:\n\n");
  printf("1. Cadastrar Locacao\n");
  printf("2. Alterar Locacao\n");
  printf("3. Remover Locacao\n");
  printf("4. Compactar arquivo\n");
  printf("5. Buscar pelo codigo da Locacao\n");
  printf("6. Buscar pelo nome do filme");   
}
