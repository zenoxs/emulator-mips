//
//  register.h
//  emulator-mips
//
//  Created by Amaury CIVIER on 05/12/15.
//  Copyright © 2015 Amaury CIVIER. All rights reserved.
//

#ifndef register_h
#define register_h

#if defined(_WIN32) || defined(_WIN64)
# define strtok_r strtok_s
#endif

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    char* name;
    char* mnemonique;
    int32_t value;
}Register;

typedef Register* Registers;

void displayRegister(Registers R);
void initRegisters(Registers R);
uint32_t registerToInt(char* name);

/* 
strbreak: Divise une chaine de caractere en 2 sous-chaines
Parametres: 
	- s: 
*/

#endif /* register_h */
