#ifndef HOTELMANAGEMENT_CPP
#define HOTELMANAGEMENT_CPP

#include "HotelManagement.h"
#include <iostream>
#include <cstdlib>

Person::Person()
{

}

Person::Person(string newname, int newphonenumber, int newroom_no, string newaddress)
{
    name = newname;
    phonenumber = newphonenumber;
    room_no = newroom_no;
    address = newaddress;
}

string Person::getName()
{
    return name;
}

int Person::getPhonenumber()
{
    return phonenumber;
}

string Person::getAddress()
{
    return address;
}

int Person::getRoom_no()
{
    return room_no;
}

void Person::setName(string newname)
{
    name = newname;
}

void Person::setPhonenumber(int newphonenumber)
{
    phonenumber = newphonenumber;
}

void Person::setAddress(string newaddress)
{
    address = newaddress;
}

void Person::setRoom_no(int newroom_no)
{
    room_no = newroom_no;
}
// Smaller elements go left
// larger elements go right
void BinarySearchTree::insert(Person p)
{
    tree_node* t = new tree_node;
    tree_node* parent;
    t->data = p;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
    // is this a new tree?
    if(isEmpty()) root = t;
    else
    {
        //Note: ALL insertions are as leaf nodes
        tree_node* curr;
        curr = root;
        // Find the Node's parent
        while(curr)
        {
            parent = curr;
            if(t->data.getName() > curr->data.getName())curr = curr->right;
            else curr = curr->left;
        }
        if(t->data.getName() < parent->data.getName())
            parent->left = t;

        else
            parent->right = t;



        }
}

void BinarySearchTree::remove(string p)
{
    //Locate the element
    bool found = false;
    if(isEmpty())
    {
        cout<<" Data is Empty! "<<endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL)
    {
        if(curr->data.getName() == p)
        {
            found = true;
            break;
        }
        else
        {
            parent = curr;
            if(p>curr->data.getName()) curr = curr->right;
            else curr = curr->left;
        }
    }
    if(!found)
    {
        cout<<" Data not found! "<<endl;
        return;
    }

    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL&& curr->right == NULL))
    {
        if(curr->left == NULL && curr->right != NULL)
        {
            if(parent->left == curr)
            {
                parent->left = curr->right;
                delete curr;
            }
            else
            {
                parent->right = curr->right;
                delete curr;
            }
        }
        else
        {
            if(parent->left == curr)
                {
                    parent->left = curr->left;
                    delete curr;
                }
                else
                {
                    parent->right = curr->left;
                    delete curr;
                }
            }
            return;
        }

    if( curr->left == NULL && curr->right == NULL)
    {
        if(parent->left == curr) parent->left = NULL;
        else parent->right = NULL;
        delete curr;
        return;
    }


    //Node with 2 children
    if (curr->left != NULL && curr->right != NULL)
    {
        tree_node* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL))
        {
            curr = chkr;
            delete chkr;
            curr->right = NULL;
        }
        else
        {
            if((curr->right)->left != NULL)
            {
                tree_node* lcurr;
                tree_node* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL)
                {
                    lcurrp = lcurr;
                    lcurr = lcurr->left;
                }
                curr->data = lcurr->data;
                delete lcurr;
                lcurrp->left = NULL;
            }
            else
            {
                tree_node* tmp;
                tmp = curr->right;
                curr->data = tmp->data;
                curr->right = tmp->right;
                delete tmp;
            }
        }
        return;
    }
}

void BinarySearchTree::print_inorder()
{
    inorder(root);
}

void BinarySearchTree::inorder(tree_node* p)
{
    if(p != NULL)
    {
        if(p->left)
        {
            inorder(p->left);
        }
        cout<<" \n Room Number: "<<p->data.getRoom_no()<< "   Name: "<<p->data.getName()<<" \n";
        if(p->right)
        {
            inorder(p->right);
        }
    }
    else return;
}

void BinarySearchTree::print_preorder()
{
    preorder(root);
}

void BinarySearchTree::preorder(tree_node* p)
{
    if(p != NULL)
    {
        cout<<" \n Room Number: "<<p->data.getRoom_no()<< "   Name: "<<p->data.getName()<<" \n";
        if(p->left)
        {
            preorder(p->left);
        }
        if(p->right)
        {
            preorder(p->right);
        }
    }
    else return ;
}

void BinarySearchTree::print_postorder()
{
    postorder(root);
}

void BinarySearchTree::postorder(tree_node* p)
{
    if(p != NULL)
    {
        if(p->left) postorder(p->left);
        if(p->right) postorder(p->right);
        cout<<" \n Room Number: "<<p->data.getRoom_no()<< "   Name: "<<p->data.getName()<<" \n";
    }
    else return;
}



void BinarySearchTree::search(string key)
{
    bool found = false;
    if(isEmpty())
    {
        cout<<" Data is empty! "<<endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL)
    {
        if(curr->data.getName() == key)
        {
            found = true;
            cout << "Room Number : " << key << " is " << curr->data.getRoom_no() << endl;
            cout << "Address : " << curr->data.getAddress() << endl;
            cout << "Phone number : " << curr->data.getPhonenumber() << endl;
            break;
        }
        else
        {
            parent = curr;
            if(key>curr->data.getName())
            {
                curr = curr->right;
            }
            else curr = curr->left;
        }
    }


    if(!found)
    {
        cout<<" Data not found! "<<endl;
        return;
    }
}

void BinarySearchTree::searchRoom(int number)
{
    bool found = false;
    if(isEmpty())
    {
        cout<<" Data is empty! "<<endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;

    while(curr != NULL)
    {
        if(curr->data.getRoom_no() == number)
        {
            found = true;
            cout << "Person name :  " << curr->data.getName() << endl;
            cout << "Room number : " << curr->data.getRoom_no() << endl;
            cout << "Phone number : " << curr->data.getPhonenumber() << endl;
            cout << "Address: " << curr->data.getAddress() << endl;
            break;
        }
        else
        {
            parent = curr;
            if(number>curr->data.getRoom_no())
            {
                curr = curr->right;
            }
            else curr = curr->left;
        }
    }


    if(!found)
    {
        cout<<" Data not found! "<<endl;
        return;
    }
}



void BinarySearchTree::changeRoom_no(string p, int newnumber)
{
    bool found = false;
    if(isEmpty())
    {
        cout<<"Data is empty! "<<endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL)
    {
        if(curr->data.getName() == p)
        {
            found = true;
            break;
        }
        else
        {
            parent = curr;
            if(p>curr->data.getName())
            {
                curr = curr->right;
            }
            else curr = curr->left;
        }
    }
    if(!found)
    {
        cout<<"Person not found and Room is Empty. "<<endl;
        return;
    }
    curr->data.setRoom_no(newnumber);
    cout<< "Successfully changed the Room number. " << endl;
}

void BinarySearchTree::changePhonenumber(string p, int newnumber)
{
    bool found = false;
    if(isEmpty())
    {
        cout<<" Data is empty! "<<endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL)
    {
        if(curr->data.getName() == p)
        {
            found = true;
            break;
        }
        else
        {
            parent = curr;
            if(p>curr->data.getName())
            {
                curr = curr->right;
            }
            else curr = curr->left;
        }
    }
    if(!found)
    {
        cout<<" Person not found. "<<endl;
        return;
    }
    curr->data.setPhonenumber(newnumber);
    cout<< "Successfully changed the number. " << endl;
}

#endif // HOTELMANAGEMENT_CPP
