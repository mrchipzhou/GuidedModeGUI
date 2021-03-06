#ifndef SCHARTWIDGET_H
#define SCHARTWIDGET_H

#include <QObject>
#include <QWidget>
#include <QMutex>
#include <QVector>
#include <QList>
#include <QPointF>
#include <QFileDialog>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_marker.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_picker.h>
#include <qwt_plot_renderer.h>

#include <armadillo>

#include "cGloabalParam.h"
class SChartWidget : public QWidget
{
    Q_OBJECT
public:
    static SChartWidget * GetInstance(QWidget *parent = nullptr);
    ~SChartWidget();
private:
    explicit SChartWidget(QWidget *parent = nullptr);
    static SChartWidget * mInstance;
    class GC{
        public:
            ~GC(){
                SChartWidget::mInstanceMutex.lock();
                if(SChartWidget::mInstance != nullptr)
                    SChartWidget::mInstance->sClean();//Crashed when call deconstructor.
                SChartWidget::mInstanceMutex.unlock();
                SChartWidget::mInstance = nullptr;
            }
    };
    static GC Gc;

public:
    void setSamples(QVector<QPointF> const& samples);
    void setSamples();
    void clearGraph(){
        mPointXQVec->clear();
        mPointYQVec->clear();
        setSamples();
        clearGratingLines();
        clearBoundaryIndex();
    }
    void addGratingLine(double const x);
    void setGratingLines(QVector<double> const & beta);
    void setBoundaryIndex(QVector<double> const & index);
    void drawBoundaryIndex();
    void clearBoundaryIndex()
    {
        for(auto var : mMatterCurveList)
            if(var)
            {
                delete var;
                var = nullptr;
            }
        mMatterCurveList.clear();
    }
    void drawGratingLines();
    void clearGratingLines();
    void setPlotData(QVector<double> const& Beta, QVector<double> const& F);

    void sClean();

public slots:
    void exportPNG();
    void exportTXT();
    void exportCSV();

private:
    QwtPlot *mQwtPlot;
    QwtPlotCurve *mQwtScatter;
    QList<QwtPlotCurve*> mMatterCurveList;
    QwtPlotZoomer *mQwtZoomer;
    QwtPlotPicker *mQwtPicker;
    static QMutex mInstanceMutex;

private:
    QVector<double> *mPointXQVec;
    QVector<double> *mPointYQVec;
    QVector<double> mBetaQVec;
    QVector<double> mBoundaryIndex;
    QList<QwtPlotMarker*> mGratingLines;
signals:

public slots:
};

#endif // SCHARTWIDGET_H
