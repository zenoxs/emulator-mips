#include "emulator.h"

#define SIZE 50

int main(int argc, char * argv[]) {
	char instruction[SIZE] = "";
	switch (argc) {
		case 1: //Mode interactif

			//Lecture instruction
			printf("emul-mips(interactif)>");
			scanf_s("%s", &instruction, SIZE);

			while ((strcmp(instruction, "exit") != 0) || (strcmp(instruction, "EXIT") != 0)) {
				//Affichage instruction hexadecimale

				//Execution instruction

				//Lecture instruction
				printf("emul-mips(interactif)>");
				scanf_s("%s", &instruction, SIZE);
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
	return 0;
}