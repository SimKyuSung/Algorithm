#define N			4
#define MAXCOUNT	10000
typedef struct {
	int strike;
	int ball;
} Result;

// API

extern Result query(int guess[]);

bool pos[MAXCOUNT];
int posCounter;

int init(int guess[]) {

	int num[10];
	for (int x = 0; x < 10; x++)
		num[x] = 0;

	for (int i = 0; i < MAXCOUNT; i++) {
		pos[i] = 1;
		int tmp = i, t = N;
		while (t--) {
			num[tmp % 10]++;
			tmp /= 10;
		}
		for (int x = 0; x < 10; x++) {
			if (num[x] > 1)
				pos[i] = 0;
			num[x] = 0;
		}
		if (pos[i])
			posCounter++;
	}

	guess[0] = 9;
	guess[1] = 8;
	guess[2] = 7;
	guess[3] = 6;

	return 9876;
}

void doUserImplementation(int guess[]) {
	
	int s = init(guess);
	while (posCounter != 1) {
		Result a = query(guess);
		if (a.strike == 4)
			return;

		for (int i = 123; i <= 9876; i++) {
			if (!pos[i])
				continue;
			int ans[N] = { 0, 0, 0, 0 };
			int num[10], t = N, tmp = i;

			for (int x = 0; x < 10; x++)
				num[x] = 0;
			while (t--) {
				ans[t] = tmp % 10;
				num[tmp % 10] = 1;
				tmp /= 10;
			}

			int strike = 0, ball = 0;
			for (int idx = 0; idx < N; ++idx)
				if (guess[idx] == ans[idx])
					strike++;
				else if (num[guess[idx]] > 0)
					ball++;

			if (a.strike != strike || a.ball != ball) {
				pos[i] = 0;
				posCounter--;
			}
			else {
				s = i;
			}
		}

		int nextGuess[N] = { 0, 0, 0, 0 }, t = N;
		while (t--) {
			nextGuess[t] = s % 10;
			s /= 10;
		}
		for (int idx = 0; idx < N; idx++) {
			guess[idx] = nextGuess[idx];
		}
	}
	for (int i = 123; i <= 9876; i++) {
		if (pos[i]) {
			for (int idx = 0; idx < N; idx++)
				guess[idx] = 0;
			int t = N, tmp = i;
			while (t--) {
				guess[t] = tmp % 10;
				tmp /= 10;
			}
			return;
		}
	}
	return;
}