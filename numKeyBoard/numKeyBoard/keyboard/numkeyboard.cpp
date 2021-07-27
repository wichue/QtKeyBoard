#include "numkeyboard.h"
#include "ui_numkeyboard.h"

NumKeyboard::NumKeyboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NumKeyboard)
{
    ui->setupUi(this);
    InitUiStyle();
    this->setWindowTitle("数字键盘");

    connect(ui->pushButton_0,&QPushButton::clicked,this,&NumKeyboard::slotpushButton_0);
    connect(ui->pushButton_1,&QPushButton::clicked,this,&NumKeyboard::slotpushButton_1);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&NumKeyboard::slotpushButton_2);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&NumKeyboard::slotpushButton_3);
    connect(ui->pushButton_4,&QPushButton::clicked,this,&NumKeyboard::slotpushButton_4);
    connect(ui->pushButton_5,&QPushButton::clicked,this,&NumKeyboard::slotpushButton_5);
    connect(ui->pushButton_6,&QPushButton::clicked,this,&NumKeyboard::slotpushButton_6);
    connect(ui->pushButton_7,&QPushButton::clicked,this,&NumKeyboard::slotpushButton_7);
    connect(ui->pushButton_8,&QPushButton::clicked,this,&NumKeyboard::slotpushButton_8);
    connect(ui->pushButton_9,&QPushButton::clicked,this,&NumKeyboard::slotpushButton_9);
    connect(ui->pushButton_cancel,&QPushButton::clicked,this,&NumKeyboard::slotpushButton_cancel);
    connect(ui->pushButton_sure,&QPushButton::clicked,this,&NumKeyboard::slotpushButton_sure);
    connect(ui->pushButton_dian,&QPushButton::clicked,this,&NumKeyboard::slotpushButton_dian);
    connect(ui->pushButton_back,&QPushButton::clicked,this,&NumKeyboard::slotpushButton_back);
    connect(ui->pushButton_del,&QPushButton::clicked,this,&NumKeyboard::slotpushButton_del);
}

NumKeyboard::~NumKeyboard()
{
    delete ui;
}

