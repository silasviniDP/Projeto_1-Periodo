#include <stdio.h>
#include <string.h>

// Sessao
struct Sessao
{
    char cinema[50];
    char horario[10];
    char idioma[15];
};

// Filme
struct Filme
{
    char nome[100];
    int duracao;
    int classificacao;
    float nota;
    char genero[100];
    char sinopse[500];
    struct Sessao sessoes[25];
};

int main()
{

    struct Filme filmes[5] = {

        {"Panico 7", 110, 18, 5.7, "Terror, suspense", "Sidney enfrenta um novo assassino que ameaca sua familia.", {{"RioMar", "18:00", "Dublado"}, {"RioMar", "20:00", "Legendado"}, {"RioMar", "22:00", "Dublado"}, {"RioMar", "23:30", "Legendado"}, {"RioMar", "01:00", "Dublado"}, {"Recife", "18:30", "Dublado"}, {"Recife", "20:30", "Legendado"}, {"Recife", "22:30", "Dublado"}, {"Recife", "00:00", "Legendado"}, {"Recife", "01:30", "Dublado"}, {"Tacaruna", "17:00", "Dublado"}, {"Tacaruna", "19:00", "Legendado"}, {"Tacaruna", "21:00", "Dublado"}, {"Tacaruna", "23:00", "Legendado"}, {"Tacaruna", "00:30", "Dublado"}, {"Plaza", "18:15", "Dublado"}, {"Plaza", "20:15", "Legendado"}, {"Plaza", "22:15", "Dublado"}, {"Plaza", "23:45", "Legendado"}, {"Plaza", "01:15", "Dublado"}, {"Boa Vista", "17:30", "Dublado"}, {"Boa Vista", "19:30", "Legendado"}, {"Boa Vista", "21:30", "Dublado"}, {"Boa Vista", "23:30", "Legendado"}, {"Boa Vista", "01:00", "Dublado"}}},

        {"Casamento Sangrento 2", 105, 18, 7.0, "Terror, suspense", "Grace agora e cacada por familias poderosas apos sobreviver.", {{"RioMar", "18:00", "Dublado"}, {"RioMar", "20:00", "Legendado"}, {"RioMar", "22:00", "Dublado"}, {"RioMar", "23:30", "Legendado"}, {"RioMar", "01:00", "Dublado"}, {"Recife", "18:30", "Dublado"}, {"Recife", "20:30", "Legendado"}, {"Recife", "22:30", "Dublado"}, {"Recife", "00:00", "Legendado"}, {"Recife", "01:30", "Dublado"}, {"Tacaruna", "17:00", "Dublado"}, {"Tacaruna", "19:00", "Legendado"}, {"Tacaruna", "21:00", "Dublado"}, {"Tacaruna", "23:00", "Legendado"}, {"Tacaruna", "00:30", "Dublado"}, {"Plaza", "18:15", "Dublado"}, {"Plaza", "20:15", "Legendado"}, {"Plaza", "22:15", "Dublado"}, {"Plaza", "23:45", "Legendado"}, {"Plaza", "01:15", "Dublado"}, {"Boa Vista", "17:30", "Dublado"}, {"Boa Vista", "19:30", "Legendado"}, {"Boa Vista", "21:30", "Dublado"}, {"Boa Vista", "23:30", "Legendado"}, {"Boa Vista", "01:00", "Dublado"}}},

        {"O Agente Secreto", 158, 16, 7.2, "Drama, thriller", "Um professor foge do passado e enfrenta caos em Recife.", {{"RioMar", "18:00", "Dublado"}, {"RioMar", "20:00", "Legendado"}, {"RioMar", "22:00", "Dublado"}, {"RioMar", "23:30", "Legendado"}, {"RioMar", "01:00", "Dublado"}, {"Recife", "18:30", "Dublado"}, {"Recife", "20:30", "Legendado"}, {"Recife", "22:30", "Dublado"}, {"Recife", "00:00", "Legendado"}, {"Recife", "01:30", "Dublado"}, {"Tacaruna", "17:00", "Dublado"}, {"Tacaruna", "19:00", "Legendado"}, {"Tacaruna", "21:00", "Dublado"}, {"Tacaruna", "23:00", "Legendado"}, {"Tacaruna", "00:30", "Dublado"}, {"Plaza", "18:15", "Dublado"}, {"Plaza", "20:15", "Legendado"}, {"Plaza", "22:15", "Dublado"}, {"Plaza", "23:45", "Legendado"}, {"Plaza", "01:15", "Dublado"}, {"Boa Vista", "17:30", "Dublado"}, {"Boa Vista", "19:30", "Legendado"}, {"Boa Vista", "21:30", "Dublado"}, {"Boa Vista", "23:30", "Legendado"}, {"Boa Vista", "01:00", "Dublado"}}},

        {"Hamnet", 125, 16, 7.9, "Drama, historico", "A historia que inspirou Shakespeare a escrever Hamlet.", {{"RioMar", "18:00", "Dublado"}, {"RioMar", "20:00", "Legendado"}, {"RioMar", "22:00", "Dublado"}, {"RioMar", "23:30", "Legendado"}, {"RioMar", "01:00", "Dublado"}, {"Recife", "18:30", "Dublado"}, {"Recife", "20:30", "Legendado"}, {"Recife", "22:30", "Dublado"}, {"Recife", "00:00", "Legendado"}, {"Recife", "01:30", "Dublado"}, {"Tacaruna", "17:00", "Dublado"}, {"Tacaruna", "19:00", "Legendado"}, {"Tacaruna", "21:00", "Dublado"}, {"Tacaruna", "23:00", "Legendado"}, {"Tacaruna", "00:30", "Dublado"}, {"Plaza", "18:15", "Dublado"}, {"Plaza", "20:15", "Legendado"}, {"Plaza", "22:15", "Dublado"}, {"Plaza", "23:45", "Legendado"}, {"Plaza", "01:15", "Dublado"}, {"Boa Vista", "17:30", "Dublado"}, {"Boa Vista", "19:30", "Legendado"}, {"Boa Vista", "21:30", "Dublado"}, {"Boa Vista", "23:30", "Legendado"}, {"Boa Vista", "01:00", "Dublado"}}},

        {"Missao Refugio", 107, 16, 6.2, "Acao, thriller", "Um ex-assassino protege uma jovem enquanto foge do passado.", {{"RioMar", "18:00", "Dublado"}, {"RioMar", "20:00", "Legendado"}, {"RioMar", "22:00", "Dublado"}, {"RioMar", "23:30", "Legendado"}, {"RioMar", "01:00", "Dublado"}, {"Recife", "18:30", "Dublado"}, {"Recife", "20:30", "Legendado"}, {"Recife", "22:30", "Dublado"}, {"Recife", "00:00", "Legendado"}, {"Recife", "01:30", "Dublado"}, {"Tacaruna", "17:00", "Dublado"}, {"Tacaruna", "19:00", "Legendado"}, {"Tacaruna", "21:00", "Dublado"}, {"Tacaruna", "23:00", "Legendado"}, {"Tacaruna", "00:30", "Dublado"}, {"Plaza", "18:15", "Dublado"}, {"Plaza", "20:15", "Legendado"}, {"Plaza", "22:15", "Dublado"}, {"Plaza", "23:45", "Legendado"}, {"Plaza", "01:15", "Dublado"}, {"Boa Vista", "17:30", "Dublado"}, {"Boa Vista", "19:30", "Legendado"}, {"Boa Vista", "21:30", "Dublado"}, {"Boa Vista", "23:30", "Legendado"}, {"Boa Vista", "01:00", "Dublado"}}}};

    int escolha;

    printf("\n=== FILMES ===\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d - %s\n", i + 1, filmes[i].nome);
    }

    printf("\nEscolha um filme: ");
    scanf("%d", &escolha);
    escolha--;

    printf("\nFilme: %s\n", filmes[escolha].nome);
    printf("Genero: %s\n", filmes[escolha].genero);
    printf("Duracao: %d min\n", filmes[escolha].duracao);

    printf("\n=== SESSOES ===\n");

    char cinemaAtual[50] = "";
    int opcaoSessao = 1;

    for (int i = 0; i < 25; i++)
    {
        if (strcmp(cinemaAtual, filmes[escolha].sessoes[i].cinema) != 0)
        {
            printf("\nCinema: %s\n", filmes[escolha].sessoes[i].cinema);
            strcpy(cinemaAtual, filmes[escolha].sessoes[i].cinema);
        }

        printf("%d - %s (%s)\n",
               opcaoSessao,
               filmes[escolha].sessoes[i].horario,
               filmes[escolha].sessoes[i].idioma);

        opcaoSessao++;
    }

    return 0;
}
