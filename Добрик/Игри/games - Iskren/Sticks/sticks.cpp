/*
FROM: Central European Olympiad in Informatics (CEOI) 2000 day 2
PROB: sticks
KEYW: SG (Sprague-Grundy) theorem, game addition, splitting one game to other games
*/

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>

const int MAXSPR = 16;//max sticks per row
const int SPR = 10;//real maximum

struct pile {
	int size;
	int rn;//correspond to row number 'rn'
	int fid;//0th stick correspond to fid stick in rn original row
	pile (int _size, int _rn, int _fid) : size (_size), rn (_rn), fid (_fid) {}
	int lid () const {return fid + size;}
};

struct split {
	int p1, p2;
	split () : p1 (-1), p2 (-1) {}
	split (int _p1, int _p2 = 0) : p1 (_p1), p2 (_p2) {}
	bool operator == (const split &a) {return p1 == a.p1 && p2 == a.p2;}
	bool operator != (const split &a) {return p1 != a.p1 || p2 != a.p2;}
};

struct bot_data {
	int rn;//row number
	int fid;//first id
	int lid;//last id
	bot_data () {}
	bot_data (int _rn, int _fid, int _lid) : rn (_rn), fid (_fid), lid (_lid) {}
	bot_data (const pile &p, const split &s) {
		rn = p.rn;
		fid = p.fid + s.p1;
		lid = p.lid () - s.p2 - 1;
	}
};

std::vector <pile> games;
unsigned sg[MAXSPR];
split prev[MAXSPR][MAXSPR];//for each pile size, for each target sg after a move -> what are the sizes of the two parts

void upd_prev (int ps, int p1, int p2) {
	static unsigned sg_sum;
//	printf ("%d - %d %d\n", ps, p1, p2);
	sg_sum = sg[p1] ^ sg[p2];
	if (prev[ps][sg_sum] == split ())
		prev[ps][sg_sum] = split (p1, p2);
}

void calc_sg () {
	sg[0] = 0;
	sg[1] = 1;
	prev[1][0] = split (0);
	int i, j;
	for (i = 2; i <= SPR; ++i) {
		for (j = (i - 2) / 2; j <= i - 3; ++j) {
			upd_prev (i, i - j - 1, j);
			upd_prev (i, i - j - 2, j);
			upd_prev (i, i - j - 3, j);
		}
		upd_prev (i, 0, i - 1);
		upd_prev (i, 1, i - 2);
		upd_prev (i, 0, i - 2);
		
		for (j = 0; prev[i][j] != split (); ++j);
//		printf ("sg[%d] == %d\n", i, j);
		sg[i] = j;
	}
}

bot_data create_move () {
	size_t i;
	unsigned sg_sum = 0;
	for (i = 0; i < games.size (); ++i)
		sg_sum ^= sg[games[i].size];

	if (!sg_sum) {//we lose
		fprintf (stderr, "we lose!\n");
		//play arbitrary
		//take 1 from the first column -> implement random
		return bot_data (games[0].rn, games[0].fid, games[0].fid);
	}

	unsigned sgshb = 1 << (31 - __builtin_clz (sg_sum));
	for (i = 0; i < games.size (); ++i)
		if (sg[games[i].size] & sgshb)
			break;//play here

	assert (i != games.size ());
	return bot_data (games[i], prev[games[i].size][sg_sum ^ sg[games[i].size]]);
}

void do_move (const bot_data &move) {
	size_t i;
	for (i = 0; i < games.size (); ++i)
		if (move.rn == games[i].rn
		 && move.fid >= games[i].fid
		 && move.lid < games[i].lid ())
			break;

	if (i == games.size ()) {
		printf ("illegal move!\n");
		exit (-1);
	}

	int sz1, sz2;
	sz1 = move.fid - games[i].fid;
	sz2 = games[i].lid () - move.lid - 1;
	if (sz1)
		games.push_back (pile (sz1, games[i].rn, games[i].fid));
	if (sz2)
		games.push_back (pile (sz2, games[i].rn, games[i].lid () - sz2));

	games.erase (games.begin () + i);//erase the current game
}

int main () {
	calc_sg ();

	int N;
	scanf ("%d", &N);

	int i;
	int sz;
	for (i = 0; i < N; ++i) {
		scanf ("%d", &sz);
		games.push_back (pile (sz, i, 0));
	}

	printf ("games:\n");
	for (size_t ii = 0; ii < games.size (); ++ii)
		printf ("\t%d %d %d\n", games[ii].size, games[ii].rn, games[ii].fid);


	int sec;
	scanf ("%d", &sec);	
	bot_data move;
	for (;;) {
		if (!sec) {//we play
			move = create_move ();
			do_move (move);
			printf ("%d %d %d\n", move.rn + 1, move.fid + 1, move.lid + 1);
		} else {//bot play
			scanf ("%d %d %d", &move.rn, &move.fid, &move.lid);
			--move.rn; --move.fid; --move.lid;
			do_move (move);
		}
		sec = !sec;
		if (!games.size ()) {
			printf ("game ends!\n%s WINS\n", sec ? "PLAYER" : "BOT");
			exit (0);
		}
		printf ("games:\n");
		for (size_t ii = 0; ii < games.size (); ++ii)
			printf ("\t%d %d %d\n", games[ii].size, games[ii].rn, games[ii].fid);
	}

	return 0;
}
