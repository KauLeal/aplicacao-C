#include "menus.h"
#include <stdio.h>

int menu_principal()
{
    int opcao = 0;
    do
    {
        // Exibe o menu principal com as opções disponíveis
        printf("\n== Menu principal ==\n");
        printf("1 - Menu aluno\n");
        printf("2 - Menu professor\n");
        printf("3 - Menu turma\n");
        printf("4 - Sair\n");
        printf("Opcao > ");
        scanf("%d", &opcao);
        getchar();
        if (opcao > 0 && opcao < 5)
        {
            return opcao; // Retorna a opção escolhida pelo usuário
        }
        printf("Opcao invalida! Tente novamente\n\n"); // Mensagem de erro para opção inválida

    } while (1); // Loop infinito para repetir o menu até uma opção válida ser escolhida
}


int menu_crud_aluno()
{
    int opcao = 0;
    do
    {
        // Exibe o menu de aluno com as opções disponíveis
        printf("\n== Menu aluno==\n");
        printf("1 - Criar aluno\n");
        printf("2 - Ler aluno\n");
        printf("3 - Atualizar aluno\n");
        printf("4 - Deletar aluno\n");
        printf("5 - Voltar menu anterior\n");
        printf("Opcao > ");
        scanf("%d", &opcao);
        getchar();
        if (opcao > 0 && opcao < 6)
        {
            return opcao; // Retorna a opção escolhida pelo usuário
        }
        printf("Opcao invalida! Tente novamente\n\n"); // Mensagem de erro para opção inválida

    } while (1); // Loop infinito para repetir o menu até uma opção válida ser escolhida
}

int menu_crud_professor()
{
    int opcao = 0;
    do
    {
        // Exibe o menu de professor com as opções disponíveis
        printf("\n== Menu professor==\n");
        printf("1 - Criar professor\n");
        printf("2 - Ler professor\n");
        printf("3 - Atualizar professor\n");
        printf("4 - Deletar professor\n");
        printf("5 - Voltar menu anterior\n");
        printf("Opcao > ");
        scanf("%d", &opcao);
        getchar();
        if (opcao > 0 && opcao < 6)
        {
            return opcao;  // Retorna a opção escolhida pelo usuário
        }
        printf("Opcao invalida! Tente novamente\n\n");  // Mensagem de erro para opção inválida

    } while (1); // Loop infinito para repetir o menu até uma opção válida ser escolhida
}

int menu_crud_turma()
{
    int opcao = 0;
    do
    {
        // Exibe o menu de turma com as opções disponíveis
        printf("\n== Menu turma==\n");
        printf("1 - Criar turma\n");
        printf("2 - Ler turma\n");
        printf("3 - Atualizar turma\n");
        printf("4 - Deletar turma\n");
        printf("5 - Voltar menu anterior\n");
        printf("Opcao > ");
        scanf("%d", &opcao);
        getchar();
        if (opcao > 0 && opcao < 6)
        {
            return opcao;  // Retorna a opção escolhida pelo usuário
        }
        printf("Opcao invalida! Tente novamente\n\n");  // Mensagem de erro para opção inválida

    } while (1); // Loop infinito para repetir o menu até uma opção válida ser escolhida
}