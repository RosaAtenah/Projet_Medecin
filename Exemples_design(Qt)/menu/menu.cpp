#include "menu.h"
#include "./ui_menu.h"

menu::menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);
    this->setWindowTitle("Saisie");
}

menu::~menu()
{
    delete ui;
}
