#include "Ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(void) {
  int *vetor,tamanho;
  unsigned long long int *comparacoes=0, *trocas=0;
  clock_t Ticks[2];
  double Tempo;
  printf("Digite a quantidade de numero:  ");
  scanf("%d",&tamanho);
  geraAleatorios("nomeArquivo",tamanho);
  //geraDecrescente("nomeArquivo",tamanho);
  //geraOrdenado("nomeArquivo",tamanho);

    //Adiciona ao vetor os numeros do arquivo  
    vetor = leArquivo("nomeArquivo", tamanho);
    //Calculo de tempo
    Ticks[0] = clock();
    mergeSort(vetor,0,tamanho,&comparacoes,&trocas);
    Ticks[1] = clock();
    Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto com o MergeSort: %g ms.\n", Tempo);
    printf("O numero de comparacoes e: %llu\n", comparacoes);
    printf("O numero de trocas e: %llu\n\n", trocas);
    printaArquivo("OrdenadoMergeSort",tamanho,vetor);
    free(vetor);
    comparacoes=0;
    trocas=0;

    vetor = leArquivo("nomeArquivo", tamanho);
    Ticks[0] = clock();
    quickSort(vetor,0,tamanho,&comparacoes,&trocas);
    Ticks[1] = clock();
    Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto com QuickSort: %g ms.\n", Tempo);
    printf("O numero de comparacoes e: %llu\n", comparacoes);
    printf("O numero de trocas e: %llu\n\n", trocas);
    printaArquivo("OrdenadoQuickSort",tamanho,vetor);
    free(vetor);
    comparacoes=0;
    trocas=0;

    vetor = leArquivo("nomeArquivo", tamanho);
    Ticks[0] = clock();
    timsort(vetor,tamanho,&comparacoes,&trocas);
    Ticks[1] = clock();
    Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto com TimSort: %g ms.\n", Tempo);
    printf("O numero de comparacoes e: %llu\n",comparacoes);
    printf("O numero de trocas e: %llu\n\n", trocas);
    printaArquivo("OrdenadoTimSort",tamanho,vetor);
    free(vetor);
    comparacoes=0;
    trocas=0;

    vetor = leArquivo("nomeArquivo", tamanho);
    Ticks[0] = clock();
    insercao(vetor,0,tamanho,&comparacoes,&trocas);
    Ticks[1] = clock();
    Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo gasto com Insercao: %g ms.\n", Tempo);
    printf("O numero de comparacoes e: %llu\n", comparacoes);
    printf("O numero de trocas e: %llu\n\n", trocas);
    printaArquivo("OrdenadoInserção",tamanho,vetor);
    free(vetor);



  //timSort(vetor,10);
  //insercao(vetor,10);
  //quickSort(vetor,0,10);
  //mergeSort(vetor,0,10);
  return 0;
}
