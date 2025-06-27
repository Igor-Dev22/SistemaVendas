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
    int vendas;
} Produto;

typedef struct {
    int id_venda;
    int id_cliente;
    int produtos_venda[10];
    int quantidades[10];
    int total_itens;
    float valor_total;
    int metodo_pagamento;
} Venda;

Venda vendas[50];
int total_vendas = 0;
int next_venda_id = 1;

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
        printf("+-------------------------+\n");
        printf("|0 = sair                 |\n");
        printf("|1 = cadastrar clientes   |\n");
        printf("|2 = cadastrar produtos   |\n");
        printf("|3 = efetuar uma venda    |\n");
        printf("|4 = listar os clientes   |\n");
        printf("|5 = listar os produtos   |\n");
        printf("|6 = excluir um cliente   |\n");
        printf("|7 = excluir um produto   |\n");
        printf("|8 = editar um cliente    |\n");
        printf("|9 = editar um produto    |\n");
        printf("|10 = listar vendas       |\n");
        printf("|11 = produto mais vendido|\n");
        printf("+-------------------------+\n");

        printf("Escolha uma opcao:");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: cadastro_cliente();
                break;
            case 2: cadastro_produto();
                break;
            case 3: venda();
                break;
            case 4: listar_clientes();
                break;
            case 5: listar_produtos();
                break;
            case 6: excluir_cliente();
                break;
            case 7: excluir_produto();
                break;
            case 8: editar_cliente();
                break;
            case 9: editar_produto();
                break;
            case 10: listar_vendas();
                break;
            case 11: produto_mais_vendido();
                break;
            case 0: printf("Encerrando o programa...\n");
                break;
            default: printf("Opcao Invalida, escolha outra\n");
                break;
        }
    } while(opcao != 0);
}

int cadastro_cliente() {
    if(total_clientes >= 10) {
        printf("Limite maximo de clientes atingido!\n");
        return 0;
    }

    printf("\nCADASTRO DE CLIENTE\n\n");
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

    char opcao;
    printf("Deseja cadastrar outro cliente? (s/n): ");
    scanf(" %c", &opcao);

    if (opcao == 's' || opcao == 'S') {
        return cadastro_cliente();
    }
    else if (opcao == 'n' || opcao == 'N') {
        printf("Cadastro de clientes finalizado.\n");
        return 1;
    }
    else {
        printf("Opção inválida! Cadastro finalizado.\n");
        return 1;
    }

}

int cadastro_produto() {
    if(total_produtos >= 10) {
        printf("Limite maximo de produtos atingido!\n");
        return 0;
    }

    printf("\nCADASTRO DE PRODUTO\n\n");
    produtos[total_produtos].id = next_produto_id++;
    produtos[total_produtos].vendas = 0;

    printf("Nome do produto:\n-");
    scanf("%s", produtos[total_produtos].nome);
    printf("Valor unitario do produto:\n-");
    scanf("%f", &produtos[total_produtos].preco);

    printf("Produto cadastrado com sucesso!\nID: %d\nNome: %s\nPreco: R$%.2f\n\n",
           produtos[total_produtos].id, produtos[total_produtos].nome,
           produtos[total_produtos].preco);
    total_produtos++;

    char opcao;
    printf("Deseja cadastrar outro produto? (s/n): ");
    scanf(" %c", &opcao);

    if (opcao == 's' || opcao == 'S') {
        return cadastro_produto();
    }
    else if (opcao == 'n' || opcao == 'N') {
        printf("Cadastro de produto finalizado.\n");
        return 1;
    }
    else {
        printf("Opção inválida! Cadastro finalizado.\n");
        return 1;
    }
}

