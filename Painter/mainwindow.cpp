#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColor>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    _painter.begin(this);
    _pen.setColor(QColor(rand()%256, rand()%256, rand()%256));
    _pen.setStyle(Qt::PenStyle::SolidLine);
    _brush.setColor(QColor(rand()%256, rand()%256, rand()%256));
    _brush.setStyle(Qt::BrushStyle::FDiagPattern);
    _painter.setPen(_pen);
    _painter.setBrush(_brush);
    _painter.setTransform(_transform);
    switch (_count)
    {
        case 0:
            _painter.drawText(_rectangle, "Let's get it started!!!");
            break;
        case 1:
            _painter.drawRect(_rectangle);
            break;
        case 2:
            _painter.drawEllipse(_rectangle);
            break;
        case 3:
            _painter.drawPolygon(_star, 5);
            break;
        default:
            _painter.drawText(_rectangle, "Error!");
    }
    _painter.end();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::MouseButton::LeftButton)
    {
        ++_count;
        QWidget::repaint();
        if(_count == 3) _count = 0;
    }
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    QPoint degrees = event->angleDelta()/8;
    if(degrees.y()>0)
    {
        _transform.scale(1.1, 1.1);
        QWidget::repaint();
    }
    else
    {
        _transform.scale(0.9, 0.9);
        QWidget::repaint();
    }
}
