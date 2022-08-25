#include <stdio.h>

/*
Given the 1000 digit number:
73167176531330624919225119674426574742355349194934
96983520312774506326239578318016984801869478851843
85861560789112949495459501737958331952853208805511
12540698747158523863050715693290963295227443043557
66896648950445244523161731856403098711121722383113
62229893423380308135336276614282806444486645238749
30358907296290491560440772390713810515859307960866
70172427121883998797908792274921901699720888093776
65727333001053367881220235421809751254540594752243
52584907711670556013604839586446706324415722155397
53697817977846174064955149290862569321978468622482
83972241375657056057490261407972968652414535100474
82166370484403199890008895243450658541227588666881
16427171479924442928230863465674813919123162824586
17866458359124566529476545682848912883142607690042
24219022671055626321111109370544217506941658960408
07198403850962455444362981230987879927244284909188
84580156166097919133875499200524063689912560717606
05886116467109405077541002256983155200055935729725
71636269561882670428252483600823257530420752963450

The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.
Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?

J'ai pu voir avec le palindrome que C est assez lourd pour convertir des nombres en string et vice versa... Surtout que là on est sur un nombre immense. On peut prendre tout le grand nombre comme un char et tester '0'. Quand on a trouver 13 non 0, on convertit les chiffres du tableau un à un. Pas de long.

C'est un nombre à 1000 chiffres, donc la liste qui le contient va de 0 à 999. Lorsqu'on a lu nombre[999], le programme s'arrête et on prend le dernier resultat en mémoire.

Bruteforce:
on prend les 13 premiers nombres et on les multiplie entre eux.
On stock le résultat et les nombres
On incrémente la position de 1 et on recommence avec 13 nombres et on compare avec le produit précédent

On ne peut pas se permettre de compter les positions de 13 en 13. Cela skip trop de combinaisons possibles.
On peut prendre 13 nombres et s'il y a un 0 parmi eux, il faut prendre les 13 nombres après le 0.

Première boucle:
On parcourt le nombre chiffre par chiffre.
Si on trouve un 0, on arrête la lecture et on recommence à partir du chiffre après le 0
Si on arrive à réunir 13 chiffres, on les multiplie
On compare avec le résultat précédent, si plus grand on stock la nouvelle valeur, sinon on skip

Deuxième boucle:
On retire le chiffre le plus à gauche de la série de chiffres et on lit le chiffre suivant dans le grand nombre à droite de la série.
Si le chiffre est 0, on reprend la première boucle à partir du chiffre après 0.
Sinon on refait le produit. On compare avec le resultat le plus grand déjà trouvé et on refait la deuxième boucle.

*/

int teteDeLecture;

int serie13[13];

long result;

int makeINT(char);

char make13Serie(char);

char oneStepSerie(char);

long multiply(int);

//*********************************
//MAIN

int main(){

    printf("Le plus garnd produit de 13 chiffres dans la série est %d", result);

    return 0;
}

//*********************************


int teteDeLecture = 0;

int serie13[13] = {};

long result = 0;

int makeINT(char chiffre){
    //convert one char to int
}

char make13Serie(char){
    //read 13 from teteDeLecture
    //check if '0' a each step
    //if '0', teteDeLEcture ++ et make13serie
    //else, MakeINT et push in serie13 from the right
}

char oneStepSerie(char){
    //check if the number on the right == '0'
    //if '0', teteDeLecture++ et make13serie
    //else remove one from the left of the array and add one to the right
}

long multiply(int nombres){
    //multiplier les nombres de la serie13 entre eux et stocker le résultat si plus grand que précédent
}