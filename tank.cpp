#include "tank.h"

Tank::Tank(std::shared_ptr<Map> map, int speed, int rate_of_fire,
           Direction direction)
    : Movable(map, map->GetTankInitCellX(), map->GetTankInitCellY(), direction,
              speed),
      rate_of_fire_(rate_of_fire) {}

void Tank::Draw(QPainter& painter) {
  painter.setBrush(Qt::black);
  painter.save();
  painter.translate(cur_upper_left_x_ + cur_width_ / 2,
                    cur_upper_left_y_ + cur_height_ / 2);
  painter.rotate(current_rotate_degree_);
  painter.drawRect(-cur_width_ / 4, -cur_height_ / 2, cur_width_ / 2,
                   cur_height_);
  painter.restore();
}

int Tank::GetRateOfFire() const { return rate_of_fire_; }
int Tank::GetTimeSinceLastShot() const { return time_since_last_shot_; }

void Tank::IncreaseTimeSinceLastShot(int delta) {
  time_since_last_shot_ += delta;
  time_since_last_shot_ %= (2 * rate_of_fire_);
}
