#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* =========================================================
   ESTRUTURAS DE DADOS
   ========================================================= */

typedef struct {
    char numero[20];
    char nome[60];
    char validade[6];
    char cvv[4];
    int  parcelas;
    double valor;
} CartaoCredito;

typedef struct {
    char numero[20];
    char nome[60];
    char validade[6];
    char cvv[4];
    double valor;
} CartaoDebito;

typedef struct {
    char chave[80];
    char txid[40];
    double valor;
    int   expira_em; /* segundos */
} Pix;

/* =========================================================
   UTILITÁRIOS
   ========================================================= */

void limpar_tela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar() {
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();
}

void formatar_cartao(char *num) {
    /* Remove espaços já existentes e reformata em grupos de 4 */
    char limpo[20] = {0};
    int j = 0;
    for (int i = 0; num[i] && j < 16; i++) {
        if (num[i] >= '0' && num[i] <= '9')
            limpo[j++] = num[i];
    }
    snprintf(num, 20, "%c%c%c%c %c%c%c%c %c%c%c%c %c%c%c%c",
        limpo[0], limpo[1], limpo[2],  limpo[3],
        limpo[4], limpo[5], limpo[6],  limpo[7],
        limpo[8], limpo[9], limpo[10], limpo[11],
        limpo[12],limpo[13],limpo[14], limpo[15]);
}

int validar_validade(const char *val) {
    /* Formato esperado: MM/AA */
    if (strlen(val) != 5 || val[2] != '/') return 0;
    int mes = (val[0]-'0')*10 + (val[1]-'0');
    return (mes >= 1 && mes <= 12);
}

int validar_numero_cartao(const char *num) {
    int digitos = 0;
    for (int i = 0; num[i]; i++)
        if (num[i] >= '0' && num[i] <= '9') digitos++;
    return digitos == 16;
}

void gerar_txid(char *txid) {
    srand((unsigned)time(NULL));
    const char hex[] = "0123456789abcdef";
    for (int i = 0; i < 32; i++)
        txid[i] = hex[rand() % 16];
    txid[32] = '\0';
}

void gerar_chave_pix(char *chave) {
    /* Simula uma chave aleatória no formato UUID */
    char txid[40];
    gerar_txid(txid);
    snprintf(chave, 80, "%c%c%c%c%c%c%c%c-%c%c%c%c-%c%c%c%c-%c%c%c%c-%c%c%c%c%c%c%c%c%c%c%c%c",
        txid[0],txid[1],txid[2],txid[3],txid[4],txid[5],txid[6],txid[7],
        txid[8],txid[9],txid[10],txid[11],
        txid[12],txid[13],txid[14],txid[15],
        txid[16],txid[17],txid[18],txid[19],
        txid[20],txid[21],txid[22],txid[23],txid[24],txid[25],txid[26],txid[27],txid[28],txid[29],txid[30],txid[31]);
}

/* =========================================================
   PROCESSAMENTO DE PAGAMENTOS
   ========================================================= */

int processar_credito(CartaoCredito *c) {
    printf("\n[Processando pagamento com cartao de credito...]\n");

    if (!validar_numero_cartao(c->numero)) {
        printf("ERRO: Numero de cartao invalido.\n");
        return 0;
    }
    if (!validar_validade(c->validade)) {
        printf("ERRO: Validade invalida. Use MM/AA.\n");
        return 0;
    }
    if (strlen(c->cvv) < 3) {
        printf("ERRO: CVV invalido.\n");
        return 0;
    }

    double parcela = c->valor / c->parcelas;
    printf("\n--- COMPROVANTE DE CREDITO ---\n");
    printf("Titular : %s\n", c->nome);
    printf("Cartao  : **** **** **** %c%c%c%c\n",
        c->numero[strlen(c->numero)-4], c->numero[strlen(c->numero)-3],
        c->numero[strlen(c->numero)-2], c->numero[strlen(c->numero)-1]);
    printf("Valor   : R$ %.2f\n", c->valor);
    printf("Parcelas: %dx de R$ %.2f\n", c->parcelas, parcela);
    printf("Status  : APROVADO\n");
    printf("------------------------------\n");
    return 1;
}

