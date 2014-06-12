//
//  main.c
//  Controle_de_estoque_UNIUM
//
//  Created by Bruno Chroniaris on 6/6/14.
//  Copyright (c) 2014 Bruno Chroniaris. All rights reserved.
//

#define PSWD 12345
#define USER root
#define HOST localhost
#define conexao con

#include <stdio.h>
#include <string.h>
#include <my_global.h>
#include <mysql.h>


// Structs
struct main_user
{
    char Login[21];
    char Password[21];
    char name[101];
    int permission;
    int activity
};

// Global Var

// Functions Def.
void print_welcome_interface (void); // will print the first screen, if the conection is sucessful.
void main_menu (struct main_user *user);
int get_menu_to_select (struct main_user *user);
int ger_prod_menu (struct main_user *user);
int get_ger_prod_option (struct main_user *user);
int ger_usr_menu (void);
int get_ger_usr_option (void);
void finish_with_error (MYSQL *con);
int confirm_exit (void);
struct main_user user_login (void);
struct main_user get_user_info (char Password[21], char Login[21]);

// Main Function
int main(int argc, const char * argv[])
{
    struct main_user Logged_user;
    
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
    Logged_user = user_login();
    
    do
    {
        main_menu(&Logged_user);
        
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
void main_menu (struct main_user *user)
{
    int menu_select = 100;
    int loop = 1;
    
    if (user->permission == 1 || user->permission == 2 || user->permission == 3)
    {
        do {
                switch (menu_select)
                {
                    case 100:
                        menu_select = get_menu_to_select(user);
                        break;
                    case 1:
                        menu_select = ger_prod_menu(user);
                        break;
                    //case 2:
                        //menu_select = ger_usr_menu();
                        //break;
                    default:
                        loop = 0;
                        break;
                }
            } while (loop);
    }
    else if (user->permission == 4)
    {
        do {
            switch (menu_select)
            {
                case 100:
                    menu_select = get_menu_to_select(user);
                    break;
                case 1:
                    menu_select = ger_prod_menu(user);
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
}

int get_menu_to_select (struct main_user *user)
{
    int option;
    
    system("clear");
    
    if (user->permission >= 1 && user->permission <4)
    {
        printf("\n");
        printf("Qual area do programa voce deseja acessar?\n");
        printf("\n");
        printf("1 - Gerenciamento de produtos\n");
        //printf("2 - Gerenciamento de contas\n");
        printf("0 - Sair\n");
    }
    else if (user->permission == 4)
    {
        printf("\n");
        printf("Qual area do programa voce deseja acessar?\n");
        printf("\n");
        printf("1 - Gerenciamento de produtos\n");
        printf("2 - Gerenciamento de contas\n");
        printf("0 - Sair\n");
    }
    
    option = getchar() - '0';
    getchar();
    
    return option;
}

int ger_prod_menu (struct main_user *user)
{
    int menu_select = 100;
    int loop;
    
    if (user->permission == 1)
    {
        switch (menu_select)
        {
            case 100:
                menu_select = get_ger_prod_option(user);
                break;
            //case 1:
                //menu_select = adicionar_produto();
                //break;
            //case 2:
                //menu_select = editar_produto();
                //break;
            case 1:
                menu_select = pesquisar_produto();
                break;
            //case 4:
                //menu_select = adicionar_lote();
                //break;
            //case 5:
                //menu_select = editar_lote();
                //break;
            case 2:
                menu_select = pesquisar_lote();
                break;
                
            default:
                return 100;
                break;
        }
    }
    else if (user->permission == 2)
    {
        switch (menu_select)
        {
            case 100:
                menu_select = get_ger_prod_option(user);
                break;
            //case 1:
                //menu_select = adicionar_produto();
                //break;
            //case 2:
                //menu_select = editar_produto();
                //break;
            case 1:
                menu_select = pesquisar_produto();
                break;
            case 2:
                menu_select = adicionar_lote();
                break;
            //case 5:
                //menu_select = editar_lote();
                //break;
            case 3:
                menu_select = pesquisar_lote();
                break;
                
            default:
                return 100;
                break;
        }
    }
    else if (user->permission == 3 || user->permission == 4)
    {
        switch (menu_select)
        {
            case 100:
                menu_select = get_ger_prod_option(user);
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
}

int get_ger_prod_option (struct main_user *user)
{
    int option;
    
    system("clear");
    printf("\n");
    printf("Qual das acoes a seguir voce deseja executar?\n");
    printf("\n");
    
    if (user->permission == 1)
    {
        //printf("1 - Cadastrar Produto\n");
        //printf("2 - Editar Produto\n");
        printf("1 - Pesquisar Produto\n");
        //printf("4 - Adicionar Lote\n");
        //printf("5 - Editar Lote\n");
        printf("2 - Pesquisar Lote\n");
        printf("0 - Voltar\n");
    }
    else if (user->permission == 2)
    {
        //printf("1 - Cadastrar Produto\n");
        //printf("2 - Editar Produto\n");
        printf("1 - Pesquisar Produto\n");
        printf("2 - Adicionar Lote\n");
        //printf("5 - Editar Lote\n");
        printf("3 - Pesquisar Lote\n");
        printf("0 - Voltar\n");
    }
    else if (user->permission == 3 || user->permission == 4)
    {
        printf("1 - Cadastrar Produto\n");
        printf("2 - Editar Produto\n");
        printf("3 - Pesquisar Produto\n");
        printf("4 - Adicionar Lote\n");
        printf("5 - Editar Lote\n");
        printf("6 - Pesquisar Lote\n");
        printf("0 - Voltar\n");
    }
    
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

struct main_user user_login (void)
{
    struct main_user Loged_user;
    int loop;
    
    do
    {
        loop = 0;
        
        system("clear");
        printf("\n");
        printf("Digite seu Login:\n");
        scanf("%s", Loged_user.Login);
        getchar();
        
        printf("\n");
        printf("Digite sua Senha:\n");
        scanf("%s", Loged_user.Password);
        getchar();
        
        Loged_user = get_user_info(Loged_user.Password, Loged_user.Login);
        
        if (Loged_user.activity == 0 || Loged_user.permission == 666) // if there was some kind of error at the login, will direct the user to try again;
        {
            loop = 1;
            printf("\n");
            printf("LOGIN OU SENHA INCORRETOS!\n");
            printf("\n");
            printf("Aperte enter para tentar novamente;\n");
            getchar();
        }
    }while (loop);
    
    return Loged_user;
}

struct main_user get_user_info (char Password[21], char Login[21])
{
    struct main_user user_input;
    user_input.permission = 666;
    user_input.activity = 0;
    
    char query[2048];
    
    sprintf (query, "SELECT * FROM Contas_de_usuarios WHERE Login = %s", Login);
    
    if (mysql_query(con, query))
    {
        finish_with_error(con);
    }
    
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW user_info;
    int num = mysql_num_rows(result);
    
    if (num != 0)
    {
        user_info = mysql_fetch_row(result);
        
        //user_input.id = user_info[0];
        strcpy(user_input.Login, user_info[1]);
        strcpy(user_input.Password, user_info[2]);
        strcpy(user_input.name, user_info[3]);
        user_input.permission = user_info[4];
        user_input.activity = user_info[5];
    }
    mysql_free_result(result);
    
    // Will check if the Password Maches
    if (strcmp(user_input.Password, Password) == 0)
    {
        return user_input;
    }
    else
    {
        user_input.permission = 666;
        user_input.activity = 0;
        
        return user_input;
    }
    
}
