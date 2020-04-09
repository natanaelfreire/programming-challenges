#include <stdio.h>

int sequenceOfN(int n) {
	int cnt = 1;

	while (n != 1) {
		if (n % 2 == 0)
			n = n/2;
		else
			n = n*3 + 1;

		cnt++;
	}

	return cnt;
}

int main() {
	int n, i, j, cmp, r;

	while (scanf("%d %d", &i, &j) != EOF) {
		if (i < 1000000 && i > 0 && j < 1000000 && j > 0) {
			cmp = 0;
			if (i < j) {
				for (n = i; n <= j; n++) {
					r = sequenceOfN(n);
					if (r > cmp)
						cmp = r;
				}
			} else {
				for (n = j; n <= i; n++) {
					r = sequenceOfN(n);
					if (r > cmp)
						cmp = r;
				}
			}

			printf("%d %d %d\n", i, j, cmp); 
		}
	}

	return 0;
}