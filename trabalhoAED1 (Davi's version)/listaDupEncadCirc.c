#include "listaDupEncadCirc.h"

struct elemento{
    Numeros dadoNum;
    Nomes dadoNome;
    struct elemento *prox;
    struct elemento *ant;
};

typedef struct elemento Elem;

Lista *criaLista(){
    Lista* licir = (Lista*)malloc(sizeof(Lista));
    if(licir == NULL){ 
        printf("Erro ao criar Lista,encerrando programa.\n");
        exit(1);
    }
    *licir = NULL;
    return licir;
}

void liberaLista(Lista *licir){
    if(licir != NULL && (*licir) != NULL){
        Elem *aux,*no = *licir;
        while((*licir) != no->prox){
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(no);
        free(licir);
    }
}

int listaVazia(Lista *licir){
    if(licir == NULL){
        printf("A Lista não existe.\n");
        return 1;
    }
    if((*licir) == NULL){
        printf("A Lista esta vazia.\n");
        return 1;
    }
    return 0;
}

int listaCheia(Lista *licir){
    if(licir == NULL){
        printf("A Lista não existe.\n");
        return 0;
    }
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        printf("A Lista esta cheia.\n");
        return 1;
    }
    free(no);
    return 0;
}

int tamanhoLista(Lista *licir){
    if(licir == NULL || (*licir) == NULL) return 0;
    Elem *no = *licir;
    int count = 0;
    do{
        count ++;
        no = no->prox;
    }while(no != (*licir)); 
    return count;
}

int insereIniLista(Lista *licir, void *dado, char tipo){
    if(licir == NULL){
        printf("A Lista não existe.\n");
        return 0;
    }
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        printf("Erro ao criar no.\n");
        return 0;
    }
    //iniciaListaVazia(no);
    no->dadoNome.id = 0;
    strcpy(no->dadoNome.nome, "\0");
    no->dadoNum.id = 0;
    no->dadoNum.num = 0;
    switch (tipo) {
    case 'i': 
        no->dadoNum = *(Numeros*)dado;
        break;

    case 'n':
        no->dadoNome = *(Nomes*)dado;
        break;
    default:
        printf("Opção de dado não existe, excluindo o no, tente novamente.\n");
        free(no);
        return 0;
    }
    if((*licir)==NULL){
        *licir = no;
        no->prox = no;
        no->ant = no;
    }
    else{
        Elem *aux = *licir;
        Elem *ultimo = (*licir)->ant; 
        no->prox = *licir;
        no->ant = ultimo;
        ultimo->prox = no;
        (*licir)->ant = no;
        *licir = no; 
    }
    return 1;
}

int removeIniLista(Lista *licir){
    if(licir == NULL){
        printf("A Lista não existe.\n");
        return 0;
    }
    if((*licir) == NULL){
        printf("A Lista esta vazia.\n");
        return 0;
    }

     Elem *no = *licir;
    if (no->prox == no) {
        free(no);
        *licir = NULL;
    } else {
        Elem *ultimo = no->ant; 
        *licir = no->prox;      
        (*licir)->ant = ultimo;
        ultimo->prox = *licir;
        free(no);
    }

    return 1;
}

void imprimeLista(Lista *licir){
    if(licir == NULL){
        printf("A Lista não existe.\n");
        return ;
    }
    if((*licir) == NULL){
        printf("A Lista esta vazia.\n");
        return ;
    }

    printf("A lista possui %d nos.\n\n",tamanhoLista(licir));
    Elem *no = *licir;
    //int ind = 1;
    do{
        //printf("no numero %d:\n",ind);
        if(no->dadoNum.num != 0)
            printf("Valor %d\n",no->dadoNum.num);
        if(strlen(no->dadoNome.nome) != 0)
            printf("Nome: %s\n",no->dadoNome.nome);
        //ind++;
        no = no->prox;
    }while(no != (*licir));
}





