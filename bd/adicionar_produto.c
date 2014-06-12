#include <stdio.h>
#include <my_global.h>
#include <mysql.h>
#include <string.h>
#include "adicionar_produto.h"

int adicionar_produto (void)
{		
	int loop; // Para perguntar se o usuário quer adicionar mais produtos
	
	do
	{
		printf("Nome do produto a ser adicionado: ");
		gets(prod.nome);
		printf("\n");
		
		printf("Fabricante do produto: ");
		gets(prod.fabricante);
		printf("\n");
		
		printf("Garantia do produto(em anos): ");
		scanf("%f", &prod.garantia);
		getchar();
		printf("\n");
		
		printf("Referencia do produto: ");
		gets(prod.referencia);
		printf("\n");
		
		prod.estado=1;
		
		char query[2048];
		sprintf(query, "INSERT INTO Produtos (Nome, Fabricante, Tempo_de_garantia, Referencia, Estado_do_item) VALUES (%s, %s, %f, %s, %d)", prod.nome, prod.fabricante, prod.garantia, prod.referencia, prod.estado);
		
		if (mysql_query(con, query))
		{
			finish_with_error(con);
		}
		
		printf("\n");
		printf("Produto adicionado com sucesso!\n");
		printf("\n");
		
		printf("Quer adicionar outro item?(1-Sim, 2-Nao): ");
		scanf("%d", &loop);
		getchar();
		printf("\n");
	} while(loop==1);
}
