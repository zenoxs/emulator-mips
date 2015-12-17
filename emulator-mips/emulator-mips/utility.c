//
//  utility.c
//  emulator-mips
//
//  Created by Amaury CIVIER on 14/12/15.
//  Copyright © 2015 Amaury CIVIER. All rights reserved.
//

#include "utility.h"

char **createTable(int nbLin, int nbCol){
    /*char **tableau = (char **)malloc(sizeof(char*)*nbLin);
    char *tableau2 = (char *)malloc(sizeof(char)*nbCol*nbLin);
    for(int i = 0 ; i < nbLin ; i++){
        tableau[i] = &tableau2[i*nbCol];
    }*/
    
    char **tab;
    
    /* Allocation de la 1er dimension */
    tab = (char **)malloc ( sizeof(char *)  *  nbLin);
    /* Allocation 2e dimension */
    for (int i = 0 ; i < nbLin ; i++){
        tab[i] = (char *)malloc (sizeof(char) * nbCol);
    }
    
    return tab;
}

char *getExecutablePath(char *nameFile){
    
    char *newPath = malloc(sizeof(char)*1024); // Chemin du retour + nom du fichier
    
#if defined(__APPLE__) && defined(__MACH__)
    char path[1024]; // Chemin temporaire
    
    int i = 0;
    int stopPath = 0; // Detection de la fin du chemin
    
    uint32_t size = sizeof(path);
    
    if (_NSGetExecutablePath(path, &size) == 0)
        printf("executable path is %s\n", path);
    else
        printf("buffer too small; need size %u\n", size);
    
    while(path[i] != '\0'){
        if(path[i] == '/'){
            stopPath = i;
        }
        i++;
    }
    
    for(i=0; i<stopPath; i++){
        newPath[i] = path[i];
    }
    newPath[i] = '\0';
    
    sprintf(newPath, "%s/%s", newPath, nameFile);
#elif defined(_WIN32) || defined(_WIN64)
    sprintf(newPath, ".\%s", nameFile);
#else
    sprintf(newPath, "./%s", nameFile);
#endif
    
    return newPath;
}
