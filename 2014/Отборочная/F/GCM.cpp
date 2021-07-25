#include <iostream>
#include <fstream>

using namespace std;

long long ans,i,j,f,n=0,x,y,minz,mina,c,d,ans1, ch;
long long a1[1000000],b1[1000000];

long long NOD(long long a,long long b)
{
     while((a!=0)&&(b!=0))
     {
       if(a>b)
       {
              a=a%b;
       }
       else
       {
              b=b%a;
       }
     }
     return(a+b);
 }

 long long NOK(long long a,long long b)
 {

       return (a/(NOD(a,b))*b);
   }

 int main()
 {
  ifstream cin ("gcm.in");
  ofstream cout ("gcm.out");
  cin>>c>>d;
  f=NOD(c,d);
  ans=NOK(c,d)/f;
 // cout<<ans<<"\n";
  //cout<<f<<"\n";
  for (i=1;i*i<=ans;i++)
  {

      //cout<<ans<<"\n";
      //ans1=ans%i;
      //cout<<ans1<<"\n";
      if ((ans%i)==0)
      {
                 //cout<<i<<"\n";
                 a1[n]=i;
                 b1[n]=ans/i;

                 //cout<<n<<"\n";
                  //cout<<"a1[n]=  "<<a1[n]<<"\n"; 
                  //cout<<"b1[n]=  "<<b1[n]<<"\n";

                         n=n+1; ch+=1;
      }
  }
  //if (ch==0) {a1[0]=ans; b1[0]=ans;}
      minz=ans;
      //n=n/2;
      //cout<<"n= "<<n<<"\n";
      //cout<<"minz= "<<minz<<"\n";
  for (j=0; j<n;j++)
  {
      if ( (a1[j]-b1[j])<minz)
      {
         minz=b1[j]-a1[j];
         mina=j;
      }
  }
        //cout <<mina <<"\n";
  x=f*a1[mina];
  y=f*b1[mina];
 //cout<<"f= "<<f<<"\n";
  //cout<<a1[mina]<<" "<<b1[mina]<<"\n";
  //cout <<x <<" " <<y <<" " <<ch <<"\n\n";
  if ( (c==d) || (ch==0) ) {cout<<c<<" "<<d<<"\n";}
  else      {cout<<x<<" "<<y<<"\n";}
  //getch();
  return 0;
}






