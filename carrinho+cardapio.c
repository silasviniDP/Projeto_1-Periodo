#include <stdio.h>
#include <string.h>

// Structs do Cardápio.

struct cardapio { // O que compõe um item do cardápio.
    char  produto[70];
    float preco;
};

struct cardapio produtos[7] = { // Itens presente no cardápio.
    {"Pipoca Pequena", 12.00f},
    {"Pipoca Media", 13.50f},
    {"Pipoca Grande", 16.50f},
    {"Refrigerante 500ml", 7.50f},
    {"Refrigerante 750ml", 9.00f},
    {"Combo P (Pipoca M + Refri P)", 22.00f},
    {"Combo M (Pipoca G + Refri M)", 28.00f}
};

// Struct do Carrinho.

struct itemCarrinho { // O que compôe o item.
    char produto[70];
    int quantidade;
    float precoUnitario;
    float subtotal;
}; 

struct itemCarrinho carrinho[10]; // Define a quantia máxima de itens no carrinho.
int qtdNoCarrinho = 0; // Quantidade inicial de itens no carrinho.

// Funções do Cardápio.

void exibirCardapio() {
    printf("\n=========== Cardapio ===========\n");
    for (int i = 0; i < 7; i++) {
        printf("  %d. %-35s R$ %.2f\n", i + 1, produtos[i].produto, produtos[i].preco);
    }
    printf("  0. Voltar\n");
    printf("=================================\n");
}

// Funções do Carrinho.

void adicionarItem(int opcao, int quantidade) {
    if (opcao < 1 || opcao > 7) {
        printf("[ERRO] Opcao invalida.\n");
        return;
    }
    if (quantidade <= 0) {
        printf("[ERRO] Quantidade deve ser maior que zero.\n");
        return;
    }

    int idx = opcao - 1;

    for (int i = 0; i < qtdNoCarrinho; i++) {
        if (strcmp(carrinho[i].produto, produtos[idx].produto) == 0) {
            carrinho[i].quantidade += quantidade;
            carrinho[i].subtotal = carrinho[i].quantidade * carrinho[i].precoUnitario;
            printf("[OK] Quantidade de \"%s\" atualizada para %d.\n", carrinho[i].produto, carrinho[i].quantidade);
            return;
        }
    }

    if (qtdNoCarrinho >= 10) {
        printf("[AVISO] Carrinho cheio (maximo de 10 itens).\n");
        return;
    }

    strncpy(carrinho[qtdNoCarrinho].produto, produtos[idx].produto, 70);
    carrinho[qtdNoCarrinho].quantidade = quantidade;
    carrinho[qtdNoCarrinho].precoUnitario = produtos[idx].preco;
    carrinho[qtdNoCarrinho].subtotal = quantidade * produtos[idx].preco;

    printf("[OK] \"%s\" adicionado ao carrinho.\n", carrinho[qtdNoCarrinho].produto);
    qtdNoCarrinho++;
}

void removerItem(int posCarrinho) {
    if (posCarrinho < 1 || posCarrinho > qtdNoCarrinho) {
        printf("[ERRO] Posicao invalida.\n");
        return;
    }
    int idx = posCarrinho - 1;
    printf("[OK] \"%s\" removido.\n", carrinho[idx].produto);

    for (int i = idx; i < qtdNoCarrinho - 1; i++) {
        carrinho[i] = carrinho[i + 1];
    }
    
    qtdNoCarrinho--;
}

void exibirCarrinho() {
    if (qtdNoCarrinho == 0) {
        printf("\nCarrinho vazio.\n");
        return;
    }

    float total = 0;
    printf("\n========== Carrinho ==========\n");
    for (int i = 0; i < qtdNoCarrinho; i++) {
        printf("  %d. %-30s x%d  R$ %.2f\n",
               i + 1,
               carrinho[i].produto,
               carrinho[i].quantidade,
               carrinho[i].subtotal);
        total += carrinho[i].subtotal;
    }
    printf("------------------------------\n");
    printf("  Subtotal cardapio: R$ %.2f\n", total);
    printf("==============================\n");
}

// Menu do Cardápio.

void menuCardapio() {
    int opcao, quantidade;

    do {
        exibirCardapio();
        exibirCarrinho();

        printf("\nEscolha um produto (0 para voltar): ");
        scanf("%d", &opcao);

        if (opcao == 0) break;

        if (opcao < 1 || opcao > 7) {
            printf("[ERRO] Opcao invalida.\n");
            continue;
        }

        printf("Quantidade: ");
        scanf("%d", &quantidade);
        adicionarItem(opcao, quantidade);

        printf("Deseja remover algum item? (1-Sim / 0-Nao): ");
        int remover;
        scanf("%d", &remover);
        if (remover) {
            exibirCarrinho();
            printf("Qual posicao remover? ");
            int pos;
            scanf("%d", &pos);
            removerItem(pos);
        }

    } while (opcao != 0);
}

/* Função que retorna o total do Cardápio
   (Para Manu somar com o total dos ingressos). */

float totalCardapio() {
    float total = 0;
    for (int i = 0; i < qtdNoCarrinho; i++){
      total += carrinho[i].subtotal;
    }

    return total;
}

// Main para testes
 
int main() {
    menuCardapio();
 
    printf("\n>>> Total do cardapio: R$ %.2f\n", totalCardapio());
    printf(">>> Seguindo para o pagamento...\n");
 
    return 0;
}
