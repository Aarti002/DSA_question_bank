#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next,*prev;
    Node(int d): data(d), next(nullptr), prev(nullptr) {};
};

class LRUCache{
    private:
        unordered_map<int,Node*> cache;
        Node *head,*tail;
        int capacity,count;
    public:
        LRUCache(int size){
            head=new Node(-1);
            tail=new Node(-1);
            head->next=tail;
            tail->prev=head;
            this->capacity=size;
            count=0;
        }

        void put(int data) {
            // Check if data already exists in the cache
            if (cache.find(data) != cache.end()) {
                Node* delNode = cache[data];
                removeNode(delNode);
                cache.erase(data); // Remove the entry from the map
            }

            Node* newNode = new Node(data);
            Node* shiftNode = head->next;
            head->next = newNode;
            newNode->prev = head;
            newNode->next = shiftNode;
            shiftNode->prev = newNode;
            cache[data] = newNode;

            // Check cache size
            if (count == capacity) {
                Node* delNode = tail->prev;
                removeNode(delNode);
                cache.erase(delNode->data); // Remove the entry from the map
                count--;
            }
            count++;
        }

        void removeNode(Node *delNode){
            delNode->next->prev=delNode->prev;
            delNode->prev->next=delNode->next;
        }

        int get(int data){
            if(cache.find(data)!=cache.end()){
                //put(data);
                return data;
            }
            return -1;
        }

        void displayCache(){
            Node *currNode=head->next;
            while(currNode->next!=NULL){
                cout<<currNode->data<<" ";
                currNode=currNode->next;
            }
        }
};

int main(){
    LRUCache *obj=new LRUCache(6);
    obj->put(2);
    obj->put(21);
    obj->put(102);
    obj->put(23);
    obj->put(12);
    obj->put(234);
    obj->put(121);
    obj->put(4);
    int temp=obj->get(2);
    if(temp!=-1){
        cout<<"Present"<<endl;
        obj->put(temp);
    }
    else 
        cout<<"Absent"<<endl;
    obj->displayCache();
    return 0;
}