int venda() {
    if(total_vendas >= 50) {
        printf("Limite máximo de vendas atingido!\n");
        return 0;
    }

    vendas[total_vendas].id_venda = next_venda_id++;
    vendas[total_vendas].total_itens = 0;
    vendas[total_vendas].valor_total = 0;

    printf("\nVenda ID: %d\n", vendas[total_vendas].id_venda);

    listar_clientes();
    printf("Informe o ID do cliente:\n");
    scanf("%d", &vendas[total_vendas].id_cliente);

    int cliente_index = -1;
    for(int i = 0; i < total_clientes; i++) {
        if(clientes[i].id == vendas[total_vendas].id_cliente) {
            cliente_index = i;
            break;
        }
    }

    if(cliente_index == -1) {
        printf("Cliente não encontrado!\n");
        return 0;
    }

    char continuar = 's';
    while(continuar == 's' || continuar == 'S') {
        if(vendas[total_vendas].total_itens >= 10) {
            printf("Limite máximo de itens por venda atingido!\n");
            break;
        }

        listar_produtos();
        printf("Informe o ID do produto:\n");
        scanf("%d", &vendas[total_vendas].produtos_venda[vendas[total_vendas].total_itens]);

        printf("Informe a quantidade:\n");
        scanf("%d", &vendas[total_vendas].quantidades[vendas[total_vendas].total_itens]);

        int produto_index = -1;
        for(int i = 0; i < total_produtos; i++) {
            if(produtos[i].id == vendas[total_vendas].produtos_venda[vendas[total_vendas].total_itens]) {
                produto_index = i;
                float valor_item = produtos[i].preco * vendas[total_vendas].quantidades[vendas[total_vendas].total_itens];
                vendas[total_vendas].valor_total += valor_item;

                produtos[i].vendas += vendas[total_vendas].quantidades[vendas[total_vendas].total_itens];
                break;
            }       }

        if(produto_index == -1) {
            printf("Produto não encontrado!\n");
            continue;
        }

        vendas[total_vendas].total_itens++;

        printf("Deseja adicionar outro produto? (s/n): ");
        scanf(" %c", &continuar);
    }

    if(vendas[total_vendas].total_itens == 0) {
        printf("Nenhum produto selecionado. Venda cancelada.\n");
        return 0;
    }

    printf("Qual o metodo de pagamento?\n1 - dinheiro\n2 - pix\n3 - cartao\n");
    scanf("%d", &vendas[total_vendas].metodo_pagamento);

    printf("\nIhull venda realizada com sucesso!\n");
    printf("\nID da Venda: %d\n", vendas[total_vendas].id_venda);
    printf("Cliente: %s\n", clientes[cliente_index].nome);
    printf("Itens comprados:\n");

    for(int i = 0; i < vendas[total_vendas].total_itens; i++) {
        for(int j = 0; j < total_produtos; j++) {
            if(produtos[j].id == vendas[total_vendas].produtos_venda[i]) {
                printf("- %s |Quantidade: %d - R$%.2f un|\n",
                       produtos[j].nome, vendas[total_vendas].quantidades[i], produtos[j].preco);
                break;
            }
        }
    }

    printf("\nValor total: R$%.2f\n", vendas[total_vendas].valor_total);

    switch(vendas[total_vendas].metodo_pagamento) {
        case 1: printf("Metodo: Dinheiro\n"); break;
        case 2: printf("Metodo: PIX\n"); break;
        case 3: printf("Metodo: Cartao\n"); break;
        default: printf("Metodo de pagamento não especificado\n");
    }

    total_vendas++;
    return 1;
}

void listar_clientes() {
    printf("\nLista de clientes cadastrados:\n\n");
    for(int i = 0; i < total_clientes; i++) {
        printf("ID: %d  |%s - CPF: %s, Idade: %d| \n",
               clientes[i].id, clientes[i].nome, clientes[i].cpf, clientes[i].idade);
    }
}

void listar_produtos() {
    printf("\nLista de produtos cadastrados:\n\n");
    for(int i = 0; i < total_produtos; i++) {
        printf("ID: %d  |%s - Preco: R$%.2f| \n",
               produtos[i].id, produtos[i].nome, produtos[i].preco);
    }
}

void listar_vendas() {
    printf("\nLista de todas as vendas:\n\n");
    for(int i = 0; i < total_vendas; i++) {
        printf("Venda ID: %d\n", vendas[i].id_venda);
        printf("ID/Cliente: %d\n", vendas[i].id_cliente);

        char nome_cliente[50] = "Nao encontrado";
        for(int j = 0; j < total_clientes; j++) {
            if(clientes[j].id == vendas[i].id_cliente) {
                strcpy(nome_cliente, clientes[j].nome);
                break;
            }
        }

        printf("Cliente: %s\n", nome_cliente);
        printf("Itens:\n");

        for(int j = 0; j < vendas[i].total_itens; j++) {
            for(int k = 0; k < total_produtos; k++) {
                if(produtos[k].id == vendas[i].produtos_venda[j]) {
                    printf("- %s (Qtd: %d, R$%.2f)\n",
                           produtos[k].nome, vendas[i].quantidades[j], produtos[k].preco);
                    break;
                }
            }
        }

        printf("Valor total: R$%.2f\n", vendas[i].valor_total);

        char* metodo;
        switch(vendas[i].metodo_pagamento) {
            case 1: metodo = "Dinheiro"; break;
            case 2: metodo = "PIX"; break;
            case 3: metodo = "Cartao"; break;
            default: metodo = "Desconhecido";
        }
        printf("Metodo de pagamento: %s\n\n", metodo);
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

            printf("\nQual informacao deseja editar?");
             printf("\n1 - Nome\n2 - Preco\n3 - Cancelar\n");
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

void produto_mais_vendido() {
    if(total_produtos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    int max_vendas = -1;
    int indice_mais_vendido = -1;

    for(int i = 0; i < total_produtos; i++) {
        if(produtos[i].vendas > max_vendas) {
            max_vendas = produtos[i].vendas;
            indice_mais_vendido = i;
        }
    }

    if(max_vendas == 0) {
        printf("Nenhum produto foi vendido ainda.\n");
        return;
    }

    printf("\nProduto mais vendido:\n");
    printf("ID: %d\n", produtos[indice_mais_vendido].id);
    printf("Nome: %s\n", produtos[indice_mais_vendido].nome);
    printf("Preco: R$%.2f\n", produtos[indice_mais_vendido].preco);
    printf("Quantidade vendida: %d\n", produtos[indice_mais_vendido].vendas);
}