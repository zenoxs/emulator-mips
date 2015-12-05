#include "emulator.h"

char* instructionToHex(char* instruction) {
	char* hexInstruction = ""; // Instruction en hexadecimal
	/*uint32_t intInstruction = 0;

	char* operation = strtok_s(instruction, " ", 4); // string de l'opération

	if (strcmp(operation, "ADD") == 0) { // Instruction ADD
		intInstruction = 32;

		uint32_t intRegister = registerToInt(strtok(NULL, ',')); // Numéro du registre
		intInstruction |= (intRegister << 6);

		intRegister = registerToInt(strtok(NULL, ',')); // Numéro du registre
		intInstruction |= (intRegister << (5+6));

		intRegister = registerToInt(strtok(NULL, ',')); // Numéro du registre
		intInstruction |= (intRegister << (2*5 + 6));
	}

	sprintf(hexInstruction, "0x%X", intInstruction);*/

	return hexInstruction;
}