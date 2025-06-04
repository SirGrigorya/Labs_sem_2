#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QWidget>
#include <vector>
#include "statistics.h"

class GraphWidget : public QWidget {
    Q_OBJECT

public:
    explicit GraphWidget(QWidget *parent = nullptr);
    void setData(const std::vector<int>& years, const std::vector<double>& values,
                 const StatisticsResult& stats);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    std::vector<int> m_years;
    std::vector<double> m_values;
    StatisticsResult m_stats;

    void drawGraphLines(QPainter &painter, std::function<int(int)> toX, std::function<int(double)> toY);
    void drawStatistics(QPainter &painter, std::function<int(double)> toY, int leftMargin, int rightMargin);
    void drawLabels(QPainter &painter, std::function<int(double)> toY);
    void drawAxes(QPainter &painter, int leftMargin, int topMargin, int w, int h);
};

#endif // GRAPHWIDGET_H
