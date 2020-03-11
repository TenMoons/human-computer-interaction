#include<iostream>
#include<cstring>
#include<time.h>
#include<cstdlib>
#include<windows.h>
using namespace std;
int a[15][15], ans_pre, ans[15][15], b[15][15];
bool square[10][10], lie[10][10], hang[10][10], flag[15][15];
bool check;
bool f[15];
int c[15];
int difficult;
int level1 = 20;
int level2 = 40;
int level3 = 60;
int ans_count = 0;  // 计数器
int sum = 0;  // 空的方格总数

void userInterface();

/* 设置颜色 */
void SetColor(unsigned short ForeColor = 7, unsigned short BackGroundColor = 0) {
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, ForeColor | BackGroundColor);
}

int ge(int x, int y){
	return(((x - 1) / 3) * 3 + (y - 1) / 3 + 1);
}

/* 打印初始九宫格 */
void print() {
	cout << "\n\t   1   2   3   4   5   6   7   8   9" << endl;
	SetColor(15);
	cout << "\t ┏━━━┳━━━┳━━━";
	//SetColor(9);
	cout << "┳";
	SetColor(15);
	cout << "━━━┳━━━┳━━━";
	//SetColor(9);
	cout << "┳";
	SetColor(15);
	cout << "━━━┳━━━┳━━━┓" << endl;
	for (int i = 1; i <= 9; i++) {
		cout << "\t" << i;
		for (int j = 1; j <= 9; j++) {
			if (a[i][j] == 0) {
				//if (j == 4 || j == 7) 
					//SetColor(9);
				cout << "┃   ";
				SetColor(15);
				if (j == 9)  
					cout << "┃";
			}
			else {
				//if (j == 4 || j == 7) 
					//SetColor(9);
				cout << "┃ ";
				SetColor(15);
				if (b[i][j] == 0) 
					SetColor(4);
				cout << a[i][j] << " ";
				SetColor(15);
				if (j == 9) 
					cout << "┃";
			}
		}
		cout << endl;
		if (i == 3 || i == 6) {
			//SetColor(9);
			cout << "\t ┣━━━╋━━━╋━━━";
			cout << "╋";
			cout << "━━━╋━━━╋━━━";
			cout << "╋";
			cout << "━━━╋━━━╋━━━┫";
			if (i == 3) {
				cout << "\t\t- 输入指定位置和答案：输入x y z，将用数字z填充(x,y)";
			}
			if (i == 6) {
				cout << "\t\t- 返回：输入-2 -2 -2，返回到上一个界面";
			}
			cout << endl;
			continue;
		}
		if (i != 9) {
			cout << "\t ┣━━━╋━━━╋━━━";
			//SetColor(9);
			cout << "╋";
			SetColor(15);
			cout << "━━━╋━━━╋━━━";
			//SetColor(9);
			cout << "╋";
			SetColor(15);
			cout << "━━━╋━━━╋━━━┫";
			if (i == 4) {
				cout << "\t\t- 查看答案：输入0 0 0";
			}
			if (i == 5) {
				cout << "\t\t- 再来一局：输入-1 -1 -1";
			}
			cout << endl;
		}

		else {
			SetColor(15);
			cout << "\t ┗━━━┻━━━┻━━━";
			//SetColor(9);
			cout << "┻";
			SetColor(15);
			cout << "━━━┻━━━┻━━━";
			//SetColor(9);
			cout << "┻";
			SetColor(15);
			cout << "━━━┻━━━┻━━━┛" << endl;
		}
		SetColor(15);
		
	}
}


