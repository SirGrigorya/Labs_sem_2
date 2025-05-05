#include "graph_widget.h"
#include <QPainter>

GraphWidget::GraphWidget(QWidget *parent) : QWidget(parent) {}

void GraphWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(rect(), Qt::white);

    if (m_years.empty() || m_values.empty() || m_years.size() != m_values.size()) {
        return;
    }

    const int leftMargin = 40;
    const int rightMargin = 10;
    const int topMargin = 10;
    const int bottomMargin = 30;

    int w = width() - leftMargin - rightMargin;
    int h = height() - topMargin - bottomMargin;

    int minYear = *std::min_element(m_years.begin(), m_years.end());
    int maxYear = *std::max_element(m_years.begin(), m_years.end());
    if (maxYear == minYear) maxYear += 1;
    if (m_max == m_min) m_max += 1;

    auto toX = [&](int year) { return leftMargin + (year - minYear) * w / (maxYear - minYear); };
    auto toY = [&](double value) { return topMargin + (m_max - value) * h / (m_max - m_min); };

    drawGraphLines(painter, toX, toY);
    drawStatistics(painter, toY, leftMargin, rightMargin);
    drawLabels(painter, toY);
}

void GraphWidget::drawGraphLines(QPainter &painter, std::function<int(int)> toX, std::function<int(double)> toY) {
    painter.setPen(QPen(Qt::blue, 2));
    for (size_t i = 1; i < m_values.size(); ++i) {
        int x1 = toX(m_years[i - 1]);
        int y1 = toY(m_values[i - 1]);
        int x2 = toX(m_years[i]);
        int y2 = toY(m_values[i]);
        painter.drawLine(x1, y1, x2, y2);
    }
}

void GraphWidget::drawStatistics(QPainter &painter, std::function<int(double)> toY, int leftMargin, int rightMargin) {
    QPen statPen(Qt::DashLine);
    statPen.setColor(Qt::gray);
    painter.setPen(statPen);

    painter.drawLine(leftMargin, toY(m_min), width() - rightMargin, toY(m_min));
    painter.drawLine(leftMargin, toY(m_max), width() - rightMargin, toY(m_max));
    painter.drawLine(leftMargin, toY(m_median), width() - rightMargin, toY(m_median));
}

void GraphWidget::drawLabels(QPainter &painter, std::function<int(double)> toY) {
    painter.setPen(Qt::black);
    QFont font = painter.font();
    font.setPointSize(8);
    painter.setFont(font);
    painter.drawText(5, toY(m_max) - 2, QString("Max: %1").arg(m_max));
    painter.drawText(5, toY(m_median) - 2, QString("Median: %1").arg(m_median));
    painter.drawText(5, toY(m_min) - 2, QString("Min: %1").arg(m_min));
}

void GraphWidget::setData(const std::vector<int>& years, const std::vector<double>& values,
                          double min, double max, double median) {
    m_years = years;
    m_values = values;
    m_min = min;
    m_max = max;
    m_median = median;
    update();
}
