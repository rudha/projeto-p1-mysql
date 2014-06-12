#ifndef _pesquisar_produto_h
#define _pesquisar_produto_h

struct produto
{
	int id;
	char nome[101];
	char fabricante[101];
	char referencia[21];
};

struct produto prod;

int pesquisar_produto (void);

#endif
