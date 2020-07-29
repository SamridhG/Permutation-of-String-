#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<vector<string> >B;//2D vector for every combination occur
void fswap(string *a,string *b)//for swapping here am using pointer for actual swap change 
{swap(*a,*b);}
void permutation(vector<string>A,int n,int i)// function defination-Vector,size of vector minus one because of zero indexing,i for matching last combination
{
	int j;//for looping
	if(i==n)// base case ..if size of vector match last combination of permutation tree
	{
B.push_back(A);// that combination vector  pushed to another vector
	}
	else// recirsive case 
	{
		for(j=i;j<=n;j++)//j=i because i-1 fixed and wehave to find combination from i;
		{
			fswap(&A[i],&A[j]);// finding combination
			permutation(A,n,i+1);//next combination by fixing i
		     fswap(&A[i],&A[j]);// this case is run when our base case implement in this case we backtrack the last case before implement
		}
	}
}
int main()
{
	int i,j,n,p;
	cout<<"Number of Entry:-";
	cin>>n;//number of case you want to permutate
	string a;
	vector<string>A;
	for(j=0;j<n;j++)
	{
		cin>>a;
		A.push_back(a);// putting all case in one string array vector
	}
		permutation(A,n-1,0);//function calling with vector,size of vector,fixed number index
for(i=0;i<B.size();i++)//in B vector all permutation combination present here we check if any combination match we erase that combination we repeated
{
	for(j=i+1;j<B.size();j++)
	{
		if(B[i]==B[j])//yes in 2d vector we can check all index vector element by this
		{
			B.erase(B.begin()+j);
			j--;// reducing j value for checking
		}
	}
}
		for(i=0;i<B.size();i++)//printing all element
		{
			cout<<i+1<<".";//  checking case 
			for(j=0;j<B[i].size();j++)
			{  
					cout<<B[i][j]<<" ";
			}
			cout<<endl;
		}
	return 0;
}
