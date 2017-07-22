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
	system("clear");
	printf("Programa Finalizado!\n");
	puts("=====================\n\n");
    exit(2017);

    return;
}

void atualizar(char *buffer,int pos)
{
    move(2,0);
    css_highlight();
    addstr(buffer);

        highlight(buffer, "int", 3, 12);
        highlight(buffer, "float", 5, 12);
        highlight(buffer, "double", 5, 12);
        highlight(buffer, "char", 4, 12);
        highlight(buffer, "long", 4, 12);
        highlight(buffer, "do", 2, 12);
        highlight(buffer, "if", 2, 12);
        highlight(buffer, "for", 3, 12);
        highlight(buffer, "while", 5, 12);
        highlight(buffer, "void", 4, 12);
        highlight(buffer, "continue", 8, 12);
        highlight(buffer, "volatile", 8, 12);
        highlight(buffer, "unsigned", 8, 12);
        highlight(buffer, "typedef", 7, 12);
        highlight(buffer, "union", 5, 12);
        highlight(buffer, "switch", 6, 12);
        highlight(buffer, "struct", 6, 12);
        highlight(buffer, "static", 6, 12);
        highlight(buffer, "sizeof", 6, 12);
        highlight(buffer, "short", 5, 12);
        highlight(buffer, "return", 6, 12);
        highlight(buffer, "register", 8, 12);
        highlight(buffer, "extern", 6, 12);
        highlight(buffer, "else", 4, 12);
        highlight(buffer, "break", 5, 12);
        highlight(buffer, "const", 5, 12);
        highlight(buffer, "signed", 5, 12);
        highlight(buffer, "enum", 4, 12);
        highlight(buffer, "default", 7, 12);
        highlight(buffer, "case", 4, 12);
        highlight(buffer, "auto", 4, 12);
        highlight(buffer, "goto", 4, 12);
        highlight(buffer, "#define", 7, 11);
        highlight(buffer, "#include", 8, 11);
        highlight(buffer, "<stdio.h>", 9, 15);
        highlight(buffer, "<stdlib.h>", 10, 15);
        highlight(buffer, "<ncurses.h>", 11, 10);

    return;
}

void highlight(char *buffer, char *palavra, int tam, int cor)
{
    char buffer_aux[MAX];
    strcpy(buffer_aux, buffer);

    char *local=NULL,*token=NULL;
    int a,cont=2,cont2=0;
    refresh();

    token = strtok(buffer_aux, "\n");
    int i = 0;
    while(token!=NULL){
       local= strstr(buffer_aux,palavra);
       while(local!=NULL){
           a=local-token;
           mvchgat(cont, a, tam, A_BOLD, cor, NULL);
           local=strstr(local+strlen(palavra), palavra);
       }

        token=strtok(NULL, "\n");
        local=NULL;
        cont++;
        getsyx(posicao.y, posicao.x);
        move(posicao.y, posicao.x);
        i++;
    }
    return;
}

void busca(char *buffer, char *busca)
{


    char *local=NULL,*token=NULL;
    int a,cont=2,cont2=0;
    refresh();

    token = strtok(buffer, "\n");
    int i = 0;
    while(token!=NULL){
       local= strstr(buffer, busca);
       while(local!=NULL){
           a=local-token;
           mvchgat(cont, a, strlen(busca), A_BLINK | A_UNDERLINE ,13, NULL);
           local=strstr(local+strlen(busca), busca);
       }

        token=strtok(NULL, "\n");
        local=NULL;
        cont++;
        getsyx(posicao.y, posicao.x);
        move(posicao.y, posicao.x);
        i++;
    }
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

void limpar_vetor(char *buffer)
{
    //char nada[500000];//copiando uma string vazia pra limpar o buffer
    //strcpy(buffer, nada);
    int i;
    for(i=0;i<MAX;i++){
        buffer[i]='\b';
    }
    return;
}
