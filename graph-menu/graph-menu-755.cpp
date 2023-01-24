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
	LeafNode* f11 = new LeafNode("ps", "ProgStuffs", "explorer D:\\ProgStuffs");
	LeafNode* f12 = new LeafNode("cp", "COMPETITIVE PROGRAMMING", "explorer D:\\ProgStuffs\\COMPETITIVE_PROGRAMMING");
	
	MenuNode* wp = new MenuNode("p", "PERSONAL");
	MenuNode* wo = new MenuNode("1", "Profile 2");
	LeafNode* wifi = new LeafNode("wifi", "Connect to Sandeep_GalaxyA23", "@echo off & netsh wlan connect Sandeep_GalaxyA23");

	LeafNode* wp1 = new LeafNode("meet", "G-Meet", "start chrome --profile-directory=\"Default\" \"https://meet.google.com/pah-qvup-ohd\"");
	LeafNode* wp2 = new LeafNode("m", "G-Mail", "start chrome --profile-directory=\"Default\" \"https://mail.google.com/mail/u/0/#inbox\"");
	LeafNode* wp3 = new LeafNode("d", "G-Drive", "start chrome --profile-directory=\"Default\" \"https://drive.google.com/drive/u/0/starred\"");
	MenuNode* wp4 = new MenuNode("cp", "COMPI-and-DSA");
	MenuNode* wp5 = new MenuNode("sc", "SOCIAL");
	MenuNode* wp6 = new MenuNode("tl", "ONLINE TOOLS");

	LeafNode* cp1 = new LeafNode("cf", "codeforces", "start chrome --profile-directory=\"Default\" \"https://codeforces.com/\"");
	LeafNode* cp2 = new LeafNode("ac", "AtCoder", "start chrome --profile-directory=\"Default\" \"https://atcoder.jp/\"");
	LeafNode* cp3 = new LeafNode("cc", "Codechef", "start chrome --profile-directory=\"Default\" \"https://www.codechef.com/\"");
	LeafNode* cp4 = new LeafNode("lc", "Leetcode", "start chrome --profile-directory=\"Default\" \"https://leetcode.com/skauddy755/\"");
	LeafNode* cp5 = new LeafNode("ib", "Interviewbit", "start chrome --profile-directory=\"Default\" \"https://www.interviewbit.com/practice/\"");
	LeafNode* cp6 = new LeafNode("cses", "CSES", "start chrome --profile-directory=\"Default\" \"https://cses.fi/problemset/\"");
	LeafNode* cp7 = new LeafNode("algo", "cp-algorithm", "start chrome --profile-directory=\"Default\" \"https://cp-algorithms.com/\"");
	LeafNode* cp8 = new LeafNode("cphb", "cphb755 - github", "start chrome --profile-directory=\"Default\" \"https://github.com/SandeepKumarAuddy/cphb755\"");

	LeafNode* sc1 = new LeafNode("is", "Instagram", "start chrome --profile-directory=\"Default\" \"https://www.instagram.com/skauddy755/\"");
	LeafNode* sc2 = new LeafNode("fb", "Facebook", "start chrome --profile-directory=\"Default\" \"https://www.facebook.com/\"");
	LeafNode* sc3 = new LeafNode("ln", "LinkedIn", "start chrome --profile-directory=\"Default\" \"https://www.linkedin.com/feed/\"");
	LeafNode* sc4 = new LeafNode("tw", "Twitter", "start chrome --profile-directory=\"Default\" \"https://twitter.com/home\"");
	LeafNode* sc5 = new LeafNode("sk", "Slack", "start chrome --profile-directory=\"Default\" \"https://slack.com/signin#/workspaces\"");
	LeafNode* sc6 = new LeafNode("dd", "Discord", "start chrome --profile-directory=\"Default\" \"https://discord.com/channels/@me\"");
	LeafNode* sc7 = new LeafNode("mt", "Microsoft Teams", "start chrome --profile-directory=\"Default\" \"https://teams.live.com/_#/conversations/?ctx=chat\"");
	LeafNode* sc8 = new LeafNode("gb", "Github", "start chrome --profile-directory=\"Default\" \"https://github.com/SandeepKumarAuddy\"");

	LeafNode* tl1 = new LeafNode("ml", "MATLAB Online", "start chrome --profile-directory=\"Profile 2\" \"https://matlab.mathworks.com/\"");
	LeafNode* tl2 = new LeafNode("ge", "Graph Editor", "start chrome --profile-directory=\"Default\" \"https://csacademy.com/app/graph_editor/\"");
	LeafNode* tl3 = new LeafNode("rb", "Remove BG", "start chrome --profile-directory=\"Default\" \"https://www.remove.bg/upload\"");
	LeafNode* tl4 = new LeafNode("ac", "Audio Changer", "start chrome --profile-directory=\"Default\" \"https://www.audiospeedchanger.com/\"");
	LeafNode* tl5 = new LeafNode("lp", "Leetcode Playground", "start chrome --profile-directory=\"Default\" \"https://leetcode.com/playground/\"");
	LeafNode* tl6 = new LeafNode("lx", "LATEX Editor", "start chrome --profile-directory=\"Default\" \"https://www.tutorialspoint.com/latex_equation_editor.htm\"");
	LeafNode* tl7 = new LeafNode("vp", "Virtual Piano", "start chrome --profile-directory=\"Default\" \"https://www.musicca.com/piano\"");


	LeafNode* wo0 = new LeafNode("0", "OFFICIAL WEBSITE", "start chrome --profile-directory=\"Profile 2\" \"https://www.iitism.ac.in/iitismnew/\"");
	LeafNode* wo1 = new LeafNode("m", "G-MAIL", "start chrome --profile-directory=\"Profile 2\" \"https://mail.google.com/mail/u/0\"");
	LeafNode* wo2 = new LeafNode("d", "G-DRIVE", "start chrome --profile-directory=\"Profile 2\" \"https://drive.google.com/drive/u/0/starred\"");
	LeafNode* wo3 = new LeafNode("c", "G-CLASSROOM", "start chrome --profile-directory=\"Profile 2\" \"https://classroom.google.com/h\"");
	LeafNode* wo4 = new LeafNode("pp", "Parent Portal", "start chrome --profile-directory=\"Profile 2\" \"https://parent.iitism.ac.in/index.php/parent_portal/portal0\"");
	LeafNode* wo5 = new LeafNode("ms", "MIS", "start chrome --profile-directory=\"Profile 2\" \"https://mis.iitism.ac.in/\"");
	LeafNode* wo6 = new LeafNode("ss", "Superset", "start chrome --profile-directory=\"Profile 2\" \"https://app.joinsuperset.com/#/s/feed\"");
	LeafNode* wo7 = new LeafNode("cd", "CDC", "start chrome --profile-directory=\"Profile 2\" \"https://cdc.iitism.ac.in/tnp/index.php/\"");
	

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

	wp->push_child(0, wp1);
	wp->push_child(1, wp2);
	wp->push_child(1, wp3);
	wp->push_child(2, wp4);
	wp->push_child(2, wp5);
	wp->push_child(2, wp6);

	wo->push_child(0, wo0);
	wo->push_child(0, wo1);
	wo->push_child(0, wo2);
	wo->push_child(0, wo3);
	wo->push_child(1, wo4);
	wo->push_child(1, wo5);
	wo->push_child(1, wo6);
	wo->push_child(1, wo7);

	wp4->push_child(0, cp1);
	wp4->push_child(0, cp2);
	wp4->push_child(0, cp3);
	wp4->push_child(0, cp4);
	wp4->push_child(0, cp5);
	wp4->push_child(1, cp6);
	wp4->push_child(1, cp7);
	wp4->push_child(1, cp8);

	wp5->push_child(0, sc1);
	wp5->push_child(0, sc2);
	wp5->push_child(0, sc3);
	wp5->push_child(0, sc4);
	wp5->push_child(1, sc5);
	wp5->push_child(1, sc6);
	wp5->push_child(1, sc7);
	wp5->push_child(2, sc8);

	wp6->push_child(0, tl1);
	wp6->push_child(1, tl2);
	wp6->push_child(1, tl3);
	wp6->push_child(1, tl4);
	wp6->push_child(1, tl5);
	wp6->push_child(1, tl6);
	wp6->push_child(1, tl7);
	
	// start:
	Node::main_loop(main);
	
	return 0;
}