int processar_debito(CartaoDebito *d) {
    printf("\n[Processando pagamento com cartao de debito...]\n");

    if (!validar_numero_cartao(d->numero)) {
        printf("ERRO: Numero de cartao invalido.\n");
        return 0;
    }
    if (!validar_validade(d->validade)) {
        printf("ERRO: Validade invalida. Use MM/AA.\n");
        return 0;
    }

    printf("\n--- COMPROVANTE DE DEBITO ---\n");
    printf("Titular : %s\n", d->nome);
    printf("Cartao  : **** **** **** %c%c%c%c\n",
        d->numero[strlen(d->numero)-4], d->numero[strlen(d->numero)-3],
        d->numero[strlen(d->numero)-2], d->numero[strlen(d->numero)-1]);
    printf("Valor   : R$ %.2f\n", d->valor);
    printf("Debito  : Imediato\n");
    printf("Status  : APROVADO\n");
    printf("-----------------------------\n");
    return 1;
}

int processar_pix(Pix *p) {
    printf("\n[Gerando cobranca Pix...]\n");

    gerar_txid(p->txid);
    gerar_chave_pix(p->chave);
    p->expira_em = 900; /* 15 minutos */

    printf("\n--- COBRANCA PIX ---\n");
    printf("Valor   : R$ %.2f\n", p->valor);
    printf("TxID    : %s\n", p->txid);
    printf("Chave   : %s\n", p->chave);
    printf("Expira  : %d minutos\n", p->expira_em / 60);
    printf("\n[QR Code simulado]\n");
    printf("+--------------------------+\n");
    printf("|  ##  ##  ##  ##  ##  ##  |\n");
    printf("|  ##      ##      ##  ##  |\n");
    printf("|  ##  ##  ##  ##  ##  ##  |\n");
    printf("|      ##      ##      ##  |\n");
    printf("|  ##  ##  ##  ##  ##  ##  |\n");
    printf("+--------------------------+\n");
    printf("\nAguardando pagamento...\n");
    printf("Status  : PENDENTE\n");
    printf("--------------------\n");
    return 1;
}

/* =========================================================
   MENUS
   ========================================================= */

void menu_credito(double valor) {
    CartaoCredito c;
    c.valor = valor;

    printf("\n=== PAGAMENTO COM CARTAO DE CREDITO ===\n");
    printf("Numero do cartao: ");
    scanf("%19s", c.numero);
    formatar_cartao(c.numero);

    printf("Nome no cartao : ");
    scanf(" %59[^\n]", c.nome);

    printf("Validade (MM/AA): ");
    scanf("%5s", c.validade);

    printf("CVV            : ");
    scanf("%3s", c.cvv);

    printf("Parcelas (1-12): ");
    scanf("%d", &c.parcelas);
    if (c.parcelas < 1 || c.parcelas > 12) c.parcelas = 1;

    processar_credito(&c);
}

void menu_debito(double valor) {
    CartaoDebito d;
    d.valor = valor;

    printf("\n=== PAGAMENTO COM CARTAO DE DEBITO ===\n");
    printf("Numero do cartao: ");
    scanf("%19s", d.numero);
    formatar_cartao(d.numero);

    printf("Nome no cartao : ");
    scanf(" %59[^\n]", d.nome);

    printf("Validade (MM/AA): ");
    scanf("%5s", d.validade);

    printf("CVV            : ");
    scanf("%3s", d.cvv);

    processar_debito(&d);
}

void menu_pix(double valor) {
    Pix p;
    p.valor = valor;

    printf("\n=== PAGAMENTO VIA PIX ===\n");
    processar_pix(&p);
}

/* =========================================================
   PROGRAMA PRINCIPAL
   ========================================================= */

int main() {
    int opcao;
    double valor;

    printf("========================================\n");
    printf("        SISTEMA DE PAGAMENTO v1.0       \n");
    printf("========================================\n");
    printf("Valor da compra: R$ ");
    scanf("%lf", &valor);

    if (valor <= 0) {
        printf("Valor invalido.\n");
        return 1;
    }

    printf("\nEscolha a forma de pagamento:\n");
    printf("  [1] Cartao de Credito\n");
    printf("  [2] Cartao de Debito\n");
    printf("  [3] Pix\n");
    printf("  [0] Sair\n");
    printf("\nOpcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: menu_credito(valor); break;
        case 2: menu_debito(valor);  break;
        case 3: menu_pix(valor);     break;
        case 0: printf("Saindo...\n"); break;
        default: printf("Opcao invalida.\n");
    }

    return 0;
}
