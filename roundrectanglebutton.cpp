#include "roundrectanglebutton.h"
#include <QPaintEvent>
#include <QPainter>
#include <QPalette>

RoundRectangleButton::RoundRectangleButton(QWidget *parent)
    : QWidget(parent)
{
}

RoundRectangleButton::~RoundRectangleButton()
{

}

void RoundRectangleButton::setColor(const QColor &color)
{
    m_color = color;
    update ();
}

QColor RoundRectangleButton::color() const
{
    return m_color;
}

void RoundRectangleButton::setTextColor(const QColor &color)
{
    m_textColor = color;
    update ();
}

QColor RoundRectangleButton::textColor() const
{
    return m_textColor;
}

void RoundRectangleButton::setText(const QString &text)
{
    m_text = text;
    update ();
}

QString RoundRectangleButton::text() const
{
    return m_text;
}

void RoundRectangleButton::setRoundRadius(const qreal radius)
{
    m_roundRadius = radius;
    update ();
}

qreal RoundRectangleButton::roundRadius() const
{
    return m_roundRadius;
}

bool RoundRectangleButton::event(QEvent *event)
{
    switch(event->type())
    {
    case QEvent::MouseButtonRelease:
        {
            const QMouseEvent *mouseEvent = dynamic_cast<QMouseEvent *> (event);
            bool inside = rect ().contains (mouseEvent->pos ());
            if ((mouseEvent->button () == Qt::LeftButton) && inside)
            {
                emit clicked ();
            }
        }
        break;
    default:
        break;
    }
    return QWidget::event (event);
}

void RoundRectangleButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED (event);

    QPainter painter (this);
    painter.setRenderHints (QPainter::Antialiasing | QPainter::TextAntialiasing);

    qreal height = this->height ();
    qreal width = this->width ();
    QPointF center (width / 2, height / 2);

    qreal radius = (height > width) ? width : height;
    radius /= 2;

    if (m_roundRadius < radius && m_roundRadius > 0)
    {
        radius = m_roundRadius;
    }

    painter.setPen (Qt::NoPen);
    painter.setBrush (QBrush (m_color));
    painter.drawRoundedRect (rect (), radius, radius);

    painter.setPen (QPen (m_textColor));
    painter.drawText (rect (), Qt::AlignCenter, m_text);
}
