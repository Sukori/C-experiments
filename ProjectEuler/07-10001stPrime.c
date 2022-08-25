#include <stdio.h>
#include <math.h>

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
    on le compare % i, ou 7 < i < sqrt(nombre en cours) ; i+6 on se permet de tirer parti du fait qu'un nombre premier peut s'écrire comme 6n +/- 1
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

int isPrime(int);

int main(){

    //Doom
    while(positionEnCours < positionMax){

        if(nombreEnCours % 3 != 0){

            if(isPrime(nombreEnCours) == 1){
                result = nombreEnCours;
                positionEnCours++;
            }
        }

        nombreEnCours += 2;
    
    }

    printf("Le 10001-ième nombre premier est %d.\n", result);
    
    return 0;
}

int nombreEnCours = 5; // on n'est pas à 10 nombres près, autant commencer à 5 pour ignorer tous les pairs dès le début et permettre de mettre un filtre 3 avant de chercher un nombre premier car 3 a beaucoup de multiples et on va les skip dans la boucle.

int positionEnCours = 2; // parce que 3 est le deuxième nombre premier.

int positionMax = 10001;

int result = 3; // 3 est le plus grand nombre premier trouvé pour le moment

int isPrime(int nombreTest){

    if(nombreTest == 5){ // obligé sinon 5 ne passe pas le test ci-dessous
        return 1;
    }

    for(int i = 5; i <= sqrt(nombreTest); i = i+6){

        if(nombreTest % i == 0 || nombreTest % (i+2) == 0){
            return 0;
        }

    }

    return 1;
}