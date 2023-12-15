#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <Windows.h>

/*
10. У рядку символів визначити слова, які можна одержати перевертанням слова, що
вводиться з клавіатури на запит користувача. Кожне друге слово розбити на склади.
*/

int main() {
    std::vector<std::string> dictionaryArray;
    std::string line, word, target, syllable;

    std::stringstream output;
    const std::string vowels = "aeiouAEIOU";
    const std::string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";

    // Read dictionary from file
    std::ifstream dictionaryFile("dictionary.dict", std::ios::in);
    if (dictionaryFile.is_open())
        while (getline(dictionaryFile, line))
            dictionaryArray.push_back(line);
    else return -1;

    // Display first words for testing purposes
    std::cout << " > Dictionary loaded: " << dictionaryArray.size() << " words" << std::endl;
    std::cout << " > First 10 words: " << std::endl;
    for (int i = 0; i < 10; i++) std::cout << dictionaryArray[i] << std::endl;

    // Get input from user
    std::cout << " > Enter bunch of words: ";
    getline(std::cin, line);
    std::istringstream iss(line);

    while (iss >> word) {
        target = word;
        std::reverse(target.begin(), target.end());
        // if reversed string in dictionary
        if (std::find(dictionaryArray.begin(), dictionaryArray.end(), target) != dictionaryArray.end()) {
            std::cout << " > Found: " << target << std::endl;
            output << target << " ";
        }
        else { // break it into syllables
            for (size_t i = 0; i < word.size(); ++i) {
                syllable += word[i];
                if (vowels.find(word[i]) != std::string::npos && i + 1 < word.size() && consonants.find(word[i + 1]) != std::string::npos) {
                    output << syllable;
                    syllable.clear();
                    // If the next character is not the end of the word, add a "-"
                    if (i != word.size() - 1) output << "-";
                }
            }
            if (!syllable.empty()) output << syllable << " ";
        }
    }

    std::cout << " > Result: " << output.str() << std::endl;

    return 0;
}