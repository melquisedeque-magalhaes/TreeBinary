#ifndef USER_TYPES
#define USER_TYPES

struct Address {
  char zipCode[100];
  int number;
  char publicPlace[100];   // Logradouro
  char district[100]; // Bairro
  char city[100];
  char state[100];
  char country[100];
  char complement[100];
};

// Data de Nascimento

struct Date {
  char day[2];
  char month[50];
  int year;
};

struct Contacts {
  char email[100];
  char phoneNumber[100];
};

struct User {
  int id;
  char name[100];
  int age;

  char gender[100];
  
  char cpf[100];

  struct Date dateBirth;
  struct Address address;
  struct Contacts contacts;

  char nationality[100];

  char nameFather[100];
  char nameMother[100];
  
  struct User *rigth;
  struct User *left;
};

#endif 
