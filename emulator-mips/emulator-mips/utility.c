//
//  utility.c
//  emulator-mips
//
//  Created by Amaury CIVIER on 14/12/15.
//  Copyright © 2015 Amaury CIVIER. All rights reserved.
//

#include "utility.h"

/*********************************************************
- fonction strbreak:
Decoupe une chaine de characteres en deux sous-chaines
a partir d'un delimieur
- parametres:
> s: chaine de caractere a decouper
> delimit: charactere delimiteur
- retour:
> s: sous-chaine se trouvant apres le delimiteur
> sous-chaine se trouvant avant le delimiteur
*********************************************************/
char* strbreak(char** s, char delimit) {
	char* result = malloc(20 * sizeof(char)); // Sous-chaine retournee
	int i = 0; // Indice de boucle

	if (strchr(*s, delimit) != NULL) { // Si le delimiteur est present dans s
									   // On extrait la sous-chaine avant delimit
		while (((*s)[i] != '\0') && ((*s)[i] != delimit)) { // Tant que le delimiteur n'est pas trouvé
			result[i] = (*s)[i]; // Copie des characteres avant le delimiteur dans result
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


/*******************************************************
- fonction saveFile:
Sauvegarde le contenu d'une chaine de caractere dans
un fichier
- parametres:
> text: chaine de caractere a sauvegarder
> nameFile: nom du fichier
- retour:
> resultat de l'execution: 0 = echec / 1 = succes
*******************************************************/
int32_t saveFile(char* text, char* nameFile) {
	int32_t result = 1; // resultat succes/echec de l'ouverture du fichier

	FILE* file = fopen(nameFile, "a"); // Ouverture du fichier en ecriture

	if (file == NULL) {
		perror("Probleme ouverture fichier");
		result = 0;
	}
	else {
		fprintf(file, "%s\n", text); // Sauvegarde le contenu de text dans le fichier
		fclose(file); // Fermeture du fichier
	}

	return result;
}


/*******************************************************
- fonction eraseFile:
Efface le contenu d'un fichier
- parametre:
> name: nom du fichier
*******************************************************/
void eraseFile(char* name) {
	// Ouverture du fichier en ecriture avec effacement du contenu prealablement
	FILE* file = fopen(name, "w+");
	fclose(file); // Fermeture du fichier
}


/*******************************************************
- fonction hexaToInt:
Convertit un nombre haxadecimal en entier decimal
- parametre:
> hexa: chaine de caractere contenant un nombre
hexadecimal
- retour:
> entier decimal
*******************************************************/
uint32_t hexaToInt(char* hexa) {
	strbreak(&hexa, 'x'); // Supprime les characteres "0x"

	int length = (int)strlen(hexa); // Longueur de la chaine
	int i; // Indice de boucle
	int ascii; // Charactere hexa a convertir
	uint32_t number = 0; // nombre decimal convertit

	for (i = length - 1; i >= 0; i--) {
		ascii = (int)hexa[i]; // On recupere le charactere hexadecimal

							  // Si le charactere hexadecimal est un chiffre (0x0 a 0x9)
		if (ascii >= 48 && ascii <= 57) {
			number = number | ((ascii - 48) << (length - i) * 4);
		}
		// Si le charactere hexadecimal est une lettre majuscule (0xA a 0xF)
		if (ascii >= 65 && ascii <= 70) {
			number = number | ((ascii - 55) << (length - i - 1) * 4);
		}
		// Si le charactere hexadecimal est une lettre minuscule (0xa a 0xf)
		else if (ascii >= 97 && ascii <= 102) {
			number = number | ((ascii - 87) << (length - i) * 4);
		}
	}

	return number;
}
