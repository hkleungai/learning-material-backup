#include <iostream>
using namespace std;

int main() {
   // Initialize the puzzle.
   char pos1 = 'B', pos2 = 'C', pos3 = 'A', pos4 = '*';
   int choice, temp;
   int round = 0;
   // Start the game.
   cout << "Welcome to the Sliding Puzzle Game!" << endl;
   
   while (!(((pos3 - pos2) == 1) && ((pos2 - pos1) == 1) && (pos4 == '*'))) {
      
      round++;
      cout << "Round " << round << ": " << endl;
      cout << "Position info:" << endl;
      cout << "12" << endl << "34" << endl;
      cout << "Puzzle status:" << endl;
      cout << pos1 << pos2 << endl;
      cout << pos3 << pos4 << endl;


      cout << "Enter a position number between 1 to 4 to slide:";
      cin >> choice;

      // input validation for choosing the block
		while ( ! (choice >= 1 && choice <= 4) ) {
			cout << "Invalid input." << endl;
			cout << "Enter a number between 1 to 4 to slide:";
			cin >> choice;
		}

      // slide the chosen block
      switch (choice){
         case 1:
            if (pos1 != '*') {
               if (pos2 == '*') { temp = pos2; pos2 = pos1; pos1 = temp; }
               else if (pos3 == '*') { temp = pos3; pos3 = pos1; pos1 = temp; }
            }
            break;
         case 2:
            if (pos2 != '*') {
               if (pos1 == '*') { temp = pos1; pos1 = pos2; pos2 = temp; }
               else if (pos4 == '*') { temp = pos4; pos4 = pos2; pos2 = temp; }
            }
            break;
         case 3:
            if (pos3 != '*') {
               if (pos1 == '*') { temp = pos1; pos1 = pos3; pos3 = temp; }
               else if (pos4 == '*') { temp = pos4; pos4 = pos3; pos3 = temp; }
            }
            break;
         case 4:
            if (pos4 != '*') {
               if (pos2 == '*') { temp = pos2; pos2 = pos4; pos4 = temp; }
               else if (pos3 == '*') { temp = pos3; pos3 = pos4; pos4 = temp; }
            }
            break;
         default:
            break;
      }
   }  
   
   // Show the steps.
   cout << "Congratulations! The puzzle is solved in " << round << " steps." << endl;
   // Show the final puzzle status.
   cout << "Final puzzle status:" << endl;
   cout << pos1 << pos2 << endl;
   cout << pos3 << pos4 << endl;
   
   return 0;
}
