#include "emulator.h"



char *instructionToHex(char *instruction) {
    
    char *hexInstruction = malloc(10 * sizeof(char)); // Instruction en hexadecimal
    uint32_t intInstruction = 0;
    uint32_t intRegister = 0; // numero du registre
    char *operation;
    
    operation = strbreak(&instruction, ' ');
    
    if (strcmp(operation, "ADD") == 0) { // Instruction ADD
        
        intInstruction = 0b100000; // 100000 bits
        
        intRegister = registerToInt(strbreak(&instruction, ','));
        intInstruction |= (intRegister << 11);
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(strbreak(&instruction, ','));
        intInstruction |= (intRegister << (2*5+11));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(instruction);
        intInstruction |= (intRegister << (5 + 11));
        
    }
    else if (strcmp(operation, "ADDI") == 0) { // Instruction ADDI
        
        intInstruction = (0b001000 << (2*5 + 16));// 001000 bits
        
        intRegister = registerToInt(strbreak(&instruction, ','));
        intInstruction |= (intRegister << (16)); // rt
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rs
        intInstruction |= (intRegister << (5 + 16));
        
        strbreak(&instruction, ' ');
        
        intInstruction |= atoi(instruction); // Immediate
    }
    else if (strcmp(operation, "AND") == 0) { // Instruction ADD
        
        intInstruction |= 0b100100; // 100100 bits
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rd
        intInstruction |= (intRegister << (5 + 6));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rs
        intInstruction |= (intRegister << (3 * 5 + 6));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(instruction); // rt
        intInstruction |= (intRegister << (2 * 5 + 6));
        
    }
    else if (strcmp(operation, "BEQ") == 0) { // Instruction ADD
        
        intInstruction |= 0b000100 << (2 * 5 + 16); // 000100 bits
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rs
        intInstruction |= (intRegister << (5 + 16));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rt
        intInstruction |= (intRegister << 16);
        
        strbreak(&instruction, ' ');
        
        intInstruction |= atoi(instruction); // offset
        
    }
    else if (strcmp(operation, "BGTZ") == 0) { // Instruction ADD
        
        intInstruction |= 0b000111 << (2 * 5 + 16); // 000111 bits
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rs
        intInstruction |= (intRegister << (5 + 16));
        
        strbreak(&instruction, ' ');
        
        intInstruction |= atoi(instruction); // offset
        
    }
    else if (strcmp(operation, "BLEZ") == 0) { // Instruction ADD
        
        intInstruction |= 0b000110 << (2 * 5 + 16); // 000110 bits
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rs
        intInstruction |= (intRegister << (5 + 16));
        
        strbreak(&instruction, ' ');
        
        intInstruction |= atoi(instruction); // offset
        
    }
    else if (strcmp(operation, "BNE") == 0) { // Instruction ADD
        
        intInstruction |= 0b000101 << (2 * 5 + 16); // 000101 bits
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rs
        intInstruction |= (intRegister << (5 + 16));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rt
        intInstruction |= (intRegister << 16);
        
        strbreak(&instruction, ' ');
        
        intInstruction |= atoi(instruction); // offset
        
    }
    else if (strcmp(operation, "DIV") == 0) { // Instruction ADD
        
        intInstruction |= 0b011010; // 011010 bits
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rs
        intInstruction |= (intRegister << (5 + 10 + 6));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(instruction); // rt
        intInstruction |= (intRegister << (10 + 6));
        
    }
    else if (strcmp(operation, "J") == 0) { // Instruction ADD
        
        intInstruction |= 0b000010 << 26; // 000010 bits
        //...
    }
    else if (strcmp(operation, "JAL") == 0) { // Instruction ADD
        
        intInstruction |= 0b000011 << 26; // 000011 bits
        //...
    }
    else if (strcmp(operation, "JR") == 0) { // Instruction ADD
        
        intInstruction |= 0b001000; // 001000 bits
        
        intRegister = registerToInt(instruction); // rs
        intInstruction |= (intRegister << (10 + 5 + 6));
        //...
    }
    else if (strcmp(operation, "LUI") == 0) { // Instruction ADD
        
        intInstruction |= 0b001111 << (2 * 5 + 16); // 001111 bits
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rt
        intInstruction |= (intRegister << 16);
        
        strbreak(&instruction, ' ');
        
        intInstruction |= atoi(instruction); // immediate
        
    }
    else if (strcmp(operation, "LW") == 0) { // Instruction ADD
        
        intInstruction |= 0b100011 << (2 * 5 + 16); // 100011 bits
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rt
        intInstruction |= (intRegister << 16);
        
        strbreak(&instruction, ' ');
        
        intInstruction |= atoi(strbreak(&instruction, '(')); // offset
        
        instruction = strbreak(&instruction, ')');
        
        intInstruction |= atoi(instruction) << (5 + 16); // base
        
    }
    else if (strcmp(operation, "MFHI") == 0) { // Instruction ADD
        
        intInstruction |= 0b010000; // 010000 bits
        
        intRegister = registerToInt(instruction); // rd
        intInstruction |= (intRegister << (5 + 6));
        
    }
    else if (strcmp(operation, "MFLO") == 0) { // Instruction ADD
        
        intInstruction |= 0b010010; // 010010 bits
        
        intRegister = registerToInt(instruction); // rd
        intInstruction |= (intRegister << (5 + 6));
    }
    else if (strcmp(operation, "MULT") == 0) { // Instruction ADD
        
        intInstruction = 0b011000; // 011000 bits
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rs
        intInstruction |= (intRegister << (5 + 10 + 6));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(instruction); // rt
        intInstruction |= (intRegister << (10 + 6));
        
    }
    else if (strcmp(operation, "NOP") == 0) { // Instruction ADD
        
        intInstruction = 0;
    }
    else if (strcmp(operation, "OR") == 0) { // Instruction ADD
        
        intInstruction = 0b100101; // 100101 bits
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rd
        intInstruction |= (intRegister << (5 + 6));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rs
        intInstruction |= (intRegister << (3*5 + 6));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(instruction); // rt
        intInstruction |= (intRegister << (2 * 5 + 6));
        
    }
    else if (strcmp(operation, "ROTR") == 0) { // Instruction ADD
        
        intInstruction = 0b000010; // 000010 bits
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rd
        intInstruction |= (intRegister << (5 + 6));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rt
        intInstruction |= (intRegister << (2 * 5 + 6));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(instruction); // sa
        intInstruction |= (intRegister << 6);
        intInstruction |= 1 << (3 * 5 + 6);
        
    }
    else if (strcmp(operation, "SLL") == 0) { // Instruction ADD
        
        intInstruction = 0b000000; // 000000 bits
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rd
        intInstruction |= (intRegister << (5 + 6));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rt
        intInstruction |= (intRegister << (2 * 5 + 6));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(instruction); // sa
        intInstruction |= (intRegister << 6);
        
    }
    else if (strcmp(operation, "SLT") == 0) { // Instruction ADD
        
        intInstruction = 0b101010; // 101010 bits
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rd
        intInstruction |= (intRegister << (5 + 6));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rs
        intInstruction |= (intRegister << (3 * 5 + 6));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(instruction); // rt
        intInstruction |= (intRegister << (2*5 + 6));
        
    }
    else if (strcmp(operation, "SRL") == 0) { // Instruction ADD
        
        intInstruction = 0b000010; // 000010 bits
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rd
        intInstruction |= (intRegister << (5 + 6));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rt
        intInstruction |= (intRegister << (2 * 5 + 6));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(instruction); // sa
        intInstruction |= (intRegister << 6);
    }
    else if (strcmp(operation, "SUB") == 0) { // Instruction ADD
        
        intInstruction = 0b100010; // 100010 bits
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rd
        intInstruction |= (intRegister << (5 + 6));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rs
        intInstruction |= (intRegister << (3 * 5 + 6));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(instruction); // rt
        intInstruction |= (intRegister << (2 * 5 + 6));
    }
    else if (strcmp(operation, "SW") == 0) { // Instruction ADD
        
        intInstruction = 0b101011 << (2 * 5 + 16); // 101011 bits
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rt
        intInstruction |= (intRegister << 16);
        
        strbreak(&instruction, ' ');
        
        intInstruction |= atoi(strbreak(&instruction, '(')); // offset
        
        instruction = strbreak(&instruction, ')');
        
        intInstruction |= atoi(instruction) << (5 + 16); // base
    }
    else if (strcmp(operation, "SYSCALL") == 0) { // Instruction ADD
        
        intInstruction = 0b001100; // 001100 bits
        //...
    }
    else if (strcmp(operation, "XOR") == 0) { // Instruction ADD
        
        intInstruction = 0b100110; // 100110 bits
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rd
        intInstruction |= (intRegister << (5 + 6));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(strbreak(&instruction, ',')); // rs
        intInstruction |= (intRegister << (3 * 5 + 6));
        
        strbreak(&instruction, ' ');
        
        intRegister = registerToInt(instruction); // rt
        intInstruction |= (intRegister << (2 * 5 + 6));
        
    }
    
    sprintf(hexInstruction, "0x%08X", intInstruction);
    
    return hexInstruction;
}


