#ifndef MAP_H
#define MAP_H

#include <QFile>
#include <QPainter>
#include <QString>
#include <QTextStream>
#include <QVector>

enum class CellType {
  Wall,
  Grass
  // to be continued
};

class Map {
 public:
  explicit Map(int map_number);
  void UpdateCoordinates(int upper_left_x, int upper_left_y, int width,
                         int height);
  void DrawMap(QPainter &painter);

 public:
  CellType GetField(int cell_x, int cell_y) const;
  int GetNumberOfCellsHorizontally() const;
  int GetNumberOfCellsVertically() const;
  int GetUpperLeftX() const;
  int GetUpperLeftY() const;
  int GetWidth() const;
  int GetHeight() const;
  int GetTankInitCellX() const;
  int GetTankInitCellY() const;

 private:
  QVector<QVector<CellType>> map_;

  // координаты карты в окне
  int cur_upper_left_x_;
  int cur_upper_left_y_;
  int cur_width_;
  int cur_height_;

  // координаты исходной для этой карты ячейки пользовательского танка
  int tank_init_cell_x_;
  int tank_init_cell_y_;
};

#endif  // MAP_H
