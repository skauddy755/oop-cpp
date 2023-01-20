#include<bits/stdc++.h>
#include "scales_and_chords.cpp"

using namespace std;
using namespace music;

int main() {
	init_name_index();
	
	Note* Gb = new Note("Gb", 2);
	cout << Gb->getName(true) << endl;
	
	return 0;
}