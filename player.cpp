#include "player.h"

Player::Player(float hitPointsLimit, float damage, const std::string& name, QObject* parent) {
    qDebug() << "Constructor: Player";

    this->hitPointsLimit = hitPointsLimit;
    this->damage = damage;
    this->name = name;
    hitPoints = hitPointsLimit;
    direction = Rotate::rotate_top;
    qDebug() << direction;

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
