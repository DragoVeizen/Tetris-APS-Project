#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
#include "Headers/Global.hpp"
#include "Headers/GetTetromino.hpp"
#include "Headers/GetWallKickData.hpp"
#include "Headers/Tetromino.hpp"
int main()
{
	bool game_end = 0;
	bool insta_drop = 0;
	bool rotated = 0;
	unsigned lag = 0;
	unsigned lines_cleared = 0;
	unsigned char cleartimer = 0;
	unsigned char current_fall_speed = START_FALL_SPEED;
	unsigned char falltimer = 0;
	unsigned char movetimer = 0;
	unsigned char nextshape;
	unsigned char softtimer = 0;
	chrono::time_point<chrono::steady_clock> prevtime;
	// Code to randomise the falling tetrominoes using index 0->6
	random_device random_device;
	default_random_engine random_engine(random_device());
	uniform_int_distribution<unsigned short> shape_distribution(0, 6);
	vector<bool> clearlines(ROWS, 0);
	// Different color preset for tetrominoes
	vector<Color> cell_colors = {
		Color(36, 36, 85),
		Color(0, 219, 255),
		Color(0, 36, 255),
		Color(255, 146, 0),
		Color(255, 219, 0),
		Color(0, 219, 0),
		Color(146, 0, 255),
		Color(219, 0, 0),
		Color(73, 73, 85)};
	// Initialise Game Matrix
	vector<vector<unsigned char>> matrix(COLUMNS, vector<unsigned char>(ROWS));
	Event event;
	// SFML code for rendering game matrix
	RenderWindow window(VideoMode(2 * CELL_SIZE * COLUMNS * SCREEN_RESIZE, CELL_SIZE * ROWS * SCREEN_RESIZE), "Tetris", Style::Close);
	window.setView(View(FloatRect(0, 0, 2 * CELL_SIZE * COLUMNS, CELL_SIZE * ROWS)));
	Tetromino tetromino(static_cast<unsigned char>(shape_distribution(random_engine)), matrix);
	nextshape = static_cast<unsigned char>(shape_distribution(random_engine));
	// Storing time using chrono library
	prevtime = chrono::steady_clock::now();
	while (window.isOpen())
	{
		unsigned delta_time = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - prevtime).count();
		// Increasing lag  with change in time
		lag += delta_time;
		prevtime += chrono::microseconds(delta_time);
		while (framedur <= lag)
		{
			lag -= framedur;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case Event::Closed:
				{
					window.close();
					break;
				}
				case Event::KeyReleased:
				{
					switch (event.key.code)
					{
					case Keyboard::C:
					case Keyboard::Z:
					{
						rotated = 0;
						break;
					}
					case Keyboard::Down:
					{
						softtimer = 0;
						break;
					}
					case Keyboard::Left:
					case Keyboard::Right:
					{
						movetimer = 0;
						break;
					}
					case Keyboard::Space:
					{
						insta_drop = 0;
					}
					}
				}
				}
			}
			if (cleartimer == 0)
			{
				if (game_end == 0)
				{
					if (rotated == 0)
					{
						if (Keyboard::isKeyPressed(Keyboard::C) == 1)
						{
							rotated = 1;
							tetromino.rotate(1, matrix);
						}
						else if (Keyboard::isKeyPressed(Keyboard::Z) == 1)
						{
							rotated = 1;
							tetromino.rotate(0, matrix);
						}
					}
					if (movetimer == 0)
					{
						if (Keyboard::isKeyPressed(Keyboard::Left) == 1)
						{
							movetimer = 1;
							tetromino.move_left(matrix);
						}
						else if (Keyboard::isKeyPressed(Keyboard::Right) == 1)
						{
							movetimer = 1;
							tetromino.move_right(matrix);
						}
					}
					else
					{
						movetimer = (1 + movetimer) % MOVE_SPEED;
					}
					if (insta_drop == 0)
					{
						if (Keyboard::isKeyPressed(Keyboard::Space) == 1)
						{
							insta_drop = 1;
							falltimer = current_fall_speed;
							tetromino.hard_drop(matrix);
						}
					}
					if (softtimer == 0)
					{
						if (Keyboard::isKeyPressed(Keyboard::Down) == 1)
						{
							if (tetromino.move_down(matrix) == 1)
							{
								falltimer = 0;
								softtimer = 1;
							}
						}
					}
					else
					{
						softtimer = (1 + softtimer) % SOFT_DROP_SPEED;
					}
					if (current_fall_speed == falltimer)
					{
						if (tetromino.move_down(matrix) == 0)
						{
							tetromino.update_matrix(matrix);
							for (unsigned char a = 0; a < ROWS; a++)
							{
								bool clear_line = 1;
								for (unsigned char b = 0; b < COLUMNS; b++)
								{
									if (matrix[b][a]==0)
									{
										clear_line = 0;
										break;
									}
								}
								if (clear_line == 1)
								{
									lines_cleared++;
									cleartimer = CLEAR_EFFECT_DURATION;
									clearlines[a] = 1;
									if (lines_cleared % LINES_TO_INCREASE_SPEED == 0)
									{
										current_fall_speed = max<unsigned char>(SOFT_DROP_SPEED, current_fall_speed - 1);
									}
								}
							}
							if (cleartimer == 0)
							{
								game_end = 0 == tetromino.reset(nextshape, matrix);
								nextshape = static_cast<unsigned char>(shape_distribution(random_engine));
							}
						}
						falltimer = 0;
					}
					else
					{
						falltimer++;
					}
				}
				else if (Keyboard::isKeyPressed(Keyboard::Enter) == 1)
				{
					game_end = 0;
					insta_drop = 0;
					rotated = 0;
					lines_cleared = 0;
					current_fall_speed = START_FALL_SPEED;
					falltimer = 0;
					movetimer = 0;
					softtimer = 0;
					for (vector<unsigned char> &a : matrix)
					{
						fill(a.begin(), a.end(), 0);
					}
				}
			}
			else
			{
				cleartimer--;
				if (cleartimer==0)
				{
					for (unsigned char a = 0; a < ROWS; a++)
					{
						if (1 == clearlines[a])
						{
							for (unsigned char b = 0; b < COLUMNS; b++)
							{
								matrix[b][a] = 0;
								for (unsigned char c = a; 0 < c; c--)
								{
									matrix[b][c] = matrix[b][c - 1];
									matrix[b][c - 1] = 0;
								}
							}
						}
					}
					game_end = 0 == tetromino.reset(nextshape, matrix);
					nextshape = static_cast<unsigned char>(shape_distribution(random_engine));
					fill(clearlines.begin(), clearlines.end(), 0);
				}
			}
			if (framedur > lag)
			{
				unsigned char clear_cell_size = static_cast<unsigned char>(2 * round(0.5f * CELL_SIZE * (cleartimer / static_cast<float>(CLEAR_EFFECT_DURATION))));
				RectangleShape cell(Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
				RectangleShape preview_border(Vector2f(5 * CELL_SIZE, 5 * CELL_SIZE));
				preview_border.setFillColor(Color(0, 0, 0));
				preview_border.setOutlineThickness(-1);
				preview_border.setPosition(CELL_SIZE * (1.5f * COLUMNS - 2.5f), CELL_SIZE * (0.25f * ROWS - 2.5f));
				window.clear();
				for (unsigned char a = 0; a < COLUMNS; a++)
				{
					for (unsigned char b = 0; b < ROWS; b++)
					{
						if (0 == clearlines[b])
						{
							cell.setPosition(static_cast<float>(CELL_SIZE * a), static_cast<float>(CELL_SIZE * b));
							if (1 == game_end && 0 < matrix[a][b])
							{
								cell.setFillColor(cell_colors[8]);
							}
							else
							{
								cell.setFillColor(cell_colors[matrix[a][b]]);
							}
							window.draw(cell);
						}
					}
				}
				cell.setFillColor(cell_colors[8]);
				if (game_end == 0)
				{
					for (Position &mino : tetromino.get_ghost_minos(matrix))
					{
						cell.setPosition(static_cast<float>(CELL_SIZE * mino.x), static_cast<float>(CELL_SIZE * mino.y));
						window.draw(cell);
					}
					cell.setFillColor(cell_colors[1 + tetromino.get_shape()]);
				}
				for (Position &mino : tetromino.get_minos())
				{
					cell.setPosition(static_cast<float>(CELL_SIZE * mino.x), static_cast<float>(CELL_SIZE * mino.y));
					window.draw(cell);
				}
				for (unsigned char a = 0; a < COLUMNS; a++)
				{
					for (unsigned char b = 0; b < ROWS; b++)
					{
						if (clearlines[b] == 1)
						{
							cell.setFillColor(cell_colors[0]);
							cell.setPosition(static_cast<float>(CELL_SIZE * a), static_cast<float>(CELL_SIZE * b));
							cell.setSize(Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
							window.draw(cell);
							cell.setFillColor(Color(255, 255, 255));
							cell.setPosition(floor(CELL_SIZE * (0.5f + a) - 0.5f * clear_cell_size), floor(CELL_SIZE * (0.5f + b) - 0.5f * clear_cell_size));
							cell.setSize(Vector2f(clear_cell_size, clear_cell_size));
							window.draw(cell);
						}
					}
				}
				cell.setFillColor(cell_colors[1 + nextshape]);
				cell.setSize(Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
				window.draw(preview_border);
				for (Position &mino : get_tetromino(nextshape, static_cast<unsigned char>(1.5f * COLUMNS), static_cast<unsigned char>(0.25f * ROWS)))
				{
					unsigned short next_tetromino_x = CELL_SIZE * mino.x;
					unsigned short next_tetromino_y = CELL_SIZE * mino.y;
					if (0 == nextshape)
					{
						next_tetromino_y += static_cast<unsigned char>(round(0.5f * CELL_SIZE));
					}
					else if (3 != nextshape)
					{
						next_tetromino_x -= static_cast<unsigned char>(round(0.5f * CELL_SIZE));
					}
					cell.setPosition(next_tetromino_x, next_tetromino_y);
					window.draw(cell);
				}
				window.display();
			}
		}
	}
}