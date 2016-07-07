class LRUCache
{
private:
    typedef pair<int,int> P;
    P *start;
    P *finish;
    P *end_of_storage;

public:
    LRUCache(int capacity) {
        start = new P[capacity];
        finish = start;
        end_of_storage = start + capacity;
    }

    ~LRUCache() {
        delete [] start;
    }

    int get(int key) {
        for(int i = 0;i < finish - start;i++){
            if((*(start + i)).first == key){
                P tmp = *(start + i);
                for(int j = i;j < finish - start - 1;j++)   *(start + j) = *(start + j + 1);
                *finish = tmp;
                return (*finish).second;
            }
        }
        return -1;
    }

    void set(int key, int value) {
        for(int i = 0;i < finish - start;i++){
            if((*(start + i)).first == key){
                (*(start + i)).second = value;
            }
        }
        if(finish < end_of_storage)     *finish++ = make_pair(key,value);
        else{
            for(int i = 0;i < finish - start - 1;i++){
                *(start + i) = *(start + i + 1);
            }
            *finish = make_pair(key,value);
        }
    }
};

