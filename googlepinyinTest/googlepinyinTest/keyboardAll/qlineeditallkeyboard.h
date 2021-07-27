/*!
 *  @brief     自定义QLineEdit，点击弹出软键盘，支持中文输入
 *  @details
 *  @author    褚伟
 *  @version
 *  @date      2021.7.23
 *  @warning
 *  @copyright
 *  @note
 */
#ifndef QLINEEDITALLKEYBOARD_H
#define QLINEEDITALLKEYBOARD_H

#include <QLineEdit>
#include "inputcontext.h"

class QLineEditAllKeyBoard : public QLineEdit
{
    Q_OBJECT
public:
    explicit QLineEditAllKeyBoard(QWidget *parent = nullptr);

private:
    InputContext *pInputContext;
signals:

public slots:
protected:
    virtual void mousePressEvent(QMouseEvent *event);
};

#endif // QLINEEDITALLKEYBOARD_H
