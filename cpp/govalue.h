#ifndef GOVALUE_H
#define GOVALUE_H

// Unfortunatley we need access to private bits, because the
// whole dynamic meta-object concept is sadly being hidden
// away, and without it this package wouldn't exist.
#include <private/qmetaobject_p.h>

#include "capi.h"

class GoValueMetaObject;

// TODO Painting.
//#include <QQuickPaintedItem>
//#include <QPainter>
//class GoValue : public QQuickPaintedItem
class GoValue : public QObject
{
    Q_OBJECT

public:
    GoAddr *addr;
    GoTypeInfo *typeInfo;

    GoValue(GoAddr *addr, GoTypeInfo *typeInfo, QObject *parent);

    void activate(int propIndex);

    // TODO Painting.
    //virtual void paint(QPainter *painter);

    static QMetaObject *metaObjectFor(GoTypeInfo *typeInfo);

    virtual ~GoValue();

private:
    GoValueMetaObject *valueMeta;
};

#endif // GOVALUE_H

// vim:ts=4:et
