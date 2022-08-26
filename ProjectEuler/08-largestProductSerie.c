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
const char milleDigits[1001];

int teteDeLecture;

int serie13[13];

int serieMAX[13];

long result;

int makeINT(char);

int make13Serie();

int oneStepSerie();

int multiply(int *);

//*********************************
//MAIN

int main(){

    make13Serie();

    printf("Le plus grand produit de 13 chiffres dans la série est: \n");
    
    for(int i = 0; i < 12; i++){
    
    	printf("%d * ", serieMAX[i]);
    }
    printf("%d = %ld", serieMAX[12], result);
    

    return 0;
}

//*********************************

const char milleDigits[1001] = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

int teteDeLecture = 0;

int serie13[13] = {};

int serieMAX[13] = {};

long result = 0;

int makeINT(char chiffre){
    // y a de la guerre à faire avec atoi et sscanf. Mais là je veux lire un certain caractère dans une chaine et les pointeurs rendent tout très compliqué.
    //switch case is magic. Le nombre de cas est limité et connu.
    // sorry not sorry ¯\_(ツ)_/¯

    switch(chiffre){
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
    }
}

int make13Serie(){
    //read 13 from teteDeLecture
    //check if '0' a each step
    //if '0', teteDeLEcture ++ et make13serie
    //else, MakeINT et push in serie13 from the right

    if(teteDeLecture > 986){
        return 0;
    }

    static int serieInsertStep = 0;

    for(int i = teteDeLecture; i < teteDeLecture + 12; i++){
        if(milleDigits[i] == '0'){
            teteDeLecture = i + 1;
            serieInsertStep = 0;
            return make13Serie();
        }
        serie13[serieInsertStep] = makeINT(milleDigits[i]);
        serieInsertStep++;
    }
    serieInsertStep = 0;
    teteDeLecture++;
    multiply(serie13);
}

int oneStepSerie(){
    //check if the number on the right == '0'
    //if '0', teteDeLecture++ et make13serie
    //else remove one from the left of the array and add one to the right

    if(teteDeLecture > 999){
        return 0;
    }

    if(milleDigits[teteDeLecture] == '0'){
        teteDeLecture++;
        make13Serie();
    }else{
        for(int i = 0; i < 12; i++){
            serie13[i] = serie13[i+1];
        }
        serie13[12] = makeINT(milleDigits[teteDeLecture]);
        teteDeLecture++;
        multiply(serie13);
    }
}

int multiply(int *nombres){
    //multiplier les nombres de la serie13 entre eux et stocker le résultat si plus grand que précédent

    long resultatBuffer = 1;

    for(int i = 0; i < 13; i++){
        resultatBuffer *= nombres[i];
    }

    if(resultatBuffer > result){
        result = resultatBuffer;

        for(int j = 0; j < 13; j++){
            serieMAX[j] = serie13[j];
        }
    }

    oneStepSerie();
}