#include "utility.h"
#include "memory.h"
#include "register.h"
#include "emulator.h"

int main(int argc, char * argv[]) {

	char* instruction = malloc(MAX_CHAR_INSTRUCTION * sizeof(char));
	char* instructionHex;
	char str[50];
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
			strcpy(str, "emul-mips(interactif)>");
			strcat(str, instruction);
			saveFile(str, "resultats_interactif.txt");

			// Traduction instruction en hexadecimal
			instructionHex = instructionToHex(instruction);

			if (instructionHex != NULL) {
				// Affichage instruction hexadecimale
				printf("%s\n", instructionHex);
				saveFile(instructionHex, "resultats_interactif.txt");

				// Execution instruction
				executeInstruction(instruction, memory, registers, 0);
				displayRegisters(registers, "resultats_interactif.txt");
				displayMemory(memory, "resultats_interactif.txt");
			}
			else {
				printf("Wrong instruction !\n");
				saveFile("Wrong instruction !", "resultats_interactif.txt");
			}

			// Lecture instruction suivante
			printf("emul-mips(interactif)>");
			fgets(instruction, MAX_CHAR_INSTRUCTION, stdin);
			instruction = strbreak(&instruction, '\n');
		}

		break;
	case 2: // Mode non-interactif
		// Suppression du contenu du fichier resultats
		eraseFile("resultats_non_interactif.txt");

		// Lecture et execution du programme
		readFile(argv[1], 0, memory, registers);

		break;
	case 3: // Mode pas a pas
		if(strcmp(argv[2], "-pas") == 0){
			// Suppression du contenu du fichier resultats
			eraseFile("resultats_non_interactif.txt");

			// Lecture et execution du programme en mode pas a pas
            readFile(argv[1], PAS_A_PAS, memory, registers);
        }
		else{
			printf("Error wrong command !\n");
            exit(EXIT_FAILURE);
		}
		break;
	default :
		printf("Error wrong command !\n");
        exit(EXIT_FAILURE);
        break;
	}

	return 0;
}
