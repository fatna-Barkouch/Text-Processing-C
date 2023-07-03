#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char** extraireLignes(char* nomFichier)
{
    // Declatation des variables lignes, ligne, nb, i, caractereActuel, fichierSource
    FILE* f = fopen(nomFichier,"r");
    int S=sizeof(f)*256,i=0;
    char **lignes = (char**)malloc(sizeof(char*)*S);
    char *texte = (char*)malloc(sizeof(char)*S);
    char *ligne;
    fread(texte,sizeof(char),S,f);
   // getch();
    //system("cls");
	ligne = strdup(strtok(texte,"\n"));//strdup() retourne l'adresse d'un tableau de caractéres alloué dynamiquement contenant une copie de la chaine passée en paramètre.
        //strtok() Cette fonction renvoie un pointeur sur le dernier jeton trouvé dans la chaîne
    while(ligne != NULL)
    {
    	lignes[i]=strdup(ligne);
    	i++;
     	ligne = strtok(NULL,"\n");
    }
    lignes[i]='\0';
    return lignes;
}
char** extraireMots(char* ligne, char* delim)
{   int i=0,n=0,j;
	char **mots =(char**)malloc(sizeof(char*)*n);
	char *mot =(char*)malloc(sizeof(char));
	mot = strdup(strtok(ligne,delim));
	i=0;
	while(mot!=NULL)
	{
		mots[i]=strdup(mot);
		i++;
		mot = strtok(NULL,delim);
	}
	mots[i]='\0';
	return mots;
}

int chercheMot(char *nomFichier,char *mot)
{
    int trouve=0;
    FILE *f;
    char *chaine=malloc(sizeof(char*)*20);
    f=fopen(nomFichier,"r+");
while(fgets(chaine,strlen(mot)+1,f)!=NULL)
{
        if (strcmp(chaine,mot)==0)
            trouve=1;
}
return trouve;
}
int chiffre(char c)
{
	return(c>='0' && c<='9');
}
int ident(char *mot)
{
    int i=1;
    int etat=0;

	if((mot[0]>='A' && mot[0]<='Z') || (mot[0]>='a' && mot[0]<='z') || mot[0]=='_')
    {
       while(mot[i]!='\0' && ((mot[i]>'A' && mot[i]<'Z') ||
	   (mot[i]>'a' && mot[i]<'z') || (chiffre(mot[i])) || mot[i]=='_'))
	   {  i++;}
       if(mot[i]=='\0')etat=1;
    }
    return etat;
}

// un nombre reel
int reel(char *ch)
{
	int etat=0, compt=0;
	int n=strlen(ch);

    if(ch[compt]=='+' || ch[compt]=='-') etat=1 ;
    else if(chiffre(ch[compt])) etat=2 ;
    else if(ch[compt]=='.') etat=3 ;
    else return 0;
    compt++;
    while(compt!=n)
    {
    	if(etat==1)
    	{
	        if(chiffre(ch[compt])) etat=2 ;
	        else if(ch[compt]=='.') etat=3 ;
	        else break;
    	}
        else if(etat==2 )
    	{
	        if(chiffre(ch[compt])) etat=2 ;
	        else if(ch[compt]=='.') etat=3 ;
	        else break;
    	}
        else if(etat==3)
        {
        	if(chiffre(ch[compt])) etat=4;
        	else break;
    	}
    	else if(etat==4)
        {
        	if(chiffre(ch[compt])) etat=4;
        	else break;
    	}
    	compt++;
    }

    if(strcmp(ch,".")==0) return 0;
	if(compt==n && (etat==4 || etat==3 || etat==2))
	    return 1;
	return 0;
}
void main(){
FILE *file = fopen("generateFile.txt","w+");
char** extLigne=extraireLignes("test.txt");
char** extMots=(char**)malloc(sizeof(char)*40);
for(int i=0;extLigne[i]!='\0';i++){
        printf("************la ligne numero %d************\n",i+1);
    fprintf(file,"la ligne numero %d ces proprietes sont : %s\n",i+1,extLigne[i]);
    extMots=extraireMots(extLigne[i],"# <>()[],;{}");
    for(int j=0;extMots[j];j++)
    {
        if(chercheMot("motcle.txt",extMots[j])){
            printf("%s est un mot cle\n",extMots[j]);
            fprintf(file,"%s est un mot cle\n",extMots[j]);
             }
       else if(chercheMot("operateur.txt",extMots[j])){
        printf("%s est un operateur \n",extMots[j]);
        fprintf(file,"%s est un operateur \n",extMots[j]);
       }
       else if(chercheMot("caracterespecial.txt",extMots[j])){
        printf("%s est un caractere special \n",extMots[j]);
        fprintf(file,"%s est un caractere special  \n",extMots[j]);
       }
       else if(ident(extMots[j])){
        printf("%s est un identifiant\n",extMots[j]);
            fprintf(file,"%s est un identifiant\n",extMots[j]);
       }
       else if(reel(extMots[j])){
        printf("%s est un reel\n",extMots[j]);
            fprintf(file,"%s est un reel\n",extMots[j]);
       }
    }
}
fclose(file);
}
