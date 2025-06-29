#pragma once
#include "�urrency_�ontainer.h"
#include <pqxx/pqxx>
#include <iostream>
#include <fstream>

void ConnectedBD(const std::vector<Currence>& data)
{
    pqxx::connection conn("dbname= mydb user=postgres password=20ufodop1 host=127.0.0.1 port=5432");
    try {
        if (conn.is_open()) {
            std::cout << "�������� ����������� � ����: " << conn.dbname() << std::endl;
        }
        else {
            std::cout << "������ �����������." << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "������: " << e.what() << std::endl;
    }


    pqxx::work txn(conn);
    try
    {
        txn.exec(
            "CREATE TABLE IF NOT EXISTS exdc ("
            "CharCode VARCHAR(3) NOT NULL, "
            "NameCurrency VARCHAR(50) NOT NULL, "
            "Value VARCHAR(12) NOT NULL)");

        std::cout << "������� �������\n";
    }
    catch (const std::exception& ex)
    {
        std::cout << "������ " << ex.what() << std::endl;
    }


    txn.exec("insert into exdc (CharCode, NameCurrency, Value) values ('RUS', '�������������', '213');");

    //std::ifstream file("data_file/data.txt");
    //if (!file.is_open())
    //{
    //    std::cerr << "�� ������� ������� ����" << std::endl;
    //    return;
    //}

    //std::string DataFromFile;
    //while (std::getline(file, DataFromFile))
    //{
    //    if (!DataFromFile.empty())
    //    {
    //        txn.exec(DataFromFile);
    //    }
    //}

    txn.commit();

}


//#include <pqxx/pqxx>
//#include <iostream>
//#include <locale>
//#include <clocale>
//
//void Con(const std::vector<Currence>& data) {
//    try {
//        // ������������� ������ ��� ������� � ���������
//        std::setlocale(LC_ALL, "ru_RU.UTF-8");
//        std::locale::global(std::locale("ru_RU.UTF-8"));
//        std::cout.imbue(std::locale());
//
//        // ������������ � ��
//        pqxx::connection conn("dbname=your_database_name user=postgres password=20ufodop1 host=127.0.0.1 port=5432");
//
//        // ��������� ����������
//        if (!conn.is_open()) {
//            throw std::runtime_error("�� ������� ������������ � ���� ������");
//        }
//
//        // ������������� ��������� ����������
//        pqxx::nontransaction set_enc(conn);
//        set_enc.exec("SET client_encoding TO 'UTF-8'");
//        set_enc.commit();
//
//        pqxx::work txn(conn);
//
//        // ������ ������� (������ ������)
//        txn.exec(
//            "CREATE TABLE IF NOT EXISTS exc("
//            "CharCode VARCHAR(3) NOT NULL, "
//            "NameCurrency VARCHAR(50) NOT NULL, "
//            "Value VARCHAR(12) NOT NULL)");
//
//        // ��������� ������ - 3 ������ �������:
//
//        // 1. ������ SQL � ������� �������
//        txn.exec("INSERT INTO exc (CharCode, NameCurrency, Value) VALUES ('RUR', '�����', '1.00')");
//
//        txn.commit();
//        std::cout << "������ ���������!\n";
//
//    }
//    catch (const std::exception& e)
//    {
//        std::cerr << "������ " << e.what() << std::endl;
//    }
//}