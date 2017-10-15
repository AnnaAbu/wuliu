// 分治算法求最近点对
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

struct point
{
	double x , y;
}p[100005];

int a[100005];    //保存筛选的坐标点的索引

int cmpx(const point &a, const point &b)
{
	return a.x < b.x;
}
int cmpy(const int &a, const int &b)    //这里用的是下标索引
{
	return p[a].y < p[b].y;
}
inline double dis(point &a , point &b)
{
	return (double)sqrt( ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)) * 1.0);
}
inline double min(double a , double b)
{
	return a < b ? a : b;
}
double closest(int low , int high)
{
	if(low + 1 == high)
		return dis(p[low] , p[high]);
	if(low + 2 == high)
		return min(dis(p[low] , p[high]) , min( dis(p[low] , p[low+1]) , dis(p[low+1] , p[high]) ));
	int mid = (low + high)>>1;
	double ans = min( closest(low , mid) , closest(mid + 1 , high) );    //分治法进行递归求解
	int i , j , cnt = 0;
	for(i = low ; i <= high ; ++i)   //把x坐标在p[mid].x-ans~p[mid].x+ans范围内的点取出来
	{
		if(p[i].x >= p[mid].x - ans && p[i].x <= p[mid].x + ans)
			a[cnt++] = i;       //保存的是下标索引
	}
	sort(a , a + cnt , cmpy);   //按y坐标进行升序排序
	for(i = 0 ; i < cnt ; ++i)
	{
		for(j = i+1 ; j < cnt ; ++j)
		{
			if(p[a[j]].y - p[a[i]].y >= ans)   //注意下标索引
				break;
			ans = min(ans , dis(p[a[i]] , p[a[j]]));
		}
	}
	return ans;
}
int main(void)
{
    int n;
	while(~scanf("%d",&n))
	{
		for(int i = 0 ; i < n ; ++i)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		sort(p , p + n , cmpx);
		printf("%.2f\n",closest(0 , n - 1));
	}
	return 0;
}
