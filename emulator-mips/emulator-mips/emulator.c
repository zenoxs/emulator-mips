#include "emulator.h"

char* instructionToHex(char* instruction) {
	char* hexInstruction = "";

	char* operation = strtok(instruction, " ");

	if (strcmp(operation, "ADD") == 0) {
		uint32_t intInstruction= 32;
		int intRegister= registerToInt(strtok(NULL, ','));

	}


	return hexInstruction;
}