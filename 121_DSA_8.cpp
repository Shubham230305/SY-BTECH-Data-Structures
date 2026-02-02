#include<iostream>
using namespace std;

int countpaths(int x, int y, int endx, int endy)
{
    if(x == endx  &&  y == endy)
    {
        return 1;
    }
    if (x > endx  ||  y > endy)
    {
        return 0;
    }
    return countpaths(x+1, y, endx, endy) + countpaths(x, y+1, endx, endy);
}

int main()
{
    int gridsize, startx, starty, endx, endy;

    cout<<"Enter the Grid Size : ";
    cin>>gridsize;
    cout<<"Enter the Starting Position (x,y) :"<<endl;
    cin>>startx>>starty;
    cout<<"Enter the Ending Position (x,y) :"<<endl;
    cin>>endx>>endy;

    if(startx < 1  ||  starty < 1  ||  endx < 1  ||  endy < 1  ||  startx > gridsize  ||  starty > gridsize  ||  endx > gridsize  ||  endy > gridsize)
    {
        cout<<"INVALID POSITION"<<endl;
        return 1;
    }
    
    int uniquepaths = countpaths(startx, starty, endx, endy);
    cout<<"Unique path from ("<<startx<<","<<starty<< ") to ("<<endx<<"," <<endy<<") : "<<uniquepaths;
    return 0;
}