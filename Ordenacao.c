
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "Ordenacao.h"
#define RUN 32

//Função para gerar numeros aleatórios
int geraAleatorios(char *nomeArquivo, int qtd){ 
  FILE *arq;
  arq = fopen(nomeArquivo, "w");

  if(arq==NULL){
    return 1;
  }else

  for(int i=0; i<qtd; i++){
    fprintf(arq, "%d " , rand() % 1000000);
  }

  fclose(arq);
  
  return 0;
};
//Função para imprimir o vetor ordenado no arquivo
int printaArquivo(char *nomeArquivo, int qtd,int *Numeros){
  FILE *arq;
  arq = fopen(nomeArquivo, "w");

  if(arq==NULL){
    return 1;
  }else

  for (int i=0;i<qtd;i++){
    fprintf(arq, "%d ",Numeros[i]);
  }
  fclose(arq);
    return 0;
};


//Adiciona os valores do arquivo no vetor
int* leArquivo(char *nomeArquivo, int qtd){
 int *num;

  num = (int*) malloc(qtd * sizeof(int));

  //abrir arquivo para a leitura
  FILE *arquivo = fopen(nomeArquivo,"r");
  
  if(arquivo == NULL){
    return NULL;
  }
  
  for(int i=0; i<qtd;i++){
    fscanf(arquivo,"%d ", &num[i]);
  }
  
  
  //fechar arquivo
  fclose(arquivo);
     
return num;
  
};


//Método da inserção
void insercao(int *vet, int inicio, int fim,unsigned long long int *comparacoes,unsigned long long int *trocas){

    for (int i = inicio + 1; i <= fim; i++){
        (*comparacoes)++;
        int temp = vet[i];
        int j = i - 1;
        while(j>=inicio && vet[j]>temp){
            vet[j+1] = vet[j];
            j--;
          (*trocas)++;
        }
        vet[j+1] = temp;
    }
};

//Função para imprimir vetor
void imprimeVet(int *vet, int tam){
	for(int i=0; i < tam; i++){
    printf("%d ", vet[i]);
  }
  printf("\n");
};


//Método Merge
void merge(int *vet, int inicio, int meio, int fim, unsigned long long int *comparacoes,unsigned long long int *trocas){
  int V1=inicio,V2=meio+1,k=0;
  int VetAux[(fim-inicio)+1];
  while(V1 <= meio && V2 <= fim){
      (*comparacoes)++;
    if(vet[V1] <= vet[V2]){
      VetAux[k] = vet[V1];
      V1++;
    
    }
    else{
      VetAux[k] = vet[V2] ;
      V2++;
    }
    k++;
  }
  while(V1<=meio){
    VetAux[k] = vet[V1];
    V1++;
    k++;
  }
  while(V2<=fim){
    VetAux[k]= vet[V2];
    V2++;
    k++;
  }
  k=0;
  for(V1=inicio; V1<=fim; V1++){
    vet[V1]=VetAux[k];
    k++;
    (*trocas)++;
  }
};


//Função para gerar os numeros decrecentes
int geraDecrescente(char *nomeArquivo, int qtd){

    FILE *arq;
    arq = fopen(nomeArquivo, "w");

    if(arq==NULL){
        return 1;
    }else

        for(int i=qtd; i>=0; i--){
            fprintf(arq, "%d\n" , i);
        }

    fclose(arq);

    return 0;
};


//Função para gerar numeros ordenados
int geraOrdenado(char *nomeArquivo,int qtd){
    FILE *arq;
    arq = fopen(nomeArquivo, "w");

    if(arq==NULL){
        return 1;
    }else

        for(int i=0;i<qtd;i++){
            fprintf(arq, "%d\n" , i);
        }

    fclose(arq);

    return 0;
};


//MétodoMergeSort
void mergeSort(int *vet, int inicio, int fim,unsigned long long int *comparacoes,unsigned long long int *trocas){
  int meio;
  if(inicio < fim){
    meio = ((inicio+fim)/2);
    mergeSort(vet,inicio,meio,comparacoes,trocas);
    mergeSort(vet,meio+1,fim,comparacoes,trocas);
    merge(vet,inicio,meio,fim,comparacoes,trocas);
  }
};

//Função auxiliar do Quicksort
int particiona(int *vet, int inicio, int fim,unsigned long long int *comparacoes,unsigned long long int *trocas){
  int pivo,pos,Auxiliar;
  pivo = vet[inicio];
  pos=inicio;
    for(int i=inicio;i<=fim;i++){
        (*comparacoes)++;
        if(vet[i]<pivo) {
            pos=pos+1;
            if (i != pos){
            Auxiliar = vet[pos];
            vet[pos]=vet[i];
            vet[i]=Auxiliar;
            (*trocas)++;
            }
        }
    }
    (*trocas)++;
    Auxiliar=vet[inicio];
    vet[inicio]=vet[pos];
    vet[pos]=Auxiliar;
    return pos;
};

int min(int a, int b){
    if( a>b){
        return b;
    }else{
        return a;
    }
}

//Método quickSort
void quickSort(int *vet, int inicio, int fim,unsigned long long int *comparacoes,unsigned long long int *trocas){
  int pivo;
  if(inicio < fim){
    pivo = particiona(vet,inicio,fim,comparacoes,trocas);
    quickSort(vet,inicio,pivo-1,comparacoes,trocas);
    quickSort(vet,pivo+1,fim,comparacoes,trocas);
  }
};
//Método TimSort
void timsort(int *vet, int n,unsigned long long int *comparacoes,unsigned long long int *trocas){

    for (int i = 0; i < n; i+=RUN){
        insercao(vet, i, min((i+RUN-1),(n-1)),comparacoes,trocas);
    }
    for (int tam = RUN; tam < n; tam = 2*tam){
        for (int inicio = 0; inicio < n; inicio += 2*tam){
            int meio = inicio + tam - 1;
            int fim = min((inicio + 2*tam - 1),(n-1));
            if(meio < fim){
                merge(vet, inicio, meio, fim,comparacoes,trocas);
            }
        }
    }
};