#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QQmlEngine>

class Engine : public QObject
{
    Q_OBJECT

    int m_maxPower;
    //Q_PROPERTY(int maxPower READ maxPower WRITE setMaxPower)

public:
    //explicit Engine(int max_power, QObject *parent = nullptr);
    explicit Engine(QObject *parent = nullptr);

    int maxPower();
    void setMaxPower(int max_power);

signals:
    void current_power(double value);

public slots:
    double calculate_power(int throttle_pos);
};

#endif // ENGINE_H
