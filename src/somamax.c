//Autor: Victor Hugo Faria Dias Magalhães 2019055010
//Complexidade linear, O(n)

#include <stdio.h>
#include <stdlib.h>

/* 
1 - Toda vez que o algoritmo encontra o fim da maior sequência até agora (quando a soma máxima + o item atual < 0)
Ele altera o indiceTeste para o índice atual+2 (+1 para criar o próximo subvetor e +1 pois os vetores do exemplo do 
TP começavam no índice 1), criando o próximo subvetor de teste, a soma teste é zerada.

2 - Quando a soma máxima + o item atual > 0 o algoritmo acrescenta à soma teste o valor atual do vetor.

3 - Se a soma de teste for maior que a soma máxima em algum momento, isso significa que um novo subvetor com soma máxima
foi encontrado. Soma máxima passa a valer a soma de teste, o limite inferior se torna o início do subvetor antigo, ou
seja, recebe o índiceTeste e o limite superior se torna o índice atual no vetor.
*/


void processaVetor(int *vetor, int tamanhoVetor){

    int valorMax = 0;
    int somaAux = 0;
    int indiceTeste = 1;
    int limiteInf = 0;
    int limiteSup = 0;


    for (int i=0; i<tamanhoVetor; i++){ 

        if ((valorMax+vetor[i])<0){
            indiceTeste = (i+1)+1;  //+1 devido aos vetores do exemplo do TP começarem na casa 1
            somaAux = 0;
        }

        else{
            somaAux+=vetor[i];
        }

        if (somaAux>valorMax){
            valorMax = somaAux;
            limiteInf = indiceTeste;  //+1 devido aos vetores do exemplo do TP começarem na casa 1
            limiteSup = i+1;                
        }

    }
    printf("Soma: %d\nÍndices: %d à %d", valorMax, limiteInf, limiteSup);
}

int main(void){
    int tamanhoVetor;
    int *vetor;
    scanf("%d", &tamanhoVetor);
    vetor = (int*) malloc(tamanhoVetor*sizeof(int));
    for (int i=0; i<tamanhoVetor; i++){
        scanf("%d", &(vetor[i]));
    }
    processaVetor(vetor, tamanhoVetor);
    free(vetor);
    return 0;
}