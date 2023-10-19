#include <iostream>
#include <string.h>


struct City {
    const char *name;
    float population_millions;
    float area_km2;
};

void printCity(const City *city) {
    std::cout << "\n < city " << city->name << " >"
    << "\n > population: " << city->population_millions << " millions"
    << "\n > area: " << city->area_km2 << " km2\n";
}

const City cities[] = {
    {"Aarhus", 0.35, 91},
    {"Beijing", 21.5, 16410},
    {"Chicago", 2.7, 606},
    {"Dubai", 3.4, 4114},
    {"Edinburgh", 0.54, 175},
    {"Frankfurt", 0.75, 248},
    {"Geneva", 0.2, 15.92},
    {"Honolulu", 0.35, 272},
    {"Istanbul", 15.5, 5343},
    {"Jakarta", 10.6, 661},
    {"Kiev", 2.8, 839},
    {"Lima", 10.7, 2672},
    {"Marrakech", 1.0, 230},
    {"Nairobi", 4.4, 696},
    {"Oslo", 0.7, 454},
    {"Paris", 2.2, 105},
    {"Quito", 2.8, 324},
    {"Rome", 2.9, 1285},
    {"Seoul", 9.7, 605},
    {"Tokyo", 13.5, 2187},
    {"Ulaanbaatar", 1.3, 4704},
    {"Vienna", 1.9, 414},
    {"Warsaw", 1.8, 517},
    {"Xiamen", 3.7, 1699},
    {"Yokohama", 3.8, 437},
    {"Zurich", 0.4, 87.88}
};

int main() {
    /* You can say, that i've used switch case in wrong way. 
     * Побудувати блок-схему завдання, яке відповідає вашому варіанту. Реалізувати даний
алгоритм мовою С/С++ з використанням команд switch case.
     * There is no specification HOW i should use it! Whoahaha!  
     * I'm deeply concerned, that this part (question) is very important for algorythm */
    char coolAnswer;
    std::cout << " > Do you enjoy programming enourmously large switch statements? \n Y/N: \n";
    std::cin >> coolAnswer;

    switch (coolAnswer) {
    case 'Y': std::cout << "Well, i don't.\n"; break;
    case 'N': std::cout << "Me neither.\n"; break;
    default: break;
    }

    char letter; 
    std::cout << " > Enter letter: ";
    std::cin >> letter; 
    printCity(&cities[((int)letter-'A')]);

    return 0;
}




/*
    char letter;
    std::cout << " > Enter city starting letter: ";
    std::cin >> letter;
    
    switch (letter)
    {
    case 'A':
        printCity(&cities[0]);
        break;
    case 'B':  
        printCity(&cities[1]);
        break;
    case 'C':
        printCity(&cities[2]);
        break;
    case 'D':
        printCity(&cities[3]);
        break;
    case 'E':
        printCity(&cities[4]);
        break;
    case 'F':
        printCity(&cities[5]);
        break;
    case 'G':
        printCity(&cities[6]);
        break;
    case 'H':
        printCity(&cities[7]);
        break;  
    case 'I':
        printCity(&cities[8]);
        break;
    case 'J':
        printCity(&cities[9]);
        break;
    case 'K':
        printCity(&cities[10]);
        break;
    case 'L':   
        printCity(&cities[11]);
        break;
    case 'M':
        printCity(&cities[12]);
        break;
    case 'N':
        printCity(&cities[13]);
        break;  
    case 'O':
        printCity(&cities[14]);
        break;
    case 'P':
        printCity(&cities[15]);
        break;
    case 'Q':
        printCity(&cities[16]);
        break;
    case 'R':   
        printCity(&cities[17]);
        break;
    case 'S':   
        printCity(&cities[18]);
        break;
    case 'T':   
        printCity(&cities[19]);
        break;
    case 'U':   
        printCity(&cities[20]);
        break;
    case 'V':   
        printCity(&cities[21]);
        break;  
    case 'W':   
        printCity(&cities[22]);
        break;
    case 'X':   
        printCity(&cities[23]);
        break;
    case 'Y':   
        printCity(&cities[24]);
        break;
    case 'Z':   
        printCity(&cities[25]);
        break;

    default:
        break;
    }


*/