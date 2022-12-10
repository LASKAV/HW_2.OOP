#include <iostream>
#include <string>

/*
�������� ���������� ����������� �����. ���������� ������� ������ �� �������� (���, �������� �������,
������� �������, ��������� �������, �������������� ���������� � ��������) ������ ���������������� ������.
��������� ����� �����������-�������, ��������������, inline-���������-�������, ���������� ����������.
����������� ���������� �������� ����������� ������ ��� ���. ������������ ������������ ����������� ���������
����� ���������, ������� ���������, ������ ��������� �� ���, ���������� ���� ���������
*/

const size_t BUFFER = 100;

class Phonebook
{
public:
	char* FIO;
	char* Home_phone;
	char* Work_phone;
	char* Phone;
	char* Notes;
	int number;

	Phonebook ()
	{
		FIO = nullptr;
		Home_phone = nullptr;
		Work_phone = nullptr;
		Phone = nullptr;
		Notes = nullptr;
		number = 0;
	}
	Phonebook (const char* Data_FIO, const char* Data_Home_phone, const char* Data_Work_phone, const char* Data_Phone, const char* Data_Notes) // ����������� ���e����� ������������ ������
	{

		FIO = new char[strlen(Data_FIO) + 1];          
		strcpy_s(FIO, strlen(Data_FIO) + 1, Data_FIO);

		Home_phone = new char[strlen(Data_Home_phone) + 1];
		strcpy_s(Home_phone, strlen(Data_Home_phone) + 1, Data_Home_phone);

		Work_phone = new char[strlen(Data_Work_phone) + 1];
		strcpy_s(Work_phone, strlen(Data_Work_phone) + 1, Data_Work_phone);

		Phone = new char[strlen(Data_Phone) + 1];
		strcpy_s(Phone, strlen(Data_Phone) + 1, Data_Phone);

		Notes = new char[strlen(Data_Notes) + 1];
		strcpy_s(Notes, strlen(Data_Notes) + 1, Data_Notes);
		
	}
	void Output (int num_sub)
	{
		 if (FIO == nullptr || Home_phone == nullptr)
		 {
		 	std::cout << "_nullptr error_" << std::endl;
		 	return;
		 }

		 std::cout << "\nSubscriber " << num_sub << std::endl
			 << "FIO = " << FIO << std::endl
			 << "Home_phone = " << Home_phone << std::endl
			 << "Work_phone = " << Work_phone << std::endl
			 << "Phone = " << Phone << std::endl
			 << "Notes = " << Notes << std::endl;
		
	}
	~Phonebook ()
	{
		delete[] FIO;
		delete[] Home_phone;
		delete[] Work_phone;
		delete[] Phone;
		delete[] Notes;
	}

};

// ����� �������� ������� ������� ����� ��������� �������� 

void Add_accounts(Phonebook*& subscriber,int& Contact, int& Number_sub)
{
	Phonebook* sub_buff = new Phonebook[Contact + 1];
	
	for (int i = 0; i < Contact; i++)
	{
		sub_buff[i].number = subscriber[i].number;

		sub_buff[i].FIO = new char[strlen(subscriber->FIO) + 1];
		strcpy_s(sub_buff[i].FIO, strlen(subscriber[i].FIO) + 1, subscriber[i].FIO);

		sub_buff[i].Work_phone = new char[strlen(subscriber->Work_phone) + 1];
		strcpy_s(sub_buff[i].Work_phone, strlen(subscriber[i].Work_phone) + 1, subscriber[i].Work_phone);

		sub_buff[i].Home_phone = new char[strlen(subscriber->Home_phone) + 1];
		strcpy_s(sub_buff[i].Home_phone, strlen(subscriber[i].Home_phone) + 1, subscriber[i].Home_phone);

		sub_buff[i].Phone = new char[strlen(subscriber->Phone) + 1];
		strcpy_s(sub_buff[i].Phone, strlen(subscriber[i].Phone) + 1, subscriber[i].Phone);

		sub_buff[i].Notes = new char[strlen(subscriber->Notes) + 1];
		strcpy_s(sub_buff[i].Notes, strlen(subscriber[i].Notes) + 1, subscriber[i].Notes);
	}

	sub_buff[Contact].number = Number_sub;

	char enter_b[BUFFER];

	std::cout << "FIO: ";
	std::cin.ignore();  // ������ ������ ���� �� ignore
	std::cin.getline(enter_b, BUFFER);
	sub_buff[Contact].FIO = new char[strlen(enter_b) + 1];
	strcpy_s(sub_buff[Contact].FIO, strlen(enter_b) + 1, enter_b);

	std::cout << "Home phone: ";
	std::cin.ignore();
	std::cin.getline(enter_b, BUFFER);
	sub_buff[Contact].Home_phone = new char[strlen(enter_b) + 1];
	strcpy_s(sub_buff[Contact].Home_phone, strlen(enter_b) + 1, enter_b);

	std::cout << "Work_phone: ";
	std::cin.ignore();
	std::cin.getline(enter_b, BUFFER);
	sub_buff[Contact].Work_phone = new char[strlen(enter_b) + 1];
	strcpy_s(sub_buff[Contact].Work_phone, strlen(enter_b) + 1, enter_b);

	std::cout << "Phone: ";
	std::cin.ignore();
	std::cin.getline(enter_b, BUFFER);
	sub_buff[Contact].Phone = new char[strlen(enter_b) + 1];
	strcpy_s(sub_buff[Contact].Phone, strlen(enter_b) + 1, enter_b);

	std::cout << "Notes: ";
	std::cin.ignore();
	std::cin.getline(enter_b, BUFFER);
	sub_buff[Contact].Notes = new char[strlen(enter_b) + 1];
	strcpy_s(sub_buff[Contact].Notes, strlen(enter_b) + 1, enter_b);


	Contact++;
	Number_sub++;

	delete[] subscriber;

	subscriber = sub_buff;

}

