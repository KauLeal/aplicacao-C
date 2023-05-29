#include "tratadores.h"
#include "menus.h"
#include <stdio.h>
#include "constantes.h"
#include <string.h>

void tratador_menu_aluno(Aluno **alunos, int *qtd_atual_aluno)
{
    int opcao = menu_crud_aluno();
    Aluno *aluno = NULL;
    switch (opcao)
    {
    case 1:
        if (*qtd_atual_aluno >= MAX_ALUNO)
        {
            printf("Numero maximo de alunos atingido\n");
        }
        else
        {
            // Passo 1: buscar posicao disponível
            int i = 0;
            for (; i < *qtd_atual_aluno; i++)
            {
                if (alunos[i] != NULL)
                {
                    // significa que esta posição está livre para uso
                    break;
                }
            }
            Aluno *aluno = construir_aluno();
            alunos[i] = aluno;
            (*qtd_atual_aluno)++;
            salvarDadosAlunos(alunos, *qtd_atual_aluno);
        }
        break;
    case 2:
{
    char cpf_pesquisa[9];
    printf("\nDigite o CPF do aluno: ");
    fgets(cpf_pesquisa, 9, stdin);
    printf("\n");
    cpf_pesquisa[strcspn(cpf_pesquisa, "\n")] = '\0';  // Remover o caractere de nova linha

    FILE *arquivo_aluno = fopen("dados_alunos.txt", "r");
    if (arquivo_aluno == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        break;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo_aluno) != NULL)
    {
        if (strstr(linha, cpf_pesquisa) != NULL)
        {
            // CPF encontrado, imprimir o aluno
            Aluno aluno_encontrado;
            strcpy(aluno_encontrado.cpf, cpf_pesquisa);
            fgets(aluno_encontrado.nome, sizeof(aluno_encontrado.nome), arquivo_aluno);

            imprimir_aluno(&aluno_encontrado);

            break;
        }
    }

    fclose(arquivo_aluno);
    break;
}
case 3:
{
    char cpf_pesquisa[9];
    printf("Digite o CPF do aluno que deseja atualizar: ");
    fgets(cpf_pesquisa, 9, stdin);
    cpf_pesquisa[strcspn(cpf_pesquisa, "\n")] = '\0';  // Remover o caractere de nova linha

    FILE *arquivo_aluno = fopen("dados_alunos.txt", "r+");
    if (arquivo_aluno == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura/escrita");
        break;
    }

    char linha[100];
    long int posicao_aluno = -1;
    while (fgets(linha, sizeof(linha), arquivo_aluno) != NULL)
    {
        if (strstr(linha, cpf_pesquisa) != NULL)
        {
            // CPF encontrado, obter a posição no arquivo
            posicao_aluno = ftell(arquivo_aluno) - strlen(linha);
            break;
        }
    }

    if (posicao_aluno == -1)
    {
        printf("Aluno nao encontrado\n");
        fclose(arquivo_aluno);
        break;
    }

    // Posicionar o ponteiro do arquivo na posição do aluno
    fseek(arquivo_aluno, posicao_aluno, SEEK_SET);

    // Ler os dados atuais do aluno
    Aluno aluno_atual;
    fgets(aluno_atual.matricula, sizeof(aluno_atual.matricula), arquivo_aluno);
    fgets(aluno_atual.cpf, sizeof(aluno_atual.cpf), arquivo_aluno);
    fgets(aluno_atual.nome, sizeof(aluno_atual.nome), arquivo_aluno);

    // Pular a linha em branco
    fgets(linha, sizeof(linha), arquivo_aluno);

    printf("\nDados atuais do aluno:\n");
    imprimir_aluno(&aluno_atual);

    printf("\nDigite os novos dados do aluno:\n");
    Aluno *aluno_atualizado = construir_aluno();

    // Posicionar o ponteiro do arquivo na posição do aluno
    fseek(arquivo_aluno, posicao_aluno, SEEK_SET);

    // Atualizar os dados do aluno no arquivo
    fprintf(arquivo_aluno, "Matricula: %s", aluno_atualizado->matricula);
    fprintf(arquivo_aluno, "CPF: %s", aluno_atualizado->cpf);
    fprintf(arquivo_aluno, "Nome: %s", aluno_atualizado->nome);
    fprintf(arquivo_aluno, "Endereço: ");
    imprimir_endereco(aluno_atualizado->endereco);

    // Escrever os dados do endereço do aluno, se necessário
    fprintf(arquivo_aluno, "\n");

    printf("\nDados do aluno atualizados:\n");
    imprimir_aluno(aluno_atualizado);

    fclose(arquivo_aluno);
    break;
}

    case 4:
    {
        int posicao = 0;
        aluno = buscar_aluno(alunos, &posicao);
        if (aluno)
        {
            destruirAluno(aluno);
            alunos[posicao] = NULL;
            printf("Aluno destruido\n");
        }
        else
        {
            printf("Aluno nao encontrado!!\n");
        }
    }

    break;
    default:
        printf("Retornando ao menu principal\n");
        break;
    }
}

