//
//  editar_usuarios.h
//  
//
//  Created by Bruno Chroniaris on 5/20/14.
//
// PAREI EM "STOPPED HERE"

#ifndef _editar_usuario_h
#define _editar_usuario_h

// global var

struct USER
{
    int id;
    char login[21];
    char password[21];
    char name[101];
    int level;
    int activity;
};
// main function

int editar_usuarios (void);

// staple functions

void first_question_print (void); // fornecera a primeira tela de interacao, com perguntas sobre a proxima acao;
int first_question_scan (void); // scaneara a acao a tomar e ira retornar qual um valor para "menu_selection";
void second_question_print (void); // fornecera a segunda tela de interacao, de acordo com a opcao escolhida;
int second_question_scan (void); // Will scan the action to take and return a value to "menu_selection";
void third_question_print (void); // will print the third interactive menu;
int third_question_scan (void); //will scan the action to take and return a value to "menu_selection";

// functions for the second case actions

int edit_login (); // will return the next menu to select
int edit_password (); // will return the next menu to select
int edit_name (); // will return the next menu to select
int edit_user_level (); // will return the next menu to select
int erase_user (); // will return the next menu to select

// functions for inside the editing tools

void edit_login_question_print (void);
void edit_password_question_print (void);
void edit_name_question_print (void);
void edit_user_level_question_print (void);
void erase_user_question_print (void);

char scan_new_login (void);
char scan_new_password (void);
char scan_new_name (void);
int scan_new_user_level (void);
int scan_erase_user_confirmation (void);

// functions for MYSQL integration

void get_structure_from_selected_user (void);
void confirmation (void); // will get the new user info (after edited) and will give the feedback to the user, thru confirmation;

#endif
