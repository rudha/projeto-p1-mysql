#ifndef _adicionar_usuario_h
#define _adicionar_usuario_h

// Declarar variáveis das informações do usuário:
char user_login [21];
char user_password [21];
char user_name [101];
int permission;

int adicionar_usuario (void);

void insert_login (void);
void insert_password (void);
void insert_name (void);
void insert_permission (void);

#endif
