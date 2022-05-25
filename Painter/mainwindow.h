#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QMouseEvent>
#include <QWheelEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ushort _count = 0;
    QPainter _painter;
    QTransform _transform;
    QPen _pen;
    QBrush _brush;
    const QRectF _rectangle{50, 60, 200, 150};
    const QPointF _star[5] = {QPointF(150, 10),
                             QPointF(67, 253),
                             QPointF(283, 106),
                             QPointF(17, 106),
                             QPointF(232, 253)};

protected:
    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;
};
#endif // MAINWINDOW_H
