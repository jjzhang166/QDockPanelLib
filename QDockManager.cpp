#include "QDockManager.h"
#include "QDockFrame.h"
#include "QDockPanel.h"
#include <cassert>
#include "QDockNode.h"

QDockManager::QDockManager(QWidget *parent)
	: QObject(parent),dockFrmae_(new QDockFrame(this,parent))
{

}

QDockManager::~QDockManager()
{

}

QDockPanel* QDockManager::addPanel(int id, const QString& title,QPoint pos,QSize size, QWidget* contensWidget /*= NULL*/)
{
	if (dockPanels_.find(id) != dockPanels_.end())
	{
		return NULL;
	}
	QDockPanel* p = new QDockPanel(this,dockFrmae_);
	p->setId(id);
	p->setWindowTitle(title);
	p->resetContensWidget(contensWidget);
	p->move(pos);
	p->resize(size);
	p->show();
	dockPanels_.insert(std::make_pair(id,p));

	return p;
}

QDockPanel* QDockManager::getDockPanelByID( int id )
{
	std::map<int,QDockPanel*>::iterator it = dockPanels_.find(id);
	if (it == dockPanels_.end())
	{
		return NULL;
	}

	return it->second;
}

bool QDockManager::dockPanelToFrame( QDockPanel* panel,DockArea area )
{
	switch (area)
	{
	case LeftArea:
		{
			int c = dockFrmae_->rootNode_->count();
			if (c == 1)
			{
				dockFrmae_->rootNode_->setOrientation(Qt::Horizontal);
				panel->setDockStatus();
 				dockFrmae_->rootNode_->insertWidget(0,panel);
			}
			else if (c == 2)
			{
				QDockNode* tmpNode = dockFrmae_->rootNode_;
				panel->setDockStatus();
				dockFrmae_->rootNode_ = new QDockNode(dockFrmae_);
				dockFrmae_->rootNode_->setOrientation(Qt::Horizontal);
				dockFrmae_->rootNode_->insertWidget(0,panel);
				dockFrmae_->rootNode_->insertWidget(1,tmpNode);
				dockFrmae_->relayout();
				panel->resize(tmpNode->width()/2,tmpNode->height());
			}
			else
			{
				assert(false);
			}
			break;
		}
	case TopArea:
		{
			int c = dockFrmae_->rootNode_->count();
			if (c == 1)
			{
				dockFrmae_->rootNode_->setOrientation(Qt::Vertical);
				panel->setDockStatus();
				dockFrmae_->rootNode_->insertWidget(0,panel);
			}
			else if (c == 2)
			{
				QDockNode* tmpNode = dockFrmae_->rootNode_;
				panel->setDockStatus();
				dockFrmae_->rootNode_ = new QDockNode(dockFrmae_);
				dockFrmae_->rootNode_->setOrientation(Qt::Vertical);
				dockFrmae_->rootNode_->insertWidget(0,panel);
				dockFrmae_->rootNode_->insertWidget(1,tmpNode);
				dockFrmae_->relayout();
				panel->resize(tmpNode->width(),tmpNode->height()/2);
			}
			else
			{
				assert(false);
			}
			break;
		}
	case RightArea:
		{
			int c = dockFrmae_->rootNode_->count();
			if (c == 1)
			{
				dockFrmae_->rootNode_->setOrientation(Qt::Horizontal);
				panel->setDockStatus();
				dockFrmae_->rootNode_->insertWidget(1,panel);
			}
			else if (c == 2)
			{
				QDockNode* tmpNode = dockFrmae_->rootNode_;
				panel->setDockStatus();
				dockFrmae_->rootNode_ = new QDockNode(dockFrmae_);
				dockFrmae_->rootNode_->setOrientation(Qt::Horizontal);
				dockFrmae_->rootNode_->insertWidget(0,tmpNode);
				dockFrmae_->rootNode_->insertWidget(1,panel);
				dockFrmae_->relayout();
				panel->resize(tmpNode->width()/2,tmpNode->height());
			}
			else
			{
				assert(false);
			}
			break;
		}
	case BottomArea:
		{
			int c = dockFrmae_->rootNode_->count();
			if (c == 1)
			{
				dockFrmae_->rootNode_->setOrientation(Qt::Vertical);
				panel->setDockStatus();
				dockFrmae_->rootNode_->insertWidget(0,panel);
			}
			else if (c == 2)
			{
				QDockNode* tmpNode = dockFrmae_->rootNode_;
				panel->setDockStatus();
				dockFrmae_->rootNode_ = new QDockNode(dockFrmae_);
				dockFrmae_->rootNode_->setOrientation(Qt::Vertical);
				dockFrmae_->rootNode_->insertWidget(0,tmpNode);
				dockFrmae_->rootNode_->insertWidget(1,panel);
				dockFrmae_->relayout();
				panel->resize(tmpNode->width(),tmpNode->height()/2);
			}
			else
			{
				assert(false);
			}
			break;
		}
	case CenterArea:
		assert(dockFrmae_->rootNode_->count() == 0);
		panel->setDockStatus();
		panel->setParent(dockFrmae_->rootNode_);
		break;
	default:
		return false;
	}

	return true;
}

bool QDockManager::dockPanelToPanel( QDockPanel* panel1,QDockPanel* panel2 )
{
	return false;
}

bool QDockManager::isRootNode( QDockNode* node )
{
	return node == dockFrmae_->rootNode_;
}
