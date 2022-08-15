#include <stdio.h>

/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

On sait que faire 20! ne va pas donner le plus petit multiple.
Bruteforce: on teste les nombres un à un à partir de 20 et on les divise par 1 à 20. Très lourd pour rien.

Le nombre recherché finit forcément par 0: il doit etre pair et multiple de 5.
Pour rester dans les multiples de 20, on peut aussi compter de 20 en 20 à partir de 40?
Il faut aussi compter avec les nombres premiers entre 1 et 20. On peut skip 2 et 5.
Pour info: {3, 7, 11, 13, 17, 19}
Bof en fait. Ils n'ont rien à m'apporter là.

Cela dit, avant de diviser par des tonnes de trucs, je peux tester si c'est multiple de nombre premiers. Si oui, on teste les autres, si non, on skip. ça fait une condition d'entrée assez sévère sur peu de tests. Comme on compte de 20 en 20, on saute aussi un tas de nombres et pas besoin de tester pour les nombres pairs, les multiples de 5.
Les multiples de nombres pairs sont forcément pairs:
pair * pair = pair
pair * impair = pair
impair * impair = impair -> OSEF ici

Bon je peux faire la liste des nombres à tester absolument parce qu'on n'est pas sur, sauf 1, 2, 5, 10 et 20, parce que ça on le sait déjà.
Pour info: {3, 4, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19}

Si c'est un multiple de 18, c'est forcément un multiple de 3, 6, 9.
18 = 9*2 || 3*6
9 = 3*3
6 = 3*2
(3*3*2) * X -> est à la fois multiple de 3, 6, 9, 18

Donc en ne testant que les multiples à partir de 11, on a forcément aussi respecté les multiples des chiffres au dessous.
Pour info: {11, 12, 13, 14, 15, 16, 17, 18, 19}

On compte de 20 en 20
On test si c'est divisible par tous les nombres voulus
C'est un petit bruteforce sur 9 nombres seulement.

évidemment, l'algo doitetre affiné si on veu tester sur autre chose que 20.
Piste: trouver le plus petit ensemble de nombres premiers qui permet de construire tous les nombres de 1-X. Cet ensemble est la factorisation en nombres premiers du plus petit nombre qui soit multiple de tous les entiers successifs entre 1 et X.
Le problème 3, smallest primeFactors sert à ça.

*/

int diviseursATester[] = {11, 12, 13, 14, 15, 16, 17, 18, 19}; // length = 9

int iterations20(int);

int main(){

    int result = iterations20(40);
    printf("%d est le plus petit nombre divisible par tous les entiers successifs compris entre 1 et 20.\n", result);

    return 0;
}

int iterations20(int nombreATester){

    for(int i = 0; i < 9; i++){
        if(nombreATester % diviseursATester[i] != 0){
            
            return iterations20(nombreATester + 20);
        }
    }

    return nombreATester;
}