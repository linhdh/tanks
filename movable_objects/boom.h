#ifndef MOVABLE_OBJECTS_BOOM_H_
#define MOVABLE_OBJECTS_BOOM_H_

#include <QMediaPlayer>
#include <QPainter>

#include <list>
#include <memory>
#include <utility>
#include <vector>

#include "tank.h"

class Boom : public Movable {
 public:
  Boom(std::shared_ptr<const Map> map, const std::shared_ptr<Movable>& tank,
       int speed);
  ~Boom() override = default;

  void UpdateCoordinates(Coordinates cell) override;
  void Draw(QPainter* painter) override;

  void StartMovement(
      const std::list<std::shared_ptr<Tank>>&,
      std::list<std::pair<std::shared_ptr<Tank>, Coordinates>>*,
      std::vector<std::vector<std::shared_ptr<StaticObject>>>*,
      int number_of_cells) override;

 private:
  QMediaPlayer boom_sound_;
};

#endif  // MOVABLE_OBJECTS_BOOM_H_
