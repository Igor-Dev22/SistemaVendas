# Sistema de Gerenciamento de Vendas em C

## Descrição

Este é um sistema completo de gerenciamento de vendas desenvolvido em linguagem C, projetado para pequenos negócios ou como projeto acadêmico. O sistema permite:

- Cadastro e gestão de clientes
- Cadastro e gestão de produtos
- Processamento completo de vendas

## Funcionalidades

### Gestão de Clientes
- Cadastro de novos clientes (nome, idade, CPF)
- Listagem completa de clientes, vendas e produtos.
- Edição de informações cadastrais
- Exclusão de clientes e produto

### Gestão de Produtos
- Cadastro de produtos (nome, preço)
- Listagem de todos os produtos
- Atualização de informações
- Remoção de produtos

### Processamento de Vendas
- Registro de vendas com múltiplos produtos
- Cálculo automático do valor total
- Seleção de método de pagamento (dinheiro, PIX, cartão)
- Histórico completo de vendas

### Listas
- Listagem de todas as vendas realizadas
- Identificação do produto mais vendido
- Visualização de detalhes de cada venda

## Interface do Usuário

O sistema possui um menu com as seguintes opções:

```
+-------------------------+
|0 = sair                 |
|1 = cadastrar clientes   |
|2 = cadastrar produtos   |
|3 = efetuar uma venda    |
|4 = listar os clientes   |
|5 = listar os produtos   |
|6 = excluir um cliente   |
|7 = excluir um produto   |
|8 = editar um cliente    |
|9 = editar um produto    |
|10 = listar vendas       |
|11 = produto mais vendido|
+-------------------------+
```
### Funções Principais
- `cadastro_cliente()`
- `cadastro_produto()`
- `venda()`
- `listar_vendas()`
- `listar_clientes()`
- `listar_produto()`
- `excluir_cliente()`
- `excluir_produto()`
- `editar_cliente()`
- `editar_produto()`
- `produto_mais_vendido()`


## Limitações do sistema

- Capacidade fixa para 10 clientes, 10 produtos e 50 vendas
- Dados são armazenados apenas em memória (não persistem após encerramento)
- Interface textual sem recursos gráficos

## ✉️ Contato

- Email: [igor22@unochapeco.edu.br]
- GitHub: [Igor-Dev22]
