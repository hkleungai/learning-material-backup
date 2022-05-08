#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int MAX_NUM_BARRIERS = 5;
const int MAX_NUM_ROCKETS = 3;
const int MAX_HEALTH = 4;
enum Player {None = 0, Player1 = 1, Player2 = 2};

int rock_paper_scissors_input_loop(Player player) {
	int choice;
	cout << "Player" << player << ": Please choose between rock(1), paper(2) or scissors(3): ";
	cin >> choice;
	while (choice < 1 || choice > 3) {
		cout << "Invalid input. Please enter again." << endl;
		cout << "Player" << player << ": Please choose between rock(1), paper(2) or scissors(3): ";
		cin >> choice;
	}

	return choice;
}

int main() {
	// Game State Variables.
	Player winner = None; // The player who won the game.
	Player current_player = None, opponent_player = None; // The current active player, and the opponent player respectively.
	Player player_initiative = None;	// The player who won the Rock Paper Scissors and goes first for that round.

	int p1_num_barriers = 0, p2_num_barriers = 0;
	int p1_num_rockets = 0, p2_num_rockets = 0;
	int p1_health = MAX_HEALTH, p2_health = MAX_HEALTH;
	
	// Game Loop.
	while (winner == None) {
		// Rock Paper Scissors Loop.
		int p1_choice, p2_choice;
		while (true) {
			cout << endl;
			p1_choice = rock_paper_scissors_input_loop(Player1);
			p2_choice = rock_paper_scissors_input_loop(Player2);
			
			if (p1_choice == p2_choice) {
				cout << "It's a draw. Retry." << endl;
			}
			else {
				// Evaluate Rock Paper Scissors result and exit the loop.
				player_initiative = ((p1_choice == 1 && p2_choice == 3) || 
									 (p1_choice == 2 && p2_choice == 1) ||
									 (p1_choice == 3 && p2_choice == 2)) ? Player1 : Player2;
				break;
			}
		}		

		// Player Actions Loop.
		current_player = player_initiative;
		opponent_player = ((current_player == Player1) ? Player2 : Player1);
		int input = 0;
		bool invalid_input = false;
		for (int i = 0; i < 2 && winner == None; ++i, current_player = opponent_player, opponent_player = ((current_player == Player1) ? Player2 : Player1)) {
			cout << '\n' << "--------------------------------------------------" << endl;
			cout << "Player1: Health x " << p1_health << " | Rockets x " << p1_num_rockets << " | Barriers x " << p1_num_barriers << endl;
			cout << "Player2: Health x " << p2_health << " | Rockets x " << p2_num_rockets << " | Barriers x " << p2_num_barriers << endl;
			cout << "--------------------------------------------------" << endl;

			do {
				invalid_input = false;
				cout << '\n' << "Player" << current_player << ", choose any one action below: " << endl;
				cout << "0: Surrender." << endl;
				cout << "1: Build Barriers." << endl;
				cout << "2: Build Rockets." << endl;
				cout << "3. Launch Rockets." << endl;
				cin >> input;

				switch (input) {
					case 0: {
						cout << "Player" << current_player << " surrenders." << endl;
						winner = opponent_player;
						break;
					}

					case 1: {
						int& current_player_num_barriers = ((current_player == Player1) ? p1_num_barriers : p2_num_barriers);
						if (current_player_num_barriers >= MAX_NUM_BARRIERS) {
							cout << "Player" << current_player << ", you can't build any more barriers." << endl;
							invalid_input = true;
							break;
						}

						current_player_num_barriers += 1;
						cout << "Player" << current_player << ", you now have " << current_player_num_barriers << " barriers." << endl;

						break;
					}

					case 2: {
						int& current_player_num_rockets = ((current_player == Player1) ? p1_num_rockets : p2_num_rockets);
						if (current_player_num_rockets >= MAX_NUM_ROCKETS) {
							cout << "Player" << current_player << ", you can't build any more rockets." << endl;
							invalid_input = true;
							break;
						}

						current_player_num_rockets += 1;
						cout << "Player" << current_player << ", you now have " << current_player_num_rockets << " rockets." << endl;

						break;
					}

					case 3: {
						int& current_player_num_rockets = ((current_player == Player1) ? p1_num_rockets : p2_num_rockets);
						int& opponent_player_num_barriers = ((current_player == Player1) ? p2_num_barriers : p1_num_barriers);
						int& opponent_player_health = ((current_player == Player1) ? p2_health : p1_health);

						if (current_player_num_rockets == 0) {
							cout << "Player" << current_player << ", you have no rockets to launch." << endl;
							invalid_input = true;
							break;
						}

						opponent_player_num_barriers -= current_player_num_rockets;
						current_player_num_rockets = 0;
						if (opponent_player_num_barriers < 0) {
							opponent_player_health += opponent_player_num_barriers;
							opponent_player_num_barriers = 0;
						}
						if (opponent_player_health <= 0) {
							opponent_player_health = 0;
							winner = current_player;
						}

						cout << "Player" << opponent_player << " has " << opponent_player_num_barriers << " barriers left." << endl;
						cout << "Player" << opponent_player << " has " << opponent_player_health << "/" << MAX_HEALTH << " health left." << endl;

						break;
					}

					default: {
						cout << "Invalid input. Please enter again." << endl;
						invalid_input = true;
						break;
					}
				}

				if (winner != None) {
					cout << "Congratz! Player" << winner << ". You win!" << endl;
					break;
				}
			} while (invalid_input);
		}
	}

	system("pause");
	return 0;
}
