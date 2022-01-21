#include <bits/stdc++.h>
using namespace std;

class LRUCache{
    public:
        LRUCache(int capacity);
        int get(int key);
        void set(int key,int value);
};

int t,n;
map<int,pair<int,int> > mp; // key,value,time
set<pair<int,int> > st; // time,key

LRUCache::LRUCache(int capacity) {
    t=0; n =capacity;
    mp.clear(); st.clear();
}

int LRUCache::get(int key) {
    if(mp.find(key)==mp.end()) return -1;
    t++;
    st.erase({mp[key].second,key});
    st.insert({t,key});
    mp[key].second = t;
    return mp[key].first;
}

void LRUCache::set(int key, int value) {

    t++;
    if(mp.find(key)!=mp.end()){
        st.erase({mp[key].second,key});
        mp[key] = {value,t};
        st.insert({t,key}); return;
    }

    if(mp.size()==n){
        auto it = st.begin();
        mp.erase((*it).second);
        st.erase(it);
    }

    mp[key] = {value,t};
    st.insert({t,key});
}


int main(){

    return 0;
}