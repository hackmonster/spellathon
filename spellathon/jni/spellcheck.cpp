//
// Created by Siddheshwar Sharma on 11/06/17.
//
#include <jni.h>
#include <string.h>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <jni.h>
#include <fstream>
using namespace std;

#define MAXLEN 7
#include <stdbool.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
static int count = 0;
// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));

    if (pNode)
    {
        int i;

        pNode->isLeaf = false;

        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }

    return pNode;
}
TrieNode *T = getNode();

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, char *key)
{
    int level;
    int length = strlen(key);
    int index;

    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isLeaf = true;
}

// Returns true if key presents in trie, else false
bool search(struct TrieNode *root, char *key)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;

    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);

        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    return (pCrawl != NULL && pCrawl->isLeaf);
}

/* Following function is needed for library function qsort(). */
int compare(const void *a, const void * b)
{
    return ( *(char *)a - *(char *)b );
}

// A utility function two swap two characters a and b
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
string sortedPermutations(char str[])
{
    // Get size of string
    int size = strlen(str);

    // Sort the string in increasing order
    qsort(str, size, sizeof( str[0] ), compare);

    // Print permutations one by one
    bool isFinished = false;
    while (!isFinished)
    {
        // print this permutation
        static int x = 1;
        //printf("%d  %s \n", x++, str);
 		if(search(T, str))
 		{
    		//cout<<str<<endl;
    		return str;
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
    return NULL;
}

string solve(string s)
{
    char *str = new char[100];
    int i=0;
    do{
     	str[i] = tolower(s[i]);
    }while(str[i++]!='\0');
    s = sortedPermutations(str);
    return s;
}

// Print all permutations of str in sorted order
void sortedPermutations1(char str[], string *list)
{
    // Get size of string
    int size = strlen(str);

    // Sort the string in increasing order
    qsort(str, size, sizeof( str[0] ), compare);

    // Print permutations one by one
    bool isFinished = false;
    while (!isFinished)
    {
        // print this permutation
        static int x = 1;
        //printf("%d  %s \n", x++, str);
 		if(search(T, str))
 		{
    		//cout<<str<<endl;
    		list[count++] = str;
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

void solve1(string s, string *list)
{
    char *str = new char[100];
    int i=0;
    do{
     	str[i] = tolower(s[i]);
    }while(str[i++]!='\0');
    sortedPermutations1(str, list);
    delete[] str;
}

int train()
{
	ifstream input("/data/words_eng.txt");
    string train_string;
    if(input==NULL)
        return 1;
    while(input >> train_string)
    {
        int i=0;
        char *str = new char[100];
        do{
        	str[i] = tolower(train_string[i]);
        }while(str[i++]!='\0');
        //cout<<"inserting : "<<str<<endl;
    	insert(T, str);
    }
    return 0;
}

int main(int argc, char **argv)
{
	train();
	for(int i=1; i<=10; i++)
	{
		string s = argv[i];
    	cout<<solve(s)<<endl;
	}
	//sortedPermutations( s );
    cout<<endl<<"------------"<<endl;
    return 0;
}


extern "C"
{
jint Java_com_example_sidsharma_spellathon_MainActivity_train(JNIEnv *env, jobject obj)
{
    int err = train();
    return err;
}
jstring Java_com_example_sidsharma_spellathon_MainActivity_spell(JNIEnv *env, jobject obj, jstring jumbled)
{
        int err = 0;//train();
        if(err)
            return env->NewStringUTF("dictionary not found");
        else
        {
        	int i=0;
            const char *st;
            st = env->GetStringUTFChars(jumbled, NULL);

        	char ch[100];
            string s = solve(st);
    	    i=0;
    	    while(s[i]!='\0')
    	        ch[i] = s[i], i++;
    	    ch[i] = '\0';
    	    return env->NewStringUTF(ch);
    	}

}
jobjectArray Java_com_example_sidsharma_spellathon_MainActivity_spellList(JNIEnv *env, jobject obj, jstring jumbled)
{
    jobjectArray ret;

    const char *st;
    st = env->GetStringUTFChars(jumbled, NULL);
    char *ch[100];
    count = 0;
    string *list = new string[100];

    solve1(st, list);
    for(int i=0; i<count; i++)
    {
        int j=0;
        for(j=0; j<list[i].length(); j++)
            ch[i][j] = list[i][j];
        ch[i][j] = '\0';
    }
    ret= (jobjectArray)env->NewObjectArray(5,env->FindClass("java/lang/String"),env->NewStringUTF(""));

    for(int i=0;i<count;i++)
        env->SetObjectArrayElement(ret,i,env->NewStringUTF(ch[i]));
    return(ret);

}
}