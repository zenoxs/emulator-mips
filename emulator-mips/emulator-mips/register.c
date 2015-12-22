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
	else if (strcmp(noRegister, "HI") == 0) {
		result = 32;
	}
	else if (strcmp(noRegister, "LO") == 0) {
		result = 33;
	}
	else {
		result = atoi(noRegister);
	}

	if ((result < 0) || (result > 33))
		result = NULL;

    return result;
}


Registers initRegisters() {
	Registers R = malloc(NB_REGISTERS * sizeof(Register));
	int i;

	for (i = 0; i < NB_REGISTERS; i++) {
		R[i].value = 0;
	}

	R[0].name = "zero";
	R[1].name = "at";
	R[2].name = "vo";
	R[3].name = "v1";
	R[4].name = "a0";
	R[5].name = "a1";
	R[6].name = "a2";
	R[7].name = "a3";
	R[8].name = "t0";
	R[9].name = "t1";
	R[10].name = "t2";
	R[11].name = "t3";
	R[12].name = "t4";
	R[13].name = "t5";
	R[14].name = "t6";
	R[15].name = "t7";
	R[16].name = "s0";
	R[17].name = "s1";
	R[18].name = "s2";
	R[19].name = "s3";
	R[20].name = "s4";
	R[21].name = "s5";
	R[22].name = "s6";
	R[23].name = "s7";
	R[24].name = "t8";
	R[25].name = "t9";
	R[26].name = "k0";
	R[27].name = "k1";
	R[28].name = "gp";
	R[29].name = "sp";
	R[30].name = "fp";
	R[31].name = "ra";
	R[32].name = "HI";
	R[33].name = "LO";

	return R;
}


void displayRegisters(Registers R) {
	int i;

	printf("Registers:\n\n");

	for (i = 0; i < NB_REGISTERS; i++) {
		printf("$%s\t$%i\t%i\n", R[i].name, i, R[i].value);
	}
}


void setRegister(Registers R, char* name, int32_t value) {
	R[registerToInt(name)].value = value;
}


int32_t getRegister(Registers R, char* name) {
	return R[registerToInt(name)].value;
}