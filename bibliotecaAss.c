#include "bibliotecaAss.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Aloca o advogado
Advogado *alocaAdvogado(char *nome){
    Advogado *advogado = (Advogado *)malloc(sizeof(Advogado));
    
    if(advogado == NULL) return NULL;

    advogado->nome = strdup(nome);
    advogado->prox = NULL;

    return advogado;
}

//Aloca o cliente
Cliente *alocaCliente(char *nome, int idade, int numDocs, int cpf, Advogado *advogado, char *arquivo, Cliente *prox){
    Cliente *cliente = (Cliente *)malloc(sizeof(Cliente));

    if(cliente == NULL) return NULL;

    cliente->nome = strdup(nome);
    cliente->idade = idade;
    cliente->numDocs = numDocs;
    cliente->cpf = cpf;
    cliente->advogado = advogado;
    cliente->arquivoTxt = strdup(arquivo);
    cliente->prox = NULL;

    return cliente;
}

//Cria lista de clientes
Cliente *criaListaCliente(){
    Cliente *cabeca = malloc(sizeof(Cliente));

    if(cabeca == NULL) return NULL;

    cabeca->nome = " ";
    cabeca->prox = NULL;

    return cabeca;
}

//Adiciona cliente no fim da lista
void *adicionaCliente(Cliente *cabeca, char *nome, int idade, int numDocs, int cpf, Advogado *advogado, char *arquivo){
   Cliente *ultimo = alocaProduto(nome, idade, numDocs, cpf, advogado, arquivo);
   Cliente *novo = cabeca->prox;

   if(novo == NULL) return NULL;
   while(novo->prox != NULL){
       novo = novo->prox;
   }

   novo->prox = ultimo;
}

//Retira cliente do início da fila
void retiraCliente(Cliente *cabeca){
    Cliente *cliente = cabeca->prox;

    if(cliente == NULL){
        printf("Cliente não encontrado.\n");
        return;
    }

    cabeca->prox = cliente->prox;
    free(cliente);
    cliente = NULL;
}

//Busca um cliente
Cliente *buscaCliente(Cliente *cabeca, int cpf){
    Cliente *cliente = cabeca->prox;

    if(cliente == NULL){
        printf("Cliente não encontrado.\n");
        return NULL;
    }

    while(cliente != NULL){
        if(cliente->cpf == cpf){ 
            return cliente;
        } else {
            cliente = cliente->prox;
        }
    }

    printf("Cliente não encontrado.\n");
    return NULL;
}

//Imprime lista de clientes
void imprimeCliente(Cliente *cabeca){
    Cliente *cliente = cabeca->prox;

    if(cliente == NULL){
        printf("Não há clientes.\n");
        return;
    }

    while(cliente != NULL){
        printf("-> %s\n", cliente->nome);
        cliente = cliente->prox;
    }
}