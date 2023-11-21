#include "campo_minado.h"
#include <ncurses.h>
#include <stdlib.h>

void atualizar_tela(Celula** campo, int linhas, int colunas, int linha_atual, int coluna_atual, int escala) {
    clear();
    imprimir_campo(campo, linhas, colunas, escala);
    mvprintw(linha_atual * escala, coluna_atual * escala * 3, "X");
    refresh();
}

void exibir_menu() {
    clear();
    printw("Bem-vindo ao Campo Minado!\n");
    printw("1. Novo Jogo\n");
    printw("2. Instruções\n");
    printw("3. Sair\n");
    refresh();
}

void mostrar_instrucoes() {
    clear();
    printw("Instruções do Campo Minado:\n");
    printw("- Use as teclas 'W', 'A', 'S', 'D' para mover o cursor.\n");
    printw("- Pressione a barra de espaço para abrir uma célula.\n");
    printw("- Se abrir uma mina, o jogo acaba.\n");
    printw("- O número em uma célula aberta indica quantas minas estão nas células vizinhas.\n");
    printw("- O objetivo é abrir todas as células sem minas.\n");
    printw("- Pressione 'q' para voltar ao menu.\n");
    refresh();

    // Aguarde até que 'q' seja pressionado para voltar ao menu
    while (getch() != 'q') {}

    // Limpe a tela antes de voltar ao menu
    clear();
    refresh();
}

int main() {
    // Inicializar a biblioteca ncurses
    initscr();
    start_color();  // Inicialização de cores

    // Verificar se as cores são suportadas
    if (!has_colors()) {
        printw("Seu terminal não suporta cores.\n");
        endwin();
        return 1;
    }

    // Verificar se o terminal suporta pares de cores
    if (!can_change_color()) {
        printw("Seu terminal não suporta pares de cores.\n");
        endwin();
        return 1;
    }

    // Definir pares de cores
    init_pair(1, COLOR_RED, COLOR_BLACK);  // Define um par de cores (texto vermelho sobre fundo preto)

    raw();
    keypad(stdscr, TRUE);
    noecho();

    int escolha_menu = 0;

    while (1) {
        exibir_menu();
        escolha_menu = getch();  // Usar getch() para capturar a escolha do menu

        switch (escolha_menu) {
            case '1':
                // Lógica para iniciar um novo jogo
                clear();
                refresh();
                
                int linhas = 10;
                int colunas = 10;
                int num_minas = 10;

                Celula** campo;
                inicializar_campo(&campo, linhas, colunas);
                popular_com_minas(campo, linhas, colunas, num_minas);

                int tecla;
                int jogo_em_execucao = 1;
                int linha_atual = 0;
                int coluna_atual = 0;

                do {
                    // Atualizar a tela
                    atualizar_tela(campo, linhas, colunas, linha_atual, coluna_atual, 1);

                    // Capturar a tecla
                    tecla = getch();

                    switch (tecla) {
                        case 'A':
                        case 'a':
                            coluna_atual = (coluna_atual - 1 + colunas) % colunas;
                            break;
                        case 'W':
                        case 'w':
                            linha_atual = (linha_atual - 1 + linhas) % linhas;
                            break;
                        case 'S':
                        case 's':
                            linha_atual = (linha_atual + 1) % linhas;
                            break;
                        case 'D':
                        case 'd':
                            coluna_atual = (coluna_atual + 1) % colunas;
                            break;
                        case ' ':
                            abrir_celula(campo, linhas, colunas, linha_atual, coluna_atual, &jogo_em_execucao);

                            break;
                        // Adicione mais casos conforme necessário
                    }
                    if(jogo_em_execucao == 0){
                        break;
                    }

                } while (tecla != 'q');  // Pressionar 'q' para sair

                // Encerrar o jogo
                fim_do_jogo(campo, linhas, colunas);
                break;

            case '2':
                // Lógica para exibir instruções
                mostrar_instrucoes();
                break;

            case '3':
                // Sair do jogo
                endwin();
                return 0;

            default:
                printw("Escolha inválida.\n");
                refresh();
                break;
        }
    }

    // Restante do seu código
    // ...

    // Encerrar a biblioteca ncurses
    endwin();

    return 0;
}
