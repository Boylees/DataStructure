#include <iostream>
#include <cstdio>
#include <queue>
#include "test3.cpp"
using namespace std;

double BFS(Figure* f,int node){//广搜求度数
    queue<int> cur,next;
    bool visited[f->node+1]={false};
    cur.push(node);
    visited[node]=true;
    int degree=0;
    double count=1;
    while(!cur.empty()){//第一个while循环求节点的度数
        degree++;
        if(degree==7)
        break;
        while (!cur.empty())//第二个while循环从根节点BFS遍历
        {
            int tmp=cur.front();
            cur.pop();
            for(int i=1;i<=f->node;i++){
                if(!visited[i]&&f->length[tmp][i].data==1){
                    next.push(i);
                    visited[i]=true;
                    count++;
                }
            }
        }
        swap(cur,next);
        
    }
    return count;
}

int main(){
    Figure* f=new Figure;
    f=CreatFigure(f);
    for(int i=1;i<=f->node;i++){
        printf("%d: %.2lf%\n",i,(BFS(f,i)/f->node)*100);
    }
    system("pause");
}

