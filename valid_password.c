#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool checker(char pass[25]){
    int checks = 0; // Total 4 checks will be performed
    char Special_chars_list[] = {'!','@','#','$','%','&','*'};
    int Num_list[] = {'1','2','3','4','5','6','7','8','9','0'};
    bool uppr = true;
    bool spcl = true;
    bool nm = true;

    // check 1 (Check if password has any uppercase char)
    for(int i=0; i<=strlen(pass)-1; i++){
        if(isupper(pass[i]) && uppr ){
            checks+=1;
            printf("\ncheck 1 passed - one uppercase letter found");
            uppr = false;
            
            
        }
        // check 2 - (if the password contains special chars)
        for(int j=0; j<=6; j++){
            if(pass[i]==Special_chars_list[j] && spcl){
                checks+=1;
                printf("\ncheck 2 passed - spl char found");
                spcl = false;
                break;
            }
        }
        // check 3 - (If password contains a number)
        for(int k=0; k<=9; k++){
            if(pass[i]==Num_list[k] && nm){
                checks+=1;
                printf("\ncheck 3 passed - number found in password");
                nm = false;
                break;
            }
        }
    }

    // check 4 (check if password is of minimum 8 chars)
    if(strlen(pass)<8){
    }
    else{
        checks+=1;
        printf("\ncheck 4 passed - password is more than 8 characters");
    }

    

    printf("\nTotal checks passed: %d",checks);
    
    if(checks==4){
        return false;
    }

}

int main(){
    
    char pass[25];
    bool error;

    do{
        printf("\nEnter a password of minimum 8 characters (including 1uppercase 1special character 1number)\n:");
        scanf("%s",&pass);

        // check for password validity
        error = checker(pass);

        if(error){
            printf("\nError invalid password, password doesn't meet the required format specified!");
        }
        else{
            printf("\npassword stored succesfully!");
        }
    }while(error);

    return 0;
}