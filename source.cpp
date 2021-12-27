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

#pragma warning (disable:4996)

using namespace rapidjson;
using namespace std;

int main() {
	WideDesign SQLTables;
	SQLTables.GetJson("covid-segmentation-data.json");
	ofstream out("outputFiles\\AllMultiSelectResponsesTable2.sql"); out.close();
	SQLTables.Solution();
	SQLTables.OutputAllQuestionsTable("outputFiles\\AllQuestionsTable.sql");
	SQLTables.OutputAllQuestionsTable2("outputFiles\\AllQuestionsTable2.sql");
	SQLTables.OutputAllOptionsTable("outputFiles\\AllOptionsTable.sql");
	SQLTables.OutputSingleSelectResponsesTable("outputFiles\\AllSingleSelectResponsesTable.sql");
	SQLTables.OutputMultiSelectResponsesTable1("outputFiles\\AllMultiSelectResponsesTable1.sql");
	SQLTables.OutputMultiSelectResponsesTable2("outputFiles\\AllMultiSelectResponsesTable2.sql");
	return 0;
}
