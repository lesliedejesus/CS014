#include <iostream>
#include <string>
using namespace std;


class playlistNode { 
public:
	playlistNode() {
		uniqueID = "none";
		songName = "none";
		artistName = "none";
		songLength = 0;
		nextNodePtr = 0;
	}
	//Parameterized constructor 
	playlistNode(string id, string name, string artist, int sec) {
		uniqueID = id;
		songName = name;
		artistName = artist;
		songLength = sec;
		nextNodePtr = 0;
	}
	void InsertAfter(playlistNode* ptr);
	void SetNext(playlistNode* ptr);
	string GetID();
	string GetSongName();
	string GetArtistName();
	int GetSongLength();
	playlistNode* GetNext();
	void PrintPlaylistNode();
private:
	string uniqueID;
	string songName;
	string artistName;
	int songLength;
	playlistNode* nextNodePtr;
	//head = new node(null, null); //dummy head
};

class Playlist {
private:
	playlistNode* head;
	playlistNode* tail;
public:
	Playlist();
	void outputFullPlaylist();
	int totalTime();
	void specificArtist(string);
	void changePosition(int, int);
	void removeSong(string);
	void addSong(string,string, string, int);
};
#pragma once
