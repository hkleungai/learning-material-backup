//
// Hangman game
//

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int KILL_COUNT = 9;

// Makes a string consisting of only '_' with same length
string make_display_word(string s)
{
  string t = "";
  for (int i = 0; i < s.size(); i++)
    t += '_';
  return t;
}

// return true if char ch is in string s
bool ch_in_string(char ch, string s)
{
  for (int i=0; i < s.size(); i++)
    if (ch == s[i])
      return true;
  return false;
}

// enter ch into display at position where it appears 
// in secret
void enter_char(char ch, string secret, string &display)
{
  for (int i = 0; i < secret.size(); i++) {
    if (secret[i] == ch)
      display[i] = ch;
  }
}

int main()
{
  // The word to guess
  string secret_word = "superposition";
  // How many wrong guesses
  int wrong_count = 0;

  string display_word = make_display_word(secret_word);
  string already_guessed = "";

  while (true) {
    cout << "\nYour guess so far: " << display_word
         << "\nWrong guesses: " << wrong_count
	 << "   Letters guessed: " << already_guessed
	 << endl;
    if (display_word == secret_word) {
      cout << "You got it!\n";
      exit(0);
    }
    if (wrong_count >= KILL_COUNT) {
      cout << "You are dead!\n";
      exit(0);
    }
    cout << "\nGuess a letter: ";
    char ch;
    cin >> ch;
    ch = tolower(ch);
    if (!isalpha(ch)) {
      cout << "Only letters!\n\n";
    } else {
      if (ch_in_string(ch, already_guessed)) {
	cout << "You already guessed '" << ch << "'\n";
      } else {
	already_guessed += ch;
	if (ch_in_string(ch, secret_word)) {
	  enter_char(ch, secret_word, display_word);
	} else {
	  cout << "Sorry, wrong guess!\n";
	  wrong_count++;
	}
      }
    }
  }
  return 0;
}


