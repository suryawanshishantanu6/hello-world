#include<iostream>
#include<stdlib.h> 
#include<string.h>
using namespace std;
 
void Union(int set1[10],int set2[10],int m,int n); 
void Intersection(int set1[10],int set2[10],int m,int n); 
int main() 
{ 
 int a[10],b[10],m,n,i,j; 
 int ch; 

 cout<<"\n""Enter the number of elements in first set:""\n"; 
 cin>>m; 
 cout<<"\n""Enter the elements:""\n"; 
 for(i=0;i<m;i++) 
 { 
  cin>>a[i]; 
 } 
 cout<<"\nElement of First set:\n\n"; 
 for(i=0;i<m;i++) 
 { cout<<"\t";
  cout<<a[i]; 
 } 
 cout<<"\nEnter the number of elements in second set:\n"; 
 cin>>n; 
 cout<<"\nEnter the elements:\n"; 
 for(i=0;i<n;i++) 
 {
   
  cin>>b[i]; 
 } 
 cout<<"\nElement of second set\n"; 
 for(i=0;i<n;i++) 
 { 
  cout<<"\t";
  cout<<b[i]; 
 } 
do
 { 
  cout<<"\n\nMenu\n\n1.Union\n2.Intersection"; 
  cout<<"\n3.exit"; 
  cout<<"\nEnter your choice:\n"; 
  cin>>ch; 
  switch(ch) 
  {
  case 1: 
   Union(a,b,m,n); 
   break; 
  case 2: 
   Intersection(a,b,m,n); 
   break; 
  case 3:exit(0); 
   break;
   }
  }while(ch!=0);
   
  return 0; 
 
} 
 
void Union(int a[10],int b[10],int m,int n) 
{ 
 int c[20],i,j,k=0,flag=0; 
 for(i=0;i<m;i++) 
 { 
  c[k]=a[i]; 
  k++; 
 } 
 for(i=0;i<n;i++) 
 { 
  flag=0; 
  for(j=0;j<m;j++) 
  { 
   if(b[i]==c[j]) 
   { 
    flag=1; 
    break; 
   } 
  } 
  if(flag==0) 
  { 
   c[k]=b[i]; 
   k++; 
  } 
 } 
 cout<<"\nElement of resultant set\n\n"; 
 for(i=0;i<k;i++) 
 { 
  cout<<"\t";
  cout<<c[i]; 
 } 
} 
void Intersection(int a[10],int b[10],int m,int n) 
{ 
 int c[20],i,j,k=0,flag=0; 
 for(i=0;i<m;i++) 
 { 
  flag=0; 
  for(j=0;j<n;j++) 
  { 
   if(a[i]==b[j]) 
   { 
    flag=1; 
    break; 
   } 
  } 
  if(flag==1) 
  { 
   c[k]=a[i]; 
   k++; 
  } 
 } 
 if(k==0)
 {
  cout<<"\n\nResultant set is null set!\n";
 }else{
  cout<<"\nElement of resultant set\n"; 
  for(i=0;i<k;i++) 
  { 
   cout<<"\t";
   cout<<c[i]; 
  } 
  
 }
}
