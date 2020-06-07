#include <stdio.h>
#include <string.h>

void main(void) {

        int flag;
        int process; // to check if run of kill
        char option[50]= {0};
        char pid[50];
        char command[100];
        int fflag = 0;


    do{

        printf("Press number that represent the operation ..\n");
        printf("1- List all Processes in the system. \n" );
        printf("2- List all the processes grouped by user. \n");
        printf("3- Display process ID of all the processes.\n" );
        printf("4- Run/Stop a process.\n");
        printf("5- Sent a specific singla to a process.\n");
        printf("0- to Close .. \n" );

        printf("Enter # : ");
        scanf("%d", &flag);


            switch (flag) {
                case 1:
                    strcpy(command, "ps -A");
                    system(command);
                    printf("\n\n");
                      
                    break;

                case 2:
                    printf("Enter the user, to get owned process.. : ");
                    scanf("%s", option);

                    strcpy(command, "ps -u ");
                    strcat(command, option);
                    system(command);
                    
                    printf("\n\n\n");
                    break;

                case 3:
                    strcpy(command,"ps -A -o pid");
                    printf("command used is :  ps -A -o pid ");
                    system(command);

                    break;

                case 4:
                    printf("Stop -> 0\nRun -> 1\n");
                    scanf("%d", &process);

                    while(fflag == 0){
                            
                        if(process == 0){// stop a specific process
                            printf("Enter PID : ");
                            scanf("%s", pid);
                            strcpy(command, "kill -STOP ");
                            strcat(command, pid);

                            system(command);
                            fflag = 1;

                        }else if(process == 1){
                            //here to write run a process
                             printf("Enter PID : ");
                            scanf("%s", pid);
                            strcpy(command, "kill -CONT ");
                            strcat(command, pid);

                            system(command);
                            fflag = 1;

                        }else{
                            printf("invalid input ...kill -> 0  Run -> 1");  
                            scanf("%d", &process);

                        }//end if 
                    }//end while    

                    printf("\n\n\n");
                    break;

                case 5:
                   printf("entter the signal number : ");
                    scanf("%s", option);

                    strcpy(command, "kill -");
                    strcat(command, option);
                    strcat(command, " ");

                    printf("\nenter PID number: ");
                    scanf("%s", pid);

                    strcat(command, pid);
                    system(command);

                    printf("\n\n\n");
                    break;
            }

    }while ( flag != 0 );


}
