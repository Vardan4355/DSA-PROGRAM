#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){ 
    list<int> l;
    l.push_back(11);
    l.push_back(22);
    l.push_back(33);
    l.push_back(44);
    l.push_back(55);
    while(!l.empty()){
        cout<<l.front()<<" ";
        l.pop_front();
    }
    return 0;
}