#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

int math_mod(int num, int M) {
	if(num >= M) num -= M;
	else if(num < 0) num += M;
	return num;
}

struct State {
	int level;
	int order;
	
	bool equals(const State &s) {
		return (level == s.level && order == s.order);
	}
};

class Node {
	protected:
	State state;
	string key;
	string title;
	vector<pair<int,Node*>> children;
	
	public:
	
	bool execOnly;
	
	Node(string key, string title, bool execOnly) {
		this->state = {0, 0};
		this->key = key;
		this->title = title;
		
		this->execOnly = execOnly;
	}
	
	Node(string key, string title) {
		this->state = {0, 0};
		this->key = key;
		this->title = title;
		
		this->execOnly = false;
	}
	
	void push_child(int gp, Node* child) {
		child->state = {state.level + 1, (int)children.size()};
		children.push_back({gp, child});
	}
	void push_child(Node* child) {
		push_child(0, child);
	}
	
	virtual void exec() {
		
	}
	
	virtual void display_title() {
		cout << endl;
		cout << "\t===========================================================" << endl;
		cout << "\t" << title << ":\t\t" << "(" << state.level << " | " << state.order << ")" << endl;
		cout << "\t===========================================================" << endl;
		cout << endl;
	}
	
	virtual string choice_prompt() {
		cout << endl;
		cout << "\tEnter your choice : ";
		string choice; cin >> choice;
		return choice;
	}
	
	virtual void display_children() {
		int n = children.size();
		int group = 0;
		for(int i=0; i<n; i++) {
			int gp = children[i].first;
			Node* child = children[i].second;
			
			if(gp > group) {
				cout << endl;
				group = gp;
			}
			cout << "\t" << child->key << "\t:\t" << child->title << endl;
		}
	}
	
	static State driver(Node* node) {
		node->exec();
		if(node->execOnly) return {-node->state.level, 0};
		
		THIS_MENU:
		
		node->display_title();
		node->display_children();
		
		CHOICE_PROMPT:
		
		string key = node->choice_prompt();
		
		if(key == "cls") {
			system("cls");
			goto THIS_MENU;
		}
		else if(key == "prev") {
			return {-1, 0};
		}
		else if(key == "root") {
			return {-node->state.level, 0};
		}
		else if(key == "[") {
			return {0, -1};
		}
		else if(key == "]") {
			return {0, +1};
		}
		else if(key == "done") {
			return {-1 - node->state.level, 0};
		}
		
		int n = node->children.size();
		int index = -1;
		State childState = {0, 0};
		for(int i=0; i<n; i++) {
			Node* child = node->children[i].second;
			if(child->key == key) {
				index = i;
				childState = driver(child);
				break;
			}
		}
		
		if(index == -1) {
			goto CHOICE_PROMPT;
		}
		
		HANDLE_CHILD_STATE:
		
		// cout << "CS--" << childState.level << " " << childState.order << "---" << endl;
		if(childState.equals({-1, 0})) {
			goto THIS_MENU;
		}
		else if(childState.order == 0) {
			return {childState.level + 1, 0};
		}
		else if(childState.level == 0) {
			int delta = childState.order;
			index = math_mod(index + delta, n);
			childState = driver(node->children[index].second);
			goto HANDLE_CHILD_STATE;
		}
		
		return {-node->state.level, 0};
	}
	
	static void adjustLevel(Node* node, int nLevel) {
		node->state.level = nLevel;
		for(auto c : node->children) {
			Node* child = c.second;
			adjustLevel(child, 1 + node->state.level);
		}
	}
	
	static void rootAt(Node* root) {
		adjustLevel(root, 0);
	}
	
	static void main_loop(Node* root) {
		rootAt(root);
		
		do {
			cout << endl << "\t\t\t................" << endl;
			State childState = Node::driver(root);
			if(!childState.level == 0) break;
		}
		while(true);
	}
};

/*
int main() {
	
	Node* A = new Node("a", "A-menu");
	Node* B = new Node("b", "B-menu");
	Node* C = new Node("c", "C-menu");
	Node* D = new Node("d", "D-menu");
	Node* E = new Node("e", "E-menu");
	Node* F = new Node("f", "F-menu");
	Node* G = new Node("g", "G-menu");
	Node* H = new Node("h", "H-menu");
	
	
	
	B->push_child(H);
	A->push_child(C);
	
	C->push_child(E);
	A->push_child(D);
	
	E->push_child(G);
	C->push_child(F);
	
	Node::main_loop(A);
	return 0;
}
*/