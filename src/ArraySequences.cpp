/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	if (arr && len > 0)
	{
		int i = 0, start = 0, end = 0, final[6] = { 0 },c=0,gp = 0;
		for (i = 0; i < len; i++)
		{
			if ((arr[i + 1] - arr[i]) == (arr[i + 2] - arr[i + 1]))
			{
				end = i + 1;
			}
			else if (gp)
			{
				if ((arr[i] / arr[i + 1]) == (arr[i + 1] / arr[i + 2]))
				{
					end = i + 1;
				}
				else
				{
					gp = 0;
					if (start != end)
					{
						end = i;
						final[c++] = start;
						final[c++] = end;
					}
				}
			}
			else
			{
				gp = 1;
				if(start!=end){
					end = i + 1;
					final[c++] = start;
					final[c++] = end;
					start = i + 1;
					i = start-1;
					
				}
			}
		}
	}
	return NULL;
}