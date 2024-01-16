#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char* argv[])
{
    
    printf(1, "\n Choose an Option \n ");
    printf(1, "1. Return thr number of root processes \n ");
    printf(1, "2. return the number of child processes \n ");
    printf(1, "3. Return the number of total processes \n ");
    printf(1, "4. exit the program \n \n");
    
    if(argc < 1)
        exit();
    int arr[argc-1];
    int i;
    
    for(i = 1; i < argc; i++) {
        if(argv[i][0] == '-') {
            strcpy(&argv[i][0], &argv[i][1]);
            arr[i-1] = -atoi(argv[i]);
            continue;
        }
        arr[i-1] = atoi(argv[i]);
    }

    int x = fork();
   int y = fork();

    
    for(i = 0; i < argc-1; i++){
        if (arr[i]==1){
            if(x>0 && y>0){
                printf(1 , "Number of root processes: %d \n" ,1);}
            while(wait() != -1) { }
            sleep(1);
            exit();
        }
        
        
        if (arr[i]==2)
        {
            if(x>0 && y>0){
            printf(1," child processes = %d \n", getchild());
            }
            while(wait() != -1) { }
                sleep(1); // give time to parent to reach wait clause */
                exit();
        }
        
        if (arr[i]==3){
            if(x>0 && y>0){
            printf(1 , "Total Processes: %d \n" , numofprocs());
            }
            while(wait() != -1) { }
            sleep(1);
        exit();
        
        }
        
        if (arr[i]==4){
            while(wait() != -1) { }
            sleep(1);
            exit();}
        
    }
}

   


