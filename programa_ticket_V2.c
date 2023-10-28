#include <stdio.h>

// Definições de cores usando sequências de escape ANSI
#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN    "\x1B[36m"

int main() {
    printf(GREEN "Bem-vindo ao Museu Multitemático!\n" RESET);

    int exposicoesSelecionadas[4];
    int totalExposicoes = 0;

    while (totalExposicoes < 4) {
        printf("Escolha a exposição desejada:\n");
        printf("1. " BLUE "100 anos da semana de arte moderna\n" RESET);
        printf("2. " BLUE "150 anos de Santos Dumont\n" RESET);
        printf("3. " BLUE "Jogos olímpicos de Paris 2024\n" RESET);
        printf("4. " BLUE "Tema a ser definido\n" RESET);

        int exposicao;
        printf("Digite o número da exposição desejada (ou 0 para sair): ");
        scanf("%d", &exposicao);

        if (exposicao == 0) {
            break;
        } else if (exposicao < 1 || exposicao > 4) {
            printf(RED "Opção inválida. Por favor, escolha uma exposição de 1 a 4.\n" RESET);
        } else {
            exposicoesSelecionadas[totalExposicoes] = exposicao;
            totalExposicoes++;
        }
    }

    for (int i = 0; i < totalExposicoes; i++) {
        int exposicao = exposicoesSelecionadas[i];
        char categoria;
        int quantidade;
        double valorTotal = 0.0;

        printf(CYAN "Exposição %d - Escolha a categoria de ingresso:\n" RESET, exposicao);
        printf("a. " YELLOW "Inteira\n" RESET);
        printf("b. " YELLOW "Meia entrada\n" RESET);
        printf("c. " YELLOW "Gratuito (para idosos)\n" RESET);

        printf("Digite a categoria de ingresso (a, b ou c) para a Exposição %d: ", exposicao);
        scanf(" %c", &categoria);

        printf("Digite a quantidade de ingressos desejada para a Exposição %d: ", exposicao);
        scanf("%d", &quantidade);

        if (categoria == 'a') {
            valorTotal = quantidade * 20.0;
        } else if (categoria == 'b') {
            valorTotal = quantidade * 10.0;
        } else if (categoria == 'c') {
            valorTotal = 0.0;
        } else {
            printf(RED "Categoria de ingresso inválida.\n" RESET);
        }

        printf("Valor total para a Exposição %d: R$ %.2f\n", exposicao, valorTotal);
    }

    char confirmacao;
    printf("Confirmar a compra (S para sim, N para não): ");
    scanf(" %c", &confirmacao);

    if (confirmacao == 'S' || confirmacao == 's') {
        // Inserir aqui o código para registrar a compra e exibir mensagem de agradecimento
        printf(GREEN "Compra confirmada. Obrigado!\n" RESET);
    } else {
        printf(RED "Compra cancelada.\n" RESET);
    }

    char novaCompra;
    printf("Deseja fazer outra compra (S para sim, N para não): ");
    scanf(" %c", &novaCompra);

    if (novaCompra == 'S' || novaCompra == 's') {
        return 0;
    }
}
