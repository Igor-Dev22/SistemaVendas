#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cadastro_cliente();
int cadastro_produto();
int venda();
void listar_clientes();
void listar_produtos();
void excluir_cliente();
void excluir_produto();
void editar_cliente();
void editar_produto();

typedef struct {
    int id;
    char nome[50];
    char cpf[12];
    int idade;
} Cliente;

typedef struct {
    int id;
    char nome[50];
    float preco;
} Produto;

Cliente clientes[10];
Produto produtos[10];

int total_clientes = 0;
int total_produtos = 0;
int next_cliente_id = 1;
int next_produto_id = 1;

int main() {
    int opcao;

    do {
        printf("\n    Menu Principal:\n\n");
        printf("+----------------------+\n");
        printf("|0 = sair              |\n");
        printf("|1 = cadastrar clientes|\n");
        printf("|2 = cadastrar produtos|\n");
        printf("|3 = efetuar uma venda |\n");
        printf("|4 = listar os clientes|\n");
        printf("|5 = listar os produtos|\n");
        printf("|6 = excluir um cliente|\n");
        printf("|7 = excluir um produto|\n");
        printf("|8 = editar um cliente |\n");
        printf("|9 = editar um produto |\n");
        printf("+----------------------+\n");
        printf("Escolha uma opcao:");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: cadastro_cliente(); break;
            case 2: cadastro_produto(); break;
            case 3: venda(); break;
            case 4: listar_clientes(); break;
            case 5: listar_produtos(); break;
            case 6: excluir_cliente(); break;
            case 7: excluir_produto(); break;
            case 8: editar_cliente(); break;
            case 9: editar_produto(); break;
            case 0: printf("Encerrando o programa...\n"); break;
            default: printf("Opcao Invalida, escolha outra\n"); break;
        }
    } while(opcao != 0);
}

int cadastro_cliente() {
    if(total_clientes >= 10) {
        printf("Limite de clientes atingido!\n");
        return 0;
    }

    printf("\n|CADASTRO DE CLIENTE|\n\n");
    clientes[total_clientes].id = next_cliente_id++;

    printf("Nome do cliente:\n-");
    scanf("%s", clientes[total_clientes].nome);
    printf("Idade do cliente:\n-");
    scanf("%d", &clientes[total_clientes].idade);
    printf("CPF do cliente (SOMENTE NUMEROS):\n-");
    scanf("%s", clientes[total_clientes].cpf);

    printf("\nCliente cadastrado com sucesso!\nID: %d\nNome: %s\nIdade: %d\nCPF: %s\n\n",
           clientes[total_clientes].id, clientes[total_clientes].nome,
           clientes[total_clientes].idade, clientes[total_clientes].cpf);
    total_clientes++;
    return 1;
}

int cadastro_produto() {
    if(total_produtos >= 10) {
        printf("Limite de produtos atingido!\n");
        return 0;
    }

    printf("|CADASTRO DE PRODUTO|\n\n");
    produtos[total_produtos].id = next_produto_id++;

    printf("Nome do produto:\n-");
    scanf("%s", produtos[total_produtos].nome);
    printf("Valor unitario do produto:\n-");
    scanf("%f", &produtos[total_produtos].preco);

    printf("Produto cadastrado com sucesso!\nID: %d\nNome: %s\nPreco: R$%.2f\n\n",
           produtos[total_produtos].id, produtos[total_produtos].nome,
           produtos[total_produtos].preco);
    total_produtos++;
    return 1;
}

int venda() {
    int cliente_id, produto_id, quantidade, pagamento;
    float valor;

    printf("Bem vindo ao menu de venda\n");

    listar_clientes();
    printf("Informe o ID do cliente:\n");
    scanf("%d", &cliente_id);

    listar_produtos();
    printf("Informe o ID do produto:\n");
    scanf("%d", &produto_id);

    printf("Informe a quantidade:\n");
    scanf("%d", &quantidade);

    printf("Qual o metodo de pagamento?\n1 - dinheiro\n2 - pix\n3 - cartao\n");
    scanf("%d", &pagamento);

    int cliente_index = -1, produto_index = -1;

    for(int i = 0; i < total_clientes; i++) {
        if(clientes[i].id == cliente_id) {
            cliente_index = i;
            break;
        }
    }

    for(int i = 0; i < total_produtos; i++) {
        if(produtos[i].id == produto_id) {
            produto_index = i;
            valor = produtos[i].preco * quantidade;
            break;
        }
    }

    if(cliente_index == -1 || produto_index == -1) {
        printf("Cliente ou produto nao encontrado!\n");
        return 0;
    }

    switch(pagamento) {
        case 1:
            printf("Venda efetuada com sucesso!\nCliente: %s\nProduto: %s\nQuantidade: %d\nValor: %.2f\nMetodo: Dinheiro\n",
                   clientes[cliente_index].nome, produtos[produto_index].nome, quantidade, valor);
            break;
        case 2:
            printf("Venda efetuada com sucesso!\nCliente: %s\nProduto: %s\nQuantidade: %d\nValor: %.2f\nMetodo: PIX\n",
                   clientes[cliente_index].nome, produtos[produto_index].nome, quantidade, valor);
            break;
        case 3:
            printf("Venda efetuada com sucesso!\nCliente: %s\nProduto: %s\nQuantidade: %d\nValor: %.2f\nMetodo: Cartao\n",
                   clientes[cliente_index].nome, produtos[produto_index].nome, quantidade, valor);
            break;
        default:
            printf("Metodo de pagamento invalido!\n");
    }
    return 1;
}

