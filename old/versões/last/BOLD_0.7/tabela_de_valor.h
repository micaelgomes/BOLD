/*
    Biblioteca que guarda valores de importância para controle de dados.
    Ex: altura e largura de janelas.
*/

#ifndef TABELA_DE_VALOR_H_INCLUDED
#define TABELA_DE_VALOR_H_INCLUDED

#define ESCAPE 27
#define ENTER 10
#define SPACE 32
#define TRUE 1
#define FALSE 0

    struct _terminal_{
		int altura;
		int largura;
	}terminal;
    /*
        recebe altura e largura do terminal
    */

    struct _posicao_{
		int y;
		int x;
	}posicao;
	/*
        recebe valores para manipulação de cursor, tanto em tela como no buffer
    */

    struct _valor_temporario_{
		int altura;
		int largura;
	}valor_temporario;
    /*
        recebe valores aleatorios de janelas para operações rápidas
    */

    WINDOW *botao_inicio;//botão novo
    WINDOW *botao_abrir;//botao abrir
    WINDOW *barra;//barra com ESC
    WINDOW *editor;//janela de edição de texto
    WINDOW *barra_editor;//barra com comandos do editor
    WINDOW *check_box;//

    FILE *codigo;

    char temporario[1024];
    char temporario_abertura[1024];
    char *nome_abertura;
    char *nome_arquivo;

    char buffer[500000];//buffer de testes ocasionais

    int lugar_vetor;//relaciona a posição do cursor com o vetor

#endif // TABELA_DE_VALOR_H_INCLUDED
