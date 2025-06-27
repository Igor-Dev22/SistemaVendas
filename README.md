# Sistema de Gerenciamento de Vendas em C

## Descrição

Este é um sistema completo de gerenciamento de vendas desenvolvido em linguagem C, projetado para pequenos negócios ou como projeto acadêmico. O sistema permite:

- Cadastro e gestão de clientes
- Cadastro e gestão de produtos
- Processamento completo de vendas
- Geração de relatórios e consultas

## Funcionalidades

### Gestão de Clientes
- Cadastro de novos clientes (nome, idade, CPF)
- Listagem completa de clientes
- Edição de informações cadastrais
- Exclusão de clientes

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

### Relatórios
- Listagem de todas as vendas realizadas
- Identificação do produto mais vendido
- Visualização de detalhes de cada venda

## Interface do Usuário

O sistema possui um menu interativo com as seguintes opções:

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
- `cadastro_cliente()`: Gerencia o cadastro de clientes
- `cadastro_produto()`: Gerencia o cadastro de produtos
- `venda()`: Processa novas vendas
- `listar_vendas()`: Exibe o histórico de vendas
- `produto_mais_vendido()`: Gera relatório do produto mais vendido

## Limitações do sistema

- Capacidade fixa para 10 clientes, 10 produtos e 50 vendas
- Dados são armazenados apenas em memória (não persistem após encerramento)
- Interface textual sem recursos gráficos

## ✉️ Contato

Para dúvidas ou sugestões, entre em contato:

- Email: [igor22@unochapeco.edu.br]
- GitHub: [Igor-Dev22]
