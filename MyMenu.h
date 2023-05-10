#pragma once
#include <iostream>
#include <cstring>
#include <conio.h>
#include "Student.h"
#include "MyList.h"
#include "encryption.h"

using namespace std;

void MainMenu(){
    
    int MenuButton;
    int idx;
    Student st;
    MyList *StudentBase = new MyList;
    Decrypt();
    StudentBase->loadfile();
    while (true) {
        system("cls");
        cout << "===========Main_Menu===========" << endl;
        cout << "1. �������� ��������" << endl;
        cout << "2. �������� ������ ��������" << endl;
        cout << "3. ���������� � ���������" << endl;
        cout << "4. ������ � �������� ��������" << endl;
        cout << "5. ������� ��������" << endl;
        cout << "6. ��������� �������" << endl;
        cout << "0. ����� �� ���������" << endl;
        cin >> MenuButton;
        switch (MenuButton) {
            case 0:
                system("cls");
                StudentBase->savefile();
                delete StudentBase;
                Crypt();
                cout << "������� �� ������������� ����������!";
                exit(0);
            case 1:
                system("cls");
                cout << "�������� ���������� � ��������" << endl;
                st.GetValues();
                StudentBase->append_item(st);
                StudentBase->savefile();
                break;
            case 2:
                system("cls");
                StudentBase->PrintList();
                cout<<"������� ����� ������������ �������� "; cin>>idx;            
                StudentBase->edit_item(idx);
                StudentBase->savefile();
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
                cout<<"������� ����� �������� ";cin>>idx;
                StudentBase->PrintStudent(idx);
                cout<<"������� ��� �����������"<<endl;
                _getch();
                break;
            case 5:
                system("cls");
                StudentBase->PrintList();
                cout<<"������� ����� ��������, ����������� �������� ";cin>>idx;
                StudentBase->deleteItem(idx);
                StudentBase->savefile();
                cout<<"�������! ������� ��� �����������"<<endl;
                _getch();
                break;
            case 6:
                cout << "������� ��� ��������� ";
                char sex; cin >> sex;
                cout << "������� ��� ����������� ";
                int year; cin >> year;
                StudentBase->CompleteTheTask(year,sex);
                break;
            default:
                system("cls");
                cout << "������! ������������� ����������";
                delete StudentBase;
                exit(0);
        }
    }
}