int selectionSortCrescenteNum(Lista *licir, int tam){
    if(licir == NULL){
        printf("A Lista não existe.\n");
        return 0;
    }
    if((*licir) == NULL){
        printf("A Lista esta vazia.\n");
        return 0;
    }

    Elem *aux = (*licir),*aux2,*menorNo;
    int n_trocas = 0;

    for(int i = 0; i < (tam - 1);i++){
        aux2 = aux->prox;
        menorNo = aux;
        while(aux2 != (*licir)){
            if(aux2->dadoNum.num < menorNo->dadoNum.num){
                menorNo = aux2;
            }
            aux2 = aux2->prox;
        }
        if(aux != menorNo){
            Numeros temporario = aux->dadoNum;
            aux->dadoNum = menorNo->dadoNum;
            menorNo->dadoNum = temporario;
            n_trocas++;
        }
        aux = aux->prox;
    }

    printf("Numero de trocas %d\n", n_trocas);

    return 1;
}

int selectionSortDecrescenteNum(Lista *licir){
    if(licir == NULL){
        printf("A Lista não existe.\n");
        return 0;
    }
    if((*licir) == NULL){
        printf("A Lista esta vazia.\n");
        return 0;
    }

    Elem *aux = (*licir),*aux2,*maiorNo;
    int n_trocas = 0;

    do{
        aux2 = aux->prox;
        maiorNo = aux;
        while(aux2 != (*licir)){
            if((aux2->dadoNum.num > maiorNo->dadoNum.num)/*&&(strlen(aux2->dadoNome.nome) != 0)*/){
                maiorNo = aux2;
            }
            aux2 = aux2->prox;
        }
        if(maiorNo->dadoNum.num != aux->dadoNum.num){
            Numeros temporario = aux->dadoNum;
            aux->dadoNum = maiorNo->dadoNum;
            maiorNo->dadoNum = temporario;
            n_trocas++;
        }
        aux = aux->prox;
        
    }while(aux->prox != (*licir));

    printf("Numero de trocas %d\n", n_trocas);

    return 1;
}

int selectionSortCrescenteString(Lista *licir){
    if(licir == NULL){
        printf("A Lista não existe.\n");
        return 0;
    }
    if((*licir) == NULL){
        printf("A Lista esta vazia.\n");
        return 0;
    }

    Elem *aux = (*licir), *aux2, *menorNo;
    int n_trocas = 0;
    do
    {
        aux2 = aux->prox;
        menorNo = aux;
        while (aux2 != (*licir))
        {
            if (strcmp(aux2->dadoNome.nome,menorNo->dadoNome.nome) <= 0)
            {
                menorNo = aux2;
            }
            aux2 = aux2->prox;
        }
        if (strcmp(menorNo->dadoNome.nome,aux->dadoNome.nome) != 0)
        {
            Nomes temporario = aux->dadoNome;
            aux->dadoNome = menorNo->dadoNome;
            menorNo->dadoNome = temporario;
            n_trocas++;
        }
        aux = aux->prox;
    }while (aux->prox != (*licir));

    printf("Numero de trocas %d\n", n_trocas);

    return 1;
}

int selectionSortDecrescenteString(Lista *licir){
    if(licir == NULL){
        printf("A Lista não existe.\n");
        return 0;
    }
    if((*licir) == NULL){
        printf("A Lista esta vazia.\n");
        return 0;
    }

    Elem *aux = (*licir), *aux2, *maiorNo;
    int n_trocas = 0;

    do
    {
        aux2 = aux->prox;
        maiorNo = aux;
        while (aux2 != (*licir))
        {
            if (strcmp(aux2->dadoNome.nome,maiorNo->dadoNome.nome) > 0)
            {
                maiorNo = aux2;
            }
            aux2 = aux2->prox;
        }
        if (strcmp(maiorNo->dadoNome.nome,aux->dadoNome.nome) != 0)
        {
            Nomes temporario = aux->dadoNome;
            aux->dadoNome = maiorNo->dadoNome;
            maiorNo->dadoNome = temporario;
            n_trocas++;
        }
        aux = aux->prox;
    }while (aux->prox != (*licir));

    printf("Numero de trocas %d\n", n_trocas);

    return 1;
}

/*void iniciaListaVazia(Elem *vazio){
    if(vazio == NULL){
        printf("Elemento não criado.\n");
        return ;
    }
    vazio->dadoNome.id = 0;
    strcpy(vazio->dadoNome.nome, "\0");
    vazio->dadoNum.id = 0;
    vazio->dadoNum.num = 0;

    isso é de outra função
    if(strlen(aux->dadoNome.nome) != 0){
            aux = aux->prox;
        }
}*/

