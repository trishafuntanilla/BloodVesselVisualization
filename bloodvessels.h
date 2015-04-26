#ifndef BLOODVESSELS_H
#define BLOODVESSELS_H

#include <QWidget>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QVector>
#include <QVector2D>
#include <QPointF>
#include <unordered_map>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

namespace Ui {
class BloodVessels;
}

class BloodVessels : public QMainWindow
{
    Q_OBJECT

public:
    BloodVessels(QWidget *parent = 0);
    ~BloodVessels();

    bool isEmpty();
    void saveTipPoint(string imgpath, qreal x, qreal y);
    Mat identifyTip(Mat src, float x, float y);
    Mat displayTips(Mat src, string imName);
    void tipsAnimation(Mat imageIn, unordered_map<string, QVector<QVector2D> > tips_map);
    void getManuallySelectedTips(unordered_map<string, QVector<QVector2D> > &tips);

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_start_pushButton_clicked();

private:
    Ui::BloodVessels *ui;

    void updateView(Mat imageOut);

    QPixmap image;
    QImage *imageObject;
    QGraphicsScene *scene;

    // maps selected tips to image
    // ONLY FOR MANUALLY SELECTED TIPS
    unordered_map<string, QVector<QVector2D> > bv_tips_map;

};

#endif // BLOODVESSELS_H
