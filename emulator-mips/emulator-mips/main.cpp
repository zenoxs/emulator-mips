#include "emulateur.h"

int main(int argc, char * argv[]) {
	char instruction[50] = "";
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