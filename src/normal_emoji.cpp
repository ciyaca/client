#include "normal_emoji.h"
#include "ui_normal_emoji.h"

normal_emoji::normal_emoji(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::normal_emoji)
{
    ui->setupUi(this);
}

normal_emoji::~normal_emoji()
{
    delete ui;
}
