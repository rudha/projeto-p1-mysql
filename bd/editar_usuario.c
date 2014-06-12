#include "headers.h"

int editar_usuario (void)
{
    int menu_selection = 1;
    int interactivity;
    
    do
    {
        switch (menu_selection)
        {
            case 1:
                first_question_print();
                menu_selection = first_question_scan();
                get_structure_from_selected_user();
                break;
            case 2:
                second_question_print();
                menu_selection = second_question_scan();
                break;
            case 3:
                third_question_print();
                menu_selection = third_question_scan();
                break;
                
            default:
                return 0; // end function call
                break;
        }
    } while (1);
}

void first_question_print (void)
{
    system ("clear");
    
    printf ("\n");
    printf ("Caso deseje voltar, digite 0\n");
    printf ("Caso deseje editar um usuario digite o Login do usuario em questao:\n")
}

void second_question_print (void)
{
    system ("clear");
    
    printf ("\n");
    printf ("Qual das acoes abaixo voce deseja executar?\n");
    printf ("\n");
    printf ("1 - Editar Login\n");
    printf ("2 - Editar Senha\n");
    printf ("3 - Editar Nome\n");
    printf ("4 - Editar Nivel de permissoes\n");
    printf ("5 - Apagar usuario\n");
    printf ("0- Voltar\n");
}

int first_question_scan (void)
{
    char filter; // Filter is gonna define if the user wants to go back ('0'), or if he's typping the Login.
    char partial_login[20]; // Partial_login will catch the remaining of the login, that's gonna me completed with the first character from the "getchar()";
    int is_integer;
    
    filter = getchar();
    is_integer = filter - '0';
    
    if (is_integer == 0)
    {
        getchar();
        return 0;
    }
    else
    {
        scanf("%s", &partial_login);
        getchar();
        sprintf (user_login, "%c%s", filter, partial_login);
        return 2;
    }
}

int second_question_scan (void)
{
    int action_pointer; // Will define wich action to take;
    
    action_pointer = getchar() - '0';
    getchar();
    
    switch (action_pointer)
    {
        case 1:
            return = edit_login();
            break;
        case 2:
            return = edit_password();
            break;
        case 3:
            return = edit_name();
            break;
        case 4:
            return = edit_user_level();
            break;
        case 5:
            return = erase_user();
            break;
        case 0:
            return 1;
            break;
        default:
            return 2; // will repeat this second menu;
            break;
    }
}

void third_question_print (void)
{
    system ("clear");
    
    printf ("\n");
    printf ("Voce deseja continua editando informacoes do mesmo usuario?\n");
    printf ("\n");
    printf ("1 - SIM\n");
    printf ("2 - NAO\n");
}

int third_question_scan (void)
{
    int action_pointer;
    
    action_pointer = getchar() - '0';
    getchar();
    
    switch (action_pointer)
    {
        case 1:
            return 2;
            break;
        case 2:
            return 1;
            break;
        default:
            return 3; // will repeat this third menu;
            break;
    }
}

int edit_login ()
{
    char new_login[21];
    char query [2048];
    
    edit_login_question_print();
    new_login = scan_new_login();
    
    sprintf (query, "UPDATE Contas_de_usuarios SET Login = %s WHERE Id = %d", new_login, edited_user.id);
    
    if (mysql_query(con, query))
    {
        finish_with_error(con);
    }
    else
    {
        confirmation();
        
        strcpy (user_login, new_login);
        
        printf ("\nO Login foi alterado com sucesso para '%s' .\n", user_confirmation.login);
        printf ("Digite 1 para continua:\n");
        
        getchar();
        getchar();
        
        return 3; // will proceed to the next menu.
    }
}

int edit_password ()
{
    char new_password[21];
    char query [2048];
    
    edit_password_question_print();
    new_password = scan_new_password();
    
    sprintf (query, "UPDATE Contas_de_usuarios SET Senha = %s WHERE Id = %d", new_password, edited_user.id);
    
    if (mysql_query(con, query))
    {
        finish_with_error(con);
    }
    else
    {
        confirmation();
        
        printf ("\nA Senha foi alterado com sucesso para '%s' .\n", user_confirmation.password);
        printf ("Digite 1 para continua:\n");
        
        getchar();
        getchar();
        
        return 3; // will proceed to the next menu.
    }
    
}

int edit_name ()
{
    char new_name[101];
    char query [2048];
    
    edit_name_question_print();
    new_name = scan_new_name();
    
    sprintf (query, "UPDATE Contas_de_usuarios SET Nome = %s WHERE Id = %d", new_name, edited_user.id);
    
    if (mysql_query(con, query))
    {
        finish_with_error(con);
    }
    else
    {
        confirmation();
        
        printf ("\nO Nome foi alterado com sucesso para : '%s' .\n", user_confirmation.name);
        printf ("Digite 1 para continua:\n");
        
        getchar();
        getchar();
        
        return 3; // will proceed to the next menu.
    }
}

