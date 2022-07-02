#include <stdio.h>
#include <stdlib.h>

#include "CreateUser.h"
#include "../../types/UserTypes.h"
#include "../../utils/SystemFunctions.c"

struct User *newNode(struct User *user){
  struct User *newTree = malloc(sizeof(struct User));

  newTree->rigth = NULL;
  newTree->left = NULL; 

  return newTree;
}

void insert(struct User *user,int id){
  
  if(user->id == 0){
    user->id = id;
    createUser(user);
  }else{
    
    if(id < user->id){
        if(user->left == NULL) {

          struct User *newTree = newNode(user);
        
          newTree->id = id;

          createUser(newTree);
    
          user->left = newTree;
        }  else {
            insert(user->left, id);
        }
    }

    if(id > user->id){
      if(user->rigth == NULL) {
        struct User *newTree = newNode(user);
        
        newTree->id = id;

        createUser(newTree);
  
        user->rigth = newTree;
      }
      else {
        insert(user->rigth, id);
      }
    }
    
  }

  printf("\n inserindo usuario ...\n");

  mySleep(1500);

  clearWindow();
}

void createUser(struct User *user){
  getchar();
  
  printf("Digite seu nome: ");
  fgets(user->name, 100, stdin);
  fflush(stdin);

  printf("Digite sua idade: ");
  scanf("%d", &user->age);

  getchar();
  
  printf("Digite seu CPF: ");
  fgets(user->cpf, 100, stdin);
  fflush(stdin);
  
  printf("Digite seu Sexo: ");
  fgets(user->gender, 100, stdin);
  fflush(stdin);
  
  printf("Digite sua nacionalidade: ");
  fgets(user->nationality, 100, stdin);
  fflush(stdin);

  printf("Digite seu email: ");
  fgets(user->contacts.email, 100, stdin);
  fflush(stdin);
  
  printf("Digite seu Telefone para contato: ");
  fgets(user->contacts.phoneNumber, 100, stdin);
  fflush(stdin);
  
  printf("Digite seu CEP: ");
  fgets(user->address.zipCode, 100, stdin);

  printf("Digite o numero da sua casa: ");
  scanf("%d", &user->address.number);

  getchar();
  
	printf("Digite o nome da sua cidade: ");
  fgets(user->address.city, 100, stdin);
  
  printf("Digite o nome do seu Pais: ");
  fgets(user->address.country, 100, stdin);
  
  printf("Digite o nome do seu estado: ");
  fgets(user->address.state, 100, stdin);
  
  
}