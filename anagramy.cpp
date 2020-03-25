#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Anagramy{
       ifstream p1;
       ofstream p2;
       
  public:

void otworz_plik(){
	p1.open("plik1.txt");
    p2.open("plik2.txt");
}

void CzyAnagram(){
	bool CzyAnagram=true;
		string s1,s2;
    p2<<"["<<endl;
    	while(!p1.eof()){
    p1>>s1>>s2;

	if(s1.length()!=s2.length())
       CzyAnagram=false;
       
for (int i=0;i<s1.length()-1;i++)
    for (int j=0;j<s1.length()-1;j++)
        if (s1[j]>s1[j+1])
            swap(s1[j],s1[j+1]);

for (int i=0;i<s2.length()-1;i++)
    for (int j=0;j<s2.length()-1;j++)
        if (s2[j]>s2[j+1])
            swap(s2[j],s2[j+1]);

for (int i=0;i<s1.length();i++){
     	if (s1[i]!=s2[i])
	CzyAnagram=false;
    	else
    CzyAnagram=true;
		}
	}
	if (CzyAnagram==true)
p2<<"{\"wyraz1\": "<<s1<<", wyraz2\": "<<s2<<", \"anagram\":\""<<" Jest anagramem"<<"}"<<endl;
	else
p2<<"{\"wyraz1\": "<<s1<<", wyraz2\": "<<s2<<", \"anagram\":\""<<" Nie jest anagramem"<<"}"<<endl;
p2<<"]"<<endl;
}

void zamknij_plik()
{
    p1.close();
    p2.close();
}

};
int main(){

Anagramy c1;
c1.otworz_plik();
c1.CzyAnagram();
c1.zamknij_plik();

    return 0;
}
