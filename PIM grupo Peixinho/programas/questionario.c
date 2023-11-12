#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_NOME_VISITANTE 100
#define MAX_COMENTARIO 1000
#define MAX_MOTIVO_VISITA 100

// Struct para armazenar respostas do questionário
struct Resposta {
    char nome_visitante[MAX_NOME_VISITANTE];
    int satisfacao_exposicao;
    char comentario[MAX_COMENTARIO];
    char motivo_visita[MAX_MOTIVO_VISITA];
    bool aceitou_termos;
    time_t data_hora_resposta;
};

// Função para exibir o menu e permitir que o funcionário escolha a opção
int exibir_menu() {
    int escolha;
    printf("\nMenu:\n");
    printf("1. Coletar respostas do visitante\n");
    printf("2. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);
    return escolha;
}

// Função para coletar respostas do questionário
void coletar_respostas(int num_respostas, struct Resposta *respostas) {
    printf("Bem-vindo a Brasil Game Show (BGS)!\n");
    printf("Avalie sua satisfacao com a exposicao como um todo de 1 a 5, onde 1 e muito insatisfeito e 5 e muito satisfeito.\n");

    for (int i = 0; i < num_respostas; i++) {
        printf("Funcionario, preencha as informações para o Visitante %d:\n", i + 1);
        printf("Nome do visitante: ");
        scanf(" %[^\n]s", respostas[i].nome_visitante);

        do {
            printf("Satisfacao com a exposicao (1-5): ");
            scanf("%d", &respostas[i].satisfacao_exposicao);
        } while (respostas[i].satisfacao_exposicao < 1 || respostas[i].satisfacao_exposicao > 5);

        printf("Comentarios (opcional): ");
        scanf(" %[^\n]s", respostas[i].comentario);

        printf("Motivo da visita: ");
        scanf(" %[^\n]s", respostas[i].motivo_visita);

        char aceitou_termos_input[2];
        do {
            printf("Voce aceita os termos da LGPD? (S - Sim, N - Nao): ");
            scanf("%s", aceitou_termos_input);
        } while (strcmp(aceitou_termos_input, "S") != 0 && strcmp(aceitou_termos_input, "s") != 0 &&
                 strcmp(aceitou_termos_input, "N") != 0 && strcmp(aceitou_termos_input, "n") != 0);

        respostas[i].aceitou_termos = (strcmp(aceitou_termos_input, "S") == 0 || strcmp(aceitou_termos_input, "s") == 0);

        // Registrar a data e hora da resposta
        respostas[i].data_hora_resposta = time(NULL);
    }
}

// Função para salvar respostas em um arquivo CSV
void salvar_respostas_csv(int num_respostas, struct Resposta *respostas) {
    FILE *arquivo_csv = fopen("respostas.csv", "w");
    if (arquivo_csv == NULL) {
        perror("Erro ao criar o arquivo 'respostas.csv'");
        exit(1);
    }

    fprintf(arquivo_csv, "Nome do Visitante,Satisfacao com a Exposicao,Comentario,Motivo da Visita,Aceitou Termos LGPD,Data e Hora\n");

    for (int i = 0; i < num_respostas; i++) {
        fprintf(arquivo_csv, "%s,%d,%s,%s,%s,%s\n", respostas[i].nome_visitante,
                respostas[i].satisfacao_exposicao, respostas[i].comentario,
                respostas[i].motivo_visita, (respostas[i].aceitou_termos) ? "Sim" : "Não",
                asctime(localtime(&respostas[i].data_hora_resposta)));
    }

    fclose(arquivo_csv);

    printf("Respostas salvas em 'respostas.csv'.\n");
}

int main() {
    int num_respostas;
    printf("Quantos visitantes responderao ao questionario? ");
    scanf("%d", &num_respostas);

    struct Resposta *respostas = (struct Resposta *)malloc(num_respostas * sizeof(struct Resposta));
    if (respostas == NULL) {
        perror("Erro ao alocar memoria para respostas");
        return 1;
    }

    int escolha;
    do {
        escolha = exibir_menu();
        switch (escolha) {
            case 1:
                coletar_respostas(num_respostas, respostas);
                salvar_respostas_csv(num_respostas, respostas);
                break;
            case 2:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (escolha != 2);

    free(respostas);

    return 0;
}
