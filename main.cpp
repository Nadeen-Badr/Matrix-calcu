#include <iostream>
#include "matrix.h"
#include "matrix.cpp"
//matrixCalculator and menu
class matrixCalculation{
public:
    void Menu(){
        int row,col,num,r,c;
        cout << " Welcome to Matrix Calculator \n";
        cout << " -------------------------------------- \n";
        cout<<"1- Perform Matrix Addition\n"
              "2- Perform Matrix Subtraction\n"
              "3- Perform Matrix Multiplication\n"
              "4- Matrix Transpose\n";
        cout<<"Enter number \n";
        cin>>num;
        switch (num){
            //add two matrix!!!
            case 1:
            {
                cout << "Enter rows and cols of the first matrix \n";
                cin >> row >> col;
                cout << endl;
                Matrix <int> m1(row,col);
                cout<<"Enter element of first Matrix"<<endl;
                cin >> m1;
                cout << endl;
                cout << "Enter rows and cols of the second matrix \n";
                cin >> row >> col;
                cout << endl;
                Matrix <int> m2(row, col);
                cout<<"Enter element of second Matrix"<<endl;
                cin >> m2;
                cout << endl;
                cout<<"Result is:"<<endl;
                Matrix <int> rest(m1 + m2);
                cout << rest;
                break;
            }
            //sub two mat!!
            case 2:
            {
                cout << "Enter rows and cols of the first matrix \n";
                cin >> row >> col;
                cout << endl;
                Matrix <int> m1(row, col);
                cout<<"Enter element of first Matrix"<<endl;
                cin >> m1;
                cout << "\n";
                cout << "Enter rows and cols of the second matrix \n";
                cin >> row >> col;
                cout << "\n";
                Matrix <int> m2(row, col);
                cout<<"Enter element of second Matrix"<<endl;
                cin >> m2;
                cout << endl;
                cout<<"Result is:\n";
                Matrix <int> rest(m1 - m2);
                cout << rest;
                break;
            }
            //multi two mat!!
            case 3:
            {
                cout << "Enter rows and cols of the first matrix \n";
                cin >> row >> col;
                cout << endl;
                Matrix <int> m1(row, col);
                cout<<"Enter element of first Matrix"<<endl;
                cin >> m1;
                cout << endl;
                cout << "Enter rows and cols of the second matrix \n";
                cin >> row >> col;
                cout << endl;
                Matrix <int> m2(row, col);
                cout<<"Enter element of second Matrix"<<endl;
                cin >> m2;
                cout << endl;
                cout<<"Result is:"<<endl;
                Matrix <int> rest(m1 * m2);
                cout << rest;
                break;
            }
            //transport matrix!!
            case 4:
            {
                cout << "Enter rows and cols of the first matrix \n";
                cin >> row >> col;
                cout << endl;
                Matrix <int> m1(row, col);
                cout<<"Enter element of first Matrix"<<endl;
                cin >> m1;
                cout << endl;
                cout<<"Result is:\n";
                m1.transMatrix();
                break;
            }
            default:
            {
                cout << "Invalid number \n";
                break;
            }
        }
    }
};
int main(){
    matrixCalculation m;
    m.Menu();

    return 0;
}