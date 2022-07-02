#include <stdio.h>
#include <stdlib.h>

#include "../../types/UserTypes.h"
#include "../../utils/SystemFunctions.h"
#include "Search.h"

struct User *searchUserId(struct User *user, int id){

  if(id == 0)
    return NULL;

  if(user == NULL) 
    return NULL;

  if(user->id == id)
    return user;

  if(user->id > id)
    searchUserId(user->left, id);
    
  if(user->id < id)
    searchUserId(user->rigth, id);

}