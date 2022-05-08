#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int item_a_value = 6;
const int item_b_value = 4;

int main()
{
	int item_a_count = 3;
	int item_b_count = 3;

	int coin_5_count = 3;
	int coin_2_count = 3;
	int coin_1_count = 3;

	int balance = 0;

	while (true) {
		int action;

		while (true) {
			cout << "The balance is $" << balance << endl;
			cout << "Please choose an action:" << endl;
			cout << "1. Insert coin" << endl;
			cout << "2. Purchase" << endl;
			cout << "3. Return coins" << endl;
			cout << "4. Leave" << endl;
			cout << "Please enter 1-4: ";

			if (!(cin >> action)) {
				cin.clear();
				cin.ignore(80, '\n');
				cout << "Invalid choice" << endl;
			}
			else if (action < 1 || action > 4) {
				cout << "Invalid choice" << endl;
			}
			else
				break;
		}
		
		if (action == 1) {
			// Insert coin
			while (true) {
				cout << "Please insert a coin: $";

				if (!(cin >> action)) {
					cin.clear();
					cin.ignore(80, '\n');
					cout << "Only $5, $2 and $1 coins are accepted" << endl;
				}
				else if (action != 5 && action != 2 && action != 1) {
					cout << "Only $5, $2 and $1 coins are accepted" << endl;
				}
				else
					break;
			}

			switch (action) {
				case 5:
				balance += 5;
				coin_5_count++;
				break;
				case 2:
				balance += 2;
				coin_2_count++;
				break;
				case 1:
				balance += 1;
				coin_1_count++;
				break;
				default:
				break;
			}
		}
		else if (action == 2) {
			// Purchase
			while (true) {
				cout << "Please select an item:" << endl;

				cout << "1. Item A - ";
				if (item_a_count > 0)
					cout << "$" << item_a_value;
				else
					cout << "SOLD OUT";
				cout << endl;

				cout << "2. Item B - ";
				if (item_b_count > 0)
					cout << "$" << item_b_value;
				else
					cout << "SOLD OUT";
				cout << endl;

				cout << "3. Go back" << endl;

				cout << "Please enter 1-3: ";

				if (!(cin >> action)) {
					cin.clear();
					cin.ignore(80, '\n');
					cout << "Invalid choice" << endl;
				}
				else if (action < 1 || action > 3) {
					cout << "Invalid choice" << endl;
				}
				else {
					if (action == 1) {
						if (item_a_count == 0) {
							cout << "Item A has been sold out" << endl;
						}
						else if (balance < item_a_value) {
							cout << "Insufficient balance" << endl;
						}
						else
							break;
					}
					else if (action == 2) {
						if (item_b_count == 0) {
							cout << "Item B has been sold out" << endl;
						}
						else if (balance < item_b_value) {
							cout << "Insufficient balance" << endl;
						}
						else
							break;
					}
					else if (action == 3) {
						break;
					}
				}
			}

			switch (action) {
				case 1:
				balance -= item_a_value;
				item_a_count--;
				cout << "Purchased item A" << endl;
				break;
				case 2:
				balance -= item_b_value;
				item_b_count--;
				cout << "Purchased item B" << endl;
				break;
			}
		}
		else if (action == 3) {
			// Coin return
			while (balance > 0) {
				if (balance >= 5 && coin_5_count > 0) {
					balance -= 5;
					coin_5_count -= 1;
					cout << "Returned a $5 coin" << endl;
					continue;
				}

				if (balance >= 2 && coin_2_count > 0) {
					balance -= 2;
					coin_2_count -= 1;
					cout << "Returned a $2 coin" << endl;
					continue;
				}

				if (balance >= 1 && coin_1_count > 0) {
					balance -= 1;
					coin_1_count -= 1;
					cout << "Returned a $1 coin" << endl;
					continue;
				}

				cout << "Oops... Not enough coins to return..." << endl;
				break;
			}
		}
		else if (action == 4) {
			// Leave
			cout << "Bye" << endl;
			break;
		}
	}

	return 0;
}


