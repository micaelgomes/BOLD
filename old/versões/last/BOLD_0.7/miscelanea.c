#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ncurses.h>
#include "tabela_de_valor.h"
#include "pseudo_css.h"
#include "editor.h"

void menu(void)
{
    int ch;//recebe do usuário a opção do menu
    int boleano; //recebe valores de menu para novo ou abrir.

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

		do{
			ch=getch();
			if(ch == KEY_DOWN)
			{
                selecionado(botao_abrir, botao_inicio);
                boleano = FALSE;
			}

			if(ch == KEY_UP)
			{
                selecionado(botao_inicio, botao_abrir);//contorno de (*) ao redor do botão
                boleano = TRUE;
			}

            if(ch == ENTER && boleano == TRUE)
			{
                prepara_terreno();//removendo impurezas da tela
                editor_texto();// o nome já é bem sugestivo
			}

			if(ch == ENTER && boleano == FALSE)
			{
                abrir_arquivo(buffer);//função traz pra memoria o que está em arquivo
                editor_texto();
			}

			if(ch == 410)
			{
                deleta_janela(barra_editor);
                deleta_janela(editor);
                deleta_janela_string(stdscr);
                menu();
			}

    	}while(ch != ESCAPE);

	endwin();//finaliza o ecrã
	printf("Programa Finalizado!\n");
	puts("=====================\n\n");
    exit(2017);

    return;
}

void atualizar(char *buffer,int pos)
{
    move(2,0);
    //addstr(buffer);

    int i;
    for(i=pos;i<(terminal.largura*terminal.altura);i++){

        if(buffer[i]=='i') puts("morre");
        printw("%c", buffer[i]);
        highlight(buffer, i);

    }
    return;
}

void highlight(char *buffer, int pos){

     /*if(buffer[i] == 't' && buffer[i-1] == 'n' && buffer[i-2] == 'i'  && buffer[i-3] == ' '){
            getsyx(posicao.y, posicao.x);
            move(posicao.y, posicao.x-3);
            init_pair(10, COLOR_RED, COLOR_BLACK);
            attron(COLOR_PAIR(10));
            printw("%c", buffer[i-2]);
            printw("%c", buffer[i-1]);
            printw("%c", buffer[i]);
            attroff(COLOR_PAIR(10));
            //move(posicao.y, posicao.x+4);
            }*/

     return;
}

void salvar_arquivo(char *buffer)
{
    deleta_janela_string(stdscr);
    echo();
    curs_set(2);
    mvprintw(((terminal.altura)/2)-4, ((terminal.largura)/2)-19,"Insira o diretório que deseja salvar:");
    mvprintw(((terminal.altura)/2)-3, ((terminal.largura)/2)-20,"Ex: nome_pasta/nome_arquivo.tipo_arquivo ");
    mvprintw(((terminal.altura)-1), ((terminal.largura)-45),"Obs: informe diretórios que estajam criados");
    mvprintw(((terminal.altura)/2)-1, ((terminal.largura)/2)-9,":");
    move((((terminal.altura)/2)-1), (((terminal.largura)/2)-8));

    getstr(temporario);

    nome_arquivo = (char*)malloc(strlen(temporario) * sizeof(char));
    strcpy(nome_arquivo, temporario);

    codigo = fopen(nome_arquivo,"w");
    fprintf(codigo, "%s", buffer);
    fclose(codigo);
    return;
}

void abrir_arquivo(char *buffer)
{
    posicao.y=0;

    char temp_arquivo[1024];
    deleta_janela_string(stdscr);
    echo();
    curs_set(2);
    mvprintw(((terminal.altura)/2)-4, ((terminal.largura)/2)-19,"Insira o diretório que deseja salvar:");
    mvprintw(((terminal.altura)/2)-3, ((terminal.largura)/2)-20,"Ex: nome_pasta/nome_arquivo.tipo_arquivo ");
    mvprintw(((terminal.altura)-1), ((terminal.largura)-45),"Obs: informe diretórios que estajam criados");
    mvprintw(((terminal.altura)/2)-1, ((terminal.largura)/2)-9,":");
    move((((terminal.altura)/2)-1), (((terminal.largura)/2)-8));

    refresh();
    getstr(temporario);
    nome_arquivo = (char*)malloc(strlen(temporario) * sizeof(char));
    strcpy(nome_arquivo, temporario);
    codigo = fopen(nome_arquivo,"r");

    if(codigo == NULL)
    {
        mvprintw(((terminal.altura)/2)+2, ((terminal.largura)/2)-19,"Erro, nao foi possivel abrir o arquivo!\n");
        getch();
        endwin();
        printf("Diretório Inválido!\n");
        puts("=====================\n\n");
        exit(999);
    }
	else{
        while((fgets(temp_arquivo, sizeof(temp_arquivo), codigo)) != NULL)
        {
            strcat(buffer, temp_arquivo);
            posicao.y++;
        }
    }

    move(2,0);
    prepara_terreno();//removendo impurezas da tela
    posicao.y++;
    fclose(codigo);
    atualizar(buffer, 0);
    lugar_vetor = strlen(buffer);

    return;
}

void limpar_vetor(char **buffer)
{

    return;
}
