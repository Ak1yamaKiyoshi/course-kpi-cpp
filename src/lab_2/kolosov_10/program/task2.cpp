
#include <iostream>
#include <cmath>

using namespace std;
struct Work {
    char type; double amount;
};

struct Salary {
    float netto; float tax;
};

/** @param h hours of work  */
float formula(float h) {return sin(h) - pow(cos(h), 3) * sin(h*h - 4.2) + 4.27; }
 
/** @brief {tax modifier, formula modifier} */
const float modifiers[][2] = {
    {0.2,  100.}, {0.15, 150.}, {0.1,  135.},
};

/** @brief calculates netto and tax of salary using formula and modifiers (mod, percentage) */
Salary* evaluate (Salary *salary, float hours, float mod, float percentage) { 
    salary->netto = mod*abs(formula(hours)+mod);
    salary->tax = salary->netto * percentage;
    return salary;
}

void printSalary(Work work) {
    if (work.type < 'A' 
     || work.type > 'C') return;

    Salary *result = evaluate(
        new Salary, work.amount, 
        modifiers[toupper(work.type)-'A'][1], 
        modifiers[toupper(work.type)-'A'][0]
    ); 

    cout << "\n < salary for " << work.amount 
    << " hours of " << work.type << " work type >"
    << "\n > netto salary:  "  << result->netto
    << "\n > brutto salary: "  << result->netto - result->tax << "\n";
    delete result;
}

int main() {
    Work work;

    cout << " > Types of work: A, B and C\n Enter your type and hours you worked: ";
    cin >> work.type >> work.amount; 
    printSalary(work);
}

