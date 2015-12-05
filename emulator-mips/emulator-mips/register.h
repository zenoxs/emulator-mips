//
//  register.h
//  emulator-mips
//
//  Created by Amaury CIVIER on 05/12/15.
//  Copyright © 2015 Amaury CIVIER. All rights reserved.
//

#ifndef register_h
#define register_h

#include <stdio.h>
#include "memory.h"

typedef struct {
    char* name;
    char* mnemonique;
    int32_t value;
}Register;

typedef Register* Registers;

void displayRegister(Registers R);
void initRegisters(Registers R);

#endif /* register_h */
