#include<iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

vector<vector<string> > rowValue;

void readRecords() //reading the records using file handling concept
{ 
	fstream fin; 
	fin.open("input.csv", ios::in); //reading the csv file
	string word,tmp,line; 

	while (!fin.eof()) { //traversing till the end of file 
	     getline(fin,line);//fetching the line of records from the file
	     stringstream st(line);
    	     string rec;
	       	vector<string> v;
		while (getline(st,rec, ',')) //loop to fetch records till comma is encountered
		{ 
			v.push_back(rec); 
		} 
		rowValue.push_back(v);//pushing value into the vector
	}
}
//function that displays result
void displayResult(string c,int position,int len)
{
	int i;
	string str="";
	for(int i=0;i<rowValue[position].size();i++)
	{
		str=c+rowValue[position][i];
		if(str.length()==len)//comparing the lengths
		{
			cout<<str<<",";//printing the result string
		}
		else
		{
			displayResult(str,position+1,len);//recursive call to the function
		}
	}
}
int main()
{
	readRecords();//calling the function to read the array of strings
	string result="";
	displayResult(result,0,rowValue.size()-1);//calling the function to display the resulting string
	return 0;
}

