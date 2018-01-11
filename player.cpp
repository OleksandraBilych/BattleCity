#include "player.h"
#include <QGuiApplication>
#include <QWindow>

Player::Player(float hitPointsLimit, float damage, const std::string& name,
               int coordinate_x, int coordinate_y, QQuickItem* parent)
    : Tank(parent)
{
    qDebug() << "Constructor: Player";

    this->hitPointsLimit = hitPointsLimit;
    this->damage = damage;
    this->name = name;
    hitPoints = hitPointsLimit;
    direction = Direction::dir_up;
    this->coordinate_x = coordinate_x;
    this->coordinate_y = coordinate_y;
    isPlayer = true;
}

Player::Player(QQuickItem* parent)
    : Tank(parent)
{
    qDebug() << "Constructor: Player";

    this->hitPointsLimit = 150;
    this->damage = 50;
    this->name = "Sasha";
    hitPoints = 150;
    direction = Direction::dir_up;
    isPlayer = true;
}

Player::~Player()
{
    qDebug() << "Destructor: Player";
}

const std::string& Player::getName() const
{
    return name;
}

void Player::setName(const std::string& value)
{
    name = value;
}

void Player::rotate(int value)
{
    updateDirection(90);
    qDebug() << "Update direction";
}

void Player::rotatePlayer()
{
    updateDirection(90);
    qDebug() << "Update direction";
}

void Player::move()
{
    if ( direction == Direction::dir_down) {
        coordinate_y += 10;
        emit YChanged(coordinate_y);

    } else if (direction == Direction::dir_up) {
        coordinate_y -= 10;
        emit YChanged(coordinate_y);

    } else if (direction == Direction::dir_left) {
        coordinate_x -= 10;
        emit XChanged(coordinate_x);

    } else if (direction == Direction::dir_right) {
        coordinate_x += 10;
        emit XChanged(coordinate_x);
    }
}
