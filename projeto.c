#include <stdio.h>
#include <locale.h>


//--Structs-------------------------------------------------------
struct filme{
    char titulo[50];
    char genero[50];
    int faixa_etaria;
    int duracao; // Em minutos.
    float avaliacao; // Até 10.
    float preco; // Em reais.
};

struct lanche{
    char nome[40];
    float preco;
};

struct carrinho{
    char filme [50];
    char assento [5]; // Ex: A3.
    int quantidade; // Ingressos.
    int lanches_qtd [6]; // Quantidade de cada lanche (índice = posição no cardápio).
    float preco_total; 
};


int main(){
    setlocale(LC_ALL, "Portuguese");

    struct lanche cardapio[6] = {
        {"Pipoca Pequena", 12.00},
        {"Pipoca Grande", 17.00},
        {"Refrigerante", 7.50}, // A pessoa escolhera as opções de refrigerante, ao pegar no balcão.
        {"Agua", 4.00},
        {"Combo P (Pipoca P + Ref.)", 22.00},
        {"Combo G (Pipoca G + Ref.)", 28.00}
    };

    int rodando = 1;
    while (rodando) {

    printf("\n===== Bem-vindo ao CINEMAX! =====\n");

    //--Opções de Ação.-------------------------------------------
    int opcao;
    int opcao2;

    printf("\n1. Ver filmes em cartaz.");
    printf("\n2. Comprar");
    printf("\n3. Sair");
    printf("\n\nEscolha: ");
    scanf("%d", &opcao);
    
    switch (opcao){
        case 1: {
            //--Filmes em cartaz.----------------------------------
            struct filme filmes[5] = {
                {"Panico 7", "Terror, Comedia Sombria, Suspense", 18, 110, 5.7},
                {"Casamento Sangrento: A Viuva", "Terror, Comedia Sombria, Suspense", 18, 105, 7.0},
                {"O Agente Secreto", "Drama, Suspense Politico, Thriller", 16, 130, 7.2},
                {"Hamnet: A Vida Antes de Hamlet", "Drama, Historico", 14, 115, 7.9},
                {"Missao Refugio", "Acao, Thriller", 14, 108, 6.2}
            };

        printf("\n===== Filmes em Cartazes =====\n");

        for (int i = 0; i < 5; i++){
            printf("\n%d. %s\n", i + 1, filmes[i].titulo);
            printf("Genero: %s | Faixa Etaria: %d | Duracao: %d min | Avaliacao: %.1f\n",
                filmes[i].genero,
                filmes[i].faixa_etaria,
                filmes[i].duracao,
                filmes[i].avaliacao);
            };
            
            //--Escolha após visualização dos filmes-----------------
            printf("\n1. Comprar");
            printf("\n2. Sair");
            printf("\n\nEscolha: ");
            scanf("%d", &opcao2);
            if (opcao2 == 1) {
                opcao = 2;
            } 
            else {
                rodando = 0;
                printf("\nAte Logo.\n");
            }

            break; 
            }

        case 2:{
        //--Compra de ingresso e acompanhamentos-------
        struct filme filmes[5] = {
            {"Panico 7", "Terror, Comedia Sombria, Suspense", 18, 110, 5.7},
            {"Casamento Sangrento: A Viuva", "Terror, Comedia Sombria, Suspense", 18, 105, 7.0},
            {"O Agente Secreto", "Drama, Suspense Politico, Thriller", 16, 130, 7.2},
            {"Hamnet: A Vida Antes de Hamlet", "Drama, Historico", 14, 115, 7.9},
            {"Missao Refugio", "Acao, Thriller", 14, 108, 6.2}
        };
        
        printf("\n====== Escolha de Filme =====\n");
        
        for (int i = 0; i < 5; i++){
            printf("\n%d. %s\n", i + 1, filmes[i].titulo);
            printf("Genero: %s | Faixa Etaria: %d | Duracao: %d min | Avaliacao: %.1f\n",
                filmes[i].genero,
                filmes[i].faixa_etaria,
                filmes[i].duracao,
                filmes[i].avaliacao);
            };
        
        int escolha_filme;

        printf("\nNumero do filme: ");
        scanf("%d", &escolha_filme);

        int assentos[6][6] = {
            // Começa zerado, como se ninguém tivesse selecionado (por que realmente não selecionou).
            {0,0,0,0,0,0},
            {0,0,0,0,0,0},
            {0,0,0,0,0,0},
            {0,0,0,0,0,0},
            {0,0,0,0,0,0},
            {0,0,0,0,0,0}
        };

        char fileiras [6] = {'A', 'B', 'C', 'D', 'E', 'F'};

        printf("\n===== Disposicao dos Assentos =====\n");
        printf("1 2 3 4 5 6\n");

        for (int i = 0; i < 6; i++) { // para cada linha
            printf("%c  ", fileiras[i]); // imprime a letra da fileira
            
        for (int j = 0; j < 6; j++) { // para cada coluna
            if (assentos[i][j] == 0)
                printf("[ O ]");
            else
                printf("[ X ]");
         }

            printf("\n"); // pula linha ao terminar a fileira
        }
                
            printf("\nO = Disponivel  X = Ocupado\n");

            char assento_input[5];
            printf("\nDigite o assento desejado (ex: A3): ");
            scanf("%s", assento_input);

            char fileira_char = assento_input[0];  // pega a letra: 'A'
            int  coluna       = assento_input[1] - '1';  // pega o número: '3' - '1' = 2
            int  linha        = fileira_char - 'A';      // 'A' - 'A' = 0, 'B' - 'A' = 1

            if (linha < 0 || linha > 5 || coluna < 0 || coluna > 5) {
                printf("\nAssento invalido!\n");
            
            break;
        }
        
        if (assentos[linha][coluna] == 1) {
            printf("\nEsse assento ja esta ocupado!\n");

        break;
        }

        // se chegou aqui, o assento é válido e está livre
        assentos[linha][coluna] = 1;
        printf("\nAssento %s reservado com sucesso!\n", assento_input);

        break;
        }

        case 3:
        printf("\nAte Logo.\n"); // Saída do Site
        rodando = 0;
        break;
        
        default:
        printf("\nAcao Invalida!\n"); // Resposta diferente das alternativas
        break;
    };
    
    }
    
    return 0;
};
