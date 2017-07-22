/*
    Biblioteca responsável pelo gerenciamento e texto e compilação.
*/

#ifndef EDITOR_H_INCLUDED
#define EDITOR_H_INCLUDED

void cursor(int letra);
/*

    Função que move o cursor pela tela.
    recebe como parâmetro o caractere; não retorna.

*/

void prepara_terreno(void);
/*

    Função que apaga janejas para mudança de tela.
    Não recebe parâmetros; Todas suas funções são procedimentos.

*/

void editor_texto(void);
/*

    Função de edição de texto.
    Não recebe parâmetros; Todas suas funções são procedimentos.

*/

void pseudo_main(void);
/*

    Função de edição de texto.
    Não recebe parâmetros; Todas suas funções são procedimentos.

*/

void atualizar(void);
/*

    Função de edição de texto.
    Não recebe parâmetros; Todas suas funções são procedimentos.

*/

void atualizar_vetor(char *buffer_burro);
/*

    Função de edição de texto.
    Não recebe parâmetros; Todas suas funções são procedimentos.

*/

void highlight(void);
/*

    Função de edição de texto.
    Não recebe parâmetros; Todas suas funções são procedimentos.

*/

#endif // EDITOR_H_INCLUDED
