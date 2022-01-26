//
// Created by student on 04.07.2021.
//

#include "model/Player.h"


void Player::setPlayerType(bool playerType) {
    Player::playerType = playerType;
}

const std::string &Player::getName() const {
    return name;
}

void Player::setName(const std::string &name) {
    Player::name = name;
}

Player::Player(bool pieceColor) : pieceColor(pieceColor) {}

bool Player::isPieceColor() const {
    return pieceColor;
}

Player::~Player() {

}

bool Player::isPlayerType() const {
    return playerType;
}

int Player::getTurnTime() const {
    return turnTime;
}

void Player::addTurnTime(int turnTime) {
    Player::turnTime += turnTime;
}

int Player::timeLeft(int gameTime) {
    return gameTime-getTurnTime();
}
