#include "keyboardform.h"
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QFontDatabase>
#include <QApplication>
#include <QDebug>

const char *kbNumber = "1234567890";
const char *kbLetter = "qwertyuiopasdfghjklzxcvbnm";
const char *kbSymbol = "!@#$%^&*()-_+=[]{}|\\:;\"<>?";
const int verSpace = 4;
const int horSpace = 4;
const int margins = 4;
const int dialogWidth = 800;//键盘宽度
const int dialogHeight = 300;//键盘高度
const int btnHeight = (dialogHeight - verSpace*5)/5;
const int btnWidth =  (dialogWidth - margins*2 - horSpace*10)/10.8+0.5;

const int hanziCandidate = 7;
const int letter1 = 10;
const int letter2 = 9;
const int letter3 = 7;

KeyboardForm::KeyboardForm(QWidget *parent) : QDialog(parent),
    m_inputMode(ImEn),m_shiftKey(false),m_hanziPageCnt(0),
    m_curHanziPage(0)
{
    installEventFilter(this);

    m_listCharsBtns.clear();
    m_cachePinYin.clear();

    setWindowModality(Qt::WindowModal);
    setWindowFlags(windowFlags() | Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowDoesNotAcceptFocus);

    //图标字体
    int fontId = QFontDatabase::addApplicationFont("./font/FontAwesome.otf");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont icofont(fontName);
    icofont.setPixelSize(20);

    //按键字体，设置按钮样式
    QFont deffont("Courier");
    deffont.setPixelSize(21);

    // 第一行 显示拼音
    m_labPyText = new QLabel;
    //设置拼音和英文的样式
    m_labPyText->setStyleSheet("font-size : 27px;background-color : rgba(209,209,209); border-color: gray; border-width: 1px; border-style: solid; border-radius: 5px;");

    QHBoxLayout *h1 = new QHBoxLayout;
    h1->addWidget(m_labPyText);
//    h1->addStretch();//chw注释

    // 第二行 显示汉字，八个候选项
    QHBoxLayout *h2 = new QHBoxLayout;
    h2->setSpacing(1);
    for (int i = 0; i < hanziCandidate; i++)
    {
        QPushButton *btn = new QPushButton;
        btn->setFont(deffont);
        btn->setFixedHeight(30);
        //设置汉字拼写的样式
        btn->setStyleSheet("QPushButton{border: none; border-image: none; font-size: 15px}");

        h2->addWidget(btn);
        m_listHanzi.append(btn);
        if (i == 0 || i == hanziCandidate-1)
        {
            btn->setEnabled(false);
            btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
            btn->setText(i == 0 ? "\xC2\xAB" : "\xC2\xBB");
        }
        else
        {
            connect(btn, SIGNAL(clicked()), SLOT(hanziClicked()));
        }
    }
    connect(m_listHanzi[0], SIGNAL(clicked()), SLOT(prevPage()));
    connect(m_listHanzi[hanziCandidate-1], SIGNAL(clicked()), SLOT(nextPage()));

    // 拼音+汉子 整个放入pyFrm Widget
//    m_pyFrm = new QWidget;
    m_pyFrm = new QWidget;
    m_pyFrm->setLayout(h2);
    //m_pyFrm->setStyleSheet("background:#FFFFFF");
    QVBoxLayout *pyLayout = new QVBoxLayout;
    pyLayout->addLayout(h1);
    pyLayout->addWidget(m_pyFrm);

    m_pyFrm->setFixedHeight(40);

    // 第三行 数字
    QHBoxLayout *h3 = new QHBoxLayout;

    // 波浪号~
    QPushButton *btnWave = new QPushButton("~");
    btnWave->setFont(deffont);
    btnWave->setFixedSize(btnWidth, btnHeight);
    connect(btnWave, SIGNAL(clicked()), SLOT(numClicked()));//直接输出字符

    h3->addWidget(btnWave);

    for (int j = 0; j < 10; j++)
    {
        QPushButton *btn = new QPushButton(QString(QLatin1Char(kbNumber[j])));
        btn->setFixedSize(btnWidth, btnHeight);
        btn->setFont(deffont);
        connect(btn, SIGNAL(clicked()), SLOT(numClicked()));
        h3->addWidget(btn);
    }

    // 第一行字母

    QHBoxLayout *h4 = new QHBoxLayout;
    for (int j = 0; j < letter1; j++)
    {
        QPushButton *btn = new QPushButton(QString(QLatin1Char(kbLetter[j])));
        btn->setFixedSize(btnWidth, btnHeight);
        btn->setFont(deffont);
        connect(btn, SIGNAL(clicked()), SLOT(letterClicked()));
        h4->addWidget(btn);
        m_listCharsBtns.append(btn);
    }

    QPushButton *btnBack = new QPushButton();
    btnBack->setFont(icofont);
    btnBack->setText(QChar(0xf060));
    btnBack->setFixedSize(btnWidth, btnHeight);
    btnBack->setAutoRepeat(true);
    connect(btnBack, SIGNAL(clicked()), SLOT(backSpace()));
    h4->addWidget(btnBack);

    // 第二行字母

    QHBoxLayout *h5 = new QHBoxLayout;
    h5->addStretch();
    for (int j = 0; j < letter2; j++)
    {
        QPushButton *btn = new QPushButton(QString(QLatin1Char(kbLetter[letter1+j])));
        btn->setFont(deffont);
        btn->setFixedSize(btnWidth, btnHeight);
        connect(btn, SIGNAL(clicked()), SLOT(letterClicked()));
        h5->addWidget(btn);
        m_listCharsBtns.append(btn);
    }

    QPushButton *btnEnter = new QPushButton("ENTER");
    btnEnter->setFont(deffont);
    btnEnter->setFixedSize(btnWidth*2, btnHeight);
    connect(btnEnter, SIGNAL(clicked()), SLOT(enter()));
    h5->addWidget(btnEnter);
    h5->addStretch();

    // 第三行字母

    QHBoxLayout *h6 = new QHBoxLayout;
    m_btnShift = new QPushButton(QChar(0xf062));
    m_btnShift->setFont(icofont);
    m_btnShift->setFixedSize(btnWidth, btnHeight);
    connect(m_btnShift, SIGNAL(clicked()), SLOT(shiftClicked()));
    h6->addWidget(m_btnShift);
    for (int j = 0; j < letter3; j++)
    {
        QPushButton *btn = new QPushButton(QString(QLatin1Char(kbLetter[letter1 + letter2 + j])));
        btn->setFont(deffont);
        btn->setFixedSize(btnWidth, btnHeight);
        connect(btn, SIGNAL(clicked()), SLOT(letterClicked()));
        h6->addWidget(btn);
        m_listCharsBtns.append(btn);
    }

    QString letter(",./");
    for (int j = 0; j < 3; j++)
    {
        QPushButton* btn = new QPushButton(letter.at(j));
        btn->setFont(deffont);
        btn->setFixedSize(btnWidth, btnHeight);
        connect(btn, SIGNAL(clicked()), SLOT(numClicked()));
        h6->addWidget(btn);
    }

    // 第四行

    QHBoxLayout *h7 = new QHBoxLayout;

    m_btnSymbol = new QPushButton(".?123");
    m_btnSymbol->setFont(deffont);
    m_btnSymbol->setFixedSize(btnWidth*1.5, btnHeight);
    connect(m_btnSymbol, SIGNAL(clicked()), SLOT(changeSymbol()));
    h7->addWidget(m_btnSymbol);

    m_btnChange = new QPushButton(QChar(0xf0ac));
    m_btnChange->setFont(icofont);
    m_btnChange->setProperty("Mode", ImEn);
    m_btnChange->setFixedSize(btnWidth, btnHeight);
    connect(m_btnChange, SIGNAL(clicked()), SLOT(changeInputMode()));
    h7->addWidget(m_btnChange);

    m_btnSpace = new QPushButton("英文");  // 空格
    m_btnSpace->setFont(deffont);
    m_btnSpace->setFixedHeight(btnHeight);
    connect(m_btnSpace, SIGNAL(clicked()), SLOT(space()));
    h7->addWidget(m_btnSpace);

    QPushButton *btnSplit = new QPushButton("'");
    btnSplit->setFont(deffont);
    btnSplit->setFixedSize(btnWidth, btnHeight);
    connect(btnSplit, SIGNAL(clicked()), SLOT(letterClicked()));
    h7->addWidget(btnSplit);

    QString text = QChar(0xf11c);
    text.append(QChar(0xf103));
    QPushButton *btnHide = new QPushButton(text);
    btnHide->setFont(icofont);
    btnHide->setFixedSize(btnWidth*1.5, btnHeight);
    connect(btnHide, SIGNAL(clicked()), SLOT(hide()));
    h7->addWidget(btnHide);

    QVBoxLayout *boradLayout = new QVBoxLayout;
    boradLayout->setMargin(margins);
    boradLayout->setSpacing(margins);

    boradLayout->addLayout(h3);
    boradLayout->addLayout(h4);
    boradLayout->addLayout(h5);
    boradLayout->addLayout(h6);
    boradLayout->addLayout(h7);

    // 键盘widget容器
    m_btnFrm = new QWidget();
    m_btnFrm->setLayout(boradLayout);


    // 主布局，拼音、汉字 + 按键
    m_mainLayout = new QVBoxLayout;
    m_mainLayout->setMargin(0);
    m_mainLayout->setSpacing(0);
    m_mainLayout->addLayout(pyLayout);
    m_mainLayout->addWidget(m_btnFrm);
    setLayout(m_mainLayout);

    connect(&m_pinyin, SIGNAL(pinyinTextChanged(QString)), this, SLOT(setText(QString)));
//    setFixedHeight(m_pyFrm->height() + m_labPyText->height() + m_btnFrm->height());
    changeStyle();
}