void NumKeyboard::InitUiStyle()
{
    ui->pushButton_0->setStyleSheet("QPushButton{font-size : 37px;border:2px groove gray;border-radius:6px;padding:1px 2px;font-family : ""微软雅黑"";}"
                                    "QPushButton:pressed{background-color : rgb(255,255,255);}"
                                    "QPushButton:!hover{background-color: qlineargradient(spread:pad,  x1:0, x2:0, y1:0, y2:1,"
                                    "stop: 0 rgba(255,255,255,255),"
                                    "stop: 0.495 rgba(209,209,209,255),"
                                    "stop: 0.505 rgba(209,209,209,255),"
                                    "stop: 1 rgba(255,255,255,255));}"
                                    );
    ui->pushButton_1->setStyleSheet("QPushButton{font-size : 37px;border:2px groove gray;border-radius:6px;padding:1px 2px;font-family : ""微软雅黑"";}"
                                    "QPushButton:pressed{background-color : rgb(255,255,255);}"
                                    "QPushButton:!hover{background-color: qlineargradient(spread:pad,  x1:0, x2:0, y1:0, y2:1,"
                                    "stop: 0 rgba(255,255,255,255),"
                                    "stop: 0.495 rgba(209,209,209,255),"
                                    "stop: 0.505 rgba(209,209,209,255),"
                                    "stop: 1 rgba(255,255,255,255));}"
                                    );
    ui->pushButton_2->setStyleSheet("QPushButton{font-size : 37px;border:2px groove gray;border-radius:6px;padding:1px 2px;font-family : ""微软雅黑"";}"
                                    "QPushButton:pressed{background-color : rgb(255,255,255);}"
                                    "QPushButton:!hover{background-color: qlineargradient(spread:pad,  x1:0, x2:0, y1:0, y2:1,"
                                    "stop: 0 rgba(255,255,255,255),"
                                    "stop: 0.495 rgba(209,209,209,255),"
                                    "stop: 0.505 rgba(209,209,209,255),"
                                    "stop: 1 rgba(255,255,255,255));}"
                                    );
    ui->pushButton_3->setStyleSheet("QPushButton{font-size : 37px;border:2px groove gray;border-radius:6px;padding:1px 2px;font-family : ""微软雅黑"";}"
                                    "QPushButton:pressed{background-color : rgb(255,255,255);}"
                                    "QPushButton:!hover{background-color: qlineargradient(spread:pad,  x1:0, x2:0, y1:0, y2:1,"
                                    "stop: 0 rgba(255,255,255,255),"
                                    "stop: 0.495 rgba(209,209,209,255),"
                                    "stop: 0.505 rgba(209,209,209,255),"
                                    "stop: 1 rgba(255,255,255,255));}"
                                    );
    ui->pushButton_4->setStyleSheet("QPushButton{font-size : 37px;border:2px groove gray;border-radius:6px;padding:1px 2px;font-family : ""微软雅黑"";}"
                                    "QPushButton:pressed{background-color : rgb(255,255,255);}"
                                    "QPushButton:!hover{background-color: qlineargradient(spread:pad,  x1:0, x2:0, y1:0, y2:1,"
                                    "stop: 0 rgba(255,255,255,255),"
                                    "stop: 0.495 rgba(209,209,209,255),"
                                    "stop: 0.505 rgba(209,209,209,255),"
                                    "stop: 1 rgba(255,255,255,255));}"
                                    );
    ui->pushButton_5->setStyleSheet("QPushButton{font-size : 37px;border:2px groove gray;border-radius:6px;padding:1px 2px;font-family : ""微软雅黑"";}"
                                    "QPushButton:pressed{background-color : rgb(255,255,255);}"
                                    "QPushButton:!hover{background-color: qlineargradient(spread:pad,  x1:0, x2:0, y1:0, y2:1,"
                                    "stop: 0 rgba(255,255,255,255),"
                                    "stop: 0.495 rgba(209,209,209,255),"
                                    "stop: 0.505 rgba(209,209,209,255),"
                                    "stop: 1 rgba(255,255,255,255));}"
                                    );
    ui->pushButton_6->setStyleSheet("QPushButton{font-size : 37px;border:2px groove gray;border-radius:6px;padding:1px 2px;font-family : ""微软雅黑"";}"
                                    "QPushButton:pressed{background-color : rgb(255,255,255);}"
                                    "QPushButton:!hover{background-color: qlineargradient(spread:pad,  x1:0, x2:0, y1:0, y2:1,"
                                    "stop: 0 rgba(255,255,255,255),"
                                    "stop: 0.495 rgba(209,209,209,255),"
                                    "stop: 0.505 rgba(209,209,209,255),"
                                    "stop: 1 rgba(255,255,255,255));}"
                                    );
    ui->pushButton_7->setStyleSheet("QPushButton{font-size : 37px;border:2px groove gray;border-radius:6px;padding:1px 2px;font-family : ""微软雅黑"";}"
                                    "QPushButton:pressed{background-color : rgb(255,255,255);}"
                                    "QPushButton:!hover{background-color: qlineargradient(spread:pad,  x1:0, x2:0, y1:0, y2:1,"
                                    "stop: 0 rgba(255,255,255,255),"
                                    "stop: 0.495 rgba(209,209,209,255),"
                                    "stop: 0.505 rgba(209,209,209,255),"
                                    "stop: 1 rgba(255,255,255,255));}"
                                    );
    ui->pushButton_8->setStyleSheet("QPushButton{font-size : 37px;border:2px groove gray;border-radius:6px;padding:1px 2px;font-family : ""微软雅黑"";}"
                                    "QPushButton:pressed{background-color : rgb(255,255,255);}"
                                    "QPushButton:!hover{background-color: qlineargradient(spread:pad,  x1:0, x2:0, y1:0, y2:1,"
                                    "stop: 0 rgba(255,255,255,255),"
                                    "stop: 0.495 rgba(209,209,209,255),"
                                    "stop: 0.505 rgba(209,209,209,255),"
                                    "stop: 1 rgba(255,255,255,255));}"
                                    );
    ui->pushButton_9->setStyleSheet("QPushButton{font-size : 37px;border:2px groove gray;border-radius:6px;padding:1px 2px;font-family : ""微软雅黑"";}"
                                    "QPushButton:pressed{background-color : rgb(255,255,255);}"
                                    "QPushButton:!hover{background-color: qlineargradient(spread:pad,  x1:0, x2:0, y1:0, y2:1,"
                                    "stop: 0 rgba(255,255,255,255),"
                                    "stop: 0.495 rgba(209,209,209,255),"
                                    "stop: 0.505 rgba(209,209,209,255),"
                                    "stop: 1 rgba(255,255,255,255));}"
                                    );
    ui->pushButton_cancel->setStyleSheet("QPushButton{font-size : 37px;border:2px groove gray;border-radius:6px;padding:1px 2px;font-family : ""微软雅黑"";}"
                                         "QPushButton:pressed{background-color : rgb(255,255,255);}"
                                         "QPushButton:!hover{background-color: qlineargradient(spread:pad,  x1:0, x2:0, y1:0, y2:1,"
                                         "stop: 0 rgba(255,255,255,255),"
                                         "stop: 0.495 rgba(209,209,209,255),"
                                         "stop: 0.505 rgba(209,209,209,255),"
                                         "stop: 1 rgba(255,255,255,255));}"
                                         );
    ui->pushButton_sure->setStyleSheet("QPushButton{font-size : 37px;border:2px groove gray;border-radius:6px;padding:1px 2px;font-family : ""微软雅黑"";}"
                                       "QPushButton:pressed{background-color : rgb(255,255,255);}"
                                       "QPushButton:!hover{background-color: qlineargradient(spread:pad,  x1:0, x2:0, y1:0, y2:1,"
                                       "stop: 0 rgba(255,255,255,255),"
                                       "stop: 0.495 rgba(209,209,209,255),"
                                       "stop: 0.505 rgba(209,209,209,255),"
                                       "stop: 1 rgba(255,255,255,255));}"
                                       );
    ui->pushButton_dian->setStyleSheet("QPushButton{font-size : 37px;border:2px groove gray;border-radius:6px;padding:1px 2px;font-family : ""微软雅黑"";}"
                                       "QPushButton:pressed{background-color : rgb(255,255,255);}"
                                       "QPushButton:!hover{background-color: qlineargradient(spread:pad,  x1:0, x2:0, y1:0, y2:1,"
                                       "stop: 0 rgba(255,255,255,255),"
                                       "stop: 0.495 rgba(209,209,209,255),"
                                       "stop: 0.505 rgba(209,209,209,255),"
                                       "stop: 1 rgba(255,255,255,255));}"
                                       );
    ui->pushButton_back->setStyleSheet("QPushButton{font-size : 37px;border:2px groove gray;border-radius:6px;padding:1px 2px;font-family : ""微软雅黑"";}"
                                       "QPushButton:pressed{background-color : rgb(255,255,255);}"
                                       "QPushButton:!hover{background-color: qlineargradient(spread:pad,  x1:0, x2:0, y1:0, y2:1,"
                                       "stop: 0 rgba(255,255,255,255),"
                                       "stop: 0.495 rgba(209,209,209,255),"
                                       "stop: 0.505 rgba(209,209,209,255),"
                                       "stop: 1 rgba(255,255,255,255));}"
                                       );
    ui->pushButton_del->setStyleSheet("QPushButton{font-size : 37px;border:2px groove gray;border-radius:6px;padding:1px 2px;font-family : ""微软雅黑"";}"
                                      "QPushButton:pressed{background-color : rgb(255,255,255);}"
                                      "QPushButton:!hover{background-color: qlineargradient(spread:pad,  x1:0, x2:0, y1:0, y2:1,"
                                      "stop: 0 rgba(255,255,255,255),"
                                      "stop: 0.495 rgba(209,209,209,255),"
                                      "stop: 0.505 rgba(209,209,209,255),"
                                      "stop: 1 rgba(255,255,255,255));}"
                                      );
    ui->lineEdit->setStyleSheet("QLineEdit{font-size : 37px;border:2px groove gray;border-radius:6px;padding:1px 2px;font-family : ""微软雅黑"";}"
                                );
}