int mergeSortNum(Lista* licir, char opcao){
    if(licir == NULL){
        printf("A Lista não existe.\n");
        return 0;
    }
    if((*licir) == NULL){
        printf("A Lista esta vazia.\n");
        return 0;
    }

    int trocas = 0;

    // consegui com vetorização, primeiro eu extraio a lista e transformo em um vetor
    Numeros *vetor, *vet_aux;
    int tamanho_vetor = tamanhoLista(licir);
    vetor = (Numeros*) malloc(tamanho_vetor*sizeof(Numeros));
    vet_aux = (Numeros*) malloc(tamanho_vetor*sizeof(Numeros));
    Elem *atual = (*licir);

    for (int i = 0; i < tamanho_vetor; i++)
    {
        vetor[i] = atual->dadoNum;
        atual = atual->prox;
        removeIniLista(licir);
    }

    trocas = fracionaVetorNumeros(vetor,vet_aux,0,tamanho_vetor-1);

    printf("Numeros de trocas %d\n",trocas);

    // Devolve os valores para a Lista
    switch (opcao)
    {
    case 'c':
        for (int i = tamanho_vetor - 1; i >= 0; i--)
        {
            insereIniLista(licir, &vetor[i], 'i');
        }
        return 1;
        break;
    case 'd':
        for (size_t i = 0; i < tamanho_vetor; i++)
        {
            insereIniLista(licir, &vetor[i], 'i');
        }
        return 1;
        break;
    default:
        printf("Opção Inválida.\n");
        return 0;
        break;
    }
    free(vetor);
    free(vet_aux);
    return 1;
}

// Função que fraciona o vetor em vetores menores
int fracionaVetorNumeros(Numeros *vetor, Numeros *vet_aux, int inicio, int fim){
    if (inicio < fim)
    {
        int meio = (inicio + fim)/2;
        fracionaVetorNumeros(vetor,vet_aux,inicio,meio);
        fracionaVetorNumeros(vetor,vet_aux,meio+1,fim);


        return ordenaNumeros(vetor, vet_aux, inicio, meio+1, fim);
    }
    return 0;
}

// Função que ordena os vetores
int ordenaNumeros(Numeros *vetor, Numeros *vet_aux, int inicio, int meio, int fim){
    int trocas = 0;
    int metade = meio - 1;
    int indice_pricipal = inicio;
    int tamanho_vetor = fim - inicio + 1;
    while (inicio <= metade && meio <= fim)
    {
        if (vetor[inicio].num <= vetor[meio].num)
        {
            vet_aux[indice_pricipal] = vetor[inicio];
            inicio++;
        }
        else
        {
            vet_aux[indice_pricipal] = vetor[meio];
            meio++;
        }
        trocas++;
        indice_pricipal++;
    }
    
    // Caso acabe os termos da segunda metade do vetor e ainda sobraram termos da primeira
    if (inicio <= metade && meio > fim)
    {
        while (inicio <= metade)
        {
            vet_aux[indice_pricipal] = vetor[inicio];
            inicio++;
            indice_pricipal++;
        }
    }
    // Caso acabe os termos da primeira metade do vetor e ainda sobraram termos da primeira
    if (meio <= fim && inicio > metade)
    {
        while (meio <= fim)
        {
            vet_aux[indice_pricipal] = vetor[meio];
            meio++;
            indice_pricipal++;
        }
    }
    for (int i = 0; i < tamanho_vetor; i++)
    {
        vetor[fim] = vet_aux[fim];
        fim--;
    }
    return trocas;
}

int ordenaNomes(Nomes *vetor, Nomes *vet_aux, int inicio, int meio, int fim){
    int trocas = 0;
    int metade = meio -1;
    int indice_principal = inicio;
    int tamanho_vetor = fim - inicio + 1;

    while (inicio <= metade && meio <= fim)
    {
        if (strcmp(vetor[inicio].nome,vetor[meio].nome) <= 0)
        {
            vet_aux[indice_principal] = vetor[inicio];
            inicio++;
        }
        else
        {
            vet_aux[indice_principal] = vetor[meio];
            meio++;
        }
        trocas++;
        indice_principal++;
    }
    
    while (inicio <= metade)
    {
        vet_aux[indice_principal] = vetor[inicio];
        inicio++;
        indice_principal++;
    }
    
    while (meio <= fim)
    {
        vet_aux[indice_principal] = vetor[meio];
        meio++;
        indice_principal++;
    }

    for (int i = 0; i < tamanho_vetor; i++)
    {
        vetor[fim] = vet_aux[fim];
        fim--;
    }
    return trocas;
}