int edit_user_level ()
{
    int new_level;
    char query [2048];
    
    edit_user_level_question_print();
    new_level = scan_new_user_level();
    
    sprintf (query, "UPDATE Contas_de_usuarios SET Nivel_permissoes = %d WHERE Id = %d", new_level, edited_user.id);
    
    if (mysql_query(con, query))
    {
        finish_with_error(con);
    }
    else
    {
        confirmation();
        
        printf ("\nO Nivel de permissoes foi com sucesso para : '%d' .\n", user_confirmation.level);
        printf ("Digite 1 para continua:\n");
        
        getchar();
        getchar();
        
        return 3; // will proceed to the next menu.
    
    
}

int erase_user ()
{
    erase_user_question_print();
    
    if (scan_erase_user_confirmation())
    {
        char query [2048];
        sprintf (query, "UPDATE Contas_de_usuarios SET Estado_do_item = 0 WHERE Login = %s", edited_user.login);
        
        if (mysql_query(con, query))
        {
            finish_with_error(con);
        }
        
        confirmation();
        
        if (user_confirmation.activity == 0)
        {
            printf ("\nO usuario '%s' foi apagado com sucesso.\n", edited_user.name);
            printf ("Digite 1 para continua:\n");
            
            getchar();
            getchar();
            
            return 1; //will proceed to the first menu, so the user can edit another user. This erased user will no longer be accessible.
        }
        else
        {
            printf("\nHOUVE UM ERRO AO TENTAR APAGAR ESTE USUARIO\n");
            printf("Aperte 1 para continuar.\n");
            
            getchar();
            getchar();
            
            return 1;
        }
    }
    else
    {
        return 3; //will proceed to the next menu.
    }
    
}

void edit_login_question_print (void)
{
    system ("clear");
    
    printf ("\n");
    printf ("O login deve conter no maximo 20 caracteres, incluindo numeros, e nao deve incluir caracteres especiais.\n");
    printf ("\n");
    printf ("Insira abaixo o novo login para este usuario:\n");
    
}

char scan_new_login (void)
{
    char new_login[21];
    
    scanf ("%s", &new_login);
    getchar();
    
    return new_login;
}

void get_structure_from_selected_user (void)
{
    char query[2048];
    
    sprintf (query, "SELECT * FROM Contas_de_usuarios WHERE Login = %s", user_login);
    
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
        
        edited_user.id = user_info[0];
        strcpy(edited_user.login, user_info[1]);
        strcpy(edited_user.password, user_info[2]);
        strcpy(edited_user.name, user_info[3]);
        edited_user.level = user_info[4];
        edited_user.activity = user_info[5];
    }
    mysql_free_result(result);
}

void edit_password_question_print (void)
{
    system ("clear");
    
    printf ("\n");
    printf ("A Senha deve conter no maximo 20 caracteres, incluindo numeros, e nao deve incluir caracteres especiais.\n");
    printf ("\n");
    printf ("Insira abaixo a nova senha para este usuario:\n");
}
char scan_new_password (void)
{
    char new_password [21];
    
    scanf ("%s", &new_password);
    getchar();
    
    return new_password;
}

void edit_name_question_print (void)
{
    system ("clear");
    
    printf ("\n");
    printf ("O Nome deve conter no maximo 100 caracteres, e nao deve incluir caracteres especiais.\n");
    printf ("\n");
    printf ("insira abaixo o novo Nome para este usuario:\n");
}

char scan_new_name (void)
{
    char new_name [101];
    
    scanf ("%s", &new_name);
    getchar();
    
    return new_name;
}

void edit_user_level_question_print (void)
{
    System ("clear");
    
    printf ("\n");
    printf ("Qual nivel de permissão dos sugeridos abaixo você deseja atribuir a esse usuário?\n");
    printf("1 - Visualizar produtos e lotes apenas.\n");
    printf("2 - Visualizar lotes e produtos, e adicionar lotes.\n");
    printf("3 - Visualizar, editar e adicionar lotes e produtos.\n");
    printf("4 - Visualizar, editar e adicionar lotes, produtos e contas de usuario.\n");
    printf("\nINFORME APENAS O NUMERO DE PERMISSAO\n");
}

int scan_new_user_level (void)
{
    int new_user_level;
    
    new_user_level = getchar() - '0';
    getchar();
    
    return new_user_level;
}

void erase_user_question_print (void)
{
    system ("clear");
    
    printf ("\n");
    printf ("Voce tem certeza que deseja tornar este usuario inativo?\n");
    printf ("\n");
    printf ("1 - SIM\n");
    printf ("2 - NAO\n"); //STOPPED HERE
        
}

int scan_erase_user_confirmation (void)
{
    int confirmation;
    
    confirmation = getchar() - '0';
    
    if (confirmation == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void confirmation (void)
{
    char query[2048];
    
    sprintf (query, "SELECT * FROM Contas_de_usuario WHERE Login = %s", user_login)
    
    if (mysql_query(con, query))
    {
        finish_with_error(con);
    }
    
    MYSQL_RES *confirm = mysql_store_result(con);
    MYSQL_ROW info_confirm;
    int num = mysql_num_rows(confirm);
    
    if (num != 0)
    {
        info_confirm = mysql_fetch_row(result);
        
        user_confirmation.id = info_confirm[0];
        strcpy(user_confirmation.login, info_confirm[1]);
        strcpy(user_confirmation.password, info_confirm[2]);
        strcpy(user_confirmation.name, info_confirm[3]);
        user_confirmation.level = info_confirm[4];
        user_confirmation.activity = info_confirm[5];
    }
    mysql_free_result(result);
}
