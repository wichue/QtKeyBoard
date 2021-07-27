/*!
 *  @brief     自定义QLineEdit，点击弹出数字键盘
 *  @details
 *  @author    褚伟
 *  @version
 *  @date      2021.7.23
 *  @warning
 *  @copyright
 *  @note
 */
#ifndef QLINEEDITNUMKEYBOARD_H
#define QLINEEDITNUMKEYBOARD_H

#include <QLineEdit>
#include <QMouseEvent>
#include "numkeyboard.h"

class QLineEditNumKeyBoard : public QLineEdit
{
    Q_OBJECT
public:
    explicit QLineEditNumKeyBoard(QWidget *parent = nullptr);

private:
    NumKeyboard *pNumKeyboard;
signals:

public slots:
    void slotNumKeyboardSure();//按下确定按钮
protected:
    virtual void mousePressEvent(QMouseEvent *event);
};

#endif // QLINEEDITNUMKEYBOARD_H
