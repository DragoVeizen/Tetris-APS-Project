#include <vector>
using namespace std;
#include "Headers/Global.hpp"
#include "Headers/GetWallKickData.hpp"
vector<Position> get_wall_kick_data(bool ishapecheck, unsigned char currentrotation, unsigned char nextrotation)
{
	//We return the wall kick data based on the current and next rotations. We also check whether the shape is I or not
	if (ishapecheck==0)
	{
		switch (currentrotation)
		{
			case 0:
			case 2:
			{
				switch (nextrotation)
				{
					case 1:
					{
						return {{0, 0}, {-1, 0}, {-1, -1}, {0, 2}, {-1, 2}};
					}
					case 3:
					{
						return {{0, 0}, {1, 0}, {1, -1}, {0, 2}, {1, 2}};
					}
				}
			}
			case 1:
			{
				return {{0, 0}, {1, 0}, {1, 1}, {0, -2}, {1, -2}};
			}
			case 3:
			{
				return {{0, 0}, {-1, 0}, {-1, 1}, {0, -2}, {-1, -2}};
			}
		}
		return {{0, 0}};
	}
	else
	{
		switch (currentrotation)
		{
			case 0:
			{
				switch (nextrotation)
				{
					case 1:
					{
						return {{0, 0}, {-2, 0}, {1, 0}, {-2, 1}, {1, -2}};
					}
					case 3:
					{
						return {{0, 0}, {-1, 0}, {2, 0}, {-1, -2}, {2, 1}};
					}
				}
			}
			case 1:
			{
				switch (nextrotation)
				{
					case 0:
					{
						return {{0, 0}, {2, 0}, {-1, 0}, {2, -1}, {-1, 2}};
					}
					case 2:
					{
						return {{0, 0}, {-1, 0}, {2, 0}, {-1, -2}, {2, 1}};
					}
				}
			}
			case 2:
			{
				switch (nextrotation)
				{
					case 1:
					{
						return {{0, 0}, {1, 0}, {-2, 0}, {1, 2}, {-2, -1}};
					}
					case 3:
					{
						return {{0, 0}, {2, 0}, {-1, 0}, {2, -1}, {-1, 2}};
					}
				}
			}
			case 3:
			{
				switch (nextrotation)
				{
					case 0:
					{
						return {{0, 0}, {1, 0}, {-2, 0}, {1, 2}, {-2, -1}};
					}
					case 2:
					{
						return {{0, 0}, {-2, 0}, {1, 0}, {-2, 1}, {1, -2}};
					}
				}
			}
		}
		return {{0, 0}};
	}
}