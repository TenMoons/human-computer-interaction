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
int ans_count = 0;  // ������
int sum = 0;  // �յķ�������

void userInterface();

/* ������ɫ */
void SetColor(unsigned short ForeColor = 7, unsigned short BackGroundColor = 0) {
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, ForeColor | BackGroundColor);
}

int ge(int x, int y){
	return(((x - 1) / 3) * 3 + (y - 1) / 3 + 1);
}

/* ��ӡ��ʼ�Ź��� */
void print() {
	cout << "\n\t   1   2   3   4   5   6   7   8   9" << endl;
	SetColor(15);
	cout << "\t ���������ש������ש�����";
	//SetColor(9);
	cout << "��";
	SetColor(15);
	cout << "�������ש������ש�����";
	//SetColor(9);
	cout << "��";
	SetColor(15);
	cout << "�������ש������ש�������" << endl;
	for (int i = 1; i <= 9; i++) {
		cout << "\t" << i;
		for (int j = 1; j <= 9; j++) {
			if (a[i][j] == 0) {
				//if (j == 4 || j == 7) 
					//SetColor(9);
				cout << "��   ";
				SetColor(15);
				if (j == 9)  
					cout << "��";
			}
			else {
				//if (j == 4 || j == 7) 
					//SetColor(9);
				cout << "�� ";
				SetColor(15);
				if (b[i][j] == 0) 
					SetColor(4);
				cout << a[i][j] << " ";
				SetColor(15);
				if (j == 9) 
					cout << "��";
			}
		}
		cout << endl;
		if (i == 3 || i == 6) {
			//SetColor(9);
			cout << "\t �ǩ������贈�����贈����";
			cout << "��";
			cout << "�������贈�����贈����";
			cout << "��";
			cout << "�������贈�����贈������";
			if (i == 3) {
				cout << "\t\t- ����ָ��λ�úʹ𰸣�����x y z����������z���(x,y)";
			}
			if (i == 6) {
				cout << "\t\t- ���أ�����-2 -2 -2�����ص���һ������";
			}
			cout << endl;
			continue;
		}
		if (i != 9) {
			cout << "\t �ǩ������贈�����贈����";
			//SetColor(9);
			cout << "��";
			SetColor(15);
			cout << "�������贈�����贈����";
			//SetColor(9);
			cout << "��";
			SetColor(15);
			cout << "�������贈�����贈������";
			if (i == 4) {
				cout << "\t\t- �鿴�𰸣�����0 0 0";
			}
			if (i == 5) {
				cout << "\t\t- ����һ�֣�����-1 -1 -1";
			}
			cout << endl;
		}

		else {
			SetColor(15);
			cout << "\t ���������ߩ������ߩ�����";
			//SetColor(9);
			cout << "��";
			SetColor(15);
			cout << "�������ߩ������ߩ�����";
			//SetColor(9);
			cout << "��";
			SetColor(15);
			cout << "�������ߩ������ߩ�������" << endl;
		}
		SetColor(15);
		
	}
}


void print_y() {
	cout << "\n\t   1   2   3   4   5   6   7   8   9" << endl;
	SetColor(15);
	cout << "\t ���������ש������ש�����";
	//SetColor(9);
	cout << "��";
	SetColor(15);
	cout << "�������ש������ש�����";
	//SetColor(9);
	cout << "��";
	SetColor(15);
	cout << "�������ש������ש�������" << endl;
	for (int i = 1; i <= 9; i++) {
		cout << "\t" << i;
		for (int j = 1; j <= 9; j++) {
			if (ans[i][j] == 0) {
				//if (j == 4 || j == 7) 
					//SetColor(9);
				cout << "��   ";
				SetColor(15);
				if (j == 9)  
					cout << "��";
			}
			else {
				//if (j == 4 || j == 7) 
					//SetColor(9);
				cout << "�� ";
				SetColor(15);
				if (b[i][j] == 0) 
					SetColor(4);
				cout << ans[i][j] << " ";
				SetColor(15);
				if (j == 9) 
					cout << "��";
			}
		}
		cout << endl;
		if (i == 3 || i == 6) {
			//SetColor(9);
			cout << "\t �ǩ������贈�����贈����";
			cout << "��";
			cout << "�������贈�����贈����";
			cout << "��";
			cout << "�������贈�����贈������";
			if (i == 3) {
				cout << "\t\t- ����ָ��λ�úʹ𰸣�����x y z����������z���(x,y)";
			}
			if (i == 6) {
				cout << "\t\t- ���أ�����-2 -2 -2�����ص���һ������";
			}
			cout << endl;
			continue;
		}
		if (i != 9) {
			cout << "\t �ǩ������贈�����贈����";
			//SetColor(9);
			cout << "��";
			SetColor(15);
			cout << "�������贈�����贈����";
			//SetColor(9);
			cout << "��";
			SetColor(15);
			cout << "�������贈�����贈������";
			if (i == 4) {
				cout << "\t\t- �鿴�𰸣�����0 0 0";
			}
			if (i == 5) {
				cout << "\t\t- ����һ�֣�����-1 -1 -1";
			}
			cout << endl;
		}
		else {
			SetColor(15);
			cout << "\t ���������ߩ������ߩ�����";
			//SetColor(9);
			cout << "��";
			SetColor(15);
			cout << "�������ߩ������ߩ�����";
			//SetColor(9);
			cout << "��";
			SetColor(15);
			cout << "�������ߩ������ߩ�������" << endl;
		}
		SetColor(15);
	}
}

