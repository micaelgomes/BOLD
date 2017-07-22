#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ncurses.h>
#include "miscelanea.h"
#include "pseudo_css.h"

int main(void)
{
    system("gcc abertura.c -o exe -lncurses");
	system("./exe");
    /*
        Os comandos à cima executam a animação de abertura do programa;
        Optei por chamar de fora do programa, pois a função Halfdelay() estava bugando o
        resto do código.
    */

    menu();//chama as funções de abertura do programa e executa as opções escolhidas pelo usuário

    return 0;
}
