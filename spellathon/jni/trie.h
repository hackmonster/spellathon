
using namespace std;
#define NUM_ELEMENTS 26

#define text2index(a) a-'a'

struct node
{
	node *child[NUM_ELEMENTS];
	bool isLeaf;
};
node *getNewNode();
class Trie
{
	node *root;
	public:
		Trie();
		void setLeaf(node *nodeToSet);
		bool getLeaf(node *nodeToSet);
		void insertWord(string word);
		bool searchWord(string word);
};
