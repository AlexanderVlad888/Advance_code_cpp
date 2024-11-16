#include <iostream>
#include <vector>
#include <string>
#include <pqxx/pqxx>
#include <Windows.h>

#pragma execution_character_set( "utf-8")

class ClientManager {
public:
    pqxx::connection conn;

    ClientManager(const std::string& connection_str) : conn(connection_str) {
       
        pqxx::work txn(conn);
        txn.exec("CREATE TABLE IF NOT EXISTS customers ("
            "id SERIAL PRIMARY KEY,"
            "first_name VARCHAR(100),"
            "last_name VARCHAR(100),"
            "email VARCHAR(100) UNIQUE);");
        txn.exec("CREATE TABLE IF NOT EXISTS phones ("
            "id SERIAL PRIMARY KEY,"
            "customer_id INT REFERENCES customers(id),"
            "phone_number VARCHAR(20));");
        txn.commit();
    }

    void add_customer(const std::string& first_name, const std::string& last_name, const std::string& email) {
        pqxx::work txn(conn);
        txn.exec("INSERT INTO customers (first_name, last_name, email) VALUES ('" + txn.esc(first_name) +
            "', '" + txn.esc(last_name) + "', '" + txn.esc(email) + "');");
        txn.commit();
    }

    void add_phone(int customer_id, const std::string& phone_number) {
        pqxx::work txn(conn);
        txn.exec("INSERT INTO phones (customer_id, phone_number) VALUES (" + std::to_string(customer_id) +
            ", '" + txn.esc(phone_number) + "');");
        txn.commit();
    }

    void update_customer(int customer_id, const std::string& first_name, const std::string& last_name, const std::string& email) {
        pqxx::work txn(conn);
        txn.exec("UPDATE customers SET first_name = '" + txn.esc(first_name) +
            "', last_name = '" + txn.esc(last_name) +
            "', email = '" + txn.esc(email) +
            "' WHERE id = " + std::to_string(customer_id) + ";");
        txn.commit();
    }

    void delete_phone(int customer_id, const std::string& phone_number) {
        pqxx::work txn(conn);
        txn.exec("DELETE FROM phones WHERE customer_id = " + std::to_string(customer_id) +
            " AND phone_number = '" + txn.esc(phone_number) + "';");
        txn.commit();
    }

    void delete_customer(int customer_id) {
        pqxx::work txn(conn);
        txn.exec("DELETE FROM phones WHERE customer_id = " + std::to_string(customer_id) + ";");
        txn.exec("DELETE FROM customers WHERE id = " + std::to_string(customer_id) + ";");
        txn.commit();
    }

    std::vector<std::string> find_customer(const std::string& search_term) {
        pqxx::work txn(conn);
        pqxx::result res = txn.exec("SELECT first_name, last_name, email FROM customers WHERE "
            "first_name LIKE '%" + txn.esc(search_term) + "%' OR "
            "last_name LIKE '%" + txn.esc(search_term) + "%' OR "
            "email LIKE '%" + txn.esc(search_term) + "%';");

        std::vector<std::string> customers;
        for (const auto& row : res) {
            customers.push_back(row[0].as<std::string>() + " " +
                row[1].as<std::string>() + " (" +
                row[2].as<std::string>() + ")");
        }
        return customers;
    }


};

int main() {

    //setlocale(LC_ALL, "");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    try {
        ClientManager manager("host=localhost "
                    "port=5432 "
                    "dbname=postgres "
                    "user=postgres "
                    "password=1"); 

        
        manager.add_customer("John", "Game", "john@example.com");
        manager.add_customer("Jane", "Smith", "jane.smith@example.com");
        manager.add_customer("John", "Fill", "fil@gmail.com");

        
        manager.add_phone(1, "123-456-7890");
        manager.add_phone(1, "098-765-4321");
        manager.add_phone(2, "555-555-5555");
        manager.add_phone(3, "666-777-5555");

        
        manager.update_customer(1, "John", "Doe", "john@mail.com");

        
        auto results = manager.find_customer("John");
        for (const std::string& customer : results) {
            std::cout << customer << std::endl;
        }

        
        manager.delete_phone(1, "123-456-7890");

        
        manager.delete_customer(2);

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
