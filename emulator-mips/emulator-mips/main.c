#include "emulator.h"

#define SIZE 50

int main(int argc, char * argv[]) {
    
    char* instruction = malloc(SIZE * sizeof(char));
	char** tableInstructions;
    
    switch (argc) {
        case 1: //Mode interactif
            
            //Lecture instruction
            printf("emul-mips(interactif)>");
            fgets (instruction, SIZE, stdin);
            instruction = strbreak(&instruction, '\n');
            
            while ((strcmp(instruction, "exit\n") != 0) && (strcmp(instruction, "EXIT\n") != 0)) {
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
            
            //Lecture du programme
			tableInstructions = readInstructionFromFile(argv[1]);
            
            
            while (1) {
                //Affichage instruction hexadecimale
                
                //Execution instruction
                
                //Lecture instruction
                
            }
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