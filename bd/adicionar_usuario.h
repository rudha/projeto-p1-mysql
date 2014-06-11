#ifndef _adicionar_usuario_h
#define _adicionar_usuario_h

// Declarar variáveis das informações do usuário:
char user_login [21];
char user_password [21];
char user_name [101];
int permission;

void insert_login (void);
void insert_password (void);
void insert_name (void);
void insert_permission (void);

int adicionar_usuario (void)
{
	// String que acionará o "mysql_query":
	char query[2048];
	
	// Limpar toda a tela:
	system ("clear");
	
	// Escanear informações do usuário:
	insert_login();
	
	insert_password();
	
	insert_name();
	
	insert_permission();
	
	sprintf(query, "INSERT INTO Contas_de_usuario (Login, Senha, Nome_completo, Nivel_permissoes) VALUES(%s, %s, %s, %d)", user_login, user_password, user_name, permission);
	
	// Consultar o BD:
	if (mysql_query(con, query))
	{
		finish_with_error(con);
		return 1;
	}
	return 0;
}

void insert_login (void)
{
	printf ("Informe o login do usuario:\n");
	printf("(maximo de 20 caracteres)\n");
	gets(user_login);
	getchar();
}

void insert_password (void)
{
	printf("Informe a senha do usuario:\n");
	printf("(maximo de 20 caracteres)\n");
	gets(user_password);
	getchar();
}

void insert_name (void)
{
	printf("Informe o nome completo do usuario:\n");
	printf("(maximo de 100 caracteres)\n");
	gets(user_name);
	getchar();
}

void insert_permission (void)
{
	printf("Informe o nivel de permissoes do usuario:\n\n");
   	printf("1 - Visualizar produtos e lotes apenas.\n");
   	printf("2 - Visualizar lotes e produtos, e adicionar lotes.\n");
   	printf("3 - Visualizar, editar e adicionar lotes e produtos.\n");
   	printf("4 - Visualizar, editar e adicionar lotes, produtos e contas de usuario.\n");
   	printf("\nINFORME APENAS O NUMERO DE PERMISSAO\n");
   
   	scanf("%d", &permission);
   	getchar();
}

#endif
