#include "boardClear.h"

void clearBoard()
{
    

	for (int i = 0;i < 15;i++)
		for (int j = 0;j < 15;j++)
		{
			isHave[i][j] = 0;
			score[i][j] = 0;
			blackScore[i][j] = 0;
			whiteScore[i][j] = 0;
		}
}