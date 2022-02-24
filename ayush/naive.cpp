#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
 
using namespace std;
const int INF= 2147483647;

#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)
#define MOD 1000000007
struct Contri{
	string name;
	int skills;
	vector< pair<string,int> > skill;
};
typedef struct Contri contri;
struct Proj{
	string name;
	int reqs;
	int dur;
	int score;
	int best;
	vector< pair<string,int> > req;
};
typedef struct Proj proj;
int cmpp(proj a,proj b){
	return (a.score < b.score);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);	
	int C,P;
	cin>>C>>P;
	vector<contri> contributers;
	for(int i=0;i<C;i++){
		string name;
		cin>>name;
		contri c;
		c.name=name;
		int skills;
		cin>>skills;
		c.skills=skills;	
		for(int j=0;j<skills;j++){
			pair<string, int> p;
			cin>>p.first>>p.second;
			c.skill.push_back(p);
		}
		contributers.push_back(c);
	}	
	vector<proj> projects;
	for(int i=0;i<P;i++){
		string name;
		cin>>name;
		proj p;
		p.name=name;
		int dur;
		cin>>dur;
		p.dur=dur;
		int sc;
		cin>>sc;
		p.score=sc;
		int best;
		cin>>best;
		p.best=best;
		int reqs;
		cin>>reqs;
		p.reqs=reqs;
		for(int j=0;j<reqs;j++){
			pair<string,int> pr;
			cin>>pr.first>>pr.second;
			p.req.push_back(pr);
		}		
		projects.push_back(p);
	}
	sort(projects.begin(),projects.end(),cmpp);
	int E=0;
	vector<bool> flag;
	for(int i=0;i<C;i++)flag.push_back(true);
	for(int i=0;i<P;i++){
		int cnt=0;
		vector<string> names;
		for(int j=0;j<projects[i].reqs;j++)names.push_back("");
		for(int j=0;j<C;j++){ // for every jth contributer
			if(cnt==projects[i].reqs)break;
			bool done=false;
			for(int k=0;k<projects[i].reqs;k++){ //  for every role of project
				if(names[k]!="")continue;
				if(done)break;
				pair<string,int> curr=projects[i].req[k];
				for(int l=0;l<contributers[j].skills;l++){ // for every skill of contributer
					if(flag[j] && contributers[j].skill[l].first==curr.first && contributers[j].skill[i].second>=curr.second){
						names[k]=contributers[j].name;
						cnt++;
						done=true;
						break;

					}
				}
				if(done)break;
			}
		}	
		for(int j=0;j<C;j++){
			for(int k=0;k<projects[i].reqs;k++){
				if(names[k]==contributers[j].name){
					flag[j]=false;	
				}
			}
		}
		if(cnt==projects[i].reqs){
			cout<<projects[i].name<<'\n';
			for(int k=0;k<names.size();k++){
				cout<<names[k]<<' ';
			}
			cout<<'\n';
			E++;
		}
	}
	cout<<E<<'\n';
	return 0;
}
