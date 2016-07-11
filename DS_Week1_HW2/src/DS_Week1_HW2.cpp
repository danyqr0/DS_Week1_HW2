//============================================================================
// Name        : DS_Week1_HW2.cpp
// Author      : Daniel Ramirez
// Version     :
// Copyright   : HW1_Week2
// Description : Tree-Height in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

//using std::vector;
using std::cin;
using std::cout;
using std::vector;
using std::queue;

class TreeHeight {
  int n;
  int root;
  vector<int> parent;
  vector< vector<int> > children;
public:
  void read() {
    cin >> n;
    parent.resize(n);
    children.resize(n);
    for (int i = 0; i < n; i++){
      cin >> parent[i];
      if(parent[i]==-1)
         root=i;
      else
          children[parent[i]].push_back(i);
    }
  }

  int find_root (){
      return root;
  }

  void print(){
      vector<int> temp;
      for(int x=0; x<children[root].size();x++){
          cout<<"children[root]"<<children[root][x];
          temp.push_back(children[root][x]);
      }
      for(int y=0; y<temp.size();y++){
          cout<<"temp="<<temp[y];
      }
  }

  int compute_height() {
     vector<int> row; vector<int> buffer;
     bool flag=1;
     int size,pivot,height;
     if(parent.empty())
         return 0;
     height=1;
     size=children[root].size();
     buffer.push_back(root);
     while(!buffer.empty()){
         for(int i=buffer.size();i>0;i--){
             row.push_back(buffer.back());
             buffer.pop_back();
         }
         buffer.clear();
         while(size>0){
             if(flag==1){
                 pivot=children[root].back();
                 row.clear();
                 children[root].pop_back();
             }
             else{ pivot=row.back();row.pop_back();}
             while(!children[pivot].empty()){
                 buffer.push_back(children[pivot].back());
                 children[pivot].pop_back();
             }
             size--;
         }
         flag=0;
         height++;
         size=buffer.size();
     }
    return height;
  }
};

int main() {
  std::ios_base::sync_with_stdio(0);
  TreeHeight tree;
  int root;
  tree.read();
  root=tree.find_root();
  cout <<tree.compute_height();
}
