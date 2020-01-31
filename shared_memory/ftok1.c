#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>

int main(void)
{

key_t key;
key=ftok("./test.txt", 7);

printf("key=%d\n",key);

return 0;
}

