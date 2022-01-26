#ifndef TYPEDEFS_H
#define TYPEDEFS_H
#include <memory>
#include <functional>

class Piece;
class Bishop;
class Rook;
class Knight;
class Pawn;
class Queen;
class Board;
class King;
class Square;
class Interface;
class Game;
class Player;

typedef std::shared_ptr<Piece> PiecePtr;
typedef std::shared_ptr<Bishop> BishopPtr;
typedef std::shared_ptr<Rook> RookPtr;
typedef std::shared_ptr<Knight> KnightPtr;
typedef std::shared_ptr<Pawn> PawnPtr;
typedef std::shared_ptr<Queen> QueenPtr;
typedef std::shared_ptr<King> KingPtr;
typedef std::shared_ptr<Square> SquarePtr;
typedef std::shared_ptr<Interface>InterfacePtr;
typedef std::shared_ptr<Game>GamePtr;
typedef std::shared_ptr<Player>PlayerPtr;
#endif //TYPEDEFS_H
