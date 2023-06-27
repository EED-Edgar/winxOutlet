#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Cliente {
    char nome[50];
    char endereco[100];
    char email[100];
    char cpf[8];
    int id;
};

struct Tenis {
    char marca[50];
    int codigo;
    char modelo[50];
    int quantidade;
};

struct Venda {
    struct Cliente cliente;
    struct Tenis tenis;
};

int abrirArq(FILE *arq) {
    if (arq == NULL){
        printf("Erro ao abrir o arquivo");
        return 0;
    }else {
        return 1;
    }
}

void criarCliente() {
    srand(time(NULL));
    struct Cliente cliente;
    FILE *arq;

    printf("=== - Criar Cliente - ====\n");
    printf("Nome: ");
    fgets(cliente.nome, sizeof(cliente.nome), stdin);
    cliente.nome[strcspn(cliente.nome, "\n")] = '\0';

    printf("Endereço: ");
    fgets(cliente.endereco, sizeof(cliente.endereco), stdin);
    cliente.endereco[strcspn(cliente.endereco, "\n")] = '\0';

    printf("E-mail: ");
    fgets(cliente.email, sizeof(cliente.endereco), stdin);
    cliente.email[strcspn(cliente.email, "\n")] = '\0';

    printf("CPF: ");
    fgets(cliente.cpf, sizeof(cliente.cpf), stdin);
    cliente.cpf[strcspn(cliente.cpf, "\n")] = '\0';

    cliente.id = rand() % 99999;

    arq = fopen("cliente.txt", "a");

    if (abrirArq(arq)==0){
        return;
    }

    fprintf(arq, "%d;%s;%s;%s;%s\n", cliente.id, cliente.nome, cliente.endereco, cliente.email, cliente.cpf);

    fclose(arq);
}

void listarCliente() {
    struct Cliente cliente;
    FILE *arq;

    printf("=== - Lista de Clientes - ===\n");

    arq = fopen("cliente.txt","r");

    if(abrirArq(arq) == 0){
        return;
    }

    while(fscanf(arq, "%d;%[^;];%[^;];%[^;];%[^\n;];\n", &cliente.id, cliente.nome, cliente.endereco, cliente.email, cliente.cpf) != EOF) {
        printf("Nome: %s\n", cliente.nome);
        printf("Endereco: %s\n", cliente.endereco);
        printf("E-mail: %s\n", cliente.email);
        printf("CPF: %s\n", cliente.cpf);
        printf("ID: %d\n", cliente.id);
        printf("-------------------------------------------\n");
    }

    fclose(arq);
}

void atualizarCliente() {
    struct Cliente cliente;
    FILE *arq;
    int idPesquisa;
    int editar;
    int encontrado;

    printf("=== - Atualizar Cliente - ===\n");
    printf("Digite o id do cliente que deseja atualizar: ");
    scanf("%d", &idPesquisa);

    arq = fopen("cliente.txt", "r+");

    if (abrirArq == 0) {
        return;
    }

    while (fscanf(arq, "%d;%[^;];%[^;];%[^;];%[^\n;];\n", &cliente.id, cliente.nome, cliente.endereco, cliente.email, cliente.cpf) != EOF){
        if(idPesquisa == cliente.id){
            encontrado = 1;
            break;
        }
    }

    if(!encontrado){
        printf("Cliente não encontrado. \n");
        fclose(arq);
        return;
    }

    printf("Nome: %s\n", cliente.nome);
    printf("Endereco: %s\n", cliente.endereco);
    printf("E-mail: %s\n", cliente.email);
    printf("CPF: %s\n", cliente.cpf);
    printf("ID: %d\n", cliente.id);


   while(1){
    printf("O que voce deseja editar?\n");
    printf("1 - Nome\n");
    printf("2 - Endereco\n");
    printf("3 - E-mail\n");
    printf("4 - CPF\n");
    printf("0 - Sair\n");
    scanf("%d", &editar);
    getchar();

    switch(editar){
        case 1:
            printf("Digite o novo nome: \n");
            fgets(cliente.nome, sizeof(cliente.nome), stdin);
            cliente.nome[strcspn(cliente.nome, "\n")] = '\0';
            printf("Nome atualizado\n");

            break;
        case 2:
            printf("Digite o novo endereco: \n");
            fgets(cliente.endereco, sizeof(cliente.endereco), stdin);
            cliente.endereco[strcspn(cliente.endereco, "\n")] = '\0';
            printf("Endereço atualizado\n");
            break;
        case 3:
            printf("Digite o novo e-mail: \n");
            fgets(cliente.email, sizeof(cliente.email), stdin);
            cliente.email[strcspn(cliente.email, "\n")] = '\0';
            printf("E-mail atualizado\n");
            break;
        case 4:
            printf("Digite o novo cpf: \n");
            fgets(cliente.cpf, sizeof(cliente.cpf), stdin);
            cliente.cpf[strcspn(cliente.cpf, "\n")] = '\0';
            printf("CPF atualizado\n");
            break;
        case 0:
            fseek(arq, - sizeof(int) -strlen(cliente.nome) - strlen(cliente.endereco) - strlen(cliente.email) - strlen(cliente.cpf) - 5, SEEK_CUR);
            fprintf(arq, "%d;%s;%s;%s;%s\n", cliente.id,cliente.nome, cliente.endereco, cliente.email, cliente.cpf);
            printf("Atualização realizada");
            fclose(arq);
            return;
        default:
            printf("Opcao inesistente");
            break;
        }


        }


    fclose(arq);
}


int main()
{
   listarCliente();
   atualizarCliente();
}