void print_y() {
	cout << "\n\t   1   2   3   4   5   6   7   8   9" << endl;
	SetColor(15);
	cout << "\t ┏━━━┳━━━┳━━━";
	//SetColor(9);
	cout << "┳";
	SetColor(15);
	cout << "━━━┳━━━┳━━━";
	//SetColor(9);
	cout << "┳";
	SetColor(15);
	cout << "━━━┳━━━┳━━━┓" << endl;
	for (int i = 1; i <= 9; i++) {
		cout << "\t" << i;
		for (int j = 1; j <= 9; j++) {
			if (ans[i][j] == 0) {
				//if (j == 4 || j == 7) 
					//SetColor(9);
				cout << "┃   ";
				SetColor(15);
				if (j == 9)  
					cout << "┃";
			}
			else {
				//if (j == 4 || j == 7) 
					//SetColor(9);
				cout << "┃ ";
				SetColor(15);
				if (b[i][j] == 0) 
					SetColor(4);
				cout << ans[i][j] << " ";
				SetColor(15);
				if (j == 9) 
					cout << "┃";
			}
		}
		cout << endl;
		if (i == 3 || i == 6) {
			//SetColor(9);
			cout << "\t ┣━━━╋━━━╋━━━";
			cout << "╋";
			cout << "━━━╋━━━╋━━━";
			cout << "╋";
			cout << "━━━╋━━━╋━━━┫";
			if (i == 3) {
				cout << "\t\t- 输入指定位置和答案：输入x y z，将用数字z填充(x,y)";
			}
			if (i == 6) {
				cout << "\t\t- 返回：输入-2 -2 -2，返回到上一个界面";
			}
			cout << endl;
			continue;
		}
		if (i != 9) {
			cout << "\t ┣━━━╋━━━╋━━━";
			//SetColor(9);
			cout << "╋";
			SetColor(15);
			cout << "━━━╋━━━╋━━━";
			//SetColor(9);
			cout << "╋";
			SetColor(15);
			cout << "━━━╋━━━╋━━━┫";
			if (i == 4) {
				cout << "\t\t- 查看答案：输入0 0 0";
			}
			if (i == 5) {
				cout << "\t\t- 再来一局：输入-1 -1 -1";
			}
			cout << endl;
		}
		else {
			SetColor(15);
			cout << "\t ┗━━━┻━━━┻━━━";
			//SetColor(9);
			cout << "┻";
			SetColor(15);
			cout << "━━━┻━━━┻━━━";
			//SetColor(9);
			cout << "┻";
			SetColor(15);
			cout << "━━━┻━━━┻━━━┛" << endl;
		}
		SetColor(15);
	}
}

/* 搜索 */
int dfs(int x, int y) {
	if (!check) 
		return 0;
	if (x == 0 && y == 9) 	{
		check = false;
		return 0;
	}
	if (a[x][y] == 0)
		for (int j = 1; j <= 9; j++) {
			int i = c[j];
			if (square[ge(x, y)][i] && lie[y][i] && hang[x][i]) {
				square[ge(x, y)][i] = false;
				lie[y][i] = false;
				hang[x][i] = false;
				ans[x][y] = i;
				if (y == 1) 
					dfs(x - 1, 9); 
				else 
					dfs(x, y - 1);
				square[ge(x, y)][i] = true;
				lie[y][i] = true;
				hang[x][i] = true;
				if (!check) 
					return 0;
			}
		}
	if (!check)
		return 0;
	if (a[x][y] != 0) 
		if (y == 1) 
			dfs(x - 1, 9); 
		else 
			dfs(x, y - 1);
}

int work(int x) {
	if (x == 10)
		return 0;
	int i = 1;
	int y = rand() % 9 + 1;
	while (!f[y]) 
		y = rand() % 9 + 1;
	f[y] = false;
	c[x] = y;
	work(x + 1);
}


void run() {
	switch (difficult) {
	case 1:sum = level1;
		break;
	case 2:sum = level2;
		break;
	case 3:sum = level3;
		break;
	}
	int i = 1;
	while (i <= sum) {
		int x, y;
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		while (a[x][y] == 0) {
			x = rand() % 9 + 1;
			y = rand() % 9 + 1;
		}
		a[x][y] = 0;
		i++;
	}
}

/* 初始化 */
void init() {
	srand(time(NULL));
	memset(a, 0, sizeof(a));
	memset(lie, true, sizeof(lie));
	memset(hang, true, sizeof(hang));
	memset(square, true, sizeof(square));
	memset(f, true, sizeof(f));
	check = true;
	work(1);
	memset(a, sizeof(a), 0);
	check = true;
	dfs(9, 9);
	memcpy(a, ans, sizeof(ans));
	system("cls");
	cout << "\n\t\t*********游戏难度选择*********\n";
	cout << "\t\t<<                          >>\n";
	cout << "\t\t<<         1 -- 简单        >>\n";
	cout << "\t\t<<         2 -- 中等        >>\n";
	cout << "\t\t<<         3 -- 困难        >>\n";
	cout << "\t\t<<         4 -- 返回        >>\n";
	cout << "\t\t<<                          >>\n";
	cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "\n\t\t请选择：";
	cout << "	";
	difficult = 0;
	cin >> difficult;
	if (difficult == 4) {  // 返回主界面
		system("cls");
		userInterface();
	}
}