char **readInstructionFromFile(char* name){
    
    FILE *file;
    int nbLine=0;
    int i = 0;
    char *readLine = malloc(24 * sizeof(char)); // Instruction en hexadecimal
    
    name = getExecutablePath(name); // recupération du chemin du fichier
    
    /* Ouverture du fichier */
    file = fopen(name, "r");
    
    if(file == NULL) {
        perror("Probleme ouverture fichier");
        exit(1);
    }
    
    /* Recupération du nombre de ligne du fichier */
    while(!feof(file)) {
        fgets(readLine,MAX_CHAR_INSTRUCTION, file);
        nbLine++;
    }
    
    /* Création d'un tableau à 2D dynamique */
    char **table = createTable(nbLine, MAX_CHAR_INSTRUCTION);
    
    /* Lecture dans le fichier */
    file = fopen(name, "r");
    nbLine = 0;
    while(!feof(file)) {
        fgets(readLine,MAX_CHAR_INSTRUCTION, file);
        /*for(i=0; i<MAX_CHAR_INSTRUCTION; i++){
            table[nbLine][i] = readLine[i];
        }*/
        strcpy(table[nbLine], readLine); // Stockage du fichier dans le tableau
        //printf("%s \n", table[nbLine]);
        nbLine++;
    }
    
    for(i=0; i<nbLine; i++){
        printf("%s \n", table[i]);
        nbLine++;
    }
    
    /* Fermeture du fichier */
    fclose(file);
    
    return table;
}