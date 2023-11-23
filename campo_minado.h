#ifndef CAMPO_MINADO_H
#define CAMPO_MINADO_H

// Definindo a estrutura para uma célula do campo minado
typedef struct {
    int tem_mina;
    int aberto;
    // Outros campos que você precisar
} Celula;

// Funções
void inicializar_campo(Celula*** campo, int linhas, int colunas);
void popular_com_minas(Celula** campo, int linhas, int colunas, int num_minas);
void imprimir_campo(Celula** campo, int linhas, int colunas, int escala);
void abrir_celula(Celula** campo, int linhas, int colunas, int linha, int coluna, int* jogo_em_execucao);
void fim_do_jogo(Celula** campo, int linhas, int colunas);
void revelar_vizinhas(Celula** campo, int linhas, int colunas, int linha, int coluna);
int contar_bombas_vizinhas(Celula** campo, int linhas, int colunas, int linha, int coluna);

#endif
