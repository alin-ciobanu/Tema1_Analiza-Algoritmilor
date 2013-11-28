#include <stdio.h>
#define N 100

float A[N][N];

float read_altitude(int i, int j) {
	return A[i][j];
}

int cautare(float h, int n) {
	int i, j;
	i = n-1;
	j = 0; // se pleaca din coltul din stanga jos
	int directie; // directia poate fi 1 (in dreapta)
			// sau -1 (in sus)

	if (read_altitude(i,j) < h)
		directie = 1;
	else
		directie = -1;

	while (1) {

		if (i < 0) {
			return 0;
		}

		if (directie == 1) {
			if (read_altitude(i, j) <= h) {
				if (read_altitude(i, j) == h) {
					return 1;
				}
				if (j != n-1) {
					j++;
				}
				else {
					return 0;
				}
			}
			else {
				j--;
				directie *= -1;
			}
		}

		if (directie == -1) {
			if (read_altitude(i, j) == h) {
				return 1;
			}
			i--;
			directie *= -1;
		}
	}

}

int main (int argc, char **argv) {
	FILE* in = fopen (argv[1], "r");
	FILE* out = fopen (argv[2], "w");
    	int i, j;
	int n; // numarul de linii/coloane ale matricei
	float h; // altitudinea cautata

	fscanf(in, "%f", &h);
	fscanf(in, "%d", &n);

	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
            		fscanf(in, "%f", &A[i][j]);
       		}
   	}
	fclose(in);

	fprintf(out, "%d\n", cautare(h, n));
	fclose(out);

	return 0;
}

