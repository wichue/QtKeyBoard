/********************************************************************************
** Form generated from reading UI file 'numkeyboard.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUMKEYBOARD_H
#define UI_NUMKEYBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NumKeyboard
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_back;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_del;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_0;
    QPushButton *pushButton_dian;
    QPushButton *pushButton_sure;

    void setupUi(QWidget *NumKeyboard)
    {
        if (NumKeyboard->objectName().isEmpty())
            NumKeyboard->setObjectName(QString::fromUtf8("NumKeyboard"));
        NumKeyboard->resize(598, 546);
        gridLayout = new QGridLayout(NumKeyboard);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit = new QLineEdit(NumKeyboard);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 4);

        pushButton_1 = new QPushButton(NumKeyboard);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        sizePolicy.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_1, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(NumKeyboard);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(NumKeyboard);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_3, 1, 2, 1, 1);

        pushButton_back = new QPushButton(NumKeyboard);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        sizePolicy.setHeightForWidth(pushButton_back->sizePolicy().hasHeightForWidth());
        pushButton_back->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_back, 1, 3, 1, 1);

        pushButton_4 = new QPushButton(NumKeyboard);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_4, 2, 0, 1, 1);

        pushButton_5 = new QPushButton(NumKeyboard);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_5, 2, 1, 1, 1);

        pushButton_6 = new QPushButton(NumKeyboard);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_6, 2, 2, 1, 1);

        pushButton_del = new QPushButton(NumKeyboard);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));
        sizePolicy.setHeightForWidth(pushButton_del->sizePolicy().hasHeightForWidth());
        pushButton_del->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_del, 2, 3, 1, 1);

        pushButton_7 = new QPushButton(NumKeyboard);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_7, 3, 0, 1, 1);

        pushButton_8 = new QPushButton(NumKeyboard);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_8, 3, 1, 1, 1);

        pushButton_9 = new QPushButton(NumKeyboard);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_9, 3, 2, 1, 1);

        pushButton_cancel = new QPushButton(NumKeyboard);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        sizePolicy.setHeightForWidth(pushButton_cancel->sizePolicy().hasHeightForWidth());
        pushButton_cancel->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_cancel, 3, 3, 1, 1);

        pushButton_0 = new QPushButton(NumKeyboard);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        sizePolicy.setHeightForWidth(pushButton_0->sizePolicy().hasHeightForWidth());
        pushButton_0->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_0, 4, 0, 1, 2);

        pushButton_dian = new QPushButton(NumKeyboard);
        pushButton_dian->setObjectName(QString::fromUtf8("pushButton_dian"));
        sizePolicy.setHeightForWidth(pushButton_dian->sizePolicy().hasHeightForWidth());
        pushButton_dian->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_dian, 4, 2, 1, 1);

        pushButton_sure = new QPushButton(NumKeyboard);
        pushButton_sure->setObjectName(QString::fromUtf8("pushButton_sure"));
        sizePolicy.setHeightForWidth(pushButton_sure->sizePolicy().hasHeightForWidth());
        pushButton_sure->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButton_sure, 4, 3, 1, 1);


        retranslateUi(NumKeyboard);

        QMetaObject::connectSlotsByName(NumKeyboard);
    } // setupUi

    void retranslateUi(QWidget *NumKeyboard)
    {
        NumKeyboard->setWindowTitle(QApplication::translate("NumKeyboard", "Form", nullptr));
        pushButton_1->setText(QApplication::translate("NumKeyboard", "1", nullptr));
        pushButton_2->setText(QApplication::translate("NumKeyboard", "2", nullptr));
        pushButton_3->setText(QApplication::translate("NumKeyboard", "3", nullptr));
        pushButton_back->setText(QApplication::translate("NumKeyboard", "\351\200\200\346\240\274", nullptr));
        pushButton_4->setText(QApplication::translate("NumKeyboard", "4", nullptr));
        pushButton_5->setText(QApplication::translate("NumKeyboard", "5", nullptr));
        pushButton_6->setText(QApplication::translate("NumKeyboard", "6", nullptr));
        pushButton_del->setText(QApplication::translate("NumKeyboard", "\346\270\205\347\251\272", nullptr));
        pushButton_7->setText(QApplication::translate("NumKeyboard", "7", nullptr));
        pushButton_8->setText(QApplication::translate("NumKeyboard", "8", nullptr));
        pushButton_9->setText(QApplication::translate("NumKeyboard", "9", nullptr));
        pushButton_cancel->setText(QApplication::translate("NumKeyboard", "\345\217\226\346\266\210", nullptr));
        pushButton_0->setText(QApplication::translate("NumKeyboard", "0", nullptr));
        pushButton_dian->setText(QApplication::translate("NumKeyboard", ".", nullptr));
        pushButton_sure->setText(QApplication::translate("NumKeyboard", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NumKeyboard: public Ui_NumKeyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUMKEYBOARD_H
