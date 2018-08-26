#include "buttonEventWatcher.h"
#include "scene/menubuttons.h"

bool ButtonEventWatcher::eventFilter(QObject *watched, QEvent *event)
{
    menuButton * button = qobject_cast<menuButton*>(watched);
    if (!button) {
        return false;
    }

    if (event->type() == QEvent::Enter) {
        // The push button is hovered by mouse
        button->setIcon(button->getIconHover());
    }

    if (event->type() == QEvent::MouseButtonPress){
        // The push button is not hovered by mouse
        button->setIcon(button->getIconPressed());
    }

    if (event->type() == QEvent::MouseButtonRelease){
        // The push button is not hovered by mouse
        button->setIcon(button->getIcon());
    }

    if (event->type() == QEvent::Leave){
        // The push button is not hovered by mouse
        button->setIcon(button->getIcon());
    }

    return QObject::eventFilter(watched, event);
}
