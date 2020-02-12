// CS14lab1main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
//#include "CS14lab1header.h"
#include "Playlist.h"
using namespace std;

void PrintMenu(string user) {
	cout << user << " PLAYLIST MENU" << endl;
	cout << "a - Add song" << endl
		<< "b - Remove song" << endl
		<< "c - Change the position of song" << endl
		<< "s - Output songs by specific artist" << endl
		<< "t - Output total time of playlist (in seconds)" << endl
		<< "o - Output full playlist" << endl
		<< "q - Quit" << endl << endl
		<< "Choose an option:";
}

int main() {
	Playlist list;
	string userInput;
	//array for menu options
	char menuOptions[] = {'a', 'b', 'c', 's', 't', 'o', 'q'};
	bool inputValid = false;
	char menuChoice;
	cout << "Enter playlist's title:" << endl;
	cin >> userInput;

	while (!inputValid) {
		PrintMenu(userInput);
		cin >> menuChoice;
		for (int i = 0; i < 7; ++i) {
			if (menuChoice == menuOptions[i]) {
				inputValid = true;
			}
		}
	}

	if (menuChoice == 'a') {
		string id1, name1, artist1;
		int length1;

		cout << "ADD SONG" << endl;
		cout << "Enter song's unique ID:" << endl;
		cin >> id1;
		cout << "Enter song's name:" << endl;
		cin >> name1;
		cout << "Enter artist's name:" << endl;
		cin >> artist1;
		cout << "Enter song's length (in seconds):" << endl;
		cin >> length1;
		list.addSong(id1, name1, artist1, length1);

	}
	if (menuChoice == 'b') {
		string id2;
		cout << "REMOVE SONG" << endl
			<< "Enter song's unique ID:" << endl;
		cin >> id2;
		list.removeSong(id2);
	}
	if (menuChoice == 'c') {
		int old, newPos;
		cout << "CHANGE POSITION OF SONG" << endl
			<< "Enter song's current position:" << endl;
		cin >> old;
		cout << "Enter new position for song:" << endl;
		cin >> newPos;
		list.changePosition(old, newPos);
	}
	if (menuChoice == 'o') {
		list.outputFullPlaylist();
	}
	if (menuChoice == 's') {
		string artist3;
		cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl
			<< "Enter artist's name:" << endl;
		cin >> artist3;
		list.specificArtist(artist3);
	}
	if (menuChoice == 't') {
		cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl
			 << "Total time: " << list.totalTime() << " seconds";
	
	}





	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
