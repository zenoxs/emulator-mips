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

char *getExecutablePath(char *nameFile);
char** readFile(char* name); // stock le contenu d'un tableau
char **createTable(int nbLin, int nbCol); // créée un tableau de char à 2D

#endif /* utility_h */
