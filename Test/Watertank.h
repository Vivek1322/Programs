#include <iostream>
using namespace std;

class watertank {
    private:
        int current;
        int maximum;
    
    public:
        //constructor
        watertank (int maximum) {
            this->current = 0;
            this->maximum = maximum;
        }

        //constructor
        watertank (int current, int maximum) {
            this->current = current;
            this->maximum = maximum;
        }

        //member function to fill the tank with some volume
        void fill(int val) {
            if(val > (maximum - current)){
                current = maximum;
                cout<<"Filling the tank with this amount caused an overflow of "<< (val - (maximum - current)) <<" units\n";
                return;
            }
            current = current + val;
            return;
        }

        //member function to drain the entire tank
        void drain() {
            current = 0;
            return;
        }

        //member function to drain some volume of the tank
        void drain(int val) {
            if(val > current){
                current = 0;
                cout<<"Draining this amount from the tank caused underflow of "<< (val - current) <<" units\n";
                return;
            }
            current -= val;
            return;
        }

        //member function to check if the tank is empty
        bool isEmpty() {
            return current == 0 ? 1 : 0;
        }

        //operator overloading for >
        bool operator > (watertank B) {
            return current > B.current ? 1 : 0;
        }

        //operator overloading for <
        bool operator < (watertank B) {
            return current < B.current ? 1 : 0;
        }

        //operator overloading for ==
        bool operator == (watertank B) {
            return current == B.current ? 1 : 0;
        }

        //member function to print the data members of the tank
        void print() {
            cout<<"Current Volume = "<< this->current << ", Maximum Capacity = "<< this->maximum<<endl;
        }
};