void KeyboardForm::letterClicked()
{
    QString text = ((QPushButton*)sender())->text();
    if (m_inputMode == ImNum || m_shiftKey || text == "'")
    {
        sendKeyToFocusItem(text);
    }
    else
    {
        m_cachePinYin.append(text);
        m_pinyin.Matching(m_cachePinYin, m_inputMode == ImEn);
        if (m_pinyin.HanziModel.size())
        {
            m_hanziPageCnt = m_pinyin.HanziModel.size() / (hanziCandidate-2)
                    + int(m_pinyin.HanziModel.size() % (hanziCandidate-2) > 0);
            m_curHanziPage = 1;
        }
        else
        {
            m_hanziPageCnt = 0;
        }
        displayHanzi();
    }
}

void KeyboardForm::numClicked()
{
    sendKeyToFocusItem(((QPushButton*)sender())->text());
}

void KeyboardForm::hanziClicked()
{
    sendKeyToFocusItem(((QPushButton*)sender())->text());
    m_cachePinYin.clear();
    m_labPyText->clear();
//    m_labPyText->hide();
    m_hanziPageCnt = 0;
    displayHanzi();
}

void KeyboardForm::setText(QString str)
{
    m_labPyText->setVisible(str.size());
    m_labPyText->setText(str);
}

