#include<stdio.h>

int xMax;
int yMax;

struct Robot{
    int xcoordinate;
    int ycoordinate;
    char dir;
};

int main(){

    scanf("%d",&xMax);
    scanf("%d",&yMax);
    int numberOfRobots;
    scanf("%d",&numberOfRobots);
    while(numberOfRobots--){
        struct Robot r;
        int startxPos;
        int startyPos;
        char startDir;
        scanf("%d",&startxPos);
        scanf("%d",&startyPos);
       // scanf("%c",&startDir);
        r.xcoordinate = startxPos;
        r.ycoordinate = startyPos;
       // r.dir = startDir;
        printf("%d %d",r.xcoordinate,r.ycoordinate);
    }
    return 0;
}