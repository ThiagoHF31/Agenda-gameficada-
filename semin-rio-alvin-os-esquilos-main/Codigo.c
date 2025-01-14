#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Cores para o terminal
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

// Estrutura de uma tarefa
typedef struct Tarefa {
    char descricao[100];
    int xp;
    int tempoEstimado;
    int tempoReal;  
    struct Tarefa* proximo;
} Tarefa;

// Estruturas para a fila de tarefas e lista de concluídas
typedef struct Fila {
    Tarefa* frente;
    Tarefa* traseira;
} Fila;

typedef struct ListaConcluidas {
    Tarefa* inicio;
} ListaConcluidas;

// Funções para manipulação das tarefas
Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->frente = fila->traseira = NULL;
    return fila;
}

ListaConcluidas* criarListaConcluidas() {
    ListaConcluidas* lista = (ListaConcluidas*)malloc(sizeof(ListaConcluidas));
    lista->inicio = NULL;
    return lista;
}

int verificarTarefaExistente(Fila* fila, char* descricao) {
    Tarefa* atual = fila->frente;
    while (atual != NULL) {
        if (strcmp(atual->descricao, descricao) == 0) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

void adicionarTarefaFila(Fila* fila, char* descricao, int tempoEstimado) {
    if (verificarTarefaExistente(fila, descricao)) {
        printf(RED "Tarefa já existente! Não foi adicionada.\n" RESET);
        return;
    }

    Tarefa* novaTarefa = (Tarefa*)malloc(sizeof(Tarefa));
    strcpy(novaTarefa->descricao, descricao);
    novaTarefa->xp = 0;
    novaTarefa->tempoEstimado = tempoEstimado;
    novaTarefa->tempoReal = 0;
    novaTarefa->proximo = NULL;

    if (fila->traseira == NULL) {
        fila->frente = fila->traseira = novaTarefa;
    } else {
        fila->traseira->proximo = novaTarefa;
        fila->traseira = novaTarefa;
    }

    printf(GREEN "Tarefa adicionada com sucesso!\n" RESET);
}

void exibirTarefas(Fila* fila) {
    Tarefa* atual = fila->frente;
    if (atual == NULL) {
        printf(RED "Nenhuma tarefa pendente.\n" RESET);
        return;
    }

    printf(YELLOW "------------------------------------------------------------\n" RESET);
    printf(BLUE "| Nº | Descrição                  | XP    | Tempo Estimado | Tempo Real      |\n" RESET);
    printf(YELLOW "------------------------------------------------------------\n" RESET);
    int i = 1;
    while (atual != NULL) {
        printf("| %-2d | %-25s | %-5d | %-13d | %-13d |\n", i++, atual->descricao, atual->xp, atual->tempoEstimado, atual->tempoReal);
        atual = atual->proximo;
    }
    printf(YELLOW "------------------------------------------------------------\n" RESET);
}

void concluirTarefa(Fila* fila, ListaConcluidas* concluidas, int* xpTotal) {
    if (fila->frente == NULL) {
        printf(RED "Nenhuma tarefa para concluir.\n" RESET);
        return;
    }

    exibirTarefas(fila);

    int numero;
    printf("Digite o número da tarefa que deseja marcar como concluída: ");
    scanf("%d", &numero);
    getchar();

    Tarefa *anterior = NULL, *atual = fila->frente;
    for (int i = 1; i < numero && atual != NULL; i++) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf(RED "Tarefa inválida.\n" RESET);
        return;
    }

    printf("Concluiu o tempo estimado? (s/n): ");
    char resposta;
    scanf(" %c", &resposta);
    getchar();

    if (resposta == 's' || resposta == 'S') {
        atual->tempoReal = atual->tempoEstimado;
    } else {
        printf("Digite o tempo real dedicado à tarefa (em minutos): ");
        scanf("%d", &atual->tempoReal);
        getchar();
    }

    mostrarProgresso(5); // Simulação de conclusão da tarefa

    atual->xp += atual->tempoReal / 10;
    *xpTotal += atual->xp;

    if (anterior == NULL) {
        fila->frente = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    if (fila->traseira == atual) {
        fila->traseira = anterior;
    }

    atual->proximo = concluidas->inicio;
    concluidas->inicio = atual;

    printf(GREEN "Tarefa concluída!\n" RESET);
    mostrarRecompensa(*xpTotal);
}

void exibirTarefasConcluidas(ListaConcluidas* concluidas) {
    Tarefa* atual = concluidas->inicio;
    if (atual == NULL) {
        printf(RED "Nenhuma tarefa concluída.\n" RESET);
        return;
    }

    printf(YELLOW "------------------------------------------------------------\n" RESET);
    printf(BLUE "| Descrição                    | XP    | Tempo Estimado  | Tempo Real      |\n" RESET);
    printf(YELLOW "------------------------------------------------------------\n" RESET);
    while (atual != NULL) {
        printf("| %-25s | %-5d | %-13d | %-13d |\n", atual->descricao, atual->xp, atual->tempoEstimado, atual->tempoReal);
        atual = atual->proximo;
    }
    printf(YELLOW "------------------------------------------------------------\n" RESET);
}

void mostrarProgresso(int tempo) {
    printf(CYAN "Concluindo tarefa...\n" RESET);
    for (int i = 0; i <= 100; i += 10) {
        printf("\rProgresso: [%-10s] %d%%", "##########" + 10 - (i / 10), i);
        fflush(stdout);
        Sleep(tempo * 10);
    }
    printf("\n");
}

void mostrarRecompensa(int xpTotal) {
    if (xpTotal >= 10 && xpTotal < 50) {
        printf(YELLOW "Parabéns! Você alcançou o nível Bronze! 🥉\n" RESET);
    } else if (xpTotal >= 50 && xpTotal < 100) {
        printf(GREEN "Incrível! Você alcançou o nível Prata! 🥈\n" RESET);
    } else if (xpTotal >= 100) {
        printf(CYAN "Fantástico! Você alcançou o nível Ouro! 🥇\n" RESET);
    }
}

void exibirXP(int xpTotal) {
    printf(GREEN "XP Total: " RESET);
    for (int i = 0; i < xpTotal / 10; i++) {
        printf("■");
    }
    printf(" %d XP\n", xpTotal);
}

void animacaoInicial() {
    printf(YELLOW "Carregando" RESET);
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        Sleep(500);
    }
    printf(GREEN "\nBem-vindo ao Gerenciador de Tarefas XP!\n" RESET);
}

void exibirMenu() {
    printf("\n");
    printf(YELLOW "==========================================" RESET "\n");
    printf(GREEN " Bem-vindo ao Gerenciador de Tarefas XP! " RESET "\n");
    printf(YELLOW "==========================================" RESET "\n");
    printf("1. Adicionar Tarefa\n");
    printf("2. Exibir Tarefas\n");
    printf("3. Marcar Tarefa como Concluída\n");
    printf("4. Ver Tarefas Concluídas\n");
    printf("5. Ver XP Total\n");
    printf("6. Sair\n");
    printf("Escolha uma opção: ");
    printf("\n");
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Fila* tarefasPendentes = criarFila();
    ListaConcluidas* tarefasConcluidas = criarListaConcluidas();
    int xpTotal = 0;

    animacaoInicial();

    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                {
                    char descricao[100];
                    int tempoEstimado;
                    printf("Digite a descrição da tarefa: ");
                    fgets(descricao, sizeof(descricao), stdin);
                    descricao[strcspn(descricao, "\n")] = '\0';
                    printf("Digite o tempo estimado (em minutos): ");
                    scanf("%d", &tempoEstimado);
                    getchar();
                    adicionarTarefaFila(tarefasPendentes, descricao, tempoEstimado);
                }
                break;

            case 2:
                exibirTarefas(tarefasPendentes);
                break;

            case 3:
                concluirTarefa(tarefasPendentes, tarefasConcluidas, &xpTotal);
                break;

            case 4:
                exibirTarefasConcluidas(tarefasConcluidas);
                break;

            case 5:
                exibirXP(xpTotal);
                break;

            case 6:
                printf(MAGENTA "Saindo do programa...\n" RESET);
                break;

            default:
                printf(RED "Opção inválida. Tente novamente.\n" RESET);
        }
    } while (opcao != 6);

    return 0;
}
