#include "dados.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


// Função para criar um aluno
Aluno *criarAluno(char *matricula, char *cpf, char *nome, Endereco *end)
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno)); // Aloca memória para a estrutura do Aluno
    if (aluno)
    {
        // Copia os dados para a estrutuda do Aluno
        strcpy(aluno->matricula, matricula);
        strcpy(aluno->cpf, cpf); 
        strcpy(aluno->nome, nome);
        aluno->endereco = end;
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n"); // Mensagem de erro para caso não seja possível alocar memória
    }

    return aluno; // Retorna o ponteiro para a estrutura do Aluno
}

// Função para salvar os dados dos alunos em um arquivo
void salvarDadosAlunos(Aluno **alunos, int qtd_atual_aluno)
{
    FILE *arquivo_aluno = fopen("dados_alunos.txt", "a"); // Abre o arquivo para escrita, no modo append

    if (arquivo_aluno == NULL)
    {
        perror("Erro ao abrir o arquivo para escrita"); // Mensagem de erro para caso não seja possível abrir o arquivo
        return;
    }

    for (int i = 0; i < qtd_atual_aluno; i++)
    {
        Aluno *aluno = alunos[i];
        // Escreve os dados no arquivo para deixar salvo
        fprintf(arquivo_aluno, "Matricula: %s", aluno->matricula);
        fprintf(arquivo_aluno, "CPF: %s", aluno->cpf);
        fprintf(arquivo_aluno, "Nome: %s", aluno->nome); 
        fprintf(arquivo_aluno, "Logradouro: %s", aluno->endereco->logradouro);
        fprintf(arquivo_aluno, "Bairro: %s", aluno->endereco->bairro); 
        fprintf(arquivo_aluno, "Cidade: %s", aluno->endereco->cidade);
        fprintf(arquivo_aluno, "Estado: %s", aluno->endereco->estado);
        fprintf(arquivo_aluno, "Numero: %s", aluno->endereco->numero);
        fprintf(arquivo_aluno, ";\n"); // Indica o fim dos dados do aluno no arquivo
    }

    fclose(arquivo_aluno);
}

// Função para salvar os dados dos professores em um arquivo
void salvarDadosProfessores(Professor **professores, int qtd_atual_professor)
{
    FILE *arquivo_professor = fopen("dados_professores.txt", "a"); // Abre o arquivo para escrita, no modo append

    if (arquivo_professor == NULL)
    {
        perror("Erro ao abrir o arquivo para escrita"); // Mensagem de erro para caso não seja possível abrir o arquivo
        return;
    }

    for (int i = 0; i < qtd_atual_professor; i++)
    {
        Professor *professor = professores[i];
        // Escreve os dados no arquivo para deixar salvo
        fprintf(arquivo_professor, "Matricula: %s", professor->matricula);
        fprintf(arquivo_professor, "CPF: %s", professor->cpf);
        fprintf(arquivo_professor, "Nome: %s", professor->nome);
        fprintf(arquivo_professor, "Logradouro: %s", professor->endereco->logradouro);
        fprintf(arquivo_professor, "Bairro: %s", professor->endereco->bairro);
        fprintf(arquivo_professor, "Cidade: %s", professor->endereco->cidade);
        fprintf(arquivo_professor, "Estado: %s", professor->endereco->estado);
        fprintf(arquivo_professor, "Numero: %s", professor->endereco->numero);
        fprintf(arquivo_professor, ";\n"); // Indica o fim dos dados do professor no arquivo
    }

    fclose(arquivo_professor);
}

// Função para criar um endereço
Endereco *criarEndereco(char *logradouro,
                        char *bairro,
                        char *cidade,
                        char *estado,
                        char *numero)
{
    Endereco *endereco = (Endereco *)malloc(sizeof(Endereco)); // Aloca memória para a estrutura do Endereco

    if (endereco)
    {
        // Copia os dados para a estrutura do Endereço
        strcpy(endereco->logradouro, logradouro);
        strcpy(endereco->bairro, bairro);
        strcpy(endereco->cidade, cidade);
        strcpy(endereco->estado, estado);
        strcpy(endereco->numero, numero);
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n"); // Exibe uma mensagem de erro caso não seja possível alocar memória
    }

    return endereco;
}

// Função para criar um professor
Professor *criarProfessor(char *matricula,
                          char *cpf,
                          char *nome,
                          Endereco *end)
{
    Professor *professor = (Professor *)malloc(sizeof(Professor)); // Aloca memória para a estrutura do Professor

    if (professor)
    {
        //Copia os dados para a estrutura do Professor
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

// Função para destruir a estrutura do Aluno. Não está funcionando pois não interage com o arquivo .txt
void destruirAluno(Aluno *aluno)
{
    if (aluno)
    {
        Endereco *end = aluno->endereco;
        destruirEndereco(end); // Libera a memória alocada para o endereço do Aluno
        free(aluno); // Libera a memória alocada para a estrutura do Aluno
    }
}

// Função para destruir a estrutura do Professor. Não está funcionando pois não interage com o arquivo .txt
void destruirProfessor(Professor *professor)
{
    if (professor)
    {
        Endereco *end = professor->endereco;
        destruirEndereco(end); // Libera a memória alocada para o endereço do Professor
        free(professor); // Libera a memória alocada para a estrutura do Professor
    }
}

// Função para destruir a estrutura da Turma. Não está funcionando pois não interage com o arquivo .txt
void destruirTurma(Turma *turma)
{
    if (turma)
    {
        free(turma); // Libera a memória alocada para a estrutura da Turma
    }
}

// Função para criar uma Turma
Turma *criarTurma(char *codigo, char *nome_disc, char *prof, char *media)
{
    Turma *turma = (Turma *)malloc(sizeof(Turma)); // Aloca memória para a estrutura da Turma

    if (turma)
    {
        // Copia os dados para a estrutura de Turma
        strcpy(turma->codigo, codigo);
        strcpy(turma->nome_disc, nome_disc);
        strcpy(turma->prof, prof);
        strcpy(turma->media, media); // Há uma limitação pos média está como string e não como float
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n");
    }

    return turma;
}

// Função para salvar os dados das turmas em um arquivo
void salvarDadosTurmas(Turma **turmas, int qtd_atual_turma)
{
    FILE *arquivo_turma = fopen("dados_turmas.txt", "a"); // Abre o arquivo para escrita, no modo append

    if (arquivo_turma == NULL)
    {
        perror("Erro ao abrir o arquivo para escrita"); // Exibe uma mensagem de erro caso não seja possível abrir o arquivo
        return;
    }

    for (int i = 0; i < qtd_atual_turma; i++)
    {
        Turma *turma = turmas[i];
        // Escreve os dados no arquivo
        fprintf(arquivo_turma, "Codigo da turma: %s", turma->codigo);
        fprintf(arquivo_turma, "Nome da disciplina: %s", turma->nome_disc);
        fprintf(arquivo_turma, "Professor responsavel: %s", turma->prof);
        fprintf(arquivo_turma, "Media da turma: %s", turma->media); // Média é escrito como uma string e não como float
        fprintf(arquivo_turma, ";\n"); // Indica o fim dos dados da turma no arquivo
    }

    fclose(arquivo_turma);
}

void destruirEndereco(Endereco *endereco)
{
    if (endereco)
        free(endereco);
}