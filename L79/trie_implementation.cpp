// implementation of trie data structure:
#include <iostream>
using namespace std;

// defining the Node of a trie:
class TrieNode
{
public:
    // properties:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    // constructor:
    TrieNode(char ch)
    {
        data = ch;
        isTerminal = false;
        // initialising its children as NULL;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

// defining a class for trie DS *(only insert small letter):
class trie
{
public:
    // making a root node:
    TrieNode *root;

    // constructor
    trie()
    {
        root = new TrieNode('\0'); // Initialize root with a dummy value
    }

    // function to insert a new word:

    void insertWord(string word)
    {
        // passing the word to a utility function that will add the word to the trie recursively:
        insertUtil(root, word);
    }
    void insertUtil(TrieNode *root, string word)
    {
        // base case:
        if (word.length() == 0)
        {
            // marking the current root node as terminal node :
            root->isTerminal = true;
            return;
        }

        // index to insert the current letter:
        int index = word[0] - 'a';
        // if the current letter is present:
        if (root->children[index] != NULL)
        {
            // recursive call to add next letter:
            insertUtil(root->children[index], word.substr(1));
        }
        // if the current letter is not present:
        else
        {
            // create a new Trienode:
            TrieNode *newNode = new TrieNode(word[0]);
            root->children[index] = newNode;
            // recursive call to add next letter:
            insertUtil(newNode, word.substr(1));
        }
    }

    // function to search:
    void searchWord(string word)
    {
        if (searchUtil(root, word) == true)
        {
            cout << word << " is present" << endl;
        }
        else
        {
            cout << word << " not present" << endl;
        }
    }
    bool searchUtil(TrieNode *root, string word)
    {
        // base case:
        if (word.length() == 0)
        {
            // if it is a terminal node then only return true:
            return root->isTerminal;
        }

        // index of current letter:
        int index = word[0] - 'a';

        // if the current letter is present in the children of current node:
        if (root->children[index] != NULL)
        {
            // recursive function to search next letter:
            return searchUtil(root->children[index], word.substr(1));
        }
        // if the currentletter is not present:
        {
            return false;
        }
    }

    // function to delete a word:
    /* JUST SEARCH FOR THE WORD, AND WHEN FOUND , CHANGE ITS TERMINAL NODE TO FALSE. */
};

int main()
{
    trie t;

    t.insertWord("atom");
    t.insertWord("at");
    t.insertWord("bat");
    t.insertWord("cat");
    t.insertWord("come");

    t.searchWord("hello");
    t.searchWord("atom");
    t.searchWord("at");
    t.searchWord("bat");
    t.searchWord("cat");
    t.searchWord("come");
}
