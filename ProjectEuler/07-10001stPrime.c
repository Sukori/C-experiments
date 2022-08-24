#include <stdio.h>

/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10'001st prime number?


On ignore tous les nombres paires.
La bruteforce s'appelle le tamis d'Eratosthène, mais à ma sauce, parce que là je me fiche de compter 2, 3, 5,... Je commence directement plus haut pour sauter quelques pas.
Aussi je peux ignorer les nombres pairs dans la boucle, plutôt que de tester %2.
J'avais vu aussi dans 03 qu'on pouvait se contenter de compter jusqu'à sqrt du nombre, plutôt que tout faire

alors on veut faire:

on commence avec nombre en cours
on regarde si le nombre en cours est premier
    on le compare % i, ou 3 < i < sqrt(nombre en cours) ; i+2 osef des nombres paires
    si on a % = 0 alors pas premier, continue
    si on sort de la boucle sans % = 0
        Result = le nombre en cours, qui est premier
        position en cours ++
        et on retente la boucle avec le nombre + 2
si position en cours == position max, alors result == le 10001e nombre premier
*/

int positionEnCours;

int positionMax;

int nombreEnCours;

int result; //le plus grand premier trouvé à ce moment

int main(){

    //Doom
    while(positionEnCours < positionMax){
        
    
    }

    printf("Le 10001-ième nombre premier est %d.\n", result);
    
    return 0;
}

int nombreEnCours = 3; // on sait qu'après 29, c'est 31 le nombre premier suivant.

int positionEnCours = 10; // parce qu'il y a dix nombres premiers de 2 à 29 inclus.

int positionMax = 10001;

int result

