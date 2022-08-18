#include <stdio.h>

/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10'001st prime number?


Donc j'avais fait un truc du genre de rechercher les nombres premiers à partir de 21 (ou 23) et utiliser tous les nombres premiers trouvés pour les ajouter à la liste des nombres dont les multiples sont à ignorer, pour ignorer de plus en plus de nombre et ne pas faire péter le processeur.
On ignore aussi tous les nombres paires.
*/

int premiers[];

int multiplePremier(int, int[]);

int positionAtrouver;

int nombreEnCours;

int limiteur;


int main()
{

    printf("Quel nombre premier veux tu trouver ?\n");
    scanf("%i\n", &positionAtrouver);

    //Doom, mettre un limiteur
    while(length(premiers) < positionAtrouver || limiteur == 0){
        limiteur--;
        int step = multiplePremier(nombreEnCours, premiers);
    }
    
    return 0;
}

int limiteur = 100;

int premiers[] = {3,5,7,11,13,17,19};

int nombreEnCours = 23;

int multiplePremier(int nombre, int premiersTrouve[]){
    for (int i = 0; i < length(premiersTrouve); i++)
    {
        /* code */
    }
    
}