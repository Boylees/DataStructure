#include <iostream>
#include <cstdio>
using namespace std;

#define Maxn 104

typedef struct {
    int data;
}Node[Maxn][Maxn];
typedef struct {
    Node length;
    int node;
    int aec;
}Figure;
Figure* CreatFigure(Figure *f){//创建邻接矩阵
    int node,aec;
    scanf("%d%d",&node,&aec);
    f->node = node;
    f->aec = aec;
    for(int i=1;i<= f->node;i++){
        for(int j=1;j<=f->node;j++){
            f->length[i][j].data=105;//这里105相当于两点间没有路
        }
    }
    for(int i=1;i<= f->aec;i++){
        int j,k;
        cin>>j>>k;
        f->length[j][k].data=1;
        f->length[k][j].data=1;
    }
    return f;
}
Figure* Floyd(Figure* f){//弗洛伊德算法求最短路
    int i,j,k;
    for(k=1;k<=f->node;k++){
        for(i=1;i<=f->node;i++){
            for(j=1;j<=f->node;j++){
                if(f->length[i][j].data>(f->length[i][k].data + f->length[k][j].data))
                    f->length[i][j].data=f->length[i][k].data + f->length[k][j].data;
            }
        }
    }
    return f;
}
void FindNode(Figure* f){//找路径中<=6的节点数
    double node=0;
    int sum=0;
    for(int i=1;i<=f->node;i++){
        for(int j=1;j<=f->node;j++){
            if(f->length[i][j].data<=6)
                sum+=1;
        }
       node=(double)sum/f->node;
       node=node*100;
       printf("%d: %.2lf%\n",i,node);
       node=0;
       sum=0;
    }
}
// int main(){
//     Figure *f =new Figure;
//     f= CreatFigure(f);
//     f=Floyd(f);
//     // for(int i=1;i<=f->node;i++){
//     //     for(int j=1;j<=f->node;j++){
//     //         cout<<f->length[i][j].data<<" ";
//     //     }
//     //     cout<<endl;
//     // }
//     FindNode(f);
//     system("pause");
// }

