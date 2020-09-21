#include <iostream>
#include "Watertank.h"
using namespace std;

int main() {
    //Initializing two objects with different constructor calls
    watertank A(5, 10);
    watertank B(11);

    //Printing the contents of both the watertanks
    cout<<"Watertank A :- ";
    A.print();
    cout<<"Watertank B :- ";
    B.print();
    
    //Checking if the watertank B is empty
    cout<<"Is Watertank B empty => "<<B.isEmpty()<<endl;

    //Filling the watertank B with 5 volume and printing its updated contents
    B.fill(5);
    cout<<"Watertank B :- ";
    B.print();

    //Checking if both watertank have equal current volume
    cout<<"Is volume of Watertank A & B equal => "<<(A == B)<<endl;

    //Draining 3 volumes from watertank A and printing its updated contents
    A.drain(3);
    cout<<"Watertank A :- ";
    A.print();

    //Checking if both watertank have equal current volume
    cout<<"Is volume of Watertank A & B equal => "<<(A == B)<<endl;

    //Checking if watertank A has more current colume than watertank B
    cout<<"Is Watertank A > WAtertank B => "<<(A > B)<<endl;

    //Checking if watertank A has less current colume than watertank B
    cout<<"Is Watertank A < WAtertank B => "<<(A < B)<<endl;

    return 0;
}
