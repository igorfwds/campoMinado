#include <unistd.h>
#include "campo_minado.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>


void inicializar_campo(Celula*** campo, int linhas, int colunas) {
    *campo = (Celula**)malloc(linhas * sizeof(Celula*));
    for (int i = 0; i < linhas; i++) {
        (*campo)[i] = (Celula*)malloc(colunas * sizeof(Celula));
        for (int j = 0; j < colunas; j++) {
            (*campo)[i][j].tem_mina = 0;
            (*campo)[i][j].aberto = 0;
        }
    }
}

void popular_com_minas(Celula** campo, int linhas, int colunas, int num_minas) {
    // Semente para a geração de números aleatórios
    srand(time(NULL));

    // Distribuir minas aleatoriamente
    for (int i = 0; i < num_minas; i++) {
        int linha = rand() % linhas;
        int coluna = rand() % colunas;

        // Verificar se já existe uma mina nessa posição
        if (campo[linha][coluna].tem_mina) {
            i--; // Tentar novamente
        } else {
            campo[linha][coluna].tem_mina = 1;
        }
    }
}

void imprimir_campo(Celula** campo, int linhas, int colunas, int escala) {
    // Imprimir o campo no formato desejado
    for (int i = 0; i < linhas; i++) {
        for (int k = 0; k < escala; k++) {
            for (int j = 0; j < colunas; j++) {
                for (int l = 0; l < escala; l++) {
                    if (campo[i][j].aberto) {
                        if (campo[i][j].tem_mina) {
                            attron(COLOR_PAIR(1));  // Cor vermelha para mina aberta
                            mvprintw(i * escala + k, j * escala * 3 + l * 3, " * ");
                            attroff(COLOR_PAIR(1));
                        } else {       
                            int contador = contar_bombas_vizinhas(campo,linhas,colunas, i, j);       
                            mvprintw(i * escala + k, j * escala * 3 + l * 3, " %d ", contador);  // Espaço vazio aberto
                        }
                    } else {
                        mvprintw(i * escala + k, j * escala * 3 + l * 3, " - ");  // Célula fechada
                    }
                }
            }
            printw("\n");
        }
    }
}



