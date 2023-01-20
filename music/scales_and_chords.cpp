#include<bits/stdc++.h>
#include "scales_and_chords.h"

using namespace std;

namespace music {

	// ===================================================================================
	// Implementation of methods of Class: Note
	// ===================================================================================
	
	Note::Note(int index) {
		this->index = index;
		this->order = 0;
	};
	
	Note::Note(int index, int order) {
		this->index = index;
		this->order = order;
	};
	
	Note::Note(string name) {
		this->index = name_index[name];
		this->order = 0;
	};
	
	Note::Note(string name, int order) {
		this->index = name_index[name];
		this->order = order;
	};
	
	int Note::getIndex() {
		return this->index;
	};
	
	int Note::getOrder() {
		return this->order;
	};
	
	string Note::getName(bool flat) {
		return ((!flat) ? sharpNames[this->index] : flatNames[this->index]);
	};
	
	bool Note::isBlack() {
		return blackNotes[this->index];
	}
	
	bool Note::equals(Note* note, bool exact) {
		bool bid = (this->index == note->index);
		bool bod = (this->order == note->order);
		
		return (bid && (!exact || bod));
	};
	
	Note* Note::getSemi(int step) {
		
		int sign = (step > 0) ? 1 : -1;
		if(sign < 0) step = -step;
		
		int quo = step / 12;
		int rem = step % 12;
		
		int index = this->index;
		int order = this->order;
		
		index += (sign * rem);
		if((index >= 12) || (index < 0)) {
			index -= (sign * 12);
			order += sign;
		}
		order += (sign * quo);
		
		return new Note(index, order);
	};
	
	Note* Note::next() {
		return this->getSemi(+1);
	};
	
	Note* Note::prev() {
		return this->getSemi(-1);
	};
	
	int Note::delta(Note* note) {
		int x1 = this->index + (12 * this->order);
		int x2 = note->index + (12 * note->order);
		
		return (x2 - x1);
	};

	
	// ===================================================================================
	// Implementation of methods of Class: Scale
	// ===================================================================================
	
	Scale::Scale(Note* root, vector<int> steps) {
		this->root = root;
		this->numNotes = (int)steps.size();
		this->steps = steps;
		
		this->notes = vector<Note*>(numNotes, root);
		for(int i=0; i<numNotes-1; i++) {
			notes[i+1] = notes[i]->getSemi(steps[i]);
		}
	};
	
	Note* Scale::getRoot() {
		return this->root;
	};
	
	int Scale::getNumNotes() {
		return this->numNotes;
	};
	
	vector<int> Scale::getSteps() {
		return this->steps;
	};
	
	vector<Note*> Scale::getNotes() {
		return this->notes;
	};
	

	vector<int> Scale::getStdSteps(string type) {
		vector<int> steps;
		
		if(type == "MAJOR" || type == "IONIAN") {
			steps = {2, 2, 1, 2, 2, 2, 1};
		}
		else if(type == "NATURAL_MINOR" || type == "MINOR" || type == "AEOLIAN") {
			steps = {2, 1, 2, 2, 1, 2, 2};
		}
		else if(type == "HARMONIC_MINOR") {
			steps = {2, 1, 2, 2, 1, 3, 1};
		}
		else if(type == "MELODIC_MINOR") {
			steps = {2, 1, 2, 2, 2, 2, 1};
		}
		
		
		else if(type == "DORIAN") {
			steps = {2, 1, 2, 2, 2, 1, 2};
		}
		else if(type == "PHRYGIAN") {
			steps = {1, 2, 2, 2, 1, 2, 2};
		}
		else if(type == "LYDIAN") {
			steps = {2, 2, 2, 1, 2, 2, 1};
		}
		else if(type == "MIXOLYDIAN") {
			steps = {2, 2, 1, 2, 2, 1, 2};
		}
		else if(type == "LOCRIAN") {
			steps = {1, 2, 2, 1, 2, 2, 2};
		}
		
		else if(type == "PENTATONIC_MAJOR") {
			steps = {2, 2, 3, 2, 3};
		}
		else if(type == "PENTATONIC_MINOR") {
			steps = {3, 2, 2, 3, 2};
		}
		
		else if(type == "WHOLE_TONE") {
			steps = vector<int>(6, 2);
		}
		
		else if(type == "CHROMATIC") {
			steps = vector<int>(12, 1);
		}
		
		else {
			// By default : MAJOR
			steps = {2, 2, 1, 2, 2, 2, 1};
		}
		return steps;
	};


class Piano {
	
	static int mask_len;
	static vector<vector<int>> mask;
	
	
	Note *start, *end;
	int numKeys;
	vector<vector<Note*>> grid;
	int grid_len;
	
	public:
	
	Piano(Note* start, Note* end) {
		this->start = start;
		this->end = end;
		this->numKeys = 1 + start->delta(end);
		
		int mid = 0;
		while(mask[2][mid] != start->getIndex()) mid++;
		
		this->grid = vector<vector<Note*>>(2, vector<Note*>(0));
		this->grid_len = 0;
		
		Note* curr = start;
		while(!(curr->equals(end->next(), true))) {
			
			grid[0].push_back(NULL);
			grid[1].push_back(NULL);
			grid_len++;
			
			grid[0][grid_len - 1] = mask[0][mid] ? curr : NULL;
			grid[1][grid_len - 1] = mask[1][mid] ? curr : NULL;
			
			if(mask[2][mid] != -1) curr = curr->next();
			mid = (mid + 1) % mask_len;
		}
	};
	
