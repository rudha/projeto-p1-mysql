//
//  editar_lote.h
//  
//
//  Created by Bruno Chroniaris on 5/29/14.
//
//

#ifndef _Header_h
#define _Header_h

#include<stdio.h>
#include<my_global.h>
#include <mysql.h>

//structs
struct lote
{
    int ID;
    char goods_name[100];
    int amount;
};

//global variables
struct lote current_lote;
int inputed_id, inputed_amount; // values gotten from stdin;
//functions declarations
int editar_lote (void);
void print_menus (int version); // will print the user interactive interface, wich will be defined by the version, where 1 == first, 2 == second ...;
int scan_inputs (int version); // will scan the user inputs, wich will be defined by the version, where 1 == first, 2 == second ... The value return will direct the user to the next menu;
void get_info_from_selected_lote (void);
void edit_lote_amount (void);
// main function
int editar_lote (void)
{
    int menu_select=1;
    
    do
    {
        switch (menu_select)
        {
            case 1:
                print_menus(menu_select);
                menu_select = scan_inputs(menu_select);
                get_info_from_selected_lote();
                break;
            case 2:
                print_menus(menu_select);
                menu_select = scan_inputs(menu_select);
                edit_lote_amount();
                get_info_from_selected_lote();
                break;
            case 3:
                print_menus(menu_select);
                menu_select = scan_inputs(menu_select);
                break;
                
            default:
                return 0;
                break;
        }
    } while (1);
}
//bodies
void print_menus (int version)
{
    
    switch (version)
    {
        case 1:
            system("clear");
            printf("\n");
            printf("0 - Voltar\n");
            printf("\n");
            printf("Digite abaixo o ID do lote que voce deseja editar ou digite 0 para voltar:\n");
            break;
        case 2:
            system("clear");
            printf("\n");
            printf("0 - Voltar\n");
            printf("\n");
            printf("Este lote de %s contem %d unidades.\n", current_lote.goods_name, current_lote.amount);
            printf("Por motivos de seguranca, a unica informacao que voce pode mudar sobre um lote e a quantidade de produtos disponivel.\n");
            printf("Para quantos produtos voce deseja atualizar este lote?\n");
            printf("obs.: Digite apenas inteiros entre 0 e 9999\n");
            break;
        case 3:
            system("clear");
            printf("\n");
            printf("Este lote de %s foi atualizado para %d unidade com sucesso.\n", current_lote.goods_name, current_lote.amount);
            printf("1 - Editar outro lote.\n");
            printf("0 - Sair.\n");
            
        default:
            break;
    }
}
int scan_inputs (int version)
{
    int valid;
    char valid_char;
    
    switch (version)
    {
        case 1:
            valid_char = getchar();
            valid = valid_char - '0';
            if (valid == 0)
            {
                getchar();
                return 0; // will return;
            }
            else
            {
                ungetc(valid_char, stdin);
                
                scanf("%d", &inputed_id);
                getchar();
                return 2; // will procede to the next menu;
            }
            break;
        case 2:
            valid_char = getchar();
            valid = valid_char - '0';
            if (valid == 0)
            {
                getchar();
                return 1; // will return;
            }
            else
            {
                ungetc(valid_char, stdin);
                
                scanf("%d", &inputed_amount);
                getchar();
                return 3; // will procede to the next menu;
            }
        case 3:
            valid_char = getchar();
            valid = valid_char - '0';
            
            if (valid)
            {
                return 1;
            }
            else
            {
                return 0;
            }
            break;
            
            
        default:
            break;
    }
}

void get_info_from_selected_lote (void)
{
    char query[2048];
    
    sprintf (query, "SELECT * FROM Lotes WHERE ID = %d", inputed_id);
    
    if (mysql_query(con, query))
    {
        finish_with_error(con);
    }
    
    MYSQL_RES *result = mysql_store_result(con);
    MYSQL_ROW lote_info;
    int num = mysql_num_rows(result);
    
    if (num != 0)
    {
        user_info = mysql_fetch_row(result);
        
        current_lote.ID = lote_info[0];
        strcpy(current_lote.goods_name, lote_info[2]);
        current_lote.amount = lote_info[7];
    }
    
    mysql_free_result(result);
}

void edit_lote_amount (void)
{
    char query[2048];
    
    sprintf (query, "UPDATE Lotes SET Quantidade = %d WHERE ID = %d", inputed_amount, inputed_id);
    
    if (mysql_query(con, query))
    {
        finish_with_error(con);
    }
}

#endif
