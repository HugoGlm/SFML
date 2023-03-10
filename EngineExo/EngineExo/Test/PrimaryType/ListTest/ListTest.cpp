#include "ListTest.h"
#include "../../../Engine/PrimaryType/List/List.h"
#include "../../../Engine/PrimaryType/Boolean/Boolean.h"
#include <iostream>

void Test::ListTest::Test()
{
	Engine::PrimaryType::List<Engine::PrimaryType::String> tab = { "a", "b", "c"};
	checkLow((tab.Count() == 3), "tab count is not equal to 3")
		checkLow((tab[0] == "a"), "tab[0] is not equal to a")

		const size_t _index = tab.Find("a");
	checkLow((_index == 0), "tab.Find[0] is not equal to a")

		LOG(tab)

		tab.Remove("b");
	checkLow((tab.Count() == 2), "tab count is not equal to 2")

	LOG(tab)
}
