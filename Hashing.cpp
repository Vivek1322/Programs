#include<bits/stdc++.h>
using namespace std;

template <typename T>
class node
{
public:
    string key;
    T value;
    node<T> * next;
    node(string k, T v)
    {
        key = k;
        value = v;
        next = NULL;
    }
};

template <typename T>
class HashTable
{
    int cs, ms;
    node<T> ** buckets;
public:
    HashTable(int m=7)
    {
        ms = m;
        cs = 0;
        buckets = new node<T> * [m];
        for(int i=0; i<ms; i++)
            buckets[i] = NULL;
    }

private:
    int hashFn(string key)
    {
        int l = key.length();
        int ans = 0;
        int p = 1;
        for(int i=0; i<l; i++)
        {
            ans += key[l-i-1]*p;
            p *= 37;
            p %= 37;
            ans %= 37;
        }
        return ans;
    }

    void rehash()
    {
        node <T>** oldBuckets = buckets;
        int oldMS = ms;
        ms = ms*2 + 1;
        cs = 0;
        buckets = new node<T>* [ms];
        for(int i=0; i<ms; i++)
            buckets[i] = NULL;
        for(int i=0; i<oldMS; i++)
        {
            node <T>* temp = buckets[i];
            if(temp!=NULL)
            {
                while(temp!=NULL)
                {
                    insert(temp->key, temp->value);
                    temp = temp->next;
                }
            }
            delete oldBuckets[i];
        }
        delete [] oldBuckets;
    }

public:
    void insert(string key, T value)
    {
       int index = hashFn(key);
       node <T> * temp = new node<T> (key, value);
       temp->next = buckets[index];
       buckets[index] = temp;
       cs++;
       float load_factor = float(cs/ms);
       if(load_factor>0.7)
       {
           cout<<endl<<"Load factor is "<<load_factor<<endl;
           rehash();
       }
    }

    void print()
    {
        for(int i=0; i<ms; i++)
        {
            cout<<endl<<"Bucket "<<i<<"=>";
            node<T> * temp = buckets[i];
            while(temp!=NULL)
            {
                cout<<temp->key<<"->"<<temp->value<<" , ";
                temp = temp->next;
            }
        }
        cout<<endl;
    }

    T* search(string key)
    {
        int i = hashFn(key);
        node<T>* temp = buckets[i];
        while(temp!=NULL)
        {
            if(temp->key == key)
                return &(temp->value);
            temp = temp->next;
        }
        return NULL;
    }

    void del(string key)
    {
        int i = hashFn(key);
        node<T>* temp = buckets[i];
        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                ///code to delete linked list
                return;
            }
            temp = temp->next;
        }
    }

    T& operator [] (string key)
    {
        T * temp = search(key);
        if(temp==NULL)
        {
            T garbage;
            insert(key, garbage);
            T * value = search(key);
            return *value;
        }
        return *temp;
    }
};

int main()
{
    return 0;
}
