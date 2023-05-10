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
        cout << "1. Добавить студента" << endl;
        cout << "2. Изменить данные студента" << endl;
        cout << "3. Информация о студентах" << endl;
        cout << "4. Узнать о студенте подробно" << endl;
        cout << "5. Удалить студента" << endl;
        cout << "6. Выполнить задание" << endl;
        cout << "0. Выйти из программы" << endl;
        cin >> MenuButton;
        switch (MenuButton) {
            case 0:
                system("cls");
                StudentBase->savefile();
                delete StudentBase;
                Crypt();
                cout << "Спасибо за использование приложения!";
                exit(0);
            case 1:
                system("cls");
                cout << "Добавьте информацию о студенте" << endl;
                st.GetValues();
                StudentBase->append_item(st);
                StudentBase->savefile();
                break;
            case 2:
                system("cls");
                StudentBase->PrintList();
                cout<<"Введите номер необходимого студента "; cin>>idx;            
                StudentBase->edit_item(idx);
                StudentBase->savefile();
                _getch();
            case 3:
                system("cls");
                StudentBase->PrintList();
                cout<<"Нажмите для продолжения"<<endl;
                _getch();
                break;
            case 4:
                system("cls");
                StudentBase->PrintList();
                cout<<"Введите номер студента ";cin>>idx;
                StudentBase->PrintStudent(idx);
                cout<<"Нажмите для продолжения"<<endl;
                _getch();
                break;
            case 5:
                system("cls");
                StudentBase->PrintList();
                cout<<"Введите номер студента, подлежащего удалению ";cin>>idx;
                StudentBase->deleteItem(idx);
                StudentBase->savefile();
                cout<<"Успешно! Нажмите для продолжения"<<endl;
                _getch();
                break;
            case 6:
                cout << "Введите пол студентов ";
                char sex; cin >> sex;
                cout << "Введите год поступления ";
                int year; cin >> year;
                StudentBase->CompleteTheTask(year,sex);
                break;
            default:
                system("cls");
                cout << "Ошибка! Перезапустите приложение";
                delete StudentBase;
                exit(0);
        }
    }
}