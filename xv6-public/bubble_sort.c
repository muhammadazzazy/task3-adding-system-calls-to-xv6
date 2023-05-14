#include "types.h"
#include "user.h"

int
main(int argc, char* argv[])
{
	int i, j, temp;
	if(argc < 3)
		exit();
	int arr[argc-1];
	
	for(int i = 1; i < argc+1; i++) {
		if(argv[i][0] == '-') {
			strcpy(&argv[i][0], &argv[i][1]);
			arr[i-1] = -atoi(argv[i]);
			continue;
		}
		arr[i-1] = atoi(argv[i]);
	}
	for(i = 0; i < argc-2; i++) {
		for(j = 0; j < argc-2; j++) {
			if(arr[j] < arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	for(i = 0; i < argc-1; i++)
		printf(1, "%d\n", arr[i]);
	exit();
}
