#ifndef _TRATADORES_H_
#define _TRATADORES_H_

#include "dados.h"

// Função responsável por tratar o menu relacionado aos alunos
// Recebe como parâmetros um vetor de ponteiros para alunos e a quantidade atual de alunos
void tratador_menu_aluno(Aluno **alunos, int *qtd_atual_aluno);

// Função responsável por construir um novo aluno
// Retorna um ponteiro para o aluno criado
Aluno *construir_aluno();

// Função responsável por imprimir os dados de um aluno
// Recebe como parâmetro um ponteiro para o aluno a ser impresso
void imprimir_aluno(Aluno *aluno);

// Função responsável por buscar um aluno pelo seu número de matrícula
// Recebe como parâmetros um vetor de ponteiros para alunos e a posição onde o aluno foi encontrado
// Retorna um ponteiro para o aluno encontrado ou NULL se não for encontrado
Aluno *buscar_aluno(Aluno **alunos, int *posicao);

// Função responsável por tratar o menu relacionado aos professores
// Recebe como parâmetros um vetor de ponteiros para professores e a quantidade atual de professores
void tratador_menu_professor(Professor **professores, int *qtd_atual_professor);

// Função responsável por construir um novo professor
// Retorna um ponteiro para o professor criado
Professor *construir_professor();

// Função responsável por imprimir os dados de um professor
// Recebe como parâmetro um ponteiro para o professor a ser impresso
void imprimir_professor(Professor *professor);

// Função responsável por buscar um professor pelo seu número de matrícula
// Recebe como parâmetros um vetor de ponteiros para professores e a posição onde o professor foi encontrado
// Retorna um ponteiro para o professor encontrado ou NULL se não for encontrado
Professor *buscar_professor(Professor **professores, int *posicao);

// Função responsável por tratar o menu relacionado às turmas
// Recebe como parâmetros um vetor de ponteiros para turmas e a quantidade atual de turmas
void tratador_menu_turma(Turma **turmas, int *qtd_atual_turma);

// Função responsável por construir uma nova turma
// Retorna um ponteiro para a turma criada
Turma *construir_turma();

// Função responsável por imprimir os dados de uma turma
// Recebe como parâmetro um ponteiro para a turma a ser impressa
void imprimir_turma(Turma *turma);

// Função responsável por buscar uma turma pelo seu código
// Recebe como parâmetros um vetor de ponteiros para turmas e a posição onde a turma foi encontrada
// Retorna um ponteiro para a turma encontrada ou NULL se não for encontrada
Turma *buscar_turma(Turma **turmas, int *posicao);

// Função responsável por imprimir os dados de um endereço
// Recebe como parâmetro um ponteiro para o endereço a ser impresso
void imprimir_endereco(Endereco *endereco);

// Função responsável por construir um novo endereço
// Retorna um ponteiro para o endereço criado
Endereco *construir_endereco();

#endif