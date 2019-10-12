#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int hasString(FILE *fp, char *str) {
	
	char buf[1000];
	
	while(fgets(buf, 512, fp) != NULL) {
		printf("%s", buf);
		if((strstr(buf, str)) != NULL) {
			// the file has the string
			return 1;
		}
	}
	return 0;
}


int main(void) {	

	char fname[] = "PE-1.txt";
	char str[] = "I want to learn PE file format!";
	FILE *fp;
	
	if(access(fname, F_OK) != -1 ) {
		// file exists		
		// opens the file to update both reading and writing
		fp = fopen(fname, "r+");
		
		if (hasString(fp, str) == 1) {
			// file has the string
			
			// print the content
			// read contents from file 
    		char c = fgetc(fp); 
    		while (c != EOF) { 
        		printf ("%c", c); 
        		c = fgetc(fp); 
    		} 
		}
		else {
			// file does not have the string			
			// append the string in the file
			fprintf(fp, "%s", str);
		}
		
		// close the file
		fclose(fp);
	}
	else {
		// file does not exist
		// creates an empty file for both reading and writing
		fp = fopen(fname, "w+");
		// write the string in the file.
		fprintf(fp, "%s", str);
	}

	return 0;
}
