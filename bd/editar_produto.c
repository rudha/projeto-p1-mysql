#include "headers.h"

// Main Function
int editar_produto (void)
{
    int menu_selection = 1;
    
    do
    {
        switch (menu_selection)
        {
            case -1:
                menu_selection = continue_editing();
                break;
                
            case 1:
                intro();
                menu_selection = get_goods_id();
                get_product_info();
                break;
            case 2:
                edit_product_info(get_wich_info_to_edit());
                break;
                
            default:
                return 0;
                break;
        }
    } while (1);
    
    return 0;
}

// Bodies
void intro (void)
{
    system("clear");
    printf("0 - Voltar\n");
    printf("\n");
    printf("Digite abaixo o ID do produto que deseja editar ou digite 0 para voltar:\n");
}

int get_goods_id (void)
{
    int valid;
    char char_valid;
    
    char_valid = getchar();
    valid = char_valid - '0';
    
    if (valid)
    {
        ungetc(char_valid, stdin);
        
        scanf("%d", &inputed_info.ID);
        getchar();
        
        return 2;
    }
    else
    {
        return 0;
    }
}

void get_product_info (void)
{
    char query[2048];
    
    sprintf(query, "SELECT * FROM Produtos WHERE ID = %d", inputed_info.ID);
    
    if (mysql_query(con, query))
    {
        finish_with_error(con);
    }
    
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW product_info;
    int num = mysql_num_rows(result);
    
    if (num != 0)
    {
        product_info = mysql_fetch_row(result);
        
        current_goods.ID = product_info[0];
        strcpy(current_goods.name, product_info[1]);
        strcpy(current_goods.manufacturer, product_info[2]);
        current_goods.warranty = product_info[3];
        strcpy(current_goods.reference, product_info[4]);
        current_goods.activity = product_info[5];
    }
    
    mysql_free_result(result);
}

int get_wich_info_to_edit (void)
{
    int option;
    
    system("clear");
    printf("\n");
    printf("Que informacao de %s voce deseja editar?\n", current_goods.name);
    printf("\n");
    printf("1 - Nome\n");
    printf("2 - Fabricante\n");
    printf("3 - Tempo de Garantia\n");
    printf("4 - Referencia\n");
    printf("5 - Apagar\n");
    printf("0 - Voltar\n");
    
    option = getchar() - '0';
    getchar();
    
    return option;
}

int edit_product_info (int operation)
{
    switch (operation)
    {
        case 1:
            return edit_product_name();
            break;
        case 2:
            return edit_product_manufacturer();
            break;
        case 3:
            return edit_product_warranty();
            break;
        case 4:
            return edit_product_reference();
            break;
        case 5:
            return erase_product();
            break;
            
        default:
            return -1;
            break;
    }
}

int edit_product_name (void)
{
    char query[2048];
    
    system("clear");
    printf("\n");
    printf("Qual o novo nome que voce deseja atribuir a %s?\n", current_goods.name);
    
    gets(inputed_info.name);
    
    sprintf(query, "UPDATE Produtos SET Nome = %s WHERE ID = %d", inputed_info.name, inputed_info.ID);
    
    if (mysql_query(con, query))
    {
        finish_with_error(con);
    }
    else
    {
        get_product_info();
        
        printf("\n");
        printf("O nome foi alterado com sucesso para '%s'!\n", current_goods.name);
        printf("\n");
        printf("Aperte Enter para continuar:\n");
        
        getchar();
        
        return -1;
    }
    
    return 0;
}

int edit_product_manufacturer (void)
{
    char query[2048];
    
    system("clear");
    printf("\n");
    printf("Qual o novo Fabricante que voce deseja atribuir a %s?\n", current_goods.name);
    
    gets(inputed_info.manufacturer);
    
    sprintf(query, "UPDATE Produtos SET Fabricante = %s WHERE ID = %d", inputed_info.manufacturer, inputed_info.ID);
    
    if (mysql_query(con, query))
    {
        finish_with_error(con);
    }
    else
    {
        get_product_info();
        
        
        printf("\n");
        printf("O Fabricante foi alterado com sucesso para '%s'!\n", current_goods.manufacturer);
        printf("\n");
        printf("Aperte Enter apra continuar:\n");
        
        getchar();
        
        return -1;
    }
    
    return 0;
}

