#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 10
#define MAX_NOME 100

// Função para processar as informações
void processar_informacoes(int matriculas[], char nomes[][MAX_NOME], int tamanho) {
    printf("Resultados:\n");
    for (int i = tamanho - 1; i >= 0; i--) {
        int matricula = matriculas[i];

        // Processar as informações
        if (matricula % 2 == 1) {
            int soma_numeros = 0;
            int temp = matricula;

            // Calcular a soma dos dígitos da matrícula
            while (temp != 0) {
                soma_numeros += temp % 10;
                temp /= 10;
            }

            int resultado = soma_numeros - matricula;
            printf("Soma dos números da matrícula (%d) - Matrícula (%d) = %d\n", soma_numeros, matricula, resultado);
        } else {
            printf("Matrícula: %d - Aluno: %s\n", matricula, nomes[i]);
        }
    }

    printf("\nPrimeiro nome: %s\n", nomes[tamanho - 1]);
    printf("Último nome: %s\n", nomes[0]);
}

int main() {
    int matriculas[MAX_ALUNOS];
    char nomes[MAX_ALUNOS][MAX_NOME];
    int n;

    // Solicitar a quantidade de alunos
    printf("Digite a quantidade de alunos (no máximo %d): ", MAX_ALUNOS);
    scanf("%d", &n);

    // Limpar o buffer do teclado
    while (getchar() != '\n');

    // Solicitar as matrículas e nomes dos alunos
    printf("Digite as matrículas e nomes dos alunos:\n");
    for (int i = 0; i < n; i++) {
        printf("Aluno %d:\n", i + 1);

        // Solicitar a matrícula do aluno
        printf("Matrícula: ");
        scanf("%d", &matriculas[i]);

        // Limpar o buffer do teclado
        while (getchar() != '\n');

        // Solicitar o nome do aluno
        printf("Nome: ");
        fgets(nomes[i], MAX_NOME, stdin);

        // Remover o caractere de nova linha do final do nome
        nomes[i][strcspn(nomes[i], "\n")] = '\0';
    }

    // Chamar a função para processar as informações
    processar_informacoes(matriculas, nomes, n);

    return 0;
}

/*
Trabalho desenvolvido por:

Gabriel de Morais Rocha
Gabriel Santos Santana
Vinícius Amorim Bernardi
*/