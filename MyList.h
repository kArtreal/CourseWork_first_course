#pragma once
#include "Student.h"
#include <fstream>
#include <array>
#include <conio.h>
#include <iostream>

using namespace std;


class MyList{
private:
    class node{
    public:
        Student data;
        node* next;
    };
    void add_item(Student _st)
    {
        node* new_item = new node();
        new_item->data = _st;
        new_item->next = head;
        head = new_item;
        count++;
    }

    void insert_item(Student st, int index) {
        if (not (index >= 0 and index <= count))
            return;
        if (count == 0)
            add_item(st);
        else {
            node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            node* new_item = new node();
            new_item->data = st;
            new_item->next = current->next;
            current->next = new_item;
            count++;
        }
    }

public:
    MyList(){
        count = 0;
        head = nullptr;
        last = nullptr;
    }
    ~MyList() {
        node* old = nullptr;
        node* current = head;
        while (current != nullptr){
            old = current;
            current = current->next;
            delete old;
        }
    }
    node* head;
    node* last;
    int count;

    void loadfile(){
        ifstream in;
        in.open("DataBase.bin",ios::binary);
        in.peek();
        while(!in.eof())
        {
            node *new_item = new node;
            if (count==0) {
                head = new_item;
            }
            in.read((char *) &new_item->data, sizeof( Student));
            if (count!=0)
                last->next=new_item;
            last=new_item;
            count++;
            in.peek();
        }
        if (count!=0)
            last->next= nullptr;
        in.close();
    };
    void savefile(){
        ofstream out("DataBase.bin",ios::binary);
        node *current= head;
        while(current!= nullptr) {
            out.write((char *) &current->data, sizeof( Student));
            current=current->next;
        }
        out.close();
    };
    void append_item(Student s){
        insert_item(s,count);
    }
    void edit_item(int index){
        if (index<1 or index-1>=count or count<0)
            return;
        else {
            node *current = head;
            for (int i=0;i<index-1;i++)
                current=current->next;
            current->data.Edit_Student();
            
        }
    }
    void deleteItem(int index) {
        if (index<1 or index-1>=count or count<0)
            return;
        else{
            struct node* current = head;
            struct node* old;
            if (index == 1) {
                old = head;
                head = current->next;
                delete old;
                count--;
            }
            else {
                int i = 0;
                while (current) {
                    if (i == index - 2) {
                        old = current->next->next;
                        delete current->next;
                        current->next = old;
                        count--;
                        break;
                    }
                    i++;
                    current = current->next;
                }
            }
        }
    }
    void PrintList(){
        node* current=head;
        int index=0;
        while(current!= nullptr){
            cout << index+1 << ':'; current->data.Show_Basic_Info();
            index++;
            current=current->next;
        }
    }
    void PrintStudent(int index){
        if (index<1 or index-1>=count or count<0)
            return;
        else{
            node* current=head;
            for (int i=0;i<index-1;i++)
                current=current->next;
            current->data.Show_Full_Info();
        }
    }
    void CompleteTheTask(int year, char sex) {
        node* current = head;
        int amount_of_good=0; int amount_of_bad=0;
        while (current) {
            if (current->data.GetSex()=='ж')
                current = current->next;
            else {
                if (current->data.GetEntranceYear() == year) amount_of_good++;
                else amount_of_bad++;
                current = current->next;
            }
        }
        Student* good = (Student*)calloc(amount_of_good, sizeof(Student));
        Student* bad = (Student*)calloc(amount_of_bad, sizeof(Student));
        int index_of_good=0; int index_of_bad=0;
        current = head;
        while (current) {
            if (current->data.GetSex() == 'ж')
                current = current->next;
            else {
                if (current->data.GetEntranceYear() == year) {
                    good[index_of_good] = current->data;
                    index_of_good++;
                }
                else {
                    bad[index_of_bad] = current->data;;
                    index_of_bad++;
                }
                current = current->next;
            }
        }
        cout << "Студенты, поступившие в " << year << " году"<<endl;
        for (int i = 0; i < amount_of_good; i++) {
            cout << i + 1 << ")" << endl; good[i].Show_Basic_Info();
        }
        cout << "Студенты, поступившие в другие года" << endl;
        for (int i = 0; i < amount_of_bad; i++) {
            cout << i + 1 << ")" << endl; bad[i].Show_Basic_Info();
        }
        cout << "Нажмите для продолжения ";
        _getch();
        free(good); free(bad);
    }
};

