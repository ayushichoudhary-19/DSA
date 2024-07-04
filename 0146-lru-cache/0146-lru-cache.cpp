class LRUCache {
public:
    class node {
        public:
            int key;
        int value;
        node *prev;
        node* next;
        node(int _key, int _value){
            key= _key;
            value= _value;
        }
    };
    node* head= new node(-1,-1);
    node* tail= new node(-1,-1);

    int cap;

    unordered_map<int,node*> map;

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addNode(node *newnode){
        node * temp = head->next;
        newnode->next=temp;
        head->next=newnode;
        newnode->prev=head;
        temp->prev=newnode;
    }
    void deleteNode(node* delnode){
        node* delprev=delnode->prev;
        node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int get(int key) {
        if(map.find(key) !=map.end())
        {
            node* getnode=map[key];
            int res = getnode->value;
            map.erase(key);
//now this is most recently used so delete last occurance and readd as latest used
            deleteNode(getnode);
            addNode(getnode);
            map[key]=head->next;
            return res;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            //new entry with this key so delete the old entry
            node* existingnode = map[key];
            map.erase(key);
            deleteNode(existingnode);
        }
        if(map.size()==cap){
            int delkey=tail->prev->key;
            map.erase(delkey);
            deleteNode(tail->prev);
        }
        node* newnode = new node(key,value);
        addNode(newnode);
        map[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */