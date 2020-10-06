// 这个 "over five-thousand" 把我秀晕了.
// 自己把txt文件去逗号和双引号. 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 10000;
string names[MAXN];

int main(){
	freopen("p022_names.txt","r",stdin);
//	freopen("p022_names_out.txt","w",stdout);

	LL ans=0;
	int n=5163;
	for(int i=0;i<n;i++)	cin>>names[i];
	cout<<names[n-1]<<endl;
	sort(names,names+n);
	for(int i=0;i<n;i++){
//		if(i>900 && i<940)
//			cout<<names[i]<<endl;
		LL temp=0;
		for(int j=0;j<names[i].length();j++)
			temp+=(names[i].at(j)-'A'+1);
		temp=temp*(i+1);
		ans+=temp;
	}
	cout<<ans<<endl;
	
	return 0;
}