void tratador_menu_professor(Professor **professores, int *qtd_atual_professor)
{
    int opcao = menu_crud_professor();
    Professor *professor = NULL;
    switch (opcao)
    {
    case 1:
        if (*qtd_atual_professor >= MAX_PROFESSOR)
        {
            printf("Numero maximo de professores atingido\n");
        }
        else
        {
            // Passo 1: buscar posicao disponível
            int i = 0;
            for (; i < *qtd_atual_professor; i++)
            {
                if (professores[i] != NULL)
                {
                    // significa que esta posição está livre para uso
                    break;
                }
            }
            Professor *professor = construir_professor();
            professores[i] = professor;
            (*qtd_atual_professor)++;
            salvarDadosProfessores(professores, *qtd_atual_professor);
        }
        break;
    case 2:
{
    char cpf_pesquisa[9];
    printf("\nDigite o CPF do professor: ");
    fgets(cpf_pesquisa, 9, stdin);
    printf("\n");
    cpf_pesquisa[strcspn(cpf_pesquisa, "\n")] = '\0';  // Remover o caractere de nova linha

    FILE *arquivo_professor = fopen("dados_professores.txt", "r");
    if (arquivo_professor == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        break;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo_professor) != NULL)
    {
        if (strstr(linha, cpf_pesquisa) != NULL)
        {
            // CPF encontrado, imprimir o professor
            Professor professor_encontrado;
            strcpy(professor_encontrado.cpf, cpf_pesquisa);
            fgets(professor_encontrado.nome, sizeof(professor_encontrado.nome), arquivo_professor);

            imprimir_professor(&professor_encontrado);

            break;
        }
    }

    fclose(arquivo_professor);
    break;
}
case 3:
{
    char cpf_pesquisa[9];
    printf("Digite o CPF do professor que deseja atualizar: ");
    fgets(cpf_pesquisa, 9, stdin);
    cpf_pesquisa[strcspn(cpf_pesquisa, "\n")] = '\0';  // Remover o caractere de nova linha

    FILE *arquivo_professor = fopen("dados_professores.txt", "r+");
    if (arquivo_professor == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura/escrita");
        break;
    }

    char linha[100];
    long int posicao_professor = -1;
    while (fgets(linha, sizeof(linha), arquivo_professor) != NULL)
    {
        if (strstr(linha, cpf_pesquisa) != NULL)
        {
            // CPF encontrado, obter a posição no arquivo
            posicao_professor = ftell(arquivo_professor) - strlen(linha);
            break;
        }
    }

    if (posicao_professor == -1)
    {
        printf("Professor nao encontrado\n");
        fclose(arquivo_professor);
        break;
    }

    // Posicionar o ponteiro do arquivo na posição do professor
    fseek(arquivo_professor, posicao_professor, SEEK_SET);

    // Ler os dados atuais do professor
    Professor professor_atual;
    fgets(professor_atual.matricula, sizeof(professor_atual.matricula), arquivo_professor);
    fgets(professor_atual.cpf, sizeof(professor_atual.cpf), arquivo_professor);
    fgets(professor_atual.nome, sizeof(professor_atual.nome), arquivo_professor);

    // Pular a linha em branco
    fgets(linha, sizeof(linha), arquivo_professor);

    printf("\nDados atuais do professor:\n");
    imprimir_professor(&professor_atual);

    printf("\nDigite os novos dados do professor:\n");
    Professor *professor_atualizado = construir_professor();

    // Posicionar o ponteiro do arquivo na posição do professor
    fseek(arquivo_professor, posicao_professor, SEEK_SET);

    // Atualizar os dados do professor no arquivo
    fprintf(arquivo_professor, "Matricula: %s", professor_atualizado->matricula);
    fprintf(arquivo_professor, "CPF: %s", professor_atualizado->cpf);
    fprintf(arquivo_professor, "Nome: %s", professor_atualizado->nome);
    fprintf(arquivo_professor, "Endereço: ");
    imprimir_endereco(professor_atualizado->endereco);

    // Escrever os dados do endereço do professor, se necessário
    fprintf(arquivo_professor, "\n");

    printf("\nDados do professor atualizados:\n");
    imprimir_professor(professor_atualizado);

    fclose(arquivo_professor);
    break;
}

    case 4:
    {
        int posicao = 0;
        professor = buscar_professor(professores, &posicao);
        if (professor)
        {
            destruirProfessor(professor);
            professores[posicao] = NULL;
            printf("Professor destruido\n");
        }
        else
        {
            printf("Professor nao encontrado!!\n");
        }
    }

    break;
    default:
        printf("Retornando ao menu principal\n");
        break;
    }
}

