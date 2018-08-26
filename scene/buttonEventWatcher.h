#ifndef BUTTONEVENTWATCHER_H
#define BUTTONEVENTWATCHER_H
#include <QObject>

class ButtonEventWatcher : public QObject
{
    Q_OBJECT
public:
    explicit ButtonEventWatcher(QObject *parent = nullptr) : QObject(parent) {}
    virtual bool eventFilter(QObject * watched, QEvent * event) Q_DECL_OVERRIDE;
};

#endif // BUTTONEVENTWATCHER_H
