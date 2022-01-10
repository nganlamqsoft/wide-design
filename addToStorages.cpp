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

#define _BOOL "BOOL"
#define _TABLE "TABLE"
#define _INT "INT"
#define _STRING "STRING"
#define _AddResponseValue 1
#define _AddQuestionValue 2

using namespace rapidjson;
using namespace std;

void WideDesign::AddQuestion(string groupName, string text)
{
    AllQuestions[++QuestionID_].groupName = groupName;
    AllQuestions[QuestionID_].text = text;
    OptionID_ = 0;
}
void WideDesign::AddQuestion2(vector<string> lv, bool type)
{
    QuestionID2_++;
    reverse(lv.begin(), lv.end());
    AllQuestions2[QuestionID2_].level = lv;
    AllQuestions2[QuestionID2_].isClosed = type;
    MaxLevel_ = max(MaxLevel_, (int)lv.size());
}
void WideDesign::AddMultiSelectResponse(int curQuestion, int participantID, string optionText, int OptionID_)
{
    MultiSelectResponses1.push_back({ participantID,curQuestion,optionText });
    MultiSelectResponses2[participantID].push_back({ curQuestion,OptionID_ });
}

void WideDesign::TransferToMultiSelect(int curQuestion, bool& isMulti)
{
    isMulti = 1;
    for (auto x : SingleSelectResponsesColumn[curQuestion]) {               //x.first: participantID    x.second: optionText
        MultiSelectResponses1.push_back({ x.first,curQuestion,x.second });

        int columnName = OptionsMap[x.second];
        MultiSelectOptionsList.insert({ curQuestion,columnName });
        MultiSelectResponses2[x.first].push_back({ curQuestion,columnName });
    }
}

void WideDesign::AddMapBOOL(int curQuestion, string val, Value& arr)
{
    bool isMulti = MultiSelectQuestions.find(curQuestion) != MultiSelectQuestions.end();

    AllQuestions[curQuestion].isClosed = 1;
    AllOptions.push_back({ ++OptionID_, curQuestion, val });
    OptionsMap[val] = OptionID_;

    NumParticipants_ = max(NumParticipants_, (int)arr.Size());

    for (int i = 0; i < (int)arr.Size(); i++)
        if (arr[i] == 1) {
            if (isMulti) {
                MultiSelectOptionsList.insert({ curQuestion,OptionID_ });
                AddMultiSelectResponse(curQuestion, i + 1, val, OptionID_);
                continue;
            }
            if (SingleSelectResponsesColumn[curQuestion].find(i + 1) == SingleSelectResponsesColumn[curQuestion].end())
                SingleSelectResponsesColumn[curQuestion][i + 1] = val;
            else {
                TransferToMultiSelect(curQuestion, isMulti);
                MultiSelectOptionsList.insert({ curQuestion,OptionID_ });
                AddMultiSelectResponse(curQuestion, i + 1, val, OptionID_);

                MultiSelectQuestions.insert(curQuestion);
                SingleSelectResponsesColumn.erase(SingleSelectResponsesColumn.find(curQuestion));
            }
        }
}

void WideDesign::AddMapINT(int curQuestion, string val, Value& arr)
{
    for (int i = 0; i < (int)arr.Size(); i++)
        if (arr[i].IsNull())
            SingleSelectResponsesColumn[curQuestion][i + 1] = "NULL";
        else
            SingleSelectResponsesColumn[curQuestion][i + 1] = to_string(arr[i].GetInt());
}
void WideDesign::AddMapSTR(int curQuestion, string val, Value& arr)
{
    for (int i = 0; i < (int)arr.Size(); i++)
        if (arr[i].IsNull())
            SingleSelectResponsesColumn[curQuestion][i + 1] = "NULL";
        else
            SingleSelectResponsesColumn[curQuestion][i + 1] = arr[i].GetString();
}


