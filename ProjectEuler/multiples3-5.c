#include <stdio.h>

/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.

Un peu bruteforce: On cherche les multiples "un par un" sachant que ça fait forcément 333 itérations (3  * 333 = 999). 5 * 200 = 1000, mais on veut rester strictement inférieur à 1000. Donc une boucle qui multiplie 3 par 1-333 et 5 aussi, mais seulement jusqu'à 199, après ça stop de compter pour 5.
Au total on a quand-même dans les 500 opérations.
ça a l'avantage d'être vite écrit.
*/

int result = 0;

int main(){

    for(int i = 1; i <=333; i++){
        if(i < 200){

            result += 5*i;

        }

        result += i * 3;
    }

    printf("The sum of all the multiples of 3 and 5 below 1000 is: %i", result);

    return 0;
}