void KeyboardForm::shiftClicked()
{
    // 切换拼音状态

    if (m_shiftKey)
    {
        m_shiftKey = false;
    }
    else
    {
        m_shiftKey = true;
        m_btnChange->setProperty("Mode", ImEn);
        m_btnSpace->setText("英文");
    }

    // 输出已有的字母
    sendKeyToFocusItem(m_cachePinYin);
    // 所有拼音相关清空

    m_labPyText->clear();
    m_cachePinYin.clear();
    m_hanziPageCnt = 0;
    displayHanzi();

    // 恢复符号
    m_btnSymbol->setText(".?123");

    // 重新布局字母
    for (int i = 0; i < m_listCharsBtns.size(); i++)
    {
        m_listCharsBtns[i]->setText(QString(QLatin1Char(m_shiftKey ? kbLetter[i] - 32 : kbLetter[i])));
    }
}

void KeyboardForm::changeInputMode()
{
    m_btnChange->setProperty("Mode", m_inputMode = m_btnChange->property("Mode").toInt() == ImEn ? ImCn : ImEn);
    m_btnSpace->setText(m_inputMode == ImCn ? "拼音" : "英文");

    for (int i = 0; i < m_listCharsBtns.size(); i++)
    {
        m_listCharsBtns[i]->setText(QString(QLatin1Char(kbLetter[i])));
    }

    // 输出已有的字母
    sendKeyToFocusItem(m_cachePinYin);

    m_labPyText->clear();
    m_cachePinYin.clear();
    m_hanziPageCnt = 0;
    displayHanzi();

    m_btnSymbol->setText(".?123");
    m_shiftKey = false;
    //m_btnShift->setStyleSheet("QPushButton{color:#FFFFFF; border-image: url(:/images/btn2.png); border-width: 5;} QPushButton:pressed{border-image: url(:/images/btn3.png); border-width: 5;}");
}

