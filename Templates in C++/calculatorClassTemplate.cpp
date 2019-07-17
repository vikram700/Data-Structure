// This is example of the class template
/*
   we can create a object of the class tempate using the following syntax

   className<dataType > classObject;

   ex:
      className<int > integerObject;
      className<float > floatObject;
      className<string > stringObject;

 */

#include<bits/stdc++.h>

using namespace std;

template<typename T >

class Calculator{

    private :
        T firstNumber, secondNumber;
    public  :
        Calculator(T x, T y){
            firstNumber  = x;
            secondNumber = y;
        }

        void displayResult(){
            cout<<"Two Numbers are : "<<firstNumber<<" "<<secondNumber<<"\n";
            cout<<"Addition is : "<<add()<<"\n";
            cout<<"Subtraction is : "<<subtraction()<<"\n";
            cout<<"multiplication is : "<<multiplication()<<"\n";
            cout<<"Division is : "<<division()<<"\n";
        }

        T add(){ return firstNumber + secondNumber ;}
        T subtraction(){ return firstNumber - secondNumber; }
        T multiplication(){ return firstNumber*secondNumber; }
        T division(){ return firstNumber/secondNumber;}
};

int main(){

    Calculator<int > intClass(2,1);
    Calculator<float > floatClass(4.5, 2.3);

    cout<<"Integer result is : "<<"\n";
    intClass.displayResult();

    cout<<"Float result is : "<<"\n";
    floatClass.displayResult();

    return 0;
}

