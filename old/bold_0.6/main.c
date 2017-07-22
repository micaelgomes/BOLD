/*

  IDE: BOLD
  =========
  (c) Copyright Micael Gomes 2016
  Email: micaellgoms@gmail.com

*/

#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <locale.h>

#include "css.h"
#include "tabela_de_valor.h"
#include "editor.h"

int main(void)
{
    system("gcc abertura.c -o exe -lncurses");
	system("./exe");

	pseudo_main();//função que realiaza todas as funções da main sem a animação; pois ela é chamada novamente

	return 0;
}
