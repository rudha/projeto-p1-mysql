//
//  main.c
//  Controle_de_estoque_UNIUM
//
//  Created by Bruno Chroniaris on 6/6/14.
//  Copyright (c) 2014 Bruno Chroniaris. All rights reserved.
//

#define PSWD "12345"
#define USER "root"
#define HOST "localhost"

#include <stdio.h>
#include <string.h>
#include <my_global.h>
#include <mysql.h>


// Structs

// Global Var

// Functions Def.
void print_welcome_interface (void); // will print the first screen, if the conection is sucessful.
void main_menu (void);
int get_menu_to_select (void);
int ger_prod_menu (void);
int get_ger_prod_option (void);
int ger_usr_menu (void);
int get_ger_usr_option (void);
void finish_with_error (MYSQL *con);
int confirm_exit (void);


// Main Function
int main(int argc, const char * argv[])
{
    MYSQL *conexao = mysql_init(NULL);
    
    if (conexao == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }
    
    if (mysql_real_connect(con, "HOST", "USER", "PSWD",
                           NULL, 0, NULL, 0) == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        mysql_close(con);
        exit(1);
    }
    
    print_welcome_interface();
    
    do
    {
        main_menu();
        
    } while (confirm_exit());
    
    mysql_close(conexao);
    exit(0);
}

// Bodies
void print_welcome_interface (void)
{
    system ("clear");
    
    printf("Bem-vindo ao controle de estoque UNIUM!\n");
    printf("\n");
    printf("Aperte Enter para continuar:\n");
    
    getchar();
}
void main_menu (void)
{
    int menu_select = 100;
    int loop = 1;
    
    do {
        switch (menu_select)
        {
            case 100:
                menu_select = get_menu_to_select();
                break;
            case 1:
                menu_select = ger_prod_menu();
                break;
            case 2:
                menu_select = ger_usr_menu();
                break;
            default:
                loop = 0;
                break;
        }
    } while (loop);
}

int get_menu_to_select (void)
{
    int option;
    
    system("clear");
    printf("\n");
    printf("Qual area do programa voce deseja acessar?\n");
    printf("\n");
    printf("1 - Gerenciamento de produtos\n");
    printf("2 - Gerenciamento de contas\n");
    printf("0 - Sair\n");
    
    option = getchar() - '0';
    getchar();
    
    return option;
}

int ger_prod_menu (void)
{
    int menu_select = 100;
    int loop;
    
    switch (menu_select)
    {
        case 100:
            menu_select = get_ger_prod_option();
            break;
        case 1:
            menu_select = adicionar_produto();
            break;
        case 2:
            menu_select = editar_produto();
            break;
        case 3:
            menu_select = pesquisar_produto();
            break;
        case 4:
            menu_select = adicionar_lote();
            break;
        case 5:
            menu_select = editar_lote();
            break;
        case 6:
            menu_select = pesquisar_lote();
            break;
            
        default:
            return 100;
            break;
    }
}

int get_ger_prod_option (void)
{
    int option;
    
    system("clear");
    printf("\n");
    printf("Qual das acoes a seguir voce deseja executar?\n");
    printf("\n");
    printf("1 - Cadastrar Produto\n");
    printf("2 - Editar Produto\n");
    printf("3 - Pesquisar Produto\n");
    printf("4 - Adicionar Lote\n");
    printf("5 - Editar Lote\n");
    printf("6 - Pesquisar Lote\n");
    printf("0 - Voltar\n");
    
    option = getchar()- '0';
    getchar();
    
    return option;
}

int ger_usr_menu (void)
{
    int menu_select = 100;
    
    switch (menu_select)
    {
        case 100:
            menu_select = get_ger_usr_menu();
            break;
        case 1:
            menu_select = adicionar_usuario();
            break;
        case 2:
            menu_select = editar_usuario();
            break;
        case 3:
            menu_select = pesquisar_usuario();
            break;
            
        default:
            return 100;
            break;
    }
}

int get_ger_usr_option (void)
{
    int option;
    
    system("clear");
    printf("\n");
    printf("Qual das acoes a seguir voce deseja executar?\n");
    printf("\n");
    printf("1 - Adicionar usuario\n");
    printf("2 - Editar usuario\n");
    printf("3 - Pesquisar usuario\n");
    printf("0 - Voltar;\n");
    
    option = getchar() - '0';
    getchar();
    
    return option;
}

int confirm_exit (void)
{
    int option;
    
    system("clear");
    printf("\n");
    printf("Tem certeza que deseja finalizar o programa?\n");
    printf("\n");
    printf("1 - SIM\n");
    printf("2 - NAO\n");
    
    option = getchar() - '0';
    getchar();
    
    if (option == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}
