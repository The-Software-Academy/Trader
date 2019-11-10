import re
if __name__=='__main__':
	aProjectFile = open("test.pro", 'r')
	aTestSuiteCollection = re.findall(r'.*testsuite.hpp',aProjectFile.read())
	aProjectFile.close()
	aTestSuiteCollection = [x.strip() for  x in aTestSuiteCollection]
	aNewMain = "#include <gtest/gtest.h>\n"
	aNewMain = aNewMain +  "#include <gmock/gmock.h>\n\n"
	for aTestSuite in aTestSuiteCollection:
		aNewMain = aNewMain + "#include " + "\"" + aTestSuite + "\"\n"
	aNewMain = aNewMain + "\n" \
			   "int main(int argc, char *argv[])\n" \
			   "{\n" \
			   "    ::testing::InitGoogleTest(&argc, argv);\n" \
			   "    ::testing::InitGoogleMock(&argc, argv);\n" \
			   "    return RUN_ALL_TESTS();\n" \
			   "}\n"

	aTestMainFile = open("main.cpp", "w+")
	aTestMainFile.write(aNewMain)
	aTestMainFile.close()