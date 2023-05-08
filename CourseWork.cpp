#include <cstring>
#include <iostream>
#include <fstream>
#include <windows.h>
#include "MyList.h"
#include "Student.h"
#include "MyMenu.h"

using namespace std;
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251); 
    MainMenu();

    /*
        Student st;
        Student st1(true);
        Student st2(2);
        DataBase->loadfile();
        DataBase->PrintList();
        DataBase->PrintStudent(1);
        DataBase->PrintStudent(2);
        DataBase->savefile();
        return 0;
    /*
        setlocale(LC_ALL, "Russian");
        Student st1;
        Student st2;
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
        char a = 'т';
        if (a == 'т')
            cout << "YES" << endl;
        strncpy_s(st1.name, "ivanov", 10);
        st1.day = 8;
        st1.month = 16;
        st1.year = 1024;
        ofstream out("1.txt", ios::binary | ios::out); //Открываем файл в двоичном режиме для записи
        out.write((char *) &st1, sizeof st1); //Записываем в файл число y
        strncpy(st1.name, "petrov", 10);
        st1.day = 9;
        st1.month = 17;
        st1.year = 1025;
        out.write((char *) &st1, sizeof(Student));
        out.close(); //Закрываем файл


        ifstream in("1.txt", ios::binary | ios::in); //Открываем файл в двоичном режиме только для чтения
        in.read((char *) &st2, sizeof st2); //Читаем оттуда информацию и запоминаем её в X
        cout << st2.name << ' ' << st2.day << endl;
        in.read((char *) &st2, sizeof st2); //Читаем оттуда информацию и запоминаем её в X
        in.close(); //Закрываем файл
        cout << st2.name << ' ' << st2.day << endl;
        st2.Print();
        return 0;
    */
}