/* ���� */
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

/* ��ʼ�� */
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
	cout << "\n\t\t*********��Ϸ�Ѷ�ѡ��*********\n";
	cout << "\t\t<<                          >>\n";
	cout << "\t\t<<         1 -- ��        >>\n";
	cout << "\t\t<<         2 -- �е�        >>\n";
	cout << "\t\t<<         3 -- ����        >>\n";
	cout << "\t\t<<         4 -- ����        >>\n";
	cout << "\t\t<<                          >>\n";
	cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "\n\t\t��ѡ��";
	cout << "	";
	difficult = 0;
	cin >> difficult;
	if (difficult == 4) {  // ����������
		system("cls");
		userInterface();
	}
}

/* ��Ϸ���� */
int game() {
	run();
	system("cls");
	memcpy(b, a, sizeof(a));
	print();
	int xx, yy, zz;
	cout << "\n\t\t�����룺";
	while (cin >> xx >> yy >> zz) {
		if (xx == 0 && yy == 0 && zz == 0) {  // �鿴��
			system("cls");
			print_y();
			system("pause");
			system("cls");
			userInterface();
		}
		if (xx == -2 && yy == -2 && zz == -2) {  // ������һ������
			system("cls");
			init();
			game();
		}
		if (xx == -1 && yy == -1 && zz == -1) {  // ����һ��
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
		if (b[xx][yy] == 0) {  // ��д����
			a[xx][yy] = zz;
			system("cls");
			print();
			if (ans[xx][yy] == a[xx][yy]) {
				cout << "\t��ϲ�㣡�������\n" << endl;
				ans_count++;
				if (ans_count == sum) {
					ans_count = 0;
					system("pause");
					system("cls");
					cout << "\n\t\t********��ף********" << endl;
					cout << "\t\t<<                >>" << endl;
					cout << "\t\t<<    ������    >>" << endl;
					cout << "\t\t<<  �����Ǹ����  >>" << endl;
					cout << "\t\t<<                >>" << endl;
					cout << "\t\t~~~~~~~~~~~~~~~~~~~~" << endl;
					cout << "\t\t����һ�֣���Y/N):  ";
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
				cout << "\t����������������룡\n" << endl;
				a[xx][yy] = 0;
			}
			system("pause");
		}
		if (b[xx][yy] != 0) {
			SetColor(4);
			cout << "\t����ķ����Ѿ�����ˣ������ٴ���д��" << endl;
			SetColor(15);
			system("pause");
		}
		system("cls");
		print();
		cout << "\n\t\t�����룺";		
	}
	system("pause");
	return 0;
}

/* ������ */
void userInterface() {
	cout << "\n\t\t*******��ӭ����������Ϸ*******" << endl;
	cout << "\t\t<<                          >>" << endl;
	cout << "\t\t<<       a -- ��ʼ��Ϸ      >>" << endl;
	cout << "\t\t<<       b -- ��Ϸ����      >>" << endl;
	cout << "\t\t<<       c -- ����˵��      >>" << endl;
	cout << "\t\t<<       e -- �˳���Ϸ      >>" << endl;
	cout << "\t\t<<                          >>" << endl;
	cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\n\t\t�����룺  ";
	char w;
	cin >> w;
	if (w == 'b') {
		system("cls");
		cout << "\n\t*****************************������Ϸ����*****************************" << endl;
		cout << "\t<<                                                                  >>" << endl;
		cout << "\t<<   ������Ϸ��9x9�ķ����ڽ���,��Ϊ3x3��С����,����Ϊ��.            >>" << endl;
		cout << "\t<<   ������Ϸ���ȴ��Ѿ��������ֵĸ��ӿ�ʼ.                          >>" << endl;
		cout << "\t<<   ��1��9֮������������ո�,һ������ֻ������һ������.             >>" << endl;
		cout << "\t<<   ÿ��������ÿһ��ֻ�ܳ���һ��;                                  >>" << endl;
		cout << "\t<<   ÿ��������ÿһ��ֻ�ܳ���һ��;                                  >>" << endl;
		cout << "\t<<   ÿ��������ÿһ��ֻ�ܳ���һ��;                                  >>" << endl;
		cout << "\t<<   �ܽ���Щ����,��ÿ��������ÿһ��,ÿһ�к�ÿһ��ֻ�ܳ���һ��.    >>" << endl;
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
		cout << "\n\t***************************������Ϸ����˵��***************************" << endl;
		cout << "\t<<                                                                  >>" << endl;
		cout << "\t<<                                                                  >>" << endl;
		cout << "\t<<             ������Ϸ��Ҫ����3�����������С������С���ֵ.         >>" << endl;
		cout << "\t<<                      3�����ֱ��ÿո����.                        >>" << endl;
		cout << "\t<<                     ������ûس�������ȷ��.                      >>" << endl;
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