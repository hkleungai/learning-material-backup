#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//#include <string> // For alternative solution.
//using std::string;

// Game State Constants.
const int MAX_HEALTH = 30;
const int MAX_CHARGE = 3;

/*
 * Output messages: Please copy and paste from here.
 * cout << "Player, choose one of the following actions:" << endl;
 * cout << "0: ATTACK" << endl;
 * cout << "1: DEFEND" << endl;
 * cout << "2: CHARGE" << endl;
 * cout << "Player, you are already at FULL CHARGE!" << endl;
 * cout << "Invalid input. Please enter again.\n" << endl;
 * cout << "Player ATTACKS!" << endl;
 * cout << "Player DEFENDS!" << endl;
 * cout << "Player CHARGES!" << endl;
 * cout << "Computer ATTACKS!" << endl;
 * cout << "Computer DEFENDS!" << endl;
 * cout << "Computer CHARGES!" << endl;
 * cout << "Player REFLECTED DAMAGE!" << endl;
 * cout << "Player NULLIFIED DAMAGE!" << endl;
 * cout << "Computer REFLECTED DAMAGE!" << endl;
 * cout << "Computer NULLIFIED DAMAGE!" << endl;
 * cout << "Player's CHARGING INTERRUPTED!" << endl;
 * cout << "Computer's CHARGING INTERRUPTED!" << endl;
 * cout << "Player receives " << player_damage << " DAMAGE!" << endl;
 * cout << "Computer receives " << computer_damage << " DAMAGE!" << endl;
 * cout << "CONGRATULATIONS! Player wins!" << endl;
 * cout << "GAME OVER! Computer wins!" << endl;
 * cout << "SURPRISE! It's a tie!" << endl;
 */

// Our own simple implementation of a pseudo-random number generator, for debugging and automated grading consistency.
static unsigned long rng_lab1 = 0;

static void _srand(unsigned seed) {
	rng_lab1 = seed;
}

static int _rand() {
	rng_lab1 = (1103515245 * rng_lab1 + 12345) % (1 << 31);
    return rng_lab1 & 0x7FFFFFFF;
}

