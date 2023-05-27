#include "menus.c"
#include "tratadores.c"
#include "dados.c"
#include <stdio.h>
#include "constantes.h"

int main(int argc, char const *argv[])
{
    int op_menu_principal = 0;
    Aluno *alunos[MAX_ALUNO] = {NULL};
    Professor *professores[MAX_PROFESSOR] = {NULL};

    int qtd_atual_aluno = 0;
    int qtd_atual_professor = 0;

    do
    {
        op_menu_principal = menu_principal();
        switch (op_menu_principal)
        {
        case 1:
            tratador_menu_aluno(alunos, &qtd_atual_aluno);
            break;
        case 2:
            tratador_menu_professor(professores, &qtd_atual_professor);
        case 3:
            printf("Finalizando app...\n\n");
        }
    } while (op_menu_principal != 3);
    return 0;
}