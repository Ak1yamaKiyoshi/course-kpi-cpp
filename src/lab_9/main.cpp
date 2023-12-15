#include <iostream>
#include <string>


int main() {

    char selected;
    std::cout << "Enter a character: ";
    std::cin>>selected;
    fstream f;
    f.open("file.txt",ios::in);
    if(!f) {
        cout<<"Error in opening file";
        return -1;    
    } else if (f) {
        std::string line; 
        bool flag = false;
        while(getline(line)) {
            
        }
        f.close();
    }
    return 0;
}