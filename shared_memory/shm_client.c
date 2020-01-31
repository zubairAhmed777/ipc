#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#define SHMSZ 27

int main(void) 
{
	int shmid;
	key_t key;
	char *shm, *s;

	key = ftok("./test.txt",7);

	// Locate the segment.
	if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
		perror("shmget");
		exit(1);
	}

	//  Now we attach the segment to our data space.
	if ((shm = shmat(shmid, NULL, 0)) == (char*) -1) {
		perror("shmat");
		exit(1);
	}

	// Now read what the server put in the memory.
	for (s = shm; *s != '\0'; s++)
		putchar(*s);
	putchar('\n');

	// Finally, change the first character of the segment to '*'
	*shm = '*';
}