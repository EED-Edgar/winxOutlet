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

    while(fscanf(arq, "%d;%[^;];%[^;];%[^;];[^;];\n", &cliente.id, cliente.nome, cliente.endereco, cliente.email, cliente.cpf) != EOF) {
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
    char idPesquisa[50];
    char tempNome[50];
    char tempEndereco[100];
    char tempEmail[100];
    char tempCPF[8];
    long int posicao;
    int editar;

    printf("=== - Atualizar Cliente - ===\n");
    printf("Digite o id do cliente que deseja atualizar: ");
    scanf("%d", &idPesquisa);

    arq = fopen("cliente.txt", "r+");

    if (abrirArq == 0) {
        return;
    }

    while(fscanf(arq, "%d;%[^;];%[^;];%[^;];[^;];\n", &cliente.id, cliente.nome, cliente.endereco, cliente.email, cliente.cpf) != EOF) {
        if(idPesquisa == cliente.id){
            strcpy(tempNome, cliente.nome);
            strcpy(tempEndereco, cliente.endereco);
            strcpy(tempEmail, cliente.email);
            strcpy(tempCPF, cliente.cpf);
            posicao = ftell(arq);
            printf("Nome: %s\n", cliente.nome);
            printf("Endereco: %s\n", cliente.nome);
            printf("E-mail: %s\n", cliente.nome);
            printf("CPF: %s\n", cliente.nome);
            printf("ID: %d\n", cliente.id);


            printf("O que voce deseja editar?\n");
            printf("1 - Nome\n");
            printf("2 - Endereco\n");
            printf("3 - E-mail\n");
            printf("4 - CPF\n");
            printf("0 - Sair\n");
            scanf("%d", &editar);

            while(editar>0 && editar<5) {

                switch(editar){
                case 1:
                    printf("Digite o novo nome: ");
                    fgets(tempNome, sizeof(tempNome), stdin);
                    tempNome[strcspn(tempNome, "\n")] = '\0';
                    break;
                case 2:
                    printf("Digite o novo endereco: ");
                    fgets(tempEndereco, sizeof(tempEndereco), stdin);
                    tempEndereco[strcspn(tempEndereco, "\n")] = '\0';
                    break;
                case 3:
                    printf("Digite o novo e-mail: ");
                    fgets(tempEmail, sizeof(tempEmail), stdin);
                    tempEmail[strcspn(tempEmail, "\n")] = '\0';
                    break;
                case 4:
                    printf("Digite o novo cpf: ");
                    fgets(tempCPF, sizeof(tempCPF), stdin);
                    tempCPF[strcspn(tempCPF, "\n")] = '\0';
                    break;
                }

                printf("Deseja editar mais alguma coisa?\n");
                printf("1 - Nome\n");
                printf("2 - Endereco\n");
                printf("3 - E-mail\n");
                printf("4 - CPF\n");
                printf("0 - Sair\n");
                scanf("%d", &editar);

                if(&editar == 0){
                    fprintf(arq, "%d;%s;%s;%s;%s\n", cliente.id, cliente.nome, cliente.endereco, cliente.email, cliente.cpf);
                    printf("Atualizacao realizadas");
                    break;
                }
            }

        }
    }

    fclose(arq);
}


int main()
{
    criarCliente();
    listarCliente();
   atualizarCliente();
}