int fracionaVetorNomes(Nomes *vetor, Nomes *vet_aux, int inicio, int fim){
    if (inicio < fim)
    {
        int meio = (inicio + fim)/2;

        fracionaVetorNomes(vetor,vet_aux,inicio,meio);
        fracionaVetorNomes(vetor,vet_aux,meio+1,fim);

        return ordenaNomes(vetor,vet_aux,inicio,meio+1,fim);
    }
    return 0;
}

// Merge sorte de nomes com opção de ordenar crescente ('c') ou decrescente ('d').
int mergeSortString(Lista *licir, char opcao){
    if(licir == NULL){
        printf("A Lista não existe.\n");
        return 0;
    }
    if((*licir) == NULL){
        printf("A Lista esta vazia.\n");
        return 0;
    }

    int trocas = 0;

    Nomes *vetor, *vet_aux;
    int tamanho_vetor = tamanhoLista(licir);
    vetor = (Nomes*) malloc(tamanho_vetor*sizeof(Nomes));
    vet_aux = (Nomes*) malloc(tamanho_vetor*sizeof(Nomes));
    Elem *atual = (*licir);

    for (int i = 0; i < tamanho_vetor; i++)
    {
        vetor[i] = atual->dadoNome;
        atual = atual->prox;
        removeIniLista(licir);
    }
    
    trocas = fracionaVetorNomes(vetor,vet_aux,0,tamanho_vetor-1);

    printf("Numeros de trocas %d\n",trocas);
    
    switch (opcao)
    {
    case 'c':
        for (int i = tamanho_vetor - 1; i >= 0 ; i--)
        {
            insereIniLista(licir, &vetor[i], 'n');
        }
        return 1;
        break;
    case 'd':
        for (int i = 0; i < tamanho_vetor; i++)
        {
            insereIniLista(licir, &vetor[i], 'n');
        }
        return 1;
        break;
    default:
        printf("Opção inválida.\n");
        return 0;
        break;
    }
    free(vetor);
    free(vet_aux);
    return 1;
}

int insereAleatoriosLista(Lista *licir, int quantidadeElem){
    if(licir == NULL){
        printf("A Lista não existe.\n");
        return 0;
    }

    Numeros *num;
    num = (Numeros*)malloc(quantidadeElem*sizeof(Numeros));
    for (int i = 0; i < quantidadeElem; i++)
    {
        num[i].id = i+1;
        num[i].num = rand()%1000;
        if (!insereIniLista(licir,&num[i],'i'))
        {
            printf("Erro ao colocar na Lista.\n");
        }
        
    }
    free(num);
    return 1;
}

int esvaziaLista(Lista *licir){
    while ((*licir) != NULL)
    {
        removeIniLista(licir);
    }
    return 1;
}


// função para ler os nomes de um arquivo e inserir na lista
int lerNomesArquivo(Lista *licir, int tam){
    if(licir == NULL){
        printf("A Lista não existe.\n");
        return 0;
    }

    FILE *arquivoNomes;
    arquivoNomes = fopen("nomes_aleatorios.txt", "r");
    Nomes *name;
    int i = 0;

    if (arquivoNomes == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    // Aloca espaço para os nomes
    name = (Nomes*)malloc(tam * sizeof(Nomes));
    if (name == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(arquivoNomes);
        return 0;
    }

    // Lê os nomes do arquivo
    for (i = 0; i < tam; i++) {
        if (fscanf(arquivoNomes, "%s", name[i].nome) != 1) {
            printf("Erro ao ler nome da linha %d.\n", i + 1);
            break;
        }
        name[i].id = i + 1;  // Atribui um id sequencial para cada nome
        if (!insereIniLista(licir, &name[i], 'n')) {
            printf("Erro ao inserir nome na lista.\n");
            free(name);
            fclose(arquivoNomes);
            return 0;
        }
    }

    free(name);
    fclose(arquivoNomes);
    return 1;
}
