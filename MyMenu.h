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
        cout << "1. Добавить студента" << endl;
        cout << "2. Изменить данные студента" << endl;
        cout << "3. Информация о студентах" << endl;
        cout << "4. Узнать о студенте подробно" << endl;
        cout << "5. Удалить студента" << endl;
        cout << "6. Удалить базу данных" << endl;
        cout << "0. Выйти из программы" << endl;
        cin >> MenuButton;
        switch (MenuButton) {
            case 0:
                system("cls");
                cout << "Спасибо за использование приложения";
                StudentBase->savefile();
                delete StudentBase;
                exit(0);
            case 1:
                system("cls");
                cout << "Добавьте информацию о студенте" << endl;
                st.GetValues();
                StudentBase->append_item(st);
                break;
            case 2:
                system("cls");
                StudentBase->PrintList();
                cout<<"Введите номер необходимого студента "; cin>>temp;
                st.Edit_Student();
                StudentBase->edit_item(st,temp);
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
                cout<<"Введите номер студента ";cin>>temp;
                StudentBase->PrintStudent(temp);
                cout<<"Нажмите для продолжения"<<endl;
                _getch();
                break;
            case 5:
                system("cls");
                StudentBase->PrintList();
                cout<<"Введите номер студента, подлежащего удалению ";cin>>temp;
                StudentBase->deleteItem(temp);
                cout<<"Успешно! Нажмите для продолжения"<<endl;
                _getch();
                break;
            /*case 6:
                StudentBase->delete_all();
                cout<<"Успешно! Нажмите для продолжения"<<endl;
                getch();
                break*/
            default:
                system("cls");
                cout << "Ошибка! Перезапустите приложение";
                delete StudentBase;
                exit(0);
        }
    }
}

#endif //TEST_MYMENU_H
