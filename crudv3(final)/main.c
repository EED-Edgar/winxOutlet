#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

struct Cliente {
    char nome[50];
    char endereco[100];
    char email[100];
    char cpf[12];
    int id;
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
    system("cls");
    srand(time(NULL));//Configura para que n repita números
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
    printf("Cliente registrado com sucesso!!!\nAperte espaço para continuar...");
    getch();

    fclose(arq);
}

void listarClientes() {
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

void buscaClientes(){
    struct Cliente cliente;
    FILE *arq;

    int idPesquisa;
    char nomePesquisa[50];
    char enderecoPesquisa[100];
    char emailPesquisa[100];
    char cpfPesquisa[12];
    int editar = 1;
    int encontrado;

    system("cls");

    printf("=== - Busca Cliente - ===\n");
    printf("Como você quer busca-lo: \n");
    printf("1. Nome\n");
    printf("2. Endereco\n");
    printf("3. E-mail\n");
    printf("4. CPF\n");
    printf("5. ID\n");
    scanf("%d", &editar);

    arq = fopen("cliente.txt","r");

    if(abrirArq(arq) == 0){
        return;
    }

    switch(editar){
        case 1:
            printf("Digite o nome para a busca: \n\n");
            getchar();
            gets(nomePesquisa);
            system("cls");
            while (fscanf(arq, "%d;%[^;];%[^;];%[^;];%[^\n;];\n", &cliente.id, cliente.nome, cliente.endereco, cliente.email, cliente.cpf) != EOF){
                if(strcmp(nomePesquisa, cliente.nome) == 0){
                    encontrado++;
                    if(encontrado==1){
                        printf("Resultados encontrados para: %s\n", nomePesquisa);
                    }
                    printf("Nome: %s\n", cliente.nome);
                    printf("Endereco: %s\n", cliente.endereco);
                    printf("E-mail: %s\n", cliente.email);
                    printf("CPF: %s\n", cliente.cpf);
                    printf("ID: %d\n", cliente.id);
                    printf("-------------------------------------------\n");
                }
            }

            break;
        case 2:
            printf("Digite o endereço para a busca: \n\n");
            getchar();
            gets(enderecoPesquisa);
            system("cls");
            while (fscanf(arq, "%d;%[^;];%[^;];%[^;];%[^\n;];\n", &cliente.id, cliente.nome, cliente.endereco, cliente.email, cliente.cpf) != EOF){
                if(strcmp(enderecoPesquisa, cliente.endereco) == 0){
                    encontrado++;
                    if(encontrado==1){
                        printf("Resultados encontrados para: %s\n", enderecoPesquisa);
                    }
                    printf("Nome: %s\n", cliente.nome);
                    printf("Endereco: %s\n", cliente.endereco);
                    printf("E-mail: %s\n", cliente.email);
                    printf("CPF: %s\n", cliente.cpf);
                    printf("ID: %d\n", cliente.id);
                    printf("-------------------------------------------\n");
                }
            }
            break;
        case 3:
            printf("Digite o e-mail para a busca: \n\n");
            getchar();
            gets(emailPesquisa);
            system("cls");
            while (fscanf(arq, "%d;%[^;];%[^;];%[^;];%[^\n;];\n", &cliente.id, cliente.nome, cliente.endereco, cliente.email, cliente.cpf) != EOF){
                if(strcmp(emailPesquisa, cliente.email) == 0){
                    encontrado++;
                    if (encontrado == 1) {
                        printf("Resultados encontrados para: %s\n", emailPesquisa);
                    }
                    printf("Nome: %s\n", cliente.nome);
                    printf("Endereco: %s\n", cliente.endereco);
                    printf("E-mail: %s\n", cliente.email);
                    printf("CPF: %s\n", cliente.cpf);
                    printf("ID: %d\n", cliente.id);
                    printf("-------------------------------------------\n");
                }
            }
            break;
        case 4:
            printf("Digite o CPF para a busca: \n\n");
            getchar();
            gets(cpfPesquisa);
            system("cls");
            while (fscanf(arq, "%d;%[^;];%[^;];%[^;];%[^\n;];\n", &cliente.id, cliente.nome, cliente.endereco, cliente.email, cliente.cpf) != EOF){
                if(strcmp(cpfPesquisa, cliente.cpf) == 0){
                    encontrado++;
                    if(encontrado==1){
                        printf("Resultados encontrados para: %s\n", cpfPesquisa);
                    }
                    printf("Nome: %s\n", cliente.nome);
                    printf("Endereco: %s\n", cliente.endereco);
                    printf("E-mail: %s\n", cliente.email);
                    printf("CPF: %s\n", cliente.cpf);
                    printf("ID: %d\n", cliente.id);
                    printf("-------------------------------------------\n");
                }
            }
            break;
        case 5:
            printf("Digite o ID para a busca: \n\n");
            scanf("%d", &idPesquisa);
            while (fscanf(arq, "%d;%[^;];%[^;];%[^;];%[^\n;];\n", &cliente.id, cliente.nome, cliente.endereco, cliente.email, cliente.cpf) != EOF){
                if(idPesquisa == cliente.id){
                    encontrado++;
                    if(encontrado==1){
                        printf("Resultados encontrados para: %d\n", idPesquisa);
                    }
                    printf("Nome: %s\n", cliente.nome);
                    printf("Endereco: %s\n", cliente.endereco);
                    printf("E-mail: %s\n", cliente.email);
                    printf("CPF: %s\n", cliente.cpf);
                    printf("ID: %d\n", cliente.id);
                    printf("-------------------------------------------\n");
                }
            }
            break;
        default:
            printf("Opcao inexistente\n");
            break;
        }

        if(!encontrado){
        printf("Nenhum cliente encontrado. \nAperte espaço para continuar...");
        getch();
        system("cls");
        fclose(arq);
        return;
    }

    fclose(arq);
}

void atualizarCliente() {
    struct Cliente cliente;
    FILE *arq;
    int idPesquisa;
    int editar = 1;
    int encontrado;
    FILE *temp;

    printf("=== - Atualizar Cliente - ===\n");
    printf("Digite o id do cliente que deseja atualizar: ");
    scanf("%d", &idPesquisa);

    system("cls");

    arq = fopen("cliente.txt", "r");
    temp = fopen("temp.txt", "w");

    if (abrirArq(temp) == 0) {
        return;
    }

    if (abrirArq(arq) == 0) {
        return;
    }

    while (fscanf(arq, "%d;%[^;];%[^;];%[^;];%[^\n;];\n", &cliente.id, cliente.nome, cliente.endereco, cliente.email, cliente.cpf) != EOF){
        if(idPesquisa == cliente.id){
            printf("Nome: %s\n", cliente.nome);
            printf("Endereco: %s\n", cliente.endereco);
            printf("E-mail: %s\n", cliente.email);
            printf("CPF: %s\n", cliente.cpf);
            printf("ID: %d\n", cliente.id);
            encontrado = 1;
            while(editar > 0){
                printf("O que voce deseja editar?\n");
                printf("1. Nome\n");
                printf("2. Endereco\n");
                printf("3. E-mail\n");
                printf("4. CPF\n");
                printf("0. Sair\n");
                scanf("%d", &editar);
                getchar();

                switch(editar){
                    case 1:
                        printf("Digite o novo nome: \n");
                        fgets(cliente.nome, sizeof(cliente.nome), stdin);
                        cliente.nome[strcspn(cliente.nome, "\n")] = '\0';
                        printf("Nome atualizado\n\n");

                        break;
                    case 2:
                        printf("Digite o novo endereco: \n");
                        fgets(cliente.endereco, sizeof(cliente.endereco), stdin);
                        cliente.endereco[strcspn(cliente.endereco, "\n")] = '\0';
                        printf("Endereço atualizado\n\n");
                        break;
                    case 3:
                        printf("Digite o novo e-mail: \n");
                        fgets(cliente.email, sizeof(cliente.email), stdin);
                        cliente.email[strcspn(cliente.email, "\n")] = '\0';
                        printf("E-mail atualizado\n\n");
                        break;
                    case 4:
                        printf("Digite o novo cpf: \n");
                        fgets(cliente.cpf, sizeof(cliente.cpf), stdin);
                        cliente.cpf[strcspn(cliente.cpf, "\n")] = '\0';
                        printf("CPF atualizado\n\n");
                        break;
                    case 0:
                        printf("Atualização realizada\nAperte espcaço para continuar...");
                        getch();
                    default:
                        printf("Opcao inexistente\n");
                        break;
                    }
            }
        }
        fprintf(temp, "%d;%s;%s;%s;%s\n", cliente.id, cliente.nome, cliente.endereco, cliente.email, cliente.cpf);
    }

    if(!encontrado){
        printf("Cliente não encontrado. \n");
        getch();
        fclose(temp);
        remove("temp.txt");
        return;
    }

    fclose(arq);
    fclose(temp);
    remove("cliente.txt");
    rename("temp.txt", "cliente.txt");
}

void excluirCliente(){
    struct Cliente cliente;
    FILE *arq;
    int idPesquisa;
    int encontrado;
    FILE *temp;

    printf("=== - Apagar Cliente - ===\n");
    printf("Digite o id do cliente que deseja deletar: ");
    scanf("%d", &idPesquisa);

    arq = fopen("cliente.txt", "r");
    temp = fopen("temp.txt", "w");

    if (abrirArq(temp) == 0) {
        return;
    }

    if (abrirArq(arq) == 0) {
        return;
    }

    while (fscanf(arq, "%d;%[^;];%[^;];%[^;];%[^\n;];\n", &cliente.id, cliente.nome, cliente.endereco, cliente.email, cliente.cpf) != EOF){
        if (cliente.id == idPesquisa) {
            encontrado = 1;
            continue;  // Pular o registro do cliente a ser apagado
        }
        fprintf(temp, "%d;%s;%s;%s;%s\n", cliente.id, cliente.nome, cliente.endereco, cliente.email, cliente.cpf);
    }

    if(!encontrado){
        printf("Cliente não encontrado. \n");
        getch();
        fclose(temp);
        remove("temp.txt");
        return;
    }

    fclose(arq);
    fclose(temp);
    remove("cliente.txt");
    rename("temp.txt", "cliente.txt");
}


int main()
{
    setlocale(LC_ALL, "");
    int opcao;

    while (1) {
        printf("=== - MENU - ===\n");
        printf("1. Criar cliente\n");
        printf("2. Buscar clientes\n");
        printf("3. Listar clientes\n");
        printf("4. Editar cliente\n");
        printf("5. Excluir cliente\n");
        printf("0. Sair\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                criarCliente();
                system("cls");
                break;
            case 2:
                buscaClientes();
                break;
            case 3:
                system("cls");
                listarClientes();
                break;
            case 4:
                atualizarCliente();
                system("cls");
                break;
            case 5:
                excluirCliente();
                system("cls");
                break;
            case 0:
                printf("Saindo...\n");
                return 0;
            default:
                system("cls");
                printf("Opcao invalida.\n");
                break;
        }
    }

    return 0;

}
