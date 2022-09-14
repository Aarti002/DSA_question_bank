#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

struct trie{
    trie *a[26];
    bool flag;

    bool isPresent(char ch)
    {
        return (a[ch-'a']!=NULL);
    }

    trie* getNode(char ch)
    {
        return a[ch-'a'];
    }

    void putNode(char ch,trie *node)
    {
        a[ch-'a']=node;
    }

    void setEnd()
    {
        flag=true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie{
    trie *root;
    public:
    Trie()
    {
        root=new trie;
    }

    void insertWord(string word)
    {
        trie *node=root;
        for(int i=0;i<word.length();i++)
        {
            if(node->isPresent(word[i])==false)
            node->putNode(word[i],new trie);
            node=node->getNode(word[i]);
        }
        node->setEnd();
    }

    bool searchWord(string word)
    {
        trie *node=root;
        for(int i=0;i<word.length();i++)
        {
            if(node->isPresent(word[i])==false)
            return false;
            node=node->getNode(word[i]);
        }
        return node->isEnd();
    }

    bool isPrefix(string prefix)
    {
        trie *node=root;
        for(int i=0;i<prefix.length();i++)
        {
            if(node->isPresent(prefix[i])==false)
            return false;
            node=node->getNode(prefix[i]);
        }
        return true;
    }

    void deleteWord(string word)
    {
        trie *temp=root;
        for(int i=0;i<word.length();i++)
        {
           
            temp=temp->getNode(word[i]);
        }
        temp->flag=false;
    }


};

int main()
{
    int n,i;
    Trie root;
    root.insertWord("apple");
    root.insertWord("apps");
    cout<<"Is there any word whose prefix is 'apt':"<<root.isPrefix("apt")<<endl;
    cout<<"Is there any word whose prefix is 'ap':"<<root.isPrefix("ap")<<endl;
    cout<<"Is there any word 'apps':"<<root.searchWord("apps")<<endl;
    root.deleteWord("apps");
    cout<<"Is there any word 'apps':"<<root.searchWord("apps")<<endl;
    return 0;
    

}