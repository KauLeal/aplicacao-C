#ifndef _TRATADORES_H_
#define _TRATADORES_H_
#include "dados.h"

void tratador_menu_aluno(Aluno **alunos, int *qtd_atual_aluno);
Aluno *construir_aluno();
void imprimir_aluno(Aluno *aluno);
Aluno *buscar_aluno(Aluno **alunos, int *posicao);

void tratador_menu_professor(Professor **professores, int *qtd_atual_professor);
Professor *construir_professor();
void imprimir_professor(Professor *professor);
Professor *buscar_professor(Professor **professores, int *posicao);

void tratador_menu_turma(Turma **turmas, int *qtd_atual_turma);
Turma *construir_turma();
void imprimir_turma(Turma *turma);
Turma *buscar_turma(Turma **turmas, int *posicao);

void imprimir_endereco(Endereco *endereco);
Endereco *construir_endereco();

#endif