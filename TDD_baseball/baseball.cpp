#include <stdexcept>
#include <string>

using namespace std;


struct Result
{
	bool solved;
	int strikes;
	int balls;
};
class Baseball
{
public:
	explicit Baseball(const char* str)
	{
		question = str;
	}

	Result guess(string str)
	{
		assertillegalArgument(str);

		if (str == question) {
			return { true, 3,0 };
		}

		bool solved = false;
		int strikes = getStrikeCount(str);
		int balls = getBallCount(str);
		return { solved , strikes, balls };
	}


private:
	void assertillegalArgument(string str)
	{
		if (str == "") {
			throw std::invalid_argument("���� ��������");
		}

		if (str.length() != 3)
		{
			throw std::invalid_argument("3�ڸ� ���� ��������");
		}

		if (isIncludeChar(str))
		{
			throw std::invalid_argument("���� �ܿ� �ٸ� ĳ���Ͱ� �ֽ��ϴ�.");
		}
		if (isDuplicatedNumber(str))
		{
			throw std::invalid_argument("�ߺ����� ����.");
		}
	}

	bool isIncludeChar(const string& str)
	{
		for (char ch : str)
		{
			if (ch >= '0' && ch <= '9')continue;
			return true;
		}
		return false;
	}

	bool isDuplicatedNumber(string str)
	{
		return (str[0] == str[1] || str[0] == str[2] || str[1] == str[2]);
	}

	int getStrikeCount(string guessNumber) {
		int result = 0;
		for (int i = 0; i < 3; i++) {
			int index = question.find(guessNumber[i]);
			if (index == -1) continue;
			if (index != i) continue;
			result++;
		}
		return result;
	}

	int getBallCount(string guessNumber) {
		int result = 0;
		for (int i = 0; i < 3; i++) {
			int index = question.find(guessNumber[i]);
			if (index == -1) continue;
			if (index == i) continue;
			result++;
		}
		return result;
	}


	string question;
};