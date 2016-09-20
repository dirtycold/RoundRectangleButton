#ifndef ROUNDRECTANGLEBUTTON_H
#define ROUNDRECTANGLEBUTTON_H

#include <QWidget>

class RoundRectangleButton : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QColor color READ color WRITE setColor)
    Q_PROPERTY(QColor textColor READ textColor WRITE setTextColor)
    Q_PROPERTY(QString text READ text WRITE setText)
    Q_PROPERTY(qreal roundRadius READ roundRadius WRITE setRoundRadius)

public:
    RoundRectangleButton(QWidget *parent = 0);
    ~RoundRectangleButton();

    void setColor (const QColor &color);
    QColor color () const;

    void setTextColor (const QColor &color);
    QColor textColor () const;

    void setText (const QString &text);
    QString text () const;

    void setRoundRadius (const qreal radius);
    qreal roundRadius () const;

signals:
    void clicked ();

private:
    bool event (QEvent *event);
    void paintEvent (QPaintEvent *event);

private:
    QColor m_color;
    QColor m_textColor;
    QString m_text;
    qreal m_roundRadius;

};

#endif // ROUNDRECTANGLEBUTTON_H
