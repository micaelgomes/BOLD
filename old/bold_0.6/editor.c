#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <locale.h>
#include <string.h>

#include "css.h"
#include "tabela_de_valor.h"
#include "editor.h"

#define ESCAPE 27
#define ENTER 10

void cursor(int letra)
{
     switch(letra)
        {
            case KEY_UP:
            if(posicao.y <= 2)
            {
                posicao.y = 2;
                getsyx(posicao.y, posicao.x);
                move(posicao.y, posicao.x);

            }
            else{
                getsyx(posicao.y, posicao.x);
                posicao.y--;
                move(posicao.y, posicao.x);
            }
                break;

            case KEY_DOWN: getsyx(posicao.y, posicao.x); posicao.y++; move(posicao.y, posicao.x);
                break;
            case KEY_LEFT:
            if(posicao.x <= 0)
            {
                posicao.x = 0;
                getsyx(posicao.y, posicao.x);
                move(posicao.y, posicao.x);
                lugar_vetor--;

            }
            else{
                getsyx(posicao.y, posicao.x);
                posicao.x--;
                move(posicao.y, posicao.x);
            }
                break;
            case KEY_RIGHT: getsyx(posicao.y, posicao.x); posicao.x++; move(posicao.y, posicao.x);
                lugar_vetor++;
                break;

            default: break;
        }

    return;
}

void prepara_terreno(void)
{
    deleta_janela(botao_inicio);
    deleta_janela(botao_abrir);
    deleta_janela_string(stdscr);

    refresh();

    css_editor();
    fundo_editor();

    noecho();
    raw();
    curs_set(2);
    keypad(stdscr, TRUE);
    attron(A_BOLD);

    return;
}

void editor_texto(void)
{
    letra = 0;
    lugar_vetor=0;
    posicao.y=1;
    posicao.x=1;
    total_enter=1;

    while(letra != EOF)
    {
        letra = getch();

        if(letra == ENTER)
        {
            getsyx(posicao.y, posicao.x);
            posicao.x=0;
            posicao.y++;
            move(posicao.y, posicao.x);
            strcat(buffer_burro, "\n");
            lugar_vetor++;

        }

        else if(letra == KEY_BACKSPACE)
        {
            getsyx(posicao.y, posicao.x);
            posicao.x--;
            mvaddstr(posicao.y, (posicao.x), " ");
            move(posicao.y, posicao.x);
            strcat(buffer_burro, "\b");
            lugar_vetor--;
            //buffer_burro[posicao.y][posicao.x] = ' ';
        }

        else if(letra == KEY_UP || letra == KEY_DOWN || letra == KEY_RIGHT || letra == KEY_LEFT) cursor(letra);

        else if(letra == KEY_F(1))
        {
            codigo = fopen("file_temp/codigo.c","w");
                fprintf(codigo, "%s", buffer_burro);

            fclose(codigo);
        }

        else if(letra == KEY_F(5))
        {
            //deleta_janela(editor);
            //compilador = subwin(stdscr, 7, 17, (terminal.altura/2)-5, (terminal.largura/2)-9);
            //box(compilador, 0, 0);
            system("gcc file_temp/codigo.c -o exe -lncurses -lm");
            system("./exe");;
        }

        else if(letra == KEY_F(9))
        {
            deleta_janela(barra_editor);
            deleta_janela(editor);
            deleta_janela_string(stdscr);
            //atualizar_vetor(buffer_burro);
            free (buffer_burro[5000]);
            pseudo_main();
        }

        else{
            posicao.x++;
            buffer_burro[lugar_vetor] = letra;

            //buffer[posicao.y][20][lugar_vetor]= letra;
            lugar_vetor++;

            //printw("%c", buffer_burro[lugar_vetor-1]);
            highlight();
            atualizar();
        }

        refresh();
    }

    getch();

    return;
}

void pseudo_main(void)
{
    initscr();// inicia o ecrã
	start_color();//incia o gerenciamento de cores da Ncurses

		getmaxyx(stdscr, terminal.altura, terminal.largura); //pegando as dimensões do terminal

    css_home();//define as cores da home

        noecho();
        curs_set(0);
        keypad(stdscr, TRUE);
        keypad(botao_inicio, TRUE);
        keypad(botao_abrir, TRUE);


    marca();
    layout_botoes();//desenha: botoes-janelas
    selecionado(botao_inicio, botao_abrir);
    boleano = TRUE;

//execução da home ---------------------------------------------------
		do{
			ch=getch();
			if(ch == KEY_DOWN)
			{
                selecionado(botao_abrir, botao_inicio);
                boleano = FALSE;
			}

			if(ch == KEY_UP)
			{
                selecionado(botao_inicio, botao_abrir);
                boleano = TRUE;
			}

            if(ch == ENTER && boleano == TRUE)
			{
                prepara_terreno();//removendo impurezas da tela
                editor_texto();// o nome já é bem sugestivo
			}

			if(ch == ENTER && boleano == FALSE)
			{
                box_abrir();
			}

    	}while(ch != ESCAPE);

	endwin();//finaliza o ecrã
	printf("Volte Sempre e traga mais um!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    exit(0);
    return;
}

void atualizar(void)
{
    deleta_janela_string(editor);
    refresh();
    posicao.x=0;
    posicao.y=2;
    move(posicao.y, posicao.x);

    i=0;
    while(buffer_burro[i] != EOF){
        printw("%c", buffer_burro[i]);
        i++;
    }

    return;
}

void atualizar_vetor(char *buffer_burro)
{
    while(buffer_burro[i] != EOF){
        buffer_burro[i] = ' ';
        i++;
    }

    return;
}

void highlight(void)
{
        if(buffer_burro[lugar_vetor] == 'i')
        {
            puts("asd");
            getsyx(posicao.y, posicao.x);
            attron(COLOR_PAIR(9));
            mvprintw(posicao.y, posicao.x, "int");
            attroff(COLOR_PAIR(9));
        }

    return;
}
