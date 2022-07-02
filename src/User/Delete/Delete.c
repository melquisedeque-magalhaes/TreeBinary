#include <stdio.h>
#include <stdlib.h>

#include "../../types/UserTypes.h"
#include "../Search/Search.h"
#include "../Create/CreateUser.h"
#include "Delete.h"
#include "../../utils/SystemFunctions.h"

struct User *delete(struct User *user, int id){ 

    struct User *isUser = searchUserId(user, id);
    
    if(isUser == NULL)
        printf("\n Error usuario não existe! \n");
    else{
        if(isUser->id == user->id && isUser->rigth == NULL && isUser->left == NULL){ // Primeiro Elemento da Arvore
            struct User *newTree = newNode(user);

            newTree->id = 0;

            printf("Usuario excluido com sucesso ! \n");

            mySleep(500);

            return newTree;
        }

        if(isUser->rigth == NULL && isUser->left == NULL){ // Ultimo Elemento da Arvore ou Folhas

            if(user->left != NULL){
                if(user->left->id == id)
                    user->left = NULL;
                
            }

            if(user->rigth != NULL){
                if(user->rigth->id == id)
                    user->rigth = NULL; 
                
            }

            mySleep(500);

            printf("Usuario excluido com sucesso ! \n");

            return user;
            
		}
        else {

            if(isUser->rigth != NULL){

                struct User *nextUser = isUser->rigth;

                struct User *userTmp = user->rigth;

                struct User *prevUser = user;

                while(userTmp->id != isUser->id){
                    prevUser = user->rigth;
                    userTmp = userTmp->rigth;
                }

                prevUser->rigth = nextUser;

                free(isUser);

                mySleep(500);

                printf("Usuario excluido com sucesso ! \n");

                return user;
            }

            if(isUser->left != NULL){
                struct User *nextUser = isUser->left;

                struct User *userTmp = user->left;

                struct User *prevUser = user;

                while(userTmp->id != isUser->id){
                    prevUser = user->left;
                    userTmp = userTmp->left;
                }

                prevUser->left = nextUser;

                free(isUser);

                mySleep(500);

                printf("Usuario excluido com sucesso ! \n");

                return user;
            }
        }

    }

}