int main() {
	// Welcoming Message.
	cout << "Welcome to COMP 2012H Lab 1!" << '\n';
	cout << "ATTACK, DEFEND, CHARGE!" << '\n';
	cout << endl;

	// Setting Computer Player.
	cout << "Choose Computer Player (0-100): ";
	unsigned int id;
	cin >> id;
	_srand(id + 2012); // Initialize pseudo-random number generator.

	// Game State Variables.
	int player_health = MAX_HEALTH, computer_health = MAX_HEALTH;
	int player_charge = 0, computer_charge = 0;
	int player_action = 0, computer_action = 0; // 0 for ATTACK, 1 for DEFEND, 2 for CHARGE.
	int player_damage = 0, computer_damage = 0; // Working variables to calculate damage each turn, before modifying player_health and computer_health.
	int winner = 0; // 0 for None, 1 for Player, 2 for Computer, 3 for a tie.

	// Game Loop.
	while (true) {
		// Display Game State.
		cout << endl;
		cout << "--------------------------------------------------" << '\n';
		cout << "Player HEALTH: " << player_health << "/" << MAX_HEALTH;
		cout << '\t';
		cout << "Computer HEALTH: " << computer_health << "/" << MAX_HEALTH;
		cout << '\n';
		cout << "Player CHARGE: " << player_charge << "/" << MAX_CHARGE;
		cout << '\t';
		cout << "Computer CHARGE: " << computer_charge << "/" << MAX_CHARGE;
		cout << '\n';
		cout << "--------------------------------------------------" << endl;

		// Game Over Condition.
		if (winner != 0) {
			break;
		}

		/*
		 * Task 1: Handle Player's ACTION and Computer's ACTION.
		 * - Ask the Player to choose between ATTACK(0), DEFEND(1), and CHARGE(2) for player_action.
		 * - If the Player chooses CHARGE while at FULL CHARGE, notify the Player and ask again.
		 * - If the Player's input is invalid, ask again.
		 * - Announce the Player's action, and afterwards, announce the Computer's action.
		 * - Hint code provided for getting player_action and computer_action.
		 */

		// Player's ACTION.
		bool invalid_input;
		do {
			invalid_input = false;
			cout << "Player, choose one of the following actions:" << '\n';
			cout << "0: ATTACK" << '\n';
			cout << "1: DEFEND" << '\n';
			cout << "2: CHARGE" << endl;
			cin >> player_action;

			switch (player_action) {
			case 0:
				cout << "Player ATTACKS!" << endl;
				break;

			case 1:
				cout << "Player DEFENDS!" << endl;
				break;

			case 2:
				if (player_charge != MAX_CHARGE) {
					cout << "Player CHARGES!" << endl;
					break;
				} else {
					cout << "Player, you are already at FULL CHARGE!" << endl;
				}
				// No break, fall-through to default case.

			default:
				cout << "Invalid input. Please enter again." << '\n';
				cout << endl;
				invalid_input = true;
			}
		} while (invalid_input);

		// Computer's ACTION.
		computer_action = ((computer_charge == MAX_CHARGE) ? (_rand() % 2) : (_rand() % 3)); // Random Computer Action.
		switch (computer_action) {
		case 0:
			cout << "Computer ATTACKS!" << endl;
			break;

		case 1:
			cout << "Computer DEFENDS!" << endl;
			break;

		case 2:
			cout << "Computer CHARGES!" << endl;
			break;
		}

		/*
		 * Task 2: Determine Player's DAMAGE and Computer's DAMAGE.
		 * - Determine player_damage and computer_damage according to the provided chart.
		 * - Announce REFLECTED DAMAGE and NULLIFIED DAMAGE whenever they occur.
		 */

		// Reset to zero for simplicity.
		player_damage = 0;
		computer_damage = 0;

		// Player dealing DAMAGE to Computer.
		if (player_action == 0) {
			switch (player_charge) {
			case 0:
				if (computer_action == 1) {
					player_damage = 1;
					cout << "Computer REFLECTED DAMAGE!" << endl;
				} else {
					computer_damage = 1;
				}
				break;

			case 1:
				if (computer_action == 1) {
					cout << "Computer NULLIFIED DAMAGE!" << endl;
				} else {
					computer_damage = 2;
				}
				break;

			case 2:
				if (computer_action == 1) {
					computer_damage = 2;
				} else {
					computer_damage = 5;
				}
				break;

			case 3:
				if (computer_action == 1) {
					computer_damage = 5;
				} else {
					computer_damage = 10;
				}
				break;
			}
		}

		// Computer dealing DAMAGE to Player.
		if (computer_action == 0) {
			switch (computer_charge) {
			case 0:
				if (player_action == 1) {
					computer_damage = 1;
					cout << "Player REFLECTED DAMAGE!" << endl;
				} else {
					player_damage = 1;
				}
				break;
			case 1:
				if (player_action == 1) {
					cout << "Player NULLIFIED DAMAGE!" << endl;
				} else {
					player_damage = 2;
				}
				break;
			case 2:
				if (player_action == 1) {
					player_damage = 2;
				} else {
					player_damage = 5;
				}
				break;
			case 3:
				if (player_action == 1) {
					player_damage = 5;
				} else {
					player_damage = 10;
				}
				break;
			}
		}

//		// Alternative for-loop solution.
//		for (int i = 0; i < 2; i += 1) {
//			int& attacker_damage = ((i == 0) ? player_damage : computer_damage);
//			int attacker_action = ((i == 0) ? player_action : computer_action);
//			int attacker_charge = ((i == 0) ? player_charge : computer_charge);
//			int& defender_damage = ((i == 0) ? computer_damage : player_damage);
//			int defender_action = ((i == 0) ? computer_action : player_action);
//			string defender_string = ((i == 0) ? "Computer" : "Player");
//
//			if (attacker_action == 0) {
//				switch (attacker_charge) {
//				case 0:
//					if (defender_action == 1) {
//						attacker_damage = 1;
//						cout << defender_string << " REFLECTED DAMAGE!" << endl;
//					} else {
//						defender_damage = 1;
//					}
//					break;
//
//				case 1:
//					if (defender_action == 1) {
//						cout << defender_string << " NULLIFIED DAMAGE!" << endl;
//					} else {
//						defender_damage = 2;
//					}
//					break;
//
//				case 2:
//					if (defender_action == 1) {
//						defender_damage = 2;
//					} else {
//						defender_damage = 5;
//					}
//					break;
//
//				case 3:
//					if (defender_action == 1) {
//						defender_damage = 5;
//					} else {
//						defender_damage = 10;
//					}
//					break;
//				}
//			}
//		}

		/*
		 * Task 3: Update Player's CHARGE and Computer's CHARGE.
		 * - Update player_charge and computer_charge according to the following rules:
		 * - If one ATTACKS, one loses all CHARGE.
		 * - If one CHARGES and the opponent ATTACKS, one's CHARGING is INTERRUPTED and one's CHARGE resets.
		 * - If one CHARGES and the opponent does not ATTACK, one's CHARGE increments.
		 * - Announce INTERRUPTED CHARGING whenever it occurs.
		 */

		// Player's CHARGE.
		if (player_action == 0) {
			player_charge = 0;
		} else if (player_action == 2) {
			if (computer_action == 0) {
				player_charge = 0;
				cout << "Player's CHARGING INTERRUPTED!" << endl;
			} else {
				player_charge += 1;
			}
		}

		// Computer's CHARGE.
		if (computer_action == 0) {
			computer_charge = 0;
		} else if (computer_action == 2) {
			if (player_action == 0) {
				computer_charge = 0;
				cout << "Computer's CHARGING INTERRUPTED!" << endl;
			} else {
				computer_charge += 1;
			}
		}

//		// Debatable whether or not this is actually a code reduction and/or readability improvement.
//		for (int i = 0; i < 2; i += 1) {
//			int attacker_action = ((i == 0) ? player_action : computer_action);
//			int& attacker_charge = ((i == 0) ? player_charge : computer_charge);
//			string attacker_string = ((i == 0) ? "Player" : "Computer");
//			int defender_action = ((i == 0) ? computer_action : player_action);
//
//			if (attacker_action == 0) {
//				attacker_charge = 0;
//			} else if (attacker_action == 2) {
//				if (defender_action == 0) {
//					attacker_charge = 0;
//					cout << attacker_string << "'s CHARGING INTERRUPTED!" << endl;
//				} else {
//					attacker_charge += 1;
//				}
//			}
//		}

		/*
		 * Task 4: Update Player's HEALTH and Computer's HEALTH
		 * - Update player_damage and computer_damage; cap DAMAGE received to current HEALTH (no overkill).
		 * - Announce player_damage (only if non-zero) and update player_health.
		 * - Announce computer_damage (only if non-zero) and update computer_health.
		 */

		// Player's HEALTH.
		if (player_damage != 0) {
			if (player_damage > player_health) {
				player_damage = player_health;
			}
			player_health -= player_damage;
			cout << "Player receives " << player_damage << " DAMAGE!" << endl;
		}

		// Computer's HEALTH.
		if (computer_damage != 0) {
			if (computer_damage > computer_health) {
				computer_damage = computer_health;
			}
			computer_health -= computer_damage;
			cout << "Computer receives " << computer_damage << " DAMAGE!" << endl;
		}

//		// Probably not a code reduction, and seems to be worse readability.
//		for (int i = 0; i < 2; i += 1) {
//			int& receiver_damage = ((i == 0) ? player_damage : computer_damage);
//			int& receiver_health = ((i == 0) ? player_health : computer_health);
//			string receiver_string = ((i == 0) ? "Player" : "Computer");
//
//			if (receiver_damage != 0) {
//				if (receiver_damage > receiver_health) {
//					receiver_damage = receiver_health;
//				}
//				receiver_health -= receiver_damage;
//				cout << receiver_string << " receives " << receiver_damage << " DAMAGE!" << endl;
//			}
//		}

		/*
		 * Task 5: Check for winner.
		 * - Set winner to 1 if the Player wins, 2 if the Computer wins, and 3 for a tie.
		 * - One wins if the opponent's HEALTH reaches 0.
		 * - A tie occurs if both HEALTHs simultaneously reach 0.
		 */

		// Checking Winner.
		if (player_health == 0 && computer_health == 0) {
			winner = 3;
		} else if (player_health == 0) {
			winner = 2;
	    } else if (computer_health == 0) {
			winner = 1;
	    } /* else {
	    	winner = 0;
	    } */
	}

	/*
	 * Task 6: Display Ending Message.
	 * - Output appropriate ending message according to winner.
	 */

	// Ending Message.
	switch (winner) {
	case 1:
		cout << "CONGRATULATIONS! Player wins!" << endl;
		break;

	case 2:
		cout << "GAME OVER! Computer wins!" << endl;
		break;

	case 3:
		cout << "SURPRISE! It's a tie!" << endl;
		break;
	}

	// Preventing Immediate Console Exit.
	cout << '\n';
	cout << "Press [ENTER] to exit...";
	cin.ignore(); // Clear the newline character from the input buffer.
	cin.get(); // Wait for a single instance of cin input, but not do anything with it.
	cout << '\n';

	return 0;
}
