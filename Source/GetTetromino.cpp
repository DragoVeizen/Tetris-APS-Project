#include <vector>
using namespace std;
#include "Headers/Global.hpp"
#include "Headers/GetTetromino.hpp"
vector<Position> get_tetromino(unsigned char ishape, unsigned char x, unsigned char y)
{
	
	vector<Position> output_tetromino(4);
	
	switch (ishape)
	{
		//I- Shaped 
		case 0:
		{
			output_tetromino[0] = {1, -1};
			output_tetromino[1] = {0, -1};
			output_tetromino[2] = {-1, -1};
			output_tetromino[3] = {-2, -1};
			break;
		}
		//L-shaped
		case 1:
		{
			output_tetromino[0] = {0, 0};
			output_tetromino[1] = {1, 0};
			output_tetromino[2] = {-1, -1};
			output_tetromino[3] = {-1, 0};
			break;
		}
		//J-shaped
		case 2:
		{
			output_tetromino[0] = {0, 0};
			output_tetromino[1] = {1, 0};
			output_tetromino[2] = {1, -1};
			output_tetromino[3] = {-1, 0};
			break;
		}
		//o-shaped or simple square
		case 3:
		{
			output_tetromino[0] = {0, 0};
			output_tetromino[1] = {0, -1};
			output_tetromino[2] = {-1, -1};
			output_tetromino[3] = {-1, 0};
			break;
		}
		//z-shaped
		case 4:
		{
			output_tetromino[0] = {0, 0};
			output_tetromino[1] = {1, -1};
			output_tetromino[2] = {0, -1};
			output_tetromino[3] = {-1, 0};
			break;
		}
		//T-shaped
		case 5:
		{
			output_tetromino[0] = {0, 0};
			output_tetromino[1] = {1, 0};
			output_tetromino[2] = {0, -1};
			output_tetromino[3] = {-1, 0};
			break;
		}
		//S-shaped
		case 6:
		{
			output_tetromino[0] = {0, 0};
			output_tetromino[1] = {1, 0};
			output_tetromino[2] = {0, -1};
			output_tetromino[3] = {-1, -1};
		}
	}
	
	for (Position& mino : output_tetromino)
	{
		mino.x += x;
		mino.y += y;
	}
	
	return output_tetromino;
}