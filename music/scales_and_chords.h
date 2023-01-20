#include<bits/stdc++.h>
using namespace std;

namespace music {
	
	const vector<bool> blackNotes = {
		false, true,
		false, true,
		false,
		false, true,
		false, true,
		false, true,
		false
	};
	
	const vector<string> sharpNames = {
		"C", "C#",
		"D", "D#",
		"E",
		"F", "F#",
		"G", "G#",
		"A", "A#",
		"B"
	};
	
	const vector<string> flatNames = {
		      "C",
		"Db", "D",
		"Eb", "E",
		      "F",
		"Gb", "G",
		"Ab", "A",
		"Bb", "B"
	};
	
	map<string,int> name_index;
	void init_name_index() {
		for(int i=0; i<12; i++) {
			name_index[sharpNames[i]] = i;
			name_index[flatNames[i]] = i;
		}
	};
	
	class Note {
		private:
		
		int index;
		int order;
		
		public:
		
		Note(int index);
		Note(int index, int order);
		Note(string name);
		Note(string name, int order);
		
		int getIndex();
		int getOrder();
		string getName(bool flat);
		bool isBlack();
		
		bool equals(Note* note, bool exact);
		Note* getSemi(int step);
		Note* next();
		Note* prev();
		int delta(Note* note);
	};
	
	class Scale {
		private:
		
		Note* root;
		int numNotes;
		vector<int> steps;
		vector<Note*> notes;
		
		public:
		
		Scale(Note* root, vector<int> steps);
		
		Note* getRoot();
		int getNumNotes();
		vector<int> getSteps();
		vector<Note*> getNotes();
		
		static vector<int> getStdSteps(string);
	};
	
	
	void init_music_library() {
		init_name_index();
	};
}