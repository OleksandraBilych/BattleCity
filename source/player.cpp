#include "player.h"

Player::Player(float hitPointsLimit, float damage, const std::string& name, QQuickItem* parent) :
    Tank(parent) {
    qDebug() << "Constructor: Player";

    this->hitPointsLimit = hitPointsLimit;
    this->damage = damage;
    this->name = name;
    hitPoints = hitPointsLimit;
    direction = Direction::dir_up;
    coordinate_x = 300;
    coordinate_y = 580;
    isPlayer = true;
}

Player::Player(QQuickItem* parent) : Tank(parent) {
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
