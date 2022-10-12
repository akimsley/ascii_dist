/* ===================================
 *	ASCII TEXT ALIGN EFFECT 
 *====================================
 * prints a text file and distorts the even lines
 * to create a distortion effect
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//=-=-= FUNCTION MEAT -=-=-=
void align_text()
{
	int i;


	system("tput clear");

	//-------- line counting stage ---------
	FILE *fptr = fopen("txt_input", "r");
	int ch = 0;
	int lines = 0;

	//loop to count number of lines in document
	while(!feof(fptr))
	{
	      	ch = fgetc(fptr);
		if(ch == '\n')
 		{
			lines++;
       		}	
	}
	//-------- line counting stage ---------


	rewind(fptr); //reset file pointer 
	int curr_line = 0; //current line	

	//-------- first print iteration -------
	char buffer[1000];
	while(fgets(buffer, 1000, fptr) != NULL)
	{
		if(curr_line % 2 == 0)
		{
			printf("\t");
		}
		
		printf("\t%s", buffer);	
		curr_line++;
	}	
	//-------- first print iteration -------
	
	rewind(fptr); //rewind file pointer
	curr_line = 0; //reset current line
	usleep(110000); //wait for next print


	system("tput clear");

	//-------- second print iteration ------
	while(fgets(buffer, 1000, fptr) != NULL)
	{
		//*** this iteration only adds a tab on the odd lines ***
		if(curr_line % 2 != 0)
		{
			printf("\t");
		}
		
		printf("%s", buffer);	

		curr_line++;
	}
	//-------- second print iteration ------


	rewind(fptr); //rewind file pointer
	usleep(110000); //wait for next iteration
			//
			//
	system("tput clear");

	//-------- final print iteration -------
	while(fgets(buffer, 1000, fptr) != NULL)
	{
		printf("\t%s", buffer);	
	}	
	//-------- final print iteration -------

}
//=-=-= FUNCTION MEAT -=-=-=


//=-=-= MAIN FUNCTION -=-=-=
int main()
{

	align_text();

	return 0;
}
//=-=-= MAIN FUNCTION -=-=-=
