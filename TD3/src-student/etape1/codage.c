#include "../commun/td3.h"


extern Handler HANDLER_TABLE[PALETTE_SIZE];
extern char ALPHABET_PALETTE[PALETTE_SIZE];
extern char* NOM_FICHIERS[PALETTE_SIZE];

//choix de la palette a utiliser
char* palette_courante = ALPHABET_PALETTE;


void codage(int in)
{

int position = 0;
while(c=read(in,palette_courante,PALETTE_SIZE)){ // palette size nbr de caractere qu'on lit à chaque fois
	c=tolower(c) //On prend la minuscule
	int index_caracter = get_index_for_char(c);

	char fichier =
	p++
}
Tantque ( c <- Lecture_Caractere( descripteur ) ) Faire
c <- miniscule(c)
index_caracter <- avoir_index_caractere_dans_palette(c)
4nomfichier <- nom_fichiers[index_caracter]
out <- ouvrir_fichier(nomfichier)
ecrire_position( out, position )
fermer_fichier(out)
position++
Fin Tanque
Fin
}


void decodage(int out)
{


}
