#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "�urrency_�ontainer.h"

void SubstrCurrensiFromXML(/*const std::string nameValue,*/ const std::string XMLdata
	, std::vector<Currence>&conclusion)
{
	/*
		������� ������ �������� � ��� ������������ �������� � ������ ��� � ���������

		****************************************************************************
		������� ��� ������ ��������� ������ �� ��������� ������� ��������� � ����� �����������������������
		� ������� XML �.� ������ �������� ���������� ����� ����� �������� 
		��������: <Name>���� ����������</Name>
		� ��������� �� ������������ ����� � ������� XML � ������� ������(string) 
		� ��� � ���� ������ �������� ����� ��������: <Value> � </Value> � ������� �������� ����� � ��������� ��������� ���������� 
		����� � ������� ��� ������ � ������� �� �������� </Value> � ���� ��� � ��������� 

		������ ������:
		1) ��������������� ���� � XML-������ ���� ��� ������ ������
		2) ��������� �������� ����� ������ � ������� substr()
		3) ��������� ������ � ��������� Currence � ��������� � ������

		����������� ����������:
		1) ����� ��������� ������ ������ �������� ������������ ����� XML-������
		1) ���� ������������, ���� �� ��������� ����� ������ (��� </ValCurs>)

		��������: 
		1)� �� ��� ��������� ��������� ����, ������� �������� ����� ���� ���� ������� 1.0 ��������� ���� ����������� ����, ���� �� �������� ������ ����� 
		2)�� ��� ��������� �������� ������, ����� ������� �������, ������ ��� ����� ������� ������� substr() ���������� 0 �.� </Value> ����� ������� ��������� 
		����� �� 0 ������� � ���������� ��� � �������� ������: size_t end_pos_cur = Value_end - Value_Start. �������� Value_end ��������� 0 � Value_Start = 141(��������� ��������)
		�������: 1.1 � ������ ���� � �������� � �������� ������ �������� </Value>. ������� ���������� ���������� ���������� =)
	*/
	
	std::string name_curr, exchange_rate, CharCode;
	std::string subNameCurrencsi = XMLdata;
	
	size_t pos = 0;
	size_t end_cycle = subNameCurrencsi.find("</ValCurs>");
	while (true)
	{
		Currence curr;

		//���������� �������� ������
		size_t Value_Start = subNameCurrencsi.find("<Name>");
		size_t Value_end = subNameCurrencsi.find("</Name>");
		if (Value_Start != std::string::npos && Value_end != std::string::npos)
		{
			size_t end_pos = Value_end - Value_Start;
			name_curr = subNameCurrencsi.substr(Value_Start + 6, end_pos - 6);
			curr.Name_currence = name_curr;
			std::cout << name_curr;
		}

		//���������� �������� ������
		Value_Start = subNameCurrencsi.find("<Value>");
		Value_end = subNameCurrencsi.find("</Value>");
		if (Value_Start != std::string::npos && Value_end != std::string::npos)
		{
			size_t end_pos_cur = Value_end - Value_Start;
			exchange_rate = subNameCurrencsi.substr(Value_Start + 7, end_pos_cur - 7);
			std::cout << " " << exchange_rate << " ";
			curr.Value = exchange_rate;
			
		}

		//���������� �������� �������� ������
		Value_Start = subNameCurrencsi.find("<CharCode>");
		Value_end = subNameCurrencsi.find("</CharCode>");
		if (Value_Start != std::string::npos && Value_end != std::string::npos)
		{
			size_t end_pos_charCode = Value_end - Value_Start;
			CharCode = subNameCurrencsi.substr(Value_Start + 10, end_pos_charCode - 10);
			std::cout << CharCode << std::endl << std::endl;
			curr.CharCode = CharCode;

		}

		//������� ����������� ����� 
		subNameCurrencsi = subNameCurrencsi.substr(Value_end + 7); //������� 1.1
		
		conclusion.push_back(curr);

		if (subNameCurrencsi.find("</Value>") == std::string::npos || subNameCurrencsi.size() < 10) //������� 1.0
		{
			break;
		}

	}
}


void Choice_Name_Currencsi()
{
	int number_currenci;
	std::cout << "�������� ������: ";
	std::cin >> number_currenci;

	switch (number_currenci)
	{
	case 1:


	default:
		break;
	}



}


/*
while (true)
{
	Currence curr;

	bool hasName = false, hasValue = false, hasCharCode = false;

	// �������� ������
	size_t Value_Start = subNameCurrencsi.find("<Name>");
	size_t Value_end = subNameCurrencsi.find("</Name>");
	if (Value_Start != std::string::npos && Value_end != std::string::npos)
	{
		size_t end_pos = Value_end - Value_Start;
		name_curr = subNameCurrencsi.substr(Value_Start + 6, end_pos - 6);
		curr.Name_currence = name_curr;
		hasName = true;
		std::cout << name_curr;
	}

	// �������� ������
	Value_Start = subNameCurrencsi.find("<Value>");
	Value_end = subNameCurrencsi.find("</Value>");
	if (Value_Start != std::string::npos && Value_end != std::string::npos)
	{
		size_t end_pos_cur = Value_end - Value_Start;
		exchange_rate = subNameCurrencsi.substr(Value_Start + 7, end_pos_cur - 7);
		curr.Value = exchange_rate;
		hasValue = true;
		std::cout << " " << exchange_rate << " ";
	}

	// ��� ������
	Value_Start = subNameCurrencsi.find("<CharCode>");
	Value_end = subNameCurrencsi.find("</CharCode>");
	if (Value_Start != std::string::npos && Value_end != std::string::npos)
	{
		size_t end_pos_charCode = Value_end - Value_Start;
		CharCode = subNameCurrencsi.substr(Value_Start + 10, end_pos_charCode - 10);
		curr.CharCode = CharCode;
		hasCharCode = true;
		std::cout << CharCode << std::endl << std::endl;
	}

	// ��������� ������ ���� ����� ��
	if (hasName && hasValue && hasCharCode)
	{
		conclusion.push_back(curr);
		// �������� ������ ����� �������� ���������
		subNameCurrencsi = subNameCurrencsi.substr(Value_end + 7);
	}
	else
	{
		break; // ���� �����-�� �� ����� �� ������ � ������ ����� ������
	}

	if (subNameCurrencsi.find("</Value>") == std::string::npos || subNameCurrencsi.size() < 10)
	{
		break;
	}
}



*/