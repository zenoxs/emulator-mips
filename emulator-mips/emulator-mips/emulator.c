#include "emulator.h"

char* instructionToHex(char* instruction) {

    char* hexInstruction = malloc(10 * sizeof(char)); // Instruction en hexadecimal
	uint32_t intInstruction = 0;
	uint32_t intRegister = 0; // numero du registre
    char* operation;

	operation = strbreak(&instruction, ' ');

	if (strcmp(operation, "ADD") == 0) { // Instruction ADD
		intInstruction = 32; // 100000 bits

		intRegister = registerToInt(strbreak(&instruction, ','));
		intInstruction |= (intRegister << 11);

		strbreak(&instruction, ' ');

		intRegister = registerToInt(strbreak(&instruction, ','));
		intInstruction |= (intRegister << (2*5+11));

		strbreak(&instruction, ' ');

		intRegister = registerToInt(instruction);
		intInstruction |= (intRegister << (5 + 11));
    }else if (strcmp(operation, "ADDI") == 0) { // Instruction ADDI
        intInstruction = 32; // 001000 bits
        
    }


	sprintf(hexInstruction, "0x%08X", intInstruction);

	return hexInstruction;
}