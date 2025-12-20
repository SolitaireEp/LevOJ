#include<stdio.h>//程序填空
int main() {
	int op1[100][100], op2[100][100];
	int res[100][100] = {0};
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &op1[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &op2[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				res[i][j] += op1[i][k]* op2[k][j];
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}
