char user_login[21];
char user_name[101];

int pesquisar_usuario (void)
{
	// String que acionará o "mysql_query":
	char query[2048];
	
	// Escanear informações do usuário:
	int opcao;
	printf ("Deseja pesquisar por nome de usuario, por login, ou ver a lista completa de usuarios?\n");
	printf ("Escolha uma opcao(1-Nome, 2-Login, 3-Lista completa): ");
	scanf ("%d", &opcao);
	getchar();
	
	// Pesquisar por nome:
	if (opcao == 1)
	{
		printf("Informe o nome a ser pesquisado: ");
		gets(user_name);
		
		sprintf(query, "SELECT Login, Nome_completo, Nivel_de_permissoes FROM Contas_de_usuario HAVING Nome_completo=%s && Estado_do_item=1", user_name);
		
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
		
		// Exibir linha com o nome pesquisado:
		printf("%s\n", linha);
		
		mysql_free_result(resultado);
	}
	
	// Pesquisar por login:
	else if (opcao == 2)
	{
		printf ("Informe o login a ser pesquisado(maximo de 20 caracteres): ");
		gets(user_login);
		
		sprintf(query, "SELECT Login, Nome_completo, Nivel_de_permissoes FROM Contas_de_usuario HAVING Login=%s && Estado_do_item=1", user_login);
		
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
		
		int linha = mysql_fetch_row(resultado);
		
		// Exibir linha com o login pesquisado:
		printf("%s\n", linha);
		
		mysql_free_result(resultado);
	}
	
	// Mostrar lista inteira:
	else if (opcao == 3)
	{
		// Consultar o BD:
		if (mysql_query(con, "SELECT Login, Nome_completo, Nivel_de_permissoes FROM Contas_de_usuario WHERE Estado_do_item=1"))
		{
			finish_with_error(con);
		}
		
		// Guardar o resultado:
		MYSQL_RES *resultado = mysql_store_result(con);
		
		if (resultado == NULL) 
		{
			finish_with_error(con);
		}
		
		int num_linhas = mysql_num_fields(resultado);
		
		MYSQL_ROW coluna;
		
		MYSQL_FIELD *linha;
		
		// Exibir resultado:
		while ((coluna = mysql_fetch_row(resultado))) 
		{ 
			for(int i = 0; i < num_linhas; i++) 
			{
				if (i == 0) 
				{              
					while(linha = mysql_fetch_field(resultado)) 
					{
						printf("%s ", linha->name);
					}
					printf("\n");           
				}
				printf("%s ", coluna[i] ? coluna[i] : "NULL");
			}
		}
		
		printf("\n");
		
		mysql_free_result(resultado);
	}
	return 0;
}
