#include <QGuiApplication>
#include <QWindow>

#include "player.h"
#include "constants.h"

Player::Player(float hitPointsLimit, float damage, const std::string& name,
               int coordinate_x, int coordinate_y, QObject* parent)
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
    deadTanks = 0;
}

Player::~Player()
{
    qDebug() << "Destructor: Player";
}

const std::string& Player::getName() const
{
    return name;
}

const short Player::getDeadTanks() const
{
    return deadTanks;
}

void Player::setName(const std::string& value)
{
    name = value;
}

void Player::setDeadTanks(short value)
{
    if (deadTanks != value) {
        deadTanks = value;
        emit deadTanksChanged(value);
    }
}

void Player::rotate(int value)
{
    updateDirection(value);
}

void Player::rotatePlayer()
{
    updateDirection(90);
}

void Player::move()
{
    if ( direction == Direction::dir_down) {
        coordinate_y += cellSize;
        emit YChanged(coordinate_y);

    } else if (direction == Direction::dir_up) {
        coordinate_y -= cellSize;
        emit YChanged(coordinate_y);

    } else if (direction == Direction::dir_left) {
        coordinate_x -= cellSize;
        emit XChanged(coordinate_x);

    } else if (direction == Direction::dir_right) {
        coordinate_x += cellSize;
        emit XChanged(coordinate_x);
    }
}

void Player::incrementNumberOfDeadTanks()
{
    deadTanks++;
    emit deadTanksChanged(deadTanks);
}
