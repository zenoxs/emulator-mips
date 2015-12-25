#include "emulator.h"


/*******************************************************
- fonction instructionToHex:
Traduis une instruction MIPS en hexadecimal
- parametre:
instruction : instruction MIPS
- retour:
instruction en hexadecimal
*******************************************************/
char* instructionToHex(char* instruction) {

	char* hexInstruction = malloc(10 * sizeof(char));	// Instruction en hexadecimal
	uint32_t intInstruction = 0;						// Instruction en binaire
	uint32_t intRegister = 0;							// Numero du registre
	char* operation;									// Opcode

	operation = strbreak(&instruction, ' '); // Recupere l'opcode

	if (strcmp(operation, "ADD") == 0) { // Instruction ADD

		intInstruction = 0b100000; // 100000 bits

		intRegister = registerToInt(strbreak(&instruction, ','));
		intInstruction |= (intRegister << 11);

		strbreak(&instruction, ' ');

		intRegister = registerToInt(strbreak(&instruction, ','));
		intInstruction |= (intRegister << (2 * 5 + 11));

		strbreak(&instruction, ' ');

		intRegister = registerToInt(instruction);
		intInstruction |= (intRegister << (5 + 11));

	}
	else if (strcmp(operation, "ADDI") == 0) { // Instruction ADDI

		intInstruction = (0b001000 << (2 * 5 + 16));// 001000 bits

		intRegister = registerToInt(strbreak(&instruction, ','));
		intInstruction |= (intRegister << (16)); // rt

		strbreak(&instruction, ' ');

		intRegister = registerToInt(strbreak(&instruction, ',')); // rs
		intInstruction |= (intRegister << (5 + 16));

		strbreak(&instruction, ' ');

		intInstruction |= atoi(instruction); // Immediate
	}
	else if (strcmp(operation, "AND") == 0) { // Instruction AND

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
	else if (strcmp(operation, "BEQ") == 0) { // Instruction BEQ

		intInstruction |= 0b000100 << (2 * 5 + 16); // 000100 bits

		intRegister = registerToInt(strbreak(&instruction, ',')); // rs
		intInstruction |= (intRegister << (5 + 16));

		strbreak(&instruction, ' ');

		intRegister = registerToInt(strbreak(&instruction, ',')); // rt
		intInstruction |= (intRegister << 16);

		strbreak(&instruction, ' ');

		intInstruction |= atoi(instruction); // offset

	}
	else if (strcmp(operation, "BGTZ") == 0) { // Instruction BGTZ

		intInstruction |= 0b000111 << (2 * 5 + 16); // 000111 bits

		intRegister = registerToInt(strbreak(&instruction, ',')); // rs
		intInstruction |= (intRegister << (5 + 16));

		strbreak(&instruction, ' ');

		intInstruction |= atoi(instruction); // offset

	}
	else if (strcmp(operation, "BLEZ") == 0) { // Instruction BLEZ

		intInstruction |= 0b000110 << (2 * 5 + 16); // 000110 bits

		intRegister = registerToInt(strbreak(&instruction, ',')); // rs
		intInstruction |= (intRegister << (5 + 16));

		strbreak(&instruction, ' ');

		intInstruction |= atoi(instruction); // offset

	}
	else if (strcmp(operation, "BNE") == 0) { // Instruction BNE

		intInstruction |= 0b000101 << (2 * 5 + 16); // 000101 bits

		intRegister = registerToInt(strbreak(&instruction, ',')); // rs
		intInstruction |= (intRegister << (5 + 16));

		strbreak(&instruction, ' ');

		intRegister = registerToInt(strbreak(&instruction, ',')); // rt
		intInstruction |= (intRegister << 16);

		strbreak(&instruction, ' ');

		intInstruction |= atoi(instruction); // offset

	}
	else if (strcmp(operation, "DIV") == 0) { // Instruction DIV

		intInstruction |= 0b011010; // 011010 bits

		intRegister = registerToInt(strbreak(&instruction, ',')); // rs
		intInstruction |= (intRegister << (5 + 10 + 6));

		strbreak(&instruction, ' ');

		intRegister = registerToInt(instruction); // rt
		intInstruction |= (intRegister << (10 + 6));

	}
	else if (strcmp(operation, "J") == 0) { // Instruction JUMP

		intInstruction |= 0b000010 << 26; // 000010 bits

										  // adresse instruction sous la forme 0x_________
		strbreak(&instruction, 'x');
		intInstruction |= atoi(instruction);
	}
	else if (strcmp(operation, "JAL") == 0) { // Instruction JAL

		intInstruction |= 0b000011 << 26; // 000011 bits

										  // adresse instruction sous la forme 0x_________
		strbreak(&instruction, 'x');
		intInstruction |= atoi(instruction);
	}
	else if (strcmp(operation, "JR") == 0) { // Instruction JR

		intInstruction |= 0b001000; // 001000 bits

		intRegister = registerToInt(instruction); // rs
		intInstruction |= (intRegister << (10 + 5 + 6));
	}
	else if (strcmp(operation, "LUI") == 0) { // Instruction LUI

		intInstruction |= 0b001111 << (2 * 5 + 16); // 001111 bits

		intRegister = registerToInt(strbreak(&instruction, ',')); // rt
		intInstruction |= (intRegister << 16);

		strbreak(&instruction, ' ');

		intInstruction |= atoi(instruction); // immediate

	}
	else if (strcmp(operation, "LW") == 0) { // Instruction LW

		intInstruction |= 0b100011 << (2 * 5 + 16); // 100011 bits

		intRegister = registerToInt(strbreak(&instruction, ',')); // rt
		intInstruction |= (intRegister << 16);

		strbreak(&instruction, ' ');

		intInstruction |= atoi(strbreak(&instruction, '(')); // offset

		intRegister = registerToInt(strbreak(&instruction, ')')); // base
		intInstruction |= (intRegister << (5 + 16));

	}
	else if (strcmp(operation, "MFHI") == 0) { // Instruction MFHI

		intInstruction |= 0b010000; // 010000 bits

		intRegister = registerToInt(instruction); // rd
		intInstruction |= (intRegister << (5 + 6));

	}
	else if (strcmp(operation, "MFLO") == 0) { // Instruction MFLO

		intInstruction |= 0b010010; // 010010 bits

		intRegister = registerToInt(instruction); // rd
		intInstruction |= (intRegister << (5 + 6));
	}
	else if (strcmp(operation, "MULT") == 0) { // Instruction MULT

		intInstruction = 0b011000; // 011000 bits

		intRegister = registerToInt(strbreak(&instruction, ',')); // rs
		intInstruction |= (intRegister << (5 + 10 + 6));

		strbreak(&instruction, ' ');

		intRegister = registerToInt(instruction); // rt
		intInstruction |= (intRegister << (10 + 6));

	}
	else if (strcmp(operation, "NOP") == 0) { // Instruction NOP

		intInstruction = 0;
	}
	else if (strcmp(operation, "OR") == 0) { // Instruction OR

		intInstruction = 0b100101; // 100101 bits

		intRegister = registerToInt(strbreak(&instruction, ',')); // rd
		intInstruction |= (intRegister << (5 + 6));

		strbreak(&instruction, ' ');

		intRegister = registerToInt(strbreak(&instruction, ',')); // rs
		intInstruction |= (intRegister << (3 * 5 + 6));

		strbreak(&instruction, ' ');

		intRegister = registerToInt(instruction); // rt
		intInstruction |= (intRegister << (2 * 5 + 6));

	}
	else if (strcmp(operation, "ROTR") == 0) { // Instruction ROTR

		intInstruction = 0b000010; // 000010 bits

		intRegister = registerToInt(strbreak(&instruction, ',')); // rd
		intInstruction |= (intRegister << (5 + 6));

		strbreak(&instruction, ' ');

		intRegister = registerToInt(strbreak(&instruction, ',')); // rt
		intInstruction |= (intRegister << (2 * 5 + 6));

		strbreak(&instruction, ' ');

		intInstruction |= (atoi(instruction) << 6); // sa
		intInstruction |= 1 << (3 * 5 + 6);

	}
	else if (strcmp(operation, "SLL") == 0) { // Instruction SLL

		intInstruction = 0b000000; // 000000 bits

		intRegister = registerToInt(strbreak(&instruction, ',')); // rd
		intInstruction |= (intRegister << (5 + 6));

		strbreak(&instruction, ' ');

		intRegister = registerToInt(strbreak(&instruction, ',')); // rt
		intInstruction |= (intRegister << (2 * 5 + 6));

		strbreak(&instruction, ' ');

		intInstruction |= (atoi(instruction) << 6); // sa

	}
	else if (strcmp(operation, "SLT") == 0) { // Instruction SLT

		intInstruction = 0b101010; // 101010 bits

		intRegister = registerToInt(strbreak(&instruction, ',')); // rd
		intInstruction |= (intRegister << (5 + 6));

		strbreak(&instruction, ' ');

		intRegister = registerToInt(strbreak(&instruction, ',')); // rs
		intInstruction |= (intRegister << (3 * 5 + 6));

		strbreak(&instruction, ' ');

		intRegister = registerToInt(instruction); // rt
		intInstruction |= (intRegister << (2 * 5 + 6));

	}
	else if (strcmp(operation, "SRL") == 0) { // Instruction SRL

		intInstruction = 0b000010; // 000010 bits

		intRegister = registerToInt(strbreak(&instruction, ',')); // rd
		intInstruction |= (intRegister << (5 + 6));

		strbreak(&instruction, ' ');

		intRegister = registerToInt(strbreak(&instruction, ',')); // rt
		intInstruction |= (intRegister << (2 * 5 + 6));

		strbreak(&instruction, ' ');

		intInstruction |= (atoi(instruction) << 6); // sa
	}
	else if (strcmp(operation, "SUB") == 0) { // Instruction SUB

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
	else if (strcmp(operation, "SW") == 0) { // Instruction SW

		intInstruction = 0b101011 << (2 * 5 + 16); // 101011 bits

		intRegister = registerToInt(strbreak(&instruction, ',')); // rt
		intInstruction |= (intRegister << 16);

		strbreak(&instruction, ' ');

		intInstruction |= atoi(strbreak(&instruction, '(')); // offset

		intRegister = registerToInt(strbreak(&instruction, ')')); // base
		intInstruction |= (intRegister << (5 + 16));
	}
	else if (strcmp(operation, "SYSCALL") == 0) { // Instruction SYSCALL

		intInstruction = 0b001100; // 001100 bits
	}
	else if (strcmp(operation, "XOR") == 0) { // Instruction XOR

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
	else
		hexInstruction = NULL;

	if(hexInstruction != NULL)
		sprintf(hexInstruction, "0x%08X", intInstruction);

	return hexInstruction;
}

void readFile(char* name, int mode) {

	FILE* file;
	int i = 0;
	int nbLines = 0;
	char* instruction = malloc(MAX_CHAR_INSTRUCTION * sizeof(char)); // Instruction
	char* hexInstruction;

	name = getExecutablePath(name); // recupération du chemin du fichier

									/* Ouverture du fichier */
	file = fopen(name, "r");

	if (file == NULL) {
		perror("Probleme ouverture fichier");
		exit(1);
	}

	while (!feof(file)) {
		fgets(instruction, MAX_CHAR_INSTRUCTION, file);
		nbLines++;
	}
	nbLines--; // Décremente d'une ligne a cause de feof

	rewind(file); // Reinitialise le curseur de la ligne dans le fichier
	eraseFile("resultats_non_interactif.txt"); // Efface le contenu du fichier

	for (i = 0; i < nbLines; i++) {
		fgets(instruction, MAX_CHAR_INSTRUCTION, file);
		instruction = strbreak(&instruction, '\n');
		hexInstruction = instructionToHex(instruction);
		printf("%s\t\t\t%s\n", instruction, hexInstruction);
		strcat(instruction, "\t\t\t");
		strcat(instruction, hexInstruction);
		saveFile(instruction, "resultats_non_interactif.txt");
		if (mode == PAS_A_PAS) {
			printf("Appuyez sur ENTREE pour continuer...");
			scanf("%s");
		}	
	}

	/* Fermeture du fichier */
	//fclose(file);
}

void executeInstruction(char* instruction, Memory memory, Registers registers) {
	char* operation;	// Opcode
	char* rd;
	char* rs;
	char* rt;
	char* base;
	int32_t rd_value;
	int32_t rs_value;
	int32_t rt_value;
	int16_t immediate;
	int16_t offset;

	operation = strbreak(&instruction, ' '); // Recupere l'opcode

	if (strcmp(operation, "ADD") == 0) { // Instruction ADD
		rd = strbreak(&instruction, ',');
		strbreak(&instruction, ' ');
		rs_value = getRegister(registers, strbreak(&instruction, ','));
		strbreak(&instruction, ' ');
		rt_value = getRegister(registers, instruction);
		setRegister(registers, rd, rs_value + rt_value);
	}
	else if (strcmp(operation, "ADDI") == 0) { // Instruction ADDI
		rt = strbreak(&instruction, ',');
		strbreak(&instruction, ' ');
		rs_value = getRegister(registers, strbreak(&instruction, ','));
		strbreak(&instruction, ' ');
		immediate = atoi(instruction);
		setRegister(registers, rt, rs_value + immediate);
	}
	else if (strcmp(operation, "AND") == 0) { // Instruction AND
		rd = strbreak(&instruction, ',');
		strbreak(&instruction, ' ');
		rs_value = getRegister(registers, strbreak(&instruction, ','));
		strbreak(&instruction, ' ');
		rt_value = getRegister(registers, instruction);
		setRegister(registers, rd, rs_value & rt_value);
	}
	else if (strcmp(operation, "BEQ") == 0) { // Instruction BEQ

	}
	else if (strcmp(operation, "BGTZ") == 0) { // Instruction BGTZ

	}
	else if (strcmp(operation, "BLEZ") == 0) { // Instruction BLEZ

	}
	else if (strcmp(operation, "BNE") == 0) { // Instruction BNE

	}
	else if (strcmp(operation, "DIV") == 0) { // Instruction DIV
		rs_value = getRegister(registers, strbreak(&instruction, ','));
		strbreak(&instruction, ' ');
		rt_value = getRegister(registers, instruction);
		setRegister(registers, "$LO", rs_value / rt_value);
		setRegister(registers, "$HI", rs_value % rt_value);
	}
	else if (strcmp(operation, "J") == 0) { // Instruction JUMP

	}
	else if (strcmp(operation, "JAL") == 0) { // Instruction JAL

	}
	else if (strcmp(operation, "JR") == 0) { // Instruction JR

	}
	else if (strcmp(operation, "LUI") == 0) { // Instruction LUI
		rt = strbreak(&instruction, ',');
		strbreak(&instruction, ' ');
		immediate = atoi(instruction);
		setRegister(registers, rt, immediate << 16);
	}
	else if (strcmp(operation, "LW") == 0) { // Instruction LW
		rt = strbreak(&instruction, ',');
		strbreak(&instruction, ' ');
		offset = atoi(strbreak(&instruction, '('));
		base = strbreak(&instruction, ')');
		int32_t address = offset + getRegister(registers, base);

		if (((address & 0b1) != 0) && ((address & 0b10) != 0))
			//exception
			printf("\nexception load word\n");
		else
			//address translation ???
			setRegister(registers, rt, loadWord(memory, address));
	}
	else if (strcmp(operation, "MFHI") == 0) { // Instruction MFHI
		setRegister(registers, instruction, getRegister(registers, "$HI"));
	}
	else if (strcmp(operation, "MFLO") == 0) { // Instruction MFLO
		setRegister(registers, instruction, getRegister(registers, "$LO"));
	}
	else if (strcmp(operation, "MULT") == 0) { // Instruction MULT
		rs_value = getRegister(registers, strbreak(&instruction, ','));
		strbreak(&instruction, ' ');
		rt_value = getRegister(registers, instruction);
		int64_t prod = rs_value * rt_value;
		setRegister(registers, "$LO", prod | 0b11111111111111111111111111111111);
		setRegister(registers, "$HI", (prod | (0b11111111111111111111111111111111 << 32)) >> 32);
	}
	else if (strcmp(operation, "NOP") == 0) { // Instruction NOP
		// No operation
	}
	else if (strcmp(operation, "OR") == 0) { // Instruction OR
		rd = strbreak(&instruction, ',');
		strbreak(&instruction, ' ');
		rs_value = getRegister(registers, strbreak(&instruction, ','));
		strbreak(&instruction, ' ');
		rt_value = getRegister(registers, instruction);
		setRegister(registers, rd, rs_value | rt_value);
	}
	else if (strcmp(operation, "ROTR") == 0) { // Instruction ROTR
		rd = strbreak(&instruction, ',');
		strbreak(&instruction, ' ');
		rt_value = getRegister(registers, strbreak(&instruction, ','));
		strbreak(&instruction, ' ');
		int8_t sa = atoi(instruction);
		//...
	}
	else if (strcmp(operation, "SLL") == 0) { // Instruction SLL
		rd = strbreak(&instruction, ',');
		strbreak(&instruction, ' ');
		rt_value = getRegister(registers, strbreak(&instruction, ','));
		strbreak(&instruction, ' ');
		int8_t sa = atoi(instruction);
		setRegister(registers, rd, rt_value << sa);
	}
	else if (strcmp(operation, "SLT") == 0) { // Instruction SLT

	}
	else if (strcmp(operation, "SRL") == 0) { // Instruction SRL
		rd = strbreak(&instruction, ',');
		strbreak(&instruction, ' ');
		rt_value = getRegister(registers, strbreak(&instruction, ','));
		strbreak(&instruction, ' ');
		int8_t sa = atoi(instruction);
		setRegister(registers, rd, rt_value >> sa);
	}
	else if (strcmp(operation, "SUB") == 0) { // Instruction SUB
		rd = strbreak(&instruction, ',');
		strbreak(&instruction, ' ');
		rs_value = getRegister(registers, strbreak(&instruction, ','));
		strbreak(&instruction, ' ');
		rt_value = getRegister(registers, instruction);
		setRegister(registers, rd, rs_value - rt_value);
	}
	else if (strcmp(operation, "SW") == 0) { // Instruction SW
		rt = strbreak(&instruction, ',');
		strbreak(&instruction, ' ');
		offset = atoi(strbreak(&instruction, '('));
		base = strbreak(&instruction, ')');
		int32_t address = offset + getRegister(registers, base);

		if (((address & 0b1) != 0) && ((address & 0b10) != 0))
			//exception
			printf("\nexception load word\n");
		else
			//address translation ???
			storeWord(memory, address, getRegister(registers, rt));
	}
	else if (strcmp(operation, "SYSCALL") == 0) { // Instruction SYSCALL
		// No operation
	}
	else if (strcmp(operation, "XOR") == 0) { // Instruction XOR
		rd = strbreak(&instruction, ',');
		strbreak(&instruction, ' ');
		rs_value = getRegister(registers, strbreak(&instruction, ','));
		strbreak(&instruction, ' ');
		rt_value = getRegister(registers, instruction);
		setRegister(registers, rd, rs_value ^ rt_value);
	}
}