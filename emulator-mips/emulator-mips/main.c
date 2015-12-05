#include "emulator.h"

#define SIZE 50

int main(int argc, char * argv[]) {
    

    
    
	char instruction[SIZE] = "";
	switch (argc) {
		case 1: //Mode interactif

			//Lecture instruction
			printf("emul-mips(interactif)>");
			scanf("%s", &instruction);

			while ((strcmp(instruction, "exit") != 0) || (strcmp(instruction, "EXIT") != 0)) {
				//Affichage instruction hexadecimale

				//Execution instruction

				//Lecture instruction
				printf("emul-mips(interactif)>");
				scanf("%s", &instruction);
                
                instructionToHex(instruction);
			}

			break;
		case 2: // Mode non-interactif

			//Lecture instruction


			while (1) {
				//Affichage instruction hexadecimale

				//Execution instruction

				//Lecture instruction
				
			}
			break;
		case 3: // Mode pas à pas

			//Lecture instruction


			while (1) {
				//Affichage instruction hexadecimale

				//Execution instruction

				//Lecture instruction

			}
			break;
	}
	return 0;*/
	char* instruction = "ADD $2, $3, $4";
	char* hexInstruction = ""; // Instruction en hexadecimal
	uint32_t intInstruction = 0;

	char* operation = strtok_s(instruction, " ", 5); // string de l'opération

	if (strcmp(operation, "ADD") == 0) { // Instruction ADD
		intInstruction = 32;
		printf("%s\n", operation);
		printf("%s\n", strtok_s(NULL, ',', 5));
		printf("%s\n", strtok_s(NULL, ',', 5));
		printf("%s\n", strtok_s(NULL, ',', 5));
	}

	sprintf_s(hexInstruction, "0x%X", intInstruction, 20);
}