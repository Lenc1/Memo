#include "setting.h"
#include "ui_setting.h"

setting::setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);
    this->setWindowTitle("设置 ");
}

setting::~setting()
{
    delete ui;
}
