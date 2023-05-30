#ifndef _DADOS_H_
#define _DADOS_H_

// Definição da estrutura Endereco
typedef struct
{
    // Definição dos campos para armazenar os dados
    char logradouro[50];
    char bairro[50];
    char cidade[50];
    char estado[10];
    char numero[10];
} Endereco;

// Definição da estrutura Aluno
typedef struct
{
    // Definição dos campos para armazenar os dados
    char matricula[10];
    char cpf[12];
    char nome[50];
    Endereco *endereco;  // Ponteiro para a estrutura Endereco que representa o endereço do aluno
} Aluno;

// Definição da estrutura Professor
typedef struct
{
    // Definição dos campos para armazenar os dados
    char matricula[19];
    char cpf[12];
    char nome[50];
    Endereco *endereco; // Ponteiro para a estrutura Endereco que representa o endereço do professor
} Professor;

// Definição da estrutura Turma
typedef struct
{
    // Ponteiro para a estrutura Endereco que representa o endereço do professor
    char codigo[19];
    char nome_disc[30];
    char prof[50];
    char media[10]; // Há uma limitação pois media está declarada como string e não como float
} Turma;

// Função para criar uma estrutura Endereco
Endereco *criarEndereco(char *logradouro,
                        char *bairro,
                        char *cidade,
                        char *estado,
                        char *numero);

// Função para criar uma estrutura Aluno
Aluno *criarAluno(char *matricula,
                  char *cpf,
                  char *nome,
                  Endereco *end);

// Função para criar uma estrutura Professor
Professor *criarProfessor(char *matricula,
                          char *cpf,
                          char *nome,
                          Endereco *end);

// Função para criar uma estrutura Turma
Turma *criarTurma(char *codigo,
                  char *nome_disc,
                  char *prof,
                  char *media);

// Função para destruir a estrutura Aluno
void destruirAluno(Aluno *aluno);

// Função para destruir a estrutura Professor
void destruirProfessor(Professor *professor);

// Função para destruir a estrutura Turma
void destruirTurma(Turma *turma);

// Função para destruir a estrutura Endereco
void destruirEndereco(Endereco *endereco);

#endif