	string toString(bool flat) {
		string ustr = "", dstr = "";
		
		for(int i=0; i<grid_len; i++) {
			ustr += ((grid[0][i] == NULL) ? "  " : grid[0][i]->getName(flat));
			dstr += ((grid[1][i] == NULL) ? "  " : (grid[1][i]->getName(flat)) + " ");
		}
		
		string disp = ustr + "\n" + dstr;
		return disp;
	};
	
	string toString1(bool flat, int zoomX, int zoomY) {
		
		/*
		  _________________________________________________________
		  |     |   |   |   |     |     |   |   |   |   |   |     |
		  |     | c#|   | D#|     |     | F#|   | G#|   | A#|     |
		  |     |___|   |___|     |     |___|   |___|   |___|     |
		  |       |       |       |       |       |       |       |
		  |   C   |   D   |   E   |   F   |   G   |   A   |   B   |
		  |_______|_______|_______|_______|_______|_______|_______|
		
		*/
		
		const int B = 3;
		const int H = 3;
		
		int b = B + (2 * zoomX);
		int bd = b;
		int bs = 1 + (b-1)/2;
		int w = 2 * (1 + (b-1)/2) + bd;
		
		int h = H + zoomY;
		
		string str_b = "";
		string str_bk = "";
		string str_b_ = "";
		string str_w = "";
		string str_wk = "";
		string str_w_ = "";
		
		auto rep = [=](string s, int t) {
			string rs = "";
			for(int i=1; i<=t; i++) rs += s;
			return rs;
		};
		
		auto getSamples = [&](int flagB, int flagW, string key) {
			if(flagB == 0 && flagW == 0) {
				str_b = rep(" ", bs) + "|" + rep(" ", bs);
				str_bk = rep(" ", bs) + "|" + rep(" ", bs);
				str_b_ = rep(" ", bs) + "|" + rep(" ", bs);
				str_w = rep(" ", bs) + "|" + rep(" ", bs);
				str_wk = rep(" ", bs) + "|" + rep(" ", bs);
				str_w_ = rep("_", bs) + "|" + rep("_", bs);
			}
			else if(flagB == 1 && flagW == 0) {
				str_b = "|" + rep(" ", b) + "|";
				str_bk = "|" + rep(" ", (b-2)/2) + key + rep(" ", 1 + (b-2)/2) + "|";
				str_b_ = "|" + rep("_", b) + "|";
				str_w = rep(" ", bs) + "|" + rep(" ", bs);
				str_wk = rep(" ", bs) + "|" + rep(" ", bs);
				str_w_ = rep("_", bs) + "|" + rep("_", bs);
			}
			else if(flagB == 0 && flagW == 1) {
				str_b = rep(" ", bd);
				str_bk = rep(" ", bd);
				str_b_ = rep(" ", bd);
				str_w = rep(" ", bd);
				str_wk = rep(" ", (bd-1)/2) + key + rep(" ", (bd-1)/2);
				str_w_ = rep("_", bd);
			}
		};
		
		vector<string> board(1 + 2*h, "");
		// 0		: bar,
		// [1,h]	: black
		// [h+1, 2h]: white
		
		
		
		for(int i=0; i<grid_len; i++) {
			
			bool fB = (grid[0][i] != NULL);
			bool fW = (grid[1][i] != NULL);
			
			getSamples(
				fB,
				fW,
				fB ? grid[0][i]->getName(flat) : (fW ? grid[1][i]->getName(flat) : "")
			);
			
			for(int y=1; y<=(h-2); y++) board[y] += str_b;
			board[h-1] += str_bk;
			board[h] += str_b_;
			
			for(int y=h+1; y<=(2*h-2); y++) board[y] += str_w;
			board[2*h-1] += str_wk;
			board[2*h] += str_w_;
		}
		
		for(char ch : board[1]) board[0].push_back('_');
		
		string ans = "\n";
		for(string sx : board) ans += (sx + "\n");
		
		return ans;
	}
};

int Piano::mask_len = 14;

vector<vector<int>> Piano::mask = {
	{0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
	{1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 2, 3, 4,-1, 5, 6, 7, 8, 9,10,11,-1}
};



int main()
{
	init_name_index();
	
	string root; cin >> root;
	string name; cin >> name;
	Scale* C = new Scale(new Note(root), Scale::getStdSteps(name));
	
	for(Note* note : C->getNotes()) {
		cout << note->getName(true) << " ";
	}
	cout << endl;
	for(Note* note : C->getNotes()) {
		cout << note->getName(false) << " ";
	}
	cout << endl;
	
	
	Piano *p = new Piano(new Note("D", 0), new Note("F#", 1));
	cout << endl << p->toString1(false, 1, 3) << endl;
	
	return 0;
}

}

int main() {
	music::main();
	return 0;
}