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

string WideDesign::modifyString (string x)
{
    string y="";
    for (int i=0;i<(int)x.size();i++)
        if (x[i]=='\'')
            y+="''";
        else y+=x[i];
    return y;
}
void WideDesign::OutputAllQuestionsTable(string output)
{
    ofstream out;
    out.open(output);

    out<<"DROP TABLE IF EXISTS all_questions;\n";

    out<<"CREATE TABLE all_questions(";
    out<<"\n\tQuestionID INT,";
    out<<"\n\tQuestionText VARCHAR(255),";
    out<<"\n\tGroupName VARCHAR(255),";
    out<<"\n\tisClosed BOOLEAN\n);\n";

	for (auto x : AllQuestions) {
        out<<"INSERT INTO all_questions VALUES (";
		out <<x.first <<",'"<< modifyString(x.second.text) << "','" ;
		out << modifyString(x.second.groupName) << "'," << (x.second.isClosed ? "True" : "False")<<");\n";
	}

    out<<"SELECT * FROM all_questions;";

	out.close();
}
void WideDesign::OutputAllQuestionsTable2(string output)
{
    ofstream out;
    out.open(output);
    out<<"DROP TABLE IF EXISTS all_questions2;\n";
    out<<"CREATE TABLE all_questions2(\n";
    out<<"\tQuestionID INT\n";
    out<<");\n\n";

    out<<"ALTER TABLE all_questions2\n";
    for (int i=1;i<maxLevel;i++)
        out<<"ADD COLUMN Level"<<i<<" VARCHAR(255),\n";
    out<<"ADD COLUMN Level"<<maxLevel<<" VARCHAR(255);\n\n";

    for (auto x: AllQuestions2){
        auto y = x.second.level;
        out<<"INSERT INTO all_questions2 (";
        for (int i=0;i<(int)y.size();i++)
            out<<"Level"<<i+1<<',';
        out<<"QuestionID)\n";

        out<<"VALUES (";
        for (int i=0;i<(int)y.size();i++)
            out<<'\''<<modifyString(y[i])<<'\''<<',';
        out<<x.first<<");\n\n";
    }

    out<<"SELECT * FROM all_questions2;";

    out.close();
}
void WideDesign::OutputAllOptionsTable(string output)
{
    ofstream out;
    out.open(output);

    out<<"DROP TABLE IF EXISTS all_options;\n";

    out<<"CREATE TABLE all_options(";
    out<<"\n\tQuestionID INT,";
    out<<"\n\tOptionID INT,";
    out<<"\n\tOptionText VARCHAR(255)\n);\n";

	for (auto x : AllOptions){
        out<<"INSERT INTO all_options VALUES (";
        out<<x.quesId<<","<<x.id<<",'"<<modifyString(x.text)<<"');\n";
	}

    out<<"SELECT * FROM all_options;";

	out.close();
}
void WideDesign::OutputSingleSelectResponsesTable(string output)
{
    ofstream out;
    out.open(output);

    out<<"DROP TABLE IF EXISTS single_select_responses;\n";

    out<<"CREATE TABLE single_select_responses(";
    out<<"\n\tSurveyParticipantID INT\n);\n";
    out<<"\nALTER TABLE single_select_responses\n";

    int size = SingleSelectResponsesColumn.size(), i = 0;
    for (auto question:SingleSelectResponsesColumn){
        int questionID = question.first;                        //List question (column name)
        string text = "\"" + to_string(questionID) + "\"";

        out<<"ADD COLUMN "<<text<<" VARCHAR(255)";
        if (++i<size) out<<",\n";
        else out<<";\n";

        auto response = question.second;
        for (auto x:response) {                                 //x.second: value   x.first:participantID
            SingleSelectResponsesRow[x.first][questionID] = x.second;
        }
    }
    out<<"\n\n";

    for (auto row:SingleSelectResponsesRow){
        int participantID = row.first;
        auto response = row.second;

        out<<"INSERT INTO single_select_responses (";
        for (auto x: response){
            string text = "\"" + to_string(x.first) + "\"";
            out<<text<<",";
        }
        out<<"SurveyParticipantID)\n";

        out<<"VALUES (";
        for (auto x: response){
            string text = '\'' + modifyString(x.second) + '\'';
            out<<text<<",";
        }
        out<<participantID<<");\n\n\n";
    }
    out<<"SELECT * FROM single_select_responses;";

    out.close();
}

//bool cmp(MultiSelectResponsesType1 x, MultiSelectResponsesType1 y)
//{
//    if (x.participantID==y.participantID) return x.questionID<y.questionID;
//    return x.participantID<y.participantID;
//}

void WideDesign::OutputMultiSelectResponsesTable1(string output)
{
    ofstream out;
    out.open(output);

    out<<"DROP TABLE IF EXISTS multi_select_responses;\n";

    out<<"CREATE TABLE multi_select_responses(";
    out<<"\n\tSurveyParticipantID INT,";
    out<<"\n\tQuestionID INT,";
    out<<"\n\tOptionText VARCHAR(255)\n);\n";

    for (auto x: MultiSelectResponses1){
        out<<"INSERT INTO multi_select_responses VALUES (";
        out << x.participantID<<","<<x.questionID<<",'"<<modifyString(x.optionText)<<"');\n";
    }

    out<<"SELECT * FROM multi_select_responses ORDER BY SurveyParticipantID, QuestionID;";

    out.close();
}

void WideDesign::OutputMultiSelectResponsesTable2(string output)
{
    ofstream out;
    out.open(output);

    out<<"DROP TABLE IF EXISTS multi_select_responses2;\n";

    out<<"CREATE TABLE multi_select_responses2(";
    out<<"\n\tSurveyParticipantID INT\n);\n";
    out<<"\nALTER TABLE multi_select_responses2\n";

    int size=MultiSelectOptionsList.size(), i=0;
    for (auto id: MultiSelectOptionsList){
        string text = "Question"+to_string(id.first)+"_Option" + to_string(id.second);
        out<<"ADD COLUMN "<<text<<" VARCHAR(255)";
        if (++i<size) out<<",\n";
        else out<<";\n";
    }
    out<<"\n\n";

    for (auto responses: MultiSelectResponses2){
        int cnt=0;

        out<<"INSERT INTO multi_select_responses2 (";
        for (auto id:responses.second){
            string text = "Question"+to_string(id.first)+"_Option" + to_string(id.second);
            out<<text<<",";
            ++cnt;
        }
        out<<"SurveyParticipantID)\n";

        out<<"VALUES (";
        for (int j=0;j<cnt;j++) out<<"TRUE,";
        out<<responses.first<<");\n\n\n";
    }

    out<<"SELECT * FROM multi_select_responses2;";

    out.close();
}
