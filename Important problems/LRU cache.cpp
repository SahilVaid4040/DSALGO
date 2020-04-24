class node{
    public:
    int key;
    int val;
    node* next;
    node* prev;
    node(int k,int v):key(k),val(v),prev(NULL),next(NULL){}
};
class DoublyLinkedList{
    node* front;
    node* rear;
    bool isEmpty(){
        return rear==NULL;
    }
    public:
    DoublyLinkedList():front(NULL),rear(NULL){}
    node* add(int key,int val){
        node* page = new node(key,val);
        //list empty
        if(!front && !rear){
            front=rear=page;
        }
        else{
            page->next = front;
            front->prev = page;
            front = page;
        }
        return page;
    }
    void move(node* page){
        if(page==front){
            return;
        }
        if(page==rear){
            rear = rear->prev;
            rear->next=NULL;
        }
        else{
            page->prev->next= page->next;
            page->next->prev = page->prev;
        }
        page->next= front;
        page->prev=NULL;
        front->prev = page;
        front=page;       
    }
    void remove(){
        if(isEmpty()){
            return;
        }
        if(front==rear){
            delete rear;
            front=rear=NULL;
        }
        else{
            node* temp = rear;
            rear = rear->prev;
            rear->next=NULL;
            delete temp;
        }
    }
    node* get_rear(){
        return rear;
    }
    
};
class LRUCache {
int capacity,size;
DoublyLinkedList* pagelist;
unordered_map<int,node*>pagemap;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size=0;
        pagelist = new DoublyLinkedList();
        pagemap = unordered_map<int,node*>();
    }
    
    int get(int key) {
        if(pagemap.find(key)==pagemap.end()){
            return -1;
        }
        int val = pagemap[key]->val;
        pagelist->move(pagemap[key]);
        return val;
    }
    
    void put(int key, int value) {
        if(pagemap.find(key)!=pagemap.end()){
            pagemap[key]->val = value;
            pagelist->move(pagemap[key]);
            return;
        }
        if(size==capacity){
            int k = pagelist->get_rear()->key;
            pagemap.erase(k);
            pagelist->remove();
            size--;
        }
        node* page = pagelist->add(key,value);
        size++;
        pagemap[key]=page;
    }
};