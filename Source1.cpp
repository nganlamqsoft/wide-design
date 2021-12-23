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

#pragma warning (disable: 4996)

using namespace rapidjson;
using namespace std;

struct AllQuestionsType {
    string text, groupName;
    bool isClosed;
};
struct OptionsType {
    int id, quesId;
    string text;
};
struct MultiSelectResponsesType1 {
    int participantID, questionID;
    string optionText;
};

int QuestionID = 0, OptionID = 0, numParticipants = 0;

map<int, AllQuestionsType> AllQuestions;
vector<OptionsType> AllOptions;
map<string, int> OptionsMap;
map<int, map<int, string> > SingleSelectResponsesColumn, SingleSelectResponsesRow;
set<int> MultiSelectQuestions;
set<pair<int, int> > MultiSelectOptionsList;         //First: QuestionID, Second: OptionID
vector<MultiSelectResponsesType1> MultiSelectResponses1;
map<int, vector<pair<int, int>> > MultiSelectResponses2;

Document d;

void addQuestion(string groupName, string text)
{
    AllQuestions[++QuestionID].groupName = groupName;
    AllQuestions[QuestionID].text = text;
    OptionID = 0;
}
void addMultiSelectResponse(int curQuestion, int participantID, string optionText, int optionID)
{
    MultiSelectResponses1.push_back({ participantID,curQuestion,optionText });
    MultiSelectResponses2[participantID].push_back({ curQuestion,optionID });
}

void TransferToMultiSelect(int curQuestion, bool& isMulti)
{
    isMulti = 1;
    for (auto x : SingleSelectResponsesColumn[curQuestion]) {               //x.first: participantID    x.second: optionText
        MultiSelectResponses1.push_back({ x.first,curQuestion,x.second });


        int columnName = OptionsMap[x.second];
        MultiSelectOptionsList.insert({ curQuestion,columnName });
        MultiSelectResponses2[x.first].push_back({ curQuestion,columnName });
    }
}

void addMapBOOL(int curQuestion, string val, Value& arr)
{
    bool isMulti = MultiSelectQuestions.find(curQuestion) != MultiSelectQuestions.end();

    AllQuestions[curQuestion].isClosed = 1;
    AllOptions.push_back({ ++OptionID, curQuestion, val });
    OptionsMap[val] = OptionID;

    numParticipants = max(numParticipants, (int)arr.Size());

    for (int i = 0; i < (int)arr.Size(); i++)
        if (arr[i] == 1) {
            if (isMulti) {
                MultiSelectOptionsList.insert({ curQuestion,OptionID });
                addMultiSelectResponse(curQuestion, i + 1, val, OptionID);
                continue;
            }
            if (SingleSelectResponsesColumn[curQuestion].find(i + 1) == SingleSelectResponsesColumn[curQuestion].end())
                SingleSelectResponsesColumn[curQuestion][i + 1] = val;
            else {
                TransferToMultiSelect(curQuestion, isMulti);
                MultiSelectOptionsList.insert({ curQuestion,OptionID });
                addMultiSelectResponse(curQuestion, i + 1, val, OptionID);

                MultiSelectQuestions.insert(curQuestion);
                SingleSelectResponsesColumn.erase(SingleSelectResponsesColumn.find(curQuestion));
            }
        }
}

void addMapINT(int curQuestion, string val, Value& arr)
{
    for (int i = 0; i < (int)arr.Size(); i++)
        SingleSelectResponsesColumn[curQuestion][i + 1] = to_string(arr[i].GetInt());
}
void addMapSTR(int curQuestion, string val, Value& arr)
{
    for (int i = 0; i < (int)arr.Size(); i++)
        SingleSelectResponsesColumn[curQuestion][i + 1] = arr[i].GetString();
}


int dfs(string str, Value& u, int curQuestion)
{
    int cnt = 1;
    string Type = u["type"].GetString();
    string Label = u["label"].GetString();


    if (Type == "TABLE") {
        Value& val = u["value"];
        int theMax = 0;
        for (int i = 0; i < (int)val.Size(); i++) {
            Value& v = val[i];
            string TypeV = v["type"].GetString();
            string LabelV = v["label"].GetString();
            if (TypeV == "TABLE") {
                addQuestion(str, LabelV);
                theMax = max(theMax, dfs(LabelV, v, QuestionID));
            }
            else {
                theMax = max(theMax, dfs(str, v, curQuestion));
            }
        }
        cnt += theMax;
    }

    if (cnt == 1) {
        Value& ValArray = u["value"];
        if (Type == "INT")
            addMapINT(curQuestion, Label, ValArray);
        if (Type == "BOOL")
            addMapBOOL(curQuestion, Label, ValArray);
        if (Type == "STRING")
            addMapSTR(curQuestion, Label, ValArray);
    }
    return cnt;
}

