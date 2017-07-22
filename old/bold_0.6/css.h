/*
    Biblioteca responsável pelo gerenciamento e criação de cores e formações de layout.
*/

#ifndef CSS_H_INCLUDED
#define CSS_H_INCLUDED

//FUNÇÕES DE ORGANIZAÇÃO
void css_home(void);
/*

    Função de gerenciamento de cores, da tela principal.
    Não recebe parâmetros; Todas suas funções são procedimentos.

*/

void css_editor(void);
/*

    Função de gerenciamento de cores, da tela de edição de texto.
    Não recebe parâmetros; Todas suas funções são procedimentos.

*/

void fundo_editor(void);
/*

    Função desenha uma "lousa" para facilitar a vida do programador.
    Não recebe parâmetros; Todas suas funções são procedimentos.

*/

void marca(void);
/*

    Função apenas desenha a marca da empresa.

*/

//FUNÇÕES INTERARTIVAS
void layout_botoes(void);
/*

    Função que cria e desenha janelas(botões) na interface.
    Não retorna nada; Não recebe parâmetros.

*/

void box_abrir(void);
/*

    Função  desenha a box de arquivo na interface.
    Não retorna nada; Não recebe parâmetros.

*/

//FUNÇÕES DE ORGANIZAÇÃO COM PARÂMETROS
void selecionado(WINDOW *janela_on, WINDOW *janela_off);
/*

    Função que evidencia janelas na interface.
    Não retorna nada;
    1ª parâmetro é a janela a ser evidenciada.
    2ª parâmetro é a janela que perderá a contraste de tela(não será evidenciada);

*/

void deleta_janela(WINDOW *janela);
/*

    Função que apaga janelas na interface.
    Não retorna nada; Recebe como parâmetro a janela a ser apagada.

*/

void deleta_janela_string(WINDOW *janela);
/*

    Função que apaga as strings contidas nas janelas na interface.
    Não retorna nada; Recebe como parâmetro a janela a ser apagada.

*/

#endif // CSS_H_INCLUDED
