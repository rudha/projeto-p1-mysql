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

int pesquisar_produto (void)
{
	// String que acionará o "mysql_query":
	char query[2048];
	
	// Escanear informações do usuário:
	int opcao;
	printf ("Deseja pesquisar o produto por Id, por nome, por fabricante, ou por referencia?\n");
	printf ("Escolha uma opcao(1-Id, 2-Nome, 3-Fabricante, 4-Referencia): ");
	scanf ("%d", &opcao);
	getchar();
	
	if (opcao == 1)
	{
		printf ("Informe o Id a ser pesquisado: ");
		scanf ("%d", &prod.id);
		getchar();
		
		sprintf(query, "SELECT Id, Nome, Fabricante, Tempo_de_garantia, Referencia FROM Produtos HAVING Id=%d && Estado_do_item=1", prod.id);
		
		// Consultar o BD:
		if (mysql_query(con, query))
		{
			finish_with_error(con);
		}
		
		// Guardar o resultado:
		MYSQL_RES *resultado = mysql_store_result(con);
		
		MYSQL_ROW *linha;
		
		if (resultado == NULL) 
		{
			finish_with_error(con);
		}
		
		linha = mysql_fetch_row(resultado);
		
		// Exibir linha com o Id pesquisado:
		printf("%s\n", linha);
		
		mysql_free_result(resultado);
	}
	
	else if (opcao == 2)
	{
		printf ("Informe o Nome a ser pesquisado: ");
		gets(prod.nome);
		
		sprintf(query, "SELECT Id, Nome, Fabricante, Tempo_de_garantia, Referencia FROM Produtos HAVING Nome=%s && Estado_do_item=1", prod.nome);
		
		// Consultar o BD:
		if (mysql_query(con, query))
		{
			finish_with_error(con);
		}
		
		// Guardar o resultado:
		MYSQL_RES *resultado = mysql_store_result(con);
		
		MYSQL_ROW *linha;
		
		if (resultado == NULL) 
		{
			finish_with_error(con);
		}
		
		linha = mysql_fetch_row(resultado);
		
		// Exibir linha com o Nome pesquisado:
		printf("%s\n", linha);
		
		mysql_free_result(resultado);
	}
	
	else if (opcao == 3)
	{
		printf ("Informe o Fabricante a ser pesquisado: ");
		gets(prod.nome);
		
		sprintf(query, "SELECT Id, Nome, Fabricante, Tempo_de_garantia, Referencia FROM Produtos HAVING Fabricante=%s && Estado_do_item=1", prod.fabricante);
		
		// Consultar o BD:
		if (mysql_query(con, query))
		{
			finish_with_error(con);
		}
		
		// Guardar o resultado:
		MYSQL_RES *resultado = mysql_store_result(con);
		
		MYSQL_ROW *linha;
		
		if (resultado == NULL) 
		{
			finish_with_error(con);
		}
		
		linha = mysql_fetch_row(resultado);
		
		// Exibir linha com o Fabricante pesquisado:
		printf("%s\n", linha);
		
		mysql_free_result(resultado);
	}
	
	else if (opcao == 4)
	{
		printf ("Informe a Referencia a ser pesquisada: ");
		gets(prod.referencia);
		
		sprintf(query, "SELECT Id, Nome, Fabricante, Tempo_de_garantia, Referencia FROM Produtos HAVING Referencia=%s && Estado_do_item=1", prod.referencia);
		
		// Consultar o BD:
		if (mysql_query(con, query))
		{
			finish_with_error(con);
		}
		
		// Guardar o resultado:
		MYSQL_RES *resultado = mysql_store_result(con);
		
		MYSQL_ROW *linha;
		
		if (resultado == NULL) 
		{
			finish_with_error(con);
		}
		
		linha = mysql_fetch_row(resultado);
		
		// Exibir linha com a Referencia pesquisada:
		printf("%s\n", linha);
		
		mysql_free_result(resultado);
	}
	
	return 0;
}

#endif
