// �����㷨��������
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

struct point
{
	double x , y;
}p[100005];

int a[100005];    //����ɸѡ������������

int cmpx(const point &a, const point &b)
{
	return a.x < b.x;
}
int cmpy(const int &a, const int &b)    //�����õ����±�����
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
	double ans = min( closest(low , mid) , closest(mid + 1 , high) );    //���η����еݹ����
	int i , j , cnt = 0;
	for(i = low ; i <= high ; ++i)   //��x������p[mid].x-ans~p[mid].x+ans��Χ�ڵĵ�ȡ����
	{
		if(p[i].x >= p[mid].x - ans && p[i].x <= p[mid].x + ans)
			a[cnt++] = i;       //��������±�����
	}
	sort(a , a + cnt , cmpy);   //��y���������������
	for(i = 0 ; i < cnt ; ++i)
	{
		for(j = i+1 ; j < cnt ; ++j)
		{
			if(p[a[j]].y - p[a[i]].y >= ans)   //ע���±�����
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
