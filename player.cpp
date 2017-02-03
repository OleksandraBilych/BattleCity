#include "player.h"

Player::Player() {
    qDebug() << "Constructor: Player";
}

Player::~Player() {
    qDebug() << "Destructor: Player";
}

const std::string& Player::getName() const {
    return name;
}

void Player::setName(const std::string& value) {
    name = value;
}

void Player::rotate(Rotate value) {

}

void Player::attack(float value) {

}
