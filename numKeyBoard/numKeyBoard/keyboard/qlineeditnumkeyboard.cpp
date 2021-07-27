#include "qlineeditnumkeyboard.h"

QLineEditNumKeyBoard::QLineEditNumKeyBoard(QWidget *parent) : QLineEdit(parent)
{
    pNumKeyboard = new NumKeyboard;
    connect(pNumKeyboard,&NumKeyboard::signalNumKeyboardSure,this,&QLineEditNumKeyBoard::slotNumKeyboardSure);
}

void QLineEditNumKeyBoard::slotNumKeyboardSure()
{
    this->setText(pNumKeyboard->GetLineText());
}

void QLineEditNumKeyBoard::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        pNumKeyboard->show();
        pNumKeyboard->SetLineText(this->text());
    }
}
