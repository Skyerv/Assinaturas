#define bibliotecaAss_h

typedef struct advogado{
    char *nome;
    struct Advogado *prox;
} Advogado;

typedef struct cliente{
    char *nome;
    int idade;
    int numDocs;
    int cpf;
    struct Advogado *advogado;
    char *arquivoTxt;
    struct Cliente *prox;
} Cliente;

Advogado *alocaAdvogado(nome);
Cliente *alocaCliente(nome, idade, numDocs, cpf, advogado, arquivo);
Cliente *criaListaCliente();
void *adicionaCliente(nome, idade, numDocs, cpf, advogado, arquivo);
void retiraCliente(cabeca);
Cliente *buscaCliente(cabeca, cpf);
void imprimeLista(cabeca);
//void *insereInicio(cabeca, nome1, preco1, id1);
//void retiraFinal(cabeca);