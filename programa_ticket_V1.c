#include <stdio.h>

int main() {
    printf("Bem-vindo ao Museu Multitemático!\n");

    int exposicoesSelecionadas[4]; // Um array para armazenar as exposições selecionadas
    int totalExposicoes = 0; // Para acompanhar o número de exposições selecionadas

    while (totalExposicoes <= 4) { // Permite selecionar até 4 exposições
        printf("Escolha a exposição desejada:\n");
        printf("1. 100 anos da semana de arte moderna\n");
        printf("2. 150 anos de Santos Dumont\n");
        printf("3. Jogos olímpicos de Paris 2024\n");
        printf("4. 19 anos da BGS\n");

        // Solicitar exposição (1 a 4)
        int exposicao;
        printf("Digite o número da exposição desejada (ou 0 para sair): ");
        scanf("%d", &exposicao);

        if (exposicao == 0) {
            break; // Sai do loop se o cliente escolher 0
        } else if (exposicao < 1 || exposicao > 4) {
            printf("Opção inválida. Por favor, escolha uma exposição de 1 a 4.\n");
        } else {
            // Armazena a exposição selecionada no array
            exposicoesSelecionadas[totalExposicoes] = exposicao;
            totalExposicoes++;
        }
    }

    // Agora, incluímos o código para a compra de ingressos para cada exposição selecionada
    for (int i = 0; i < totalExposicoes; i++) {
        int exposicao = exposicoesSelecionadas[i];
        char categoria;
        int quantidade;
        double valorTotal = 0.0; // Inicializamos com zero

        printf("Exposição %d - Escolha a categoria de ingresso:\n", exposicao);
        printf("a. Inteira\n");
        printf("b. Meia entrada\n");
        printf("c. Gratuito (para idosos)\n");

        // Solicitar categoria (a, b ou c)
        printf("Digite a categoria de ingresso (a, b ou c) para a Exposição %d: ", exposicao);
        scanf(" %c", &categoria);

        // Solicitar quantidade de ingressos
        printf("Digite a quantidade de ingressos desejada para a Exposição %d: ", exposicao);
        scanf("%d", &quantidade);

        // Calcular valor total com base na categoria e quantidade de ingressos
        if (categoria == 'a') { // Inteira
            valorTotal = quantidade * 20.0; // Preço fictício de R$20 por ingresso inteira
        } else if (categoria == 'b') { // Meia entrada
            valorTotal = quantidade * 10.0; // Preço fictício de R$10 por ingresso meia entrada
        } else if (categoria == 'c') { // Gratuito (idosos)
            valorTotal = 0.0; // Ingressos para idosos são gratuitos
        } else {
            printf("Categoria de ingresso inválida.\n");
        }

        printf("Valor total para a Exposição %d: R$ %.2f\n", exposicao, valorTotal);
    }

char confirmacao;
    printf("Confirmar a compra (S para sim, N para não): ");
    scanf(" %c", &confirmacao);

    if (confirmacao == 'S' || confirmacao == 's') {
        // Inserir aqui o código para registrar a compra e exibir mensagem de agradecimento
    } else {
        printf("Compra cancelada.\n");
    }

    char novaCompra;
    printf("Deseja fazer outra compra (S para sim, N para não): ");
    scanf(" %c", &novaCompra);

    if (novaCompra == 'S' || novaCompra == 's') {
    return 0;}
}
