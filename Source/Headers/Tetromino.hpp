class Tetromino
{
	unsigned char rotation;
	unsigned char shape;
	std::vector<Position> minos;
public:
	Tetromino(unsigned char ishape, const std::vector<std::vector<unsigned char>>& imatrix);
	bool move_down(const std::vector<std::vector<unsigned char>>& imatrix);
	bool reset(unsigned char ishape, const std::vector<std::vector<unsigned char>>& imatrix);
	unsigned char get_shape();
	void hard_drop(const std::vector<std::vector<unsigned char>>& imatrix);
	void move_left(const std::vector<std::vector<unsigned char>>& imatrix);
	void move_right(const std::vector<std::vector<unsigned char>>& imatrix);
	void rotate(bool iclockwise, const std::vector<std::vector<unsigned char>>& imatrix);
	void update_matrix(std::vector<std::vector<unsigned char>>& imatrix);
	std::vector<Position> get_ghost_minos(const std::vector<std::vector<unsigned char>>& imatrix);
	std::vector<Position> get_minos();
};