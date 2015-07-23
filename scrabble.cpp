#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
int calculateScores(string word);
int getScoreValueof(char c);
void printPermutations(string,string);
int main()
{
//    ifstream fin ;
//    string content;
//    map<int,map<long ,string> > dict;
//    fin.open("C:/Users/test/workspace/Upload/AnagramGen/sowpods1.txt");
//    do
//    {
//        fin >> content;
//        cout << content<<endl;
//
//
//    }while(!fin.eof());
    string text="evlyn";
    sort(text.begin(),text.end());
    cout<<"text is "<<text;
    for(int i=0;i<text.length();i++)
    {
        printPermutations("",text.substr(i,text.length()));

    }

}
int getScoreValueof(char c)
{
    return ((int)c)%97;
}
int calculateScores(string word)
{
    int total=0;
    for (int i=0;i<word.length();i++)
    {
        total=total+getScoreValueof(word[i]);
    }
    return total;
}
void printPermutations(string beginningString ,string endingString)
{
    //cout<<content<<" is the content before rev"<<endl;
    if(endingString.length()<=1)
    {
        cout<< beginningString+endingString<<"\t"<<calculateScores(beginningString+endingString)<< endl;

    }
   else{
        for(int i=0;i<endingString.length();i++){

            string newString= endingString.substr(0,i)+endingString.substr(i+1);

            printPermutations(beginningString+endingString[i],newString);

        }
   }
}
