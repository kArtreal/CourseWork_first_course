#ifndef TEST_MYMENU_H
#define TEST_MYMENU_H
#include <iostream>
#include <cstring>
#include <conio.h>
#include "Student.h"
#include "MyList.h"
using namespace std;

void MainMenu(){

    int MenuButton;
    Student st;
    MyList *StudentBase = new MyList;
    StudentBase->loadfile();
    while (true) {
        int temp;
        system("cls");
        cout << "===========Main_Menu===========" << endl;
        cout << "1. �������� ��������" << endl;
        cout << "2. �������� ������ ��������" << endl;
        cout << "3. ���������� � ���������" << endl;
        cout << "4. ������ � �������� ��������" << endl;
        cout << "5. ������� ��������" << endl;
        cout << "6. ������� ���� ������" << endl;
        cout << "0. ����� �� ���������" << endl;
        cin >> MenuButton;
        switch (MenuButton) {
            case 0:
                system("cls");
                cout << "������� �� ������������� ����������";
                StudentBase->savefile();
                delete StudentBase;
                exit(0);
            case 1:
                system("cls");
                cout << "�������� ���������� � ��������" << endl;
                st.GetValues();
                StudentBase->append_item(st);
                break;
            case 2:
                system("cls");
                StudentBase->PrintList();
                cout<<"������� ����� ������������ �������� "; cin>>temp;
                st.Edit_Student();
                StudentBase->edit_item(st,temp);
                _getch();
            case 3:
                system("cls");
                StudentBase->PrintList();
                cout<<"������� ��� �����������"<<endl;
                _getch();
                break;
            case 4:
                system("cls");
                StudentBase->PrintList();
                cout<<"������� ����� �������� ";cin>>temp;
                StudentBase->PrintStudent(temp);
                cout<<"������� ��� �����������"<<endl;
                _getch();
                break;
            case 5:
                system("cls");
                StudentBase->PrintList();
                cout<<"������� ����� ��������, ����������� �������� ";cin>>temp;
                StudentBase->deleteItem(temp);
                cout<<"�������! ������� ��� �����������"<<endl;
                _getch();
                break;
            /*case 6:
                StudentBase->delete_all();
                cout<<"�������! ������� ��� �����������"<<endl;
                getch();
                break*/
            default:
                system("cls");
                cout << "������! ������������� ����������";
                delete StudentBase;
                exit(0);
        }
    }
}

#endif //TEST_MYMENU_H