int edit_product_warranty (void)
{
    char query[2048];
    
    system("clear");
    printf("\n");
    printf("Quanto tempo de garantia voce deseja atribuir a '%s'?\n", current_goods.name);
    
    scanf("%f", &inputed_info.warranty);
    getchar();
    
    sprintf(query, "UPDATE Produtos SET Tempo_de_garantia = %f WHERE ID = %d", inputed_info.warranty, inputed_info.ID);
    
    if (mysql_query(con, query))
    {
        finish_with_error(con);
    }
    else
    {
        get_product_info();
        
        if (current_goods.warranty >= 2)
        {
            printf("\n");
            printf("A garantia foi alterada com sucesso para '%f' anos!\n", current_goods.warranty);
            printf("\n");
            printf("Aperte enter para continuar:\n");
        }
        else
        {
            printf("\n");
            printf("A garantia foi alterada com sucesso para '%f' ano!\n", current_goods.warranty);
            printf("\n");
            printf("Aperte enter para continuar:\n");
        }
        
        getchar();
        
        return-1
    }
    
    return 0;
}

int edit_product_reference (void)
{
    char query[2048];
    
    system("clear");
    printf("\n");
    printf("Qual a nova referencia de '%s'?\n", current_goods.name);
    
    gets(inputed_info.reference);
    
    sprintf(query, "UPDATE Produtos SET Referencia = %s WHERE ID = %d", inputed_info.reference, inputed_info.ID);
    
    if (mysql_query(con, query))
    {
        finish_with_error(con);
    }
    else
    {
        get_product_info();
        
        printf("\n");
        printf("A referencia foi alterada com sucesso para '%s'!\n", current_goods.reference);
        printf("\n");
        printf("Aperte enter para continuar:\n");
        
        getchar();
        
        return -1;
    }
    
    return 0;
}

int erase_product (void)
{
    char query[2048];
    int option;
    
    system("clear");
    printf("\n");
    printf("Voce tem certeza que deseja apagar '%s'? Esta acao nao podera ser revertida por nenhum usuario deste programa!\n");
    printf("1 - Apagar\n");
    printf("2 - Cancelar\n");
    
    option = getchar() - '0';
    getchar();
    
    if (option != 1)
    {
        printf("\n");
        printf("Sua operacao foi cancelada com sucesso.\n");
        printf("\n");
        printf("Aperte enter para continuar:\n");
        
        getchar();
        
        return -1
    }
    else
    {
        sprintf(query, "UPDATE Produtos SET Estado_do_item = 0 WHERE ID = %d", inputed_info.ID);
        
        if (mysql_query(con, query))
        {
            finish_with_error(con);
        }
        else
        {
            get_product_info();
            
            if (current_goods.activity == 0)
            {
                printf("\n");
                printf("'%s' foi apagado com sucesso.\n", current_goods.name);
                printf("\n");
                printf("Aperte enter para continuar\n");
            }
            else
            {
                printf("\n");
                printf("'%s' não pode ser apagado devido a um erro desconhecido.\n");
                printf("\n");
                printf("Aperte enter para continuar\n");
            }
            
            getchar();
            
            return -1;
        }
    }
    
    return 0;
}

int continue_editing (void)
{
    int option;
    
    system("clear");
    printf("\n");
    printf("Como deseja prosseguir?\n");
    printf("\n");
    printf("1 - Continuar Editando este produto\n");
    printf("2 - Editar outro Produto\n");
    printf("0 - Sair\n");
    
    option = getchar() - '0';
    getchar();
    
    switch (option)
    {
        case 1:
            return 2;
            break;
        case 2:
            return 1;
            break;
        default:
            return 0;
            break;
    }
}
