//
//  utility.h
//  emulator-mips
//
//  Created by Amaury CIVIER on 14/12/15.
//  Copyright © 2015 Amaury CIVIER. All rights reserved.
//

#ifndef utility_h
#define utility_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#if defined(__APPLE__) && defined(__MACH__)
#include <mach-o/dyld.h>
#endif

#define MAX_CHAR_INSTRUCTION 50
#define NB_REGISTERS 34
#define PAS_A_PAS 1

char* getExecutablePath(char *nameFile);
char* strbreak(char** s, char delimit);
int saveFile(char* text, char* nameFile); // Sauvegarde le contenu d'une chaine de caractére dans un fichier
void eraseFile(char* name);
uint32_t hexaToInt(char* hexa);

#endif /* utility_h */
