/**
 *从1-n中选出三个数组成三角形，问有多少种选择？例如n=5时，有3中方法，(2,3,4),(2,3,5),(3,4,5)
 *n=8时有22种方法。
 *
 *问题的分析思路：
 *最简单的方法是O(n^3)直接暴力解决。但是我们有加法原理，设最大边长为x的三角形有c(x)个，
 *另外两条边是y和z，有y+z > x。所有z的取值是： x-y < z < x 显然y的取值，对应这个不等式的解的个数
 *y = 1时，没有解，y = 2时，1个解；y=3时，2个解；y=x-1时，有x-2个解；
 *共有0+1+2+...+(x-2) = (x-1)(x-2)/2。注意上式子多计算了，每个三角形计算了两次，
 *例如 y = 3 和 y = x-4时， y=2: (2,x-1,x) ; y=x-2:(x-1,2,x) 只是交换了边长的顺序。 
 *而且y=z时更是多计算了。
 *c(x) = 1/2{(x-1)(x-2)/2 - (x-1)/2}
 *f(n) = c(1) + c(2) +...+ c(n) = f(n-1) + c(n)
 */
#include<iostream>
using namespace std;
typedef long long LL;
const int MAXN = 1000000 + 10;

LL f[MAXN];
int main()
{
	
	f[3] = 0;
	for(LL i=4;i<=1000000;i++){
		f[i] = f[i-1] + ((i-1)*(i-2)/2 - (i-1)/2)/2;
	}	
	int n;
	while(cin>>n){
		if(n<3) break;
		cout<<f[n]<<endl;
	}	


	return 0;	
}






