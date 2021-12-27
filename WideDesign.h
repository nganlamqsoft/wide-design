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

    int QuestionID = 0, QuestionID2 = 0, OptionID = 0, numParticipants = 0, maxLevel = 0;

    map<int, AllQuestionsType> AllQuestions;
    map<int, AllQuestionsType2 >AllQuestions2;
    vector<OptionsType> AllOptions;
    map<string,int> OptionsMap;
    map<int,map<int,string> > SingleSelectResponsesColumn, SingleSelectResponsesRow;
    set<int> MultiSelectQuestions;
    set<pair<int,int> > MultiSelectOptionsList;         //First: QuestionID, Second: OptionID
    vector<MultiSelectResponsesType1> MultiSelectResponses1;
    map<int, vector<pair<int,int>> > MultiSelectResponses2;

    Document d;

public:
    void addQuestion(string groupName, string text);
    void addQuestion2(vector<string> lv, bool type);
    void addMultiSelectResponse(int curQuestion, int participantID, string optionText, int optionID);
    void TransferToMultiSelect(int curQuestion, bool &isMulti);
    void addMapBOOL(int curQuestion, string val, Value& arr);
    void addMapINT(int curQuestion, string val, Value& arr);
    void addMapSTR(int curQuestion, string val, Value& arr);
    int dfs(string str, Value& u, int curQuestion, vector<string> lv);
    void GetJson(string input);
    void Solution();
    string modifyString (string x);
    void OutputAllQuestionsTable(string output);
    void OutputAllQuestionsTable2(string output);
    void OutputAllOptionsTable(string output);
    void OutputSingleSelectResponsesTable(string output);
    void OutputMultiSelectResponsesTable1(string output);
    void OutputMultiSelectResponsesTable2(string output);

};
