#include <stdio.h>
#include <stdlib.h>

char ** criaMatriz(int n, int m){
	int i;

	char **mat;
	mat = malloc(sizeof(char *) * n);
	for(i = 0; i < n; ++i){
		mat[i] = malloc(sizeof(char) * m);
	}

	return mat;
}

void printField(char **mat, int n, int m){
	int cnt, i, j;

	for(i = 0; i < n; ++i){
		for(j = 0; j < m; ++j){
			if(mat[i][j] == '*')
				printf("*");
			else{
				cnt = 0;
				if(i != 0 && j != 0)
					if(mat[i-1][j-1] == '*')
						cnt++;

				if(i != 0)
					if(mat[i-1][j] == '*')
						cnt++;

				if(i != 0 && j != m-1)
					if(mat[i-1][j+1] == '*')
						cnt++;

				if(j != 0)
					if(mat[i][j-1] == '*')
						cnt++;

				if(j != m-1)
					if(mat[i][j+1] == '*')
						cnt++;

				if(i != n-1 && j != 0)
					if(mat[i+1][j-1] == '*')
						cnt++;

				if(i != n-1)
					if(mat[i+1][j] == '*')
						cnt++;

				if(i != n-1 && j != m-1)
					if(mat[i+1][j+1] == '*')
						cnt++;	

				printf("%d", cnt);

			}
		}
		printf("\n");

	}

}


int main(){

	int n, m, i, j, cnt = 1;

	scanf("%d %d\n", &n, &m);
	while(n != 0 && m != 0){
		if(n > 0 && m <= 100){
			char **field = criaMatriz(n, m);

			for(i = 0; i < n; ++i){
				for(j = 0; j < m; ++j)
					scanf("%c", &field[i][j]);
				scanf("\n");
			}

			printf("Field #%d:\n", cnt);
			printField(field, n, m);

			scanf("%d %d\n", &n, &m);
			if(n == 0 && m == 0) return 0;
			cnt++;
			printf("\n");
		}
	}


	return 0;
}