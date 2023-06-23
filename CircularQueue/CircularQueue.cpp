#include <iostream>
using namespace std;

class Queues {
	int FRONT, REAR, max = 5;
	int queue_array[5];

public:
	Queues() {
		FRONT = -1;
		REAR = -1;
	}

	void insert() {
		int num;
		cout << "Enter a number: ";
		cin >> num;
		cout << endl;

		//Cek apakah antrian penuh
		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
			cout << "\nQueue Overflow\n";
			return;
		}

		//Cek apakah queue kosong
		if (FRONT == -1) {
			FRONT = 0;
			REAR = 0;
		}
		else {
			//jika REAR berada di posisi terakhir array, kembali ke awal array
			if (REAR == max - 1)
				REAR = 0;
			else
				REAR = REAR + 1;
		}
		queue_array[REAR] = num;
	}

	void remove() {
		//Cek Apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queue is Empty\n";
			return;
		}
		cout << "\nThe element deleted from the queue is: " << queue_array[FRONT] << "\n";

		//Cek jika antrian hanya memiliki satu elemen
		if (FRONT == REAR) {
			FRONT = -1;
			REAR = -1;
		}
		else {
			//jika elemen yang dihapus berada di posisi terakhir array, kembali ke awal array
			if (FRONT == max - 1)
				FRONT = 0;
			else
				FRONT = FRONT + 1;
		}
	}

	void display() {
		int FRONT_position = FRONT;
		int REAR_position = REAR;

		//cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queue is Empty\n";
			return;
		}

		cout << "\nElements in the queue are...\n";

		//jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
		if (FRONT_position <= REAR_position) {
			while (FRONT_position <= REAR_position) {
				cout << queue_array[FRONT_position] << "	";
				FRONT_position++;
			}
			cout << endl;
		}
		else {
			//jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array
			while (FRONT_position <= max - 1) {
				cout << queue_array[FRONT_position] << "	";
				FRONT_position++;
			}

			FRONT_position = 0;

			//Iterasi dari awal array hingga REAR
			while (FRONT_position <= REAR_position) {
				cout << queue_array[FRONT_position] << "	";
				FRONT_position++;
			}
			cout << endl;
		}
	}
};

int main() {
	Queues Q;
	char ch;

	while (true)
	{
		try {
			cout << "Menu" << endl;
			cout << "1. Implement Insert Operation" << endl;
			cout << "2. Implement Delete Operation" << endl;
			cout << "3. Dislpay Values" << endl;
			cout << "4. Exit" << endl;
			cout << "Enter Your Choice (1-4): ";
			cin >> ch;
			cout << endl;

			switch (ch) {
			case'1': {
				Q.insert();
				break;
			}
			case'2': {
				Q.remove();
				break;
			}
			case'3': {
				Q.display();
				break;
			}
			case'4': {
				return 0;
			}
			default: {
				cout << "Invalid Option!!" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << "Check for the values entered." << endl;
		}
	}
	return 0;
}