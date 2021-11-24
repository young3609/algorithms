#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

void hanoi(int n,int x,int y) {
	if (n == 0)return;
	hanoi(n - 1, x, 6 - x - y);
	printf("%d %d\n",x,y);
	hanoi(n - 1, 6 - x - y, y);
}

int main() {

	int n;
	//test git new branch
    int test = 0;

	scanf("%d",&n);
	printf("%d\n",(1<<n)-1);

	hanoi(n,1,3);

	return 0;
}