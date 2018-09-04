#include "HotelManagement.h"

#include<iostream>
#include<cstdlib>
//#include<stdio.h>

using namespace std;

int main()
{
    BinarySearchTree b;
    int ch;
    string name;
    string address;
    string key;
    int phonenumber;
    int room_no;
    int number;
    Person tmp;
    Person tmp1;
    //fillTree(&b);
    b.print_preorder();
    while(1)
    {

    cout<<endl<<endl;
    cout<<" HOTEL MANAGEMENT "<<endl;
    cout<<" ----------------------------- "<<endl;
    cout<<" 1. Insert Person ID"<<endl;
    cout<<" 2. View Person Info (In-Order Traversal) "<<endl;
    cout<<" 3. View Person Info (Pre-Order Traversal) "<<endl;
    cout<<" 4. View Person Info (Post-Order Traversal) "<<endl;
    cout<<" 5. Search by Name "<<endl;
    cout<<" 6. Search by room number "<<endl;
    cout<<" 7. Remove Person Info "<<endl;
    cout<<" 8. Change Contact Number "<<endl;
    cout<<" 9. Change Room Number Number "<<endl;
    cout<<" 10. Exit "<<endl;

    cout<<"\nEnter your choice : ";
    cin>>ch;
    switch(ch)
    {

        case 1 : cout<<"\nEnter name to be inserted: ";
        cin>>name;
        cout << "Enter Room Number : ";
        cin >> room_no;
        cout << "Enter Address : ";
        cin >> address;
        cout << "Enter Phone Number : ";
        cin >> phonenumber;

        tmp.setName(name);
        tmp.setPhonenumber(phonenumber);
        tmp.setAddress(address);
        tmp.setRoom_no(room_no);
        b.insert(tmp);
        //insertfile(name,phonenumber);
        break;


        case 2 : cout<<endl;
        cout<<" View Contacts(In-Order Traversal):  "<<endl;
        cout<<" ----------------------------------"<<endl;
        b.print_inorder();
        break;

        case 3 : cout<<endl;
        cout<<" View Contacts(Pre-Order Traversal) "<<endl;
        cout<<" ----------------------------------"<<endl;
        b.print_preorder();

        break;
        case 4 : cout<<endl;
        cout<<" View Contacts(Post-Order Traversal) "<<endl;
        cout<<" -----------------------------------"<<endl;
        b.print_postorder();
        break;

        case 5 :
        /*cout<<" Search Person Info By Name :  "<<endl;
        cout<<" --------------"<<endl;
        cout<<" "<<endl;*/
        cout <<"Enter the name of the person to search for: ";
        cin>>key;
        b.search(key);
        break;

        case 6 :
        /*cout<<" Search Room Info:  "<<endl;
        cout<<" --------------"<<endl;
        cout<<" "<<endl; */
        cout <<"Enter the Room number of the person to search for: ";
        cin>>number;
        b.searchRoom(number);
        break;


        case 7 : cout<<"Enter data to be deleted : ";

        cin>>key;
        b.remove(key);
        break;


        case 8 : cout<<"Enter the name of the person whose number you wish to change: ";
        cin>>name;
        cout<<endl<<"Enter the new Phone Number: " <<endl;
        cin>>phonenumber;
        cout<<endl;
        b.changePhonenumber(name, phonenumber);
        break;


        case 9 : cout<<"Enter the Room number which you wish to change: ";
        cin>>room_no;
        cout<<endl<<"Enter the new Room Number: " <<endl;
        cin>>room_no;
        cout<<endl;
        b.changeRoom_no(name, room_no);
        break;

        case 10 : return 0;
        default :
        cout<<"input again";
        break;
        }

    }
}

