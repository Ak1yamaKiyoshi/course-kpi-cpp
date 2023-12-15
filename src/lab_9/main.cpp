#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>

const std::string FILENAME = "sample.txt";
const std::string FILENAMEFINAL = "final.txt";


void writefile(int lines) {
    std::ofstream file(FILENAME);
    for (int i = 0; i < lines; i++) {
        file << "\n";
        for (int j = 0; j < 10; j++)
            file << static_cast<char>((rand() % 26) + 97);
    }
}

int main() {
    srand(time(NULL));
    int sameStart = 0, sameBoth = 0;
    char c;

    writefile(10000);
    std::fstream file(FILENAME);
    std::string line;
    std::string *lines = new std::string[10000];

    std::cout << "Enter a character: ";
    std::cin >> c;

    int i = 0;
    while (std::getline(file, line)) {
        if (line[0] == c) {
            sameStart++;
            lines[i++] = "same_start;" + line + "\n";
        }
        if (line[0] == c && line[line.length() - 1] == c) {
            sameBoth++;
            lines[i++] = "same_start&end;" + line + "\n";
        }
    }

    std::cout << "Lines starting with " << c << ": " << sameStart << std::endl;
    std::cout << "Lines starting and ending with " << c << ": " << sameBoth << std::endl;

    std::ofstream filefinal(FILENAMEFINAL);
    i = 0;
    while(lines[i++] != "")
        filefinal << lines[i];
    return 0;
}