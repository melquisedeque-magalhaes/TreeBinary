#include <stdio.h>
#include <stdlib.h>

#include "../Search/Search.h"
#include "../Create/CreateUser.h"
#include "Delete.h"

struct User *delete(struct User *user, int id){ 

    struct User *isUser = searchUserId(user, id);
    
    if(isUser == NULL)
        printf("\n Error usuario não existe! \n");
    else{
        if(isUser->id == 1 && isUser->rigth == NULL && isUser->left == NULL){ // Primeiro Elemento da Arvore
            struct User *newTree = newNode(user);

            newTree->id = 0;

            printf("Usuario excluido com sucesso ! \n");

            return newTree;
        }

        if(isUser->rigth == NULL && isUser->left == NULL){ // Ultimo Elemento da Arvore

            if(user->left != NULL){
                if(user->left->id == id)
                    user->left = NULL;
                else {
                    struct User *tmpUser = user->left;
                    struct User *prevUser = user;
                    while (tmpUser->id != id){
                        prevUser = tmpUser;
                        tmpUser = user->left;
                    }
                    
                    printf("anterior %d\n", prevUser->id);
                    printf("atual %d\n", tmpUser->id);
                }
            }

            if(user->rigth != NULL){
                if(user->rigth->id == id)
                    user->rigth = NULL; 
                else {
                    struct User *tmpUser = user->rigth;
                    struct User *prevUser = user;
                    while (tmpUser->id != id){
                        prevUser = tmpUser;
                        tmpUser = user->rigth;
                    }
                    
                    printf("anterior %d\n", prevUser->id);
                    printf("atual %d\n", tmpUser->id);
                }
            }

            printf("Usuario excluido com sucesso ! \n");

            return user;
            
		}

    }

}
