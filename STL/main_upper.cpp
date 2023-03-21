//-------------------------------------------------------
// 2023 1�б� STL 3�� 21�� (3�� 2)
//-------------------------------------------------------
// ���� ����
//-------------------------------------------------------
// �ڵ�ȯ�� - VS RELEASE/X64, C++ǥ�� - LATEST, SDL/�ƴϿ�
//-------------------------------------------------------

#INCLUDE <IOSTREAM>
#INCLUDE <FSTREAM>
#INCLUDE <ALGORITHM>
#INCLUDE "SAVE.HPP"

// [����] "MAIN.CPP"�� �о� �ҹ��ڸ� �빮�ڷ� ��ȯ�Ͽ�
// "MAIN_UPPER.CPP"�� �����϶�.

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
