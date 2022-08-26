#include <stdio.h>

/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2

For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

J'ai voulu filouter:
(3^2 + 4^2 + 5^2) * 20 = 1000
9*20 + 16*20 + 25*20 = 1000
180 + 320 + 500 = 1000
(180^2) + (320^2) ?= (500^2) non

Bon, on a testé la filouterie.

Donc le but c'est d'avoir a + b + c = 1000 ET a^2 + b^2 = c^2 ET a < b < c
Quel est le résultat de a * b * c ?

Il n'y a exactement qu'une seule solution.

J'ai la preuve que trouver =1000 et < ne suffit pas. Donc le début c'est plutôt de trouver les ^2 qui vérifient l'égalité.

Brute force : tout tester un par un jusqu'à 1 + 2 + 997 puis recommencer en incrémentant b XD. Dans 1000 ans, on y est encore.
Note 0 + 499 + 501 = 1000. a = 0 est autorisé XD, mais pas forcément utile ... Surtout qu'on cherche le résultat du produit des 3 nombres, ça serait triste d'avoir 0 XD.

Bon, sinon, c'est une occasion de faire de la trigo avec sinus/cosinus.
*/

int main(){

    return 0;
}