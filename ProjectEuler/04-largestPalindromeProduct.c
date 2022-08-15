#include <stdio.h>
#include <stdlib.h>

/*
Probleme 4
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

sprintf(str, "%f", number); -> avec ça on peut ensuite considérer le string comme un tableau.

Bruteforce: on fait le produit de deux nombres entre 100 et 999 chacun.
On commence avec 100 et on le multiplie par tout, jusqu'à 999
n * n+x pour 0 <= x <= 999 - (n-1) et pour 100 <= n <= 999

Alors si on veut être intelligent, on commence de tout en haut et on descend de 999 à 100. Mais la condition d'arrêt est à établir.

On peut essayer de prédire que le plus grand palindrome commence avec 9 et finit par 9.
Le seul moyen d'avoir un produit qui commence par 9 est de rester entre 901 et 999, Ce qui réduit la zone de recherche.
Aussi, si on finit par 9, on peut skip de la boucle tous les nombres pairs.

Si cela ne fonctionne pas, on peut toujours bruteforce en faisant pour tout.

Tu peux aussi faire une version qui cherche un palindrome en dehors du cadre de cet exercice en pensant à:
10^5 * a + 10^4 * b + 10^3 *c + 10^2 * c + 10 * b + a est un palindrome de 6 chiffres
en factorisant on a 11(9091a + 910b + 100c), un multiple de 11.
si le résultat de la multiplication est multiple de 11, c'est peut-tre ce qu'on cherche, sinon on passe au step suivant.
On gagne masse essais.


à chaque multiplication, on convertit le résultat en string
on lit le résultat par les deux bouts.
Si on a une différence entre les deux chiffres comparés, c'est dead, sinon on continue.
Si la boucle termine, on sauve dans notre variable result. La dernière entrée sera forcément la plus grande.

C'est valable en C [::-1] pour inverser un string ??? -> non

"Found the palindrom 906609, which is made from 913*993"
*/

int length = 0;
char* stringedINT = "";

int multiplication (int, int);
int isPalindrome(char*);

int main(){

    int multiplicationResult = 0;
    int biggest = 1;
    int multiplicateurs[2];

    for(int i = 999; i > 100; i -= 2){
        for(int j = i; j > 100; j -= 2){

            multiplicationResult = multiplication(i,j);

            if(multiplicationResult > biggest){
                length = snprintf(NULL, 0, "%d", multiplicationResult);
	        stringedINT = malloc(length + 1);
	        snprintf(stringedINT, length + 1, "%d", multiplicationResult);

                if(isPalindrome(stringedINT)){

                    if(multiplicationResult > biggest){
                        biggest = multiplicationResult;
                        multiplicateurs[0] = i;
                        multiplicateurs[1] = j;
                    }
                
                }
            }
        }
    }

    printf("Le nombre %d est un palindrome est est le résultat de %d * %d.\n", biggest, multiplicateurs[0], multiplicateurs[1]);
    return 0;
}

int multiplication(int a, int b){
    return a*b;
}

int isPalindrome(char* nombre){
    for(int i = 0; i < length/2; i++){

        if(nombre[i] != nombre[length-(i+1)]){
            return 0;
        }
    }
    return 1;
}