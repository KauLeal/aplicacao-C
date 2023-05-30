#include "menus.c"
#include "tratadores.c"
#include "dados.c"
#include <stdio.h>
#include "constantes.h"

int main(int argc, char const *argv[])
{
    int op_menu_principal = 0; // Variável para armazenar a opção escolhida no menu principal
    Aluno *alunos[MAX_ALUNO] = {NULL}; // Vetor de ponteiros para estruturas Aluno
    Professor *professores[MAX_PROFESSOR] = {NULL}; // Vetor de ponteiros para estruturas Professor
    Turma *turmas[MAX_TURMA] = {NULL}; // Vetor de ponteiros para estruturas Turma

    // Variáveis para armazenar a quantidade atual de alunos, professores e turmas
    int qtd_atual_aluno = 0;
    int qtd_atual_professor = 0; 
    int qtd_atual_turma = 0;

    do
    {
        op_menu_principal = menu_principal(); // Exibe o menu principal e obtém a opção escolhida
        switch (op_menu_principal)
        {
        case 1:
            tratador_menu_aluno(alunos, &qtd_atual_aluno); // Caso o usuário digite 1, chama a função tratador_menu_aluno
            break;
        case 2:
            tratador_menu_professor(professores, &qtd_atual_professor); // Caso o usuário digite 2, chama a função tratador_menu_professor
            break;
        case 3:
            tratador_menu_turma(turmas, &qtd_atual_turma); // Caso o usuário digite 3, chama a função tratador_menu_turma
            break;
        case 4:
            printf("Finalizando app...\n\n"); // Caso o usuário digite 4, exibe a mensagem de encerramento do programa
            break;
        }
    } while (op_menu_principal != 4); // Repete o loop até que a opção 4 (encerrar) seja escolhida

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
