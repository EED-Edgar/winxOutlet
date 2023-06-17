#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

FILE *arq;

struct Cliente{
    char nome[50];
    char endereco[300];
    char email[100];
    char cpf[11];
};

struct Tenis {
    char marca[50];
    int tamanho;
    int codigo;
    char cor[50];
    char modelo[50];
    int quantidadeEstoque;
};

struct Venda {
    struct Cliente cliente;
    struct Tenis tenis;
};

void criarCliente(){
    FILE *arq;
    struct Cliente cliente;
    printf("===CRIAR CLIENTE===\n");
    printf("NOME: ");
    fgets(cliente.nome, sizeof(cliente.nome), stdin);
    cliente.nome[strcspn(cliente.nome, "\n")] = '\0';
    printf("ENDERECO: ");
    fgets(cliente.endereco, sizeof(cliente.endereco), stdin);
    cliente.endereco[strcspn(cliente.endereco, "\n")] = '\0';
    printf("EMAIL: ");
    fgets(cliente.email, sizeof(cliente.email), stdin);
    cliente.email[strcspn(cliente.email, "\n")] = '\0';
    printf("CPF: ");
    fgets(cliente.cpf, sizeof(cliente.cpf), stdin);
    cliente.cpf[strcspn(cliente.cpf, "\n")] = '\0';
    arq = fopen("tenis.txt", "a");

    if(arq == NULL){
        printf("Erro!!");
        return;
    }

    fprintf(arq, "%s,%s,%s,%s", cliente.nome,cliente.endereco,cliente.email,cliente.cpf);

    fclose(arq);
}

void listarClientes(){
    struct Cliente cliente;
    FILE *arq;

    printf("");
}

int main()
{
    criarCliente();

}
