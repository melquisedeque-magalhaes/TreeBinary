#include <stdio.h>
#include <stdlib.h>

#include "../../types/UserTypes.h"
#include "../../utils/SystemFunctions.h"
#include "Show.h"

void printTree(struct User *user){
  if(user->id <= 0 || user == NULL){

    printf("Arvore vazia... %d \n", user->id);

  }else {
  
    printf("\n\n ======================= Usuario %d ======================= \n\n", user->id);
    printf("Id: %d\n", user->id);
    printf("Name: %s", user->name);
    printf("Idade: %d\n", user->age);
    
    printf("CPF: %s", user->cpf);
    printf("Genero: : %s", user->gender);
    printf("Nascionalidade: %s", user->nationality);
    
    printf("\n ======================= Contatos ======================= \n");
    
    printf("E-mail: %s", user->contacts.email);
    printf("Telefone: %s", user->contacts.phoneNumber);
    
    printf("\n ======================= Endereço ======================= \n");
    
    printf("\nCEP: %s", user->address.zipCode);
    printf("Numero: %d", user->address.number);
    printf("\nCidade: %s", user->address.city);
    printf("Pais: %s", user->address.country);
    printf("Estado: %s", user->address.state);

    if(user->rigth != NULL)
      printTree(user->rigth);

    if(user->left != NULL)
      printTree(user->left);
    
  }
}


void printUser(struct User *user){
  clearWindow();

  if(user->id <= 0){

    printf("Arvore vazia... %d \n", user->id);

  }else {
  
    printf("\n\n ======================= Usuario %d ======================= \n\n", user->id);
    printf("Id: %d\n", user->id);
    printf("Name: %s", user->name);
    printf("Idade: %d\n", user->age);
    
    printf("CPF: %s", user->cpf);
    printf("Genero: : %s", user->gender);
    printf("Nascionalidade: %s", user->nationality);
    
    printf("\n ======================= Contatos ======================= \n");
    
    printf("E-mail: %s", user->contacts.email);
    printf("Telefone: %s", user->contacts.phoneNumber);
    
    printf("\n ======================= Endereço ======================= \n");
    
    printf("\nCEP: %s", user->address.zipCode);
    printf("Numero: %d", user->address.number);
    printf("\nCidade: %s", user->address.city);
    printf("Pais: %s", user->address.country);
    printf("Estado: %s", user->address.state);

    getchar();
    fflush(stdin);
    getchar();
    
    clearWindow();
  }
}