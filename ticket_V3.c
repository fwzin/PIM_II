#include <stdio.h>
#include <time.h>
#include <stdbool.h> // Para usar o tipo de dado 'bool'

#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN    "\x1B[36m"

// Função para calcular o valor total da compra
double calcularValorTotal(char categoria, int quantidade) {
    double valorTotal = 0.0;

    switch (categoria) {
        case 'a':
            valorTotal = quantidade * 20.0;
            break;
        case 'b':
            valorTotal = quantidade * 10.0;
            break;
        case 'c':
            valorTotal = 0.0;
            break;
        default:
            printf(RED "Categoria de ingresso inválida.\n" RESET);
            break;
    }

    return valorTotal;
}

// Função para obter a confirmação do usuário
bool obterConfirmacao() {
    char confirmacao;
    printf("Confirmar a compra (S para sim, N para não): ");
    scanf(" %c", &confirmacao);

    return (confirmacao == 'S' || confirmacao == 's');
}

int main() {
    printf(GREEN "Bem-vindo ao Museu Multitemático!\n" RESET);

    char funcionario[50];

    printf("Digite o nome do funcionário que está vendendo os ingressos: ");
    scanf("%s", funcionario);

    char categoria;
    int quantidade;
    double valorTotalCompra = 0.0;

    do {
        printf(CYAN "Escolha a categoria de ingresso:\n" RESET);
        printf("a. " YELLOW "Inteira\n" RESET);
        printf("b. " YELLOW "Meia entrada\n" RESET);
        printf("c. " YELLOW "Gratuito (para idosos)\n" RESET);

        printf("Digite a categoria de ingresso (a, b ou c): ");
        scanf(" %c", &categoria);

        printf("Digite a quantidade de ingressos desejada: ");
        scanf("%d", &quantidade);

        if (quantidade <= 0) {
            printf(RED "A quantidade de ingressos deve ser maior que zero.\n" RESET);
            continue;
        }

        valorTotalCompra = calcularValorTotal(categoria, quantidade);

        time_t t;
        struct tm* tm_info;
        char dataHora[100];
        time(&t);
        tm_info = localtime(&t);
        strftime(dataHora, sizeof(dataHora), "%d/%m/%Y %H:%M:%S", tm_info);

        if (obterConfirmacao()) {
            FILE *reciboArquivo = fopen("recibo.txt", "a");

            if (reciboArquivo == NULL) {
                printf(RED "Erro ao abrir o arquivo de recibo.\n" RESET);
            } else {
                fprintf(reciboArquivo, "Recibo da Compra:\n");
                fprintf(reciboArquivo, "Data e Hora da Compra: %s\n", dataHora);
                fprintf(reciboArquivo, "Funcionário: %s\n", funcionario);
                fprintf(reciboArquivo, "Categoria de Ingresso: %c\n", categoria);
                fprintf(reciboArquivo, "Quantidade de Ingressos: %d\n", quantidade);
                fprintf(reciboArquivo, "Valor Total da Compra: R$ %.2f\n", valorTotalCompra);
                fprintf(reciboArquivo, "Compra registrada com sucesso. Obrigado!\n\n");

                fclose(reciboArquivo);

                printf("Recibo da compra salvo em 'recibo.txt'.\n");
            }
        } else {
            printf("Compra cancelada.\n");
        }

        printf("Deseja fazer outra compra (S para sim, N para não): ");
        char novaCompra;
        scanf(" %c", &novaCompra);

        if (novaCompra != 'S' && novaCompra != 's') {
            break;
        }
    } while (true);

return 0;
}
