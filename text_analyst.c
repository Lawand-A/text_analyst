//Analyze the letters and digits in your text

#include <stdio.h>



void counting_letters (){
    int nletter[26]; 
    int i = 0, letter = 0; 
    int sum_vol = 0, sum_cons = 0;
    int line = 0;
    int big_letter= 0, small_letter = 0; 
    int j = 0, digit = 0;
    int ndigit[10]; 
 
    while (i < 26) { 
        nletter[i] = 0; 
        i++; 
    } 
    
    while (j < 10) { 
        ndigit[j] = 0; 
        j++; 
    } 
    
    FILE  *myFile = fopen("yourText.txt","r");
    
    while ((i  = fgetc(myFile) ) != EOF) { //While not End Of File
    
         if (i >= 'a' && i <= 'z') { 
              nletter[i - 'a']++; 
              letter++;
              small_letter++;
              if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u'){
                  sum_vol++;
              } else if(!(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')){
                  sum_cons++;
              }         
         } else if (i >= 'A' && i <= 'Z'){
              nletter[i - 'A']++; 
              letter++;
              big_letter++;             
              if (i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U'){
                  sum_vol++;
              } else if(!(i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U')){
                  sum_cons++;
              }         
         } else if (i == '\n'){
             line++;         
         } else if (i >= '0' && i <= '9') { 
              ndigit[i - '0']++; 
              digit++;
         }         
    } 
    
    i=0;   
    printf("=== Digit analysis ===\n\nNumber of repetitions\n");
    
    while (i < 10) { 
         printf("The %d: %3d times\n", i, ndigit[i]); 
         i++; 
     } 
     
    printf("\n== The number of digits in your text is (%d) ==\n\n========================================\n\n", digit);
     
    i = 0; 	
    	
    printf("=== Letter analysis ===\n\nNumber of repetitions\n");
    
    while (i < 26) { 
         printf("The %c: %3d times\n", i+65, nletter[i]); 
         i++; 
     } 
     
     printf("\n=== Details ===\nThere are %d vowels in your text \nThere are %d consonants in your text \nThere are %d capital letters in your text \nThere are %d small letters in your text \nThere are %d letters in your text \nThere are %d lines in your text \n=========================================\n\n", sum_vol, sum_cons, big_letter, small_letter ,letter, line);
     
     
     fclose(myFile);
}



int main(void) { 

printf("\n======================================================================================\n==     ##   #    #   ##   #      #   # ###### ######    ##### ###### #    # #####   ==\n==    #  #  ##   #  #  #  #       # #      #  #           #   #       #  #    #     ==\n==   #    # # #  # #    # #        #      #   #####       #   #####    ##     #     ==\n==   ###### #  # # ###### #        #     #    #           #   #        ##     #     ==\n==   #    # #   ## #    # #        #    #     #           #   #       #  #    #     ==\n==   #    # #    # #    # ######   #   ###### ######      #   ###### #    #   #     ==\n======================================================================================\n\n\n");                                                     

    counting_letters();
    
    return 0;  
} 	
