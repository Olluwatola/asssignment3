
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
    FILE *file; 
    file = fopen("selfdescribing.in", "r");
    if (file==NULL){
            printf("File cant be opened \n");
        }else{
    
    //we initialize our variables
        int array[100];
        char matchStatus = '1';

        // we then read the first line to ge the number of test cases
        int TC;
        fscanf(file, "%d", &TC);

        for (int a=0; a<TC; a++){
        //we loop through the file and assign the digits to the variable test num
            char testnum[100];
            fscanf(file, "%s", testnum);
            int length;
            length = strlen(testnum);
            // we test each position and assign 1 for true and 0 for false
            for (int b = 0; b < length; b++) {
                array[b] =testnum[b] - '0';
            }
            for (int b = 0; b< length; b++) {
                int counter = 0;
    
                for (int a = 0; a< length; a++) {
                    if (array[a] == b) 
                    counter++;
                }
                if(counter == array[b]){
                    matchStatus = '1';
                }
                else{
                    matchStatus = '0';
                    printf("Not self-describing\n");
                    break;
                }
                counter = 0;
                if (matchStatus!= '0'){
                    printf("Self-describing\n");
                    break;
                }
            }
            
        }
        fclose(file);
}    return 0;
}