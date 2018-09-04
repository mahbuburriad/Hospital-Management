#ifndef HOTELMANAGEMENT_H
#define HOTELMANAGEMENT_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Person
{
private:
    string name;
    int phonenumber;
    int room_no;
    string address;
public:
    Person();
    Person(string name, int phonenumber, int room_no, string address);

    string getName();
    int getPhonenumber();
    int getRoom_no();
    string getAddress();

    void setName(string newname);
    void setPhonenumber(int newphonenumber);
    void setRoom_no(int newroom_no);
    void setAddress(string newaddress);
};

class BinarySearchTree
{
private:
    struct tree_node
    {
        tree_node* left;
        tree_node* right;
        Person data;
    };
    tree_node* root;
public:
    BinarySearchTree()
    {
        root = NULL;
    }
    bool isEmpty() const { return root==NULL; }
    void print_inorder();
    void inorder(tree_node*);
    void print_preorder();
    void preorder(tree_node*);
    void print_postorder();
    void postorder(tree_node*);
    void insert(Person);
    void remove(string);
    void search(string key);
    void changePhonenumber(string key, int newnumber);
    void changeRoom_no(string key, int newroom_no);
    void searchRoom(int number);
};
#endif // HOTELMANAGEMENT_H
