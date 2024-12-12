

#include "listaDupEncadCirc.h"
#include <time.h> // Biblioteca para medir o tempo de execução

int main() {
    Lista* point = criaLista();
    Lista* nomes = criaLista(); // Lista separada para nomes, já comentada no código
    int quantidadeElem,quantidadeNomes;
    
    printf("Digite a quantidade de Numeros de entrada\n");
    scanf("%d",&quantidadeElem);
    insereAleatoriosLista(point,quantidadeElem);

    clock_t inicio, fim;
    double tempo_execucao;


    printf("-------------Teste Selection Sort--------------\n");
    printf("\nSelection sort com entrada Aleatoria Ordenando Crescente com N = %d:\n",quantidadeElem);

    // Medir tempo de execução para Selection Sort crescente (números) com entrada aleatoria
    inicio = clock();
    int tamanho = tamanhoLista(point);
    selectionSortCrescenteNum(point, tamanho);
    fim = clock();

    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Selection Sort Crescente: %.6f segundos\n", tempo_execucao);
    printf("Com entrada Aleatoria.\n");

    printf("\nSelection sort com entrada Ordenada Crescente Ordenando Crescente com N = %d:\n",quantidadeElem);

    // Medir tempo de execução para Selection Sort crescente (números) com entrada ordenada crescente
    inicio = clock();
    tamanho = tamanhoLista(point);
    selectionSortCrescenteNum(point, tamanho);
    fim = clock();

    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Selection Sort Crescente: %.6f segundos\n", tempo_execucao);
    printf("Com entrada Ordenada Crescente.\n");

    printf("\nSelection sort com entrada Crescente Ordenando Decrescente com N = %d:\n",quantidadeElem);

    // Medir tempo de execução para Selection Sort decrescente (números) com entrada ordenada crescente
    inicio = clock();
    tamanho = tamanhoLista(point);
    selectionSortDecrescenteNum(point);
    fim = clock();

    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Selection Sort Decrescente: %.6f segundos\n", tempo_execucao);
    printf("Com entrada Ordenada Crescente.\n");

    esvaziaLista(point);


    printf("-------------Teste Merge Sort--------------\n");

    insereAleatoriosLista(point,quantidadeElem);
    
    printf("\nMerge sort com entrada Aleatoria Ordenando Crescente com N = %d:\n",quantidadeElem);
    
    // Medir tempo de execução para Merge Sort crescente (números) Com dados Aleatorios
    inicio = clock();
    mergeSortNum(point, 'c');
    fim = clock();

    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Merge Sort Crescente: %.6f segundos\n", tempo_execucao);
    printf("Com entrada de dados Aleatorios.\n");

    printf("\nMerge sort com entrada Ordenada Crescente Ordenando Crescente com N = %d:\n",quantidadeElem);
    
    // Medir tempo de execução para Merge Sort crescente (números) com dados Ordenados Crescente
    inicio = clock();
    mergeSortNum(point, 'c');
    fim = clock();

    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Merge Sort Crescente: %.6f segundos\n", tempo_execucao);
    printf("Com entrada de dados Ordenados Crescente.\n");

    printf("\nMerge sort com entrada Ordenada Crescente Ordenando Decrescente com N = %d:\n",quantidadeElem);
    
    // Medir tempo de execução para Merge Sort Decrescente (números) com dados Ordenados Crescente
    inicio = clock();
    mergeSortNum(point, 'd');
    fim = clock();

    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Merge Sort Decrescente: %.6f segundos\n", tempo_execucao);
    printf("Com entrada de dados Ordenados Crescente.\n");


    esvaziaLista(point);
    
    printf("Digite um N menor que 1000000\n");
    scanf("%d",&quantidadeNomes);
    lerNomesArquivo(nomes,quantidadeNomes);

    
    printf("\n-------------Teste Selection Sort Com Nomes--------------\n");
    printf("\nSelection sort com entrada N = %d Nomes Ordenando Crescente\n",quantidadeNomes);

    // Medir tempo de execução para Selection Sort crescente (nomes) com entrada aleatoria
    inicio = clock();
    selectionSortCrescenteString(nomes);
    fim = clock();
    
    
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Selection Sort Crescente com Nomes: %.6f segundos\n", tempo_execucao);
    printf("Com entrada Aleatoria.\n");

    esvaziaLista(nomes);
    lerNomesArquivo(nomes,quantidadeElem);

    printf("\nSelection sort com entrada N = %d Nomes Ordenando Decrescente\n",quantidadeNomes);

    // Medir tempo de execução para Selection Sort crescente (nomes) com entrada aleatoria
    inicio = clock();
    selectionSortDecrescenteString(nomes);
    fim = clock();
    
    
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Selection Sort Decrescente com Nomes: %.6f segundos\n", tempo_execucao);
    printf("Com entrada Aleatoria.\n");

    esvaziaLista(nomes);


    printf("\n-------------Teste Merge Sort Com Nomes--------------\n");

    lerNomesArquivo(nomes,quantidadeElem);
    
    printf("\nMerge sort com N = %d Nomes e Ordenando Crescente\n",quantidadeElem);
    
    // Medir tempo de execução para Merge Sort crescente (Nomes) com entrada de dados Aleatorias
    inicio = clock();
    mergeSortString(nomes, 'c');
    fim = clock();

    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Merge Sort Crescente com Nomes: %.6f segundos\n", tempo_execucao);
    printf("Com entrada de dados Aleatorios.\n");

    esvaziaLista(nomes);
    lerNomesArquivo(nomes,quantidadeElem);
    printf("\nMerge sort com N = %d Nomes Ordenando Decrescente\n",quantidadeElem);
    
    // Medir tempo de execução para Merge Sort Decrescente (Nomes) com entrada de dados Aleatorias
    inicio = clock();
    mergeSortString(nomes, 'd');
    fim = clock();

    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Merge Sort Decrescente com Nomes: %.6f segundos\n", tempo_execucao);
    printf("Com entrada de dados Aleatoria.\n");

    liberaLista(point);
    liberaLista(nomes);

    return 0;
}


