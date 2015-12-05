#include "emulator.h"

char* instructionToHex(char* instruction) {
	char* hexInstruction = malloc(8 * sizeof(char));

	char* operation = strtok(instruction, " ");

	if (strcmp(operation, "ADD") == 0) {

	}


	return hexInstruction;
}