#include "emulator.h"
#include "utility.h"

#define SIZE 50

int main(int argc, char * argv[]) {
    
    char* instruction = malloc(SIZE * sizeof(char));
	char* instructionHex;
    
    switch (argc) {
        case 1: //Mode interactif
			// Suppression du contenu du fichier resultats
			eraseFile("resultats_interactif.txt");

            //Lecture instruction
            printf("emul-mips(interactif)>");
            fgets (instruction, SIZE, stdin);
            instruction = strbreak(&instruction, '\n');
            
            while ((strcmp(instruction, "exit") != 0) && (strcmp(instruction, "EXIT") != 0)) {
				// Traduction instruction en hexadecimal
				instructionHex = instructionToHex(instruction);

                // Affichage instruction hexadecimale
                printf("%s\n", instructionHex);

				// Sauvegarde des resultats
				strcat(instruction, " = ");
				strcat(instruction, instructionHex);
				saveFile(instruction, "resultats_interactif.txt");
                
                // Execution instruction
                
                // Lecture instruction suivante
                printf("emul-mips(interactif)>");
                fgets (instruction, SIZE, stdin);
				instruction = strbreak(&instruction, '\n');
            }
            
            break;
        case 2: // Mode non-interactif

            printf("Instruction\t\tHexadecimal\n\n");
            
            //Lecture du programme et affichage des instructions en hexa
			readFile(argv[1]);
                
            break;
        case 3: // Mode pas a pas
            
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