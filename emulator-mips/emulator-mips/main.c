#include "utility.h"
#include "memory.h"
#include "register.h"
#include "emulator.h"

int main(int argc, char * argv[]) {

	char* instruction = malloc(MAX_CHAR_INSTRUCTION * sizeof(char));
	char* instructionHex;
	Registers registers = initRegisters();
	Memory memory = initMemory();

	switch (argc) {
	case 1: //Mode interactif
		// Suppression du contenu du fichier resultats
		eraseFile("resultats_interactif.txt");

		//Lecture instruction
		printf("emul-mips(interactif)>");
		fgets(instruction, MAX_CHAR_INSTRUCTION, stdin);
		instruction = strbreak(&instruction, '\n');

		while ((strcmp(instruction, "exit") != 0) && (strcmp(instruction, "EXIT") != 0)) {
			// Traduction instruction en hexadecimal
			instructionHex = instructionToHex(instruction);

			if (instructionHex != NULL) {
				// Affichage instruction hexadecimale
				printf("%s\n", instructionHex);

				// Sauvegarde des resultats
				//strcat(instruction, " = ");
				//strcat(instruction, instructionHex);
				//saveFile(instruction, "resultats_interactif.txt");

				// Execution instruction
				executeInstruction(instruction, memory, registers);
				displayRegisters(registers);
				displayMemory(memory);
			}
			else
				printf("Wrong instruction !\n");

			// Lecture instruction suivante
			printf("emul-mips(interactif)>");
			fgets(instruction, MAX_CHAR_INSTRUCTION, stdin);
			instruction = strbreak(&instruction, '\n');
		}

		break;
	case 2: // Mode non-interactif

		//Lecture du programme et affichage des instructions en hexa
		readFile(argv[1], 0, memory, registers);

		break;
	case 3: // Mode pas a pas

		//Affichage instruction hexadecimale
		readFile(argv[1], PAS_A_PAS, memory, registers);

		break;
	}

	return 0;
}
