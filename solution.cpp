#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <fstream>
#include <string>
#include <string.h>

#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/ostreamwrapper.h"
#include "WideDesign.h"

using namespace rapidjson;
using namespace std;

int WideDesign::dfs(string str, Value& u, int curQuestion, vector<string> lv)
{
	int cnt = 1;
	bool isClosed = 1;
	string Type = u["type"].GetString();
	string Label = u["label"].GetString();


	if (Type == "TABLE") {
		Value& val = u["value"];
		int theMax = 0;
		for (int i = 0; i < (int)val.Size(); i++) {
			Value& v = val[i];
			string TypeV = v["type"].GetString();
			string LabelV = v["label"].GetString();
			if (TypeV !="BOOL") {
				addQuestion(str, LabelV);
				lv.push_back(LabelV);
				theMax = max(theMax, dfs(LabelV, v, QuestionID,lv));
				lv.pop_back();
			}
			else {
				theMax = max(theMax, dfs(str, v, curQuestion,lv));
			}
		}
		cnt += theMax;
	}

	if (cnt == 1) {
		Value& ValArray = u["value"];
		if (Type=="INT"){
			addMapINT(curQuestion, Label, ValArray);
			++cnt; isClosed = 0;
		}
		if (Type=="BOOL")
			addMapBOOL(curQuestion, Label, ValArray);
		if (Type == "STRING"){
			addMapSTR(curQuestion, Label, ValArray);
			++cnt; isClosed = 0;
		}
	}
	if (cnt==2){
        addQuestion2(lv,isClosed);
	}
	return cnt;
}

void WideDesign::GetJson(string input)
{
	ifstream inp;
	inp.open(input);
	IStreamWrapper isw(inp);

	d.ParseStream(isw);

	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);

	d.Accept(writer);

	string jsonStr(buffer.GetString());
}
void WideDesign::Solution()
{
	Value& a = d["result"];
	Value& b = a["value"];
	int size = b.Size();
	for (int i = 0; i < size; i++) {
		string Label = b[i]["label"].GetString();
        vector<string> lv;

		addQuestion("NULL", Label);
        lv.push_back(Label);

		dfs(Label, b[i], QuestionID,lv);
	}
}
