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
Note 0 + 499 + 501 = 1000. a = 0 est autorisé XD, mais pas forcément utile ... Surtout qu'on cherche le résultat du produit des 3 nombres, ça serait triste d'avoir 0 XD. le minimum requis c'est 0<1<2 pour a<b<c

allez, pour la doc:
for(int c = 2; c < 1000; c++)
    for(int b = 1; b < c; b++)
        for(int a = 0; a < b; a++)
            if(a+b+c == 1000 && a^2+b^2==c^2)
                return (a*b*c)

Voila, c'est tout con et ça ne prend que quelques lignes pour un calcul bien long.

maintenant Si on veut résoudre d'une manière plus élaborée, il y a la formule d'Euclide. Mais elle sort d'un bouquin. J'ai envie de calculer moi-meme.

par exemple, en factorisant un tit peu, on peut isoler c = 1000 - a - b

donc c^2 = (1000 - a - b)^2
a^2 + b^2 = 1'000'000 + a^2 + b^2 + 2ab - 2000a - 2000b
On constate avec l'égalité ci-dessus que 1'000'000 + 2ab -2000a - 2000b = 0
Continuons: ab - 1000a - 1000b = -500'000
on veut inverser le signe du -500'000, donc on peut faire  + 1'000'000

1'000'000 + ab -1000a - 1000b = 500'000
Et on peut factoriser::
(1000 - a) (1000 - b) = 500'000

De là, on peut essayer de trouver les valeurs de a et b en cherchant des facteurs premiers de 500'000 : 2^5 * 5^6. nommons les F1 et F2 -> exercice prime factors.
On peut supposer 700^2 = 490'000, qui est assez proche de 500'000, donc on recherche des nombres proches de 700 pour a et b.
Prenons large 500 < F1,F2 < 1000
F1, 2^5 = 32, on n'est pas dans l'intervale 500 - 1000. En plus, il n'a pas de facteur 5 dans 32, donc on peut retirer 5 pour les deux facteurs:
2^5 * 5^4 : 100 < F1/5, F2/5 < 200, 32 n'est toujours pas dans l'intervalle, alors on retire encore deux facteurs 5
2^5 * 5^2 : 20 < F1/5^2, F2/5^2 < 40, là on arrive à fit 32, et l'autre facteur est 5^2 = 25
32 * 32 = 1024, on est plus haut que 1000
32 * 25 = 800, parfait
25 * 25 = 625, parfait aussi

on peut donc poser:
F1 = 1000 - a = 800 -> a = 200
F2 = 1000 - b = 625 -> b = 375

donc c = 1000 - 200 - 375 = 425

et voilà

Alors c'est très beau, mais c'est une solution humaine. On ne peut pas coder ça sans avoir le résultat au fond. Donc le bruteforce est mon meilleur plan sur ce problème... Tant pis ^^'
*/

int main(){
    // exécution même pas si lente. sur un nombre plus grand par contre ...
    for(int c = 2; c < 1000; c++){
        for(int b = 1; b < c; b++){
            for(int a = 0; a < b; a++){
                if(a+b+c == 1000 && a*a+b*b == c*c){
                    printf("Les trois nombres sont %d, %d et %d.\nLeur somme est bien %d et leur produit est : %d\n", a, b, c, a+b+c, a*b*c);
                }
            }
        }
    }

    return 0;
}