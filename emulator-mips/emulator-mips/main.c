#include "emulator.h"
#include "utility.h"

#define SIZE 50

int main(int argc, char * argv[]) {
    
    char* instruction = malloc(SIZE * sizeof(char));
	char** tableInstructions;
	int nbIntructions = 0;
    
    switch (argc) {
        case 2: //Mode interactif
            
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
        case 1: // Mode non-interactif
            
            //Lecture du programme
			tableInstructions = readFile("C:\Users\Romain\Source\Repos\emulator-mips\emulator-mips\emulator-mips\Debug\prog.txt", &nbIntructions);
            
            while (1) {
				int i = 0;
				printf("Instruction\t\t\tHexadecimal");
				for (i = 0; i < nbIntructions; i++) {
                //Affichage instruction hexadecimale
					printf("%s\t\t\t%s", tableInstructions[i], instructionToHex(tableInstructions[i]));
                
                //Execution instruction
				}
                
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