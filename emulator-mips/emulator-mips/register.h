#ifndef register_h
#define register_h

#include "utility.h"

// Definition du type structure Register
typedef struct {
	char* name;
	int32_t value;
}Register;

// Tableau contenant les registres
typedef Register* Registers;

// Initialise tous les registres
Registers initRegisters();

// Affiche les registres
void displayRegisters(Registers R, char* nameFile);

// Enregistre une valeur dans un registre
void setRegister(Registers R, char* name, int32_t value);

// Lit un registre
int32_t getRegister(Registers R, char* name);

// Convertit le nom d'un registre en son numero
uint32_t registerToInt(char* name);

#endif /* register_h */
