#ifndef _adicionar_produto_h
#define _adicionar_produto_h

struct produto
{
	int id;
	char nome[101];
	char fabricante[101];
	float garantia;
	char referencia[21];
	int estado;
};

int adicionar_produto (void);

#endif
