/*
* Recitation Section Number: 
* Breakout Number:
* Member Name
* Member Name
* Member Name
* Member Name
*/


#include<stdio.h>
#include <stdlib.h> // For exit() 


int main() {

	//STEP 1
	//Your code to open the file copy the file and close the file
	FILE* fread = fopen("sample.txt", "r");
	FILE* fwrite = fopen("sample_copy.txt", "w");
	int bufsize = 30;
	char str[bufsize];
	fgets(str, bufsize, fread);
	fputs(str, fwrite);

	//STEP 2
	//Your code to read the text and add the numbers 
	char* text = "sample text 2 4 5";
	int a=0, b=0, c=0;
	char* waste1; char* waste2;
	sscanf(text, "%s %s %d %d %d", &waste1, &waste2, &a, &b, &c);
	printf("%d\n", a+b+c);

	return 0;

}