//
//  editar_produto.h
//  
//
//  Created by Bruno Chroniaris on 5/30/14.
//
//

#ifndef _editar_produto_h
#define _editar_produto_h

// Structs
struct goods_info
{
    int ID;
    char name[100];
    char manufacturer[100];
    float warranty;
    char reference[20];
    int activity;
};

// Global Variables
struct goods_info current_goods; // this info will be retrieved from the mysql table it self;
struct goods_info inputed_info; // this info will be inserted by the user, by stdin;

// Functions definition
int editar_produto (void);
int get_goods_id (void); // will get the goods id and return wich menu to proceed;
int get_wich_info_to_edit (void); // will get wich info the user wants to edit from the current item;
void intro (void);
void get_product_info (void); // will retrieve all the data from the mysql table and atribute it to 'current_goods';
int edit_product_info (int operation); // will lead the program for the user's selected operation;
int edit_product_name (void); // will edit the product's name and try to validate it, else it's gonna break the program by 'finish_with_error(con)';
int edit_product_manufacturer (void); // will edit the product's manufacturer and try to validate it, else it's gonna break the program by 'finish_with_error(con)';
int edit_product_warranty (void); // will edit the product's warranty and try to validate it, else it's gonna break the program by 'finish_with_error(con)';
int edit_product_reference (void); // will edit the product's reference and try to validate it, else it's gonna break the program by 'finish_with_error(con)';
int erase_product (void); // will edit the product's activity to 0 and try to validate it, else it's gonna break the program by 'finish_with_error(con)' or telling the user that something went wrong while trying to erase the product. The Product will actually never be deleted, but it's 'activity' will be '0' for now on;
int continue_editing (void); // after editing a product's info, will ask how the user wants do proced;

#endif
