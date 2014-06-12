#include <stdio.h>
#include <my_global.h>
#include <mysql.h>
#include <string.h>
#include "adicionar_lote.h"

//Global Variables
struct goods
{
    int identification;
    char name[101];
    char producer[101];
    float warranty;
    char reference [20];
    int activity;
};

struct goods current_goods;

struct lote
{
    int identification;
    int goods_identification;
    char name[101];
    char producer [101];
    float warranty;
    char reference;
    char initialization_date;
    int quantity;
    float buying_value;
    int activity;
};

struct lote current_lote;

//main function body

int adicionar_lote (void)
{
    int quantity, identification, price;
    int loop; // if loop == 1, then the user wants to repeat the process
    
    do
    {
        user_interface_first_print();
        identification = id_scan();
        
        get_product_informations(identification);
        
        user_interface_second_print();
        quantity = quantity_scan();
        
        user_interface_third_print();
        price = price_scan();
        
        insert_lote(identification, quantity, price);
        get_lote_informations();
        
        user_interface_fourth_print();
        loop = repetition_scan();
    } while (loop);
    
    return 0;
}





// functions bodies
void user_interface_first_print (void)
{
    system ("clear");
    
    printf("\n");
    printf("Informe abaixo o ID do produto do lote que voce deseja adicionar:\n");
}

void user_interface_second_print (void);
{
    printf("\n");
    printf("Quantos(as) %s pertencem a este lote?\n", current_goods.name);
}

void user_interface_third_print (void)
{
    printf("\n");
    printf("Qual foi o valor de compra individual de %s?\n", current_goods.name);
}

void user_interface_fourth_print (void)
{
    system ("clear");
    
    printf("\n");
    printf("O lote foi adicionado com sucesso:\n");
    printf("* Produto: %s\n", current_goods.name);
    printf("* Quantidade: %d\n", current_lote.quantity);
    printf("* Preco: %f\n", current_lote.buying_value);
    printf("\n");
    printf("Voce deseja adicionar mais algum lote?\n");
    printf("1 - SIM\n");
    printf("2 - NAO\n");
}

int id_scan (void)
{
    int ID;
    
    scanf ("%d", &ID);
    getchar();
    
    return ID;
}

int quantity_scan (void)
{
    int quantity;
    
    scanf("%d", &quantity);
    getchar();
    
    return quantity;
}

int price_scan (void)
{
    float price;
    
    scanf("%f", &price);
    
    return price;
}

int repetition_scan (void)
{
    int input;
    
    input = getchar() -'0';
    
    if (input == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insert_lote (int product_id, int quantity, int price)
{
    char query[2048]; // string for the query call
    
    sprintf(query, "INSERT INTO Lotes (ID_do_produto, Nome_do_produto, Fabricante, Tempo_de_garantia, Referencia, Quantidade, Valor_de_compra) VALUES (%d, %s, %s, %f, %s, %d, %f)", product_id, current_goods.name, current_goods.producer, current_goods.warranty, current_goods.reference, quantity, price);
    
    if (mysql_query(con, query))
    {
        finish_with_error(con);
    }
}

void get_product_informations (int product_id)
{
    char query[2048]; // string for the query call
    
    sprintf(query, "SELECT * FROM Produtos WHERE ID = %d", product_id);
    
    if (mysql_query(con, query))
    {
        finish_with_error(con);
    }
    
    MYSQL_RES *product = mysql_store_result(con);
    MYSQL_ROW goods_info;
    int num = mysql_num_rows(product);
    goods_info = mysql_fetch_row(product);
    
    if (num != 0)
    {
        current_goods.identification = goods_info[0];
        strcpy(current_goods.name, goods_info[1]);
        strcpy(current_goods.producer, goods_info[2]);
        current_goods.warranty = goods_info[3];
        strcpy(current_goods.reference, goods_info[4]);
        current_goods.activity = goods_info[5];
    }
    
    mysql_free_result(product);
}

void get_lote_informations (void)
{
    char query[2048]; // string for the query call
    
    sprintf(query, "SELECT * FROM Lotes ORDER BY ID DESC LIMIT 1", product_id);
    
    if (mysql_query(con, query))
    {
        finish_with_error(con);
    }
    
    MYSQL_RES *lote = mysql_store_result(con);
    MYSQL_ROW lote_info;
    int num = mysql_num_rows(lote);
    lote_info = mysql_fetch_row(lote);
    
    if (num != 0)
    {
        current_lote.identification = lote_info[0];
        current_lote.goods_identification = lote_info[1];
        strcpy(current_lote.name, lote_info[2]);
        strcpy(current_lote.producer, lote_info[3]);
        current_lote.warranty = lote_info[4];
        strcpy(current_lote.reference, lote_info[5]);
        strcpy(current_lote.initialization_date, lote_info[6]);
        current_lote.quantity = lote_info[7];
        current_lote.buying_value = lote_info[8];
        current_lote.activity = lote_info[9];
    }
    
    mysql_free_result(lote);
}
