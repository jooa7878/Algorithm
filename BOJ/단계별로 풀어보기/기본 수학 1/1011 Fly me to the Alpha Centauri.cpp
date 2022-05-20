#include <iostream>

using namespace std;

int main() {
	unsigned int T, X, Y;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> X >> Y;
		int move = 1;
		unsigned int result = 1;
		unsigned int pos = X+1;
		while (true) {
			if (Y - pos >= ((move+1) * (move + 2)) / 2) {
				move++;
				pos += move;
			}
			else if (Y - pos >= (move * (move + 1)) / 2) {
				pos += move;
			}
			else {	
				move--;		
				if (move == 0) {
					break;
				}
				pos += move;
			}
			result++;
		}
		cout << result << endl;
	}

}
