#include<bits/stdc++.h>
#include "driver.cpp"

using namespace std;

class MenuNode : public Node {
	public:
	MenuNode(string key, string title) : Node(key, title) {
		
	}
};

class LeafNode : public Node {
	string cmd;
	
	public:
	LeafNode(string key, string title, string cmd) : Node(key, title, true) {
		this->cmd = cmd;
	}
	
	void exec() {
		system(cmd.c_str());
	}
	
	void driver() {
		exec();
	}
};

int main() {
	
	MenuNode* main = new MenuNode("main", "MAIN-MENU");
	
	MenuNode* f = new MenuNode("f", "OPEN FOLDER in EXPLORER");
	MenuNode* w = new MenuNode("w", "WEB");
	
	LeafNode* f0 = new LeafNode("0", "STRAY_CUTS", "explorer C:\\Users\\hp\\D-Shortcuts\\Desktop-Special-Folders\\STRAY_CUTS");
	LeafNode* f1 = new LeafNode("s", "SRIB INTERN", "explorer D:\\SRIB INTERN");
	LeafNode* f2 = new LeafNode("i", "ISM DOCS", "explorer C:\\Users\\hp\\MyDocs755\\ISM_Docs");
	LeafNode* f3 = new LeafNode("ac", "ACADS_SEM_8", "explorer C:\\Users\\hp\\MyDocs755\\ISM_Docs\\Sem_8_Winter\\Acad_Sem8");
	LeafNode* f33 = new LeafNode("fp", "FINAL-YEAR-PROJECT", "explorer C:\\Users\\hp\\MyDocs755\\ISM_Docs\\FINAL-YEAR-PROJECT");
	LeafNode* f4 = new LeafNode("pd", "PROOF DOCS", "explorer C:\\Users\\hp\\MyDocs755\\PROOF_DOCS");
	LeafNode* f5 = new LeafNode("cl", "CYBERLABS", "explorer D:\\CYBERLABS");
	LeafNode* f6 = new LeafNode("fi", "FFI", "explorer D:\\FFI");
	LeafNode* f7 = new LeafNode("fc", "FOCUS", "explorer D:\\FOCUS");
	LeafNode* f8 = new LeafNode("sp", "SPECIAL_PROJECTS", "explorer C:\\Users\\hp\\MyProgs755\\SPECIAL_PROJECTS");
	LeafNode* f9 = new LeafNode("sc", "STRAY_CODES", "explorer C:\\Users\\hp\\MyProgs755\\STRAY_CODES");
	LeafNode* f10 = new LeafNode("py", "PYTHON-DS-ML", "explorer C:\\Users\\hp\\MyProgs755\\PYTHON-DS-ML");
	LeafNode* f11 = new LeafNode("ps", "PrgStuffs", "explorer D:\\ProgStuffs");
	LeafNode* f12 = new LeafNode("ps", "PrgStuffs", "explorer D:\\ProgStuffs\\COMPETITIVE_PROGRAMMING");
	
	MenuNode* wp = new MenuNode("p", "PERSONAL");
	MenuNode* wo = new MenuNode("1", "Profile 2");
	LeafNode* wifi = new LeafNode("wifi", "Connect to Sandeep_GalaxyA23", "@echo off & netsh wlan connect Sandeep_GalaxyA23");

	LeafNode* wo0 = new LeafNode("0", "OFFICIAL WEBSITE", "start chrome --profile-directory=\"Profile 2\" \"https://www.iitism.ac.in/iitismnew/\"");
	LeafNode* wo1 = new LeafNode("m", "G-MAIL", "start chrome --profile-directory=\"Profile 2\" \"https://mail.google.com/mail/u/0\"");
	LeafNode* wo2 = new LeafNode("d", "G-DRIVE", "start chrome --profile-directory=\"Profile 2\" \"https://drive.google.com/drive/u/0/starred\"");
	LeafNode* wo3 = new LeafNode("c", "G-CLASSROOM", "start chrome --profile-directory=\"Profile 2\" \"https://classroom.google.com/h\"");
	LeafNode* wo4 = new LeafNode("pp", "Classroom", "start chrome --profile-directory=\"Profile 2\" \"https://parent.iitism.ac.in/index.php/parent_portal/portal0\"");
	LeafNode* wo5 = new LeafNode("ms", "Classroom", "start chrome --profile-directory=\"Profile 2\" \"https://mis.iitism.ac.in/\"");
	LeafNode* wo6 = new LeafNode("ss", "Classroom", "start chrome --profile-directory=\"Profile 2\" \"https://app.joinsuperset.com/#/s/feed\"");
	LeafNode* wo7 = new LeafNode("cd", "Classroom", "start chrome --profile-directory=\"Profile 2\" \"https://cdc.iitism.ac.in/tnp/index.php/\"");
	

	// relations:
	main->push_child(f);
	main->push_child(w);
	
	f->push_child(0, f0);
	f->push_child(0, f1);
	f->push_child(0, f2);
	f->push_child(0, f3);
	f->push_child(0, f33);
	f->push_child(0, f4);
	f->push_child(1, f5);
	f->push_child(1, f6);
	f->push_child(1, f7);
	f->push_child(2, f8);
	f->push_child(2, f9);
	f->push_child(2, f10);
	f->push_child(2, f11);
	f->push_child(2, f12);
	
	w->push_child(0, wp);
	w->push_child(0, wo);
	w->push_child(1, wifi);

	wo->push_child(0, wo0);
	wo->push_child(0, wo1);
	wo->push_child(0, wo2);
	wo->push_child(0, wo3);
	wo->push_child(1, wo4);
	wo->push_child(1, wo5);
	wo->push_child(1, wo6);
	wo->push_child(1, wo7);
	
	// start:
	Node::main_loop(main);
	
	return 0;
}