Endereco *construir_endereco()
{
    Endereco endereco;

    printf("Logradouro\t> ");
    fgets(endereco.logradouro, 49, stdin);
    printf("Bairro\t> ");
    fgets(endereco.bairro, 49, stdin);
    printf("Cidade\t> ");
    fgets(endereco.cidade, 49, stdin);
    printf("Estado\t> ");
    fgets(endereco.estado, 9, stdin);
    printf("Numero\t> ");
    fgets(endereco.numero, 9, stdin);

    return criarEndereco(endereco.logradouro, endereco.bairro, endereco.cidade, endereco.estado, endereco.numero);
}

void imprimir_endereco(Endereco *endereco)
{
    printf("Logradouro: %s", endereco->logradouro);
    printf("Bairro: %s", endereco->bairro);
    printf("Cidade: %s", endereco->cidade);
    printf("Estado: %s", endereco->estado);
    printf("Numero: %s", endereco->numero);
}

Aluno *construir_aluno()
{
    Aluno aluno;
    printf("\nMatricula\t> ");
    fgets(aluno.matricula, 9, stdin);
    printf("CPF\t> ");
    fgets(aluno.cpf, 9, stdin);
    printf("Nome\t> ");
    fgets(aluno.nome, 49, stdin);
    aluno.endereco = construir_endereco();
    return criarAluno(aluno.matricula, aluno.cpf, aluno.nome, aluno.endereco);
}

Aluno *buscar_aluno(Aluno **alunos, int *posicao)
{
    char matricula[50];
    printf("\nMatricula > ");
    fgets(matricula, 49, stdin);
    Aluno *resultado = NULL;
    int pos_resultado = -1;
    for (int i = 0; i < MAX_ALUNO; i++)
    {
        // Vamos testar se o aluno existe e se a matricula e a buscada
        // strcmp compara strings. Se for 0 indica que são iguais
        if (alunos[i] && !strcmp(matricula, alunos[i]->matricula))
        {
            resultado = alunos[i];
            break;
        }
    }
    *posicao = pos_resultado;
    return resultado;
}

void imprimir_aluno(Aluno *aluno)
{
    FILE *arquivo_aluno = fopen("dados_alunos.txt", "r");
    if (arquivo_aluno == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo_aluno) != NULL)
    {
        if (strstr(linha, aluno->cpf) != NULL)
        {
            while (fgets(linha, sizeof(linha), arquivo_aluno) != NULL)
            {
                if (strstr(linha, ";") != NULL)
                    break;
                printf("%s", linha);
            }
            break;
        }
    }

    fclose(arquivo_aluno);
}

