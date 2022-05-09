int geraAleatorios(char *nomeArquivo, int qtd);

int printaArquivo(char *nomeArquivo, int qtd,int *Numeros);

int* leArquivo(char *nomeArquivo, int qtd);

void insercao(int *vet, int inicio, int fim,unsigned long long int *comparacoes,unsigned long long int *trocas);

void imprimeVet(int *vet, int tam);

void merge(int *vet, int inicio, int meio, int fim, unsigned long long int *comparacoes,unsigned long long int *trocas);

int geraDecrescente(char *nomeArquivo, int qtd);

int geraOrdenado(char *nomeArquivo,int qtd);

void mergeSort(int *vet, int inicio, int fim,unsigned long long int *comparacoes,unsigned long long int *trocas);

int particiona(int *vet, int inicio, int fim,unsigned long long int *comparacoes,unsigned long long int *trocas);

int min(int a, int b);

void quickSort(int *vet, int inicio, int fim,unsigned long long int *comparacoes,unsigned long long int *trocas);

void timsort(int *vet, int n,unsigned long long int *comparacoes,unsigned long long int *trocas);