#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Word list
vector<string> words = {
    "python", "github", "hacker", "network",
    "cipher", "algorithm", "security", "firewall"
};

// Draw hangman
void drawHangman(int wrong) {
    cout << "\n";
    cout << "  +---+" << "\n";
    cout << "  |   |" << "\n";
    cout << "  |   " << (wrong > 0 ? "O" : " ") << "\n";
    cout << "  |  " << (wrong > 2 ? "/" : " ") 
         << (wrong > 1 ? "|" : " ") 
         << (wrong > 3 ? "\\" : " ") << "\n";
    cout << "  |  " << (wrong > 4 ? "/" : " ") 
         << " " 
         << (wrong > 5 ? "\\" : " ") << "\n";
    cout << "  |" << "\n";
    cout << "=========" << "\n";
}

int main() {
    srand(time(0));
    
    // Pick random word
    string word = words[rand() % words.size()];
    string guessed(word.length(), '_');
    
    int wrongGuesses = 0;
    int maxWrong = 6;
    vector<char> usedLetters;
    
    cout << "🎮 Welcome to Hangman!" << "\n";
    cout << "Guess the word letter by letter!" << "\n";
    
    while (wrongGuesses < maxWrong && guessed != word) {
        drawHangman(wrongGuesses);
        
        cout << "\nWord: ";
        for (char c : guessed) cout << c << " ";
        
        cout << "\nWrong guesses left: " 
             << (maxWrong - wrongGuesses) << "\n";
        
        cout << "Used letters: ";
        for (char c : usedLetters) cout << c << " ";
        
        cout << "\nEnter a letter: ";
        char guess;
        cin >> guess;
        
        // Check if already used
        bool alreadyUsed = false;
        for (char c : usedLetters) {
            if (c == guess) {
                alreadyUsed = true;
                break;
            }
        }
        
        if (alreadyUsed) {
            cout << "Already used that letter!\n";
            continue;
        }
        
        usedLetters.push_back(guess);
        
        // Check if correct
        bool correct = false;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == guess) {
                guessed[i] = guess;
                correct = true;
            }
        }
        
        if (!correct) {
            wrongGuesses++;
            cout << "Wrong! ❌\n";
        } else {
            cout << "Correct! ✅\n";
        }
    }
    
    drawHangman(wrongGuesses);
    
    if (guessed == word) {
        cout << "\n🎉 You won! The word was: " 
             << word << "\n";
    } else {
        cout << "\n😢 You lost! The word was: " 
             << word << "\n";
    }
    
    return 0;
}
