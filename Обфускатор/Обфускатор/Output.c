#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

int fun34() 
{ 
char fun44[30], fun54[30]; 
FILE *fun64; 
fopen_s(&fun64, "password.txt", "r"); 
fscanf_s(fun64, "%s", &fun44, 30); 
fclose(fun64); 
printf("Hello! Enter password:\n\r"); 
scanf_s("%s", &fun54, 30); 
if (strcmp(fun54, fun44)) 
return 0; 
else 
return 1; 
} 

int main() 
{ 
if (!fun34()) 
{ 
perror("Nice try."); 
abort(); 
} 
else 
printf("Nice to see you."); 
getchar(); 
getchar(); 
return 0; 
}