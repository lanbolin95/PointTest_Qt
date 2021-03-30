#include "widget.h"
#include "ui_widget.h"
#include <QDesktopWidget>
#include <QDebug>
#include <QFont>
#include <QMenu>

int g_nActScreenX;
int g_nActScreenY;
QPoint lastPos;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QDesktopWidget* desktopWidget = QApplication::desktop();
    QRect screenRect = desktopWidget->screenGeometry();
    g_nActScreenX = screenRect.width();
    g_nActScreenY = screenRect.height();

    Label = new QLabel("0,0", this);
    QFont font("Microsoft YaHei", 30, 75);
    QFont font1("Microsoft YaHei", 20, 75);
    Label->setFont(font);
    Label->setGeometry(g_nActScreenX/2 - 115, 10, 400, 50);

    Label1 = new QLabel("130,130", this);
    Label1->setFont(font1);
    Label1->setGeometry(100, 160, 200, 50);

    Label2 = new QLabel(this);
    Label2->setFont(font1);
    Label2->setText(QString::asprintf("%d",g_nActScreenX - 130) + ",130");
    Label2->setGeometry(g_nActScreenX - 360, 160, 200, 50);

    Label3 = new QLabel(this);
    Label3->setFont(font1);
    Label3->setText("130," + QString::asprintf("%d", g_nActScreenY - 130));
    Label3->setGeometry(100, g_nActScreenY - 210, 200, 50);

    Label4 = new QLabel(this);
    Label4->setFont(font1);
    Label4->setText(QString::asprintf("%d",g_nActScreenX - 130) + "," + QString::asprintf("%d", g_nActScreenY - 130));
    Label4->setGeometry(g_nActScreenX - 360, g_nActScreenY - 210, 200, 50);

    Label5 = new QLabel(this);
    Label5->setFont(font1);
    Label5->setText(QString::asprintf("%d",g_nActScreenX/2) + "," + QString::asprintf("%d", g_nActScreenY/2));
    Label5->setGeometry(g_nActScreenX/2 - 30, g_nActScreenY/2 + 30, 200, 50);

    Label11 = new QLabel("0,0", this);
    Label11->setFont(font1);
    Label11->setGeometry(100, 210, 300, 50);

    Label21 = new QLabel("0,0", this);
    Label21->setFont(font1);
    Label21->setGeometry(g_nActScreenX - 360, 210, 300, 50);

    Label31 = new QLabel("0,0", this);
    Label31->setFont(font1);
    Label31->setGeometry(100, g_nActScreenY - 260, 300, 50);

    Label41 = new QLabel("0,0", this);
    Label41->setFont(font1);
    Label41->setGeometry(g_nActScreenX - 360, g_nActScreenY - 260, 300, 50);

    Label51 = new QLabel("0,0", this);
    Label51->setFont(font1);
    Label51->setGeometry(g_nActScreenX/2 - 30, g_nActScreenY/2 + 80, 300, 50);

    this->showFullScreen();

//    qDebug() << g_nActScreenX << g_nActScreenY;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(QColor(Qt::red));
    painter.setBrush(QBrush(Qt::red));

    QRectF rectangle1(100, 100, 60.0, 60.0);
    painter.drawEllipse(rectangle1);

    QRectF rec1(g_nActScreenX - 160, 100, 60, 60);
    painter.drawEllipse(rec1);

    QRectF rec2(100, g_nActScreenY - 160, 60, 60);
    painter.drawEllipse(rec2);

    QRectF rec3(g_nActScreenX - 160, g_nActScreenY - 160, 60, 60);
    painter.drawEllipse(rec3);

    QRectF rec4(g_nActScreenX/2 - 30, g_nActScreenY/2 - 30, 60, 60);
    painter.drawEllipse(rec4);

    QPainter painter1(this);
    QLineF line10(100, 130, 160, 130);
    painter1.drawLine(line10);
    QLineF line11(130, 100, 130, 160);
    painter1.drawLine(line11);

    QLineF line20(g_nActScreenX - 160, 130, g_nActScreenX - 100, 130);
    painter1.drawLine(line20);
    QLineF line21(g_nActScreenX - 130, 100, g_nActScreenX - 130, 160);
    painter1.drawLine(line21);

    QLineF line30(100, g_nActScreenY - 130, 160, g_nActScreenY - 130);
    painter1.drawLine(line30);
    QLineF line31(130, g_nActScreenY - 160, 130, g_nActScreenY - 100);
    painter1.drawLine(line31);

    QLineF line40(g_nActScreenX - 160, g_nActScreenY - 130, g_nActScreenX - 100, g_nActScreenY - 130);
    painter1.drawLine(line40);
    QLineF line41(g_nActScreenX - 130, g_nActScreenY - 160, g_nActScreenX - 130, g_nActScreenY - 100);
    painter1.drawLine(line41);

    QLineF line50(g_nActScreenX/2 - 30, g_nActScreenY/2, g_nActScreenX/2 + 30, g_nActScreenY/2);
    painter1.drawLine(line50);
    QLineF line51(g_nActScreenX/2, g_nActScreenY/2 - 30, g_nActScreenX/2, g_nActScreenY/2 + 30);
    painter1.drawLine(line51);

    QPainter painterJ(this);
    QPen pen;
    pen.setColor(Qt::blue);
    pen.setWidth(1);
    painterJ.setPen(pen);
    painterJ.drawLine(0, lastPos.y(), g_nActScreenX, lastPos.y());
    painterJ.drawLine(lastPos.x(), 0, lastPos.x(), g_nActScreenY);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Escape:
        this->close();
        break;
    default:
        break;
    }
}

