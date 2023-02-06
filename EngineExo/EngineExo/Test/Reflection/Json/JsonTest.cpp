#include "JsonTest.h"
#include "ATest.h"
#include <filesystem>
#include <fstream>

void Test::JsonTest::Test()
{
	ATest a = ATest();
	const std::string _path = std::filesystem::current_path().parent_path().string();
	std::ofstream _outFile = std::ofstream(_path + "\\a.asset");
	a.Serialize(_outFile);
	_outFile.close();

	ATest c = ATest();
	std::ifstream _inFile = std::ifstream(_path + "\\a.asset");
	c.DeSerialize(_inFile);
	_inFile.close();
}
