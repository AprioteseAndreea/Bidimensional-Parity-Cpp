#include <iostream>
#include <vector>
using namespace std;

vector<int> readMesage() {
	cout << "Enter the message: ";

	vector<int> message;
	string stringMessage;

	cin >> stringMessage;
	for (size_t i = 0; i < stringMessage.size(); i++) {
		char substring = stringMessage.at(i);
		
		
		message.push_back(int(substring)-'0');
	}
	return message;

}
bool verifyDimension(vector<int>& message) {
	if (message.size() % 7 == 0) return true;
	return false;

}
bool verifyBytes(vector<int>& message) {
	for (int i : message) {
		if ((i != 1) && (i != 0)) return false;
	}
	return true;
}
void constructMessage(vector<int>& message) {

	const int lines = message.size()/7 + 1;
	const int column = 8;

	int** matrix = new int* [lines];
	
	for (int i = 0; i < lines; ++i)
	{
		matrix[i] = new int[column];
	}
	
	int contor = 0;
	for (int i = 0; i < lines-1; ++i) {
		for (int j = 0; j < column-1; ++j) {

			matrix[i][j] = message[contor];
			contor++;
		
			
		}
	}
	cout << "Initial matrix: " << endl;
	for (int i = 0; i < lines - 1; ++i) {
		for (int j = 0; j < column - 1; ++j) {
			
			cout << matrix[i][j] << " ";
			
		}
		cout << endl;
	}
	for (int i = 0; i < lines - 1; ++i) {
		int count = 0;
		for (int j = 0; j < column ; ++j) {
			if (matrix[i][j] == 1) count++;
			if (j == column - 1) {
				if (count % 2 == 0) {
					matrix[i][column - 1] = 0;
				}
				else  matrix[i][column - 1] = 1;
			}
		}
		cout << endl;
	}

	for (int k = 0; k< column; k++) {
		int count = 0;
		for (int p = 0; p < lines-1 ; p++) {
			if (matrix[p][k] == 1) count++;
			if (p == (lines - 2)) {
				if (count % 2 == 0) matrix[lines - 1][k] = 0;
				else matrix[lines - 1][k] = 1;
			}
		}
	}
	for (int i = 0; i < lines ; i++) {
		for (int j = 0; j < column ; j++) {
			cout << matrix[i][j] << " ";

		}
		cout << endl;
	}
	cout << endl;
	cout << "Sended message is: " << endl;
	for (int i = 0; i < lines; i++) {
		for (int j = 0; j < column; j++) {
			cout << matrix[i][j] << " ";

		}
	}

	for (int i = 0; i < lines; ++i)
		delete[] matrix[i];
	delete[] matrix;
	
}


int main() {
	vector<int> message;
	message=readMesage();
	if (verifyDimension(message) && verifyBytes(message))
	constructMessage(message);
	return 0;
}
