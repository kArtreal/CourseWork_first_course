#pragma once
#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

class Student{
private:
    class Exams{
    public:
        char name_of_exam[31];
        int mark;
    };
    char name[31];
    char surname[31];
    char patronymic[31];
    int BD_day;
    int BD_month;
    int BD_year;
    int entranceYear;
    char faculty[31];
    char department[31];
    char group[31];
    char gradebookNumber[31];
    char sex;
    Exams grades[9][10];
public:
    Student() {
        strncpy_s(name, "", 30);
        strncpy_s(surname, "", 30);
        strncpy_s(patronymic, "", 30);
        BD_day = 1;
        BD_month = 1;
        BD_year = 1970;
        entranceYear = 1970;
        strncpy_s(faculty, "", 30);
        strncpy_s(department, "", 30);
        strncpy_s(group, "", 30);
        strncpy_s(gradebookNumber, "", 30);
        sex = '�';
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 10; j++) {
                strncpy_s(grades[i][j].name_of_exam, "", 30);
                grades[i][j].mark=-1;
            }
        }
}
    void GetValues(){
        char temp[31]; char temp_char; int temp_int1; int temp_int2; int temp_int3;
        cout<<"������� ������� "; 
        cin>>temp;
        while(!CheckInitials(temp)){
            cout<<"����� ������� �� ����������, ���������� ��� ���";
            cin>>temp;
        }
        strncpy_s(surname,temp,30);
        cout<<"������� ��� "; cin>>temp;
        while(!CheckInitials(temp)){
            cout<<"������ ����� �� ����������, ���������� ��� ���";
            cin>>temp;
        }
        strncpy_s(name,temp,30);
        cout<<"������� �������� "; cin>>temp;
        while(!CheckInitials(temp)){
            cout<<"������ �������� �� ����������, ���������� ��� ���";
            cin>>temp;
        }
        strncpy_s(patronymic,temp,30);
        cout<<"������� ���� �������� (� ������� �� �� ����) ";
        cin>>BD_day>>BD_month>>BD_year;
        while(!CheckBirthDate(BD_day,BD_month,BD_year)){
            cout<<"������� �� ��� �������� � ��� ����, ���������� ��� ���";
            cin>>BD_day>>BD_month>>BD_year;
        }
        cout<<"������� ��� ����������� ";
        cin>>entranceYear;
        cout<<"������� �������� ��������� (����������) "; cin>>temp;
        strncpy_s(faculty,temp,30);
        cout<<"������� �������� ������� "; cin>>temp;
        strncpy_s(department,temp,30);
        cout<<"������� ������ �������� "; cin>>temp;
        strncpy_s(group,temp,30);
        cout<<"������� ����� �������� ������ "; cin>>temp;
        strncpy_s(gradebookNumber,temp,30);
        cout<<"������� ��� �������� (� - �������. � - �������) "; cin>>temp_char;
        sex = temp_char;
        cout<<"������� ���������� ��������� "; cin>>temp_int1;
        cout<<"������� ���������� ��������� � �������� ";cin>>temp_int2;
        for (int i = 0; i < temp_int1; i++){
            for (int j = 0; j < temp_int2; j++) {
                cout<<"������� �������� � ������ "<<j+1<<" �������� � �������� "<<i+1<<' '<<endl;
                cin>>temp>>temp_int3;
                strncpy_s(grades[i][j].name_of_exam, temp, 30);
                grades[i][j].mark=temp_int1;
            }
        }
    }
    void Show_Full_Info(){
        cout<<surname<<' '<<name<<' '<<patronymic<<' '<<BD_day<<' '<<BD_month<<' '<<BD_year<<endl;
        cout << "��� ��������: " << sex << endl;
        cout<<"��� �����������: "<<entranceYear<<endl;
        cout<<"��������: "<<faculty<<endl;
        cout<<"�������: "<<department<<endl;
        cout<<"������: "<<group<<endl;
        cout<<"����� �������� ������: "<<gradebookNumber<<endl;
        cout<<"�������� ������ "<<endl;
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 10; j++) {
                if(strcmp("",grades[i][j].name_of_exam)!=0){
                    cout<<grades[i][j].name_of_exam<<' '<<grades[i][j].mark<<endl;
                }
            }
        }
    }
    void Show_Basic_Info(){
        cout << "���: " << surname << ' ' << name << ' ' << patronymic << endl
            << "����� �������� ������: " << gradebookNumber <<"   "
            << "��� ��������: " << sex << "   "
            << "��� �����������: " << entranceYear << endl << endl;
    }
    void Edit_Student(){
        system("cls");
        int button; char temp[31]; char temp_char;
        cout << "1. �������� ��� � ��� ��������" << endl;
        cout << "2. �������� ���� �������� ��������" << endl;
        cout << "3. �������� ���������� � ����� �������� ��������" << endl;
        cout << "4. �������� ���������� � �������� ������" << endl;
        cout << "0. �����" << endl;
        cin>>button;
        switch (button) {
            case 0:
                break;
            case 1:
                cout << "������� ������� ";
                cin >> temp;
                strncpy_s(surname, temp, 30);
                cout << "������� ��� ";
                cin >> temp;
                strncpy_s(name, temp, 30);
                cout << "������� �������� ";
                cin >> temp;
                strncpy_s(patronymic, temp, 30);
                cout << "������� ��� �������� ";
                cin >> temp_char;
                sex = temp_char;
                cout << "������ ������� ��������. ������� ��� ����������� ";
                _getch();
                break;
            case 2:
                cout << "������� ���� �������� (� ������� �� �� ����) ";
                cin >> BD_day >> BD_month >> BD_year;
                cout << "������ ������� ��������. ������� ��� ����������� ";
                _getch();
                break;
            case 3:
                cout << "������� ��� ����������� ";
                cin >> entranceYear;
                cout << "������� �������� ��������� (����������) ";
                cin >> temp;
                strncpy_s(faculty, temp, 30);
                cout << "������� �������� ������� ";
                cin >> temp;
                strncpy_s(department, temp, 30);
                cout << "������� ������ �������� ";
                cin >> temp;
                strncpy_s(group, temp, 30);
                cout << "������ ������� ��������. ������� ��� ����������� ";
                _getch();
                break;
            case 4:
                int temp_int1;
                int temp_int2;
                cout << "������� ����� �������� ������ ";
                cin >> temp;
                strncpy_s(gradebookNumber, temp, 30);
                cout << "������� ���������� ��������� ";
                cin >> temp_int1;
                cout << "������� ���������� ��������� � �������� ";
                cin >> temp_int2;
                for (int i = 0; i < temp_int1; i++) {
                    for (int j = 0; j < temp_int2; j++) {
                        cout << "������� �������� � ������ " << j + 1 << " �������� � �������� " << i + 1 << ' ';
                        cin >> temp >> temp_int1;
                        strncpy_s(grades[i][j].name_of_exam, temp, 30);
                        grades[i][j].mark = temp_int1;
                    }
                }
                cout << "������ ������� ��������. ������� ��� ����������� ";
                _getch();
                break;
            default:
                cout << "������! ������ ����� ��� � ����. ���������� ��� ���";
                _getch();
                break;
        }
    }
    bool CheckInitials(char init[31]){
        for (int i=0;i<strlen(init);i++){
            if (init[i]>='0' && init[i]<='9')
                return false;
        }
        return true;
    }
    bool CheckBirthDate(int dd,int mm,int yy)
    {
        if(yy>1970&&yy<2023)
        {
            if((mm==1 || mm==3 || mm==5|| mm==7|| mm==8||mm==10||mm==12) && dd>0 && dd<=31)
                return true;
            else
            if((mm==4 || mm==6 || mm==9|| mm==11) && dd>0 && dd<=30)
                return true;
            else
            if(mm==2)
            {
                if((yy%400==0 || (yy%100!=0 && yy%4==0)) && dd>0 && dd<=29)
                    return true;
                else if(dd>0 && dd<=28)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    }
    int GetEntranceYear() {
        return entranceYear;
    }
    char GetName() {
        return name[30];
    }
    char GetSex() {
        return sex;
    }
};
