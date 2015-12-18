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

#define MAX_CHAR_INSTRUCTION 25

char* getExecutablePath(char *nameFile);
char* strbreak(char** s, char delimit);
int saveFile(char* text, char* nameFile, char* mode); // Sauvegarde le contenu d'une chaine de caractére dans un fichier

#endif /* utility_h */
