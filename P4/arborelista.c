#include <stdio.h>
#include <stdlib.h>

typedef struct tnod {
	int val;
	struct tnod* mici;
	struct tnod* mari;
} tnod;

tnod* add (tnod* r, int x) {
	if (r == NULL) {
		r =(tnod*) malloc (sizeof(tnod));
		r->val = x;
		r->mici = r->mari = NULL;
	}
	else
		if (x < r->val)
			r->mici = add (r->mici, x);
		else
			r->mari = add (r->mari, x);
	return r;
}

void convert(tnod *r, tnod** prev, tnod ** head) {
// head este pointer catre primul element al listei
// prev este pointer catre predecesorul lui r
	if (r == NULL)
		return;

	convert(r->mici, prev, head);

	r->mici = *prev; // nodul curent pointeza spre precedentul
	if (*prev != NULL)
		(*prev)->mari = r;  // legatura spre mari a precedentului pointeaza catre nodul nod curent
	else
		*head = r; // nodul curent (cel mai mic element) este inceput de lista daca precedentul nu exista

	tnod *mari = r->mari;
	(*head)->mici = r;
	r->mari = *head;
	*prev = r; // schimba nodul precedent

	convert(mari, prev, head);
}

tnod* arbToList (tnod* r) {
	tnod* prev = NULL;
	tnod* head = NULL;
	convert(r, &prev, &head);
	return head;
}

void printList (tnod* r, char* fileName) {
	FILE* out = fopen(fileName, "w");
	tnod* temp = r;
	if (r != NULL)
		fprintf(out, "%d ", r->val);
	while (r->mari != temp) {
		fprintf(out, "%d ", r->mari->val);
		r = r->mari;
	}
	fclose(out);
}


int main (int argc, char** argv) {

	FILE* in = fopen (argv[1], "r");

	int nr; // urmatorul numar care se va citi din fisier
	tnod* r = NULL; // arborele care se va transforma in lista

	while (fscanf(in, "%d", &nr) != EOF) {
		r = add(r, nr);
	}
	fclose(in);

	r = arbToList(r);
	printList(r, argv[2]);
    
    return 0;
}
