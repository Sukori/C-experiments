#include <stdio.h>

/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

AH !

Bon ben pour commencer, je recycle ma fonction findprimes du problème 07 et je l'adapte pour additionner les primes que je trouve au fur et à mesure.
*/

const int limiteMax;

int nombreEnCours;

long result; 

int isPrime(int);

int main(){


     //Doom
    while(nombreEnCours < limiteMax){

        if(nombreEnCours % 3 != 0){

            if(isPrime(nombreEnCours) == 1){
                result += nombreEnCours;
            }
        }

        nombreEnCours += 2;
    
    }



    printf("La somme de tous les nombres premiers inférieurs à deux million est : %ld.\n", result);

    return 0;
}

int nombreEnCours = 5; // on n'est pas à 10 nombres près, autant commencer à 5 pour ignorer tous les pairs dès le début et permettre de mettre un filtre 3 avant de chercher un nombre premier car 3 a beaucoup de multiples et on va les skip dans la boucle.

const int limiteMax = 2000000;

long result = 5; //2+3, les deux premiers nombres premiers qui sont ignorés dans mes préfiltres.

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