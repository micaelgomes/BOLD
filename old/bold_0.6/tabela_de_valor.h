/*
    Biblioteca que guarda valores de importância para controle de dados.
    Ex: altura e largura de janelas e/ou declarações de váriaveis.
*/

#ifndef TABELA_DE_VALOR_H_INCLUDED
#define TABELA_DE_VALOR_H_INCLUDED

//Tabelas
	 struct _terminal_{ //recebe altura e largura do terminal
		int altura;
		int largura;
	}terminal;

	struct _valor_temporario_{ //recebe valores aleatorios de janelas para operações rápidas
		int altura;
		int largura;
	}valor_temporario;

	struct _posicao_{ //recebe valores para manipulação de cursor
		int y;
		int x;
	}posicao;

//Váriaveis
    WINDOW *botao_inicio;
    WINDOW *botao_abrir;
    WINDOW *barra;
    WINDOW *editor;
    WINDOW *barra_editor;
    WINDOW *logo;

    FILE *codigo;

    char letra_tmp;
    char temporario[1024];
    char buffer_burro[5000];//buffer de testes ocasionais
    char buffer[10][20][1024];

    int total_enter;
    int lugar_vetor;//relaciona a posição do cursor com o vetor
    int letra; //caractere responsável pra despeijar a entrada no buffer
    int ch;//caractere de escolha para a tela de boas vindas
    int boleano; //recebe valores de menu para novo ou abrir.

    int i, j, k;//váriaveis de interação

#endif // TABELA_DE_VALOR_H_INCLUDED