Professor *construir_professor()
{
    Professor professor;
    printf("\nMatricula\t> ");
    fgets(professor.matricula, 9, stdin);
    printf("CPF\t> ");
    fgets(professor.cpf, 9, stdin);
    printf("Nome\t> ");
    fgets(professor.nome, 49, stdin);
    professor.endereco = construir_endereco();
    return criarProfessor(professor.matricula, professor.cpf, professor.nome, professor.endereco);
}

Professor *buscar_professor(Professor **professores, int *posicao)
{
    char matricula[50];
    printf("\nMatricula > ");
    fgets(matricula, 49, stdin);
    Professor *resultado = NULL;
    int pos_resultado = -1;
    for (int i = 0; i < MAX_PROFESSOR; i++)
    {
        // Vamos testar se o professor existe e se a matricula e a buscada
        // strcmp compara strings. Se for 0 indica que são iguais
        if (professores[i] && !strcmp(matricula, professores[i]->matricula))
        {
            resultado = professores[i];
            break;
        }
    }
    *posicao = pos_resultado;
    return resultado;
}

void imprimir_professor(Professor *professor)
{
    FILE *arquivo_professor = fopen("dados_professores.txt", "r");
    if (arquivo_professor == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo_professor) != NULL)
    {
        if (strstr(linha, professor->cpf) != NULL)
        {
            while (fgets(linha, sizeof(linha), arquivo_professor) != NULL)
            {
                if (strstr(linha, ";") != NULL)
                    break;
                printf("%s", linha);
            }
            break;
        }
    }

    fclose(arquivo_professor);
}

void tratador_menu_turma(Turma **turmas, int *qtd_atual_turma)
{
    int opcao = menu_crud_turma();
    Turma *turma = NULL;
    switch (opcao)
    {
    case 1:
        if (*qtd_atual_turma >= MAX_TURMA)
        {
            printf("Numero maximo de turmas atingido\n");
        }
        else
        {
            // Passo 1: buscar posicao disponível
            int i = 0;
            for (; i < *qtd_atual_turma; i++)
            {
                if (turmas[i] != NULL)
                {
                    // significa que esta posição está livre para uso
                    break;
                }
            }
            Turma *turma = construir_turma();
            turmas[i] = turma;
            (*qtd_atual_turma)++;
            salvarDadosTurmas(turmas, *qtd_atual_turma);
        }
        break;
    case 2:
{
    char cod_pesquisa[9];
    printf("\nDigite o codigo do turma: ");
    fgets(cod_pesquisa, 9, stdin);
    printf("\n");
    cod_pesquisa[strcspn(cod_pesquisa, "\n")] = '\0';  // Remover o caractere de nova linha

    FILE *arquivo_turma = fopen("dados_turmas.txt", "r");
    if (arquivo_turma == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        break;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo_turma) != NULL)
    {
        if (strstr(linha, cod_pesquisa) != NULL)
        {
            // Codigo encontrado, imprimir a turma
            Turma turma_encontrado;
            strcpy(turma_encontrado.codigo, cod_pesquisa);
            fgets(turma_encontrado.nome_disc, sizeof(turma_encontrado.nome_disc), arquivo_turma);

            imprimir_turma(&turma_encontrado);

            break;
        }
    }

    fclose(arquivo_turma);
    break;
}
case 3:
{
    char cod_pesquisa[9];
    printf("Digite o codigo da turma que deseja atualizar: ");
    fgets(cod_pesquisa, 9, stdin);
    cod_pesquisa[strcspn(cod_pesquisa, "\n")] = '\0';  // Remover o caractere de nova linha

    FILE *arquivo_turma = fopen("dados_turmas.txt", "r+");
    if (arquivo_turma == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura/escrita");
        break;
    }

    char linha[100];
    long int posicao_turma = -1;
    while (fgets(linha, sizeof(linha), arquivo_turma) != NULL)
    {
        if (strstr(linha, cod_pesquisa) != NULL)
        {
            // Codigo encontrado, obter a posição no arquivo
            posicao_turma = ftell(arquivo_turma) - strlen(linha);
            break;
        }
    }

    if (posicao_turma == -1)
    {
        printf("Turma nao encontrada\n");
        fclose(arquivo_turma);
        break;
    }

    // Posicionar o ponteiro do arquivo na posição da turma
    fseek(arquivo_turma, posicao_turma, SEEK_SET);

    // Ler os dados atuais da turma
    Turma turma_atual;
    fgets(turma_atual.codigo, sizeof(turma_atual.codigo), arquivo_turma);
    fgets(turma_atual.nome_disc, sizeof(turma_atual.nome_disc), arquivo_turma);
    fgets(turma_atual.prof, sizeof(turma_atual.prof), arquivo_turma);
    fgets(turma_atual.media, sizeof(turma_atual.media), arquivo_turma);

    // Pular a linha em branco
    fgets(linha, sizeof(linha), arquivo_turma);

    printf("\nDados atuais da turma:\n");
    imprimir_turma(&turma_atual);

    printf("\nDigite os novos dados da turma:\n");
    Turma *turma_atualizado = construir_turma();

    // Posicionar o ponteiro do arquivo na posição da turma
    fseek(arquivo_turma, posicao_turma, SEEK_SET);

    // Atualizar os dados da turma no arquivo
    fprintf(arquivo_turma, "Codigo da turma: %s", turma_atualizado->codigo);
    fprintf(arquivo_turma, "Nome da disciplina: %s", turma_atualizado->nome_disc);
    fprintf(arquivo_turma, "Professor da turma: %s", turma_atualizado->prof);
    fprintf(arquivo_turma, "Nota media da turma: %s", turma_atualizado->media);

    // Escrever os dados do endereço da turma, se necessário
    fprintf(arquivo_turma, "\n");

    printf("\nDados da turma atualizados:\n");
    imprimir_turma(turma_atualizado);

    fclose(arquivo_turma);
    break;
}

    case 4:
    {
        int posicao = 0;
        turma = buscar_turma(turmas, &posicao);
        if (turma)
        {
            destruirTurma(turma);
            turmas[posicao] = NULL;
            printf("Turma destruida\n");
        }
        else
        {
            printf("Turma nao encontrada\n");
        }
    }

    break;
    default:
        printf("Retornando ao menu principal\n");
        break;
    }
}