void KeyboardForm::changeSymbol()
{
    if (m_btnSymbol->text() == ".?123")
    {
        m_btnSymbol->setText("返回");

        // 输出已有的字母
        sendKeyToFocusItem(m_cachePinYin);

        m_hanziPageCnt = 0;
        m_labPyText->clear();
        m_cachePinYin.clear();
        displayHanzi();

        m_shiftKey = false;
        //m_btnShift->setStyleSheet("QPushButton{color:#FFFFFF; border-image: url(:/images/btn2.png); border-width: 5;} QPushButton:pressed{border-image: url(:/images/btn3.png); border-width: 5;}");
        m_inputMode = ImNum;
        m_btnSpace->setText("数字");
        for (int i = 0; i < m_listCharsBtns.size(); i++)
        {
            m_listCharsBtns[i]->setText(kbSymbol[i] == '&' ? "&&" : QString(QLatin1Char(kbSymbol[i])));
        }
    }
    else
    {
        m_btnSymbol->setText(".?123");
        m_inputMode = (InputMode)m_btnChange->property("Mode").toInt();
        m_btnSpace->setText(m_inputMode == ImCn ? "拼音" : "英文");
        for (int i = 0; i < m_listCharsBtns.size(); i++)
        {
            m_listCharsBtns[i]->setText(QString(QLatin1Char(kbLetter[i])));
        }
    }
}

void KeyboardForm::space()
{
    sendKeyToFocusItem(" ");
}

void KeyboardForm::enter()
{
    if (m_cachePinYin.size())
    {
        sendKeyToFocusItem(m_cachePinYin);
        m_cachePinYin.clear();
        m_labPyText->clear();
        m_hanziPageCnt = 0;
        displayHanzi();
    }
    else
    {
        sendKeyToFocusItem("\n");
    }
}

void KeyboardForm::backSpace()
{
    if (m_inputMode == ImNum || m_shiftKey)
    {
        sendKeyToFocusItem("\x7F");
    }
    else
    {
        if (m_cachePinYin.size() > 1)
        {
            m_cachePinYin.remove(m_cachePinYin.size()-1, 1);
            m_pinyin.Matching(m_cachePinYin, m_inputMode == ImEn);
            if (m_pinyin.HanziModel.size())
            {
                int size = hanziCandidate-2;
                m_hanziPageCnt = m_pinyin.HanziModel.size() / size + int(m_pinyin.HanziModel.size() % size > 0);
                m_curHanziPage = 1;
            }
            else
            {
                m_hanziPageCnt = 0;
            }
            displayHanzi();
        }
        else if(1 == m_cachePinYin.size())
        {
            m_cachePinYin.clear();
            m_labPyText->clear();
            m_hanziPageCnt = 0;
            displayHanzi();
        }
        else
        {
            m_cachePinYin.clear();
            m_labPyText->clear();
            sendKeyToFocusItem("\x7F");
        }
    }
}

