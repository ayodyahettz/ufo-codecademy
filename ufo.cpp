#include <iostream>
#include <vector>
#include "ufo_functions.hpp"

int main() {
  //greeting on startup of program
  greet();

  std::string codeword = "codecademy";
  std::string answer = "__________";
  int misses = 0;
  std::vector<char> incorrect;
  bool guess = false;
  char letter;

  //player turns
  while (answer!= codeword && misses < 7){
    display_misses(misses); 
    display_status(incorrect, answer);
    std::cout << "\n\nPlease enter your guess: ";
    std::cin >> letter;
    for (int i = 0; i < codeword.length(); i++){
      if(letter == codeword[i]){
        answer[i] = letter;
        guess = true;
      }
    }
    if (guess == true){
      std::cout << "\nCorrect! You're closer to cracking the codeword.\n";
    } else {
      std::cout << "\nIncorrect! The trctor beam pulls the person in further.\n";
      incorrect.push_back(letter);
      misses++;
    }
    guess = false;
  }

  //call for end_game function
  end_game(codeword, answer);
}
