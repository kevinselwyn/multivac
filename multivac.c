#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define QUESTION_COUNT 3
#define ANSWER_COUNT   5

static char *question[QUESTION_COUNT] = {
	"entropy",
	"be",
	"reversed"
};

static char *answers[ANSWER_COUNT] = {
	"INSUFFICIENT DATA FOR MEANINGFUL ANSWER",
	"INSUFFICIENT DATA FOR A MEANINGFUL ANSWER",
	"THERE IS INSUFFICIENT DATA FOR A MEANINGFUL ANSWER",
	"THERE IS AS YET INSUFFICIENT DATA FOR A MEANINGFUL ANSWER",
	"LET THERE BE LIGHT!"
};

int main(int argc, char *argv[]) {
	int i = 0, l = 0, answer = 0, random = 0;
	time_t now;

	if (argc >= QUESTION_COUNT + 1) {
		for (i = 0, l = QUESTION_COUNT; i < l; i++) {
			if (strcmp(argv[i + 1], question[i]) != 0) {
				answer = 1;
				break;
			}
		}

		if (answer == 0) {
			srand(time(&now));
			random = getuid() == 0 ? ANSWER_COUNT - 1 : rand() % (ANSWER_COUNT - 1);

			printf("%s\n", answers[random]);
		}
	}

	return 0;
}