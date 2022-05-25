#include <vector>
using namespace std;
#include "Headers/Global.hpp"
#include "Headers/GetTetromino.hpp"

vector<Position> get_tetromino(unsigned char i_shape, unsigned char i_x, unsigned char i_y)
{
	
	vector<Position> output_tetromino(4);

	
	switch (i_shape)
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
		mino.x += i_x;
		mino.y += i_y;
	}

	
	return output_tetromino;
}