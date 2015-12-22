//
//  register.h
//  emulator-mips
//
//  Created by Amaury CIVIER on 05/12/15.
//  Copyright © 2015 Amaury CIVIER. All rights reserved.
//

#ifndef register_h
#define register_h

#include "utility.h"

typedef struct {
    char* name;
    int32_t value;
}Register;

typedef Register* Registers;

Registers initRegisters();
void displayRegister(Registers R);
void setRegister(Registers R, char* name, int32_t value);
int32_t getRegister(Registers R, char* name);
uint32_t registerToInt(char* name);

#endif /* register_h */
