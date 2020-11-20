#include <iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
#include<string>
#include<map>
using namespace std;


char c;
string v;
map<string,int> dict;

long long ltext,u;
double p,H,sp,avgw,Hchar;

int main()
{

    ifstream in("texte.in");
    ofstream out("rezultate.out");
    while(in>>c)
    {
        v.clear();
        while(c>=92 && c<=122) //litere mici + diacritice inlocuite
        {
            ltext++;
            v.push_back(c);
            in>>c;
        }

        if(v.size()>0)
        {
            //cout<<v<<'\n';
            dict[v]++;
            u++;
        }

    }

        for (map<string,int>::iterator it=dict.begin(); it!=dict.end(); ++it)
        {

                p=double(it->second);
                p=p/(u);
                sp=sp+p;
                H=H-p*log2(p);

        }
        sp=0;
        avgw=double(ltext)/double(u);
        Hchar=H/avgw;
        out<<fixed<<setprecision(7)<<"Entropia/cuvant: "<<H<<"\nLungimea medie a cuvantului: "<<avgw<<"\nEntropia/caracter:  "<<Hchar<<'\n';





}
