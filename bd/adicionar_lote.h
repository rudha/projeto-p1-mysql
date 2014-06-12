//
//  adicionar_lote.h
//  
//
//  Created by Bruno Chroniaris on 5/22/14.
//
//

#ifndef _adicionar_lote_h
#define _adicionar_lote_h

// main function
int adicionar_lote.h (void);

// user interface functions
void user_interface_first_print (void);
void user_interface_second_print (void);
void user_interface_third_print (void);
void user_interface_fourth_print (void);

// scanning functions
int id_scan (void); // will return the product id
int quantity_scan (void); // will return the amount to store
int repetition_scan (void); // will return 1 for repeating and 0 for leaving function
int price_scan (void);

// mysql interaction functions
void insert_lote (int product_id, int quantity, int price); // will insert the new row to the 'Lotes' table;
void get_product_informations (int product_id);
void get_lote_informations (void);

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

#endif
