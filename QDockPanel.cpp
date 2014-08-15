#include "QDockPanel.h"
#include <QResizeEvent>
#include <QPainter>

QDockPanel::QDockPanel()
    :QWidget(NULL,Qt::FramelessWindowHint),
     contensWidget(NULL),frameWidth(3),titleRectHeight(20)
{

}

void QDockPanel::paintEvent(QPaintEvent*)
{
    QPainter p(this);

    p.fillRect(titleRect,Qt::blue);
    p.setPen(QPen(Qt::white));
    p.drawText(titleRect,Qt::AlignVCenter,windowTitle());
}

void QDockPanel::resizeEvent(QResizeEvent* e)
{
    titleRect.setLeft(frameWidth);
    titleRect.setTop(frameWidth);
    titleRect.setWidth(e->size().width() - frameWidth*2);
    titleRect.setHeight(titleRectHeight);

    resetContensWidgetPosAndSize();
}

void QDockPanel::resetContensWidgetPosAndSize()
{
    if (!contensWidget)
    {
        return;
    }

    if (contensWidget->parentWidget() != this)
    {
        contensWidget->setParent(this);
    }

    contensWidget->move(frameWidth,frameWidth * 2 + titleRectHeight);
    contensWidget->resize(width() - frameWidth * 2,height() - frameWidth * 2 - titleRectHeight);
}