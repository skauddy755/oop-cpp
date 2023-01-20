#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>

using namespace std;

enum Motion {
	STOP = 0,
	LEFT, UP, RIGHT, DOWN
};

Motion opp(Motion dir) {
	Motion oppDir;
	switch(dir) {
		case STOP: 	oppDir = STOP; 	break;
		case LEFT: 	oppDir = RIGHT; break;
		case RIGHT: oppDir = LEFT; 	break;
		case UP: 	oppDir = DOWN;	break;
		case DOWN: 	oppDir = UP; 	break;
	}
	return oppDir;
}

class Point {
	public:
	int x;
	int y;
	
	Point(const Point &p) {
		x = p.x;
		y = p.y;
	};
	
	Point(int xx, int yy) {
		x = xx;
		y = yy;
	};
	
	bool equals(Point &p) {
		return (x == p.x && y == p.y);
	};
	
	void move(Motion dir) {
		switch(dir) {
			case STOP:  break;
			case LEFT:	x--; break;
			case UP: 	y--; break;
			case RIGHT: x++; break;
			case DOWN: 	y++; break;
		}
	};
	
	Point get(Motion dir) {
		Point p = Point(x, y);
		
		switch(dir) {
			case STOP:  break;
			case LEFT:	p.x--; break;
			case UP: 	p.y--; break;
			case RIGHT: p.x++; break;
			case DOWN: 	p.y++; break;
		}
		
		return p;
	};
};

class Snake {
	public:
	int len;
	char head, tail;
	Motion dir;
	vector<Point> body;
	
	Snake(int n, char h, char t, Motion d, Point h_cord) {
		len = n;
		head = h;
		tail = t;
		
		body.push_back(Point(h_cord));
		for(int i=1; i<len; i++) {
			body.push_back(body[i-1].get(opp(d)));
			// body.push_back(Point(-1, -1));
		}
		
		dir = STOP;
	};
	
	void move() {
		
		if(dir == STOP) return;
		
		for(int i=len-1; i>=1; i--) {
			body[i] = Point(body[i-1]);
		}
		body[0] = body[0].get(dir);
	};
	
	void grow(int step) {
		for(int k=0; k<step; k++) body.push_back(Point(body[len-1]));
		len += step;
	}
};

class Board {
	public:
	int width, height;
	char wall, space;
	
	Board(int w, int h, char wa, char sp) {
		width = w;
		height = h;
		wall = wa;
		space = sp;
	}
};

class Game {
	public:
	
	bool gameOver;
	int coord;
	
	int score;
	Snake *snk;
	Board *brd;
	
	Point *fruit;
	char fruit_char;
	
	Game(int sc, Snake *s, Board *b, char f) {
		gameOver = false;
		
		score = sc;
		snk = s;
		brd = b;
		
		fruit_char = f;
	};
	
	void setup() {
		gameOver = false;
		coord = 0;
		fruit = new Point(1 + rand() % brd->width, 1 + rand() % brd->height);
	};
	
	void draw() {
		
		if(snk->dir != STOP) snk->move();
		
		// system("cls");
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
		
		for(int j=0; j<=brd->width+1; j++) {
			cout << brd->wall;
		}
		cout << endl;
		
		for(int i=1; i<=brd->height; i++) {
			cout << brd->wall;
			for(int j=1; j<=brd->width; j++) {
				Point p = Point(j, i);
				char ch = brd->space;
				
				// Check for snake:
				if(p.equals(snk->body[0])) {
					ch = snk->head;
				}
				for(int k=1; k<snk->len; k++) {
					if(p.equals(snk->body[k])) {
						ch = snk->tail;
					}
				}
				
				// Check for Fruit:
				if(p.equals(*fruit)) {
					ch = fruit_char;
				}
				
				cout << ch;
			}
			cout << brd->wall;
			
			cout << endl;
		}
		
		for(int j=0; j<=brd->width+1; j++) {
			cout << brd->wall;
		}
		cout << endl;
		cout << " Score:  " << score << endl;
		cout << " Dir:  " << snk->dir << endl;
		cout << " Length: " << snk->len << endl;
	}
	
	void input() {
		if(_kbhit()) {
			Motion ndir = snk->dir;
			switch(_getch()) {
				case 'a': ndir = LEFT; break;
				case 'w': ndir = UP; break;
				case 'd': ndir = RIGHT; break;
				case 's': ndir = DOWN; break;
			}
			
			if(snk->dir != STOP && ndir == opp(snk->dir)) {
				ndir = snk->dir;
			}
			
			snk->dir = ndir;
		}
	};
	
	void logic() {
		
		for(int k=3; k<snk->len; k++) {
			if(snk->body[0].equals(snk->body[k])) {
				coord = k;
				gameOver = true;
				return;
			}
		}
		
		if(snk->body[0].equals(*fruit)) {
			fruit = new Point(1 + rand() % brd->width, 1 + rand() % brd->height);
			score += 5;
			
			snk->grow(1);
		}
		
		if(snk->body[0].x < 1) snk->body[0].x = brd->width;
		if(snk->body[0].x > brd->width) snk->body[0].x = 1;
		if(snk->body[0].y < 1) snk->body[0].y = brd->height;
		if(snk->body[0].y > brd->height) snk->body[0].y = 1;
	};
};

int main() {
	system("cls");
	
	int width = 40, height = 25;
	char wc = '#', fc = 'F';
	int len = 5;
	char hc = 'x', tc = 'o';
	
	// cin >> noskipws;
	
	cout << endl << endl;
	cout << "\t\t--------------------------------" << endl;
	cout << "\t\t     Welcome to snake game:" << endl;
	cout << "\t\t--------------------------------" << endl;
	
	cout << endl;
	cout << "Choose your configuration(s):" << endl;
	cout << "=============================" << endl;
	cout << endl;
	
	cout << "BOARD config:" << endl;
	cout << "-----------------------------" << endl;
	cout << "\tBoard Width           : (40) "; cin >> width;
	cout << "\tBoard Height          : (25) "; cin >> height;
	cout << "\tBoard Wall Character  : (#)  "; cin >> wc;
	cout << "\tFruit Character       : (F)  "; cin >> fc;
	cout << endl;
	
	cout << "SNAKE config:" << endl;
	cout << "-----------------------------" << endl;
	cout << "\tSnake Init Length       : (5)  "; cin >> len;
	cout << "\tSnake Head Character    : (x)  "; cin >> hc;
	cout << "\tSnake Tail Character    : (o)  "; cin >> tc;
	cout << endl;
	
	system("cls");
	
	Board *board = new Board(width, height, wc, ' ');
	Snake *snake = new Snake(len, hc, tc, UP, Point(board->width / 2, board->height / 2));
	
	Game *game = new Game(0, snake, board, fc);
	
	game->setup();
	while(!game->gameOver) {
	// while(true) {	
		game->draw();
		game->input();
		game->logic();
	}
	cout << endl << "(dramatic music) GAME OVER, Score: " << game->score << endl;
	cout << snake->body[0].x << "," << snake->body[0].y << endl;
	cout << game->coord << endl;
	for(int i=0; i<snake->len; i++) {
		cout << snake->body[i].x << " " << snake->body[i].y << " | ";
	}
	cout << endl;
	system("pause");
	
	return 0;
}