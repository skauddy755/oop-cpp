#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

struct State {
	int level;
	int order;
	
	bool equals(const State &s) {
		return (level == s.level && order == s.order);
	}
};

class Node {
	public:
	
	bool active, leaf;
	string key;
	string title;
	string cmd;
	State (*childMenu)(State);
	
	Node(bool active, bool leaf, string key, string title, string cmd, State (*childMenu)(State)) {
		this->active = active;
		this->leaf = leaf;
		this->key = key;
		this->title = title;
		this->cmd = cmd;
		this->childMenu = childMenu;
	};
	
	State call_child_menu(State childState) {
		return childMenu(childState);
	};
	
	void exec(bool clear) {
		system(cmd.c_str());
		if(clear) {
			system("cls");
		}
	};
	
	void exec(bool clear, string history) {
		system(cmd.c_str());
		if(clear) {
			system("cls");
		}
		cout << history << endl;
	};
};


vector<Node*> data_mainMenu;
vector<Node*> data_folderMenu;

// ======================================================================================
// MENU HANDLING:
// ======================================================================================

// -----------------------------------------------
// MENU HANDLING - Main Menu:
// -----------------------------------------------
State mainMenu(State state) {
	bool cameFromParent = true;
	cout << "\t ----------------------------------------------------" << endl;
	cout << "\t MAIN - MENU" << endl;
	cout << "\t ----------------------------------------------------" << endl;
	
	for(Node* node : data_mainMenu) {
		if(!node->active) cout << endl;
		
		cout << "(" << node->key << ")" << "\t:" << node->title << endl;
	}
	cout << endl << "Your Choice:\t";
	string choice; cin >> choice;
	
	if(choice == "cls") {
		return {0, -2};
	}
	if(choice == "[") {
		return {0, -1};
	}
	if(choice == "]") {
		return {0, 1};
	}
	if(choice == "prev") {
		return {-1, 0};
	}
	if(choice == "root") {
		return {-state.level, 0};
	}
	if(choice == "done") {
		return {-1-state.level, 0};
	}
	
	bool found = false;
	State st;
	
	int index = 0;
	for(Node* node: data_mainMenu) {
		if(!node->active) continue;
		
		if(node->key == choice) {
			st = node->childMenu({state.level + 1, index});
			break;
		}
		index++;
	}
	
	if(!found) {
		return {0, 0};
	}
	
	if(st.equals({0, -2})) {
		system("cls");
		data_mainMenu[index]->childMenu({state.level + 1, index});
	}
	return {0, 0};
}


// -----------------------------------------------
// MENU HANDLING - Folder Menu:
// -----------------------------------------------
State folderMenu(State state) {
	return {0, 3};
}


// ======================================================================================
// MENU DATA:
// ======================================================================================

// -----------------------------------------------
// DATA - Folder Menu:
// -----------------------------------------------
void init_data_mainMenu() {
	data_mainMenu = vector<Node*>{
		new Node(
			true, false,
			"f",
			"OPEN FOLDER",
			"",
			&folderMenu
		),
	};
}
	


// -----------------------------------------------
// DATA - Folder Menu:
// -----------------------------------------------
void init_data_folderMenu() {
	data_folderMenu = vector<Node*>{
		new Node(
			true, true,
			"0",
			"STRAY_CUTS",
			"explorer C:\\Users\\hp\\D-Shortcuts\\Desktop-Special-Folders\\STRAY_CUTS",
			NULL
		),
		new Node(
			true, true,
			"s",
			"SRIB INTERN",
			"explorer D:\\SRIB INTERN",
			NULL
		),
		new Node(
			true, true,
			"i",
			"ISM DOCS",
			"explorer C:\\Users\\hp\\MyDocs755\\ISM_Docs",
			NULL
		),
		new Node(
			true, true,
			"ac",
			"ACAD_SEM-8",
			"explorer C:\\Users\\hp\\MyDocs755\\ISM_Docs\\Sem_8_Winter\\Acad_Sem8",
			NULL
		),
		new Node(
			true, true,
			"pd",
			"PROOF DOCS",
			"explorer C:\\Users\\hp\\MyDocs755\\PROOF_DOCS",
			NULL
		),
		new Node(
			false, true,
			"",
			"",
			"",
			NULL
		),
		new Node(
			true, true,
			"cl",
			"CYBERLABS",
			"explorer D:\\CYBERLABS",
			NULL
		),
		new Node(
			true, true,
			"fi",
			"FFI",
			"explorer D:\\FFI",
			NULL
		),
		new Node(
			true, true,
			"fc",
			"FOCUS",
			"explorer D:\\FOCUS",
			NULL
		),
		new Node(
			false, true,
			"",
			"",
			"",
			NULL
		),
		new Node(
			true, true,
			"sp",
			"SPECIAL_PROJECTS",
			"explorer C:\\Users\\hp\\MyProgs755\\SPECIAL_PROJECTS",
			NULL
		),
		new Node(
			true, true,
			"sc",
			"STRAY_CODES",
			"explorer C:\\Users\\hp\\MyProgs755\\STRAY_CODES",
			NULL
		),
		new Node(
			true, true,
			"py",
			"PYTHON-DS-ML",
			"explorer C:\\Users\\hp\\MyProgs755\\PYTHON-DS-ML",
			NULL
		),
		new Node(
			true, true,
			"ps",
			"ProgStuffs",
			"explorer D:\\ProgStuffs",
			NULL
		),
		new Node(
			true, true,
			"cp",
			"COMPETITIVE PROGRAMMING",
			"explorer D:\\ProgStuffs\\COMPETITIVE_PROGRAMMING",
			NULL
		)
	};
}



int main() {
	
	cout << "Enter your hit: ";
}