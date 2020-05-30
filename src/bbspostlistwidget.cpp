#include "bbspostlistwidget.h"

BBSPostListWidget::BBSPostListWidget(QWidget *parent) : QWidget(parent)
{
    this->__layout = new QVBoxLayout;
}

void BBSPostListWidget::addWidget(QWidget* w)
{
    __layout->addWidget(w);
    this->setLayout(__layout);
}
