#include <stdio.h>
#include <math.h>

/*
Probleme 3
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
Bruteforce: en comptant depuis 1, trouver des nombres premiers et diviser le nombre par chacun d'eux en stockant la valeur du plus grand qui a fonctionné.
C'est stupide et ça peut faire des tonnes d'itérations.
Déjà, si on cherche le plus grand diviseur, on peut rester au dessous de la racine carrée du nombre, parce qu'on ne peut pas avoir un nombre premier plus grand que ça comme facteur.
Un nombre premier n'est jamais pair, donc on peut ignorer tous les nombres pairs dans nos calculs.
On peut aussi dégager les multiples de 5 et de 3 et commencer à partir de 7.
Les multiples de 5 et 3 sont obvious et très nombreux. les multiples de 7, déjà moins.
Donc on peut compter de 2 en 2 à partir de 7 pour ne pas inutilement tester les nombres pairs.
Merci Wolfram alpha: 6857 est le nombre qu'on recherche.
Prime factors: 71×839×1471×6857 = 600851475143
On commence à 7
On teste si le nombre est divisible par 3-5, si oui, on skip
sinon on essaie de diviser N par notre nombre.
Si divisible, on place le nombre en buffer jusqu'à en trouver un plus grand
sinon, on recommence avec le n+2 (donc 9 après 7, comme on évite les nombres pairs).
Le buffer est une liste, parce qu'on veut aussi vérifier que le nombre trouvé, n'est pas aussi un multiple d'un nombre premier déjà trouvé, non ?
    //function test prime(n)
    //function test divide (n,N) -> function test prime (n+2)
*/

static long theNumber = 600851475143;
float sqRoot = 0;
int result = 0;

void diviseurs();
void isPrime(int);

int main(){
    sqRoot = sqrt(theNumber);
    diviseurs();
    printf("le plus grand facteur premier de %ld est %d\n\n", theNumber, result);
    return 0;
}

void diviseurs() {
    for (int i = 7; i < sqRoot; i += 2) {
        if (i % 3 == 0 || i % 5 == 0) {
            continue;
        }
        
        if(theNumber % i == 0){
            isPrime(i);
        }
    }
}

void isPrime(int diviseurAtest){
    for(int j = 7; j < sqrt(diviseurAtest); j += 2){
        if(diviseurAtest % j == 0){
            return;
        }
    }
    result = diviseurAtest;
}