#pragma once
#include <QWidget>
#include <vector>

class GraphWidget : public QWidget {
    Q_OBJECT

public:
    explicit GraphWidget(QWidget *parent = nullptr);

    void setData(const std::vector<int> &years, const std::vector<double> &values,
                 double min, double max, double median);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    std::vector<int> m_years;
    std::vector<double> m_values;
    double m_min = 0, m_max = 0, m_median = 0;

    void drawGraphLines(QPainter &painter, std::function<int(int)> toX, std::function<int(double)> toY);
    void drawStatistics(QPainter &painter, std::function<int(double)> toY, int leftMargin, int rightMargin);
    void drawLabels(QPainter &painter, std::function<int(double)> toY);
};