void KeyboardForm::displayHanzi()
{
    if (m_hanziPageCnt <= 0)
    {
        m_listHanzi[0]->setEnabled(false);
        m_listHanzi[hanziCandidate-1]->setEnabled(false);
        for (int i = 0; i < hanziCandidate-2; i++)
        {
            m_listHanzi[i+1]->setText("");
            m_listHanzi[i+1]->setEnabled(false);
        }
    }
    else if (m_hanziPageCnt == 1)
    {
        m_listHanzi[0]->setEnabled(false);
        m_listHanzi[hanziCandidate-1]->setEnabled(false);
        int len = m_pinyin.HanziModel.size();
        for (int i = 0; i < len; i++)
        {
            m_listHanzi[i+1]->setText(m_pinyin.HanziModel[i]);
            m_listHanzi[i+1]->setEnabled(true);
        }
        for (int i = len; i < hanziCandidate-2; i++)
        {
            m_listHanzi[i+1]->setText("");
            m_listHanzi[i+1]->setEnabled(false);
        }
    }
    else if (m_curHanziPage == 1)
    {
        m_listHanzi[0]->setEnabled(false);
        m_listHanzi[hanziCandidate-1]->setEnabled(true);
        for (int i = 0; i < hanziCandidate-2; i++)
        {
            m_listHanzi[i+1]->hide();
            m_listHanzi[i+1]->setText(m_pinyin.HanziModel[i]);
            m_listHanzi[i+1]->setEnabled(true);
            m_listHanzi[i+1]->show();
        }
    }
    else if (m_curHanziPage == m_hanziPageCnt)
    {
        m_listHanzi[0]->setEnabled(true);
        m_listHanzi[hanziCandidate-1]->setEnabled(false);
        qDebug() << m_pinyin.HanziModel << m_pinyin.HanziModel.size();
        int len = m_pinyin.HanziModel.size() % (hanziCandidate-2);
        int idx = (m_hanziPageCnt - 1) * (hanziCandidate-2);
        if (len == 0)
        {
            len = hanziCandidate-2;
        }

        for (int i = 0; i < len; i++)
        {
            m_listHanzi[i+1]->setText(m_pinyin.HanziModel[idx + i]);
            m_listHanzi[i+1]->setEnabled(true);
        }
        for (int i = len; i < hanziCandidate-2; i++)
        {
            m_listHanzi[i+1]->setText("");
            m_listHanzi[i+1]->setEnabled(false);
        }
    }
    else
    {
        m_listHanzi[0]->setEnabled(true);
        m_listHanzi[hanziCandidate-1]->setEnabled(true);
        int idx = (m_curHanziPage - 1) * (hanziCandidate-2);
        for (int i = 0; i < hanziCandidate-2; i++)
        {
            m_listHanzi[i+1]->setText(m_pinyin.HanziModel[idx + i]);
            m_listHanzi[i+1]->setEnabled(true);
        }
    }
}

bool KeyboardForm::eventFilter(QObject *, QEvent *event)
{
    static QPoint lastPnt;
    static bool isHover = false;
    if(event->type() == QEvent::MouseButtonPress)
    {

        QMouseEvent* e = static_cast<QMouseEvent*>(event);
        if(this->rect().contains(e->pos()) && //is the mouse is clicking the key
                (e->button() == Qt::LeftButton)) //if the mouse click the right key
        {
            lastPnt = e->pos();
            isHover = true;
        }
    }
    else if(event->type() == QEvent::MouseMove && isHover)
    {
        QMouseEvent* e = static_cast<QMouseEvent*>(event);
        int dx = e->pos().x() - lastPnt.x();
        int dy=e->pos().y()-lastPnt.y();
        this->move(this->x()+dx,this->y()+dy);
    }
    else if(event->type() == QEvent::MouseButtonRelease && isHover)
    {
        isHover = false;
    }
    return false;
}

void KeyboardForm::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void KeyboardForm::prevPage()
{
    m_curHanziPage--;
    displayHanzi();
}

void KeyboardForm::nextPage()
{
    m_curHanziPage++;
    displayHanzi();
}

void KeyboardForm::changeStyle()
{
//    setStyleSheet("QPushButton{border-image: url(./images/btn2.png); border-width: 5; font: normal } QPushButton:pressed{border-image: url(./images/btn3.png); border-width: 5;}");
    setStyleSheet("QPushButton{background-color: rgb(171,178,188); border-width: 5; font: normal;border:2px groove gray;border-radius:6px;padding:1px 2px;} QPushButton:pressed{background-color: rgb(93,156,236); border-width: 5;}");

    m_pyFrm->setStyleSheet("background:#D1D4DA");
    m_btnFrm->setStyleSheet("background:#D1D4DA;");
}
