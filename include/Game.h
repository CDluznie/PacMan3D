#ifndef __GAME_H__
#define __GAME_H__

#include <Board.h>
#include <Pacman.h>
#include <Ghost.h>
#include <PointOfView.h>
#include <GameRepresentation.h>
#include <json/json.hpp>
#include <string>
#include <vector>

using json = nlohmann::json;

using namespace std;

class Game {

public:

    static Game fromJSON(const json &jsonGame);

    static Game fromJSONFile(const string &filePath);

    PointOfView *getPointOfView();

    void orientPacman(Utils::Orientation orientation);

    const GameRepresentation &getRepresentation() const;

    void iterate();

private:

    Board _board;
    Pacman _pacman;
    vector<Ghost *> _ghosts;
    
    PointOfView _pointOfView;

    GameRepresentation _representation;

    Game(const Board & board, const Pacman & pacman, const vector<Ghost *> & ghosts);

    void setSquare(const BoardPosition &position);
    void setPacman();
    void setGhost(const Ghost * ghost);

    void cleanSquare(const BoardPosition &position);
    void cleanPacman();
    void cleanGhost(const Ghost * ghost);
    
    void iteratePacman();
    void iterateGhost(Ghost * ghost);

};

#endif
