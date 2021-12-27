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

void WideDesign::addQuestion(string groupName, string text)
{
	AllQuestions[++QuestionID].groupName = groupName;
	AllQuestions[QuestionID].text = text;
	OptionID = 0;
}
void WideDesign::addQuestion2(vector<string> lv, bool type)
{
    QuestionID2++;
    reverse(lv.begin(),lv.end());
    AllQuestions2[QuestionID2].level = lv;
    AllQuestions2[QuestionID2].isClosed = type;
    maxLevel = max(maxLevel,(int)lv.size());
}
void WideDesign::addMultiSelectResponse(int curQuestion, int participantID, string optionText, int optionID)
{
    MultiSelectResponses1.push_back({participantID,curQuestion,optionText});
    MultiSelectResponses2[participantID].push_back({curQuestion,optionID});
}

void WideDesign::TransferToMultiSelect(int curQuestion, bool &isMulti)
{
    isMulti = 1;
    for (auto x:SingleSelectResponsesColumn[curQuestion]){               //x.first: participantID    x.second: optionText
        MultiSelectResponses1.push_back({x.first,curQuestion,x.second});


        int columnName = OptionsMap[x.second];
        MultiSelectOptionsList.insert({curQuestion,columnName});
        MultiSelectResponses2[x.first].push_back({curQuestion,columnName});
    }
}

void WideDesign::addMapBOOL(int curQuestion, string val, Value& arr)
{
    bool isMulti = MultiSelectQuestions.find(curQuestion) != MultiSelectQuestions.end();

    AllQuestions[curQuestion].isClosed=1;
	AllOptions.push_back({++OptionID, curQuestion, val});
	OptionsMap[val] = OptionID;

	numParticipants = max(numParticipants, (int) arr.Size());

	for (int i = 0; i < (int)arr.Size(); i++)
        if (arr[i] ==  1){
            if (isMulti){
                MultiSelectOptionsList.insert({curQuestion,OptionID});
                addMultiSelectResponse(curQuestion, i+1, val, OptionID);
                continue;
            }
            if (SingleSelectResponsesColumn[curQuestion].find(i+1) == SingleSelectResponsesColumn[curQuestion].end())
                SingleSelectResponsesColumn[curQuestion][i+1]=val;
            else {
                TransferToMultiSelect(curQuestion, isMulti);
                MultiSelectOptionsList.insert({curQuestion,OptionID});
                addMultiSelectResponse(curQuestion, i+1, val, OptionID);

                MultiSelectQuestions.insert(curQuestion);
                SingleSelectResponsesColumn.erase(SingleSelectResponsesColumn.find(curQuestion));
            }
        }
}

void WideDesign::addMapINT(int curQuestion, string val, Value& arr)
{
	for (int i = 0; i < (int)arr.Size(); i++)
		SingleSelectResponsesColumn[curQuestion][i+1]=to_string(arr[i].GetInt());
}
void WideDesign::addMapSTR(int curQuestion, string val, Value& arr)
{
	for (int i = 0; i < (int)arr.Size(); i++)
		SingleSelectResponsesColumn[curQuestion][i+1]=arr[i].GetString();
}


