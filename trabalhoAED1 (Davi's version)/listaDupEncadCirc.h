//selection sort
//merge sort


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct elemento *Lista;

typedef struct numeros{
    int id;
    int num;
} Numeros;

typedef struct nomes{
    int id;
    char nome[100];
} Nomes;

//Operações com a Lista
Lista* criaLista();
void liberaLista(Lista* licir);
int listaVazia(Lista* licir);
int listaCheia(Lista* licir);
int tamanhoLista(Lista* licir);
int insereIniLista(Lista* licir,void* dado,char tipo);
int removeIniLista(Lista* licir);
void imprimeLista(Lista* licir);

//operações de ordenação
int selectionSortCrescenteNum(Lista* licir,int tam);
int selectionSortDecrescenteNum(Lista* licir);
int selectionSortCrescenteString(Lista *licir);
int selectionSortDecrescenteString(Lista *licir);

int mergeSortNum(Lista* licir, char opcao); // Opção 'c' = crescente; 'd' = decrescente;
int fracionaVetorNumeros(Numeros *vetor, Numeros *vet_aux, int inicio, int fim);
int ordenaNumeros(Numeros *vetor, Numeros *vet_aux, int inicio, int meio, int fim);
int mergeSortString(Lista *licir, char opcao); // Opção 'c' = crescente; 'd' = decrescente;
int ordenaNomes(Nomes *vetor, Nomes *vet_aux, int inicio, int meio, int fim);
int fracionaVetorNomes(Nomes *vetor, Nomes *vet_aux, int inicio, int fim);

//inserir elementos aleatorios na lista
int insereAleatoriosLista(Lista *licir, int quantidadeElem);
int esvaziaLista(Lista *licir);
int lerNomesArquivo(Lista *licir,int tam);