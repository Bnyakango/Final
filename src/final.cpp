/**
 * @file final.cpp
 * @brief This is a test of CMake, doxygen, and GitHub.
 * @details This is the long brief at the top of main.cpp.
 * @author Benson Nyakango and Scott Gillis
 * @date 5/5/2021
 * 
 */

#include <bits/stdc++.h>
using namespace std;

string contactList[] = {"Seth", "Scott","Benson"};
struct TrieNode
{
    unordered_map<char,TrieNode*> child;
    bool lastLetter;
    TrieNode()
    {
        for (char i = 'a'; i <= 'z'; i++)
            child[i] = NULL;
        lastLetter = false;
    }
};

TrieNode *root = NULL;

void AddContact(string s)
{
    int length = s.length();
    TrieNode *head = root;
    for (int i = 0; i < length; i++)
    {
        TrieNode *nextNode = head->child[s[i]];
        if (nextNode == NULL)
        {      
            nextNode = new TrieNode();  
            head->child[s[i]] = nextNode;
        }
        
        head = nextNode;
        if (i == length - 1)
            head->lastLetter = true;
    }
}

void showContactsTil(TrieNode *currentNode, string pre)
{
    if (currentNode->lastLetter)
        cout << pre << endl;
   for (char i = 'a'; i <= 'z'; i++)
    {
        TrieNode *next = currentNode->child[i];
        if (next != NULL)
            showContactsTil(next, pre + (char)i);
    }
}

void showContacts(string str)
{
    TrieNode *previousNode = root;
    string pre = "";
    int length = str.length();
    int i;
    for (i=0; i<length; i++)
    {
        pre += (char)str[i];
        char lastChar = pre[i];
        TrieNode *currentNode = previousNode->child[lastChar];
        if (currentNode == NULL)
        {
            cout << "No result found "<<" " << pre
                 << endl;
            i++;
            break;
        }

        cout << "Suggesions for" <<" "<< pre<<" "
             << "are "<< endl;
        showContactsTil(currentNode, pre);
        previousNode = currentNode;
    }
    for (; i<length; i++)
    {
        pre += (char)str[i];
        cout << "No contact found for"<<" " << pre
             << endl;
    }
}
// Insert all the Contacts into the Trie
void insertInDirectory(string contacts[],int n)
{
    root = new TrieNode();
    for (int i = 0; i < n; i++)
        AddContact(contacts[i]);
}
int main()
{
    int n = sizeof(contactList)/sizeof(string);
    insertInDirectory(contactList, n);
    string Search;
    cout << "Search: ";
    cin >> Search;
    cout << "Results: " << Search << endl;
    showContacts(Search);
    return 0;
}

