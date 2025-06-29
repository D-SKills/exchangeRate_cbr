#pragma once
#include <curl/curl.h>
#include <pqxx/pqxx>
#include "�urrency_�ontainer.h"
#include "mistake.h"
#include "config_parser.h"
#include "DATABASE.h"
#include <fstream>


void WriteFile(const std::vector<Currence>& data)
{
    std::ofstream out("data_file/data.txt", std::ios::out | std::ios::binary);

    if (out.is_open())
    {
        for (int i = 0; i < data.size(); i++)
        {
            std::string value_fixed = data[i].Value;
            std::replace(value_fixed.begin(), value_fixed.end(), ',', '.');

            std::string request = "insert into exc (CharCode, NameCurrency, Value) values ('";
            request += data[i].CharCode;
            request += "', '";
            request += data[i].Name_currence;
            request += "', '";
            request += value_fixed;
            request += "');";

            out << request << std::endl;
        }
        std::cout << "���� �������!" << std::endl;
    }
    else
    {
        std::cerr << "���� �� ��� ������ ��� ������!\n";
    }

    out.close();
}