void fim_do_jogo(Celula** campo, int linhas, int colunas) {
    int pontuacao = 0;

    // Mostrar a posição de todas as bombas e atualizar pontuação
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (campo[i][j].tem_mina) {
                attron(COLOR_PAIR(1));  // Cor vermelha para mina
                mvprintw(i, j * 3, " * ");
                attroff(COLOR_PAIR(1));
            } else if (campo[i][j].aberto && campo[i][j].tem_mina==0) {
                pontuacao++;  // Incrementar a pontuação para células sem minas
            }
        }
    }
    if(pontuacao>=90){
        refresh();
        printw("\n");
        printw("\n");
        printw("\n");
        printw("VVVVVVVV           VVVVVVVVIIIIIIIIIITTTTTTTTTTTTTTTTTTTTTTT     OOOOOOOOO     RRRRRRRRRRRRRRRRR   IIIIIIIIII               AAA                     !!!  !!!  !!! \n");
        refresh();
        sleep(1);
        printw("V::::::V           V::::::VI::::::::IT:::::::::::::::::::::T   OO:::::::::OO   R::::::::::::::::R  I::::::::I              A:::A                   !!:!!!!:!!!!:!!\n");
        refresh();
        sleep(1);
        printw("V::::::V           V::::::VI::::::::IT:::::::::::::::::::::T OO:::::::::::::OO R::::::RRRRRR:::::R I::::::::I             A:::::A                  !:::!!:::!!:::!\n");
        refresh();
        sleep(1);
        printw("V::::::V           V::::::VII::::::IIT:::::TT:::::::TT:::::TO:::::::OOO:::::::ORR:::::R     R:::::RII::::::II            A:::::::A                 !:::!!:::!!:::!\n");
        refresh();
        sleep(1);
        printw(" V:::::V           V:::::V   I::::I  TTTTTT  T:::::T  TTTTTTO::::::O   O::::::O  R::::R     R:::::R  I::::I             A:::::::::A                !:::!!:::!!:::!\n");
        refresh();
        sleep(1);
        printw("  V:::::V         V:::::V    I::::I          T:::::T        O:::::O     O:::::O  R::::R     R:::::R  I::::I            A:::::A:::::A               !:::!!:::!!:::!\n");
        refresh();
        sleep(1);
        printw("   V:::::V       V:::::V     I::::I          T:::::T        O:::::O     O:::::O  R::::RRRRRR:::::R   I::::I           A:::::A A:::::A              !:::!!:::!!:::!\n");
        refresh();
        sleep(1);
        printw("    V:::::V     V:::::V      I::::I          T:::::T        O:::::O     O:::::O  R:::::::::::::RR    I::::I          A:::::A   A:::::A             !:::!!:::!!:::!\n");
        refresh();
        sleep(1);
        printw("     V:::::V   V:::::V       I::::I          T:::::T        O:::::O     O:::::O  R::::RRRRRR:::::R   I::::I         A:::::A     A:::::A            !:::!!:::!!:::!\n");
        refresh();
        sleep(1);
        printw("      V:::::V V:::::V        I::::I          T:::::T        O:::::O     O:::::O  R::::R     R:::::R  I::::I        A:::::AAAAAAAAA:::::A           !:::!!:::!!:::!\n");
        refresh();
        sleep(1);
        printw("       V:::::V:::::V         I::::I          T:::::T        O:::::O     O:::::O  R::::R     R:::::R  I::::I       A:::::::::::::::::::::A          !!:!!!!:!!!!:!!\n");
        refresh();
        sleep(1);
        printw("        V:::::::::V          I::::I          T:::::T        O::::::O   O::::::O  R::::R     R:::::R  I::::I      A:::::AAAAAAAAAAAAA:::::A          !!!  !!!  !!! \n");
        refresh();
        sleep(1);
        printw("         V:::::::V         II::::::II      TT:::::::TT      O:::::::OOO:::::::ORR:::::R     R:::::RII::::::II   A:::::A             A:::::A                       \n");
        refresh();
        sleep(1);
        printw("          V:::::V          I::::::::I      T:::::::::T       OO:::::::::::::OO R::::::R     R:::::RI::::::::I  A:::::A               A:::::A        !!!  !!!  !!! \n");
        refresh();
        sleep(1);
        printw("           V:::V           I::::::::I      T:::::::::T         OO:::::::::OO   R::::::R     R:::::RI::::::::I A:::::A                 A:::::A      !!:!!!!:!!!!:!!\n");
        refresh();
        sleep(1);
        printw("            VVV            IIIIIIIIII      TTTTTTTTTTT           OOOOOOOOO     RRRRRRRR     RRRRRRRIIIIIIIIIIAAAAAAA                   AAAAAAA      !!!  !!!  !!! \n");
        refresh();
        sleep(1);
        printw("\n");
        

        mvprintw(linhas + 19, 5, "UHUUUUUUL!  VOCE VENCEU !!!!");
        // Exibir a pontuação abaixo do campo
        mvprintw(linhas + 21, 0, "Sua Pontuação foi de : %d pontos !!!", pontuacao);
        refresh();
        sleep(5);  // Esperar 6 segundos antes de voltar para o menu

        // Limpar a tela
        clear();
    }else{
            // Exibir a pontuação abaixo do campo
        mvprintw(linhas + 2, 0, "Pontuação: %d", pontuacao);
        refresh();
        sleep(5);  // Esperar 6 segundos antes de voltar para o menu

        // Limpar a tela
        clear();
    }
    

}


void revelar_vizinhas(Celula** campo, int linhas, int colunas, int linha, int coluna) {
    // Verificar limites
    if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas) {
        return;
    }

    // Se a célula já foi aberta ou contém uma mina, não fazer nada
    if (campo[linha][coluna].aberto || campo[linha][coluna].tem_mina) {
        return;
    }

    // Abrir a célula
    campo[linha][coluna].aberto = 1;

    // Verificar se a célula é vazia (sem mina)
    if (campo[linha][coluna].tem_mina == 0) {
        contar_bombas_vizinhas(campo,linhas,colunas,linha,coluna);
    } 
}


int contar_bombas_vizinhas(Celula** campo, int linhas, int colunas, int linha, int coluna) {
    int contador = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int vizinha_linha = linha + i;
            int vizinha_coluna = coluna + j;

            if (vizinha_linha >= 0 && vizinha_linha < linhas && vizinha_coluna >= 0 && vizinha_coluna < colunas) {
                if (campo[vizinha_linha][vizinha_coluna].tem_mina) {
                    contador++;
                }
            }
        }
    }
    

    return contador;
}

void abrir_celula(Celula** campo, int linhas, int colunas, int linha, int coluna, int* jogo_em_execucao) {
    // Verificar limites
    if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas) {
        return;
    }

    // Verificar se a célula já foi aberta
    if (campo[linha][coluna].aberto) {
        return;
    }

    // Abrir a célula
    campo[linha][coluna].aberto = 1;

    // Verificar se há uma mina na célula
    if (campo[linha][coluna].tem_mina) {
        // Chamar a função de fim do jogo
        fim_do_jogo(campo,linhas,colunas);
        *jogo_em_execucao = 0;
        return;
    } else {
        // Se a célula não contém uma mina, verificar células vizinhas
        revelar_vizinhas(campo, linhas, colunas, linha, coluna);
    }
}
