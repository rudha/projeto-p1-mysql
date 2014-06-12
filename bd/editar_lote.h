//
//  editar_lote.h
//  
//
//  Created by Bruno Chroniaris on 5/29/14.
//
//

#ifndef _Header_h
#define _Header_h

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

#endif
