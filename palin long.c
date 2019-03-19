# palindromelong
#include<iostream.h>
#include <stdlib.h> 
#include <string.h> 
  
using namespace std; 
  
/* function to find and print the longest common  
   substring of X[0..m-1] and Y[0..n-1] */
void printLCSubStr(char* X, char* Y, int m, int n) 
{ 
    int LCSuff[m + 1][n + 1]; 
    int len = 0;
    int row, col; 
  
    /* Following steps build LCSuff[m+1][n+1] in bottom 
       up fashion. */
    for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 
            if (i == 0 || j == 0) 
                LCSuff[i][j] = 0; 
  
            else if (X[i - 1] == Y[j - 1]) { 
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1; 
                if (len < LCSuff[i][j]) { 
                    len = LCSuff[i][j]; 
                    row = i; 
                    col = j; 
                } 
            } 
            else
                LCSuff[i][j] = 0; 
        } 
    } 
    if (len == 0) { 
        cout << "No Common Substring"; 
        return; 
    } 
    char* resultStr = (char*)malloc((len + 1) * sizeof(char)); 
      while (LCSuff[row][col] != 0) { 
        resultStr[--len] = X[row - 1];
         row--; 
        col--; 
    } 
        cout << resultStr; 
} 
  int main() 
{ 
    char X[] = "OldSite:GeeksforGeeks.org"; 
    char Y[] = "NewSite:GeeksQuiz.com"; 
  
    int m = strlen(X); 
    int n = strlen(Y); 
  
    printLCSubStr(X, Y, m, n); 
    return 0; 
} 
