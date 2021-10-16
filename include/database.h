// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Projeto final
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#ifndef DATABASE_H
#define DATABASE_H

#include <mysql/mysql.h>

struct connection_details {
    const char *server, *user, *password, *database;
};

MYSQL* mysql_connection_setup(struct connection_details);
MYSQL_RES* mysql_execute_query(MYSQL *, const char *);

#endif