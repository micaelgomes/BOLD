#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <string.h>

int main(void)
{
	initscr();
	WINDOW *logo;
	int largura, altura;

	getmaxyx(stdscr, altura, largura);
    
    start_color();
    init_pair(9,COLOR_CYAN,COLOR_BLACK);
    bkgd(COLOR_PAIR(9));
    curs_set(0);

    attron(A_BOLD);
    logo = subwin(stdscr, 7, 17, (altura/2)-5, (largura/2)-9);
    wborder(logo,'#','#','#','#','#','#','#','#');
    mvaddstr((altura/2)-2, (largura/2)-5, "BOLD 0.5.7");
    mvaddstr((altura/2)+4, (largura/2)-9 ,"[               ]");
    noecho();
    refresh();

    halfdelay(10);
    getch();
    mvaddstr((altura/2)+4, (largura/2)-9 ,"[==========     ]");

    halfdelay(20);
    getch();
    mvaddstr((altura/2)+4, (largura/2)-9 ,"[===============]");

    halfdelay(10);
    getch();

    attroff(A_BOLD);
    attroff(COLOR_PAIR(9));
    delwin(logo);

    refresh();
    endwin();
    return 0;
}