void Show_contact(Phonebook*& subscriber, int& Contact)  // ���������� ���� ���������
{
	
	for (int i = 0; i < Contact; i++)
	{
		subscriber[i].Output(i + 1);
		std::cout << "\n";
	}
}

void Delete_contact(Phonebook*& subscriber, int& Contact, int& Number_sub)  // ������� ���������
{
	short del_numb;
	bool flag = 0;
	std::cout << "������� ����� ��� ��������: ";
	std::cin >> del_numb;

	for (int i = 0; i < Contact; i++)
	{
		if (subscriber[i].number == del_numb)
		{
			Contact--;
			Number_sub--;
			flag++;
		}
	}
	short ind = 0;
	Phonebook* sub_buff = new Phonebook[Contact];

	for (size_t i = 0; i < Contact; i++)
	{
		if (subscriber[ind].number == del_numb)
		{
			ind++;
			i--;
		}
		else if (subscriber[ind].number != del_numb)
		{
			sub_buff[i].number = subscriber[ind].number;

			sub_buff[i].FIO = new char[strlen(subscriber[ind].FIO) + 1];
			strcpy_s(sub_buff[i].FIO, strlen(subscriber[ind].FIO) + 1, subscriber[ind].FIO);

			sub_buff[i].Home_phone = new char[strlen(subscriber[ind].Home_phone) + 1];
			strcpy_s(sub_buff[i].Home_phone, strlen(subscriber[ind].Home_phone) + 1, subscriber[ind].Home_phone);

			sub_buff[i].Work_phone = new char[strlen(subscriber[ind].Work_phone) + 1];
			strcpy_s(sub_buff[i].Work_phone, strlen(subscriber[ind].Work_phone) + 1, subscriber[ind].Work_phone);

			sub_buff[i].Phone = new char[strlen(subscriber[ind].Phone) + 1];
			strcpy_s(sub_buff[i].Phone, strlen(subscriber[ind].Phone) + 1, subscriber[ind].Phone);

			sub_buff[i].Notes = new char[strlen(subscriber[ind].Notes) + 1];
			strcpy_s(sub_buff[i].Notes, strlen(subscriber[ind].Notes) + 1, subscriber[ind].Notes);
			ind++;
		}
	}

	delete[] subscriber;
	subscriber = sub_buff;

	if (flag)
	{
		std::cout << "\n������� ��������!" << std::endl;
	}
	else
	{
		std::cout << "������� �� ������!\n";
		return;
	}
}

void Search_subscribers(Phonebook*& subscriber, int& Contact)  // ������ ��������� �� ���
{
	int flag = 0;
	std::cout << "������� ��� ��� ������: ";
	char Search_Sub [BUFFER];
	std::cin.getline(Search_Sub, BUFFER);

	for (int i = 0; i < Contact; i++)
	{
		if (_stricmp(subscriber[i].FIO, Search_Sub) == 0)
		{
			subscriber[i].Output(i + 1);
			std::cout << "\n";
			flag = 1;
		}
	}
	if (flag == 0) std::cout << " ������� �� ������!\n";
}

int main()
{
	setlocale(LC_ALL, "ru");  // ��������� ���� 

	int Contact = 0;     // ��������� � �����
	int Number_sub = 1;  // ����� �������� � ����� 

	Phonebook* subscriber = new Phonebook[Contact]; // ������ ������ �������� 

	short batton_menu = 0;
	
	do 
	{
		std::cout << "___Phonebook___" << std::endl
			<< "\n1.�������� ��������" << std::endl
			<< "2.������� ��������" << std::endl
			<< "3.����� �������� �� ���" << std::endl
			<< "4.�������� ���� ���������" << std::endl
			<< "5.�����" << std::endl;

		std::cout << "\nTerminal : ";
		std::cin >> batton_menu;

		switch (batton_menu)
		{
		case 1:  // �������� ��������
		{
			system("cls");
			std::cout << "���������� ��������" << std::endl;
			Add_accounts(subscriber, Contact, Number_sub);
			std::cout << "\n������� ��������!" << std::endl;
			system("pause");
			system("cls");
			break;
		}
		case 2:  // ������� ��������
		{
			system("cls");
			Delete_contact(subscriber, Contact, Number_sub);
			std::cout << "\n������� ������!" << std::endl;
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			Search_subscribers(subscriber, Contact);
			system("pause");
			system("cls");
			break;
		}
		case 4:  // �������� ���� ���������
		{
			system("cls");
			Show_contact(subscriber, Contact);
			system("pause");
			system("cls");
		}break;
		case 5:  // �����
		{
			system("pause");
			return -1;
		}break;
		default:
			break;
		}

	} while (batton_menu != 5);

	delete[] subscriber;

	return 0;
}
