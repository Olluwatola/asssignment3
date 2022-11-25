#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>

void string_split(char *s, int index ,char *first , char *second );
int main(){
        // the below lines of code read the files
    FILE* filePointer;
    char fileLine[50];
    filePointer = fopen("files.in", "r");
    

    if (NULL == filePointer) {
        printf("file can't be opened \n");
    }else{
        printf("file loaded\n");
        //first we split the file placeholder into the string part and integer part
        //we do this by detecting for the first digit in the placeholder

        //below we detect the index where the string parts ends, per line
        int counter=0;
        int* counterPter=&counter;
        int noOfIterations;
        int numPartArray[2];
        int* noiPter=&noOfIterations;
        

        char breakerCharacter[] = "0123456789 ";
        
        while (fgets(fileLine, 50, filePointer) != NULL) {    
            int numBeforeInt;
            char breakerCharacter[] = "0123456789 ";
            numBeforeInt = strcspn(fileLine, breakerCharacter);;
            char stringPartArray[10];
            char numPartTemp[30];
            
            if(numBeforeInt==0 && counter + 1 != noOfIterations){
                printf("entering first if \n");
                    noOfIterations=atoi(fileLine);
                    counter=0;
                    numPartArray[*noiPter];
            }else if(numBeforeInt>0){
                string_split(fileLine,numBeforeInt,stringPartArray,numPartTemp);
                printf("expected number of iterations is %d \n",noOfIterations);
                printf("the value of counter  is %d \n",*counterPter);
                numPartArray[*counterPter]=atoi(numPartTemp);
                counter=counter+1;
                printf("this is the string part : %s \n",stringPartArray);
                printf("this is the number part: %s \n",numPartTemp);
                printf("counter equals %d",counter);
             }
             if(counter == noOfIterations){
                printf("about to enter third if \n");
                int loop;
                int* loopPtr= &loop;
                printf("%d", sizeof(numPartArray)/sizeof(numPartArray[0]));
                for(loop = 0; loop < sizeof(numPartArray)/sizeof(numPartArray[0]); loop++){
                    printf("%s ", numPartArray[*loopPtr]);
                    return 0;
                }
                counter = 0;


            

                // if(strlen(fileLine)==1){
                //     noOfIterations=atoi(fileLine);
                //     counter=0;
                //     numPartArray[*noiPter];   
                // }
            
            }


            //below  we split the string part and the array part into two different  arrays

            // first we figure out if the string array is empty or not
            // if((sizeof(stringPartArray)/sizeof(stringPartArray[0])!=0)){
            //     //we crop out the string part below


            // printf("%s \n",fileLine);
            // printf("%d \n",numBeforeInt);
            // string_split(fileLine,numBeforeInt,stringPartArray,numPartTemp);
            // printf("this is the string part : %s \n",stringPartArray);
            // printf("this is the number part: %s \n",numPartTemp);




            // }else{

            // }
            //}

        }
        
        
        // // the below while loop loops through each line of the strings in the file scanned
        // while (fgets(fileLine, 50, filePointer) != NULL) {
        //     //the line below loops through the line being, read character by character
        //     numBeforeInt = strcspn(fileLine, breakerCharacter);
        //     printf("%d",numBeforeInt);


            //for(int i = 0; i < strlen(fileLine); i++) {
                //printf("%c \n", fileLine[i]);
                
                // the line below scans if the current character is a string or integer
                // the atoi() methods tests if the character passes as an integer and returns 1 for true
                //or returns 1 for true
                //int boolNumOutput = isdigit(fileLine[i]);

                

                //if the  i passes as an integer we slice the file placeholder into the string part and number parts
                //at this point
                // if(boolNumOutput!=0){
                //     stringPart[i]=fileLine[i];
                // }else{
                //     break;
                // }


            //     int numOutput = atoi(string);

            // //if it passes as integer , it is skipped and no steps are counted
            // if(numOutput!=0){
            //     printf(" ");
            // }else{
            //     //if it does not pass as an integer, the steps are counted
            //     char breakerCharacter[] = "D";
            //     printf("The line being tested for is : %s \n", string);
            //     steps = strcspn(string, breakerCharacter);
            //     printf("The steps before fall are :  %d\n \n", steps);

            //     }
            //}
            
        //}



        //     printf("new line now  , \n");


        printf("\n \n and we are done!!");

        fclose(filePointer);
        return 0;
        }


};
void string_split(char *s , int index , char *first, char *second){
    int length = strlen(s);

    if(index<length){
        for (int k=0;k<index;k++){
            first[k]=s[k];
        }
        first[index]='\0';

        for(int k =index;k<length;k++){
            second[k-index]=s[k];
        }
        
        second[length-1]='\0';
        
    }
}