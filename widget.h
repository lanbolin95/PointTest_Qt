#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QLabel>
#include <QMouseEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);

    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *);

    QLabel *Label;
    QLabel *Label1;
    QLabel *Label2;
    QLabel *Label3;
    QLabel *Label4;
    QLabel *Label5;
    QLabel *Label11;
    QLabel *Label21;
    QLabel *Label31;
    QLabel *Label41;
    QLabel *Label51;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
