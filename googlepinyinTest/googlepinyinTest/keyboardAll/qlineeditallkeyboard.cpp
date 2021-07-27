#include "qlineeditallkeyboard.h"

QLineEditAllKeyBoard::QLineEditAllKeyBoard(QWidget *parent) : QLineEdit(parent)
{
    pInputContext = new InputContext;
    pInputContext->setFocusObject(this);
}

void QLineEditAllKeyBoard::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        pInputContext->showInputPanel();
//        pInputContext->SetLineText(this->text());
    }
}
