# TP1 da disciplina de matemática discreta UFMG
## Algoritmo Soma Máxima:
  O objetivo desse algoritmo é encontrar o subvetor cuja soma dos elementos seja 
  a máxima possível dentre todos os subvetores possíveis de serem feitos com o vetor de entrada.
  
  **Entrada**: O algoritmo foi projetado para receber dois parâmetros de entrada, um inteiro que contém o tamanho do vetor que será processado, 
  e um vetor de n inteiros, alocado dinâmicamente baseado na primeira entrada com todos os seus itens.
  
  **Saída**: O algoritmo escreve na tela a soma dos itens do subvetor resultante, além dos índices de início e fim do subvetor baseados no
  índice do vetor original. Exemplo:
  
```C
Entrada:
10
31 -41 59 26 -53 58 97 -93 -23 84
```

```C
Saída:
Soma: 187
Índices: 3 a 7
```
  
**Funcionamento**: O algoritmo funciona da seguinte maneira:

* A entrada do tamanho do vetor é fornecida ao algoritmo, que aloca dinâmicamente memória para receber um vetor do tamanho necessário.
* O algoritmo então começa a varrer o vetor de entrada buscando a maior sequência possível. O algoritmo entende como fim de uma maior sequência possível quando a soma da sequência com o próximo item do vetor original < 0;
* Toda vez que o algoritmo encontra o fim da maior sequência até agora (quando a soma máxima + o item atual < 0) Ele altera uma variável
de índice auxiliar (chamada de indiceTeste) para o índice atual+2 (+1 para criar o próximo subvetor e +1 pois os vetores do exemplo do 
TP começavam no índice 1), criando o próximo subvetor de teste, a soma teste é zerada.
* Se a soma de teste for maior que a soma máxima em algum momento, isso significa que um novo subvetor com soma máxima
foi encontrado. Soma máxima passa a valer a soma de teste, o limite inferior se torna o início do subvetor antigo, ou
seja, recebe o índiceTeste e o limite superior se torna o índice atual no vetor.

  
**Complexidade**: O algoritmo utiliza apenas um loop , cuja duração depende exclusivamente da entrada n, logo a complexidade de tempo para o pior caso é O(n).
O algoritmo também utiliza memória proporcional ao tamanho do vetor de entrada, logo a complexidade de espaço é O(n).

## Algoritmo Quadrado Mágico:
**Entrada**: O algoritmo não recebe nenhum parâmetro.
**Saída**: O algoritmo escreve na tela os quadrados mágicos para os números de 3 a 6.
```C
n=3, Soma=15 
 8  1  6 
 3  5  7 
 4  9  2 
n=4, Soma=34 
 16  2  3  13 
 5  11  10  8 
 9   7  6  12 
 4  14  15  1 
n=5, Soma=65 
 17  24  1  8  15 
 23  5  7  14  16 
 4  6  13  20  22 
 10  12  19  21 3 
 11  18  25  2  9 
n=6, Soma=111 
 35  1  6  26  19  24 
 3  32  7  21  23  25 
 31  9  2  22  27  20 
 8  28  33  17  10  15 
 30  5  34  12  14  16 
 4  36  29  13  18  11 
```
**Funcionamento**: O algoritmo funciona da seguinte maneira:

* O algoritmo se baseia nas números do índice dos quadrados mágicos para calculá-los da maneira correta. Existem 3 maneiras de gerar um quadarado 
mágico e elas dependem do valor do lado do quadrado mágico. Existe uma lógica diferente para quadrados de índice ímpar, pares do tipo 4n e pares do tipo 4n+2,
Por exemplo, os números 4 (4n), 5(Ímpar) e 6(4n+2) utilizarão lógicas diferentes.
* Os algoritmos funcionam de maneira similar, posicionando o primeiro número e percorrendo as matrizes utilizando as regras para cada tipo a fim
de preencher o próximo número da matriz.
* Fontes sobre os algoritmos foram encontradas nos links: http://oaji.net/articles/2017/1602-1486725836.pdf & https://www.programering.com/a/MDNyQTMwATA.html


**Complexidade**: O algoritmo contém no máximo dois loops aninhados, cuja duração se baseia na entrada, possuindo duração O(n²). (ironicamente,
mesmo que qualquer parte do algoritmo (ímpar, 4n ou 4n+2) fosse implementado com uma complexidade menor, a ação de escrever a matriz
foi baseada em dois loops aninhados, garantindo a complexidade O(n²)). O algoritmo também utiliza memória baseada numa matriz quadrada de n
lados, possuindo assim complexidade de memória de O(n²).

##Execução
* Ambos os algoritmos foram desenvolvidos e testados utiliando Ubuntu. 
* A versão mínima para execução dos algoritmos da linguagem C é a c99.
* O compilador utilizado para os testes foi o gcc.
* Os comandos para compilação foram:

```bash
gcc qmagico.c -o qmagico
gcc somamax.c -o somamax
```

