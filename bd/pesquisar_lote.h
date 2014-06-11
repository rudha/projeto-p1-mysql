#ifndef _pesquisar_lote_h
#define _pesquisar_lote_h

int id;

struct data
{
	int dia;
	int mes;
	int ano;
};

struct data data

int pesquisar_produto (void)
{
	// String que acionará o "mysql_query":
	char query[2048];
	
	// Escanear informações do usuário:
	int opcao;
	printf ("Deseja pesquisar o lote por Id do produto ou por Data de entrada?\n");
	printf ("Escolha uma opcao(1-Id, 2-Data): ");
	scanf ("%d", &opcao);
	getchar();
	
	if (opcao == 1)
	{
		printf ("Informe o Id do produto a ser pesquisado: ");
		scanf ("%d", &id);
		getchar();
		
		sprintf(query, "SELECT Id, Id_do_produto, Nome_do_produto, Fabricante, Tempo_de_garantia, Referencia, Data_de_entrada, Quantidade, Valor_de_compra FROM Lotes HAVING Id_do_produto=%d && Estado_do_item=1", id);
		
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
		
		// Exibir linha com o Id do produto pesquisado:
		printf("%s\n", linha);
		
		mysql_free_result(resultado);
	}
	
	else if (opcao == 2)
	{
		printf ("Informe a Data de entrada do lote a ser pesquisado no formato DD/MM/AAAA: ");
		scanf ("%d/%d/%d", &data.dia, &data.mes, &data.ano);
		getchar();
		
		sprintf(query, "SELECT Id, Id_do_produto, Nome_do_produto, Fabricante, Tempo_de_garantia, Referencia, Data_de_entrada, Quantidade, Valor_de_compra FROM Lotes HAVING Data_de_entrada=%d-%d-%d && Estado_do_item=1", data.dia, data.mes, data.ano);
		
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
}

#endif
