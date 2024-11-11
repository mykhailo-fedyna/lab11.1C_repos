#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../lab11.1C.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        // Тест для countCharacters
        TEST_METHOD(TestCountCharacters)
        {
            const char* testString = "++--==";
            int plusCount = 0, minusCount = 0, equalCount = 0;

            countCharacters(testString, &plusCount, &minusCount, &equalCount);

            Assert::AreEqual(2, plusCount);    // Очікується 2 символи '+'
            Assert::AreEqual(2, minusCount);   // Очікується 2 символи '-'
            Assert::AreEqual(2, equalCount);   // Очікується 2 символи '='
        }
    };
}
