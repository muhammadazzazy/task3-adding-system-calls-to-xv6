#include "types.h"
#include "user.h"
#include <errno.h>
#include <math.h>

int
main(int argc, char* argv[])
{
	if(argc < 2)
		exit();
	int arr[argc-1];
	int i, j;
	for(i = 1; i < argc; i++) {
		if(argv[i][0] == '-') {
			strcpy(&argv[i][0], &argv[i][1]);
			arr[i-1] = -atoi(argv[i]);
			continue;
		}
		arr[i-1] = atoi(argv[i]);	
	}
	float sum = 0.0;
	for(i = 0; i < argc-1; i++)
		sum += arr[i];	
	float average = sum / (argc-1);
	float max = arr[0];
	float min = arr[0];
	for(i = 1; i < argc-1; i++) {
		if(arr[i] > max)
			max = arr[i];
		if(arr[i] < min)
			min = arr[i];
	}
	float sum_of_squares = 0.0;
	for(i = 0; i < argc-1; i++)
		sum_of_squares += pow(arr[i], 2);
	float square_of_mean = pow(average, 2);
	float var = sum_of_squares / (argc-1) - square_of_mean;
	float std = sqrt(var);
	float temp, median;
	int pos;
	for(i = 0; i < argc-2; i++) {
		for(j = 0; j < argc-2; j++) {
			if(arr[j] < arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	if((argc-1) % 2 == 0)
		median = (arr[(argc-1)/2] + arr[(argc-1)/2 + 1]) / 2;
	else {
		pos = (argc-1)/2 + 1;
		median = arr[pos];
	}
	printf(1, "The average is %d.\n", (int)average);
	printf(1, "The maximum is %d.\n", (int)max);
	printf(1, "The minimum is %d.\n", (int)min);
	printf(1, "The standard deviation is %d.\n", (int)std);
	printf(1, "The median is %d.\n", (int)median);
	exit();
}
