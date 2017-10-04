/*
TASK: metro
LANG: C++
*/
#include<iostream>
using namespace std;
int price[1024][128];//[distance][currentheight]
int height[1024];
int leng,i;
int priceat(int d, int h){//evaluates the cost if we built somethnig at distance d and height h
	if(height[d]==h)return 1;
	if(height[d]>h) return (height[d]-h)*(height[d]-h);
	return 7*(h-height[d]);
}
void fromto(int d,int curh,int nexth){
	if((nexth>=0)&&(nexth<100)&&((price[d+1][nexth]==0)||
		(price[d+1][nexth]>price[d][curh]+priceat(d+1,nexth)))){
		 price[d+1][nexth]=price[d][curh]+priceat(d+1,nexth);
	}
	
	
}
int main(){
	cin>>leng;
	for(i=0;i<leng;i++){
		cin>>height[i];
	}
	for(i=0;i<=100;i++){
		price[0][i]=priceat(0,i);
	}
	for(int d=0;d<leng-1;d++){
		for(int curh=1;curh<100;curh++){
				fromto(d,curh,curh+1);
				fromto(d,curh,curh  );
				fromto(d,curh,curh-1);
				fromto(d,curh,curh-2);
		}
	}
	int best=1000000000;
	for(int endingheight=1;endingheight<=100;endingheight++){
			if((best>price[leng-1][endingheight])&&(price[leng-1][endingheight]>0)){
			best=price[leng-1][endingheight];
		}
	}
	cout<<best<<endl;
	return 0;
}