void NumKeyboard::SetLineText(QString str)
{
    ui->lineEdit->setText(str);
    strContent = str;
}

QString NumKeyboard::GetLineText()
{
    return strContent;
}

void NumKeyboard::slotpushButton_0()
{
    int idx = ui->lineEdit->cursorPosition();  //根据光标的位置索引
    if(strContent.left(idx) == "0")       //除了小数外，第一个数不为0
    {
        ui->lineEdit->setCursorPosition(idx);
        ui->lineEdit->setFocus();
        return;
    }
   //  字符串的存储有引用计数，当一个 QString 对象被复制为另一个 QString 对象时，它们实际上指向相同的存储空间，仅仅是增加一个引用计数
    strContent.insert(idx, '0');  //插入字符串str在给定的索引位置对这个字符串,并返回一个引用。 //数据存入strContent
    ui->lineEdit->setText(strContent); //strContent中的内容显示在lineEdit
    ui->lineEdit->setCursorPosition(idx+1); //设置光标的位置 ??不设置好像也可以使用设定光标的位置
    ui->lineEdit->setFocus();  //存在光标
}

void NumKeyboard::slotpushButton_1()
{
    int idx = ui->lineEdit->cursorPosition();
    if(strContent.left(idx) == "0")
    {
        ui->lineEdit->setCursorPosition(idx);
        ui->lineEdit->setFocus();
        return;
    }

    strContent.insert(idx, '1');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::slotpushButton_2()
{
    int idx = ui->lineEdit->cursorPosition();
    if(strContent.left(idx) == "0")
    {
        ui->lineEdit->setCursorPosition(idx);
        ui->lineEdit->setFocus();
        return;
    }

    strContent.insert(idx, '2');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::slotpushButton_3()
{
    int idx = ui->lineEdit->cursorPosition();
    if(strContent.left(idx) == "0")
    {
        ui->lineEdit->setCursorPosition(idx);
        ui->lineEdit->setFocus();
        return;
    }

    strContent.insert(idx, '3');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::slotpushButton_4()
{
    int idx = ui->lineEdit->cursorPosition();
    if(strContent.left(idx) == "0")
    {
        ui->lineEdit->setCursorPosition(idx);
        ui->lineEdit->setFocus();
        return;
    }

    strContent.insert(idx, '4');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::slotpushButton_5()
{
    int idx = ui->lineEdit->cursorPosition();
    if(strContent.left(idx) == "0")
    {
        ui->lineEdit->setCursorPosition(idx);
        ui->lineEdit->setFocus();
        return;
    }

    strContent.insert(idx, '5');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::slotpushButton_6()
{
    int idx = ui->lineEdit->cursorPosition();
    if(strContent.left(idx) == "0")
    {
        ui->lineEdit->setCursorPosition(idx);
        ui->lineEdit->setFocus();
        return;
    }

    strContent.insert(idx, '6');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::slotpushButton_7()
{
    int idx = ui->lineEdit->cursorPosition();
    if(strContent.left(idx) == "0")
    {
        ui->lineEdit->setCursorPosition(idx);
        ui->lineEdit->setFocus();
        return;
    }

    strContent.insert(idx, '7');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::slotpushButton_8()
{
    int idx = ui->lineEdit->cursorPosition();
    if(strContent.left(idx) == "0")
    {
        ui->lineEdit->setCursorPosition(idx);
        ui->lineEdit->setFocus();
        return;
    }

    strContent.insert(idx, '8');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::slotpushButton_9()
{
    int idx = ui->lineEdit->cursorPosition();
    if(strContent.left(idx) == "0")
    {
        ui->lineEdit->setCursorPosition(idx);
        ui->lineEdit->setFocus();
        return;
    }

    strContent.insert(idx, '9');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::slotpushButton_cancel()
{
    this->close();
}

void NumKeyboard::slotpushButton_sure()
{
    qDebug()<<"["<<__FILE__<<"]"<<__LINE__<<__FUNCTION__<<" "<<strContent;
    if(strContent.size()>0)
    {
        if(strContent.at(strContent.size()-1) == ".")
        {
            strContent.remove(strContent.size()-1,1);
            qDebug()<<"["<<__FILE__<<"]"<<__LINE__<<__FUNCTION__<<" "<<strContent;
        }
    }
    emit signalNumKeyboardSure();
    this->close();
}

void NumKeyboard::slotpushButton_dian()
{
    int idx = ui->lineEdit->cursorPosition();

    if(idx==0 || strContent.contains('.'))
    {
        ui->lineEdit->setCursorPosition(idx);
        ui->lineEdit->setFocus();
        return;
    }

    strContent.insert(idx, '.');
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx+1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::slotpushButton_back()
{
    int idx = ui->lineEdit->cursorPosition();
    if(idx == 0)
    {
        ui->lineEdit->setCursorPosition(idx);
        ui->lineEdit->setFocus();
        return;
    }
    strContent.remove(idx-1,1);
    ui->lineEdit->setText(strContent);
    ui->lineEdit->setCursorPosition(idx-1);
    ui->lineEdit->setFocus();
}

void NumKeyboard::slotpushButton_del()
{
    ui->lineEdit->clear();
    strContent.clear();
}