Turma *construir_turma()
{
    Turma turma;
    printf("\nCodigo da turma\t> ");
    fgets(turma.codigo, 9, stdin);
    printf("Nome da disciplina\t> ");
    fgets(turma.nome_disc, 30, stdin);
    printf("Professor da turma\t> ");
    fgets(turma.prof, 30, stdin);
    printf("Media da turma\t> ");
    fgets(turma.media, 10, stdin);    
    return criarTurma(turma.codigo, turma.nome_disc, turma.prof, turma.media);
}

Turma *buscar_turma(Turma **turmas, int *posicao)
{
    char codigo[50];
    printf("\nCodigo da turma > ");
    fgets(codigo, 49, stdin);
    Turma *resultado = NULL;
    int pos_resultado = -1;
    for (int i = 0; i < MAX_TURMA; i++)
    {
        // Vamos testar se a turma existe e se o codigo e a buscada
        // strcmp compara strings. Se for 0 indica que são iguais
        if (turmas[i] && !strcmp(codigo, turmas[i]->codigo))
        {
            resultado = turmas[i];
            break;
        }
    }
    *posicao = pos_resultado;
    return resultado;
}

void imprimir_turma(Turma *turma)
{
    FILE *arquivo_turma = fopen("dados_turmas.txt", "r");
    if (arquivo_turma == NULL)
    {
        perror("Erro ao abrir o arquivo para leitura");
        return;
    }

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo_turma) != NULL)
    {
        if (strstr(linha, turma->codigo) != NULL)
        {
            while (fgets(linha, sizeof(linha), arquivo_turma) != NULL)
            {
                if (strstr(linha, ";") != NULL)
                    break;
                printf("%s", linha);
            }
            break;
        }
    }

    fclose(arquivo_turma);
}