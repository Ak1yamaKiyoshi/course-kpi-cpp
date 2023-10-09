#include <iostream>
#include <cmath>

using namespace std;

void GetValuesFromTypeA(double fullAmount);
void GetValuesFromTypeB(double fullAmount);
void GetValuesFromTypeC(double fullAmount);


int main() {
    int workType;
    cout << "What type of work u want choose\n" <<
            "Enter value from 1 to 3\n" <<
            "1 - Type of work A\n" <<
            "2 - Type of work B\n" <<
            "3 - Type of work C\n";
    cin >> workType;

    if (typeOfWork < 1 || typeOfWork > 3) {
        cout << "Nice joke";
        return 0;
    }

    cout << "Enter full amount:";
    double fullAmount;
    cin >> fullAmount;
    cout << endl;

    if (fullAmount < 0 ) {
        cout << "Nice joke";
        return 0;
    }

    if (typeOfWork == 1){
        GetValuesFromTypeA(fullAmount);
    }else if(typeOfWork == 2){
        GetValuesFromTypeB(fullAmount);
    }else{
        GetValuesFromTypeC(fullAmount);
    }

    return 0;
}

void GetValuesFromTypeA(double fullAmount){
    double salaryWithOutTax, salaryWithTax, tax;
    float percentageOfTask = 0.1;

    salaryWithOutTax = 100*abs(pow(fullAmount,2))/(abs(4.5-9.7* sin(fullAmount-3.1))+50);
    tax = salaryWithOutTax * percentageOfTask;
    salaryWithTax = salaryWithOutTax - tax;

    cout << "salary without tax: " << salaryWithOutTax << endl;
    cout << "tax: " << tax << endl;
    cout << "resulted salary: " << salaryWithTax << endl;

}

void GetValuesFromTypeB(double fullAmount){
    double salaryWithOutTax, salaryWithTax, tax;
    float percentageOfTask = 0.15;

    salaryWithOutTax = 150* abs(13.4 * sin(-1.26 * fullAmount)* cos(abs(fullAmount/7.5)) + 100);
    tax = salaryWithOutTax * percentageOfTask;
    salaryWithTax = salaryWithOutTax - tax;

    cout << "salary without tax: " << salaryWithOutTax << endl;
    cout << "tax: " << tax << endl;
    cout << "resulted salary: " << salaryWithTax << endl;
}

void GetValuesFromTypeC(double fullAmount){
    double salaryWithOutTax, salaryWithTax, tax;
    float percentageOfTask = 0.2;

    salaryWithOutTax = 100*abs(2 * sin(abs(2*fullAmount))* cos(2*fullAmount)-11.6* sin(fullAmount/0.4 - 1) + 135) ;
    tax = salaryWithOutTax * percentageOfTask;
    salaryWithTax = salaryWithOutTax - tax;

    cout << "salary without tax: " << salaryWithOutTax << endl;
    cout << "tax: " << tax << endl;
    cout << "resulted salary: " << salaryWithTax << endl;
}
