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

// Recupere le chemin absolu d'un fichier
char* getExecutablePath(char *nameFile);

// Découpe une chaine de characteres en 2 a partir d'un delimiteur
char* strbreak(char** s, char delimit);

// Sauvegarde le contenu d'une chaine de caractére dans un fichier
int32_t saveFile(char* text, char* nameFile);

// Efface le contenu d'un fichier
void eraseFile(char* name);

// Convertit un nombre haxadecimal en entier decimal
uint32_t hexaToInt(char* hexa);

#endif /* utility_h */
