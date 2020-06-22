//
//  main.cpp
//  Double Circular Linked List
//
//  Created by Ira Xavier Porchia on 5/18/20.
//  Copyright © 2020 Ira Xavier Porchia. All rights reserved.
//

#include <iostream>
using namespace std;

class node{
    friend class DCL;
private:
    int _data;
    node *_next;
    node *_prev;
public:
    node():
    _data(-1),_next(nullptr),_prev(nullptr){}
    
    node(int data):
    _data(data),_next(nullptr),_prev(nullptr){}
};

class DCL{
private:
    node *_head;
public:
    DCL():
    _head(nullptr){}
    
    ~DCL(){
        clear();
    }
    
    void clear(){
        if(_head == nullptr){
            return;
        }
        node *p = _head->_next;
        node *temp;
        _head->_next = nullptr;
        _head->_prev = nullptr;
        while(p != _head){
            temp = p;
            p = p->_next;
            p->_prev = nullptr;
            temp->_prev = nullptr;
            temp->_next = nullptr;
            delete temp;
        }
        delete _head;
    }
    
    void prepend(int data){
        if(_head == nullptr){
            _head = new node();
            _head->_next = new node(data);
            _head->_prev = _head->_next;
            _head->_next->_next = _head;
            _head->_next->_prev = _head;
            return;
        }
        node *p = new node(data);
        p->_next = _head->_next;
        p->_prev = _head;
        _head->_next = p;
        p->_next->_prev = p;
    }
    
    void traverse(){
        node *p = _head->_next;
        while(p != _head){
            cout << p->_data << " ";
            p = p->_next;
        }
        cout << endl;
    }
    
    void remove(int data){
        if(_head == nullptr){
            return;
        }
        node *p = _head->_next;
        while(p != _head){
            if(p->_data == data){
                p->_next->_prev = p->_next->_prev->_prev;
                p->_prev->_next = p->_prev->_next->_next;
                p->_next = nullptr;
                p->_prev = nullptr;
                return;
            }
            p = p->_next;
        }
    }
    
    void append(int data){
        if(_head == nullptr){
            _head = new node();
            _head->_next = new node(data);
            _head->_prev = _head->_next;
            _head->_next->_next = _head;
            _head->_next->_prev = _head;
            return;
        }
        node *p = new node(data);
        p->_next = _head;
        p->_prev = _head->_prev;
        _head->_prev->_next = p;
        _head->_prev = p;
    }
    
};

int main(int argc, const char * argv[]) {
    DCL list;
//           list.prepend(50);
//           list.prepend(100);
//           list.prepend(150);
//           list.prepend(200);
//           list.prepend(250);
//           list.prepend(300);
//           list.prepend(350);
//           list.prepend(400);
//           list.prepend(450);
           list.append(5);
           list.append(10);
           list.append(15);
           list.append(20);
           list.append(25);
           list.append(35);
           list.append(40);
           list.append(45);
           list.traverse();
//           list.head();
           list.remove(35);
           list.traverse();
//           list.head();
    return 0;
}
