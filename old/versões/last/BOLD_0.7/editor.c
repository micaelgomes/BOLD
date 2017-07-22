#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <locale.h>
#include <string.h>
#include "pseudo_css.h"
#include "tabela_de_valor.h"
#include "editor.h"

    int letra; //caractere responsável pra despeijar a entrada no buffer
    int estado_aquivo = FALSE;
    int contador_coluna=0;
    int contador_linha=0;
    //int pos;

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
            case KEY_RIGHT:
                if(posicao.x < contador_coluna)
                {
                    getsyx(posicao.y, posicao.x);
                    posicao.x++;
                    move(posicao.y, posicao.x);
                    lugar_vetor++;
                }
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

void repara_terreno(void)
{
    refresh();

    deleta_janela(editor);
    deleta_janela(barra_editor);
    deleta_janela_string(stdscr);
    css_editor();
    fundo_editor();

    noecho();
    raw();
    curs_set(2);
    keypad(stdscr, TRUE);
    //attron(A_BOLD);

    refresh();

    return;
}

void editor_texto(void)
{
    letra = 0;
    posicao.y=1;
    posicao.x=0;

    while(letra != EOF)
    {
        letra = getch();

        if(letra == ENTER)
        {
            getsyx(posicao.y, posicao.x);
            posicao.x=0;
            posicao.y++;
            move(posicao.y, posicao.x);
            strcat(buffer, "\n");
            lugar_vetor++;
            contador_coluna=0;

        }

        else if(letra == KEY_BACKSPACE)
        {
            getsyx(posicao.y, posicao.x);
            posicao.x--;
            //mvaddstr(posicao.y, (posicao.x), " ");
            move(posicao.y, posicao.x);
            //lugar_vetor--;
            strcat(buffer, "\b");

            /*
            getsyx(posicao.y, posicao.x);
            posicao.x--;
            mvaddstr(posicao.y, posicao.x, " ");
            move(posicao.y, posicao.x);
            strcat(buffer, "\b");
            lugar_vetor = lugar_vetor-2;
            */
        }

        else if(letra == KEY_UP || letra == KEY_DOWN || letra == KEY_RIGHT || letra == KEY_LEFT) cursor(letra);

        else if(letra == KEY_F(1))
        {
            if(estado_aquivo == FALSE){
                salvar_arquivo(buffer);
                estado_aquivo = TRUE;
                deleta_janela_string(stdscr);

                attroff(A_BOLD);
                attron(COLOR_PAIR(3));
                box(barra_editor, 0, 0);
                attroff(COLOR_PAIR(3));

                attron(COLOR_PAIR(4));
                mvprintw(0,2,"Salvar(F1)");
                mvprintw(0,16,"Compilar(F5)");
                mvprintw(0,terminal.largura-9,"MENU(F9)");
                attroff(COLOR_PAIR(4));
                move(2,0);

                attron(A_BOLD);
                codigo = fopen(nome_arquivo,"w");
                fprintf(codigo, "%s", buffer);
                fclose(codigo);
            }
            else{
                codigo = fopen(nome_arquivo,"w");
                fprintf(codigo, "%s", buffer);
                fclose(codigo);
            }

        }

        else if(letra == KEY_F(5))
        {
            compilar();
        }

        else if(letra == KEY_F(9))
        {
            deleta_janela(barra_editor);
            deleta_janela(editor);
            deleta_janela_string(stdscr);
            estado_aquivo = FALSE;
            limpar_vetor(&buffer);
            lugar_vetor=0;
            menu();
        }

        else if(letra == 410)
        {
            repara_terreno();//removendo impurezas da tela
            editor_texto();// o nome já é bem sugestivo
        }

        else{

            posicao.x++;
            buffer[lugar_vetor] = letra;
            lugar_vetor++;
            atualizar(buffer, 0);
            contador_coluna++;
        }
        refresh();
    }

    getch();

    return;
}

void compilar(void)
{
    puts("Ainda não");
    return;
}
