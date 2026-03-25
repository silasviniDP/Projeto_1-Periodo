#include <stdio.h>
#include <locale.h>


// ============================================================
//                          STRUCTS 
// ============================================================ 


/* Cada filme tem: título, gênero, faixa etária, duração,
   avaliação e preço do ingresso. */
struct filme {
    char titulo[50];
    char genero[50];
    int faixa_etaria;
    int duracao;    // Em minutos
    float avaliacao; // Até 10
    float preco;    // Em reais
};

// Cada lanche tem: nome e preço.
struct lanche {
    char nome[40];
    float preco;
};

// O carrinho guarda o que o usuário escolheu:
// filme, assento, quantidade de ingressos,
// quantidade de cada lanche e o total.
struct carrinho {
    char filme[50];
    char assento[5];       // ex: "A3"
    int quantidade;        // ingressos
    int lanches_qtd[6];    // índice = posição no cardápio
    float preco_total;
};


// ============================================================
//                             MAIN
// ============================================================
int main() {
    setlocale(LC_ALL, "Portuguese");

    // -- Cardápio de lanches (fixo, não muda durante o programa) --
    struct lanche cardapio[6] = {
        {"Pipoca Pequena",           12.00},
        {"Pipoca Grande",            17.00},
        {"Refrigerante",              7.50}, // sabor escolhido no balcão
        {"Agua",                      4.00},
        {"Combo P (Pipoca P + Ref.)", 22.00},
        {"Combo G (Pipoca G + Ref.)", 28.00}
    };

    // -- Controle do loop principal --
    // Enquanto rodando == 1, o menu continua aparecendo.
    // Quando o usuário escolhe Sair, rodando vira 0 e o programa encerra.
    int rodando = 1;

    // Variável de opção declarada FORA do loop
    // para que o case 1 consiga alterar opcao = 2
    // e o loop use o novo valor na próxima volta.
    int opcao;

    while (rodando) {

        // -- Array de filmes declarado dentro do loop --
        // Assim tanto o case 1 (ver filmes) quanto o
        // case 2 (comprar) enxergam os mesmos dados.
        struct filme filmes[5] = {
            {"Panico 7",                   "Terror, Comedia Sombria, Suspense",    18, 110, 5.7, 28.00},
            {"Casamento Sangrento",        "Terror, Comedia Sombria, Suspense",    18, 105, 7.0, 28.00},
            {"O Agente Secreto",           "Drama, Suspense Politico, Thriller",   16, 130, 7.2, 26.00},
            {"Hamnet: A Vida Antes de Hamlet", "Drama, Historico",                 14, 115, 7.9, 24.00},
            {"Missao Refugio",             "Acao, Thriller",                       14, 108, 6.2, 24.00}
        };

        // -- Menu principal --
        printf("\n===== Bem-vindo ao CINEMAX! =====\n");
        printf("\n1. Ver filmes em cartaz.");
        printf("\n2. Comprar");
        printf("\n3. Sair");
        printf("\n\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {

            // ------------------------------------------------
            //         CASE 1 — Ver filmes em cartaz
            // ------------------------------------------------
            case 1: {
                printf("\n===== Filmes em Cartaz =====\n");

                for (int i = 0; i < 5; i++) {
                    printf("\n%d. %s\n", i + 1, filmes[i].titulo);
                    printf("Genero: %s | Faixa Etaria: %d | Duracao: %d min | Avaliacao: %.1f\n",
                        filmes[i].genero,
                        filmes[i].faixa_etaria,
                        filmes[i].duracao,
                        filmes[i].avaliacao);
                }

                // Submenu: após ver os filmes, o usuário decide
                int opcao2;
                printf("\n1. Comprar");
                printf("\n2. Sair");
                printf("\n\nEscolha: ");
                scanf("%d", &opcao2);

                if (opcao2 == 1) {
                    // Força o case 2 na próxima volta do while.
                    // O break abaixo encerra ESTA volta,
                    // e o loop recomeça já com opcao = 2.
                    opcao = 2;
                } else {
                    printf("\nAte Logo.\n");
                    rodando = 0; // para o loop
                }

                break;
            }

            // ------------------------------------------------
            //           CASE 2 — Comprar ingresso
            // ------------------------------------------------
            case 2: {
                printf("\n===== Escolha de Filme =====\n");

                for (int i = 0; i < 5; i++) {
                    printf("\n%d. %s\n", i + 1, filmes[i].titulo);
                    printf("Genero: %s | Faixa Etaria: %d | Duracao: %d min | Avaliacao: %.1f\n",
                        filmes[i].genero,
                        filmes[i].faixa_etaria,
                        filmes[i].duracao,
                        filmes[i].avaliacao);
                }

                int escolha_filme;
                printf("\nNumero do filme: ");
                scanf("%d", &escolha_filme);

                // -- Mapa de assentos --
                // 0 = disponível, 1 = ocupado.
                // Grade 6x6: 6 fileiras (A-F), 6 colunas (1-6).
                int assentos[6][6] = {
                    {0,0,0,0,0,0},
                    {0,0,0,0,0,0},
                    {0,0,0,0,0,0},
                    {0,0,0,0,0,0},
                    {0,0,0,0,0,0},
                    {0,0,0,0,0,0}
                };

                char fileiras[6] = {'A','B','C','D','E','F'};

                printf("\n===== Disposicao dos Assentos =====\n");
                printf("   1     2     3     4     5     6\n");

                for (int i = 0; i < 6; i++) {
                    printf("%c  ", fileiras[i]);
                    for (int j = 0; j < 6; j++) {
                        if (assentos[i][j] == 0)
                            printf("[ O ]");
                        else
                            printf("[ X ]");
                    }
                    printf("\n");
                }

                printf("\nO = Disponivel  X = Ocupado\n");

                // -- Leitura e validação do assento --
                char assento_input[5];
                printf("\nDigite o assento desejado (ex: A3): ");
                scanf("%s", assento_input);

                // Converte letra → índice de linha
                // 'A' - 'A' = 0, 'B' - 'A' = 1, etc.
                int linha  = assento_input[0] - 'A';

                // Converte número → índice de coluna
                // '1' - '1' = 0, '3' - '1' = 2, etc.
                int coluna = assento_input[1] - '1';

                if (linha < 0 || linha > 5 || coluna < 0 || coluna > 5) {
                    printf("\nAssento invalido!\n");
                    break;
                }

                if (assentos[linha][coluna] == 1) {
                    printf("\nEsse assento ja esta ocupado!\n");
                    break;
                }

                // Assento válido e livre: marca como ocupado
                assentos[linha][coluna] = 1;
                printf("\nAssento %s reservado com sucesso!\n", assento_input);

                /* Aqui sera a Etapa 7: perguntar quantidade de ingressos,
                   exibir cardápio, adicionar lanches ao carrinho, calcular 
                   total e imprimir resumo do pedido. */

                break;
            }

            // ------------------------------------------------
            //                CASE 3 — Sair
            // ------------------------------------------------
            case 3:
                printf("\nAte Logo.\n");
                rodando = 0;
                break;

            default:
                printf("\nAcao Invalida!\n");
                break;
        }
    }

    return 0;
}
