//
//  register.c
//  emulator-mips
//
//  Created by Amaury CIVIER on 05/12/15.
//  Copyright © 2015 Amaury CIVIER. All rights reserved.
//

#include "register.h"

uint32_t registerToInt(char* name){
	uint32_t result = 0;
	char* noRegister;

	noRegister = &name[1];

	if (strcmp(noRegister, "zero") == 0) {
		result = 0;
	}
	else if (strcmp(noRegister, "at") == 0) {
		result = 1;
	}
	else if (strcmp(noRegister, "v0") == 0) {
		result = 2;
	}
	else if (strcmp(noRegister, "v1") == 0) {
		result = 3;
	}
	else if (strcmp(noRegister, "a0") == 0) {
		result = 4;
	}
	else if (strcmp(noRegister, "a1") == 0) {
		result = 5;
	}
	else if (strcmp(noRegister, "a2") == 0) {
		result = 6;
	}
	else if (strcmp(noRegister, "a3") == 0) {
		result = 7;
	}
	else if (strcmp(noRegister, "t0") == 0) {
		result = 8;
	}
	else if (strcmp(noRegister, "t1") == 0) {
		result = 9;
	}
	else if (strcmp(noRegister, "t2") == 0) {
		result = 10;
	}
	else if (strcmp(noRegister, "t3") == 0) {
		result = 11;
	}
	else if (strcmp(noRegister, "t4") == 0) {
		result = 12;
	}
	else if (strcmp(noRegister, "t5") == 0) {
		result = 13;
	}
	else if (strcmp(noRegister, "t6") == 0) {
		result = 14;
	}
	else if (strcmp(noRegister, "t7") == 0) {
		result = 15;
	}
	else if (strcmp(noRegister, "t8") == 0) {
		result = 24;
	}
	else if (strcmp(noRegister, "t9") == 0) {
		result = 25;
	}
	else if (strcmp(noRegister, "s0") == 0) {
		result = 16;
	}
	else if (strcmp(noRegister, "s1") == 0) {
		result = 17;
	}
	else if (strcmp(noRegister, "s2") == 0) {
		result = 18;
	}
	else if (strcmp(noRegister, "s3") == 0) {
		result = 19;
	}
	else if (strcmp(noRegister, "s4") == 0) {
		result = 20;
	}
	else if (strcmp(noRegister, "s5") == 0) {
		result = 21;
	}
	else if (strcmp(noRegister, "s6") == 0) {
		result = 22;
	}
	else if (strcmp(noRegister, "s7") == 0) {
		result = 23;
	}
	else if (strcmp(noRegister, "k0") == 0) {
		result = 26;
	}
	else if (strcmp(noRegister, "k1") == 0) {
		result = 27;
	}
	else if (strcmp(noRegister, "gp") == 0) {
		result = 28;
	}
	else if (strcmp(noRegister, "sp") == 0) {
		result = 29;
	}
	else if (strcmp(noRegister, "fp") == 0) {
		result = 30;
	}
	else if (strcmp(noRegister, "ra") == 0) {
		result = 31;
	}
	else {
		result = atoi(noRegister);
	}

    return result;
}
