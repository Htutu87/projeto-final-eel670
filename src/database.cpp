// Universidade Federal do Rio de Janeiro
// EEL670 - Linguagens de Programção
// Prof.: Miguel Campista
// Projeto final
// Autor: Artur Amaral | DRE: 119057968 | Agosto 2021

#include "../include/common-deps.h"
#include "../include/database.h"

MYSQL* mysql_connection_setup(struct connection_details mysql_details)
{
    MYSQL *connection = mysql_init(NULL);

    if (!mysql_real_connect (connection, mysql_details.server,
                                            mysql_details.user,
                                            mysql_details.password,
                                            mysql_details.database, 0, NULL, 0 ) )
    {
        /*Se a conexão com a base de dados falhar, este trecho será executado.*/
        cout << "Connection error: " << mysql_error(connection) << endl;
        exit (1);
    }

    return connection;
}

MYSQL_RES* mysql_execute_query(MYSQL *connection, const char *sql_query)
{
    if (mysql_query (connection, sql_query) )
    {
        /*Se um erro ocorrer durante a query...*/
        cout << "MySQL query error: " << mysql_error(connection) << endl;
        exit(1);
    } 

    return mysql_use_result(connection);
}
