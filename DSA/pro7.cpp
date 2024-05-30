// You have a business with several offices; you want to lease phone lines to connect them up with each other; and the phone company charges different amounts of money to connect different pairs of cities. You want a set of lines that connects all your offices with a minimum total cost. Solve the problem by suggesting appropriate data structures.
#include <iostream>
using namespace std;
int cost[20][20];               //matrix declared as global variable
class graph
{
    int i,j,v,w,k;
public:
    graph()            //constructor
    {

        for(i=1;i<=20;i++)           //iterates from 1 to 20 and represents the rows of the cost matrix
            for(j=1;j<=20;j++)      //iterates from 1 to 20 and represents the columns of the cost matrix
                cost[i][j]=0;                 // initializes all elements of the cost matrix to zero using nested for loops
    }
    void create();
    void display();
    void prims();
};
int main() {
    graph g;
    cout<<"\n CREATE MST";
    g.create();
    g.display();
    g.prims();
    return 0;
}

void graph::create()                                         //function is used to create graph 
{
  cout<<"\n Enter total number of vertices/Houses in a lane:";    //asks user to enter the total number of vertices(houses) in the lane 
    cin>>v;                  //and storing the value in the variable v

    for(i=1;i<=v;i++)			//iterates from 1 to v & represents the starting vertex of an edge
        for(j=i+1;j<=v;j++)     // represents the ending vertex of an edge & starting from 'i+1' means each pair of vertices are visited once 
        {
            cout<<"\n Press 0 if no edge or provide cost if edge between"<<i<<"and"<<j;
            cin>>w;
     cost[i][j]=cost[j][i]=w;           //assigns cost entered by user to matrix & ensures cost from vertex i-j is same as j-i
        }
}

void graph::display()
{
    cout<<"\n Adjacency Matrix is:";
    for(i=1;i<=v;i++)  //iterates from 1 to v and represents the rows of the adjacency matrix
    {
		cout<<"\n";   //move to a new line before printing the elements of the next row
            for(j=1;j<=v;j++)    //iterates from 1 to v. It represents the columns of the adjacency matrix
            {
                cout<<"\t"<<cost[i][j];  //prints the value of edge between vertices i-j
            }
    }
}


void graph::prims()
{
    int pos=1,mincost=0,min=9999,row=0,col=0;
    int visit[20];	                 // visit and path arrays declared to track visited vertices & the selected path in the Minimum Spanning Tree
    int path[20];   
    for(i=1;i<=v;i++)
    {
        visit[i]=0;   //set to 0
        path[i]=0;
    }

    visit[1]=1;    //set to 1 saying that vertex 1 is visited and included in the MST
    path[pos++]=1; //indicates position in 'path' array

    cout<<"\n INITIALLY MINIMUM COST IS "<<mincost;        //'mincost' displayed as initial minimum cost
    for(k=1;k<=v-1;k++)    
    {
        min=999;  //
        for(i=1;i<=v;i++)    //used to check each pair of vertices
        {
            for(j=1;j<=v;j++)   //used to check each pair of vertices
            {
                if(visit[i]==1 && visit[j]==0)   //1 indicates that 'i' vertex visited once & 'j' unvisited 
                {
                    if(cost[i][j]!=0 && min>cost[i][j])
                    {
                        min=cost[i][j];   
                        row=i;
                        col=j;
                    }
                }
            }
        }
        mincost=mincost+min; //
        visit[col]=1;
        path[pos++]=col;
        cost[row][col]=cost[col][row]=0;
    }
    cout<<"\n Total minimum cost:"<<mincost;
    cout<<"\n Shortest Path is \n";
    for(i=1;i<=v;i++)
                cout<<" "<<path[i];
}