void listar_clientes() {
    printf("\nListagem de clientes cadastrados:\n\n");
    for(int i = 0; i < total_clientes; i++) {
        printf("ID: %d - %s (CPF: %s, Idade: %d)\n",
               clientes[i].id, clientes[i].nome, clientes[i].cpf, clientes[i].idade);
    }
}

void listar_produtos() {
    printf("\nListagem de produtos cadastrados:\n\n");
    for(int i = 0; i < total_produtos; i++) {
        printf("ID: %d - %s ( Preco: R$%.2f)\n",
               produtos[i].id, produtos[i].nome, produtos[i].preco);
    }
}

void excluir_cliente() {
    int id, i, j;

    listar_clientes();
    printf("Digite o ID do cliente que deseja EXCLUIR:\n");
    scanf("%d", &id);

    for(i = 0; i < total_clientes; i++) {
        if(clientes[i].id == id) {
            for(j = i; j < total_clientes - 1; j++) {
                clientes[j] = clientes[j + 1];
            }
            total_clientes--;
            printf("\nCliente excluido com sucesso!\n");
            return;
        }
    }
    printf("Cliente nao encontrado!\n");
}

void excluir_produto() {
    int id, i, j;

    listar_produtos();
    printf("Digite o ID do produto que deseja EXCLUIR:\n");
    scanf("%d", &id);

    for(i = 0; i < total_produtos; i++) {
        if(produtos[i].id == id) {
            for(j = i; j < total_produtos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            total_produtos--;
            printf("\nProduto excluido com sucesso!\n");
            return;
        }
    }
    printf("Produto nao encontrado!\n");
}

void editar_cliente() {
    int id, opcao, encontrado = 0;

    listar_clientes();
    printf("Digite o ID do cliente que deseja editar:\n");
    scanf("%d", &id);

    for(int i = 0; i < total_clientes; i++) {
        if(clientes[i].id == id) {
            printf("\nCliente selecionado:\n");
            printf("ID: %d\nNome: %s\nIdade: %d\nCPF: %s\n",
                   clientes[i].id, clientes[i].nome, clientes[i].idade, clientes[i].cpf);

            printf("\nQual informacao deseja editar?\n1 - Nome\n2 - Idade\n3 - CPF\n4 - Cancelar\n");
            scanf("%d", &opcao);

            switch(opcao) {
                case 1:
                    printf("Digite o novo nome:\n");
                    scanf("%s", clientes[i].nome);
                    break;
                case 2:
                    printf("Digite a nova idade:\n");
                    scanf("%d", &clientes[i].idade);
                    break;
                case 3:
                    printf("Digite o novo CPF:\n");
                    scanf("%s", clientes[i].cpf);
                    break;
                case 4:
                    printf("Edicao cancelada.\n");
                    return;
                default:
                    printf("Opcao invalida!\n");
                    return;
            }

            printf("\nCliente editado com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if(!encontrado) {
        printf("Cliente nao encontrado!\n");
    }
}

void editar_produto() {
    int id, opcao, encontrado = 0;

    listar_produtos();
    printf("Digite o ID do produto que deseja editar:\n");
    scanf("%d", &id);

    for(int i = 0; i < total_produtos; i++) {
        if(produtos[i].id == id) {
            printf("\nProduto selecionado:\n");
            printf("ID: %d\nNome: %s\nPreco: R$%.2f\n",
                   produtos[i].id, produtos[i].nome,produtos[i].preco);

            printf("\nQual informacao deseja editar?\n1 - Nome\n2 - Preco\n4 - Cancelar\n");
            scanf("%d", &opcao);

            switch(opcao) {
                case 1:
                    printf("Digite o novo nome:\n");
                    scanf("%s", produtos[i].nome);
                    break;
                case 2:
                    printf("Digite o novo preco:\n");
                    scanf("%f", &produtos[i].preco);
                    break;
                case 3:
                     printf("Edicao cancelada.\n");
                    return;
                default:
                    printf("Opcao invalida!\n");
                    return;
            }

            printf("\nProduto editado com sucesso!\n");
            encontrado = 1;
            break;
        }
    }

    if(!encontrado) {
        printf("Produto nao encontrado!\n");
    }
}