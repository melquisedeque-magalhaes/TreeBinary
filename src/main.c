#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "types/UserTypes.h"
#include "utils/SystemFunctions.h"

#include "User/Create/CreateUser.c"
#include "User/Search/Search.c"
#include "User/Show/Show.c"
#include "User/Delete/Delete.c"

int main(void) {	
	setlocale(LC_ALL, "Portuguese");

  int idCounter = 1;
  int searchUser = 0;

  struct User user;

  struct User *pointerTree = &user;

  int menu;

  pointerTree->left = NULL;
  pointerTree->rigth = NULL;
  pointerTree->id = 0;

  do {
    printf("\n=====================================================\n\n");

    printf("Digite ( 1 ) para inserir um Usuario\n");
    printf("Digite ( 2 ) para mostrar todos os Usuarios\n");
    printf("Digite ( 3 ) para buscar um Usuarios\n");
    printf("Digite ( 4 ) para excluir um Usuario\n");
    printf("Digite ( 0 ) para sair\n");

    printf("\n=====================================================\n");

    printf("Digite sua opção: ");
    scanf("%d", &menu);

    printf("\n=====================================================\n");

    clearWindow();
     
    switch(menu){
      case 0: 
        break;
        break;
      case 1: 
        printf("\n=====================================================\n");

        printf("\nInserindo Usuario ....\n");

        printf("\n=====================================================\n");

        mySleep(1000);
        
        insert(pointerTree, idCounter);

        idCounter += 1;
        
        break;
      case 2:

        printf("\n=====================================================\n");
        printf("\nMostrando Usuario ....\n");
        printf("\n=====================================================\n");

        mySleep(1000);
        
        printTree(pointerTree);
        
        break;

      case 3:

        printf("Digite o id do usuario que você deseja encontrar: ");
        scanf("%d", &searchUser);

        struct User *isUser = searchUserId(pointerTree, searchUser);

        if(isUser == NULL)
          printf("\n Error usuario não existe! \n");
        else 
          printUser(isUser);

        break;

      case 4: 
        
        printf("Digite o Id do usuario que deseja excluir: ");
        scanf("%d", &searchUser);
        
        pointerTree = delete(pointerTree, searchUser);
        
        printTree(pointerTree);
        
        break;

      default:
        printf("\nError valor invalido, tente novamente... \n");
    }

  }while(menu > 0 && menu <= 4);
  
  return 0;
}
