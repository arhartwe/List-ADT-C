/* 
 * Name		: Andrew Hartwell
 * CruzID	: arhartwe
 * Assignment	: pa2
*/ 


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"List.h"

#define MAX_LEN 160

int main(int argc, char * argv[]){

	FILE *in, *out;
	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w");
	List indices = newList();
	char *words[MAX_LEN];
	char  lineArray[MAX_LEN];
	int i = 0;
	
	if(argc != 3)
	{
		printf("Usage %s <input file> <output file>\n", argv[0]);
		exit(1);
	}
	
	// open files for reading and writing
	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w");

	if(in == NULL)
	{
		printf("Unable to open file %s for reading\n", argv[1]);
		exit(1);
	}
	if(out == NULL)
	{
		printf("Unable to open file %s for writing\n", argv[2]);
		exit(1);
	}
	
	while(fgets(lineArray, MAX_LEN, in) != NULL) // Place input file strings into array
	{
		words[i] = malloc(sizeof(char) * strlen(lineArray));
		strcpy(words[i], lineArray);
		i++;	
	}

	append(indices, 0);
	
	for(int j = 1; j < i; j++) // Indirectly sorts strings using List ADT
	{
		moveFront(indices);
		
		while(strcmp(words[j], words[get(indices)]) > 0)
		{
			if(length(indices) == 1)
			{
				append(indices, j);
			}
			if(length(indices) == (index(indices) + 1))
			{
				append(indices, j);
			}
			moveNext(indices);
		}
		if(strcmp(words[j],words[get(indices)]) < 0)
		{
			insertBefore(indices, j);
		}
	}


	
	moveFront(indices);
	int x;
	
	while(index(indices) >= 0) // Prints alphabetized strings to output file
	{
		x = get(indices);
		fprintf(out, "%s", words[x]);
		moveNext(indices);
	}

	fclose(in);
	fclose(out);
	freeList(&indices);
	for(int k = 0; k < i; k++)
	{
		free(words[k]);
	}	
	free(*words);	
	

}