//鼠标滑动事件
void Widget::mouseMoveEvent(QMouseEvent *e)
{
    lastPos = e->globalPos();
    update();
    QPoint p_ab = e->globalPos();//整个桌面位置

    QString str;
    str = QString("%1 , %2").arg(p_ab.x()).arg(p_ab.y());
    Label->setText(str);

    str = QString("%1, %2").arg(130 - p_ab.x()).arg(130 - p_ab.y());
    Label11->setText(str);

    str = QString("%1, %2").arg(g_nActScreenX - 130 - p_ab.x()).arg(130 - p_ab.y());
    Label21->setText(str);

    str = QString("%1, %2").arg(130 - p_ab.x()).arg(g_nActScreenY - 130 - p_ab.y());
    Label31->setText(str);

    str = QString("%1, %2").arg(g_nActScreenX - 130 - p_ab.x()).arg(g_nActScreenY - 130 - p_ab.y());
    Label41->setText(str);

    str = QString("%1, %2").arg(g_nActScreenX/2 - p_ab.x()).arg(g_nActScreenY/2 - p_ab.y());
    Label51->setText(str);
}

//鼠标点击事件
void Widget::mousePressEvent(QMouseEvent *e)
{
    lastPos = e->globalPos();
    update();
    Label->setText(QString("%1 , %2").arg(e->globalX()).arg(e->globalY()));
    Label11->setText(QString("%1 , %2").arg(130 - e->globalX()).arg(130 - e->globalY()));
    Label21->setText(QString("%1 , %2").arg(g_nActScreenX - 130 - e->globalX()).arg(130 - e->globalY()));
    Label31->setText(QString("%1 , %2").arg(130 - e->globalX()).arg(g_nActScreenY - 130 - e->globalY()));
    Label41->setText(QString("%1 , %2").arg(g_nActScreenX - 130 - e->globalX()).arg(g_nActScreenY - 130 - e->globalY()));
    Label51->setText(QString("%1 , %2").arg(g_nActScreenX/2 - e->globalX()).arg(g_nActScreenY/2 - e->globalY()));
}

void Widget::mouseDoubleClickEvent(QMouseEvent *)
{
    QMenu *pMenu = new QMenu(this);

//    QAction *pClearTask = new QAction(tr("清除"), this);
    QAction *pExitTask = new QAction(tr("退出"), this);

    //1:清除 2:退出
//    pClearTask->setData(1);
    pExitTask->setData(2);

    //把QAction对象添加到菜单上
//    pMenu->addAction(pClearTask);
    pMenu->addAction(pExitTask);

    //连接鼠标右键点击信号
//    connect(pClearTask, SIGNAL(triggered()), myDraw, SLOT(clear()));
    connect(pExitTask, SIGNAL(triggered()), this, SLOT(close()));

    //在鼠标右键点击的地方显示菜单
    pMenu->exec(cursor().pos());

    //释放内存
    QList<QAction*> list = pMenu->actions();
    foreach (QAction* pAction, list) delete pAction;
    delete pMenu;
}
