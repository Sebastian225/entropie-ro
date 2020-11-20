#include <iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

char v[500],c;
map<string,int> dict;
long long n,i,j,u,k,e,l,nr,g;
double p,H[500];

int main()
{

    ifstream in("texte.in");
    ofstream out("rezultate.out");
    //out<<"0: "<<log2(alphabet_size)<<'\n';
    n=30; //Grupuri de maxim n litere
    for(i=1;i<=n;i++) //grupuri de i litere
    {
        cout<<i;
        dict.clear();
        u=0;
        for(k=0;k<i;k++) //citite incepand cu k
        {
            for(l=0;l<=k;l++)
            {
                in>>c;
            }
            while(in>>c && c!='~') //iau grupuri de i si le adaug la string array-ul m
            {
                if((c>=92 && c<=122) || c=='O')
                {
                    v[0]=c;
                    j=1;
                    while(j<i)
                    {
                        in>>c;
                        if((c>=92 && c<=122) || c=='O')// 'O' =' '
                        {
                            v[j]=c;
                            j++;
                        }
                        else
                        {
                            if(c=='~')
                                j=i;
                        }
                    }
                    if(v[j-1]!='~') // ca sa nu mai analizeze ultimele siruri care cotin mai putine litere si in rest '~'
                    {
                        //cout<<v<<'\n';
                        dict[v]++;
                        //cout<<u<<' '<<m[u]<<'\n';
                        u++;
                    }
                }


            }
                           // cout<<u<<' ';
            in.seekg(0,ios::beg); //duc citirea pe pozitia 0 a fisierului
        }



        for (map<string,int>::iterator it=dict.begin(); it!=dict.end(); ++it)
        {

                p=double(it->second);
                p=p/(u);
                H[i]=H[i]-p*log2(p);

        }

        out<<i<<": "<<fixed<<setprecision(7)<<H[i]-H[i-1]<<"   H["<<i<<"]= "<<H[i]<<'\n';

    }
}
