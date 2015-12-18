#include "emulator.h"
#include "utility.h"

#define SIZE 50

int main(int argc, char * argv[]) {
    
    char* instruction = malloc(SIZE * sizeof(char));
	int nbIntructions = 0;
    
    switch (argc) {
        case 1: //Mode interactif
            
            //Lecture instruction
            printf("emul-mips(interactif)>");
            fgets (instruction, SIZE, stdin);
            instruction = strbreak(&instruction, '\n');
            
            while ((strcmp(instruction, "exit") != 0) && (strcmp(instruction, "EXIT") != 0)) {
                //Affichage instruction hexadecimale
                printf("%s\n", instructionToHex(instruction));
                
                //Execution instruction
                
                //Lecture instruction
                printf("emul-mips(interactif)>");
                fgets (instruction, SIZE, stdin);
				instruction = strbreak(&instruction, '\n');
            }
            
            break;
        case 2: // Mode non-interactif

            printf("Instruction\t\tHexadecimal\n\n");

            //Lecture du programme
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
