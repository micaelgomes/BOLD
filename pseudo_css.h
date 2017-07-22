/*
    Biblioteca responsável pelo gerenciamento de cores, criação de cores e formações do layout.
*/

#ifndef PSEUDO_CSS_H_INCLUDED
#define PSEUDO_CSS_H_INCLUDED

void css_home(void);
/*

    Função de gerenciamento de cores, da tela principal.
    Não recebe parâmetros;
    Todas suas funções são da Ncurses para interface.
    Ñão retorna nada;

*/

void marca(void);
/*

    Função que imprimi a marca da empresa na tela;
    Não recebe parâmetros;
    Possui apenas uma função(mvprintw());
    Ñão retorna nada;

*/

void layout_botoes(void);
/*

    Função de formação dos botões na tela principal.
    Não recebe parâmetros;
    Possui funções de controle de janela.
    Ñão retorna nada;

*/

void selecionado(WINDOW *janela_on, WINDOW *janela_off);
/*

    Função que recebe a opção do usário para continuar no programa.
    Recebe como parâmetros as janelas/botões escolhidos pelo o usuário;
    Ñão retorna nada;

*/

void css_editor(void);
/*

    Função de gerenciamento de cores, da tela de edição de texto.
    Não recebe parâmetros;
    Todas suas funções são da Ncurses para interface.
    Ñão retorna nada;

*/

void css_highlight(void);
/*

    Função de gerenciamento de cores das palavras reservadas da linguagem.
    Não recebe parâmetros;
    Todas suas funções são da Ncurses para interface.
    Ñão retorna nada;

*/

void fundo_editor(void);
/*

    Função que desenha as janelas de edição de texto.
    Não recebe parâmetros;
    Todas suas funções são da Ncurses para interface.
    Ñão retorna nada;

*/

void deleta_janela(WINDOW *janela);
/*

    Função que desaloca o ponteiro de WINDOW e atualiaza a janela.
    Recebe como parâmetros a janela aonde será realizada as operações à cima;
    Ñão retorna nada;

*/

void deleta_janela_string(WINDOW *janela);
/*

    Função que limpa os rezidos em telas deixados por outras funções.
    Recebe como parâmetros a janela aonde será realizada as operações à cima;
    Ñão retorna nada;

*/

#endif // PSEUDO_CSS_H_INCLUDED
