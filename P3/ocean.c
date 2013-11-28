#include <stdio.h>
#include <stdlib.h>

int* findLongestSeq( int* a, int n, int *nr) {
	int *best, i, j, max = 0;
	int* v; // vectorul in care se va pune rezultatul
	best = (int*) malloc (sizeof(int)*n);
	// best = vectorul care in care se calculeaza care e cea mai lunga secventa care se termina pe pozitia curenta

	for (i = 0; i < n; i++)
		best[i] = 1;

	for (i = 1; i < n; i++)
		for ( j = 0; j < i; j++ )
			if ( a[i] > a[j] && best[i] < best[j] + 1 ){
				best[i] = best[j] + 1;
				if(max < best[i])
					max = best[i];
			}
	*nr = max;
	v = (int*) malloc (sizeof(int)*max);

	for (i = n-1; i >= 0; i--) {
		if (best[i] == max) {
			v[max-1] = a[i];
			max--;
		}
	}

	return v;
}

int main(int argc, char** argv){
	int i, n;
	int* v; // vectorul
	int nr, *vrez; // nr = nr de elemente din vectorul rezultat
		// vrez = vectorul in care se va pune cea mai lunga secventa crescatoare

	FILE* in = fopen (argv[1], "r");
	FILE* out = fopen (argv[2], "w");

	fscanf (in, "%d ", &n);
	v = (int*) malloc (n*sizeof(int));
	for (i=0; i<n; i++)
 		fscanf(in, "%d ", &v[i]);
	fclose(in);

	vrez = findLongestSeq(v, n, &nr);	

	for (i=0; i<nr; i++)
		fprintf(out, "%d ", vrez[i]);
	fclose(out);

	return 0;
}

