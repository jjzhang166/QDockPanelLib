#ifndef QDOCKPANELCONPONENTS_H
#define QDOCKPANELCONPONENTS_H

#include <QWidget>

class QDockPanelTitle : public QWidget
{
	Q_OBJECT

public:
	QDockPanelTitle(QWidget *parent);
	~QDockPanelTitle(){}

	virtual void paintEvent( QPaintEvent * );

public slots:
	void setTitle(const QString& title);

signals:
	Qt::DropAction startDrag();
	void dragMoving();
	void endDrag(Qt::DropAction);
private:
	virtual void mousePressEvent( QMouseEvent* e);

	virtual void mouseReleaseEvent( QMouseEvent*);

	virtual void mouseMoveEvent( QMouseEvent* e);

private:
	QString title_;

	bool isLBtnPressed_;
	QPoint pressedPos_;
	QPoint parentOldPos_;
};

class QDockPanelEdgeLeft : public QWidget
{
	Q_OBJECT

public:
	QDockPanelEdgeLeft(QWidget *parent);
	~QDockPanelEdgeLeft(){}

private:
	virtual void mousePressEvent( QMouseEvent* e);

	virtual void mouseReleaseEvent( QMouseEvent*);

	virtual void mouseMoveEvent( QMouseEvent* e);

private:
	bool isLBtnPressed_;
	QPoint pressedPos_;
	QRect parentOldRect_;
};

class QDockPanelEdgeTop : public QWidget
{
	Q_OBJECT

public:
	QDockPanelEdgeTop(QWidget *parent);
	~QDockPanelEdgeTop(){}

private:
	virtual void mousePressEvent( QMouseEvent* e);

	virtual void mouseReleaseEvent( QMouseEvent*);

	virtual void mouseMoveEvent( QMouseEvent* e);

private:
	bool isLBtnPressed_;
	QPoint pressedPos_;
	QRect parentOldRect_;
};

class QDockPanelEdgeRight : public QWidget
{
	Q_OBJECT

public:
	QDockPanelEdgeRight(QWidget *parent);
	~QDockPanelEdgeRight(){}

private:
	virtual void mousePressEvent( QMouseEvent* e);

	virtual void mouseReleaseEvent( QMouseEvent*);

	virtual void mouseMoveEvent( QMouseEvent* e);

private:
	bool isLBtnPressed_;
	QPoint pressedPos_;
	int parentOldWidth_;
};

class QDockPanelEdgeBottom : public QWidget
{
	Q_OBJECT

public:
	QDockPanelEdgeBottom(QWidget *parent);
	~QDockPanelEdgeBottom(){}

private:
	virtual void mousePressEvent( QMouseEvent* e);

	virtual void mouseReleaseEvent( QMouseEvent*);

	virtual void mouseMoveEvent( QMouseEvent* e);

private:
	bool isLBtnPressed_;
	QPoint pressedPos_;
	int parentOldHeight_;
};

class QDockPanelEdgeLeftTop : public QWidget
{
	Q_OBJECT

public:
	QDockPanelEdgeLeftTop(QWidget *parent);
	~QDockPanelEdgeLeftTop(){}

private:
	virtual void mousePressEvent( QMouseEvent* e);

	virtual void mouseReleaseEvent( QMouseEvent*);

	virtual void mouseMoveEvent( QMouseEvent* e);

private:
	bool isLBtnPressed_;
	QPoint pressedPos_;
	QRect parentOldRect_;
};

class QDockPanelEdgeRightTop : public QWidget
{
	Q_OBJECT

public:
	QDockPanelEdgeRightTop(QWidget *parent);
	~QDockPanelEdgeRightTop(){}

private:
	virtual void mousePressEvent( QMouseEvent* e);

	virtual void mouseReleaseEvent( QMouseEvent*);

	virtual void mouseMoveEvent( QMouseEvent* e);

private:
	bool isLBtnPressed_;
	QPoint pressedPos_;
	QRect parentOldRect_;
};

class QDockPanelEdgeRightBottom : public QWidget
{
	Q_OBJECT

public:
	QDockPanelEdgeRightBottom(QWidget *parent);
	~QDockPanelEdgeRightBottom(){}

private:
	virtual void mousePressEvent( QMouseEvent* e);

	virtual void mouseReleaseEvent( QMouseEvent*);

	virtual void mouseMoveEvent( QMouseEvent* e);

private:
	bool isLBtnPressed_;
	QPoint pressedPos_;
	QSize parentOldSize_;
};

class QDockPanelEdgeLeftBottom : public QWidget
{
	Q_OBJECT

public:
	QDockPanelEdgeLeftBottom(QWidget *parent);
	~QDockPanelEdgeLeftBottom(){}

private:
	virtual void mousePressEvent( QMouseEvent* e);

	virtual void mouseReleaseEvent( QMouseEvent*);

	virtual void mouseMoveEvent( QMouseEvent* e);

private:
	bool isLBtnPressed_;
	QPoint pressedPos_;
	QRect parentOldRect_;
};

#endif // QDOCKPANELCONPONENTS_H
