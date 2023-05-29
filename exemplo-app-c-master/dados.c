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
    FILE *arquivo_aluno = fopen("dados_alunos.txt", "a");
    if (arquivo_aluno == NULL)
    {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    for (int i = 0; i < qtd_atual_aluno; i++)
    {
        Aluno *aluno = alunos[i];
        fprintf(arquivo_aluno, "Matricula: %s", aluno->matricula);
        fprintf(arquivo_aluno, "CPF: %s", aluno->cpf);
        fprintf(arquivo_aluno, "Nome: %s", aluno->nome);
        fprintf(arquivo_aluno, "Logradouro: %s", aluno->endereco->logradouro);
        fprintf(arquivo_aluno, "Bairro: %s", aluno->endereco->bairro);
        fprintf(arquivo_aluno, "Cidade: %s", aluno->endereco->cidade);
        fprintf(arquivo_aluno, "Estado: %s", aluno->endereco->estado);
        fprintf(arquivo_aluno, "Numero: %s", aluno->endereco->numero);
        fprintf(arquivo_aluno, ";\n");
    }

    fclose(arquivo_aluno);
}

void salvarDadosProfessores(Professor **professores, int qtd_atual_professor)
{
    FILE *arquivo_professor = fopen("dados_professores.txt", "a");
    if (arquivo_professor == NULL)
    {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    for (int i = 0; i < qtd_atual_professor; i++)
    {
        Professor *professor = professores[i];
        fprintf(arquivo_professor, "Matricula: %s", professor->matricula);
        fprintf(arquivo_professor, "CPF: %s", professor->cpf);
        fprintf(arquivo_professor, "Nome: %s", professor->nome);
        fprintf(arquivo_professor, "Logradouro: %s", professor->endereco->logradouro);
        fprintf(arquivo_professor, "Bairro: %s", professor->endereco->bairro);
        fprintf(arquivo_professor, "Cidade: %s", professor->endereco->cidade);
        fprintf(arquivo_professor, "Estado: %s", professor->endereco->estado);
        fprintf(arquivo_professor, "Numero: %s", professor->endereco->numero);
        fprintf(arquivo_professor, ";\n");
    }

    fclose(arquivo_professor);
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
        perror("Não ha memoria disponível. Encerrando\n\n");
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
        perror("Não ha memória disponível. Encerrando\n\n");
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