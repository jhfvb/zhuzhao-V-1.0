#ifndef ZZLOGWIDGET_H
#define ZZLOGWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QCommandLinkButton>
#include <QTextBrowser>

class ZZLogWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ZZLogWidget(QWidget *parent = nullptr);

protected:
    bool InitWidget();

private slots:
    void OnClearBtnClicked();
    void OnHelperBtnClicked();

private:
    QPushButton* m_pClearBtn;
    QPushButton* m_pHelperBtn;
    QTextBrowser* m_pLogTextBrowser;

};

#endif // ZZLOGWIDGET_H
