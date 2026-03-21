#include <stdio.h>
#include <locale.h>


/*Váriaveis para os Filmes em Cartaz.*/
struct filme{
    char titulo[50];
    char genero[30];
    int faixa_etaria;
    int duracao;
    float avaliacao;
};


int main(){
    setlocale(LC_ALL, "Portuguese");

    printf("\n===== Bem-vindo ao CINEMAX! =====\n");

    /*Opções de Ação.*/
    int opcao;

    printf("\n1. Ver filmes em cartaz.");
    printf("\n2. Sair");
    printf("\n\nEscolha:");
    scanf("%d", &opcao);
    
    switch (opcao){
        case 1: {
            /*Filmes em cartaz.*/
            struct filme filmes[5] = {
                {"Pânico 7", "Terror, Comédia Sombria, Suspense", 18, 110, 5.7},
                {"Casamento Sangrento: A Viúva", "Terror, Comédia Sombria, Suspense", 18, 105, 7.0},
                {"O Agente Secreto", "Drama, Suspense Político, Thriller", 16, 130, 7.2},
                {"Hamnet: A Vida Antes de Hamlet", "Drama, Histórico", 14, 115, 7.9},
                {"Missão Refúgio", "Ação, Thriller", 14, 108, 6.2}
            };

        printf("\n===== Filmes em Cartazes =====\n");

        for (int i = 0; i < 5; i++){
            printf("\n%d. %s\n", i + 1, filmes[i].titulo);
            printf("Gênero: %s | Faixa Etária: %d | Duração: %d min | Avaliação: %.1f\n",
                filmes[i].genero,
                filmes[i].faixa_etaria,
                filmes[i].duracao,
                filmes[i].avaliacao);
            }

            /*Mapa dos assentos da sessão*/
            
            break; 
        }
        
        case 2:
        /*Quando o úsuario sair do Site.*/
        printf("\nAté Logo.\n");
        break;
        
        default:
        /*Caso o úsuario digite algum valor diferente de 1 ou 2.*/
        printf("\nAção Inválida!\n");
    };
    
    return 0;
}
