#include <ncurses.h>
#include "pseudo_css.h"
#include "tabela_de_valor.h"

int i, j, k;//váriaveis de interação
WINDOW *botao_inicio, *botao_abrir, *barra,*editor, *barra_editor;// variaveis tipos janelas

//FUNÇÕES DA HOME
void css_home(void)
{
    init_pair(1, COLOR_BLACK, COLOR_CYAN);
    init_pair(2,COLOR_CYAN,COLOR_BLACK);

    bkgd(COLOR_PAIR(1));

    return;
}

void marca(void)
{
    mvprintw(terminal.altura-1 ,terminal.largura-29 , "© 2016 - 2017, The Big Goms.");

    return;
}

void layout_botoes(void)
{
    attron(COLOR_PAIR(2));
    barra = subwin(stdscr, 1, terminal.largura, 1, 0);
    wborder(barra,'-', '-', '-', '-', '-', '-','-', '-');
    mvaddstr( 1, 1, "   Esc(sair)   ");
    attroff(COLOR_PAIR(2));

    botao_inicio = subwin(stdscr, 5, 16, (terminal.altura/2)-6, (terminal.largura/2)-8);
    box(botao_inicio, 0, 0);
    mvaddstr((terminal.altura/2)-4, (terminal.largura/2)-2, "Novo");

    botao_abrir = subwin(stdscr, 5, 16, (terminal.altura/2), (terminal.largura/2)-8);
    box(botao_abrir, 0, 0);
    mvaddstr((terminal.altura/2)+2, (terminal.largura/2)-2, "Abrir");

    refresh();

    return;
}

void selecionado(WINDOW *janela_on, WINDOW *janela_off)
{
    wborder(janela_on,'*', '*', '*', '*', '*', '*', '*', '*');
    wrefresh(janela_on);
    box(janela_off, 0, 0);
    wrefresh(janela_off);

    return;
}

//FUNÇÕES DO EDITOR
void css_editor(void)
{
    init_pair(1, COLOR_BLACK, COLOR_CYAN);
    init_pair(2,COLOR_WHITE, COLOR_BLACK);
    init_pair(3,COLOR_WHITE, COLOR_WHITE);
    init_pair(4,COLOR_RED, COLOR_WHITE);
    init_pair(9,COLOR_BLUE, COLOR_BLACK);

    bkgd(COLOR_PAIR(2));

    return;
}

void css_highlight(void)
{
    init_pair(10, COLOR_GREEN, COLOR_BLACK);
    init_pair(11, COLOR_RED, COLOR_BLACK);
    init_pair(12, COLOR_CYAN, COLOR_BLACK);
    init_pair(13, COLOR_WHITE, COLOR_BLACK);
    init_pair(14, COLOR_BLUE, COLOR_BLACK);
    init_pair(15, COLOR_YELLOW, COLOR_BLACK);

    return;
}

void fundo_editor(void)
{
    editor = subwin(stdscr, terminal.altura-1, terminal.largura, 1, 2);

    attron(COLOR_PAIR(3));
    barra_editor = subwin(stdscr, 2, terminal.largura, 0, 0);
    box(barra_editor, 0, 0);
    attroff(COLOR_PAIR(3));

    attron(COLOR_PAIR(4));
    mvprintw(0,(terminal.largura-79),"Salvar(F1)");
    mvprintw(0,(terminal.largura-65),"Compilar(F5)");
    mvprintw(0,(terminal.largura-9),"MENU(F9)");
    attroff(COLOR_PAIR(4));

    move(2,0);
    return;
}

//FUNÇÕES COMPARTILHADAS
void deleta_janela(WINDOW *janela)
{
    wborder(janela, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    wrefresh(janela);
    delwin(janela);

    return;
}

void deleta_janela_string(WINDOW *janela)
{
    getmaxyx(janela, valor_temporario.altura, valor_temporario.largura);

    for(i=0;i<valor_temporario.altura;i++)
    {
        for(j=0;j<valor_temporario.largura;j++)
        {
            mvaddstr(i, j, "                 ");
        }
    }

    return;
}
