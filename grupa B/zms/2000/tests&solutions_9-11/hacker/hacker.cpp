#define MAX 100
#define MAX_FNAME_LEN 30

#define INPUT_FILE  "files.txt"
#define DELETE_FILE "delete.txt"
#define OUTPUT_FILE "hacker.out"

// Boolean constants
#define TRUE  1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
	char *fname;
	int toDel;
} files[MAX];				// List of file names to do NOT delete
unsigned int fcnt;			// Count of file names to do NOT delete

struct {
	char *fname;
	int used;
} del[MAX];					// Strings to delete
unsigned int dcnt;			// Strings to delete count

char *toDel[MAX];			// Strings to delete
unsigned int toDelCnt;

char *unif[MAX*MAX];		// Unified strings
unsigned int ucnt;			// Unified strings count

char *final[MAX];			// Final strings
unsigned int finalCnt = 0;  // Final strings count


void readInputFile() // Get the file names
{
	FILE *fp;
	char s[MAX_FNAME_LEN];
	if ((fp = fopen(INPUT_FILE,"rt")) == NULL) {
		fprintf(stderr,"\nError while trying to open %s for reading!",INPUT_FILE);
		exit(-1);
	}

	fcnt = 0;
	while (!feof(fp)) {
		fscanf(fp,"%s",s);
		files[fcnt].fname = strdup(s);
		files[fcnt++].toDel = FALSE;
	}	

	fclose(fp);
}

void readDeleteFile() // Get the file names
{
	unsigned int i,ind;
	FILE *fp;
	if ((fp = fopen(DELETE_FILE,"rt")) == NULL) {
		fprintf(stderr,"\nError while trying to open %s for reading!",DELETE_FILE);
		exit(-1);
	}

	// Get the files to delete
	for (dcnt = 0; !feof(fp); dcnt++) {
		unsigned int ind;
		fscanf(fp,"%u",&ind);
		files[ind-1].toDel = TRUE;
		del[dcnt].fname = strdup(files[ind-1].fname);
		toDel[dcnt] = strdup(files[ind-1].fname);
		del[dcnt].used = FALSE;
	}
	toDelCnt = dcnt;

	// Remove them from the files list
	for (i = ind = 0; i < fcnt; i++)
		if (!files[i].toDel && i != ind) 
			files[ind++].fname = files[i].fname;
	fcnt = ind;

	fclose(fp);
}

char *unify(char *s1, char *s2, char *result) // Unify two strings
{
	char *res = result;
	if (s1 == NULL || s2 == NULL) return NULL;
	while (*s1 && *s2) {
		if (*s1 == '*' || *s2 == '*') *result++ = '*'; 
		else *result++ = (*s1 == *s2) ? *s1 : '?';
		*s1++; *s2++;
	}

	if (*s1 != *s2 && *(result-1) != '*') *result++ = '*';

	*result = '\0'; 
	return res;
}

void doUnify() 
{
	char s[MAX_FNAME_LEN], s2[MAX_FNAME_LEN];
	unsigned int i,j,k;
	int flag;
	
	ucnt = 0;
	for (i = 0; i < dcnt-1; i++) 
		for (j = i+1; j < dcnt; j++) {
			unify(del[i].fname,del[j].fname,s); // Get the unified code
	
			// Check if it matches a non-delete file name
			for (k = 0, flag = FALSE; k < fcnt; k++)
				if (strcmp(s,unify(files[k].fname,s,s2)) == 0) 
					{ flag = TRUE; break; }

			if (!flag) {
				del[i].used = del[j].used = TRUE;
				// Check if it does exist already
				for (k = 0, flag = FALSE; k < ucnt; k++)
					if (strcmp(s,unif[k]) == 0) { flag = TRUE; break; }
			}

			if (!flag) {
				unif[ucnt++] = strdup(s);
			}
		}
}

void getFinals() // Get the finals
{
	for (unsigned int i = 0; i < dcnt; i++)
		if (!del[i].used) 
			final[finalCnt++] = strdup(del[i].fname);
}

void prepareNextStep() // Prepare the next iteration step
{
	unsigned int i;
	// Free the memory allocated by the old file names
	for (i = 0; i < dcnt; i++) free(del[i].fname);
	// Put in the new files
	dcnt = ucnt;
	for (i = 0; i < ucnt; i++) {
		del[i].fname = unif[i];
		del[i].used = FALSE;
	}
}

// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------

unsigned int *puiCnt;                  // How much times is the element covered
unsigned char *pa;                     // The spanning matrix
unsigned char *curChoice, *bestChoice; // The family of sets chosen
unsigned int minSets = 100000;         // Minimum sets used
unsigned int elemsCovered = 0;         // Elements covered count

void buildSetCoverMatrix()
{
	unsigned int i,j;
	char s[1000];

	puiCnt = new unsigned int [toDelCnt];
	memset(puiCnt,0,toDelCnt*sizeof(unsigned int));

	curChoice = new unsigned char [finalCnt];
	memset(curChoice,0,finalCnt*sizeof(unsigned char));

	bestChoice = new unsigned char [finalCnt];

	pa = new unsigned char [toDelCnt*finalCnt];
	for (i = 0; i < finalCnt; i++)
		for (j = 0; j < toDelCnt; j++)
			pa[i*toDelCnt+j] = !strcmp(final[i],unify(final[i],toDel[j],s));
}

void cover(unsigned ind) 
{
	unsigned int i,j;
	unsigned char found;

	if (ind == finalCnt) return;

	found = FALSE;
	for (j = 0; j < toDelCnt; j++)
		if (!puiCnt[j] && pa[ind*toDelCnt+j]) { found = TRUE; break; }

	// Try to include the set into the cover family
	if (found) {
		for (i = 0; i < ind && found; i++) {
			// Check if the set is obsolete?
			found = FALSE;
			for (j = 0; j < toDelCnt; j++)
				if (pa[i*toDelCnt+j] && !pa[ind*toDelCnt+j]) { found = TRUE; break; }
		}
		if (found) { // Try to include the set 
			for (j = 0; j < toDelCnt; j++)
				if (pa[ind*toDelCnt+j]) {
					if (!puiCnt[j]) elemsCovered++;
					puiCnt[j]++;
				}
			curChoice[ind] = TRUE;

			// Check if a solution has been found
			if (elemsCovered == toDelCnt) {
				unsigned int cnt = 0;
				for (i = 0; i <= ind; i++) if (curChoice[i]) cnt++;
				if (cnt < minSets) { 
					minSets = cnt; 
					for (i = 0; i <= ind; i++) bestChoice[i] = curChoice[i];
				}
			}
			else cover(ind+1);
			
			curChoice[ind] = FALSE;
			for (j = 0; j < toDelCnt; j++) 
				if (pa[ind*toDelCnt+j]) {
					puiCnt[j]--;
					if (!puiCnt[j]) elemsCovered--;
				}
		}
	}

	// Try to skip the set
	cover(ind+1);
}

// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
// ---------------------------------------------------------------------

void main() {
	FILE *fp;
	readInputFile();
	readDeleteFile();
	do {
		doUnify();
		getFinals();
		prepareNextStep();
	} while (ucnt > 0);

	// Solve the minimum set cover
	buildSetCoverMatrix();
	cover(0);

	if ((fp = fopen(OUTPUT_FILE,"wt")) == NULL) {
		fprintf(stderr,"\nError while trying to open %s for writing!",OUTPUT_FILE);
		exit(-1);
	}
	for (unsigned int i = 0; i < finalCnt; i++)
		if (bestChoice[i])
			fprintf(fp,"DEL %s\n",final[i]);

	fclose(fp);
	return;
}