/* 游戏界面 */
int game() {
	run();
	system("cls");
	memcpy(b, a, sizeof(a));
	print();
	int xx, yy, zz;
	cout << "\n\t\t请输入：";
	while (cin >> xx >> yy >> zz) {
		if (xx == 0 && yy == 0 && zz == 0) {  // 查看答案
			system("cls");
			print_y();
			system("pause");
			system("cls");
			userInterface();
		}
		if (xx == -2 && yy == -2 && zz == -2) {  // 返回上一个界面
			system("cls");
			init();
			game();
		}
		if (xx == -1 && yy == -1 && zz == -1) {  // 再来一局
			system("cls");
			srand(time(NULL));
			memset(a, 0, sizeof(a));
			memset(lie, true, sizeof(lie));
			memset(hang, true, sizeof(hang));
			memset(square, true, sizeof(square));
			memset(f, true, sizeof(f));
			check = true;
			work(1);
			memset(a, sizeof(a), 0);
			check = true;
			dfs(9, 9);
			memcpy(a, ans, sizeof(ans));
			game();
		}
		if (b[xx][yy] == 0) {  // 填写方格
			a[xx][yy] = zz;
			system("cls");
			print();
			if (ans[xx][yy] == a[xx][yy]) {
				cout << "\t恭喜你！答对啦！\n" << endl;
				ans_count++;
				if (ans_count == sum) {
					ans_count = 0;
					system("pause");
					system("cls");
					cout << "\n\t\t********庆祝********" << endl;
					cout << "\t\t<<                >>" << endl;
					cout << "\t\t<<    你答对了    >>" << endl;
					cout << "\t\t<<  你真是个天才  >>" << endl;
					cout << "\t\t<<                >>" << endl;
					cout << "\t\t~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << "\t\t再来一局？（Y/N):  ";
					char choice;
					cin >> choice;
					if (choice == 'Y') {
						system("cls");
						srand(time(NULL));
						memset(a, 0, sizeof(a));
						memset(lie, true, sizeof(lie));
						memset(hang, true, sizeof(hang));
						memset(square, true, sizeof(square));
						memset(f, true, sizeof(f));
						check = true;
						work(1);
						memset(a, sizeof(a), 0);
						check = true;
						dfs(9, 9);
						memcpy(a, ans, sizeof(ans));
						game();
					}
					else {
						system("cls");
						userInterface();
					} 
				}
			}
			else {
				cout << "\t输入错误！请重新输入！\n" << endl;
				a[xx][yy] = 0;
			}
			system("pause");
		}
		if (b[xx][yy] != 0) {
			SetColor(4);
			cout << "\t您填的方格已经填好了，不可再次填写！" << endl;
			SetColor(15);
			system("pause");
		}
		system("cls");
		print();
		cout << "\n\t\t请输入：";		
	}
	system("pause");
	return 0;
}

/* 主界面 */
void userInterface() {
	cout << "\n\t\t*******欢迎进入数独游戏*******" << endl;
	cout << "\t\t<<                          >>" << endl;
	cout << "\t\t<<       a -- 开始游戏      >>" << endl;
	cout << "\t\t<<       b -- 游戏规则      >>" << endl;
	cout << "\t\t<<       c -- 按键说明      >>" << endl;
	cout << "\t\t<<       e -- 退出游戏      >>" << endl;
	cout << "\t\t<<                          >>" << endl;
	cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\n\t\t请输入：  ";
	char w;
	cin >> w;
	if (w == 'b') {
		system("cls");
		cout << "\n\t*****************************数独游戏规则*****************************" << endl;
		cout << "\t<<                                                                  >>" << endl;
		cout << "\t<<   数独游戏在9x9的方格内进行,分为3x3的小方格,被称为区.            >>" << endl;
		cout << "\t<<   数独游戏首先从已经填入数字的格子开始.                          >>" << endl;
		cout << "\t<<   用1至9之间的数字填满空格,一个格子只能填入一个数字.             >>" << endl;
		cout << "\t<<   每个数字在每一行只能出现一次;                                  >>" << endl;
		cout << "\t<<   每个数字在每一列只能出现一次;                                  >>" << endl;
		cout << "\t<<   每个数字在每一区只能出现一次;                                  >>" << endl;
		cout << "\t<<   总结这些规则,即每个数字在每一行,每一列和每一区只能出现一次.    >>" << endl;
		cout << "\t<<                                                                  >>" << endl;
		cout << "\t**********************************************************************" << endl;
		cout << "\n\t\t";
		system("pause");
		system("cls");
		userInterface();
	}
	if (w == 'a') {
		init();
		game();
	}
	if (w == 'c') {
		system("cls");
		cout << "\n\t***************************数独游戏按键说明***************************" << endl;
		cout << "\t<<                                                                  >>" << endl;
		cout << "\t<<                                                                  >>" << endl;
		cout << "\t<<             进入游戏后要输入3个数：所在行、所在列、其值.         >>" << endl;
		cout << "\t<<                      3个数分别用空格隔开.                        >>" << endl;
		cout << "\t<<                     输完后用回车键进行确定.                      >>" << endl;
		cout << "\t<<                                                                  >>" << endl;
		cout << "\t<<                                                                  >>" << endl;
		cout << "\t**********************************************************************" << endl;
		cout << "\n\t\t";
		system("pause");
		system("cls");
		userInterface();
	}
	if (w == 'd') {
		exit(0);
	}
}

int main() {
	userInterface();
	return 0;
}