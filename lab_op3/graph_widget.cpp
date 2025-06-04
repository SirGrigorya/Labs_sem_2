#include "graph_widget.h"
#include <QPainter>
#include <algorithm>
#include <cmath>

GraphWidget::GraphWidget(QWidget *parent) : QWidget(parent) {}

void GraphWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(rect(), Qt::white);

    if (m_years.empty() || m_values.empty() || m_years.size() != m_values.size()) {
        return;
    }

    const int leftMargin = 60;
    const int rightMargin = 10;
    const int topMargin = 60;
    const int bottomMargin = 50;

    int w = width() - leftMargin - rightMargin;
    int h = height() - topMargin - bottomMargin;

    int minYear = *std::min_element(m_years.begin(), m_years.end());
    int maxYear = *std::max_element(m_years.begin(), m_years.end());
    if (maxYear == minYear) maxYear += 1;
    if (m_stats.max == m_stats.min) m_stats.max += 1;

    auto toX = [&](int year) {
        return leftMargin + (year - minYear) * w / (maxYear - minYear);
    };

    auto toY = [&](double value) {
        return topMargin + (m_stats.max - value) * h / (m_stats.max - m_stats.min);
    };

    drawGraphLines(painter, toX, toY);

    drawStatistics(painter, toY, leftMargin, rightMargin);

    drawLabels(painter, toY);

    drawAxes(painter, leftMargin, topMargin, w, h);
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

    painter.drawLine(leftMargin, toY(m_stats.min), width() - rightMargin, toY(m_stats.min));
    painter.drawLine(leftMargin, toY(m_stats.max), width() - rightMargin, toY(m_stats.max));
    painter.drawLine(leftMargin, toY(m_stats.median), width() - rightMargin, toY(m_stats.median));
}

void GraphWidget::drawAxes(QPainter &painter, int leftMargin, int topMargin, int w, int h) {
    painter.setPen(QPen(Qt::black, 1));

    int x0 = leftMargin;
    int y0 = topMargin + h;

    painter.drawLine(x0, y0, x0 + w, y0);
    painter.drawLine(x0, topMargin, x0, y0);

    QFont font = painter.font();
    font.setPointSize(8);
    painter.setFont(font);

    painter.drawText(x0 - 25, topMargin + 10, "↑ Value");
    painter.drawText(x0 + w - 30, y0 + 15, "Year →");

    if (!m_years.empty()) {
        int minYear = *std::min_element(m_years.begin(), m_years.end());
        int maxYear = *std::max_element(m_years.begin(), m_years.end());
        if (minYear == maxYear) maxYear += 1;

        for (int year : m_years) {
            int x = leftMargin + (year - minYear) * w / (maxYear - minYear);
            painter.drawLine(x, y0, x, y0 + 5);
            painter.drawText(x - 10, y0 + 18, QString::number(year));
        }
    }

    if (m_stats.max != m_stats.min) {
        for (double value : m_values) {
            int y = topMargin + (m_stats.max - value) * h / (m_stats.max - m_stats.min);
            painter.drawLine(leftMargin - 5, y, leftMargin, y);
            painter.drawText(0, y + 4, QString::number(value, 'f', 1));
        }
    }
}



void GraphWidget::drawLabels(QPainter &painter, std::function<int(double)> toY) {
    painter.setPen(Qt::black);
    QFont font = painter.font();
    font.setPointSize(8);
    painter.setFont(font);

    int yMax = toY(m_stats.max);
    int yMed = toY(m_stats.median);
    int yMin = toY(m_stats.min);

    const int labelPadding = 12;

    if (std::abs(yMax - yMed) < labelPadding) yMed += labelPadding;
    if (std::abs(yMed - yMin) < labelPadding) yMin += labelPadding;
    if (std::abs(yMax - yMin) < labelPadding * 2) yMin += labelPadding * 2;

    painter.drawText(5, yMax - 2, QString("Max: %1").arg(m_stats.max));
    painter.drawText(5, yMed - 2, QString("Median: %1").arg(m_stats.median));
    painter.drawText(5, yMin - 2, QString("Min: %1").arg(m_stats.min));
}

void GraphWidget::setData(const std::vector<int>& years, const std::vector<double>& values,
                          const StatisticsResult& stats) {
    m_years = years;
    m_values = values;
    m_stats = stats;
    update();
}



