#include "new_game_dialog.h"

#include "constants.h"

NewGameDialog::NewGameDialog(QWidget* parent)
    : QDialog(parent),
      layout_(new QVBoxLayout(this)),
      switch_map_menu_(new QComboBox(this)),
      switch_tank_menu_(new QComboBox(this)),
      switch_difficulty_menu_(new QComboBox(this)),
      new_game_label_(
          new QLabel(tr("Choose map, tank and difficulty"), this)),
      switch_map_label_(
          new QLabel(QString(tr("Map")) + ":", this)),
      switch_tank_label_(
          new QLabel(QString(tr("Tank")) + ":", this)),
      switch_difficulty_label_(
          new QLabel(QString(tr("Difficulty")) + ":", this)),
      buttons_(new QDialogButtonBox(
          QDialogButtonBox::Ok, Qt::Horizontal, this)) {
  for (int i = 1; i <= constants::kMapsNumber; ++i) {
    switch_map_menu_->addItem(tr("Map") + " " + QString::number(i));
  }

  for (int i = 1; i <= constants::kTanksNumber; ++i) {
    switch_tank_menu_->addItem(tr("Tank") + " " + QString::number(i));
  }

  for (int i = 0; i < constants::kDifficultyLevelsNumber; ++i) {
    switch_difficulty_menu_->addItem(kDifficultyLevelsNames[i]);
  }

  layout_->addWidget(new_game_label_);
  layout_->addWidget(switch_map_label_);
  layout_->addWidget(switch_map_menu_);
  layout_->addWidget(switch_tank_label_);
  layout_->addWidget(switch_tank_menu_);
  layout_->addWidget(switch_difficulty_label_);
  layout_->addWidget(switch_difficulty_menu_);
  layout_->addWidget(buttons_);

  connect(buttons_, &QDialogButtonBox::accepted, this, &NewGameDialog::accept);
  connect(buttons_, &QDialogButtonBox::rejected, this, &NewGameDialog::reject);
}

void NewGameDialog::accept() {
  current_map_number_ = switch_map_menu_->currentIndex();
  current_tank_number_ = switch_tank_menu_->currentIndex();
  current_difficulty_level_ = switch_difficulty_menu_->currentIndex();
  return QDialog::accept();
}

void NewGameDialog::reject() {
  switch_map_menu_->setCurrentIndex(current_map_number_);
  switch_tank_menu_->setCurrentIndex(current_tank_number_);
  switch_difficulty_menu_->setCurrentIndex(current_difficulty_level_);
  return QDialog::reject();
}

int NewGameDialog::GetCurrentMapNumber() const {
  return current_map_number_;
}

int NewGameDialog::GetCurrentTankNumber() const {
  return current_tank_number_;
}

int NewGameDialog::GetCurrentDifficultyLevel() const {
  return current_difficulty_level_;
}
