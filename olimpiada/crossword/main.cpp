#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
//------------------------------------------------
vector<char> words;//L A B A S R Y T A S B I R U T E
vector<char> word;// null
vector<vector<char>> chWords; //(L A B A S) (R Y T A S) (B I R U T E)
vector<char> characters; //A B R S T
//------------------------------------------------
void read();
void findDuplicates();
void deleteduplicates();
void write();
//------------------------------------------------
int main() {
  read();
  findDuplicates();
  deleteduplicates();
  write();

  return 0;
}
//------------------------------------------------
void read(){
  for(int n =0; n<3; n++){
    string line;
    getline(cin, line);
    for (int i = 0; i < line.length(); ++i) {
      words.push_back(line[i]);//1d vector
      word.push_back(line[i]);
    }
    chWords.push_back(word);//2d
    word.clear();
  }
}
//------------------------------------------------
void findDuplicates(){
  for (int i = 0; i < words.size(); ++i) {
    for (int j = i+1; j < words.size(); ++j) {
      if(words[i] == words[j] && i != j){
        characters.push_back(words[i]);
      }
    }
  }
}
//------------------------------------------------
void deleteduplicates(){
  sort(characters.begin(),characters.end() );
  characters.erase(unique(characters.begin(),characters.end() ),characters.end() );
}
//------------------------------------------------
void write(){
  string str1 = "";
  for (int j = 0; j < chWords[0].size(); ++j) {
    str1+=chWords[0][j];
  }
  string str2 = "";
  for (int j = 0; j < chWords[1].size(); ++j) {
    str2+=chWords[1][j];
  }
  string str3 = "";
  for (int j = 0; j < chWords[2].size(); ++j) {
    str3+=chWords[2][j];
  }
  //---
  for (int i = 0; i < characters.size(); ++i) {//A B R S T
    if(str1.find(characters[i])!= string::npos && str2.find(characters[i])!= string::npos)
      cout<<str1<<" "<<str1.find(characters[i])+1<<" "<<str2<<" "<<str2.find(characters[i])+1<<endl;
    else if(str2.find(characters[i])!= string::npos && str3.find(characters[i])!= string::npos ){
      cout<<str2<<" "<<str2.find(characters[i])+1<<" "<<str3<<" "<<str3.find(characters[i])+1<<endl;
    }
    else if(str1.find(characters[i])!= string::npos && str3.find(characters[i])!= string::npos ){
      cout<<str1<<" "<<str1.find(characters[i])+1<<" "<<str3<<" "<<str3.find(characters[i])+1<<endl;
    }
  }
}
//str1(L A B A S) str2(R Y T A S) str3(B I R U T E)