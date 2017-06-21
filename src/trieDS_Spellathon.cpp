#include <iostream>
#include <stdio.h>
#include <fstream>
#include "trie.h"
using namespace std;
node *getNewNode()
{
	node *newNode = new node();
	for(int i=0; i<NUM_ELEMENTS; i++)
		newNode->child[i] = NULL;
	newNode->isLeaf = false;
	return newNode;
}
Trie::Trie()
{
	root = getNewNode();
}
void Trie::setLeaf(node *nodeToSet)
{
	nodeToSet->isLeaf = true;
}
bool Trie::getLeaf(node *nodeToSet)
{
	return nodeToSet->isLeaf;
}
/*
	PS : insert only lowercase letters
*/
void Trie::insertWord(string word)
{
	node *pos = root;
	for(int i=0; i<word.length(); i++)
	{
		int index = text2index(word[i]);
		if(pos->child[index] == NULL)
			pos->child[index] = getNewNode();
		pos = pos->child[index];
	}
	setLeaf(pos);//->isLeaf = true;
}

bool Trie::searchWord(string word)
{
	node *pos = root;
	for(int i=0; i<word.length(); i++)
	{
		int index = text2index(word[i]);
		if(pos->child[index]!=NULL)
			pos = pos->child[index];
		else
			return false;
	}
	return (pos!=NULL && getLeaf(pos));
}
