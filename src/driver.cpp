//
// Created by Siddheshwar Sharma on 11/06/17.
//

#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <math.h>
#include <vector>
#include <trie.h>
using namespace std;

#define MAXLEN 7
#include <stdbool.h>


Trie T;
vector<string> solution_space;
vector<string>::iterator it;

int compare(const void *a, const void * b)
{
    return ( *(char *)a - *(char *)b );
}

void swap(char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

// This function finds the index of the smallest character
// which is greater than 'first' and is present in str[l..h]
int findCeil(char str[], char first, int l, int h)
{
    // initialize index of ceiling element
    int ceilIndex = l;

    // Now iterate through rest of the elements and find
    // the smallest character greater than 'first'
    for (int i = l+1; i <= h; i++)
        if (str[i] > first && str[i] < str[ceilIndex])
            ceilIndex = i;

    return ceilIndex;
}

// Print all permutations of str in sorted order
void sortedPermutations(char str[])
{
    // Get size of string
    int size = strlen(str);

    // Sort the string in increasing order
    qsort(str, size, sizeof( str[0] ), compare);

    // Print permutations one by one
    bool isFinished = false;
    while (!isFinished)
    {
 		if(T.searchWord(str))
 		{
    		//cout<<str<<endl;
    		string temp = str;
    		//cout<<endl<<temp;
    		bool flag = false;
    		if(solution_space.size()==0)
    		{
    			solution_space.push_back(temp);
    			//cout<<"\tValid";
    		}
    		else
    		{
    			for(it = solution_space.begin(); it!=solution_space.end(); it++)
    				if(temp.compare(*it)==0)
    				{
    					flag = true;
    					break;
    				}
    			if(!flag)
    			{
    				//cout<<"\tValid";
		    		solution_space.push_back(temp);
		    	}
		    	//else
		    		//cout<<"\tInvalid";
		    }
    		//return str;
    	}
        // Find the rightmost character which is smaller than its next
        // character. Let us call it 'first char'
        int i;
        for (i = size - 2; i >= 0; --i)
            if (str[i] < str[i+1])
                break;

        // If there is no such chracter, all are sorted in decreasing order,
        // means we just printed the last permutation and we are done.
        if (i == -1)
            isFinished = true;
        else
        {
            // Find the ceil of 'first char' in right of first character.
            // Ceil of a character is the smallest character greater than it
            int ceilIndex = findCeil(str, str[i], i + 1, size - 1);

            // Swap first and second characters
            swap(&str[i], &str[ceilIndex]);

            // Sort the string on right of 'first char'
            qsort(str + i + 1, size - i - 1, sizeof(str[0]), compare);
        }
    }
}

void printPowerSet(char *set, int set_size)
{
    /*set_size of power set of a set with set_size
      n is (2**n -1)*/
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;
 
    /*Run from counter 000..0 to 111..1*/
    for(counter = 0; counter < pow_set_size; counter++)
    {
      char *s = new char[MAXLEN];
      int index = 0;
      for(j = 0; j < set_size; j++)
       {
          /* Check if jth bit in the counter is set
             If set then pront jth element from set */
          if(counter & (1<<j))
          {
            s[index++] = set[j];
            //printf("%c", set[j]);
    	  }
       }
       s[index]='\0';
       string st = s;
       if(st.length()>3 && st.length()<8 && st.find(set[0])!=string::npos)
	       sortedPermutations(s);
           //solution_space.push_back(st);
    }
}
//assume for now that 1st character of 
//jumbledWord is the ROOT character
void genPermAndSearch(char *jumbleWord)
{
	int wordLen = 7;//jumbleWord.length()
	printPowerSet(jumbleWord, wordLen);
}

void train()
{
	ifstream input("/data/words_eng.txt");
	string train_string;
    if(!input)
        cout<<"\nFailed to load dictionary";
    while(input >> train_string)
    {
        int i=0;
        char *str = new char[100];
        do{
        	str[i] = tolower(train_string[i]);
        }while(str[i++]!='\0');
    	T.insertWord(str);
    	delete[] str;
    }
}

int main(int argc, char **argv)
{    
	train();
    genPermAndSearch(argv[1]);
	if(solution_space.size()==0)
		cout<<"\nNo solution";
	else
		for(it = solution_space.begin(); it!= solution_space.end(); it++)
    		cout<<endl<<*it;
    cout<<endl;
	return 0;
}

