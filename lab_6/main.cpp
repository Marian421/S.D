#include <iostream>

using namespace std;

void inserareInceput(int &n,int x,int(&v)[100])
{
   if(n==0 || n==100)
    cout<<"Vectorul nu are elemente";
   else{
    for(int i=n;i>=1;i--)
       v[i+1]=v[i];
   v[1]=x;
   n++;
   }
}

void inserareSfarsit(int &n,int x,int(&v)[100])
{
    n++;
    v[n]=x;

}

void inserareP(int &n,int x,int(&v)[100],int p)
{
    for(int i=n;i>=p;i--)
        v[i+1]=v[i];
    v[p]=x;
    n++;
}

void afisare(int n,int (&v)[100])
{
    for(int i=1;i<=n;i++)
        cout<<v[i]<<" ";
}

void stergereK(int &n,int x,int(&v)[100],int k)
{
    for(int i=k;i<=n;i++)
        v[i]=v[i+1];
    n--;
}

void citire(int n, int (&v)[100])
{
    for(int i=1;i<=n;i++)
        cin>>v[i];
}

int main()
{
    int n,v[100]={0},x=99,p,k;
    cout<<"Introduceti numarul de elemente: ";
    cin>>n;
    cout<<"Introduceti elemtele vectorului: ";
    citire(n,v);
    cout<<"Pozitia pe care doriti sa introduceti elementul: ";
    cin>>p;
    cout<<"Pozitia pe care doriti sa o stergeti: ";
    cin>>k;
    inserareInceput(n,x,v);
    inserareSfarsit(n,x,v);
    inserareP(n,x,v,p);
    stergereK(n,x,v,k);
    afisare(n,v);
    return 0;
}
