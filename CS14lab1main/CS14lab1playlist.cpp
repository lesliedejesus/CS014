#include <iostream>
#include <string>
#include "CS14lab1header.h"
#include "Playlist.h"

using namespace std;

void playlistNode::InsertAfter(playlistNode* ptr) {
	this->SetNext(ptr->GetNext()); //sets the pointers
	ptr->SetNext(this);
}
void playlistNode::SetNext(playlistNode* ptr) {
	nextNodePtr = ptr;
}
string playlistNode::GetID() {
	return uniqueID;
}
string playlistNode::GetSongName() {
	return songName;
}
string playlistNode::GetArtistName() {
	return artistName;
}
int playlistNode::GetSongLength() {
	return songLength;
}
playlistNode* playlistNode::GetNext() {
	return nextNodePtr;
}
void playlistNode::PrintPlaylistNode() {
	cout << "Unique ID: " << uniqueID << endl;
	cout << "Song Name: " << songName << endl;
	cout << "Artist Name: " << artistName << endl;
	cout << "Song Length (in seconds): " << songLength << endl;
}

Playlist::Playlist() {
	head = 0;
	tail = 0;
}
void Playlist::addSong(string id, string name, string artist, int length) {
	playlistNode* newNode = new playlistNode(id, name, artist, length);
	if (head == 0) {
		head = tail;
		tail = newNode;
	}
	else {
		newNode->InsertAfter(tail);
		tail = newNode;
	}
	return;
}
void Playlist::removeSong(string id) {
	if (head == NULL) { //playlist empty
		return;
	}

	playlistNode* currentNode = head;
	playlistNode* prevNode = NULL;
	while (currentNode != NULL) {
		if (currentNode->GetID() == id) {
			break;
		}
		prevNode = currentNode;
		currentNode = currentNode->GetNext();
	}
	if (prevNode != NULL) {
			prevNode->SetNext(currentNode->GetNext());
	}
	else {
		head = currentNode->GetNext();
	}
	if (tail == currentNode) {
		tail = prevNode;
	}
	cout << "\"" << currentNode->GetSongName() << "\" removed" << endl;
	delete currentNode;
}
void Playlist::changePosition(int orig, int newPos) {
	//CHANGE POSITION AND FIND SONG
  /*Moving the head node (1 pt)
	Moving the tail node (1 pt)
	Moving a node to the head (1 pt)
	Moving a node to the tail (1 pt)
	Moving a node up the list (1 pt)
	Moving a node down the list (1 pt)
	*/
	playlistNode* previous = NULL;
	playlistNode* current = head;

	if (head == NULL || head == tail) {
		return;
	}
	//find orig node
	for (int i = 1; current != NULL && i < orig; i++) {
		previous = current;
		current = current->GetNext();
	}
	if (current != NULL) {
		string currentSong = current->GetSongName();
		if (previous == NULL) {
			head = current->GetNext();
		}
		else {
			previous->SetNext(current->GetNext());
		}

		if (current == tail) {
			tail = previous;
		}
		playlistNode* insCurrent = current;
		previous = NULL;
		current = head;

		for (int i = 1; current != NULL && i < newPos; i++) {
			previous = current;
			current = current->GetNext();
		}
		//insert here
		if (previous == NULL) {
			insCurrent->SetNext(head);
			head = insCurrent;
		}
		else {
			insCurrent->InsertAfter(previous);
		}
		if (current == NULL) {
			tail = insCurrent;
		}
		cout << '\"' << currentSong << "\" moved to position " << newPos << endl;
	}
	else {
		cout << "Position invalid" << endl;
	}
}
void Playlist::specificArtist(string artist) {
	playlistNode* current = head;
	int i = 1;
	while (current != NULL) {
		if (current->GetArtistName() == artist) {
			cout << endl << i << "." << endl;
			current->PrintPlaylistNode();
		}
		current = current->GetNext();
		i++;
	}
}
int Playlist::totalTime() {
	int total = 0;
	playlistNode* current = head;

	while (current != NULL) {
		total += current->GetSongLength();
		current = current->GetNext();
	}
	return total;
}
//finish this function
void Playlist::outputFullPlaylist() {
	playlistNode* current = head;
	int i = 1;
	while (current != NULL) {
		cout << endl << i++ << "." << endl;
		current->PrintPlaylistNode();
		current = current->GetNext();
	}
}


