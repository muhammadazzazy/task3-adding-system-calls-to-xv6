#include "types.h"
#include "user.h"
#include <stdbool.h>
#include <stddef.h>

int
main(int argc, char* argv[])
{
	int i, key;
	if(argc < 3)
		exit();
	int arr[argc-2];

	for(i = 1; i < argc-1; i++) {
		if(argv[i][0] == '-') {
			strcpy(&argv[i][0], &argv[i][1]);
			arr[i-1] = -atoi(argv[i]);
			continue;
		}
		arr[i-1] = atoi(argv[i]);
	}
	if(argv[argc-1][0] == '-') {
		strcpy(&argv[i][0], &argv[i][1]);
		key = -atoi(argv[argc-1]);
	} else
		key = atoi(argv[argc-1]);
	bool flag = false;
	for(i = 0; i < argc-2; i++) {
		if(arr[i] == key) {
			flag = true;
			break;
		}
	}
	if(flag)
		printf(1, "The key is at index %d.\n", i);
	else
		printf(1, "The key is not in the list.\n");
	exit();
}
