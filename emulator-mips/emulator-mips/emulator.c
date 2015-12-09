#include "emulator.h"

char* instructionToHex(char* instruction) {

    char* hexInstruction = malloc(10 * sizeof(char)); // Instruction en hexadecimal
	uint32_t intInstruction = 0;
	uint32_t intRegister = 0; // numero du registre
    char* operation;

	operation = strbreak(&instruction, ' ');

	if (strcmp(operation, "ADD") == 0) { // Instruction ADD
        
		intInstruction = 0b100000; // 100000 bits

		intRegister = registerToInt(strbreak(&instruction, ','));
		intInstruction |= (intRegister << 11);

		strbreak(&instruction, ' ');

		intRegister = registerToInt(strbreak(&instruction, ','));
		intInstruction |= (intRegister << (2*5+11));

		strbreak(&instruction, ' ');

		intRegister = registerToInt(instruction);
		intInstruction |= (intRegister << (5 + 11));
        
    }
	else if (strcmp(operation, "ADDI") == 0) { // Instruction ADDI
        
        intInstruction = (0b001000 << (2*5 + 16));// 001000 bits + decallage
        
        intRegister = registerToInt(strbreak(&instruction, ','));
        intInstruction |= (intRegister << (16)); // rt
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rs
        intInstruction |= (intRegister << (5 + 16));
        
        strbreak(&instruction, ' ');
        
        intInstruction |= atoi(instruction); // Immediate
    }
	else if (strcmp(operation, "AND") == 0) { // Instruction ADD

		intInstruction |= 0b100100; // 100100 bits

		intRegister = registerToInt(strbreak(&instruction, ',')); // rd
		intInstruction |= (intRegister << (5 + 6));

		strbreak(&instruction, ' ');

		intRegister = registerToInt(strbreak(&instruction, ',')); // rs
		intInstruction |= (intRegister << (3 * 5 + 6));

		strbreak(&instruction, ' ');

		intRegister = registerToInt(instruction); // rt
		intInstruction |= (intRegister << (2 * 5 + 6));

	}
	else if (strcmp(operation, "BEQ") == 0) { // Instruction ADD

		intInstruction |= 0b000100 << (2 * 5 + 16); // 000100 bits

		intRegister = registerToInt(strbreak(&instruction, ',')); // rs
		intInstruction |= (intRegister << (5 + 16));

		strbreak(&instruction, ' ');

		intRegister = registerToInt(strbreak(&instruction, ',')); // rt
		intInstruction |= (intRegister << 16);

		strbreak(&instruction, ' ');

		intRegister = atoi(strbreak(&instruction, '\n')); // offset
		intInstruction |= intRegister;

	}
    else if (strcmp(operation, "BGTZ") == 0) { // Instruction ADD
        
        intInstruction |= 0b000111 << (2 * 5 + 16); // 000100 bits
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rs
        intInstruction |= (intRegister << (5 + 16));
        
        
        strbreak(&instruction, ' ');
        
        intRegister = atoi(strbreak(&instruction, '\n')); // offset
        intInstruction |= intRegister;
        
    }

	sprintf(hexInstruction, "0x%08X", intInstruction);

	return hexInstruction;
}