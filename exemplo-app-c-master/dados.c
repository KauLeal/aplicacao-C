#include "dados.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Aluno *criarAluno(char *matricula, char *cpf, char *nome, Endereco *end)
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    if (aluno)
    {
        strcpy(aluno->matricula, matricula);
        strcpy(aluno->cpf, cpf);
        strcpy(aluno->nome, nome);
        aluno->endereco = end;
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n");
    }
    return aluno;
}

void salvarDadosAlunos(Aluno **alunos, int qtd_atual_aluno)
{
    FILE *arquivo = fopen("dados_alunos.txt", "a");
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    for (int i = 0; i < qtd_atual_aluno; i++)
    {
        Aluno *aluno = alunos[i];
        fprintf(arquivo, "Matricula: %s", aluno->matricula);
        fprintf(arquivo, "CPF: %s", aluno->cpf);
        fprintf(arquivo, "Nome: %s", aluno->nome);
        fprintf(arquivo, "Logradouro: %s", aluno->endereco->logradouro);
        fprintf(arquivo, "Bairro: %s", aluno->endereco->bairro);
        fprintf(arquivo, "Cidade: %s", aluno->endereco->cidade);
        fprintf(arquivo, "Estado: %s", aluno->endereco->estado);
        fprintf(arquivo, "Numero: %s", aluno->endereco->numero);
        fprintf(arquivo, ";\n");
    }

    fclose(arquivo);
}

Endereco *criarEndereco(char *logradouro,
                        char *bairro,
                        char *cidade,
                        char *estado,
                        char *numero)
{
    Endereco *endereco = (Endereco *)malloc(sizeof(Endereco));
    if (endereco)
    {
        strcpy(endereco->logradouro, logradouro);
        strcpy(endereco->bairro, bairro);
        strcpy(endereco->cidade, cidade);
        strcpy(endereco->estado, estado);
        strcpy(endereco->numero, numero);
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n");
    }
    return endereco;
}

Professor *criarProfessor(char *matricula,
                          char *cpf,
                          char *nome,
                          Endereco *end)
{
    Professor *professor = (Professor *)malloc(sizeof(Professor));
    if (professor)
    {
        strcpy(professor->matricula, matricula);
        strcpy(professor->cpf, cpf);
        strcpy(professor->nome, nome);
        professor->endereco = end;
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n");
    }
    return professor;
}

void destruirAluno(Aluno *aluno)
{
    if (aluno)
    {
        Endereco *end = aluno->endereco;
        destruirEndereco(end);
        free(aluno);
    }
}

void destruirProfessor(Professor *professor)
{
    if (professor)
    {
        Endereco *end = professor->endereco;
        destruirEndereco(end);
        free(professor);
    }
}

void destruirEndereco(Endereco *endereco)
{
    if (endereco)
        free(endereco);
}