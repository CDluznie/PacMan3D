#ifndef __BOARD_H__
#define __BOARD_H__

#include <BoardPosition.h>
#include <BoardSquare.h>
#include <GameRepresentation.h>
#include <map>
#include <vector>
#include <json/json.hpp>

using namespace std;

using json = nlohmann::json;

class Board {

public:

	static Board fromJSON(const json & jsonBoard);
	
	Board(const Board & other);
	
	~Board();

	vector<BoardPosition> getPositions() const;

	BoardSquare * getSquare(const BoardPosition & position) const;

	BoardSquare *operator[](const BoardPosition &position) const;

	Board &operator=(const Board &other);

	json toJSON() const;
			
private:
 
	map<BoardPosition, BoardSquare *> _squares;
	map<BoardPosition, BoardSquare *> _squares_init;

	Board(const map<BoardPosition, BoardSquare *> & squares);

};

#endif
