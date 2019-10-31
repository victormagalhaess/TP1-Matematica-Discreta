//Autor: Victor Hugo Faria Dias Magalhães - 2019055010
//Complexidade: O(n)
#include <stdio.h>
#include <stdlib.h>
  
 void QuadradoMagicoImpar(int tamanho)
 {
     int matrix[tamanho][tamanho];
     int coluna,linha;
     int soma = 0;
  
     coluna = (tamanho-1)/2;
     linha = 0;
  
     matrix[linha][coluna] = 1;
  
     for(int i = 2; i <= tamanho*tamanho; i++)
     {
         if((i-1)%tamanho == 0 )
         {
             linha++;
         }
         else
         {
             linha--;
             linha = (linha+tamanho)%tamanho;
             coluna ++;
             coluna %= tamanho;
        }
        matrix[linha][coluna] = i;
     }

    for(linha = 0;linha <tamanho; linha++)
    {
        soma+=matrix[linha][1];
    }

    printf("n=%d, Soma=%d \n", tamanho, soma);

    for(linha = 0;linha<tamanho; linha++)
     {
         for(coluna = 0;coluna <tamanho; coluna++)
         {
             printf(" %d ",matrix[linha][coluna]);
         }
         printf("\n");
    }
 }

 
void QuadradoMagicoPar4n2(int tamanho)
{
    int matrix[tamanho][tamanho];
    int i,k,temp;
    int coluna,linha;
    int soma = 0;

    k = tamanho / 2;
    coluna = (k-1)/2;
    linha = 0;
    matrix[linha][coluna] = 1;

    for(i = 2; i <= k*k; i++)
    {
        if((i-1)%k == 0 )
        {
            linha++;
        }
        else
        {
            
            linha--;
            linha = (linha+k)%k;
 
            coluna ++;
            coluna %= k;
        }
        matrix[linha][coluna] = i;
    }
 
    for(linha = 0;linha <k; linha++)
    {
        for(coluna = 0;coluna <k; coluna ++)
        {
            matrix[linha+k][coluna+k] = matrix[linha][coluna] + k*k;
            matrix[linha][coluna+k] = matrix[linha][coluna] + 2*k*k;
            matrix[linha+k][coluna] = matrix[linha][coluna] + 3*k*k;
        }
    }
 
    for(linha = 0;linha <k;linha++)
    {
        if(linha == k / 2)
        {
            for(coluna = k / 2; coluna <k - 1; coluna++)
            {
                temp = matrix[linha][coluna];
                matrix[linha][coluna] = matrix[linha + k][coluna];
                matrix[linha + k][coluna] = temp;
            }
        }
        else
        {
            for(coluna = 0;coluna <k / 2;coluna++)
            {
                temp = matrix[linha][coluna];
                matrix[linha][coluna] = matrix[linha + k][coluna];
                matrix[linha + k][coluna] = temp;
            }
        }
    }
 
    for(linha = 0; linha <k;linha++)
    {
        for(i = 0;i <(k - 1)/2 - 1;i++)
        {
            temp = matrix[linha][k+ k/2 - i];
            matrix[linha][k+ k /2 -i] = matrix[linha + k][k+k/2 -i];
            matrix[linha + k][k+k/2 -i] = temp;
        }
    }

    for(linha = 0;linha <tamanho; linha++)
    {
        soma+=matrix[linha][1];
    }

    printf("n=%d, Soma=%d \n", tamanho, soma);

    for(linha = 0;linha <tamanho; linha++)
    {
        for(coluna = 0;coluna <tamanho; coluna ++)
        {
            printf("% d ", matrix[linha][coluna]);
        }
        printf("\n");
    }
}

void QuadradoMagicoPar4n(int tamanho)
 {
     int matrix[tamanho][tamanho];
     int auxVetor[tamanho*tamanho/2];
     int i;
     int coluna, linha;
     int soma = 0;
  
         i = 1;
         for(linha = 0;linha <tamanho; linha++)
         {
             for(coluna = 0;coluna <tamanho; coluna ++)
             {
                 matrix[linha][coluna] = i;
                 i++;
             }
         }

     i = 0;
     for(linha = 0;linha <tamanho; linha++)
     {
         for(coluna = 0;coluna <tamanho; coluna ++)
         {
              if((coluna % 4 == linha % 4) || ( 3 == ( coluna % 4 + linha % 4)))
             {
                 auxVetor[i] = matrix[linha][coluna];
                 i++;
             }
         }
     }
     i = tamanho*tamanho/2 -1;
     for(linha = 0;linha <tamanho; linha++)
     {
         for(coluna = 0;coluna <tamanho; coluna ++)
         {
             if((coluna % 4 == linha % 4) || ( 3 == ( coluna % 4 + linha % 4)))
             {
                 matrix[linha][coluna] = auxVetor[i];
                 i--;
             }
         }
     }

    for(linha = 0;linha <tamanho; linha++)
     {
         soma+=matrix[linha][1];
     }

    printf("n=%d, Soma=%d \n", tamanho, soma);
    
     for(linha = 0;linha <tamanho; linha++)
     {
         soma+=matrix[linha][1];

         for(coluna = 0;coluna <tamanho; coluna ++)
         {
             printf(" %d ",matrix[linha][coluna]);
         }
         printf("\n");
     }
 }


int main(void){
    for (int i = 3; i<=6; i++){
        if (i%2 == 1)
            QuadradoMagicoImpar(i);
        else if (i%4 == 0)
            QuadradoMagicoPar4n(i);
        else
            QuadradoMagicoPar4n2(i);
    }

 }
