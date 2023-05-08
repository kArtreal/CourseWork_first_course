#ifndef TEST_MYLIST_H
#define TEST_MYLIST_H
#include "Student.h"
#include <fstream>
#include <iostream>

using namespace std;


class MyList{
private:
    struct node{
        Student data;
        node* next;
    };

public:
    MyList(){
        count = 0;
        head = nullptr;
        last = nullptr;
    }

    node* head;
    node* last;
    int count;

    void loadfile(){
        ifstream in("10.bin",ios::binary);
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
        ofstream out("10.bin",ios::binary);
        node *current= head;
        while(current!= nullptr) {
            out.write((char *) &current->data, sizeof( Student));
            current=current->next;
        }
        out.close();
    };
    void cleanList(){
        node *current= head;
        int index=0;
        while(!current->data.GetName()){
            deleteItem(index);
        }
    }

    void add_item(Student _st)
    {
        node* new_item = new node();
        new_item->data = _st;
        if (count==0){
            new_item->next = head;
            head = new_item;
        }
        count++;
    }

    void insert_item(Student st,int index){
        if (not (index >= 0 and index <= count and count >= 0))
            return;
        if (count==0)
            add_item(st);
        else{
            node* current=head;
            for (int i = 0; i < index-1; i++) {
                current = current->next;
            }
            node* new_item = new node();
            new_item->data = st;
            new_item->next = current->next;
            current->next = new_item;
            count++;
        }
    }

    void append_item(Student s){
        insert_item(s,count);
    }

    void edit_item(Student ST, int index){
        if (index<1 or index-1>=count or count<0)
            return;
        else {
            node *current = head;
            for (int i=0;i<index-1;i++)
                current=current->next;
            current->data=ST;
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
};
#endif //TEST_MYLIST_H
