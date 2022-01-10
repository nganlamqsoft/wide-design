#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <fstream>

#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/ostreamwrapper.h"

#define _BOOL "BOOL"
#define _TABLE "TABLE"
#define _INT "INT"
#define _STRING "STRING"
#define _AddResponseValue 1
#define _AddQuestionValue 2

using namespace rapidjson;
using namespace std;

class WideDesign{
private:
    struct AllQuestionsType{
        string text,groupName;
        bool isClosed;
    };
    struct AllQuestionsType2{
        vector<string> level;
        bool isClosed;
    };
    struct OptionsType{
        int id,quesId;
        string text;
    };
    struct MultiSelectResponsesType1{
        int participantID, questionID;
        string optionText;
    };

    int QuestionID_ = 0, QuestionID2_ = 0, OptionID_ = 0, NumParticipants_ = 0, MaxLevel_ = 0;

    map<int, AllQuestionsType> AllQuestions;
    map<int, AllQuestionsType2 >AllQuestions2;
    vector<OptionsType> AllOptions;
    map<string,int> OptionsMap;
    map<int,map<int,string> > SingleSelectResponsesColumn, SingleSelectResponsesRow;
    set<int> MultiSelectQuestions;
    set<pair<int,int> > MultiSelectOptionsList;         //First: QuestionID, Second: OptionID
    vector<MultiSelectResponsesType1> MultiSelectResponses1;
    map<int, vector<pair<int,int>> > MultiSelectResponses2;

    Document JsonObject_;

public:
    //Add to storages
    void AddQuestion(string groupName, string text);
    void AddQuestion2(vector<string> lv, bool type);
    void AddMultiSelectResponse(int curQuestion, int participantID, string optionText, int optionID);
    void TransferToMultiSelect(int curQuestion, bool &isMulti);
    void AddMapBOOL(int curQuestion, string val, Value& arr);
    void AddMapINT(int curQuestion, string val, Value& arr);
    void AddMapSTR(int curQuestion, string val, Value& arr);

    //Solution
    int dfs(string str, Value& u, int curQuestion, vector<string> lv);
    void GetJson(string input);
    void Solution();

    //Output to files
    string modifyString (string x);
    void OutputAllQuestionsTable(string output);
    void OutputAllQuestionsTable2(string output);
    void OutputAllOptionsTable(string output);
    void OutputSingleSelectResponsesTable(string output);
    void OutputMultiSelectResponsesTable1(string output);
    void OutputMultiSelectResponsesTable2(string output);

};
