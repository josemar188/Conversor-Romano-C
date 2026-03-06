#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int positionRoma(char cactRom);

int main() {
    printf("Escreve um numero Romano: ");
    char rom[50];
    scanf("%s", rom);
    int tamNum = strlen(rom);

    char romC[] = {'I','V','X','L','C','D','M'};
    int decC[] = {1,5,10,50,100,500,1000};
    //Verificar se foi introduzido números coretamente
    for (int i = 0; i < tamNum; i++) {
        if (positionRoma(rom[i]) == -1) {
            printf("\nEntrada invalida\n");
            printf("Escreve um numero Romano correto 'I','V','X','L','C','D','M'");
            return 1;
        }
    }    

    for (int i = 0; i< tamNum; i++) {
        int j = rom[i];

        //verificar as repetições das letras como III, XXX, CCC, MMM que não podem repetir mais do que 3 vezes.
        if (j == 'I' || j == 'X' || j == 'C' || j == 'M') {
            if (i+3 < tamNum && rom[i+1] == j && rom[i+2]==j && rom[i+3]==j) {
                printf("Essas letras 'I, X, C, M' nao podem repetir mais do que 3 vezes!!!");
                return 1;
            }
        }
        else if (j == 'V' || j == 'L' || j == 'D') { //verificar essas letras V, L e D que não se repeti.
            if (i+1 < tamNum && j == rom[i+1]) {
                printf("Nao podes repetir 'V, L, D'!!!");
                return 1;
            }
        }
    }

    int totalSom = 0;
    for (int i = 0; i < tamNum; i++) {
        //Fazer soma se o número menor é colocado a direita
        int atual = decC[positionRoma(rom[i])];
        if (i+1 < tamNum) {
            int proximo = decC[positionRoma(rom[i+1])];
        
            if (atual < proximo) {
                totalSom -= atual;
            }
            //Fazer subtração se o número menor é colocado esquerda
            else {
                totalSom += atual;
            }
        }
        else {
            totalSom += atual;
        }
    }
    printf("O numero Romano concertido em decimal e: %d", totalSom);
    return 0;
}

//Função que retorna a posição do caracter nesse array {I,V,X,L,C,D,M}
int positionRoma(char cactRom) {
    char roman[] ={'I','V','X','L','C','D','M'};
    for (int i = 0; i<7; i++) {
        if(roman[i] == cactRom) return i;
    }
    return -1;
}