void GetJson()
{
    ifstream ifs("covid-segmentation-data.json");
    IStreamWrapper isw(ifs);

    d.ParseStream(isw);

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);

    d.Accept(writer);

    string jsonStr(buffer.GetString());
}
void Solution()
{
    Value& a = d["result"];
    Value& b = a["value"];
    int size = b.Size();
    for (int i = 0; i < size; i++) {
        string Label = b[i]["label"].GetString();

        addQuestion("NULL", Label);

        dfs(Label, b[i], QuestionID);
    }
}
string modifyString(string x)
{
    string y = "";
    for (int i = 0; i < (int)x.size(); i++)
        if (x[i] == '\'')
            y += "''";
        else y += x[i];
    return y;
}
void OutputAllQuestionsTable(string output)
{
    ofstream out;
    out.open(output);

    out << "DROP TABLE IF EXISTS all_questions;\n";

    out << "CREATE TABLE all_questions(";
    out << "\n\tQuestionID INT,";
    out << "\n\tQuestionText VARCHAR(255),";
    out << "\n\tGroupName VARCHAR(255),";
    out << "\n\tisClosed BOOLEAN\n);\n";

    for (auto x : AllQuestions) {
        out << "INSERT INTO all_questions VALUES (";
        out << x.first << ",'" << modifyString(x.second.text) << "','";
        out << modifyString(x.second.groupName) << "'," << (x.second.isClosed ? "True" : "False") << ");\n";
    }

    out << "SELECT * FROM all_questions;";

    out.close();
}
void OutputAllOptionsTable(string output)
{
    ofstream out;
    out.open(output);

    out << "DROP TABLE IF EXISTS all_options;\n";

    out << "CREATE TABLE all_options(";
    out << "\n\tQuestionID INT,";
    out << "\n\tOptionID INT,";
    out << "\n\tOptionText VARCHAR(255)\n);\n";

    for (auto x : AllOptions) {
        out << "INSERT INTO all_options VALUES (";
        out << x.quesId << "," << x.id << ",'" << modifyString(x.text) << "');\n";
    }

    out << "SELECT * FROM all_options;";

    out.close();
}
void OutputSingleSelectResponsesTable(string output)
{
    ofstream out;
    out.open(output);

    out << "DROP TABLE IF EXISTS single_select_responses;\n";

    out << "CREATE TABLE single_select_responses(";
    out << "\n\tSurveyParticipantID INT\n);\n";
    out << "\nALTER TABLE single_select_responses\n";

    int size = (int)SingleSelectResponsesColumn.size(), i = 0;
    for (auto question : SingleSelectResponsesColumn) {
        int questionID = question.first;                        //List question (column name)
        string text = "\"" + to_string(questionID) + "\"";

        out << "ADD COLUMN " << text << " VARCHAR(255)";
        if (++i < size) out << ",\n";
        else out << ";\n";

        auto response = question.second;
        for (auto x : response) {                                 //x.second: value   x.first:participantID
            SingleSelectResponsesRow[x.first][questionID] = x.second;
        }
    }
    out << "\n\n";

    for (auto row : SingleSelectResponsesRow) {
        int participantID = row.first;
        auto response = row.second;

        out << "INSERT INTO single_select_responses (";
        for (auto x : response) {
            string text = "\"" + to_string(x.first) + "\"";
            out << text << ",";
        }
        out << "SurveyParticipantID)\n";

        out << "VALUES (";
        for (auto x : response) {
            string text = '\'' + modifyString(x.second) + '\'';
            out << text << ",";
        }
        out << participantID << ");\n\n\n";
    }
    out << "SELECT * FROM single_select_responses;";

    out.close();
}

//bool cmp(MultiSelectResponsesType1 x, MultiSelectResponsesType1 y)
//{
//    if (x.participantID==y.participantID) return x.questionID<y.questionID;
//    return x.participantID<y.participantID;
//}

void OutputMultiSelectResponsesTable1(string output)
{
    ofstream out;
    out.open(output);

    out << "DROP TABLE IF EXISTS multi_select_responses;\n";

    out << "CREATE TABLE multi_select_responses(";
    out << "\n\tSurveyParticipantID INT,";
    out << "\n\tQuestionID INT,";
    out << "\n\tOptionText VARCHAR(255)\n);\n";

    for (auto x : MultiSelectResponses1) {
        out << "INSERT INTO multi_select_responses VALUES (";
        out << x.participantID << "," << x.questionID << ",'" << modifyString(x.optionText) << "');\n";
    }

    out << "SELECT * FROM multi_select_responses ORDER BY SurveyParticipantID, QuestionID;";

    out.close();
}

void OutputMultiSelectResponsesTable2(string output)
{
    ofstream out;
    out.open(output);

    out << "DROP TABLE IF EXISTS multi_select_responses2;\n";

    out << "CREATE TABLE multi_select_responses2(";
    out << "\n\tSurveyParticipantID INT\n);\n";
    out << "\nALTER TABLE multi_select_responses2\n";

    int size = (int)MultiSelectOptionsList.size(), i = 0;
    for (auto id : MultiSelectOptionsList) {
        string text = "Question" + to_string(id.first) + "_Option" + to_string(id.second);
        out << "ADD COLUMN " << text << " VARCHAR(255)";
        if (++i < size) out << ",\n";
        else out << ";\n";
    }
    out << "\n\n";

    for (auto responses : MultiSelectResponses2) {
        int cnt = 0;

        out << "INSERT INTO multi_select_responses2 (";
        for (auto id : responses.second) {
            string text = "Question" + to_string(id.first) + "_Option" + to_string(id.second);
            out << text << ",";
            ++cnt;
        }
        out << "SurveyParticipantID)\n";

        out << "VALUES (";
        for (int j = 0; j < cnt; j++) out << "TRUE,";
        out << responses.first << ");\n\n\n";
    }

    out << "SELECT * FROM multi_select_responses2;";

    out.close();
}

int main() {
    GetJson();
    ofstream out("AllMultiSelectResponsesTable2.sql"); out.close();
    Solution();
    OutputAllQuestionsTable("AllQuestionsTable.sql");
    OutputAllOptionsTable("AllOptionsTable.sql");
    OutputSingleSelectResponsesTable("AllSingleSelectResponsesTable.sql");
    OutputMultiSelectResponsesTable1("AllMultiSelectResponsesTable1.sql");
    OutputMultiSelectResponsesTable2("AllMultiSelectResponsesTable2.sql");
    return 0;
}
