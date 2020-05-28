#include <bits/stdc++.h>

using namespace std;

int main() {

	vector<int> gastos;

	int n, resto, total = 0, totalATrocar = 0;
	double media;
	scanf("%d\n", &n);

	while (n != 0) {

		for (int i = 0; i < n; i++) {
			float aux;
			scanf("%f", &aux);
			gastos.push_back(round(aux * 100.0));
			total += gastos[i];
		}

		media = total / n;
		resto = total % n;

		for (int i = 0; i < gastos.size(); ++i)	{
			if (gastos[i] > media) {
				totalATrocar += gastos[i] - media;
				if (resto > 0) {
					totalATrocar--;
					resto--;
				}
			}			
		}

		printf("$%.2f\n", (float)((float)totalATrocar / 100.0));

		total = 0;
		totalATrocar = 0;
		gastos.clear();

		scanf("%d\n", &n);
		
	}

	return 0;
}
