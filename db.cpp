// Conectando C++ com MariaDB/MySQL

#include <iostream>
#include <mysql/mysql.h>    // /usr/include/mysql/mysql.h

using namespace std;

// ------------------------------------------------------------------
// Tentar conexão com o banco de dados. Caso falhe, finaliza execução.
// ------------------------------------------------------------------

struct connection_details {
    const char *server, *user, *password, *database;
};

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
// ------------------------------------------------------------

// ------------------------------------------------------------

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





// ------------------------------------------------------------






int main (int argc, char const *argv[])
{
    cout << "Hello." << endl;

    MYSQL *con;
    MYSQL_RES *res;
    MYSQL_ROW row;

    struct connection_details mysqlDB;
    mysqlDB.server = "localhost";
    mysqlDB.user = "eel670";
    mysqlDB.password = "eel#670";
    mysqlDB.database = "disciplinas";

    con = mysql_connection_setup(mysqlDB);
    res = mysql_execute_query(con, "SELECT * FROM disciplinas.arquitetura_de_computadores;"); // Esse é o comando executado de fato no mysql. Pode ser mysql_perform_query (Pesquisar diferença).

    cout << "Displaying database output:\n" << endl;

    while ((row = mysql_fetch_row(res)) != NULL )
    {
        cout << "| " 
	<< row[0] << " | "
        << row[1] << " | "
        << row[2] << " | "
        << row[3] << " | "
        << row[4] << " | " 
	<< endl << endl;    
    }

    mysql_free_result(res);
    mysql_close(con);


    return 0;
}

