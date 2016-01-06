//
//  utility.c
//  emulator-mips
//
//  Created by Amaury CIVIER on 14/12/15.
//  Copyright © 2015 Amaury CIVIER. All rights reserved.
//

#include "utility.h"

char* strbreak(char** s, char delimit) {
	char* result = malloc(20 * sizeof(char));
	int i = 0;

	if (strchr(*s, delimit) != NULL) { // Si le delimiteur est present dans s
		while (((*s)[i] != '\0') && ((*s)[i] != delimit)) { // On extrait la sous-chaine avant delimit
			result[i] = (*s)[i];
			i++;
		}
		result[i] = '\0';
		*s = &((*s)[i + 1]); // s devient la sous-chaine apres delimit
	}

	return result;
}

char* getExecutablePath(char* nameFile) {

	char* newPath = malloc(sizeof(char) * 1024); // Chemin du retour + nom du fichier

#if defined(__APPLE__) && defined(__MACH__)
	char path[1024]; // Chemin temporaire

	int i = 0;
	int stopPath = 0; // Detection de la fin du chemin

	uint32_t size = sizeof(path);

	if (_NSGetExecutablePath(path, &size) == 0)
		printf("executable path is %s\n", path);
	else
		printf("buffer too small; need size %u\n", size);

	while (path[i] != '\0') {
		if (path[i] == '/') {
			stopPath = i;
		}
		i++;
	}

	for (i = 0; i<stopPath; i++) {
		newPath[i] = path[i];
	}
	newPath[i] = '\0';

	sprintf(newPath, "%s/%s", newPath, nameFile);
#elif defined(_WIN32) || defined(_WIN64)
	char full[1024];

	if (_fullpath(newPath, nameFile, 1024) != NULL)
		printf("The full path is: %s\n", full);
	else
		printf("Invalid path.\n");
	//sprintf(newPath, ".\%s", nameFile);
#else
	sprintf(newPath, "./%s", nameFile);
#endif

	return newPath;
}

int saveFile(char* text, char* nameFile) {

	FILE* file = fopen(nameFile, "a");

	if (file == NULL) {
		perror("Probleme ouverture fichier");
		exit(1);
	}

	fprintf(file, "%s\n", text);

	fclose(file);

	return 0;
}

void eraseFile(char* name) {
	FILE* file = fopen(name, "w+");
	fclose(file);
}
