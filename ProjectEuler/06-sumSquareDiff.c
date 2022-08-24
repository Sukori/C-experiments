#include <stdio.h>
/*
Problem 6
The sum of the squares of the first ten natural numbers is:
1^2 + 2^2 +...+ 10^2 = 385

The square of the sum of the first ten natural numbers is:
(1+2+...+10)^2 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is
3025 - 385 = 2640
.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.


Bruteforce: on fait la somme des carrés jusqu'à 100 et le carré de la somme jusqu'à 100 ^^'
-> ça fait 100 additions + 1 carré + 100 carrés + 100 additions + une soustraction. 300 opérations, en soit c'est pas si affreux ^^'. Il faut monter très haut pour avoir des problèmes.

Mais ultra réduit c'est de compter la somme comme n(n+1)/2
et la somme des carrés comme n(n+1)(2n+1)/6

Là on ne boucle même plus, on fait juste un bête calcul. BAM !
*/

int main(){

    int nMAX = 100;

    int sommeEntiers = nMAX * (nMAX + 1) / 2;

    int sommeCarres = nMAX * (nMAX + 1) * (2 * nMAX +1) / 6;

    int result = sommeEntiers * sommeEntiers - sommeCarres;

    printf("La différence entre le carré de la somme des 100 premiers entiers et la somme des carrés des 100 premiers entiers est : %d - %d = %d\n", sommeEntiers * sommeEntiers, sommeCarres, result);

    return 0;
}
