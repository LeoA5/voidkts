#include <mysql.h>
#include <iostream>
#include <fstream>
#include <cstring>

#include "oatpp/web/server/HttpConnectionHandler.hpp"

#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

void run()
{
    
}

int main()
{

    /*
    Define user login credentials, and retrieve password from
    file.

    TODO: PLEASE DONT USE ROOT!?!?!?!?!?
    Just make a custom user for this script.
    */
    const char* user = "root";
    const size_t PASSWORD_LENGTH = 33; // 32+'\0'
    const char* password_path = 
    "./.secrets/mariadb/root\%pw.txt";
    char password_buffer[PASSWORD_LENGTH];
    std::ifstream password_file(password_path);
    password_file.getline(
        password_buffer, PASSWORD_LENGTH + 1
    );
    const char* password = password_buffer;

    /*
        Establish the connection to the  mariadb instance
        on localhost:3306 with above defined user.

        TODO: Move to LAN accessible ip instead of localhost.
        TODO: Specify database.
    */
    MYSQL conn;
    mysql_init(&conn);
    const char* host = "127.0.0.1";
    if (!mysql_real_connect(
        &conn, host, user, password, nullptr, 3306, nullptr, 0
    ))
    {
        std::cout << "Connection failed: " << 
        mysql_error(&conn) << "\n";
        return 1;
    }

    const char* server_info = mysql_get_server_info(&conn);

    std::cout << "YAY!!" << server_info;

    // Make sure this closes
    mysql_close(&conn);

    return 0;
}