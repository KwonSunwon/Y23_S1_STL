//-------------------------------------------------------
// 2023 1학기 STL 3월 21일 (3주 2)
//-------------------------------------------------------
// 파일 예제
//-------------------------------------------------------
// 코딩환경 - VS RELEASE/X64, C++표준 - LATEST, SDL/아니오
//-------------------------------------------------------

#INCLUDE <IOSTREAM>
#INCLUDE <FSTREAM>
#INCLUDE <ALGORITHM>
#INCLUDE "SAVE.HPP"

// [문제] "MAIN.CPP"를 읽어 소문자를 대문자로 변환하여
// "MAIN_UPPER.CPP"에 저장하라.

INT MAIN()
{
	SAVE("MAIN.CPP");

	STD::IFSTREAM IN{ "MAIN.CPP" };
	STD::OFSTREAM OUT{ "MAIN_UPPER.CPP " };

	STD::TRANSFORM(STD::ISTREAMBUF_ITERATOR<CHAR>{IN}, {},
		STD::OSTREAMBUF_ITERATOR<CHAR>{OUT},
		[](CHAR C) {
			RETURN TOUPPER(C);
		});
}
