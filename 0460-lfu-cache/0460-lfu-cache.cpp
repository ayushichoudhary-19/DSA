class LFUCache {
public:
    class node{
        public:
        int key;
        int value;
        int freq;
        node* next;
        node* prev;
        node(int _key, int _value){
            key=_key;
            value=_value;
            freq=1;
        }
    };
    class List {
        public:
        int size;
        node* head;
        node* tail;
        List(){
            head = new node(0,0);
            tail = new node(0,0);
            head->next=tail;
            tail->prev=head;
            size=0;
        }
        void addFront(node* newnode){
                node* temp= head->next;
                head->next = newnode;
                newnode->next = temp;
                newnode->prev= head;
                temp->prev=newnode;
                size++;
        }
        void deleteNode(node *delnode){
                node* delprev=delnode->prev;
                node* delnext=delnode->next;
                delprev->next=delnext;
                delnext->prev=delprev;
                size--;
        }
    };

        map<int, node*> keyNodeMap;
        map<int, List*> freqListMap;
        int maxSize;
        int minFreq;
        int currSize;
    
    LFUCache(int capacity) {
        maxSize=capacity;
        minFreq=0;
        currSize=0;
    }

    void updateFreqListMap(node* somenode){
        keyNodeMap.erase(somenode->key);
        List* listAtThisFreq = freqListMap[somenode->freq];
        listAtThisFreq->deleteNode(somenode);
        //if this was only node for that minFreq
        if(somenode->freq==minFreq && listAtThisFreq->size==0){
            minFreq++;
        }

        List* nextHigherFreqList = new List();
        //if in map next freq exists then
        if(freqListMap.find(somenode->freq + 1) != freqListMap.end()){
            nextHigherFreqList = freqListMap[somenode->freq + 1];
        }
        somenode->freq +=1;
        nextHigherFreqList->addFront(somenode);
        freqListMap[somenode->freq] = nextHigherFreqList;
        keyNodeMap[somenode->key] = somenode;
    }
    
    int get(int key) {
        if(keyNodeMap.find(key)!=keyNodeMap.end()){
            node* getnode = keyNodeMap[key];
            int res = getnode->value;
            updateFreqListMap(getnode);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSize==0) return;

        if(keyNodeMap.find(key)!=keyNodeMap.end()){
            node* newnode=keyNodeMap[key];
            newnode->value=value;
            updateFreqListMap(newnode);
        }
        //means this is a brand new key so freq will be 1 
        else{
            //if cap is reached delete something before adding this
            if(maxSize==currSize){
                List* leastFreqList = freqListMap[minFreq];
                //delete least freq's least recently used mode
                keyNodeMap.erase(leastFreqList->tail->prev->key);
                freqListMap[minFreq]->deleteNode(leastFreqList->tail->prev);
                currSize--;
            }
            //since this is a brand new node it's freq is 1 
            //if already minFreq 1 exists update that with this node
            //else make new list for 1 freq;
            minFreq=1;
            List* listFreq = new List();
            if(freqListMap.find(minFreq)!=freqListMap.end()){
                listFreq = freqListMap[minFreq];
            }
            node* newnode = new node(key,value);
            listFreq->addFront(newnode);
            keyNodeMap[key]=newnode;
            freqListMap[minFreq] = listFreq;
            currSize++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */