#include "menus.h"
#include <stdio.h>

int menu_principal()
{
    int opcao = 0;
    do
    {
        printf("\n== Menu principal ==\n");
        printf("1 - Menu aluno\n");
        printf("2 - Menu professor\n");
        printf("3 - Sair\n");
        printf("Opcao > ");
        scanf("%d", &opcao);
        getchar();
        if (opcao > 0 && opcao < 4)
        {
            return opcao;
        }
        printf("Opcao invalida! Tente novamente\n\n");

    } while (1);
}

int menu_crud_aluno()
{
    int opcao = 0;
    do
    {
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
            return opcao;
        }
        printf("Opcao invalida! Tente novamente\n\n");

    } while (1);
}

int menu_crud_professor()
{
    int opcao = 0;
    do
    {
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
            return opcao;
        }
        printf("Opcao invalida! Tente novamente\n\n");

    } while (1);
}